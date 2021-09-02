#pragma once
#include "gameNode.h"

#define TILESIZE 64				//타일 사이즈 64 * 64

//타일 깔 때 구분하기 위한 전처리기
#define	STARTTILE 24 * 18		//시작맵 타일개수
#define BATTLETILE 60 * 18		//배틀맵 타일개수
#define GYMTILE 40 * 36			//체육관맵 타일개수

//전체 타일 개수
#define TILE 24 * 18 + 60 * 18 + 40 * 36

enum TILETYPE					//타일 속성
{
	TILETYPE_OPEN,				//지나갈 수 있는 타일
	TILETYPE_GRASS,				//풀(포켓몬 뿌릴 수 있게)
	TILETYPE_CLOSE,				//지나갈 수 없는 타일
	TILETYPE_DOOR,				//이동할 수 있는 문
	TILETYPE_LEFTSLOPE,			//왼쪽 비탈길
	TILETYPE_RIGHTSLOPE,		//오른쪽 비탈길
	TILETYPE_BOTTOMSLOPE		//아래쪽 비탈길
};
//테스트용 방향
//enum DIRECTION
//{
//	LEFT,
//	RIGHT,
//	BOTTOM,
//	TOP,
//};

struct tagTile
{
	RECT		rc;		//타일 렉트
	TILETYPE	type;	//타일 속성
};

class character;

class tileMap : public gameNode
{
private:
	character* _character;

	//DIRECTION _direction;
	image* _map;							//전체 맵 이미지
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
	//void moveX();		//움직임 함수
	//void moveY();

	//접근자
	tagTile* getTile() { return _tile; }			//맵 타일에 대한 접근자

	int getCameraX() { return _cameraX; }			//맵 카메라 X좌표에 대한 접근자
	int getCameraY() { return _cameraY; }			//맵 카메라 y좌표에 대한 접근자

	//설정자
	void setCameraX(int x) { _cameraX = x; }
	void setCameraY(int y) { _cameraY = y; }


	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};
