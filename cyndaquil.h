#pragma once
#include "poketmon.h"
class cyndaquil : public poketmon		//ºêÄÉÀÎ
{
private:

public:

	cyndaquil();
	~cyndaquil();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

