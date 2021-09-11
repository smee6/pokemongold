#pragma once
#include "singletonBase.h"
#include <string>
#include <vector>


class progressBar;
class poketmonManager;


enum class NPC
{
	// title
	TITLE,

	// mom
	MOM,

	// Dr.Gong
	GONG,
	SUPPORTER,

	// champion
	CHAMPION,

	// trainers
	TRAINER1,
	TRAINER2,

	// where connect to player
	POKECENTER,
	SHOP,

	// about pokemon
	EVOLUTION,
	TOTODILE,		// 리아코
	CHIKORITA,		// 치코리타
	CYNDAQUIL,		// 브케인

	// starting select cancel
	SELECTCANCEL,

	// battle(test)
	BATTLE,
	BATTLE_ATTACK,
	BATTLE_DOWN
};


class character;

class uiManager : public singletonBase<uiManager>
{
private:
	int gold = 5000;
	int soundVolume = 100;
	int shopCnt = 0;							//상점 메뉴 선택지
	int buyCnt = 0;								//아이템 메뉴 선택지
	int menuCnt = 0;
	int bagCnt = 0;
	int pokesCnt = 0;
	int dogamCnt = 0;
	int settingCnt = 0;
	int statusCnt = 0;
	int gearCnt = 0;
	bool shopWindow = false;					//상점 메뉴창 띄울지 안띄울지
	bool buyWindow = false;						//아이템 메뉴창 띄울지 안띄울지
	bool bagWindow = false;
	bool menuWindow = false;
	bool pokeshiftWindow = false;
	bool pokeWindow = false;
	bool settingWindow = false;
	bool pokedogamWindow = false;
	bool statusWindow = false;
	bool gearWindow = false;
	bool useMedicineWindow = false;
	bool useGoodMedicineWindow = false;
	bool howStrongWindow = false;
	int pokeballQ = 50;   // 포켓볼 보유 갯수 , 아래는 상처약, 고급상처약 갯수 (Q)
	int medicineQ = 22;
	int goodMedicineQ = 13;
	int delaycnt;
	int iconCnt;

	// isOpen
	bool _isOpenShop;	// 상점 열려있는지

	bool _isOpenPokeShift;
	bool _isOpenBag;
	bool _isOpenSetting;
	bool _isOpenPokeDogam;
	bool _isOpenPlayerStatus;
	bool _isOpenPokeGear;
	bool _isOpenHowStrong;
	// 가방등의 메뉴창에 안에 있는거 열려있는지

	bool _isOpenPokecenter;						// 포케센터 열려있는지
	bool _isOpenMenu;							// 메뉴 열려있는지

	// isBattle
	bool _isOpenSkill;							// 기술창 열려있는지
	bool _isOpenPokemon;						// 포켓몬 보유창 열려있는지
	bool _isBattle;								// 배틀 상태인지 아닌지
	bool _isAttack;								// 공격 상태인지 아닌지

	// script
	bool _isScript;								// 대화 여부 (대화 중인지)
	bool _isScriptSkip;							// 스킵 여부 (대화 한꺼번에 출력)
	image* _scriptImage;						// 스크립트 배경이미지
	int _scriptIndex;							// 스크립트 줄 카운트(문장?)
	int _txtIndex;								// 스크립트 글자 카운트
	vector<string> _vScript;					// 스크립트를 담을 벡터
	string _txt;								// 실제 텍스트 파일

	int _momCount;								// 엄마 대화 진행도 카운트
	int _drCount;								// 공박사 대화 진행도 카운트
	int _championCount;							// 관장 대화 진행도 카운트
	int _trainer1Count;							// 트레이너1 대화 진행도 카운트
	int _trainer2Count;							// 트레이너2 대화 진행도 카운트
	int _pokecenterCount;						// 간호순 눈나 대화 진행도 카운트

	bool _isCount;


	// pokeCenter
	int cnt = 0;

	int _index = 0;

	bool uiOpen = false;						// ui 켜져 있는지 여부

	//battle
	bool _isAnimation;							// 애니메이션이 끝났는지에 대한 체크변수

	image* _playerImage;						// 플레이어 이미지
	image* _playerPokeImage;					// 플레이어 포켓몬 이미지
	image* _enemyImage;							// 상대 트레이너 이미지
	image* _enemyPokeImage;						// 상대 포켓몬 이미지

	int _appearIndex = 2;						// 포켓몬 출근 시 볼 프레임 이미지 렌더용

	progressBar* _hpBarPlayer;					// 체력 게이지
	progressBar* _hpBarEnemy;
	progressBar* _expBar;						// 경험치 게이지

	int _px, _ex;								// 배틀 시 플레이어 및 에너미 이미지 시작 위치

	int _currentHP, _maxHP;						// 현재 hp, 최대 hp
	int _currentEXP, _maxEXP;					// 현재 경험치, 최대 경험치

	float _time;

	int _behaviorCount;							//커서 움직임을 위한 변수

	bool _isBattleScript;
	bool _isTurn;								// 공격 애니메이션 띄우는 중인지
	bool _isNext;								// 후턴 포켓몬의 공격 차례인지

	int _currentPoke = 0;						// 플레이어의 현재 포켓몬의 인덱스 번호(0~5)
	int _currentSkill;							// 현재 사용한 스킬의 인덱스 번호(0~3)

	int _attackCount;							// 공격 순서 판정용
	int _whoTurn;								// 현재 누구의 턴인지(0 == 평시 / 1 == 내 턴 / 2 == 상대 턴)
	int _power;

	bool _isWin;								// 배틀에서 승리했을때

	// getStarting Pokemon
	bool _isStarting;


	// 확인창(예/아니오)
	bool _isAccept;

	// class
	NPC _npc;
	character* _character;
	poketmonManager* _poketmonManager;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();

	void bag();
	void pokeDogam();
	void pokeGear();
	void playerStatus();
	void setting();

	void howStrong();

	void pokeCenter();
	void menu();

	void pokeShift();

	void script();		// 추후에 매개변수로 npc번호 받아와서 각 상황에 맞는 텍스트 출력해주면 될 듯함.

	void battle();
	void skillSelect();
	void attack();
	
	void usePokeBall();
	void useMedicine();
	void useGoodMedicine();

	void getStartingPokemon();

	

	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }

	NPC getNPC() { return _npc; }
	void setNPC(NPC npc, bool isCount) { _npc = npc; _isCount = isCount; }

	bool getIsCount() { return _isCount; }
	void setIsCount(bool isCount) { _isCount = isCount; }

	bool isUiOpen();

	bool getOpenShop() { return _isOpenShop; }
	void setOpenShop(bool openShop) { _isOpenShop = openShop; }

	bool getOpenBag() { return _isOpenBag; }
	void setOpenBag(bool openBag) { _isOpenBag = openBag; }

	bool getOpenPokecenter() { return _isOpenPokecenter; }
	void setOpenPokecenter(bool openPoke) { _isOpenPokecenter = openPoke; }

	bool getOpenMenu() { return _isOpenMenu; }
	void setOpenMenu(bool openMenu) { _isOpenMenu = openMenu; }

	bool getIsBattle() { return _isBattle; }
	void setIsBattle(bool isBattle) { _isBattle = isBattle; }

	bool getIsAnimation() { return _isAnimation; }
	void setIsAnimation(bool isAnimation) { _isAnimation = isAnimation; }

	bool getIsBattleScript() { return _isBattleScript; }
	void setIsBattleScript(bool isBattleScript) { _isBattleScript = isBattleScript;	}

	bool getIsAttack() { return _isAttack; }
	void setIsAttack(bool isAttack) { _isAttack = isAttack; }

	bool getIsTurn() { return _isTurn; }
	void setIsTurn(bool isTurn) { _isTurn = isTurn; }

	bool getIsNext() { return _isNext; }
	void setIsNext(bool next) { _isNext = next; }

	int getAttackCount() { return _attackCount; }
	void setAttackCount(int attackCount) { _attackCount = attackCount; }

	int getGold() { return gold; };
	void setGold(int newgold) { gold = newgold; }

	int getCurrentPokemon() { return _currentPoke; }
	void setCurrentPokemon(int current) { _currentPoke = current; }

	bool getIsWin() { return _isWin; }
	void setIsWin(bool isWin) { _isWin = isWin; }

	bool getIsStarting() { return _isStarting; }
	void setIsStarting(bool starting) { _isStarting = starting; }

	bool getIsAccept() { return _isAccept; }
	void setIsAccept(bool accept) { _isAccept = accept; }

	int getDrCount() { return _drCount; }

	// Memory
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setSkillMemoryAddressLink(poketmonManager* pm) { _poketmonManager = pm; }
};

