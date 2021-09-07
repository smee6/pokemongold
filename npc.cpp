#include "pch.h"
#include "npc.h"
#include "tileMap.h"

npc::npc()
{
}

npc::~npc()
{
}

HRESULT npc::init()
{
	setNPC();

	return S_OK;
}

void npc::relise()
{
}

void npc::update()
{
	updateNPC();

	for (int i = 0; i < 8; i++)
	{
		RECT temp;
		//if(IntersectRect(&temp, &_npc[i].detectRC), &_character->)
		{
			move();
		}
	}
}

void npc::render()
{
	for (int i = 0; i < 8; i++)
	{
		_npc[i].Img->render(getMemDC(), _npc[i].rc.left, _npc[i].rc.top);	//npc 이미지
		//Rectangle(getMemDC(), _npc[i].detectRC);
	}
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
}

void npc::move()
{

}
