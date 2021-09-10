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
	_npc = new npc;
	
	_tileMap->setCharacterMemoryAddressLink(_character);
	_tileMap->setNPCMemoryAddressLink(_npc);
	_character->setPoketmonManagerMemoryAddressLink(_pM);
	_character->setTileMapMemoryAddressLink(_tileMap);
	_character->setNPCMemoryAddressLink(_npc);
	_pM->setCharacterMemoryAddressLink(_character);
	UIMANAGER->setCharacterMemoryAddressLink(_character);
	UIMANAGER->setSkillMemoryAddressLink(_pM);
	_npc->setTileMapMemoryAddressLink(_tileMap);
	_npc->setCharacterMemoryAddressLink(_character);

	_tileMap->init();
	_npc->init();
	_character->init();
	_pM->init();

	UIMANAGER->init();

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

	_character->update();
	_pM->update();
	_tileMap->update();
	_npc->update();
	
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
	_npc->render();
	_character->render();
	_pM->render();

	//UIMANAGER->pokeShift();
	//UIMANAGER->script();
	//SCENEMANAGER->render();
	//UIMANAGER->battle();

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}

