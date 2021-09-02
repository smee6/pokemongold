#pragma once
#include "singletonBase.h"


class uiManager : public singletonBase<uiManager>
{
private:

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

