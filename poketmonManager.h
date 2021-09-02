#pragma once
#include "gameNode.h"
#include <vector>

#pragma region poketmon

#include "chikorita.h"	//치코리타
#include "cyndaquil.h"	//브케인
#include "totodile.h"	//리아코
#include "pikachu.h"	//피카츄

#pragma endregion


// 전방 선언
class character;

class poketmonManager : public gameNode
{
private:
	typedef vector<poketmon*>				vPoketmon;
	typedef vector<poketmon*>::iterator		viPoketmon;

private:
	vPoketmon _vPoketmon;
	viPoketmon _viPoketmon;

	character* _character;


public:

	poketmonManager();
	~poketmonManager();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void poketmonImage();										// 포켓몬 이미지 추가
	void poketmonSpawn();										// 포켓몬 생성

	void setCharacterMemoryAddressLink(character* character) { _character = character; }		// 메모리 주소 링크
};
