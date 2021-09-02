#pragma once
#include "poketmon.h"
class caterpie : public poketmon
{

private:


public:

	caterpie();
	~caterpie();

	HRESULT init();
	void release();
	void update();
	void render();
};

