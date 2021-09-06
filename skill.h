#pragma once
#include "gameNode.h"

enum class STATUS_AILMENT	// 상태이상
{
	POISON,					// 독
	BURN,					// 화상
	PARALYSIS,				// 마비
	SLEEP,					// 수면
	FREEZE,					// 얼음
	NONE					// 없음
};

enum class CLASSIFCATION	// 분류
{
	PHYSICS,				// 물리
	SPECIAL,				// 특수
	CHANGE,					// 변화

};

class skill : public gameNode
{
private:

	int _power;					// 위력
	int _accuracy;				// 명중률
	int _PP;					// PP
	int _number;				// 넘버
	int _skillLever;			// 스킬레벨

	int _index;					// 확률 조건걸떄 필요한 수


public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();
	void render();

	void tackle();			// 몸통박치기
	void stringShot();		// 실뿜기
	void harden();			// 단단해지기
	void confusion();		// 염동력
	void poisonPowder();	// 독가루
	void stunSpore();		// 저리가루
	void sleepPowder();		// 수면가루

	void poisonSting();		// 독침
	void focusEnergy();		// 기충전
	void twineedle();		// 더블니들

	void sandAttack();		// 모래뿌리기
	void gust();			// 바람일으키기
	void quickAttack();		// 전광석화
	void wingAttack();		// 날개치기

	void tailWhip();		// 꼬리흔들기

	void peck();			// 쪼기
	void growl();			// 울음소리
	void leer();			// 쨰려보기

	void thunderShock();	// 전기쇼크
	void thunderbolt();		// 10만볼트

	void razorLeaf();		// 잎날가르기
	void reflect();			// 리플렉터

	void smokescreen();		// 연막
	void ember();			// 불꽃세례

	void rage();			// 분노
	void waterGun();		// 물대포






};


