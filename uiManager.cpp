#include "pch.h"
#include "uiManager.h"
#include "gameNode.h"
#include "character.h"
#include "progressBar.h"
#include "poketmonManager.h"
#include "tileMap.h"

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

	// =======================================================================================================================

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

	IMAGEMANAGER->addImage("power", "image/menuUI/power_0.bmp", 640, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("pokeShift0", "image/menuUI/pokeShift_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift1", "image/menuUI/pokeShift_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift2", "image/menuUI/pokeShift_2.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift3", "image/menuUI/pokeShift_3.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift4", "image/menuUI/pokeShift_4.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift5", "image/menuUI/pokeShift_5.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pokeShift6", "image/menuUI/pokeShift_6.bmp", 640, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================
	IMAGEMANAGER->addImage("gear0", "image/menuUI/gear_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gear1", "image/menuUI/gear_1.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gear2", "image/menuUI/gear_2.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("pointer", "image/menuUI/map_p.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("status0", "image/menuUI/status_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("status1", "image/menuUI/status_1.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("setting0", "image/menuUI/setting_0.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("setting1", "image/menuUI/setting_1.bmp", 640, 576, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("dogam0", "image/menuUI/dogam_0.bmp", 640, 576, true, RGB(255, 0, 255));
	// =======================================================================================================================

	IMAGEMANAGER->addImage("배틀배경", "image/battle/battleBackground.bmp", 640, 576, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배틀행동선택", "image/battle/selectBehavior.bmp", 640, 186, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스킬선택", "image/battle/backgroundSkill.bmp", 640, 289, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("커서", "image/battle/cursorBehavior.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어", "image/battle/playerImage.bmp", 188, 192, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("포켓볼상태", "image/battle/poketballState.bmp", 28, 112, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("성별", "image/battle/gender.bmp", 7, 16, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("포켓몬출근", "image/battle/appearPokemon.bmp", 600, 200, 3, 1,  true, RGB(255, 0, 255));

	// ========================================================================================================================

	IMAGEMANAGER->addFrameImage("pokeCenter", "image/shopUI/pokeCenter.bmp", 500, 60, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("Icon", "image/menuUI/pokeicon.bmp", 2048, 191, 32, 3, true, RGB(255, 0, 255));

	_scriptImage = IMAGEMANAGER->addImage("script", "image/dialogueUI.bmp", 650, 576, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("예", "image/Yes.bmp", 192, 183, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("아니오", "image/No.bmp", 192, 183, true, RGB(255, 0, 255));

	// =======================================================================================================================

	IMAGEMANAGER->addImage("관장", "image/battle/champion.bmp", 220, 220, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("트레이너", "image/battle/trainer.bmp", 220, 220, true, RGB(255, 0, 255));

	// =======================================================================================================================

	_isAnimation = true;

	_hpBarPlayer = new progressBar;
	_hpBarPlayer->init(WINSIZEX - 161 - 192, 297, 192, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp", "hpFront", "hpBack");
	//_hpBarPlayer->setGauge(100, 100);

	_hpBarEnemy = new progressBar;
	_hpBarEnemy->init(33, 72, 191, 8, "image/battle/hpGauge.bmp", "image/battle/hpGaugeBack.bmp", "eHpFront", "eHpBack");

	_expBar = new progressBar;
	_expBar->init(WINSIZEX - 193 - 256, 365, 256, 8, "image/battle/expGauge.bmp", "image/battle/expGaugeBack.bmp", "expFront", "expBack");
	//_expBar->setGauge(100, 100);

	return S_OK;
}

void uiManager::release()
{

}

void uiManager::update()
{
	_isConfirm = true;
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
		//uiOpen = false;
		_isCount = true;
		_isScript = true;
		_isOpenPokecenter = false;
	}
}
/// <메뉴> ////////////////////////////////////////////
/// <메뉴> ////////////////////////////////////////////
/// <메뉴> ////////////////////////////////////////////

void uiManager::menu()
{
	uiOpen = true;

	if (!pokedogamWindow) {
		if (!statusWindow) {
			if (!settingWindow) {
				if (!pokeWindow) {
					if (!bagWindow) {
						if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && menuCnt < 6) {
							menuCnt += 1;
							//메뉴 화살표 위아래 움직이는
						}
						if (KEYMANAGER->isOnceKeyDown(VK_UP) && menuCnt > 0) {
							menuCnt -= 1;
						}
					}
				}
			}
		}
	}
	if (!_isOpenBag && !_isOpenPokemon && !_isOpenPokeDogam && !_isOpenPokeGear && !_isOpenPlayerStatus && !_isOpenSetting)
	{
		if (KEYMANAGER->isOnceKeyDown('X')) {

				uiOpen = false;
				_isOpenMenu = false;
				menuCnt = 0;
		
		}
		switch (menuCnt)
		{
		case 0: //도감
			IMAGEMANAGER->findImage("menu0")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenPokeDogam = true;

			};
			break;
		case 1: //포켓몬
			IMAGEMANAGER->findImage("menu1")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenPokemon = true;

			};
			break;
		case 2://가방
			IMAGEMANAGER->findImage("menu2")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenBag = true;

			};
			break;
		case 3://포켓기어
			IMAGEMANAGER->findImage("menu3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenPokeGear = true;

			};
			break;
		case 4://이름
			IMAGEMANAGER->findImage("menu4")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenPlayerStatus = true;

			};
			break;
		case 5://설정
			IMAGEMANAGER->findImage("menu5")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_isOpenSetting = true;

			};
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
	}

	if (_isOpenBag)
	{
		bag();
	}
	if (_isOpenPlayerStatus)
	{
		playerStatus();
	}
	if (_isOpenPokeDogam)
	{
		pokeDogam();
	}
	if (_isOpenSetting)
	{
		setting();
	}
	if (_isOpenPokeGear)
	{
		pokeGear();
	}
	if (_isOpenPokemon) {
		pokeShift();
	}

	if (_isOpenHowStrong) {
		howStrong();
	}
}

void uiManager::pokeShift()
{
	pokeWindow = true;

	if(!howStrongWindow) {
		if (pokeWindow) {

			if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && pokesCnt < 6) {
				pokesCnt += 1;

				//메뉴 화살표 위아래 움직이는
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP) && pokesCnt > 0) {
				pokesCnt -= 1;
			}
			if (KEYMANAGER->isOnceKeyDown('X')) {
				pokesCnt = 0;
				pokeWindow = false;
				_isOpenPokemon = false;
			}
		}
		if (!useMedicineWindow) {
			if (!useGoodMedicineWindow) {
				if (_isBattle && _character->getPoketmon(pokesCnt).maxHP != 0 && pokesCnt < 6)
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_currentPoke = pokesCnt;

						pokesCnt = 0;
						pokeWindow = false;
						_isOpenPokemon = false;
					}
				}
			}
		}
		switch (pokesCnt)
		{
		case 0:
			IMAGEMANAGER->findImage("pokeShift0")->render(_backBuffer->getMemDC());
			if (!_isBattle &&!useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(0, -50);
				if (_character->getPoketmon(0).currentHP >= _character->getPoketmon(0).sumMaxHP) {
					_character->setCurrentHP(0, _character->getPoketmon(0).currentHP - _character->getPoketmon(0).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(0, -100);
				if (_character->getPoketmon(0).currentHP >= _character->getPoketmon(0).sumMaxHP) {
					_character->setCurrentHP(0, _character->getPoketmon(0).currentHP - _character->getPoketmon(0).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 1: 
			IMAGEMANAGER->findImage("pokeShift1")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(1, -50);
				if (_character->getPoketmon(1).currentHP >= _character->getPoketmon(1).sumMaxHP) {
					_character->setCurrentHP(1, _character->getPoketmon(1).currentHP - _character->getPoketmon(1).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(1, -100);
				if (_character->getPoketmon(1).currentHP >= _character->getPoketmon(1).sumMaxHP) {
					_character->setCurrentHP(1, _character->getPoketmon(1).currentHP - _character->getPoketmon(1).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 2:
			IMAGEMANAGER->findImage("pokeShift2")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(2, -50);
				if (_character->getPoketmon(2).currentHP >= _character->getPoketmon(2).sumMaxHP) {
					_character->setCurrentHP(2, _character->getPoketmon(2).currentHP - _character->getPoketmon(2).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(2, -100);
				if (_character->getPoketmon(2).currentHP >= _character->getPoketmon(2).sumMaxHP) {
					_character->setCurrentHP(2, _character->getPoketmon(0).currentHP - _character->getPoketmon(2).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 3:
			IMAGEMANAGER->findImage("pokeShift3")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(3, -50);
				if (_character->getPoketmon(3).currentHP >= _character->getPoketmon(3).sumMaxHP) {
					_character->setCurrentHP(3, _character->getPoketmon(3).currentHP - _character->getPoketmon(3).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(3, -100);
				if (_character->getPoketmon(3).currentHP >= _character->getPoketmon(3).sumMaxHP) {
					_character->setCurrentHP(3, _character->getPoketmon(3).currentHP - _character->getPoketmon(3).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 4:
			IMAGEMANAGER->findImage("pokeShift4")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(4, -50);
				if (_character->getPoketmon(4).currentHP >= _character->getPoketmon(4).sumMaxHP) {
					_character->setCurrentHP(4, _character->getPoketmon(4).currentHP - _character->getPoketmon(4).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(4, -100);
				if (_character->getPoketmon(4).currentHP >= _character->getPoketmon(4).sumMaxHP) {
					_character->setCurrentHP(4, _character->getPoketmon(4).currentHP - _character->getPoketmon(4).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 5:
			IMAGEMANAGER->findImage("pokeShift5")->render(_backBuffer->getMemDC());
			if (!_isBattle && !useMedicineWindow && !useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				if (_character->getPoketmon(pokesCnt).maxHP == 0) return;
				//강한정도를 보다
				_isOpenHowStrong = true;
				//강한정도를 보다 끝

			}
			if (useMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(5, -50);
				if (_character->getPoketmon(5).currentHP >= _character->getPoketmon(5).sumMaxHP) {
					_character->setCurrentHP(5, _character->getPoketmon(5).currentHP - _character->getPoketmon(5).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useMedicineWindow = false;
			}
			if (useGoodMedicineWindow && KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				_character->setCurrentHP(5, -100);
				if (_character->getPoketmon(5).currentHP >= _character->getPoketmon(5).sumMaxHP) {
					_character->setCurrentHP(5, _character->getPoketmon(5).currentHP - _character->getPoketmon(5).sumMaxHP);
				}
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
				useGoodMedicineWindow = false;
			}
			break;
		case 6:
			IMAGEMANAGER->findImage("pokeShift6")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				pokeWindow = false;
				_isOpenPokemon = false;
				pokesCnt = 0;
			}

			break;
		}

		//아래와 같은식으로 필요할때 포켓몬 정보를 받아온다 <- 나중에 코드 놓는 위치를 유동적으로 바꿔야함
		for (int i = 0; i < myPokemon.size(); i++) {
			myPokemon[i].name = _character->getPoketmon(i).name;
			myPokemon[i].sumMaxHP = _character->getPoketmon(i).sumMaxHP;
			myPokemon[i].currentHP = _character->getPoketmon(i).currentHP;
			myPokemon[i].level = _character->getPoketmon(i).level;
			myPokemon[i].iconNumX = _character->getPoketmon(i).iconNumX;
			myPokemon[i].iconNumY = _character->getPoketmon(i).iconNumY;
		}


		char str[128];
		
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font5 = CreateFont(30, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

		delaycnt++;

		char poke[128];

		if (delaycnt == 8) {
			iconCnt++;
			delaycnt = 0;
		}
		
		for (int i = 0; i < myPokemon.size(); i++) {
			string strname = myPokemon[i].name;
			strcpy_s(poke, strname.c_str());

			if (myPokemon[i].sumMaxHP == 0) return;

			IMAGEMANAGER->findImage("Icon")->frameRender(_backBuffer->getMemDC(),35,15 + 
				(i * 65), myPokemon[i].iconNumX+(iconCnt%2), myPokemon[i].iconNumY);

			sprintf_s(str, "%s",poke);
			TextOut(_backBuffer->getMemDC(), 100, 15+ (i * 65), str, strlen(str));

			sprintf_s(str, "/%d", myPokemon[i].sumMaxHP);
			TextOut(_backBuffer->getMemDC(), 530, 25 + (i * 63), str, strlen(str));

			sprintf_s(str, "HP : %d", myPokemon[i].currentHP);
			TextOut(_backBuffer->getMemDC(), 386, 25 + (i * 63), str, strlen(str));

			sprintf_s(str, ": L %d", myPokemon[i].level);
			TextOut(_backBuffer->getMemDC(), 260, 25 + (i * 63), str, strlen(str));

		}
		
		SelectObject(_backBuffer->getMemDC(), oldFont5);
		DeleteObject(font5);
	}
}


void uiManager::bag()
{
	bagWindow = true;

	// KEYMANAGER->init(); 아니 뭔데 이닛해줘도 그러는데 ; 아오 진짜

	if (bagWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && bagCnt < 3) {
			bagCnt ++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && bagCnt > 0) {
			bagCnt --;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			bagCnt = 0;
			bagWindow = false;
			uiOpen = false;
			_isOpenBag = false;

		};


		switch (bagCnt) {

		case 0: // 가방에서 몬스터볼에 커서가 있다
			IMAGEMANAGER->findImage("bag0")->render(_backBuffer->getMemDC());
			//클릭했을때 수량이 1개 이상이면 사용됨 아니면 걍 무시
			
			if (pokeballQ > 0) {
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					// 배틀 중일 때에만 사용 가능
					if (!_isBattle) return;

					// 보유 포켓몬이 꽉찬 경우에 사용 불가
					if (_character->getPoketmon(5).maxHP != 0) return;
					pokeballQ--;
					usePokeBall();
					//전투중이 아닌 경우 못 씀
					//전투중에 쓸경우 뭐 대충 bool 값 체크해서 사용하게 해줌 
				};
			}
			break;
		case 1:// 가방에서 상처약에 커서가 있다
			IMAGEMANAGER->findImage("bag1")->render(_backBuffer->getMemDC());
			if (medicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					medicineQ--;
					bagCnt = 0;
					bagWindow = false;
					uiOpen = false;
					_isOpenBag = false;
					//포켓몬 선택창으로 이동후 대상지정해서 체력회복
					useMedicineWindow = true;
					_isOpenPokemon = true;
				};
			}
			break;
		case 2:// 가방에서 고급상처약에 커서가 있다
			IMAGEMANAGER->findImage("bag2")->render(_backBuffer->getMemDC());
			if (goodMedicineQ > 0) {
				if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
					goodMedicineQ--;
					//포켓몬 선택창으로 이동후 대상지정해서 체력회복
					bagCnt = 0;
					bagWindow = false;
					uiOpen = false;
					_isOpenBag = false;
					//포켓몬 선택창으로 이동후 대상지정해서 체력회복
					useGoodMedicineWindow = true;
					_isOpenPokemon = true;
				};
			}
			break;
		case 3:// 가방에서 나가기에 커서가 있다
			IMAGEMANAGER->findImage("bag3")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {

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

		HFONT font2 = CreateFont(28, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", pokeballQ);
		TextOut(_backBuffer->getMemDC(), 590, 78, str, strlen(str));


		sprintf_s(str, "%d", medicineQ);
		TextOut(_backBuffer->getMemDC(), 590, 143, str, strlen(str));

		sprintf_s(str, "%d", goodMedicineQ);
		TextOut(_backBuffer->getMemDC(), 590, 210, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	}
}
////////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
// 추가로 작업할것 //////////////////
////////////////////////////////////
///////////////////////////////////
//////////////////////////////////
void uiManager::pokeDogam()
{
	pokedogamWindow = true;
	if (pokedogamWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && dogamCnt < 1) {
			dogamCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && dogamCnt > 0) {
			dogamCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			dogamCnt = 0;
			pokedogamWindow = false;
			uiOpen = false;
			_isOpenPokeDogam = false;

		};

		switch (dogamCnt) {
		case 0:
			IMAGEMANAGER->findImage("dogam0")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("dogam0")->render(_backBuffer->getMemDC());
			break;
		}
	}

}

void uiManager::pokeGear()
{

	gearWindow = true;
	if (gearWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && gearCnt < 2) {
			gearCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && gearCnt > 0) {
			gearCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			gearCnt = 0;
			gearWindow = false;
			uiOpen = false;
			_isOpenPokeGear = false;

		};
		switch (gearCnt) {
		case 0:
			IMAGEMANAGER->findImage("gear0")->render(_backBuffer->getMemDC());

			break;
		case 1:
			IMAGEMANAGER->findImage("gear1")->render(_backBuffer->getMemDC());
			IMAGEMANAGER->findImage("pointer")->render(_backBuffer->getMemDC(),
				535+_tileMap->getCameraX() / 13, 
				240+ _tileMap->getCameraY() /16);
			break;
		case 2:
			IMAGEMANAGER->findImage("gear2")->render(_backBuffer->getMemDC());

			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {

				gearCnt = 0;
				gearWindow = false;
				uiOpen = false;
				_isOpenPokeGear = false;

			};

			break;
		
		}


		if (gearCnt == 0) {
			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);


			sprintf_s(str, "포켓기어를 사용할 수 있습니다.");
			TextOut(_backBuffer->getMemDC(), 135, 190, str, strlen(str));
			sprintf_s(str, "목요일 10 시 00 분");
			TextOut(_backBuffer->getMemDC(), 135, 240, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont2);
			DeleteObject(font2);
		}




	}


}

void uiManager::playerStatus()
{
	statusWindow = true;
	if (statusWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && statusCnt < 1) {
			statusCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && statusCnt > 0) {
			statusCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			statusCnt = 0;
			statusWindow = false;
			uiOpen = false;
			_isOpenPlayerStatus = false;

		};
		switch (statusCnt) {
		case 0:
			IMAGEMANAGER->findImage("status0")->render(_backBuffer->getMemDC());
			break;
		case 1:
			IMAGEMANAGER->findImage("status1")->render(_backBuffer->getMemDC());
			break;
		
		
		}



		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(52, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "레드");
		TextOut(_backBuffer->getMemDC(), 180, 50, str, strlen(str));

		HFONT font21 = CreateFont(32, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont21 = (HFONT)SelectObject(_backBuffer->getMemDC(), font21);

		sprintf_s(str, "%d",gold);
		TextOut(_backBuffer->getMemDC(), 290, 190, str, strlen(str));


		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);

		SelectObject(_backBuffer->getMemDC(), oldFont21);
		DeleteObject(font21);

	}



}

void uiManager::setting()
{

	settingWindow = true;
	if (settingWindow) {

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && settingCnt < 3) {
			settingCnt++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP) && settingCnt > 0) {
			settingCnt--;
		}
		if (KEYMANAGER->isOnceKeyDown('X')) {

			settingCnt = 0;
			settingWindow = false;
			uiOpen = false;
			_isOpenSetting = false;

		};

		switch (settingCnt) {
		case 0:
			IMAGEMANAGER->findImage("setting0")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && soundVolume < 100) {
				soundVolume++;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT) && soundVolume > 0) {
				soundVolume--;
			}

			break;
		case 1:
			IMAGEMANAGER->findImage("setting1")->render(_backBuffer->getMemDC());
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
				settingCnt = 0;
				settingWindow = false;
				uiOpen = false;
				_isOpenSetting = false;
			}


			break;
		
		}


		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(56, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		sprintf_s(str, "%d", soundVolume);
		TextOut(_backBuffer->getMemDC(), 500, 50, str, strlen(str));


		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);


	}


}

void uiManager::howStrong()
{
	howStrongWindow = true;
	IMAGEMANAGER->findImage("power")->render(_backBuffer->getMemDC());

	char str[128];

	SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

	HFONT font2 = CreateFont(38, 0, 0, 0, 700, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).index);
	TextOut(_backBuffer->getMemDC(), 85, 1, str, strlen(str));

	sprintf_s(str, (_character->getPoketmon(pokesCnt).name + _character->getPoketmon(pokesCnt).gender).c_str());
	TextOut(_backBuffer->getMemDC(), 50, 430, str, strlen(str));

	IMAGEMANAGER->findImage(to_string(_character->getPoketmon(pokesCnt).index) + "F")->render(_backBuffer->getMemDC(),20,150);

	sprintf_s(str, ":L %d", _character->getPoketmon(pokesCnt).level);
	TextOut(_backBuffer->getMemDC(), 50, 370, str, strlen(str));


	sprintf_s(str, "/ %d", _character->getPoketmon(pokesCnt).sumMaxHP);
	TextOut(_backBuffer->getMemDC(), 460, 150, str, strlen(str));

	sprintf_s(str, "HP : %d", _character->getPoketmon(pokesCnt).currentHP);
	TextOut(_backBuffer->getMemDC(), 280, 150, str, strlen(str));


	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumAttack);
	TextOut(_backBuffer->getMemDC(), 510, 240, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumDefense);
	TextOut(_backBuffer->getMemDC(), 510, 310, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpecialAttack);
	TextOut(_backBuffer->getMemDC(), 510, 380, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpecialDefense);
	TextOut(_backBuffer->getMemDC(), 510, 440, str, strlen(str));

	sprintf_s(str, "%d", _character->getPoketmon(pokesCnt).sumSpeed);
	TextOut(_backBuffer->getMemDC(), 510, 500, str, strlen(str));


	for (int i = 0; i < 4; i++) {
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[i]);
		sprintf_s(str, _poketmonManager->getSkill()->getSkillName().c_str());

		TextOut(_backBuffer->getMemDC(), 285, 5 + (i * 37), str, strlen(str));
	}





	SelectObject(_backBuffer->getMemDC(), oldFont2);
	DeleteObject(font2);


	if (KEYMANAGER->isOnceKeyDown('X')) {

		howStrongWindow = false;
		_isOpenHowStrong = false;

	};


}

// 여기까지 메뉴 안쪽 버튼 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void uiManager::script()
{
	uiOpen = true;

	if (_isCount)
	{
		switch (_npc)
		{
		case NPC::TITLE:
			_vScript = TXTDATA->txtLoad("script/타이틀.txt");
			break;
		case NPC::MOM:
			if (_momCount == 0)	_vScript = TXTDATA->txtLoad("script/조수.txt");
			else _vScript = TXTDATA->txtLoad("script/엄마2.txt");

			_momCount++;

			break;
		case NPC::GONG:
			if (_drCount == 0) _vScript = TXTDATA->txtLoad("script/공박사_처음.txt");
			else if (_drCount == 1) _vScript = TXTDATA->txtLoad("script/공박사_포켓몬전.txt");
			else if (_drCount == 2) _vScript = TXTDATA->txtLoad("script/공박사_포켓몬후.txt");
			else _vScript = TXTDATA->txtLoad("script/공박사_일상.txt");

			if (_drCount == 1 && !_isStarting) break;
			_drCount++;

			break;
		case NPC::SUPPORTER:
			_vScript = TXTDATA->txtLoad("script/조수.txt");
			break;
		case NPC::CHAMPION:
			if (_championCount == 0) _vScript = TXTDATA->txtLoad("script/관장_배틀시작.txt");
			else if (_championCount == 1) _vScript = TXTDATA->txtLoad("script/관장_배틀후.txt");
			else if (_championCount == 2) _vScript = TXTDATA->txtLoad("script/관장_배틀끝.txt");
			else _vScript = TXTDATA->txtLoad("script/관장_일상.txt");

			_championCount++;

			break;
		case NPC::TRAINER1:
			if (_trainer1Count == 0)_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀전.txt");
			else if (_trainer1Count == 1)_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀진입.txt");
			else if (_trainer1Count == 2)_vScript = TXTDATA->txtLoad("script/쫄따구1_배틀후.txt");
			else _vScript = TXTDATA->txtLoad("script/쫄따구1_승리정산.txt");

			_trainer1Count++;

			break;
		case NPC::TRAINER2:
			if (_trainer2Count == 0)_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀전.txt");
			else if (_trainer2Count == 1)_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀진입.txt");
			else if (_trainer2Count == 2)_vScript = TXTDATA->txtLoad("script/쫄따구2_배틀후.txt");
			else _vScript = TXTDATA->txtLoad("script/쫄따구2_승리정산.txt");

			_trainer2Count++;

			break;
		case NPC::POKECENTER:
			if (_pokecenterCount == 0) _vScript = TXTDATA->txtLoad("script/간호순_시작.txt");
			else _vScript = TXTDATA->txtLoad("script/간호순_끝.txt");

			_pokecenterCount++;

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
			_vScript = TXTDATA->txtLoad("script/배틀.txt");
			break;
		case NPC::BATTLE_ATTACK:
			_vScript = TXTDATA->txtLoad("script/공격.txt");
			break;
		case NPC::BATTLE_DOWN:
			switch (_whoTurn)
			{
			case 1:
				_vScript = TXTDATA->txtLoad("script/야생배틀승리.txt");
				break;
			case 2:
				_vScript = TXTDATA->txtLoad("script/패배.txt");
				break;
			}
			break;
		default:
			break;
		}

		_isCount = false;
	}
	
	// 대화 스킵
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isScriptSkip = true;
	}

	// 대화 중
	if (_isScript)
	{
		// 마지막 쓰레기값 나와서 -1까지
		if (_scriptIndex >= _vScript.size() - 1)
		{
			// 배틀 스크립트면 배틀 스크립트 종료
			if (_isBattleScript)
			{
				_isBattleScript = false;
			}
			if (_npc == NPC::POKECENTER && _pokecenterCount == 1)
			{
				_isOpenPokecenter = true;
				uiOpen = true;
			}

			if (_npc == NPC::POKECENTER && _pokecenterCount >= 2)
			{
				_pokecenterCount = 0;
			}

			if (_isAttack && _attackCount < 1)
			{
				_isTurn = true;
				_isNext = false;
			}

			if (_attackCount > 0)
			{
				_isTurn = true;
				_attackCount++;
			}

			//if (_isWin)
			//{
			//	_time = TIMEMANAGER->getWorldTime();
			//	_character->setTotalExp(_currentPoke, 50);
			//}

			if (_isBattle && (_poketmonManager->getWildPoketmon().currentHP <= 0 || _character->getPoketmon(_currentPoke).currentHP <= 0))
			{
				_isAttack = false;
				_isBattle = false;
				_attackCount = 0;
				_isTurn = false;
				_isNext = false;
				_whoTurn = 0;

				if (_character->getPoketmon(_currentPoke).currentHP <= 0)
				{
					_character->setCurrentHP(_currentPoke, _character->getPoketmon(_currentPoke).currentHP - _character->getPoketmon(_currentPoke).sumMaxHP);
				}
			}

			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				_isStarting == true;
				getStartingPokemon();
			}

			// 끝나면 스크립트 종료 및 초기화(다음 스크립트 위해서)
			_isScript = false;
			_txtIndex = 0;
			_scriptIndex = 0;
			uiOpen = false;
		}

		if (_isBattle)
		{
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
					if (_isWin && _scriptIndex == 1)
					{
						_isWin = false;
						_character->setTotalExp(_currentPoke, 50);
					}
					// 버튼을 누르면
					if (!_isConfirm)
					{
						if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
						{
							// 스킵 상태 false(다음 문장 스킵되지 않도록)
							_isScriptSkip = false;

							// 문자 인덱스 초기화 해주고 다음 줄로 넘겨줌
							_txtIndex = 0;
							_scriptIndex++;
						}
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
		}
		// 배틀 아닐 때
		else if (!_isBattle)
		{
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
					// 스킵 상태 false(다음 문장 스킵되지 않도록)
					_isScriptSkip = false;

					// 스타팅 포켓몬 선택중인 경우
					if ((_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA) && _scriptIndex == 0 && _txtIndex == _txt.length())
					{
						_isAccept = false;
						_isConfirm = true;
						_txtIndex++;
					}
					// 버튼을 누르면
					if (!_isConfirm)
					{
						if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
						{
							// 문자 인덱스 초기화 해주고 다음 줄로 넘겨줌
							_txtIndex = 0;
							_scriptIndex++;
						}
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
		}

		SetBkMode(_backBuffer->getMemDC(), TRANSPARENT);
		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));
		RECT rcText = RectMake(30, WINSIZEY - 150, 500, 120);

		HFONT font = CreateFont(60, 0, 0, 0, 500, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont = (HFONT)SelectObject(_backBuffer->getMemDC(), font);

		DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);

		SelectObject(_backBuffer->getMemDC(), oldFont);
		DeleteObject(font);


		char str[128];

		sprintf_s(str, "battle : %d", _isBattle);
		TextOut(_backBuffer->getMemDC(), 300, 10, str, strlen(str));

		sprintf_s(str, "confirm : %d", _isConfirm);
		TextOut(_backBuffer->getMemDC(), 300, 30, str, strlen(str));

		sprintf_s(str, "script : %d", _isScript);
		TextOut(_backBuffer->getMemDC(), 300, 50, str, strlen(str));

		sprintf_s(str, "%s", _currentEnemyPokemon.name.c_str());
		TextOut(_backBuffer->getMemDC(), 300, 70, str, strlen(str));
	}
}

void uiManager::battle()
{
	uiOpen = true;

	// 배경색 RGB(248, 248, 248)
	IMAGEMANAGER->findImage("배틀배경")->render(_backBuffer->getMemDC());

	_playerImage = IMAGEMANAGER->findImage("플레이어");
	
	if (_isWild)
	{
		_currentEnemyPokemon = _poketmonManager->getWildPoketmon();
	}
	else if (!_isWild)
	{
		switch (_npc)
		{
		case NPC::CHAMPION:
			_enemyImage = IMAGEMANAGER->findImage("관장");
			_currentEnemyPokemon = _poketmonManager->getChampionPoketmon()[0];
			_npc = NPC::CHAMPION;
			break;
		case NPC::TRAINER1:
			_enemyImage = IMAGEMANAGER->findImage("트레이너");
			_currentEnemyPokemon = _poketmonManager->getTrainer1Poketmon()[0];
			_npc = NPC::TRAINER1;
			break;
		case NPC::TRAINER2:
			_enemyImage = IMAGEMANAGER->findImage("트레이너");
			_currentEnemyPokemon = _poketmonManager->getTrainer2Poketmon()[0];
			_npc = NPC::TRAINER2;
			break;
		default:
			_enemyImage = IMAGEMANAGER->findImage("관장");
			_currentEnemyPokemon = _poketmonManager->getTrainer2Poketmon()[0];
			_npc = NPC::CHAMPION;
		}
	}

	_currentPokemon = _character->getPoketmon(0);

	vector<string> _vStr;
	_vStr.push_back("야생의 " + _currentEnemyPokemon.name + "(이)가\n승부를 걸어왔다!;" + "레드" + "는(은)\n" + _currentPokemon.name + "를(을);차례로 꺼냈다!;가랏! " + _currentPokemon.name + "!;" + _currentPokemon.name + "\n와(과)의 승부에서 이겼다!;");

	TXTDATA->txtSave("script/배틀.txt", _vStr);

	_playerPokeImage = IMAGEMANAGER->findImage(to_string(_character->getPoketmon(_currentPoke).index) + "B");

	// 야생포켓몬과의 배틀일 경우
	_enemyPokeImage = IMAGEMANAGER->findImage(to_string(_currentEnemyPokemon.index) + "F");

	static int px = -_playerImage->getWidth();
	static int ex = WINSIZEX;

	// 야생 포켓몬과의 전투일 때
	if (_isWild)
	{
		//_npc = NPC::BATTLE;
		// 야생일 때에는 처음 이미지 그대로 유지	(추후에 야생 / 트레이너 두 개를 구분해서 사용)
		_enemyPokeImage->render(_backBuffer->getMemDC(), ex, 0);
	}

	// 경험치 올라가는거 시간 조정하려고 했던 것
	//if (_isWin && TIMEMANAGER->getWorldTime() >= _time + 1)
	//{
	//	_isAttack = false;
	//	_isBattle = false;
	//	_attackCount = 0;
	//	_isTurn = false;
	//	_isNext = false;
	//	_whoTurn = 0;
	//	_isWin = false;
	//}

	if (_isAnimation) //플레이어쪽에서 트루로 바꿔줘야함
	{
		_playerImage->render(_backBuffer->getMemDC(), px, 200);

		// 트레이너와의 전투일 때
		if (!_isWild)
		{
			_enemyImage->render(_backBuffer->getMemDC(), ex, 0);
		}

		if (ex >= WINSIZEX - 230)
		{
			ex -= 5;
		}

		if (px <= 70)
		{
			px += 5; // 플레이어 이미지가 화면밖에서 제자리 까지 이동하는것을 구현하기 위함
			//_npc = NPC::BATTLE;
		}
		else if (_isBattleScript && !_isScript)
		{
			_isCount = true;
			_isScript = true;
		}
		else if (!_isScript)
		{
			_time = TIMEMANAGER->getWorldTime();
			_isAnimation = false;
		}
	}
	else if (!_isAnimation && TIMEMANAGER->getWorldTime() >= _time + 0.3)
	{
		if (_appearIndex >= 0)
		{
			IMAGEMANAGER->findImage("포켓몬출근")->frameRender(_backBuffer->getMemDC(), 70, 200, _appearIndex, 0);

			// 트레이너와의 배틀일 경우
			if (!_isWild) IMAGEMANAGER->findImage("포켓몬출근")->frameRender(_backBuffer->getMemDC(), WINSIZEX - 230, 0, _appearIndex, 0);

			_behaviorCount = 0;
		}

		static int count = 0;
		count++;

		if (count % 7 == 0) // 포켓몬이 볼에서 나올때
		{
			_appearIndex--;
		}

		if (_appearIndex < 0) // 포켓몬이 등장한 후
		{
			//string index;
			//index = _character->getPoketmon(0).index;

			// 이미지 출력
			_playerPokeImage->frameRender(_backBuffer->getMemDC(), 70, 200);

			// 트레이너와의 배틀일 경우
			if (!_isWild) _enemyPokeImage->frameRender(_backBuffer->getMemDC(), WINSIZEX - 230, 0);

			_currentHP = _character->getPoketmon(_currentPoke).currentHP;
			_maxHP = _character->getPoketmon(_currentPoke).sumMaxHP;
			_currentEXP = _character->getPoketmon(_currentPoke).currentExp;
			_maxEXP = _character->getPoketmon(_currentPoke).maxExp;
			
			// 플레이어 체력바
			_hpBarPlayer->setGauge(_currentHP, _maxHP);
			_hpBarPlayer->render();

			// 에너미 체력바
			_hpBarEnemy->setGauge(_currentEnemyPokemon.currentHP, _currentEnemyPokemon.sumMaxHP);
			_hpBarEnemy->render();

			// 경험치 바
			_expBar->setGauge(_currentEXP, _maxEXP);
			_expBar->render();

			// 이름 띄우기
			char str[128];

			SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

			HFONT font5 = CreateFont(45, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// 내 포켓몬
			sprintf_s(str, (_character->getPoketmon(_currentPoke).name + _character->getPoketmon(_currentPoke).gender).c_str());
			//DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);		// 추후에 오른쪽 정렬 쓰려면
			TextOut(_backBuffer->getMemDC(), 320, 245, str, strlen(str));

			// 상대 포켓몬
			sprintf_s(str, (_currentEnemyPokemon.name + _currentEnemyPokemon.gender).c_str());
			TextOut(_backBuffer->getMemDC(), 70, 20, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);

			// 레벨 띄우기
			font5 = CreateFont(40, 0, 0, 0, 700, false, false, false,
				DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

			oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

			// 내 포켓몬
			sprintf_s(str, to_string(_character->getPoketmon(_currentPoke).level).c_str());
			//DrawText(_backBuffer->getMemDC(), TEXT(_txt.c_str()), _txtIndex, &rcText, DT_VCENTER | DT_VCENTER | DT_WORDBREAK);		// 추후에 오른쪽 정렬 쓰려면
			TextOut(_backBuffer->getMemDC(), 545, 247, str, strlen(str));

			// 상대 포켓몬
			sprintf_s(str, to_string(_currentEnemyPokemon.level).c_str());
			TextOut(_backBuffer->getMemDC(), 285, 25, str, strlen(str));

			SelectObject(_backBuffer->getMemDC(), oldFont5);
			DeleteObject(font5);
			//IMAGEMANAGER->findImage(index + "");

			

			//	커서의 위치
			if (!_isOpenSkill && !_isOpenPokemon && !_isOpenBag && !_isAttack && !_isScript)
			{
				if (_behaviorCount == 0)			// 싸우다
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenSkill = true;
					}

					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						_behaviorCount = 1;			// 가방
					}
					else if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_behaviorCount = 2;			// 포켓몬 보유창
					}
				}
				if (_behaviorCount == 1)			// 가방
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenBag = true;
					}
					if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
					{
						_behaviorCount = 3;			// 도망가다
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						_behaviorCount = 0;			// 싸우다
					}

				}
				if (_behaviorCount == 2)			// 포켓몬 보유창
				{
					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						_isOpenPokemon = true;
						
					}
					if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_behaviorCount = 0;			// 싸우다
					}
					if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
					{
						_behaviorCount = 3;			// 도망가다
					}
				}
				if (_behaviorCount == 3)			// 도망가다
				{

					if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
					{
						uiOpen = false;
						_isBattle = false;
						_behaviorCount = 0;
						px = -_playerImage->getWidth();
						ex = WINSIZEX + _enemyPokeImage->getWidth();
						_appearIndex = 2;
					}
					if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
					{
						_behaviorCount = 2;			// 포켓몬 보유창
					}
					if (KEYMANAGER->isOnceKeyDown(VK_UP))
					{
						_behaviorCount = 1;			// 가방
					}
				}
			}
			// 커서의 기준점 - 싸우다
			IMAGEMANAGER->findImage("커서")->render(_backBuffer->getMemDC(), 285 + (_behaviorCount % 2)*160, 445 + (_behaviorCount / 2)*60);
		}
	}
	if (_isOpenBag)
	{
		bag();
	}
	if (_isOpenSkill)
	{
		skillSelect();
	}
	if (_isOpenPokemon)
	{
		pokeShift();
	}
	if (_isAttack)
	{
		attack();
	}

	char str[128];

	sprintf_s(str, "%d", _poketmonManager->getWildPoketmon().level);
	TextOut(_backBuffer->getMemDC(), 10, 10, str, strlen(str));
}

void uiManager::skillSelect()
{
	static int skillCnt = 0;

	IMAGEMANAGER->findImage("스킬선택")->render(_backBuffer->getMemDC(), 0, 287);

	SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

	HFONT font5 = CreateFont(38, 0, 0, 0, 700, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont5 = (HFONT)SelectObject(_backBuffer->getMemDC(), font5);

	char skill[128];
	char type[128];
	char pp[128];

	for (int i = 0; i < 4; i++) {
		//string strname = myPokemon[i].name;
		//strcpy_s(poke, strname.c_str());
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[i]);
		sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());

		TextOut(_backBuffer->getMemDC(), 55, 330 + (i * 60), skill, strlen(skill));
	}

	if (skillCnt > 0)
	{
		if(KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			skillCnt--;
		}
	}
	if (skillCnt < 3)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			skillCnt++;
		}
	}

	IMAGEMANAGER->findImage("커서")->render(_backBuffer->getMemDC(), 25, 335 + (skillCnt * 60));

	switch (skillCnt)
	{
	case 0:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[0]);
		_currentSkill = 0;
		break;
	case 1:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[1]);
		_currentSkill = 1;
		break;
	case 2:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[2]);
		_currentSkill = 2;
		break;
	case 3:
		_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[3]);
		_currentSkill = 3;
		break;
	}

	switch ((SKILL_TYPE)_poketmonManager->getSkill()->getSkillType())
	{
	case SKILL_TYPE::NOMAL:
		sprintf_s(type, "노말");
		break;
	case SKILL_TYPE::FIRE:
		sprintf_s(type, "불꽃");
		break;
	case SKILL_TYPE::WATER:
		sprintf_s(type, "물");
		break;
	case SKILL_TYPE::GRASS:
		sprintf_s(type, "풀");
		break;
	case SKILL_TYPE::ELECTR:
		sprintf_s(type, "전기");
		break;
	case SKILL_TYPE::ICE:
		sprintf_s(type, "얼음");
		break;
	case SKILL_TYPE::FIGHT:
		sprintf_s(type, "격투");
		break;
	case SKILL_TYPE::POISON:
		sprintf_s(type, "독");
		break;
	case SKILL_TYPE::GROUND:
		sprintf_s(type, "땅");
		break;
	case SKILL_TYPE::FLYING:
		sprintf_s(type, "비행");
		break;
	case SKILL_TYPE::PSYCHC:
		sprintf_s(type, "에스퍼");
		break;
	case SKILL_TYPE::BUG:
		sprintf_s(type, "벌레");
		break;
	case SKILL_TYPE::ROCK:
		sprintf_s(type, "바위");
		break;
	case SKILL_TYPE::GHOST:
		sprintf_s(type, "고스트");
		break;
	case SKILL_TYPE::DRAGON:
		sprintf_s(type, "드래곤");
		break;
	case SKILL_TYPE::DARK:
		sprintf_s(type, "악");
		break;
	case SKILL_TYPE::STEEL:
		sprintf_s(type, "강철");
		break;
	case SKILL_TYPE::FAIRY:
		sprintf_s(type, "페어리");
		break;
	default:
		break;
	}
	sprintf_s(pp, "%00d/%00d", _character->getPoketmon(_currentPoke).skillPP[_currentSkill], _poketmonManager->getSkill()->getSkillPP());
	TextOut(_backBuffer->getMemDC(), 445, 425, pp, strlen(pp));
	TextOut(_backBuffer->getMemDC(), 485, 510, type, strlen(type));

	SelectObject(_backBuffer->getMemDC(), oldFont5);
	DeleteObject(font5);

	// 선택하면 공격 실행
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		//_poketmonManager->getSkill()->setIsSkill(true);
		//skillCnt = 0;
		_power = _poketmonManager->getSkill()->getSkillPower();
		_isAttack = true;
		_isOpenSkill = false;
		_npc = NPC::BATTLE_ATTACK;
	}

	if (KEYMANAGER->isOnceKeyDown('X')) // 스킬창 끄기
	{
		//skillCnt = 0;
		_isOpenSkill = false;
	}
}

void uiManager::attack() //어택
{
	// 포켓몬 쓰러지는거 체크
	if (_character->getPoketmon(_currentPoke).currentHP <= 0)
	{

	}

	// 속도 비교
	// 플레이어가 더 빠를 때
	if (_character->getPoketmon(_currentPoke).speed >= _poketmonManager->getWildPoketmon().speed)
	{
		// 내 턴
		if (_attackCount == 0)
		{
			if (!_isNext && !_isTurn)
			{
				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_character->getPoketmon(_currentPoke).name + "의\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/공격.txt", _vStr);

				_isScript = true;
				_isCount = true;
			}
			if (_isTurn)
			{
				_whoTurn = 1;
				_poketmonManager->getSkill()->setWhoSkill(false);
				_poketmonManager->getSkill()->setIsSkill(true);

				_attackCount++;

				//_poketmonManager->setCurrentHP(_character->getPoketmon(_currentPoke).sumAttack * _power);
				_poketmonManager->setCurrentHP(10);

				if (_poketmonManager->getWildPoketmon().currentHP <= 0)
				{

					vector<string> _vStr;

					_vStr.push_back("야생의 " + _poketmonManager->getWildPoketmon().name + "는(은) 쓰러졌다!;" + _character->getPoketmon(_currentPoke).name + "는(은) 50의 경험치를 획득했다!;" + "레드는(은) 500원을 획득했다!;" + "aaa;");

					TXTDATA->txtSave("script/야생배틀승리.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					_isScript = true;
					_isCount = true;
					_isWin = true;
				}
			}
		}
		
		// 상대 턴
		else if (_attackCount > 0)
		{
			if (_isTurn && _isNext)
			{
				_whoTurn = 2;
				_poketmonManager->getSkill()->setWhoSkill(true);
				_poketmonManager->getSkill()->setIsSkill(true);
				//_character->setCurrentHP(_currentPoke, _poketmonManager->getWildPoketmon().sumAttack * _poketmonManager->getSkill()->getSkillPower());
				_character->setCurrentHP(_currentPoke, 10);

				if (_character->getPoketmon(_currentPoke).currentHP <= 0)
				{
					vector<string> _vStr;

					_vStr.push_back(_character->getPoketmon(_currentPoke).name + "는(은) 쓰러졌다!;" + "aaa;");

					TXTDATA->txtSave("script/패배.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					_isScript = true;
					_isCount = true;
				}

				_isTurn = false;
				_isNext = false;
			}
			else if (_isNext)
			{
				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_poketmonManager->getWildPoketmon().skill[RND->getInt(4)]);
				if (_poketmonManager->getSkill()->getSkillName() == " -")
				{
					while (true)
					{
						if (_poketmonManager->getSkill()->getSkillName() != " -") break;
						_poketmonManager->getSkill()->skillNumLink(_poketmonManager->getWildPoketmon().skill[RND->getInt(4)]);
					}
				}
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_poketmonManager->getWildPoketmon().name + "의\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/공격.txt", _vStr);
				//_poketmonManager->getWildPoketmon();//getSkill()->setIsSkill(true);						// 야생 포켓몬 공격 애니메이션 출력
			}

		}
	}

	// 상대가 빠를 때
	else
	{
		// 상대 턴
		if (_attackCount == 0)
		{
			if (!_isNext && !_isTurn)
			{
				_isNext = true;

				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_poketmonManager->getWildPoketmon().skill[RND->getInt(4)]);
				if (_poketmonManager->getSkill()->getSkillName() == " -")
				{
					while (true)
					{
						if (_poketmonManager->getSkill()->getSkillName() != " -") break;
						_poketmonManager->getSkill()->skillNumLink(_poketmonManager->getWildPoketmon().skill[RND->getInt(4)]);
					}
				}
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_poketmonManager->getWildPoketmon().name + "의\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/공격.txt", _vStr);

				_isScript = true;
				_isCount = true;
			}
			if (_isTurn)
			{
				_whoTurn = 2;
				_poketmonManager->getSkill()->setWhoSkill(true);
				_poketmonManager->getSkill()->setIsSkill(true);

				_attackCount++;

				//_character->setCurrentHP(_currentPoke, _poketmonManager->getWildPoketmon().sumAttack * _poketmonManager->getSkill()->getSkillPower());
				_character->setCurrentHP(_currentPoke, 10);

				if (_character->getPoketmon(_currentPoke).currentHP <= 0)
				{
					vector<string> _vStr;

					_vStr.push_back(_character->getPoketmon(_currentPoke).name + "는(은) 쓰러졌다!;" + "aaa;");

					TXTDATA->txtSave("script/패배.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					_isScript = true;
					_isCount = true;
				}
			}
		}

		// 내 턴
		else if (_attackCount > 0)
		{
			if (_isTurn && _isNext)
			{
				_whoTurn = 1;
				_poketmonManager->getSkill()->setWhoSkill(false);
				_poketmonManager->getSkill()->setIsSkill(true);

				//_poketmonManager->setCurrentHP(_character->getPoketmon(_currentPoke).sumAttack * _power);
				_poketmonManager->setCurrentHP(10);

				_isTurn = false;
				_isNext = false;

				if (_poketmonManager->getWildPoketmon().currentHP <= 0)
				{

					vector<string> _vStr;

					_vStr.push_back("야생의 " + _poketmonManager->getWildPoketmon().name + "는(은) 쓰러졌다!;" + _character->getPoketmon(_currentPoke).name + "는(은) 50의 경험치를 획득했다!;" + "레드는(은) 500원을 획득했다!;" + "aaa;");

					TXTDATA->txtSave("script/야생배틀승리.txt", _vStr);

					_npc = NPC::BATTLE_DOWN;
					_isScript = true;
					_isCount = true;
					_isWin = true;
				}
			}
			else if (_isNext)
			{
				vector<string> _vStr;

				char skill[128];

				_poketmonManager->getSkill()->skillNumLink(_character->getPoketmon(_currentPoke).skill[_currentSkill]);
				sprintf_s(skill, _poketmonManager->getSkill()->getSkillName().c_str());
				_vStr.push_back(_character->getPoketmon(_currentPoke).name + "의\n" + skill + "!;" + "aaa;");

				TXTDATA->txtSave("script/공격.txt", _vStr);
				
				//_poketmonManager->getWildPoketmon();//getSkill()->setIsSkill(true);						// 야생 포켓몬 공격 애니메이션 출력
			}

		}
	}
}

void uiManager::usePokeBall()
{
	//포켓볼 사용시 내 쪽에서 포켓볼 날아가고
	//포켓볼이 상대 포켓몬에 맞을시 포켓몬 이미지 사라지고 포켓볼 흔들거리는 이미지 출력
	//확률적으로 포획성공시 성공 시 성공장면 출력 - 내 소유 포켓몬 구조체 정보저장 - 배틀 끝 - 인게임씬
	//포획 실패시 다시 포켓몬 이미지 출력해주고 배틀 재개

	//포켓볼 포물선으로 날아가는 이미지 출력

	//맞았을때 좌우로 흔들거리는 프레임이미지 출력

	//잡았다 - 보유 구조체 3번에 저장(레벨, 젠더, 보유기술)
	for (int i = 0; i < 6; i++)
	{
		if (_character->getPoketmon(i).maxHP == 0)		// 빈 자리일 경우
		{
			_character->setPoketmon(_poketmonManager->getWildPoketmon(), i);		// 보유 포켓몬에 추가

			// 한마리 잡으면 종료
			break;
		}
	}

	uiOpen = false;
	_isBattle = false;
	_isOpenBag = false;
	bagWindow = false;
	_px = -_playerImage->getWidth();
	_ex = WINSIZEX + _enemyPokeImage->getWidth();
	_behaviorCount = 0;
	_appearIndex = 2;
}

void uiManager::useMedicine()
{
	//사용 대상의 체력을 50 회복한다
	//함수로 안하고 직접 가방안에 넣어서 만들었습니다.
}

void uiManager::useGoodMedicine()
{
	//사용 대상의 체력을 100 회복한다
	//함수로 안하고 직접 가방안에 넣어서 만들었습니다.
}

void uiManager::getStartingPokemon()
{
	//// 공박사와 대화 한 번 진행된 후에
	//if (_drCount == 1)
	//{
	//
	//}
	// 포켓볼에 말걸면 스크립트 출력

	// (예/아니오 선택)
	
	// 포켓몬 획득 (스타팅 포켓몬 초기값 정보 필요 - 이름, 레벨, 공격력 등등)
	switch (_npc)
	{
	case NPC::CYNDAQUIL:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[0], 0);		// 0번 슬롯에 포켓몬 추가
		_isGetCyndaquil = true;
		break;
	case NPC::TOTODILE:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[1], 0);		// 0번 슬롯에 포켓몬 추가
		_isGetTotodile = true;
		break;
	case NPC::CHIKORITA:
		_character->setPoketmon(_poketmonManager->getStartPoketmon()[2], 0);		// 0번 슬롯에 포켓몬 추가
		_isGetChikorita = true;
		break;
	}
	_drCount++;
	//_isStarting = true;
}

void uiManager::confirm()
{
	uiOpen = true;
	_isAccept = false;

	if (_acceptCount == 0)
	{
		// 예 선택 이미지
		IMAGEMANAGER->findImage("예")->render(_backBuffer->getMemDC(), WINSIZEX - 192, 210);			// y값이 212정도면 딱 맞을거같음
		
		// 방향키로 아래 이동
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_acceptCount++;
		}
		// 스페이스바로 선택
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			// 만약 스타팅 포켓몬을 고르는 중이라면
			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				// 선택하는 순간 다음 스크립트 진행
				_txtIndex = 0;
				_scriptIndex++;
			}
			
			_isAccept = true;		// 예 선택
			_isConfirm = false;		// 확인창 종료
			uiOpen = false;			// UI종료
			_acceptCount = 0;		// 다음번에 다시 예로 커서가 가 있게끔 초기화
		}
	}
	else if (_acceptCount == 1)
	{
		// 아니오 선택 이미지
		IMAGEMANAGER->findImage("아니오")->render(_backBuffer->getMemDC(), WINSIZEX - 192, 210);
		
		// 방향키로 위 이동
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_acceptCount--;
		}
		// 스페이스바로 선택
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
 			if (_npc == NPC::CYNDAQUIL || _npc == NPC::TOTODILE || _npc == NPC::CHIKORITA)
			{
				_npc = NPC::SELECTCANCEL;	// 선택취소로 스크립트 값 변경
				_isCount = true;			// 스크립트 변경할 수 있게끔 설정

				// 텍스트 초기화
				_txtIndex = 0;
				_scriptIndex = 0;
			}
			_isAccept = false;		// 아니오 선택
			_isConfirm = false;		// 확인창 종료
			uiOpen = false;			// UI종료
			_acceptCount = 0;		// 다음번에 다시 예로 커서가 가 있게끔 초기화
		}
	}
}

bool uiManager::isUiOpen()
{
	return uiOpen;
}
