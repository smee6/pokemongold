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
	opening = IMAGEMANAGER->addFrameImage("오프닝", "image/op_image_frame.bmp", 65280, 576, 102, 1, true, RGB(255, 0, 255));
	SOUNDMANAGER->play("op_star", 0.01f * UIMANAGER->getVolume());
	return S_OK;
}

void openingScene::release()
{
}

void openingScene::update()
{
	//if (_count == 0 && !SOUNDMANAGER->isPlaySound("op_star"))
	//{
	//	SOUNDMANAGER->play("start", 0.01f * UIMANAGER->getVolume());
	//	_count++;
	//}
	//if (_count == 1 && !SOUNDMANAGER->isPlaySound("start"))
	//{
	//	SOUNDMANAGER->play("title", 0.01f * UIMANAGER->getVolume());
	//	_count++;
	//}

	static int count = 0;

	if (count % 2 == 0 && _index <= 100) _index++;

	if (_index == 100)
	{
		_index++;
		_waitTime = TIMEMANAGER->getWorldTime();
	}

	if (_index >= 101 && TIMEMANAGER->getWorldTime() >= _waitTime + 3)
		SCENEMANAGER->changeScene("인게임");

	count++;
}

void openingScene::render()
{
	opening->frameRender(getMemDC(), 0, 0, _index, 0);
}
