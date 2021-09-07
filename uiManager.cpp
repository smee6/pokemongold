#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"
#include "character.h"

vector<tagPOKETMON_PLAYER> myPokemon(6);

//6개짜리 내 포켓몬을 담는 배열을 선언해 준다.

struct item {
	int itemNum = 0;
	// 0은 빈칸, 1은 몬스터볼 , 2는 상처약, 3은 고급상처약
	int itemQuan = 0;
	// 아이템 수량
};


uiManager::uiManager()
{
}

uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	
	

	//불러오는거 ... ?
	//_character->getPoketmon(0).name;

	//인벤토리를 10칸으로 초기화해준다 . 빈칸이 10개가 생김 ( 0~9)
	IMAGEMANAGER->addImage("사다", "image/shopUI/shop_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("팔다", "image/shopUI/shop_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("그만두다", "image/shopUI/shop_3.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("몬스터볼", "image/shopUI/buy_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상처약", "image/shopUI/buy_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("고급상처약", "image/shopUI/buy_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("안산다", "image/shopUI/buy_4.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("menu0", "image/menuUI/menu_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu1", "image/menuUI/menu_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu2", "image/menuUI/menu_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu3", "image/menuUI/menu_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu4", "image/menuUI/menu_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu5", "image/menuUI/menu_6.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu6", "image/menuUI/menu_7.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bag0", "image/bag/bag_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag1", "image/bag/bag_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag2", "image/bag/bag_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bag3", "image/bag/bag_3.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("pokeShift0", "image/menuUI/pokeShift_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift1", "image/menuUI/pokeShift_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift2", "image/menuUI/pokeShift_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift3", "image/menuUI/pokeShift_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift4", "image/menuUI/pokeShift_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift5", "image/menuUI/pokeShift_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift6", "image/menuUI/pokeShift_6.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	//_vScript = TXTDATA->txtLoad("Test.txt");		// 경로("script/OO.txt");

	return S_OK;
}

void uiManager::release()
{

}

void uiManager::update()
{
	//if (KEYMANAGER->isOnceKeyDown('P'))
	//{
	//	_isScript = true;
	//}
}

void uiManager::render()
{
}

void uiManager::shop()
{
	uiOpen = true;
	shopWindow = true;

	if (shopWindow) {

		// 스위치 넣어서 상점이 열려있을때만
		if (!buyWindow) {
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && shopCnt < 2) {
				shopCnt += 1;
				//메뉴 화살표 위아래 움직이는
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && shopCnt > 0) {
				shopCnt -= 1;
			}
		}

		switch (shopCnt)
		{
		case 0:
			IMAGEMANAGER->findImage("사다")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("팔다")->render(_backBuffer->getMemDC());
			break;
		case 2:
			IMAGEMANAGER->findImage("그만두다")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				shopWindow = false;
				uiOpen = false;
				shopCnt = 0;
				_isOpenShop = false;
				return;
			}
			break;
		}

		if (shopCnt == 0 && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			buyWindow = true;
			//상점 구현 
		};

		if (buyWindow) {

			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && buyCnt < 4) {
				buyCnt += 1;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && buyCnt > 0) {
				buyCnt -= 1;
			}

			switch (buyCnt) {
			case 0:
				IMAGEMANAGER->findImage("몬스터볼")->render(_backBuffer->getMemDC());
				// 나중에 여기서 돈 검사해서 있으면 Q (수량) 을 늘려주게 코드 몇줄만 추가
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					pokeballQ++;
				};
				break;
			case 1:
				IMAGEMANAGER->findImage("상처약")->render(_backBuffer->getMemDC());
				// 나중에 여기서 돈 검사해서 있으면 Q (수량) 을 늘려주게 코드 몇줄만 추가
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					medicineQ++;
				};
				break;
			case 2:
				IMAGEMANAGER->findImage("고급상처약")->render(_backBuffer->getMemDC());
				// 나중에 여기서 돈 검사해서 있으면 Q (수량) 을 늘려주게 코드 몇줄만 추가
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					goodMedicineQ++;
				};
				break;
			case 3:
				IMAGEMANAGER->findImage("안산다")->render(_backBuffer->getMemDC());

				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					buyCnt = 0;
					//shopCnt = 0;
					buyWindow = false;
					//상점 구현 
				};

				break;
			}


		}
	
	}

}

void uiManager::pokeCenter()
{
	uiOpen = true;
	IMAGEMANAGER->findImage("pokeCenter")->frameRender(_backBuffer->getMemDC(), 170, 105, _index, 0);

	cnt++;

	if (cnt == 15) {
		_index++;
		cnt = 0;
	}

	if (_index > 10) {
		_index = 0;
		uiOpen = false;
	}
}

void uiManager::menu()
{
	uiOpen = true;

	if (!bagWindow) {
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && menuCnt < 6) {
			menuCnt += 1;
			//메뉴 화살표 위아래 움직이는
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
			menuCnt -= 1;
		}
	}


	switch (menuCnt)
	{
	case 0: //도감
		IMAGEMANAGER->findImage("menu0")->render(_backBuffer->getMemDC());
		break;
	case 1: //포켓몬
		IMAGEMANAGER->findImage("menu1")->render(_backBuffer->getMemDC());
		break;
	case 2://가방
		IMAGEMANAGER->findImage("menu2")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
			_isOpenBag = true;
			//bag();
		};
		break;
	case 3://포켓기어
		IMAGEMANAGER->findImage("menu3")->render(_backBuffer->getMemDC());
		break;
	case 4://이름
		IMAGEMANAGER->findImage("menu4")->render(_backBuffer->getMemDC());
		break;
	case 5://설정
		IMAGEMANAGER->findImage("menu5")->render(_backBuffer->getMemDC());
		break;
	case 6://닫다
		IMAGEMANAGER->findImage("menu6")->render(_backBuffer->getMemDC());
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			uiOpen = false;
			_isOpenMenu = false;
			menuCnt = 0;
		}
		return;
		break;
	}

	if (_isOpenBag)
	{
		bag();
	}


}

void uiManager::pokeShift()
{
	pokeWindow = true;
	if (pokeWindow) {


			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && pokesCnt < 6) {
				pokesCnt += 1;
				//메뉴 화살표 위아래 움직이는
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && pokesCnt > 0) {
				pokesCnt -= 1;
			}

		switch (pokesCnt)
		{
		case 0:
			IMAGEMANAGER->findImage("pokeShift0")->render(_backBuffer->getMemDC());
			break;
		case 1: 
			IMAGEMANAGER->findImage("pokeShift1")->render(_backBuffer->getMemDC());
			break;
		case 2:
			IMAGEMANAGER->findImage("pokeShift2")->render(_backBuffer->getMemDC());
			break;
		case 3:
			IMAGEMANAGER->findImage("pokeShift3")->render(_backBuffer->getMemDC());
			break;
		case 4:
			IMAGEMANAGER->findImage("pokeShift4")->render(_backBuffer->getMemDC());
			break;
		case 5:
			IMAGEMANAGER->findImage("pokeShift5")->render(_backBuffer->getMemDC());
			break;
		case 6:
			IMAGEMANAGER->findImage("pokeShift6")->render(_backBuffer->getMemDC());
			break;
		}

		
		//아래와 같은식으로 필요할때 포켓몬 정보를 받아온다 <- 나중에 코드 놓는 위치를 유동적으로 바꿔야함
		for (int i = 0; i < myPokemon.size(); i++) {
			myPokemon[i].name = _character->getPoketmon(i).name;
			myPokemon[i].maxHP = _character->getPoketmon(i).maxHP;
			myPokemon[i].currentHP = _character->getPoketmon(i).currentHP;
			myPokemon[i].level = _character->getPoketmon(i).level;
		}

		char str[128];
		
		

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(38, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


		char poke[128];


		for (int i = 0; i < myPokemon.size(); i++) {
			string strname = myPokemon[i].name;
			strcpy_s(poke, strname.c_str());

			sprintf_s(str, "%s", poke);
			TextOut(_backBuffer->getMemDC(), 100, 15+ (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].maxHP);
			TextOut(_backBuffer->getMemDC(), 530, 3 + (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].currentHP);
			TextOut(_backBuffer->getMemDC(), 440, 3 + (i * 65), str, strlen(str));

			sprintf_s(str, "%d", myPokemon[i].level);
			TextOut(_backBuffer->getMemDC(), 320, 25 + (i * 65), str, strlen(str));

		}
		
		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);


	
	}
	

}


void uiManager::bag()
{
	bagWindow = true;

	if (bagWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && bagCnt < 3) {
			bagCnt ++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && bagCnt > 0) {
			bagCnt --;
		}


		switch (bagCnt) {

		case 0: // 가방에서 몬스터볼에 커서가 있다
			IMAGEMANAGER->findImage("bag0")->render(_backBuffer->getMemDC());
			//클릭했을때 수량이 1개 이상이면 사용됨 아니면 걍 무시
			if (pokeballQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					pokeballQ++;
				};
			}
			break;
		case 1:// 가방에서 상처약에 커서가 있다
			IMAGEMANAGER->findImage("bag1")->render(_backBuffer->getMemDC());
			if (medicineQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					medicineQ++;
				};
			}
			break;
		case 2:// 가방에서 고급상처약에 커서가 있다
			IMAGEMANAGER->findImage("bag2")->render(_backBuffer->getMemDC());
			if (goodMedicineQ > 0) {
				if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {
					goodMedicineQ++;
				};
			}
			break;
		case 3:// 가방에서 나가기에 커서가 있다
			IMAGEMANAGER->findImage("bag3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyUp(VK_SPACE)) {

				bagCnt = 0;
				bagWindow = false;
				uiOpen = false;
				_isOpenBag = false;
				
			};

			break;
		}



		//수량을 텍스트로 표시해주는 부분
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Arial"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", pokeballQ);
		TextOut(_backBuffer->getMemDC(), 595, 78, str, strlen(str));


		sprintf_s(str, "%d", medicineQ);
		TextOut(_backBuffer->getMemDC(), 595, 143, str, strlen(str));

		sprintf_s(str, "%d", goodMedicineQ);
		TextOut(_backBuffer->getMemDC(), 595, 210, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);

	}

}



void uiManager::script()
{
	uiOpen = true;

	switch (_npc)
	{
	case NPC::TITLE:
		_vScript = TXTDATA->txtLoad("script/타이틀.txt");
		break;
	case NPC::MOM_FIRST:
		_vScript = TXTDATA->txtLoad("script/엄마1.txt");
		break;
	case NPC::MOM_NORMAL:
		_vScript = TXTDATA->txtLoad("script/엄마2.txt");
		break;
	case NPC::DR_FIRST:
		_vScript = TXTDATA->txtLoad("script/공박사_처음.txt");
		break;
	case NPC::DR_BEFORE_POKEMON:
		_vScript = TXTDATA->txtLoad("script/공박사_포켓몬전.txt");
		break;
	case NPC::DR_AFTER_POKEMON:
		_vScript = TXTDATA->txtLoad("script/공박사_포켓몬후.txt");
		break;
	case NPC::DR_NORMAL:
		_vScript = TXTDATA->txtLoad("script/공박사_일상.txt");
		break;
	case NPC::SUPPORTER:
		_vScript = TXTDATA->txtLoad("script/조수.txt");
		break;
	case NPC::CHAMPION_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/관장배틀시작.txt");
		break;
	case NPC::CHAMPION_BATTLE_AFTER:
		_vScript = TXTDATA->txtLoad("script/관장배틀후.txt");
		break;
	case NPC::CHAMPION_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/관장배틀끝.txt");
		break;
	case NPC::TRAINER1_BATTLE_BEFORE:
		_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀전.txt");
		break;
	case NPC::TRAINER1_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀진입.txt");
		break;
	case NPC::TRAINER1_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀후.txt");
		break;
	case NPC::TRAINER1_BATTLE_WIN:
		_vScript = TXTDATA->txtLoad("script/쫄따구1_승리정산.txt");
		break;
	case NPC::TRAINER2_BATTLE_BEFORE:
		_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀전.txt");
		break;
	case NPC::TRAINER2_BATTLE_START:
		_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀진입.txt");
		break;
	case NPC::TRAINER2_BATTLE_END:
		_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀후.txt");
		break;
	case NPC::TRAINER2_BATTLE_WIN:
		_vScript = TXTDATA->txtLoad("script/쫄따구2_승리정산.txt");
		break;
	case NPC::POKECENTER:
		_vScript = TXTDATA->txtLoad("script/간호순.txt");
		break;
	case NPC::SHOP:
		_vScript = TXTDATA->txtLoad("script/상점.txt");
		break;
	case NPC::EVOLUTION:
		_vScript = TXTDATA->txtLoad("script/진화.txt");
		break;
	case NPC::TOTODILE:
		_vScript = TXTDATA->txtLoad("script/리아코.txt");
		break;
	case NPC::CHIKORITA:
		_vScript = TXTDATA->txtLoad("script/치코리타.txt");
		break;
	case NPC::CYNDAQUIL:
		_vScript = TXTDATA->txtLoad("script/브케인.txt");
		break;
	case NPC::SELECTCANCEL:
		_vScript = TXTDATA->txtLoad("script/스타팅선택취소.txt");
		break;
	case NPC::BATTLE:
		_vScript = TXTDATA->txtLoad("script/배틀(임시).txt");
		break;
	default:
		break;
	}
	

	// 대화 스킵
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isScriptSkip = true;
	}

	// 대화 중
	if (_isScript)
	{
		// 마지막 쓰레기값 나와서 -1까지
		if (_scriptIndex >= _vScript.size() - 1)
		{
			// 끝나면 스크립트 종료 및 초기화(다음 스크립트 위해서)
			_isScript = false;
			_txtIndex = 0;
			_scriptIndex = 0;
			uiOpen = false;
		}

		// 배경이미지 렌더
		_scriptImage->render(_backBuffer->getMemDC());

		// 받아온 텍스트정보를 넘겨줌
		_txt = _vScript[_scriptIndex];

		// 스킵이 아닐 경우에
		if (!_isScriptSkip)
		{
			// 문장 전체 길이보다 현재가 작으면
			if (_txtIndex < _txt.length())
			{
				// 한 글자씩 출력
				_txtIndex++;
			}
			// 현재 문자열의 길이가 문장 전체 길이보다 커지려고하면
			else if (_txtIndex >= _txt.length())
			{
				// 버튼을 누르면
				if (KEYMANAGER->isOnceKeyDown('I'))
				{
					// 스킵 상태 false(다음 문장 스킵되지 않도록)
					_isScriptSkip = false;

					// 문자 인덱스 초기화 해주고 다음 줄로 넘겨줌
					_txtIndex = 0;
					_scriptIndex++;
				}
			}
		}
		// 스킵하면
		else if (_isScriptSkip)
		{
			// 현재 문자열이 전체 길이보다 길어지려고 하면
			if (_txtIndex >= _txt.length())
			{
				// 스킵 상태 false
				_isScriptSkip = false;
				
				// 문자 인덱스 초기화해주고 다음 줄로 넘겨줌
				_txtIndex = 0;
				_scriptIndex++;
			}
			// 현재 문자열의 길이가 전체 길이보다 작으면
			else if (_txtIndex < _txt.length())
			{
				// 스킵 상태 false
				_isScriptSkip = false;
				
				// 현재 문장 전부 출력
				_txtIndex = _txt.length();
			}
		}

		SetBkMode(_backBuffer->getMemDC(), TRANSPARENT);
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));
		RECT rcText = RectMake(30, WINSIZEY - 120, 500, 70);

		HFONT font = CreateFont(35, 0, 0, 0, 200, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼매직체"));

		HFONT oldFont = (HFONT)SelectObject(_backBuffer->getMemDC(), font);

		DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(_backBuffer->getMemDC(), oldFont);
		DeleteObject(font);
	}
}

bool uiManager::isUiOpen()
{
	return uiOpen;
}
