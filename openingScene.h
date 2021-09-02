#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
private:

	int _index;					//프레임 이미지 사용 용도 변수

	image* opening;

	int _waitTime;				// 마지막 대기 시간

public:
	openingScene();
	~openingScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

