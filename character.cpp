#include "pch.h"
#include "character.h"
#include "poketmonManager.h"
#include "tileMap.h"

character::character()
{
}

character::~character()
{
}

HRESULT character::init() // 인잇
{
    imageInit();

    _image = IMAGEMANAGER->findImage("아이들_좌우");

    _direction = _isMoving = 0;
    _frameCount = _currentFrame = 0;
    _x = WINSIZEX / 2 + 32;
    _y = WINSIZEY / 2;

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


}

void character::controll() // 캐릭터 컨트롤 처리
{
    // 아이들
    if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) idle(0);
    if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) idle(1);
    if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) idle(2);
    if (KEYMANAGER->isOnceKeyUp(VK_UP)) idle(3);

    // 걷기
    if (!_isMoving)
    {
        if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) // 오른쪽 이동
        {
            run(0);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_LEFT)) // 왼쪽 이동
        {
            run(1);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_DOWN)) // 아래 이동
        {
            run(2);
            move();
        }

        if (KEYMANAGER->isStayKeyDown(VK_UP)) // 위 이동
        {
            run(3);
            move();
        }
    }

    // 카메라 타일 이동
    if (_tileMap->getCameraX() % TILESIZE != 0 || _tileMap->getCameraY() % TILESIZE != 0) move();
    
    // Z Key
    if (KEYMANAGER->isOnceKeyDown('Z'))
    {

    }

    // X Key
    if (KEYMANAGER->isOnceKeyDown('X'))
    {

    }
}

void character::imageSetting() // 현재 이미지 세팅
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

    // 카운트가 일정 수치마다 프레임X 갱신
    _frameCount++;
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
}

void character::idle(int direction) // 아이들 처리
{
    // 상태 변경 처리
    if (direction == 0 || direction == 1) _state = static_cast<int>(STATE::IDLE_RL);
    else if (direction == 2 || direction == 3) _state = static_cast<int>(STATE::IDLE_UD);

    _isMoving = 0;

    imageSetting();
}

void character::run(int direction) // 걷기 처리
{
    // 방향 변경 처리
    if (_tileMap->getCameraY() % TILESIZE == 0 && _tileMap->getCameraX() % TILESIZE == 0) _direction = direction;

    // 상태 변경 처리
    if (_direction == 0 || _direction == 1) _state = static_cast<int>(STATE::RUN_RL);
    else if (_direction == 2 || _direction == 3) _state = static_cast<int>(STATE::RUN_UD);

    // 이동 중인지 처리
    if (_tileMap->getCameraX() % TILESIZE != 0 && _tileMap->getCameraY() % TILESIZE != 0) _isMoving = 1;
    else _isMoving = 0;

    imageSetting();
}

void character::move() // 좌표 이동 처리
{
    switch (_direction)
    {
    case 0:
        _tileMap->setCameraX(_tileMap->getCameraX() + 4);
        break;
    case 1:
        _tileMap->setCameraX(_tileMap->getCameraX() - 4);
        break;
    case 2:
        _tileMap->setCameraY(_tileMap->getCameraY() + 4);
        break;
    case 3:
        _tileMap->setCameraY(_tileMap->getCameraY() - 4);
        break;
    }
}

void character::render() // 렌더
{
    _image->frameRender(getMemDC(), _rc.left, _rc.top);

    if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        Rectangle(getMemDC(), _rc);
    }
    
}

void character::imageInit() // 파일 이미지들 불러옴
{
    // 캐릭터
    IMAGEMANAGER->addFrameImage("아이들_좌우", "image/character_idle_RL.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("아이들_상하", "image/character_idle_UD.bmp", 56, 128, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("걷기_좌우", "image/character_run_RL.bmp", 112, 128, 2, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("걷기_상하", "image/character_run_UD.bmp", 224, 128, 4, 2, true, RGB(255, 0, 255));

    //포켓몬 뒤
    IMAGEMANAGER->addFrameImage("브케인_뒤", "image/poketmon/no_155B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("마그케인_뒤", "image/poketmon/no_156B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("블레이범_뒤", "image/poketmon/no_157B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("치코리타_뒤", "image/poketmon/no_152B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("베이리프_뒤", "image/poketmon/no_153B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("메가니움_뒤", "image/poketmon/no_154B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("리아코_뒤", "image/poketmon/no_158B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("엘리게이_뒤", "image/poketmon/no_159B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("장크로다일_뒤", "image/poketmon/no_160B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피카츄_뒤", "image/poketmon/no_25B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("라이츄_뒤", "image/poketmon/no_26B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("꼬렛_뒤", "image/poketmon/no_19B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("레트라_뒤", "image/poketmon/no_20B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("구구_뒤", "image/poketmon/no_16B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피죤_뒤", "image/poketmon/no_17B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피죤투_뒤", "image/poketmon/no_18B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("깨비참_뒤", "image/poketmon/no_21B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("깨비드릴조_뒤", "image/poketmon/no_22B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("캐터피_뒤", "image/poketmon/no_10B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("단데기_뒤", "image/poketmon/no_11B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("버터플_뒤", "image/poketmon/no_12B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("뿔충이_뒤", "image/poketmon/no_13Bbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("딱충이_뒤", "image/poketmon/no_14B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("독침붕_뒤", "image/poketmon/no_15B.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));

}


