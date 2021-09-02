#pragma once
#include "poketmon.h"
class weedle : public poketmon
{
private:


public:
	weedle();
	~weedle();
	
	HRESULT init();
	void release();
	void update();
	void render();
};

