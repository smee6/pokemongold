#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
private:



public:
	openingScene();
	~openingScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

