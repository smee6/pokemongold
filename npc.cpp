#include "pch.h"
#include "npc.h"
#include "tileMap.h"
#include "character.h"

npc::npc()
{
}

npc::~npc()
{
}

HRESULT npc::init()
{
	setNPC();

	_isMove = false;

	return S_OK;
}

void npc::relise()
{
}

void npc::update()
{
	updateNPC();

	//npc 무브렉트에 플레이어가 오면  npc움직임
	for (int i = 0; i < 8; i++)
	{
		RECT temp;
		if(IntersectRect(&temp, &_npc[i].moveRC, &_character->getRect()))
		{
			_isMove = true;
		}
	}

	if (_isMove == true)
	{
		move();
	}
}

void npc::render()
{
	for (int i = 0; i < 8; i++)
	{
		_npc[i].Img->render(getMemDC(), _npc[i].rc.left, _npc[i].rc.top);				//npc 이미지
		if (_npc[i].markCount != 0 && _npc[i].markCount != 100)
		{
			_npc[i].markImg->render(getMemDC(), _npc[i].rc.left - 16, _npc[i].rc.top - 16);
		}

		if(KEYMANAGER->isToggleKey(VK_TAB)) Rectangle(getMemDC(), _npc[i].detectRC);	//대화 상자 렉트
	}


	//Rectangle(getMemDC(), _npc[0].moveRC);		//무브 렉트

	for (int i = 0; i < 3; i++)
	{
		_pokeball[i].Img->render(getMemDC(), _pokeball[i].rc.left, _pokeball[i].rc.top);
		//Rectangle(getMemDC(), _pokeball[i].detectRC);
	}

	//Rectangle(getMemDC(), _npc[0].moveRC);


	char str[128];
	sprintf_s(str, "_isMove : %d", _isMove);
	TextOut(getMemDC(), 200, 100, str, strlen(str));
}

void npc::setNPC()
{
	//npc 공통적인 것 초기화
	for (int i = 0; i < 8; i++)
	{
		_npc[i].markImg = IMAGEMANAGER->addImage("느낌표", "image/pokemon_mark.bmp", 32, 32, true, RGB(255, 0, 255));
		_npc[i].markCount = 0;
	}

	//npc 이미지 초기화
	_npc[0].Img = IMAGEMANAGER->addImage("맘", "image/pokemon_mom.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[1].Img = IMAGEMANAGER->addImage("오박사", "image/pokemon_O.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[2].Img = IMAGEMANAGER->addImage("조수", "image/pokemon_Ominion.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[3].Img = IMAGEMANAGER->addImage("간호사", "image/pokemon_nurse.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[4].Img = IMAGEMANAGER->addImage("부하1", "image/pokemon_minion1.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[5].Img = IMAGEMANAGER->addImage("부하2", "image/pokemon_minion2.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[6].Img = IMAGEMANAGER->addImage("비상", "image/pokemon_master.bmp", 64, 64, true, RGB(255, 0, 255));
	_npc[7].Img = IMAGEMANAGER->addImage("마트", "image/pokemon_mart.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("엄마 업", "image/pokemon_mom_up.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("엄마 다운", "image/pokemon_mom_down.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("엄마 레프트", "image/pokemon_mom_left.bmp", 64, 64, true, RGB(255, 0, 255));
	//포켓볼 이미지 초기화
	{
		for (int i = 0; i < 3; i++)
		{
			_pokeball[i].Img = IMAGEMANAGER->addImage("볼", "image/pokemon_ball.bmp", 48, 48, true, RGB(255, 0, 255));
		}
	}
}

void npc::updateNPC()
{
	//npc 렉트
	_npc[0].rc = RectMake(_tileMap->getTile()[4630].rc.left + _npc[0].npcX, _tileMap->getTile()[4630].rc.top + _npc[0].npcY, 64, 64);
	_npc[1].rc = RectMake(_tileMap->getTile()[4442].rc.left + _npc[1].npcX, _tileMap->getTile()[4442].rc.top + _npc[1].npcY, 64, 64);
	_npc[2].rc = RectMake(_tileMap->getTile()[6151].rc.left + _npc[2].npcX, _tileMap->getTile()[6151].rc.top + _npc[2].npcY, 64, 64);
	_npc[3].rc = RectMake(_tileMap->getTile()[4241].rc.left + _npc[3].npcX, _tileMap->getTile()[4241].rc.top + _npc[3].npcY, 64, 64);
	_npc[4].rc = RectMake(_tileMap->getTile()[6181].rc.left + _npc[4].npcX, _tileMap->getTile()[6181].rc.top + _npc[4].npcY, 64, 64);
	_npc[5].rc = RectMake(_tileMap->getTile()[5330].rc.left + _npc[5].npcX, _tileMap->getTile()[5330].rc.top + _npc[5].npcY, 64, 64);
	_npc[6].rc = RectMake(_tileMap->getTile()[4472].rc.left + _npc[6].npcX, _tileMap->getTile()[4472].rc.top + _npc[6].npcY, 64, 64);
	_npc[7].rc = RectMake(_tileMap->getTile()[4697].rc.left + _npc[7].npcX, _tileMap->getTile()[4697].rc.top + _npc[7].npcY, 64, 64);

	//npc 감지렉트
	_npc[0].detectRC = RectMake(_npc[0].rc.left + 64, _npc[0].rc.top, 64, 64);
	_npc[1].detectRC = RectMake(_npc[1].rc.left, _npc[1].rc.top + 64, 64, 64);
	_npc[2].detectRC = RectMake(_npc[2].rc.left + 64, _npc[2].rc.top, 64, 64);
	_npc[3].detectRC = RectMake(_npc[3].rc.left , _npc[3].rc.top + 128, 64, 64);
	_npc[4].detectRC = RectMake(_npc[4].rc.left + 64, _npc[4].rc.top, 64, 64);
	_npc[5].detectRC = RectMake(_npc[5].rc.left - 64, _npc[5].rc.top, 64, 64);
	_npc[6].detectRC = RectMake(_npc[6].rc.left, _npc[6].rc.top +64, 64, 64);
	_npc[7].detectRC = RectMake(_npc[7].rc.left + 128, _npc[7].rc.top, 64, 64);

	//npc 무브렉트
	if (_npc[0].moveCount != 100)
	{
		_npc[0].moveRC = RectMake(_tileMap->getTile()[4204].rc.left, _tileMap->getTile()[4204].rc.top, 64, 64);
	}
	if (_npc[4].moveCount != 100)
	{
		_npc[4].moveRC = RectMake(_tileMap->getTile()[6184].rc.left, _tileMap->getTile()[6184].rc.top, 64, 64);
	}
	if (_npc[5].moveCount != 100)
	{
		_npc[5].moveRC = RectMake(_tileMap->getTile()[5327].rc.left, _tileMap->getTile()[5327].rc.top, 64, 64);
	}

	for (int i = 0; i < 3; i++)
	{
		_pokeball[i].rc = RectMake(_tileMap->getTile()[4657 + i].rc.left + 8, _tileMap->getTile()[4657 + i].rc.top - 8, 64, 64);
		_pokeball[i].detectRC = RectMake(_tileMap->getTile()[4871 + i].rc.left, _tileMap->getTile()[4871 + i].rc.top, 64, 64);
	}
}

void npc::move()
{
	RECT temp;
	if (IntersectRect(&temp, &_npc[0].moveRC, &_character->getRect()))
	{
		if (_npc[0].markCount != 100)
		{
			_npc[0].markCount++;
		}
		else if (_npc[0].markCount == 100)
		{
			if (_npc[0].moveCount < 125 && UIMANAGER->getIsScript() == false)
			{
				_npc[0].moveCount++;
			}
			if (_npc[0].moveCount <= 16)
			{
				_npc[0].npcX += 8;
			}
			if (_npc[0].moveCount > 16 && _npc[0].moveCount <= 24)
			{
				_npc[0].Img = IMAGEMANAGER->findImage("엄마 업");
				_npc[0].npcY -= 8;
			}
			if (_npc[0].moveCount == 25)
			{
				UIMANAGER->setIsScript(true);
				UIMANAGER->setNPC(NPC::MOM, true);
				_npc[0].moveCount = 100;
			}
			if (_npc[0].moveCount >= 101 && _npc[0].moveCount < 109)
			{
				_npc[0].Img = IMAGEMANAGER->findImage("엄마 다운");
				_npc[0].npcY += 8;
			}
			if (_npc[0].moveCount >= 109 && _npc[0].moveCount < 125)
			{
				_npc[0].Img = IMAGEMANAGER->findImage("엄마 레프트");
				_npc[0].npcX -= 8;
				_npc[0].moveRC = RectMake(_tileMap->getTile()[4204].rc.left, _tileMap->getTile()[4204].rc.top, 0, 0);
			}
			if (_npc[0].moveCount == 125)
			{
				_npc[0].Img = IMAGEMANAGER->findImage("맘");
				_isMove = false;
			}

		}
	}

	if (IntersectRect(&temp, &_npc[4].moveRC, &_character->getRect()))
	{
		if (_npc[4].markCount != 100)
		{
			_npc[4].markCount++;
		}
		else if (_npc[4].markCount == 100)
		{
			if (_npc[4].moveCount < 25 && _npc[4].moveCount != 100)
			{
				_npc[4].moveCount++;
			}
			if (_npc[4].moveCount <= 16)
			{
				_npc[4].npcX += 8;
			}
			if (_npc[4].moveCount == 17)
			{
				UIMANAGER->setIsScript(true);
				UIMANAGER->setNPC(NPC::TRAINER1, true);
				_npc[4].moveRC = RectMake(_tileMap->getTile()[6184].rc.left, _tileMap->getTile()[6184].rc.top, 0, 0);
				_isMove = false;
				_npc[4].moveCount = 100;
			}
		}
	}

	if (IntersectRect(&temp, &_npc[5].moveRC, &_character->getRect()))
	{
		if (_npc[5].markCount != 100)
		{
			_npc[5].markCount++;
		}
		else if (_npc[5].markCount == 100)
		{
			if (_npc[5].moveCount < 25 && _npc[5].moveCount != 100)
			{
				_npc[5].moveCount++;
			}
			if (_npc[5].moveCount <= 16)
			{
				_npc[5].npcX -= 8;
			}
			if (_npc[5].moveCount == 17)
			{
				UIMANAGER->setIsScript(true);
				UIMANAGER->setNPC(NPC::TRAINER2, true);
				_npc[5].moveRC = RectMake(_tileMap->getTile()[5327].rc.left, _tileMap->getTile()[5327].rc.top, 0, 0);
				_isMove = false;
				_npc[5].moveCount = 100;
			}
		}
	}
}
