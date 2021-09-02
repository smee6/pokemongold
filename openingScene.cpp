#include "pch.h"
#include "openingScene.h"

openingScene::openingScene()
{
}

openingScene::~openingScene()
{
}

HRESULT openingScene::init()
{
	opening = IMAGEMANAGER->addFrameImage("¿ÀÇÁ´×", "image/op_image_frame.bmp", 65280, 576, 102, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void openingScene::release()
{
}

void openingScene::update()
{
	static int count = 0;

	if (count % 2 == 0 && _index <= 100) _index++;

	if (_index == 100)
	{
		_index++;
		_waitTime = TIMEMANAGER->getWorldTime();
	}

	if (_index >= 101 && TIMEMANAGER->getWorldTime() >= _waitTime + 3)
		SCENEMANAGER->changeScene("¿£µù");

	count++;
}

void openingScene::render()
{
	opening->frameRender(getMemDC(), 0, 0, _index, 0);
}
