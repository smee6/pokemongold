#pragma once
#include "gameNode.h"
#include "tileMap.h"
#include "character.h"
#include "poketmonManager.h"
#include "endingScene.h"
#include "openingScene.h"
#include "npc.h"


class playGround : public gameNode
{
private:
	tileMap* _tileMap;							// 타일맵 클래스
	character* _character;						// 캐릭터 클래스
	poketmonManager* _pM;						// 포켓몬 매니저 클래스
	npc* _npc;									// npc 클래스

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	
	
};

