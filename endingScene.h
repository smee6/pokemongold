#pragma once
#include "gameNode.h"

class endingScene : public gameNode
{
private:



public:
	endingScene();
	~endingScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

