#pragma once
#include "singletonBase.h"
#include <string>

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


class uiManager : public singletonBase<uiManager>
{
private:
	int shopCnt = 0;							//상점 메뉴 선택지
	int buyCnt = 0;								//아이템 메뉴 선택지
	int menuCnt = 0;
	bool shopWindow = false;					//상점 메뉴창 띄울지 안띄울지
	bool buyWindow = false;						//아이템 메뉴창 띄울지 안띄울지

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

	bool uiOpen = false;


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


	void script(NPC npc);		// 추후에 매개변수로 npc번호 받아와서 각 상황에 맞는 텍스트 출력해주면 될 듯함.


	// get set
	bool getIsScript() { return _isScript; }
	void setIsScript(bool script) { _isScript = script; }

	vector<string> getVScript() { return _vScript; }
	void setVScript(vector<string> vScript) { _vScript = vScript; }
	bool isUiOpen();


};

