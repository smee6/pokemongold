#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>

using namespace std;

struct tagPOKETMON_PLAYER
{
	string name;							// 이름
	string gender;							// 성별
	bool isGender;							// 성별 체크
	int index;								// 인덱스 번호
	int level;								// 포켓몬 현재 레벨
	int	evolutionLevel;						// 진화 단계

	int type1; 								// 포켓몬 타입1	
	int type2;								// 포켓몬 타입2

	int iconNumX;							// 포켓몬 창에서 프레임 넘버 X값
	int iconNumY;							// 포켓몬 창에서 프레임 넘버 Y값

	int	attack;								// 1레벨 초기 공격
	int	defense;							// 1레벨 초기 방어	
	int specialAttack;						// 1레벨 초기 특수공격
	int	specialDefense;						// 1레벨 초기 특수방어
	int	speed;								// 1레벨 초기 스피드
	int	currentHP;							// 1레벨 초기 현재 체력
	int	maxHP;								// 1레벨 초기 최대 체력

	float levelAttack;						// 레벨당 증가하는 공격
	float levelDefense;						// 레벨당 증가하는 방어	
	float levelSpecialAttack;				// 레벨당 증가하는 특수공격
	float levelSpecialDefense;				// 레벨당 증가하는 특수방어
	float levelSpeed;						// 레벨당 증가하는 스피드
	float levelHP;							// 레벨당 증가하는 체력

	int sumAttack;							// 최종 공격
	int sumDefense;							// 최종 방어
	int sumSpecialAttack;					// 최종 특수공격
	int sumSpecialDefense;					// 최종 특수방어
	int sumSpeed;							// 최종 스피드
	int sumMaxHP;							// 최종 체력

	int currentExp;						// 현재 경험치(현재 얻은 총 경험치, level값 만큼 빼서 나머지 양 보여주기)
	int	maxExp;							// 최대 경험치(현재 레벨의 최대 경험치 값 표시)

	int totalEXP;							// 토탈 경험치

	int	skill[4];							// 스킬1 인덱스 
	int skillPP[4];							// 스킬1 현재 PP

	int item;								// 보유 중인 아이템 인덱스
};

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "keyAniManager.h"
#include "utils.h"
#include "txtData.h"
#include "iniDataManager.h"
#include "uiManager.h"

using namespace TN_UTILS;

//========================================
// ## 윈도우 설정 디파인문 ## 2021.05.26 ##
//========================================

#define WINNAME		(LPTSTR)TEXT("Class29")			//윈도우 이름
#define WINSTARTX	50								//윈도우 시작좌표(left)
#define WINSTARTY	50								//윈도우 시작좌표(top)
#define WINSIZEX	640								//윈도우 가로크기
#define WINSIZEY	576								//윈도우 세로크기
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniDataManager::getSingleton()
#define UIMANAGER uiManager::getSingleton()


#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = nullptr;}}

//===========================
// ## extern ## 21.05.28 ##
//===========================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern BOOL _leftButtonDown;