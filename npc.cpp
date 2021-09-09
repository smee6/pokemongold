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
		_npc[i].Img->render(getMemDC(), _npc[i].rc.left + _npc[i].npcX , _npc[i].rc.top + _npc[i].npcY);				//npc 이미지
		if (_npc[i].markCount != 0 && _npc[i].markCount != 100)
		{
			_npc[i].markImg->render(getMemDC(), _npc[i].rc.left - 16, _npc[i].rc.top - 16);
		}


		if(KEYMANAGER->isToggleKey(VK_TAB)) Rectangle(getMemDC(), _npc[i].detectRC);	//대화 상자 렉트
	}

	Rectangle(getMemDC(), _npc[0].moveRC);

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
}

void npc::updateNPC()
{
	//npc 렉트
	_npc[0].rc = RectMake(_tileMap->getTile()[4630].rc.left, _tileMap->getTile()[4630].rc.top, 64, 64);
	_npc[1].rc = RectMake(_tileMap->getTile()[4442].rc.left, _tileMap->getTile()[4442].rc.top, 64, 64);
	_npc[2].rc = RectMake(_tileMap->getTile()[6151].rc.left, _tileMap->getTile()[6151].rc.top, 64, 64);
	_npc[3].rc = RectMake(_tileMap->getTile()[4241].rc.left, _tileMap->getTile()[4241].rc.top, 64, 64);
	_npc[4].rc = RectMake(_tileMap->getTile()[6181].rc.left, _tileMap->getTile()[6181].rc.top, 64, 64);
	_npc[5].rc = RectMake(_tileMap->getTile()[5330].rc.left, _tileMap->getTile()[5330].rc.top, 64, 64);
	_npc[6].rc = RectMake(_tileMap->getTile()[4472].rc.left, _tileMap->getTile()[4472].rc.top, 64, 64);
	_npc[7].rc = RectMake(_tileMap->getTile()[4697].rc.left, _tileMap->getTile()[4697].rc.top, 64, 64);

	//npc 감지렉트
	_npc[0].detectRC = RectMake(_tileMap->getTile()[4631].rc.left, _tileMap->getTile()[4631].rc.top, 64, 64);
	_npc[1].detectRC = RectMake(_tileMap->getTile()[4656].rc.left, _tileMap->getTile()[4656].rc.top, 64, 64);
	_npc[2].detectRC = RectMake(_tileMap->getTile()[6152].rc.left, _tileMap->getTile()[6152].rc.top, 64, 64);
	_npc[3].detectRC = RectMake(_tileMap->getTile()[4669].rc.left, _tileMap->getTile()[4669].rc.top, 64, 64);
	_npc[4].detectRC = RectMake(_tileMap->getTile()[6182].rc.left, _tileMap->getTile()[6182].rc.top, 64, 64);
	_npc[5].detectRC = RectMake(_tileMap->getTile()[5329].rc.left, _tileMap->getTile()[5329].rc.top, 64, 64);
	_npc[6].detectRC = RectMake(_tileMap->getTile()[4686].rc.left, _tileMap->getTile()[4686].rc.top, 64, 64);
	_npc[7].detectRC = RectMake(_tileMap->getTile()[4699].rc.left, _tileMap->getTile()[4699].rc.top, 64, 64);

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
			if (_npc[0].moveCount < 25 && _npc[0].moveCount != 100)
			{
				_npc[0].moveCount++;
			}
			if (_npc[0].moveCount <= 16)
			{
				_npc[0].npcX += 8;
			}
			if (_npc[0].moveCount > 16 && _npc[0].moveCount <= 24)
			{
				_npc[0].npcY -= 8;
			}
			if (_npc[0].moveCount == 25)
			{
				UIMANAGER->setIsScript(true);
				UIMANAGER->setNPC(NPC::MOM, true);
				_npc[0].moveRC = RectMake(_tileMap->getTile()[4204].rc.left, _tileMap->getTile()[4204].rc.top, 0, 0);
				_isMove = false;
				_npc[0].moveCount = 100;
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
