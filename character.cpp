#include "pch.h"
#include "character.h"
#include "poketmonManager.h"
#include "tileMap.h"
#include "npc.h"

character::character()
{
}

character::~character()
{
}

HRESULT character::init() // 인잇
{
    imageInit();
    poketmonSetting();

    _image = IMAGEMANAGER->findImage("아이들_좌우");
    _shadowImage = IMAGEMANAGER->findImage("캐릭터_그림자");
    _grassImage = IMAGEMANAGER->findImage("풀숲1");
    _battleLoadingImage = IMAGEMANAGER->findImage("배틀로딩");
    _flashLoadingImage = IMAGEMANAGER->findImage("플래시로딩");

    _direction = _isMoving = _isSloping = _isPoketmonMeet = _frontTileType = _alpha = 0;
    _jumpPower = JUMPPOWER;
    _gravity = GRAVITY;
    _frameCount = _currentFrame = _loadingCount = _scriptAction = 0;
    _x = WINSIZEX / 2 + TILESIZE / 2;
    _y = WINSIZEY / 2;
    _currentTile = 4853;
    _slopeDistance = 0;
    _rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

    return S_OK;
}

void character::release()
{
}

void character::update() // 업데이트
{
    controll();
    imageFrame();
    poketmonMeet();
    npcScript();
    
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) tileAction();

}

void character::controll() // 캐릭터 컨트롤 처리
{
    if (_isPoketmonMeet || UIMANAGER->isUiOpen() || _npc->getIsMove()) // 포켓몬 만나거나 UI떠있거나 npc만나 느낌표 떠있다면~
    {
        idle(_direction); // 아이들 처리
        return; // 함수 빠져나감 
    }

    if (!_isMoving && !_isSloping) // 이동 중이 아니고, 비탈길 아닐 때
    {
        // 아이들
        if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) idle(0);
        if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) idle(1);
        if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) idle(2);
        if (KEYMANAGER->isOnceKeyUp(VK_UP)) idle(3);

        // 걷기
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // 오른쪽 이동
        {
            if (_grassCount >= 3) _grassCount = 0; // 풀 타일 이동 중일 때 초기화 해줌
            run(0);
            if (!_isMoving) tileCheck(0);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // 왼쪽 이동
        {
            if (_grassCount >= 3) _grassCount = 0; // 풀 타일 이동 중일 때 초기화 해줌
            run(1);
            if (!_isMoving) tileCheck(1);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // 아래 이동
        {
            if (_grassCount >= 3) _grassCount = 0; // 풀 타일 이동 중일 때 초기화 해줌
            run(2);
            if (!_isMoving) tileCheck(2);
            tileAction();
        }

        if (KEYMANAGER->isStayKeyDown(VK_UP)) // 위 이동
        {
            if (_grassCount >= 3) _grassCount = 0; // 풀 타일 이동 중일 때 초기화 해줌
            run(3);
            if (!_isMoving) tileCheck(3);
            tileAction();
        }
    }

    // 메뉴창 (enter Key)
    if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) UIMANAGER->setOpenMenu(true);

}

void character::imageSetting() // 상태에 따라 현재 이미지 세팅
{
    switch (_state)
    {
        case static_cast<int>(STATE::IDLE_RL) :
            _image = IMAGEMANAGER->findImage("아이들_좌우");
            break;
        case static_cast<int>(STATE::IDLE_UD) :
            _image = IMAGEMANAGER->findImage("아이들_상하");
            break;
        case static_cast<int>(STATE::RUN_RL) :
            _image = IMAGEMANAGER->findImage("걷기_좌우");
            break;
        case static_cast<int>(STATE::RUN_UD) :
            _image = IMAGEMANAGER->findImage("걷기_상하");
            break;
    }
}

void character::imageFrame() // 이미지 프레임 처리
{
    // 프레임Y 이미지 갱신
    if (_direction == 0 || _direction == 2) _image->setFrameY(0);
    else _image->setFrameY(1);

    // 프레임 카운트 증가
    _frameCount++;

    // 카운트가 일정 수치마다 프레임X 갱신
    if (_frameCount % 5 == 0)
    {
        // 프레임 초기화
        if (_direction == 0 || _direction == 2)
        {
            _currentFrame++;
            if (_currentFrame > _image->getMaxFrameX()) _currentFrame = 0;
        }
        else
        {
            _currentFrame--;
            if (_currentFrame < 0) _currentFrame = _image->getMaxFrameX();
        }

        // X프레임 이미지 갱신
        _image->setFrameX(_currentFrame);
    }

    // 렉트 갱신
    _rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

    // 프레임카운트 초기화
    if (_frameCount > 5) _frameCount = 0;
}

void character::poketmonMeet() // 포켓몬 조우 시 처리
{
    // 포켓몬 조우 시에만 처리되도록.
    if (!_isPoketmonMeet) return;

    // 포켓몬 조우 시 Y프레임 세팅
    _battleLoadingImage->setFrameY(0); 

    // 로딩 카운트 증가
    _loadingCount++; 

    // 플래시 로딩 이미지 알파값 세팅
    if (_loadingCount % 15 == 0) _alpha = 0;
    if (_loadingCount % 15 == 7) _alpha = 150;
    if (_loadingCount % 15 == 14) _alpha = 255;

    // 배틀 로딩 이미지 갱신
    if (_loadingCount % 2 == 0)
    {
        if (_loadingCount > 70) _battleLoadingImage->setFrameX(_battleLoadingImage->getFrameX() + 1);

        // 맥스 프레임 도달하면 배틀씬으로 전환
        if (_battleLoadingImage->getFrameX() >= _battleLoadingImage->getMaxFrameX() && !UIMANAGER->getIsBattle())
        {
            UIMANAGER->setIsBattle(true);
            UIMANAGER->setIsAnimation(true);
            UIMANAGER->setIsBattleScript(true); 
            _battleLoadingImage->setFrameX(0);
            _battleLoadingImage->setFrameY(0);
            _loadingCount = 0;
            _isPoketmonMeet = false;
        }
    }   
}

void character::npcScript() // npc 대화 스크립트 처리
{
    // 스크립트 떠있으면 빠져나감
    if (UIMANAGER->getIsScript()) return;

    for (int i = 0; i < 8; i++)
    {
        RECT temp;
        RECT npc = _npc->getnpcRC()[i].detectRC;

        if (IntersectRect(&temp, &_rc, &npc) && !UIMANAGER->isUiOpen() && !_isMoving) // npc 탐지 렉트랑 충돌 시, ui없을 시, 서있을 때
        {
            // 상점 아재 엔드 스크립트 대사 선택
            if (_scriptAction == 1 && i == 7) 
            {
                UIMANAGER->setIsScript(true);           // 스크립트 켜줌.
                UIMANAGER->setNPC(NPC::SHOP, true);     // 엔드 스크립트 선택
                _scriptAction = 0;                      // 스크립트 액션 초기화
            }

            //if (_scriptAction == 1 && 1 == 4)
            //{
            //    _isPoketmonMeet = 1;
            //    _scriptAction = 0;
            //}

            //if (_scriptAction == 1 && 1 == 5)
            //{
            //    _isPoketmonMeet = 1;
            //}

            //if (_scriptAction == 1 && 1 == 6)
            //{
            //    _isPoketmonMeet = 1;
            //}

            if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _scriptAction == 0) // 스페이스바 눌렀을 때
            {
                UIMANAGER->setIsScript(true); // 스크립트 켜줌.

                switch (i) // 충돌된 npc의 대사 선택
                {
                case 0: // 어머니
                    UIMANAGER->setNPC(NPC::MOM, true);
                    break;
                case 1: // 공박사
                    UIMANAGER->setNPC(NPC::GONG, true);
                    break;
                case 2: // 공박사 조수
                    UIMANAGER->setNPC(NPC::SUPPORTER, true);
                    break;
                case 3: // 간호순 눈나ㅏㅏㅏㅏㅏㅏ
                    UIMANAGER->setNPC(NPC::POKECENTER, true);
                    break;
                case 4: // 부하 1
                    UIMANAGER->setNPC(NPC::TRAINER1, true);
                    _scriptAction = 1;                          // 스크립트 액션 = 1
                    break;
                case 5: // 부하 2
                    UIMANAGER->setNPC(NPC::TRAINER2, true);
                    _scriptAction = 1;                          // 스크립트 액션 = 1
                    break;
                case 6: // 비상 관장
                    UIMANAGER->setNPC(NPC::CHAMPION, true);
                    _scriptAction = 1;                          // 스크립트 액션 = 1
                    break;
                case 7: // 상점 아재
                    UIMANAGER->setIsScript(false);              // 스크립트 꺼주고
                    UIMANAGER->setOpenShop(true);               // 상점 오픈
                    _scriptAction = 1;                          // 스크립트 액션 = 1
                    break;
                }                
            }
        }
    }
}

void character::idle(int direction) // 아이들 처리
{
    // 상태 변경 처리
    if (direction == 0 || direction == 1) _state = static_cast<int>(STATE::IDLE_RL);
    else if (direction == 2 || direction == 3) _state = static_cast<int>(STATE::IDLE_UD);

    imageSetting();
}

void character::run(int direction) // 걷기 처리
{
    // 방향 변경 처리
    if (_tileMap->getCameraX() % TILESIZE == 0 && _tileMap->getCameraY() % TILESIZE == 0) _direction = direction;

    // 상태 변경 처리
    if (_direction == 0 || _direction == 1) _state = static_cast<int>(STATE::RUN_RL);
    else if (_direction == 2 || _direction == 3) _state = static_cast<int>(STATE::RUN_UD);

    // 이동 중인지 처리
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) _isMoving = 1;

    imageSetting();
}

void character::tileCheck(int direction) // 타일 체크 처리
{
    // 바라본 방향의 타일이 갈 수 있는 타일인지 체크
    switch (direction)
    {
    case 0: // 오른쪽 방향
        if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile + 1].type == TILETYPE_RIGHTSLOPE) _frontTileType = 5;
        else _frontTileType = 0;

        break;
    case 1: // 왼쪽 방향
        if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile - 1].type == TILETYPE_LEFTSLOPE) _frontTileType = 4;
        else _frontTileType = 0;

        break;
    case 2: // 아래쪽 방향
        if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else if (_tileMap->getTile()[_currentTile + 214].type == TILETYPE_BOTTOMSLOPE) _frontTileType = 6;
        else _frontTileType = 0;

        break;
    case 3: // 위쪽 방향
        if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_OPEN) _frontTileType = 1;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_GRASS) _frontTileType = 2;
        else if (_tileMap->getTile()[_currentTile - 214].type == TILETYPE_DOOR) _frontTileType = 3;
        else _frontTileType = 0;

        break;
    }

    // 아래쪽 방향 볼 때 전체 타일 배열의 개수를 넘어간다면 타일이 없다는 뜻이니 이동 불가 타일로 처리
    if (_currentTile + 214 > TILE && direction == 2) _frontTileType = 0;
}

void character::tileAction() // 캐릭터의 타일 타입에 따른 액션 처리
{
    // 기본, 풀, 문 타일일 때
    if (_frontTileType == 1 || _frontTileType == 2 || _frontTileType == 3)
    {
        switch (_direction) // 방향에 따라 좌표이동
        {
        case 0:
            _tileMap->setCameraX(_tileMap->getCameraX() + 8);
            break;
        case 1:
            _tileMap->setCameraX(_tileMap->getCameraX() - 8);
            break;
        case 2:
            _tileMap->setCameraY(_tileMap->getCameraY() + 8);
            break;
        case 3:
            _tileMap->setCameraY(_tileMap->getCameraY() - 8);
            break;
        }

        // 타일 정중앙에 오면 타일 인덱스 변경, 문, 풀 타일 처리
        if (_tileMap->getCameraX() % TILESIZE == 0 && _tileMap->getCameraY() % TILESIZE == 0)
        {
            _isMoving = 0;

            switch (_direction)                             // 현재 타일 인덱스 변경
            {
            case 0:
                _currentTile += 1;
                break;
            case 1:
                _currentTile -= 1;
                break;
            case 2:
                _currentTile += 214;
                break;
            case 3:
                _currentTile -= 214;
                break;
            }

            if (_frontTileType == 2) grass();               // 풀 타일일 때 처리
            if (_frontTileType == 3) door(_currentTile);    // 문 타일일 때 처리
        }
    }

    // 비탈길일 때
    if (_frontTileType == 4 || _frontTileType == 5)
    {
        if (!_isSloping) _slopeDistance = _tileMap->getCameraX();   // 현재 위치 한 번 기록
        slope(_frontTileType);
    }
    else if (_frontTileType == 6)
    {
        if (!_isSloping) _slopeDistance = _tileMap->getCameraY();   // 현재 위치 한 번 기록
        slope(_frontTileType);
    }
}

void character::grass() // 풀 타일 처리
{
    // 포켓몬 조우 상태 아닐 때 
    if (!_isPoketmonMeet)
    {
        int rndPoketmonMeet = RND->getFromIntTo(1, 100);

        if (rndPoketmonMeet <= POKETMONMEET) _isPoketmonMeet = 1;
        else _isPoketmonMeet = 0;
    }
}

void character::door(int doorIndex) // 문 타일 처리
{
    switch (doorIndex)
    {
    case 5037:  // 필드에서 플레이어 집 1층 이동
        _currentTile = 5485;
        _tileMap->setCameraX(1920);
        _tileMap->setCameraY(192);
        break;
    case 3990:  // 플레이어 집 1층에서 2층 이동
        _currentTile = 4003;
        _tileMap->setCameraX(2944);
        _tileMap->setCameraY(-256);
        break;
    case 4003:  // 플레이어 집 2층에서 1층 이동
        _currentTile = 3990;
        _tileMap->setCameraX(2112);
        _tileMap->setCameraY(-256);
        break;
    case 5485:  // 플레이어 집 1층에서 필드 이동
        _currentTile = 5037;
        _tileMap->setCameraX(640);
        _tileMap->setCameraY(64);
        break;
    case 5486:  // 플레이어 집 1층에서 필드 이동
        _currentTile = 5037;
        _tileMap->setCameraX(640);
        _tileMap->setCameraY(64);
        break;
    case 4602:  // 필드에서 오박사 집 이동
        _currentTile = 6367;
        _tileMap->setCameraX(3584);
        _tileMap->setCameraY(448);
        break;
    case 6367:  // 오박사 집에서 필드 이동
        _currentTile = 4602;
        _tileMap->setCameraX(192);
        _tileMap->setCameraY(-64);
        break;
    case 6368:  // 오박사 집에서 필드 이동
        _currentTile = 4602;
        _tileMap->setCameraX(192);
        _tileMap->setCameraY(-64);
        break;
    case 5381:  // 필드에서 포켓몬 센터 이동
        _currentTile = 5525;
        _tileMap->setCameraX(4480);
        _tileMap->setCameraY(192);
        break;
    case 5525:  // 포켓몬 센터에서 필드 이동
        _currentTile = 5381;
        _tileMap->setCameraX(-4736);
        _tileMap->setCameraY(192);
        break;
    case 5526:  // 포켓몬 센터에서 필드 이동
        _currentTile = 5381;
        _tileMap->setCameraX(-4736);
        _tileMap->setCameraY(192);
        break;
    case 3656:  // 필드에서 체육관 이동
        _currentTile = 7253;
        _tileMap->setCameraX(5504);
        _tileMap->setCameraY(704);
        break;
    case 7253:  // 체육관에서 필드 이동
        _currentTile = 3656;
        _tileMap->setCameraX(-5568);
        _tileMap->setCameraY(-320);
        break;
    case 7254:  // 체육관에서 필드 이동
        _currentTile = 3656;
        _tileMap->setCameraX(-5568);
        _tileMap->setCameraY(-320);
        break;
    case 3647:  // 필드에서 상점 이동
        _currentTile = 5554;
        _tileMap->setCameraX(6336);
        _tileMap->setCameraY(192);
        break;
    case 5554:  // 상점에서 필드 이동
        _currentTile = 3647;
        _tileMap->setCameraX(-6144);
        _tileMap->setCameraY(-320);
        break;
    case 5555:  // 상점에서 필드 이동
        _currentTile = 3647;
        _tileMap->setCameraX(-6144);
        _tileMap->setCameraY(-320);
        break;
    }
}

void character::slope(int direction) // 비탈길 타일 처리
{
    _isSloping = 1;

    switch (direction)
    {
    case 4:     // 왼쪽 비탈길
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraX(_tileMap->getCameraX() - 6);   // 카메라 이동
       
        if (_y > WINSIZEY / 2)  // 캐릭터가 뛰었다가 제자리로 돌아왔을 때
        {
            _y = WINSIZEY / 2;                                      // y 좌표 초기화
            _tileMap->setCameraX(_slopeDistance - (TILESIZE * 2));  // x 좌표 초기화
            _currentTile -= 2;                                      // 타일 인덱스 변경
            _isSloping = _frontTileType = _slopeDistance = 0;       // 나머지 초기화
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;       
        }
        break;
    case 5:     // 오른쪽 비탈길
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraX(_tileMap->getCameraX() + 6);   // 카메라 이동

        if (_y > WINSIZEY / 2)  // 캐릭터가 뛰었다가 제자리로 돌아왔을 때
        {
            _y = WINSIZEY / 2;                                      // y 좌표 초기화
            _tileMap->setCameraX(_slopeDistance + (TILESIZE * 2));  // x 좌표 초기화
            _currentTile += 2;                                      // 타일 인덱스 변경
            _isSloping = _frontTileType = _slopeDistance = 0;       // 나머지 초기화
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;
        }
        break;
    case 6:     // 아래쪽 비탈길
        _y -= _jumpPower;
        _jumpPower -= _gravity;
        _tileMap->setCameraY(_tileMap->getCameraY() + 6);   // 카메라 이동

        if (_y > WINSIZEY / 2)  // 캐릭터가 뛰었다가 제자리로 돌아왔을 때
        {
            _y = WINSIZEY / 2;                                      // y 좌표 초기화
            _tileMap->setCameraY(_slopeDistance + (TILESIZE * 2));  // x 좌표 초기화
            _currentTile += 428;                                    // 타일 인덱스 변경
            _isSloping = _frontTileType = _slopeDistance = 0;       // 나머지 초기화
            _jumpPower = JUMPPOWER;
            _gravity = GRAVITY;
        }
        break;
    }
}

void character::ui() // ui창 호출
{
    // UI창 실행
    if (UIMANAGER->getOpenMenu()) UIMANAGER->menu();
    if (UIMANAGER->getOpenShop()) UIMANAGER->shop();
    if (UIMANAGER->getOpenPokecenter()) UIMANAGER->pokeCenter();
    if (UIMANAGER->getIsBattle()) UIMANAGER->battle();
    if (UIMANAGER->getIsScript()) UIMANAGER->script();
}

void character::poketmonSetting() // 테스트 데이터
{
    _poketmon[0].name = "치코리타";							// 이름
    _poketmon[0].gender = "수컷";							// 성별
    _poketmon[0].isGender = 0;							// 성별 체크
    _poketmon[0].index = 152;								// 인덱스 번호
    _poketmon[0].level = 20;								// 포켓몬 현재 레벨
    _poketmon[0].evolutionLevel = 0;						// 진화 단계

    _poketmon[0].type1 = static_cast<int>(TYPE_PLAYER::GRASS); 								// 포켓몬 타입1	
    _poketmon[0].type2 = static_cast<int>(TYPE_PLAYER::NONE);								// 포켓몬 타입2

    _poketmon[0].iconNumX = 30;							//포켓몬 미니 아이콘 좌표x
    _poketmon[0].iconNumY = 0;								//포켓몬 미니 아이콘 좌표y
    
    _poketmon[0].attack = 49;								// 1레벨 초기 공격
    _poketmon[0].defense = 65;							// 1레벨 초기 방어	
    _poketmon[0].specialAttack = 49;						// 1레벨 초기 특수공격
    _poketmon[0].specialDefense = 65;						// 1레벨 초기 특수방어
    _poketmon[0].speed = 45;								// 1레벨 초기 스피드
    _poketmon[0].currentHP = 45;							// 1레벨 초기 현재 체력
    _poketmon[0].maxHP = 45;								// 1레벨 초기 최대 체력

    _poketmon[0].levelAttack = 1.67f;                     //레벨당 공격력
    _poketmon[0].levelDefense = 1.86f;                    //레벨당 방어력
    _poketmon[0].levelSpecialAttack = 1.67f;              //레벨당 특수공격력
    _poketmon[0].levelSpecialDefense = 1.86f;             //레벨당 특수방어력
    _poketmon[0].levelSpeed = 1.62f;                      //레벨당 스피드
    _poketmon[0].levelHP = 2.49f;                         //레벨당 체력

    _poketmon[0].sumAttack = 1;							// 최종 공격
    _poketmon[0].sumDefense = 1;							// 최종 방어
    _poketmon[0].sumSpecialAttack = 1;					// 최종 특수공격
    _poketmon[0].sumSpecialDefense = 1;					// 최종 특수방어
    _poketmon[0].sumSpeed = 1;							// 최종 스피드
    _poketmon[0].sumMaxHP = 1;							// 최종 체력

    _poketmon[0].currentExp = 800;						// 현재 경험치(현재 얻은 총 경험치, level값 만큼 빼서 나머지 양 보여주기)
    _poketmon[0].maxExp = 1971;							// 최대 경험치(현재 레벨의 최대 경험치 값 표시)

    _poketmon[0].totalEXP = 8800;							// 토탈 경험치

    _poketmon[0].skill1 = 1;								// 스킬1 인덱스 
    _poketmon[0].skill2 = 2;								// 스킬2 인덱스 
    _poketmon[0].skill3 = 3;								// 스킬3 인덱스 
    _poketmon[0].skill4 = 4;								// 스킬4 인덱스 
    _poketmon[0].skillPP1 = 10;							// 스킬1 현재 PP
    _poketmon[0].skillPP2 = 10;							// 스킬2 현재 PP
    _poketmon[0].skillPP3 = 10;							// 스킬3 현재 PP
    _poketmon[0].skillPP4 = 10;							// 스킬4 현재 PP

    _poketmon[0].item = 1;								// 보유 중인 아이템 인덱스

//--------------------------------------------------------------------------------------------------------------
    _poketmon[1].name = "피죤";							// 이름
    _poketmon[1].gender = "암컷";							// 성별
    _poketmon[1].isGender = 1;							// 성별 체크
    _poketmon[1].index = 17;								// 인덱스 번호
    _poketmon[1].level = 20;								// 포켓몬 현재 레벨
    _poketmon[1].evolutionLevel = 1;						// 진화 단계
              
    _poketmon[1].type1 = static_cast<int>(TYPE_PLAYER::FLYING); 								// 포켓몬 타입1	
    _poketmon[1].type2 = static_cast<int>(TYPE_PLAYER::NONE);								// 포켓몬 타입2
              
    _poketmon[1].iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
    _poketmon[1].iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

    _poketmon[1].attack = 49;								// 1레벨 초기 공격
    _poketmon[1].defense = 65;							// 1레벨 초기 방어	
    _poketmon[1].specialAttack = 49;						// 1레벨 초기 특수공격
    _poketmon[1].specialDefense = 65;						// 1레벨 초기 특수방어
    _poketmon[1].speed = 45;								// 1레벨 초기 스피드
    _poketmon[1].currentHP = 45;							// 1레벨 초기 현재 체력
    _poketmon[1].maxHP = 45;								// 1레벨 초기 최대 체력
              
    _poketmon[1].levelAttack = 1.67f;                     //레벨당 공격력
    _poketmon[1].levelDefense = 1.86f;                    //레벨당 방어력
    _poketmon[1].levelSpecialAttack = 1.67f;              //레벨당 특수공격력
    _poketmon[1].levelSpecialDefense = 1.86f;             //레벨당 특수방어력
    _poketmon[1].levelSpeed = 1.62f;                      //레벨당 스피드
    _poketmon[1].levelHP = 2.49f;                         //레벨당 체력
              
    _poketmon[1].sumAttack = 1;							// 최종 공격
    _poketmon[1].sumDefense = 1;							// 최종 방어
    _poketmon[1].sumSpecialAttack = 1;					// 최종 특수공격
    _poketmon[1].sumSpecialDefense = 1;					// 최종 특수방어
    _poketmon[1].sumSpeed = 1;							// 최종 스피드
    _poketmon[1].sumMaxHP = 1;							// 최종 체력
              
    _poketmon[1].currentExp = 800;						// 현재 경험치(현재 얻은 총 경험치, level값 만큼 빼서 나머지 양 보여주기)
    _poketmon[1].maxExp = 1971;							// 최대 경험치(현재 레벨의 최대 경험치 값 표시)
              
    _poketmon[1].totalEXP = 8800;							// 토탈 경험치
              
    _poketmon[1].skill1 = 1;								// 스킬1 인덱스 
    _poketmon[1].skill2 = 2;								// 스킬2 인덱스 
    _poketmon[1].skill3 = 3;								// 스킬3 인덱스 
    _poketmon[1].skill4 = 4;								// 스킬4 인덱스 
    _poketmon[1].skillPP1 = 10;							// 스킬1 현재 PP
    _poketmon[1].skillPP2 = 10;							// 스킬2 현재 PP
    _poketmon[1].skillPP3 = 10;							// 스킬3 현재 PP
    _poketmon[1].skillPP4 = 10;							// 스킬4 현재 PP
              
    _poketmon[1].item = 2;								// 보유 중인 아이템 인덱스
}

void character::render() // 렌더
{    
    // 캐릭터 이미지 렌더
    _image->frameRender(getMemDC(), _rc.left, _rc.top);

    if (KEYMANAGER->isToggleKey(VK_TAB)) // 데이터값들 표시
    {
        Rectangle(getMemDC(), _rc);

        char str[128];
        sprintf_s(str, "_isMoving : %d", _isMoving);
        TextOut(getMemDC(), 100, 160, str, strlen(str));

        sprintf_s(str, "_frontTileType : %d", _frontTileType);
        TextOut(getMemDC(), 100, 190, str, strlen(str));

        sprintf_s(str, "_현재 타일 : %d", _currentTile);
        TextOut(getMemDC(), 100, 220, str, strlen(str));

        sprintf_s(str, "_포켓몬 조우 : %d", _isPoketmonMeet);
        TextOut(getMemDC(), 100, 250, str, strlen(str));

        sprintf_s(str, "_scriptAction : %d", _scriptAction);
        TextOut(getMemDC(), 100, 280, str, strlen(str));
    }
    
    // 비탈길 이동 중일 때 그림자 보여짐
    if (_isSloping) 
    {
        _shadowImage->render(getMemDC(), _rc.left, WINSIZEY / 2 - TILESIZE / 2);
    }

    // 풀 타일 이동 중일 때 풀떼기 이미지 보여짐
    if (_tileMap->getTile()[_currentTile].type == TILETYPE_GRASS)
    {
        if (_grassCount == 0) _grassImage = IMAGEMANAGER->findImage("풀숲1");
        if (_grassCount == 3) _grassImage = IMAGEMANAGER->findImage("풀숲2");
        _grassImage->render(getMemDC(), _x - 22, _y - 2);
        _grassCount++;
        if (_grassCount >= 3) _grassCount = 3;
    }

    // 포켓몬 조우 시 플래시이미지, 배틀로딩이미지 재생
    if (!UIMANAGER->getIsBattle())
    {
        if (_isPoketmonMeet && _loadingCount > 70) _battleLoadingImage->frameRender(getMemDC(), 0, 0);
        if (_isPoketmonMeet && _loadingCount <= 70) _flashLoadingImage->alphaRender(getMemDC(), _alpha);
    }

    // ui창 호출
    ui();
}

void character::imageInit() // 이미지 파일들 불러옴
{
    // 캐릭터
    IMAGEMANAGER->addFrameImage("아이들_좌우", "image/character_idle_RL.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("아이들_상하", "image/character_idle_UD.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("걷기_좌우", "image/character_run_RL.bmp", 112, 128, 2, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("걷기_상하", "image/character_run_UD.bmp", 224, 128, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("캐릭터_그림자", "image/character_shadow.bmp", 56, 64, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("풀숲2", "image/poketmon_grass2.bmp", 45, 21, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("풀숲1", "image/poketmon_grass1.bmp", 48, 36, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("배틀로딩", "image/battle_loading.bmp", 17920, 596, 28, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("플래시로딩", "image/flash_loading.bmp", 640, 576, 1, 1, true, RGB(255, 0, 255));

    //포켓몬 뒤
    IMAGEMANAGER->addFrameImage("155B", "image/poketmon/no_155B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156B", "image/poketmon/no_156B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157B", "image/poketmon/no_157B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152B", "image/poketmon/no_152B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("153B", "image/poketmon/no_153B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("154B", "image/poketmon/no_154B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("158B", "image/poketmon/no_158B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("159B", "image/poketmon/no_159B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("160B", "image/poketmon/no_160B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("25B", "image/poketmon/no_25B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("26B", "image/poketmon/no_26B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("19B", "image/poketmon/no_19B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("20B", "image/poketmon/no_20B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("16B", "image/poketmon/no_16B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("17B", "image/poketmon/no_17B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("18B", "image/poketmon/no_18B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("21B", "image/poketmon/no_21B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("22B", "image/poketmon/no_22B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("10B", "image/poketmon/no_10B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("11B", "image/poketmon/no_11B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("12B", "image/poketmon/no_12B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("13B", "image/poketmon/no_13Bbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("14B", "image/poketmon/no_14B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("15B", "image/poketmon/no_15B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
}


