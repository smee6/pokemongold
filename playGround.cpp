#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	_tileMap = new tileMap;
	_character = new character;
	_pM = new poketmonManager;
	
	_tileMap->setCharacterMemoryAddressLink(_character);
	_character->setPoketmonManagerMemoryAddressLink(_pM);
	_character->setTileMapMemoryAddressLink(_tileMap);
	_pM->setCharacterMemoryAddressLink(_character);
	
	_tileMap->init();
	_character->init();
	_pM->init();


	//SCENEMANAGER->addScene("엔딩", new endingScene);
	//SCENEMANAGER->changeScene("엔딩");
	

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
void playGround::update()
{
	gameNode::update();

	_tileMap->update();
	_character->update();
	_pM->update();

	//if (KEYMANAGER->isOnceKeyDown('P'))
	//{
	//	UIMANAGER->setVScript(TXTDATA->txtLoad("script/쫄따구2_승리정산.txt"));
	//	UIMANAGER->setIsScript(true);
	//}

	//SCENEMANAGER->update();
	
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//==============위에는 제발 건드리지 마라 ============

	_tileMap->render();
	_character->render();
	_pM->render();

	//UIMANAGER->script();

	//SCENEMANAGER->render();

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

