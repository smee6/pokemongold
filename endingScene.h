#pragma once
#include "gameNode.h"

class endingScene : public gameNode
{
private:

	image* _endingBackground[4];	// 엔딩 배경 이미지
	image* _endingPokemon[4];		// 엔딩 포켓몬 이미지

	int _index;						// imageframe용 int변수

	int _endCount;					// 현재 엔딩 이미지 결정하는 변수

	float _time;					// 시간사용을 위한 시간변수


public:
	endingScene();
	~endingScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

