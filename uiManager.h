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
	CYNDAQUIL,		// 브케인
	TOTODILE,		// 리아코
	CHIKORITA,		// 치코리타

	// starting select cancel
	SELECTCANCEL,

	// battle(test)
	BATTLE,
	BATTLE_ATTACK,
	BATTLE_DOWN,

	CHAMPION_BATTLE_DOWN,
	CHAMPION_BATTLE_WIN,
	TRAINER1_BATTLE_DOWN,
	TRAINER1_BATTLE_WIN,
	TRAINER2_BATTLE_DOWN,
	TRAINER2_BATTLE_WIN,

	// pokemon change
	POKEMONCHANGE,
};

class tileMap;
class character;

class uiManager : public singletonBase<uiManager>
{
private:

	tileMap* _tileMap;


	int gold = 5000;
	
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
	tagPOKETMON_PLAYER _currentEnemyPokemon;	// 현재 나와있는 상대 포켓몬
	tagPOKETMON_PLAYER _currentPokemon;			// 현재 나와있는 내 포켓몬
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

	bool _isBattleScript;						// 배틀 시작 스크립트 실행 여부
	bool _isTurn;								// 공격 애니메이션 띄우는 중인지
	bool _isNext;								// 후턴 포켓몬의 공격 차례인지
	bool _isBattleStart;						// 배틀 시작 시 한 번 체크

	int _currentPoke;							// 플레이어의 현재 포켓몬의 인덱스 번호(0~5)
	int _currentEnemyIndex;						// 상대방의 현재 포켓몬의 인덱스 번호
	int _currentEnemy;							// 현재 상대방 종류 (0 == 야생 / 1 == 트레이너1 / 2 == 트레이너2 / 3 == 관장)
	int _currentSkill;							// 현재 사용한 스킬의 인덱스 번호(0~3)

	int _attackCount;							// 공격 순서 판정용
	int _whoTurn;								// 현재 누구의 턴인지(0 == 평시 / 1 == 내 턴 / 2 == 상대 턴)
	int _power;

	bool _isWin;								// 배틀에서 승리했을때
	bool _isWild;								// 야생 포켓몬인지 아닌지(트레이너(false) or 야생(true))

	// getStarting Pokemon
	bool _isStarting;							// 스타팅 포켓몬 받았는지
	bool _isGetCyndaquil;						// 브케인 획득
	bool _isGetTotodile;						// 리아코 획득
	bool _isGetChikorita;						// 치코리타 획득

	// 확인창(예/아니오)
	image* _confirmImage;						// 확인창 이미지
	bool _isConfirm;							// 확인창 유무
	bool _isAccept;								// true == 예, false == 아니오
	int _acceptCount;							// 0 == 예, 1 == 아니오

	// 배지 획득여부
	bool _isGetBadge;

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

	void shop();				// 상점창

	void bag();					// 가방창
	void pokeDogam();			// 도감창
	void pokeGear();			// 포켓기어창
	void playerStatus();		// 플레이어 정보창
	void setting();				// 설정창

	void howStrong();			// 강한 정보를 보다 창

	void pokeCenter();			// 포켓몬 센터(회복)
	void menu();				// 메뉴창

	void pokeShift();			// 포켓몬창

	void script();				// 스크립트 출력창

	void battle();				// 배틀창
	void skillSelect();			// 스킬선택창
	void attack();				// 공격실행
	
	void usePokeBall();			// 포켓볼 사용
	void useMedicine();			// 상처약 사용
	void useGoodMedicine();		// 좋은 상처약 사용

	void getStartingPokemon();	// 스타팅 포켓몬 획득
	void confirm();				// 확인창(예/아니오)

	void levelUp();

	int soundVolume = 50;

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

	bool getIsConfirm() { return _isConfirm; }
	void setIsConfirm(bool confirm) { _isConfirm = confirm; }

	bool getIsCyndaquil() { return _isGetCyndaquil; }
	void setIsCyndaquil(bool Cyndaquil) { _isGetCyndaquil = Cyndaquil; }

	bool getIsTotodile() { return _isGetTotodile; }
	void setIsTotodile(bool Totodile) { _isGetTotodile = Totodile; }

	bool getIsChikorita() { return _isGetChikorita; }
	void setIsChikorita(bool Chikorita) { _isGetChikorita = Chikorita; }

	bool getIsBattleStart() { return _isBattleStart; }
	void setIsBattleStart(bool battleStart) { _isBattleStart = battleStart; }

	bool getIsWild() { return _isWild; }
	void setIsWild(bool isWild) { _isWild = isWild; }

	int getDrCount() { return _drCount; }
	int getChampionCount() { return _championCount; }
	int getTrainer1Count() { return _trainer1Count; }
	int getTrainer2Count() { return _trainer2Count; }

	bool getIsBadge() { return _isGetBadge; }

	// Memory
	void setCharacterMemoryAddressLink(character* character) { _character = character; }
	void setSkillMemoryAddressLink(poketmonManager* pm) { _poketmonManager = pm; }
	void setTileMapMemoryAddressLink(tileMap* tileMap) { _tileMap = tileMap; }
};

