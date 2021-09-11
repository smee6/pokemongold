#pragma once
#include "gameNode.h"
#include <vector>
#include "skill.h"

#include "poketmon.h"	//야생포켓몬에 데이터 넣으려고 헤더 넣음.


#pragma region poketmon

#include "chikorita.h"	//치코리타
#include "cyndaquil.h"	//브케인
#include "totodile.h"	//리아코
#include "pikachu.h"	//피카츄
#include "pidgey.h"		//구구
#include "rattata.h"	//꼬렛
#include "caterpie.h"	//캐터피
#include "spearow.h"	//깨바참
#include "weedle.h"		//뿔충이

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
	skill* _skill;
	poketmon* _poketmon;

	tagPOKETMON_PLAYER _wildPoketmon;					//야생포켓몬

	tagPOKETMON_PLAYER _startPoketmon[3];				//처음시작 포켓몬


	tagPOKETMON_PLAYER _championPoketmon[3];			//챔피언 포켓몬[3]
	tagPOKETMON_PLAYER _trainer1Poketmon[2];			//트레이너1포켓몬[2]
	tagPOKETMON_PLAYER _trainer2Poketmon[2];			//트레이너1포켓몬[2]




	int _randomPoketmon;						//포켓몬 랜덤으로 돌리기위해 만든 변수

public:

	poketmonManager();
	~poketmonManager();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void poketmonImage();										// 포켓몬 이미지 추가
	void poketmonSpawn();										// 포켓몬 생성

	void wildPoketmonSetting();									//야생 포켓몬 셋팅

	//각 상황의 포켓몬 넣어놓은거

	void startPoketmonSetting();

	void championPoketmonSetting();
	void trainer1Poketmon();
	void trainer2Poketmon();

	void setCharacterMemoryAddressLink(character* character) { _character = character; }		// 메모리 주소 링크


	tagPOKETMON_PLAYER getWildPoketmon() { return _wildPoketmon; }			//야생 포켓몬 겟터
	tagPOKETMON_PLAYER* getStartPoketmon() { return _startPoketmon; }		//스타트 포켓몬 

	tagPOKETMON_PLAYER* getChampionPoketmon() { return _championPoketmon; }	//챔피언 포켓몬
	tagPOKETMON_PLAYER* getTrainer1Poketmon() { return _trainer1Poketmon; }	//트레이너1 포켓몬
	tagPOKETMON_PLAYER* getTrainer2Poketmon() { return _trainer2Poketmon; }	//트레이너2 포켓몬
	

	skill* getSkill() { return _skill; }

	void setCurrentHP(int hp) { _wildPoketmon.currentHP -= hp; }

};
