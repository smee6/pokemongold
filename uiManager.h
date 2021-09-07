#pragma once
#include "singletonBase.h"
#include <string>
#include <vector>



enum class NPC
{
	// title
	TITLE,

	// mom
	MOM_FIRST,
	MOM_NORMAL,

	// Dr.Gong
	DR_FIRST,
	DR_BEFORE_POKEMON,
	DR_AFTER_POKEMON,
	DR_NORMAL,
	SUPPORTER,

	// champion
	CHAMPION_BATTLE_START,
	CHAMPION_BATTLE_AFTER,
	CHAMPION_BATTLE_END,

	// trainers
	TRAINER1_BATTLE_BEFORE,
	TRAINER1_BATTLE_START,
	TRAINER1_BATTLE_END,
	TRAINER1_BATTLE_WIN,

	TRAINER2_BATTLE_BEFORE,
	TRAINER2_BATTLE_START,
	TRAINER2_BATTLE_END,
	TRAINER2_BATTLE_WIN,

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


};


class character;

class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//상점 메뉴 선택지
	int buyCnt = 0;								//아이템 메뉴 선택지
	int menuCnt = 0;
	int bagCnt = 0;
	int pokesCnt = 0;
	bool shopWindow = false;					//상점 메뉴창 띄울지 안띄울지
	bool buyWindow = false;						//아이템 메뉴창 띄울지 안띄울지
	bool bagWindow = false;
	bool menuWindow = false;
	bool pokeWindow = false;
	int pokeballQ = 50;   // 포켓볼 보유 갯수 , 아래는 상처약, 고급상처약 갯수 (Q)
	int medicineQ = 22;
	int goodMedicineQ = 13;
	int delaycnt;
	int iconCnt;
	// isOpen
	bool _isOpenShop;							// 상점 열려있는지
	bool _isOpenBag;							// 가방 열려있는지
	bool _isOpenPokecenter;						// 포케센터 열려있는지
	bool _isOpenMenu;							// 메뉴 열려있는지


	// script
	bool _isScript;								// 대화 여부 (대화 중인지)
	bool _isScriptSkip;							// 스킵 여부 (대화 한꺼번에 출력)
	image* _scriptImage;						// 스크립트 배경이미지
	int _scriptIndex;							// 스크립트 줄 카운트(문장?)
	int _txtIndex;								// 스크립트 글자 카운트
	vector<string> _vScript;					// 스크립트를 담을 벡터
	string _txt;								// 실제 텍스트 파일

	// pokeCenter
	int cnt = 0;

	int _index = 0;

	bool uiOpen = false;						// ui 켜져 있는지 여부

	NPC _npc;
	character* _character;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void shop();
	void bag();

	void pokeCenter();
	void menu();

	void pokeShift();

	void script();		// 추후에 매개변수로 npc번호 받아와서 각 상황에 맞는 텍스트 출력해주면 될 듯함.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }

	NPC getNPC() { return _npc; }
	void setNPC(NPC npc) { _npc = npc; }

	bool isUiOpen();

	bool getOpenShop() { return _isOpenShop; }
	void setOpenShop(bool openShop) { _isOpenShop = openShop; }

	bool getOpenBag() { return _isOpenBag; }
	void setOpenBag(bool openBag) { _isOpenBag = openBag; }

	bool getOpenPokecenter() { return _isOpenPokecenter; }
	void setOpenPokecenter(bool openPoke) { _isOpenPokecenter = openPoke; }

	bool getOpenMenu() { return _isOpenMenu; }
	void setOpenMenu(bool openMenu) { _isOpenMenu = openMenu; }

	void setCharacterMemoryAddressLink(character* character) { _character = character; }
};

