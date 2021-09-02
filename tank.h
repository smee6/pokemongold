#pragma once
#include "gameNode.h"
#include "tankMap.h"

enum TANKDIRECTION
{
	TANKDIRECTION_LEFT,
	TANKDIRECTION_UP,
	TANKDIRECTION_RIGHT,
	TANKDIRECTION_DOWN
};

class tank : public gameNode
{
private:
	tankMap*		_tankMap;
	TANKDIRECTION	_direction;

	image*			_image;
	RECT			_rc;
	float			_x, _y;
	float			_speed;

public:
	tank();
	~tank();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//¿À´Ã ÇÙ½ÉÇÔ¼ö
	void tankMove();
	void setTankPostion();

	void setTankMapMemoryAddressLink(tankMap* tm) { _tankMap = tm; }
};

