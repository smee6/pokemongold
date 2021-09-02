#pragma once
#include "poketmon.h"
class pidgey :  public poketmon
{
private:

public :

	pidgey();
	~pidgey();

	HRESULT init();
	void release();
	void update();
	void render();
};

