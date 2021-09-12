#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;
	float _currentWidth;

	//float width;
	//float height;

	string _front;
	string _back;

	image* _progressBarTop;
	image* _progressBarBottom;

public:
	progressBar();
	~progressBar();

	HRESULT init(int x, int y, int width, int height, const char* front, const char* back, string frontKey, string backKey);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);
	void setGauge(float currentGauge, float maxGauge, bool start);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
};

