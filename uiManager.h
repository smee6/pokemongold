#pragma once
#include "singletonBase.h"


class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//상점 메뉴 선택지
	int buyCnt = 0;								//아이템 메뉴 선택지
	bool shopWindow = false;					//상점 메뉴창 띄울지 안띄울지
	bool buyWindow = false;						//아이템 메뉴창 띄울지 안띄울지

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();
	void bag();

};

