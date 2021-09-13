#pragma
#include "gameNode.h"

#define npcMAX 11				//npc max

//npc 구조체
struct tagNPC
{
	image* Img;					// npc 이미지
	image* markImg;				//느낌표 이미지
	RECT rc;					//npc 렉트
	RECT detectRC;				//감지렉트(말걸 때)
	RECT moveRC;				//움직임 렉트(이 렉트 안에 오면 npc가 다가감

	int npcX, npcY;				//npc 움직이게 하는 변수
	int moveCount;				//움직이는 시간카운트
	int markCount;				//느낌표 지속카운트
};

//전방 선언
class tileMap;
class character;

class npc : public gameNode
{
private:
	//클래스
	tileMap* _tileMap;
	character* _character;

	tagNPC _npc[11];				//npc - 0: 플레이어 엄마 1: 오박사 2: 오박사 조수 3: 간호사 4: 부하1 5: 부하2 6: 비상 7: 마트 주인 8~10 : 포켓볼

	RECT _moveRC;					//부하1 움직임렉트 2개 필요해서 만듬

	int count;					//프레임 돌리는 카운트

	bool _isMove;				//움직일 때는  속성바꾸는 것을 꺼주기 위해 만듬

public:
	npc();
	~npc();

	virtual HRESULT init();
	virtual void relise();
	virtual void update();
	virtual void render();

	void setNPC();									//NPC 초기화 함수
	void updateNPC();								//NPC 업데이트 함수
	void move();									//움직임 함수(플레이어 엄마, 부하1, 부하2)

	//접근자
	tagNPC* getnpcRC() { return _npc; }				//npc에 대한 접근자
	inline bool getIsMove() { return _isMove; }		//isMove에 대한 접근자

	//설정자
	void setNPCX4(int npcX) { _npc[4].npcX = npcX; }
	void setNPCX5(int npcX) { _npc[5].npcX = npcX; }

	//주소 링크
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};


