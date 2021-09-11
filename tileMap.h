#pragma once
#include "gameNode.h"

//타일 사이즈 64 * 64
#define TILESIZE 64

//전체 타일 개수
#define TILE (214 * 36)

//타일 속성
enum TILETYPE
{
	TILETYPE_OPEN,				//지나갈 수 있는 타일
	TILETYPE_GRASS,				//풀(포켓몬 뿌릴 수 있게)
	TILETYPE_CLOSE,				//지나갈 수 없는 타일
	TILETYPE_DOOR,				//이동할 수 있는 문
	TILETYPE_LEFTSLOPE,			//왼쪽 비탈길
	TILETYPE_RIGHTSLOPE,		//오른쪽 비탈길
	TILETYPE_BOTTOMSLOPE		//아래쪽 비탈길
};

//맵 타일
struct tagTile
{
	image* Img;			//이미지
	RECT		rc;		//타일 렉트
	TILETYPE	type;	//타일 속성
	int x, y;			//타일 이미지 x인덱스, y인덱스
};

class character;
class npc;

class tileMap : public gameNode
{
private:
	character* _character;
	npc* _npc;

	image* _map;							//전체 맵 이미지
	
	//시작맵 건물 안 이미지
	image* _startHome1;						//집 1층 이미지
	image* _startHome2;						//집 2층 이미지
	image* _startCenter;					//시작맵 센터

	//체육관맵 건물 안 이미지
	image* _gymCenter;						//체육관맵 센터
	image* _gymGym;							//체유관맵 체육관
	image* _gymMart;						//체육관맵 마트

	tagTile _tile[TILE];					//시작맵 타일

	int _cameraX;							//맵 카메라 X좌표
	int _cameraY;							//맵 카메라 y좌표

public:
	tileMap();
	~tileMap();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	
	//함수
	void setTile();		//맵에 타일 깔아주는 함수
	void save();		//저장 함수
	void load();		//불러오는 함수

	//접근자
	tagTile* getTile() { return _tile; }			//맵 타일에 대한 접근자

	int getCameraX() { return _cameraX; }			//맵 카메라 X좌표에 대한 접근자
	int getCameraY() { return _cameraY; }			//맵 카메라 y좌표에 대한 접근자

	//설정자
	void setTile6183Type(TILETYPE _type) { _tile[6183].type = _type; }	//6183번 타일 속성 설정자
	void setTile5328Type(TILETYPE _type) { _tile[5328].type = _type; }	//5328번 타일 속성 설정자
	void setCameraX(int x) { _cameraX = x; }		//맵 카메라 x좌표에 대한 설정자
	void setCameraY(int y) { _cameraY = y; }		//맵 카메라 y좌표에 대한 설정자

	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setNPCMemoryAddressLink(npc* npc) { _npc = npc; }
};
