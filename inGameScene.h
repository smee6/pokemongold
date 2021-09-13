#pragma once
#include "gameNode.h"
#include "tileMap.h"
#include "character.h"
#include "poketmonManager.h"
#include "npc.h"

class inGameScene : public gameNode
{
private:
	tileMap* _tileMap;							// 타일맵 클래스
	character* _character;						// 캐릭터 클래스
	poketmonManager* _pM;						// 포켓몬 매니저 클래스
	npc* _npc;									// npc 클래스

public:
	inGameScene();
	~inGameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};


