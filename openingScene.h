#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
private:

	int _freakIndex;					// 게임프릭스 프레임 이미지 사용 용도 변수
	int _titleIndex;

	image* _opening;
	image* _title;
	image* _dr;

	int _waitTime;				// 마지막 대기 시간

	int _count;

	bool _isTitle;

public:
	openingScene();
	~openingScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

