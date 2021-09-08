#pragma once
#include "gameNode.h"

enum class STATUS_AILMENT	// 상태이상
{
	NONE,					// 없음
	POISON,					// 독
	BURN,					// 화상
	PARALYSIS,				// 마비
	SLEEP,					// 수면
	FREEZE,					// 얼음
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

	string _name;				// 스킬 이름 <민기가 추가 해달라고 한거>

	string _imgName;			// 이미지 띄울때 이름 필요할거 같아서 일단 추가 나중에 상황봐서 지울수도있음.



	image* _skillImg;			//스킬 이미지
	int _currentFrame;			//프레임 초기화 할거.
	int _frameCount;			//프레임 카운트
	int _count;					//카운트 뒤 끝나게
	
	


	int _power;					// 위력
	int _accuracy;				// 명중률
	int _PP;					// PP
	int _number;				// 넘버
	int _skillLever;			// 스킬레벨

	POINT _imgPoint;			// 이미지 띄우는 거 조정할려고 만든 함수
	

	int _index;					// 확률 조건걸떄 필요한 수

	bool _isSkill;				// 스킬 사용확인
	bool _isWhoSkill;			// 이미지 위치 띄우는거 조절할려고 만든 불값 플레이어(true) 인가 야생(false)인가 

	RECT rc;					//위치 잡을 임시용

public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();
	

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

	void render();

	void skillAni();		// 스킬 애니메이션
	void imageInit();		// 이미지



	bool getIsSkill() { return _isSkill; }					//불값 getter값
	void setIsSkill(bool skill) { skill = _isSkill; }		//불값 setter값






};


