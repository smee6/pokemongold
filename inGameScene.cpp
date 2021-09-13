#include "pch.h"
#include "inGameScene.h"


inGameScene::inGameScene()
{
}


inGameScene::~inGameScene()
{
}

HRESULT inGameScene::init()
{
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
	UIMANAGER->setTileMapMemoryAddressLink(_tileMap);
	_npc->setTileMapMemoryAddressLink(_tileMap);
	_npc->setCharacterMemoryAddressLink(_character);

	_tileMap->init();
	_npc->init();
	_character->init();
	_pM->init();

	SOUNDMANAGER->play("town1BGM", 0.01f * UIMANAGER->getVolume());

	UIMANAGER->setIsScript(true);
	UIMANAGER->setIsCount(true);

	return S_OK;
}

void inGameScene::release()
{
}

void inGameScene::update()
{
	_character->update();
	_pM->update();
	_tileMap->update();
	_npc->update();
}

void inGameScene::render()
{
	_tileMap->render();
	_npc->render();
	_character->render();
	_pM->render();

	//IMAGEMANAGER->findImage("½ÃÀÛ")->render(getMemDC());
}
