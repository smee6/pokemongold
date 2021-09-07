#pragma
#include "gameNode.h"

//npc 구조체
struct tagNPC
{
	image* Img;					// npc 이미지
	image* markImg;				//느낌표 이미지
	RECT rc;					//npc 렉트
	RECT detectRC;				//감지렉트(말걸 때)
	RECT moveRC;				//움직임 렉트(이 렉트 안에 오면 npc가 다가감)

	int markCount;				//느낌표 지속카운트
};

//전방 선언
class tileMap;

class npc : public gameNode
{
private:
	//클래스
	tileMap* _tileMap;

	tagNPC _npc[8];				//npc - 0: 플레이어 엄마 1: 오박사 2: 오박사 조수 3: 간호사 4: 부하1 5: 부하2 6: 비상 7: 마트 주인

	int count;					//프레임 돌리는 카운트

public:
	npc();
	~npc();

	virtual HRESULT init();
	virtual void relise();
	virtual void update();
	virtual void render();

	void setNPC();							//NPC 초기화 함수
	void updateNPC();						//NPC 업데이트 함수
	void move();							//움직임 함수(플레이어 엄마, 부하1, 부하2)

	//접근자
	tagNPC* getnpcRC() { return _npc; }		//npc에 대한 접근자

	//주소 링크
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
};


