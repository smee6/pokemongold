#pragma once
#include "gameNode.h"
#include "tank.h"
#include "tankMap.h"

class tankScene : public gameNode
{
private:
	tank* _tank;
	tankMap* _tankMap;

public:
	tankScene();
	~tankScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

