#pragma once
#include "gameNode.h"

#define POKETMONMEET 7						// 포켓몬 조우 확률
#define JUMPPOWER 10						// 점프 파워
#define GRAVITY	1							// 중력 파워

// 캐릭터 상태
enum class STATE
{
	IDLE_RL,								// 아이들 좌우
	IDLE_UD,								// 아이들 상하
	RUN_RL,									// 걷기 좌우
	RUN_UD,									// 걷기 상하
};

//포켓몬 타입
enum class TYPE_PLAYER
{
	NONE,	//없음
	NOMAL,	//노말
	FIRE,	//불
	WATER,	//물
	GRASS,	//풀
	ELECTR,	//전기
	ICE,	//얼음
	FIGHT,	//격투
	POISON,	//독
	GROUND,	//땅
	FLYING,	//비행
	PSYCHC,	//초능력
	BUG,	//벌레
	ROCK,	//바위
	GHOST,	//유령
	DRAGON,	//드래곤
	DARK,	//악
	STEEL,	//강철
	FAIRY	//요정
};

// 캐릭터 포켓몬
//struct tagPOKETMON_PLAYER
//{
//	string name;							// 이름
//	string gender;							// 성별
//	bool isGender;							// 성별 체크
//	int index;								// 인덱스 번호
//	int level;								// 포켓몬 현재 레벨
//	int	evolutionLevel;						// 진화 단계
//
//	int type1; 								// 포켓몬 타입1	
//	int type2;								// 포켓몬 타입2
//
//	int iconNumX;							// 포켓몬 창에서 프레임 넘버 X값
//	int iconNumY;							// 포켓몬 창에서 프레임 넘버 Y값
//
//	int	attack;								// 1레벨 초기 공격
//	int	defense;							// 1레벨 초기 방어	
//	int specialAttack;						// 1레벨 초기 특수공격
//	int	specialDefense;						// 1레벨 초기 특수방어
//	int	speed;								// 1레벨 초기 스피드
//	int	currentHP;							// 1레벨 초기 현재 체력
//	int	maxHP;								// 1레벨 초기 최대 체력
//
//	float levelAttack;						// 레벨당 증가하는 공격
//	float levelDefense;						// 레벨당 증가하는 방어	
//	float levelSpecialAttack;				// 레벨당 증가하는 특수공격
//	float levelSpecialDefense;				// 레벨당 증가하는 특수방어
//	float levelSpeed;						// 레벨당 증가하는 스피드
//	float levelHP;							// 레벨당 증가하는 체력
//
//	int sumAttack;							// 최종 공격
//	int sumDefense;							// 최종 방어
//	int sumSpecialAttack;					// 최종 특수공격
//	int sumSpecialDefense;					// 최종 특수방어
//	int sumSpeed;							// 최종 스피드
//	int sumMaxHP;							// 최종 체력
//
//	float currentExp;						// 현재 경험치(현재 얻은 총 경험치, level값 만큼 빼서 나머지 양 보여주기)
//	float	maxExp;							// 최대 경험치(현재 레벨의 최대 경험치 값 표시)
//
//	float totalEXP;							// 토탈 경험치
//
//	int	skill[4];							// 스킬1 인덱스 
//	int skillPP[4];							// 스킬1 현재 PP
//
//	int item;								// 보유 중인 아이템 인덱스
//};

// 전방 선언
class poketmonManager;
class tileMap;
class npc;

class character : public gameNode
{
private:
	poketmonManager* _pM;									// 포켓몬 매니저 클래스 		
	tileMap* _tileMap;										// 타일맵 클래스
	npc* _npc;												// npc 클래스
	tagPOKETMON_PLAYER _poketmon[6];						// 유저가 보유한 포켓몬

	image* _image;											// 캐릭터 이미지
	image* _shadowImage;									// 비탈길 이동 시 그림자 이미지
	image* _grassImage;										// 풀숲 이미지
	image* _flashLoadingImage;								// 플래시 로딩 이미지
	image* _battleLoadingImage;								// 배틀 로딩 이미지
	RECT _rc;												// 캐릭터 렉트

	float _x, _y;											// 캐릭터 중점 좌표
	float _jumpPower;										// 점프 파워
	float _gravity;											// 중력 파워

	int _state;												// 유저 상태
	int _frameCount;										// 프레임 이미지 인터벌 카운트
	int _currentFrame;										// 현재 프레임
	int _direction;											// 캐릭터 방향 0: 우, 1: 좌, 2: 하, 3: 상
	int _currentTile;										// 현재 플레이어가 위치한 타일 인덱스
	int _frontTileType;										// 바라본 방향의 타일 타입
	int _slopeDistance;										// 비탈길 이동 거리
	int _grassCount;										// 풀 이미지 변경용 카운트값
	int _alpha;												// 플래시 로딩 이미지의 알파값
	int _loadingCount;										// 포켓몬 조우 시 배틀 로딩까지의 인터벌 카운트
	int _scriptAction;										// 대화 스크립트 중 기능 액션 필요할 때 사용하는 변수

	bool _isMoving;											// 현재 캐릭터가 이동 중인지?
	bool _isSloping;										// 현재 캐릭터가 비탈길 이동 중인지?				
	bool _isPoketmonMeet;									// 풀 타일에서 포켓몬 조우 중인지?


public:
	character();
	~character();

	virtual HRESULT init();															//초기화 함수
	virtual void release();															//메모리 해제 함슈
	virtual void update();															//연산하는 함수
	virtual void render();															//그리기 함수

	void imageInit();																// 이미지 파일들 불러옴
	void imageSetting();															// 상태에 따라 현재 이미지 세팅
	void imageFrame();																// 이미지 프레임 처리
	void controll();																// 캐릭터 컨트롤 처리
	void idle(int direction);														// 아이들 처리
	void run(int direction);														// 걷기 처리
	void tileCheck(int direction);													// 타일 체크 처리
	void tileAction();																// 좌표 이동 처리
	void grass();																	// 풀 타일 처리
	void door(int doorIndex);														// 문 타일 처리
	void slope(int direction);														// 비탈길 타일 처리
	void ui();																		// ui창 처리
	void poketmonMeet();															// 포켓몬 조우 시 처리
	void npcScript();																// npc 대화 스크립트 처리
	void poketmonSetting();			// 테스트용 데이터

	float getCharacterX() { return _x; }											// 캐릭터 X좌표 게터
	float getCharacterY() { return _y; }											// 캐릭터 Y좌표 게터
	int getDirection() { return _direction; }										// 캐릭터 방향 게터
	int getCurrentTile() { return _currentTile; }									// 캐릭터가 위치한 타일 인덱스 게터
	bool getIsMoving() { return _isMoving; }										// 이동 중인지 불값 게터
	bool getIsSloping() { return _isSloping; }										// 비탈길 이동 중인지 불값 게터
	bool getIsPoketmonMeet() { return _isPoketmonMeet; }							// 포켓몬 조우 중인지 불값 게터
	RECT getRect() { return _rc; }													// 렉트 게터
	tagPOKETMON_PLAYER getPoketmon(int arrNum) { return _poketmon[arrNum]; }		// 보유 포켓몬 게터
	void setPoketmon(tagPOKETMON_PLAYER poke,int arrNum) { _poketmon[arrNum] = poke; } //보유 포켓몬 세터

	void setCurrentHP(int arrNum, int damage) { _poketmon[arrNum].currentHP -= damage; }	// 체력 감소 세터
	void setSkillPP(int arrNum, int arrNum2) { _poketmon[arrNum].skillPP[arrNum2]--; }		// PP 감소 세터
	void setTotalExp(int arrNum, int exp) { _poketmon[arrNum].totalEXP += exp; }			// 현재 경험치 증가 세터
	void setScriptAction(int scriptAction) {_scriptAction = scriptAction; }					// _scriptAction 세터

	void setPoketmonManagerMemoryAddressLink(poketmonManager* pM) { _pM = pM; }				// 메모리 주소 링크
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }				// 메모리 주소 링크
	void setNPCMemoryAddressLink(npc* npc) { _npc = npc; }									// 메모리 주소 링크
};
