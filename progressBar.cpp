#include "pch.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(int x, int y, int width, int height, const char* front, const char* back, string frontKey, string backKey)
{
	_x = x;
	_y = y;

	_front = frontKey;
	_back = backKey;

	//this->width = width;
	//this->height = height;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage(_front, front, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage(_back, back, width, height, true, RGB(255, 0, 255));

	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(),
		_progressBarTop->getHeight());

	//_rcProgress = RectMake(_x, _y, -width, height);
}

void progressBar::render()
{
	IMAGEMANAGER->render(_back, getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render(_front, getMemDC(), 
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());
}

//게이지 조절하는 함수
void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//이해 안가신다면 외우셔도 좋습니다 *-_-*
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();

}
