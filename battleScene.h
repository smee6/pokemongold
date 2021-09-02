#pragma once
#include "gameNode.h"

class battleScene : public gameNode
{
private:






public:

	battleScene();
	~battleScene();



	HRESULT init();
	void release();
	void update();
	void render();

};

