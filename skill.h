#pragma once
#include "gameNode.h"

class poketmonManager;
class character;

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

enum class SKILL_TYPE
{
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

class skill : public gameNode
{
private:

	string _name;				// 스킬 이름 <민기가 추가 해달라고 한거>

	string _imgName;			// 이미지 띄울때 이름 필요할거 같아서 일단 추가 나중에 상황봐서 지울수도있음.



	image* _skillImg;			//스킬 이미지
	int _currentFrame;			//프레임 초기화 할거.
	int _frameCount;			//프레임 카운트
	int _count;					//카운트 뒤 끝나게

	int _imgX, _imgY;			//이미지 위치조정

	//SKILL_TYPE _skilltype;		//스킬타입


	int _power;					// 위력
	int _accuracy;				// 명중률
	int _PP;					// PP

	int _skillNumber;			// 스킬 넘버
	int _skillLever;			// 스킬레벨

	int _skilltype;				// 스킬 타입

	STATUS_AILMENT _ifAilment;	// 상태이상
	CLASSIFCATION _ifcation;	// 분류


	POINT _imgPoint;			// 이미지 띄우는 거 조정할려고 만든 함수


	int _index;					// 확률 조건걸떄 필요한 수

	bool _isSkill;				// 스킬 사용확인
	bool _isWhoSkill;			// 이미지 위치 띄우는거 조절할려고 만든 불값 플레이어(true) 인가 야생(false)인가 

	// 사운드 출력위한 변수
	int _skillIndex;
	bool _isSound;

	RECT rc;					//위치 잡을 임시용

	poketmonManager* _pM;
	character* _ch;

public:

	skill();
	~skill();

	HRESULT init();
	void release();
	void update();

	void skillNone();		// 스킬없음
	void tackle();			// 몸통박치기
	void stringShot();		// 실뿜기
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
	void harden();			// 단단해지기

	void scratch();			// 할퀴기
	void furyAttack();		// 마구찌르기
	
							
			  //추가작업
	void bind();			// 조이기
	void bite();			// 물기

	void render();

	void skillAni();		// 스킬 애니메이션
	void imageInit();		// 이미지

	void skillNumLink(int index);

	bool getIsSkill() { return _isSkill; }						//불값 getter값
	void setIsSkill(bool skill) { _isSkill = skill; }			//불값 setter값

	bool getWhoSkill() {return _isWhoSkill;	}					// whoskill getter값
	void setWhoSkill(bool whoSkill) { _isWhoSkill = whoSkill; }	// whoskill setter값

	string getSkillName() { return _name; }						//네임 getter
	string getSkillImgName() { return _imgName; }				//이미지네임 getter

	int getSkillPower() { return _power; }						//위력 getter
	int getSkillPP() { return _PP; }							//PP getter
	int getSkillAccuracy() { return _accuracy; }				//명중률 getter

	int getSkillType() { return _skilltype; }

	int getSkillIndex() { return _skillIndex; }
	void setSkillIndex(int index) { _skillIndex = index; }

	bool getIsSound() { return _isSound; }
	void setIsSound(bool sound) { _isSound = sound; }

	//CLASSIFCATION getIfcation() { return _ifcation; }			//분류
					//타입
	//STATUS_AILMENT getifAilemnt() { return _ifAilment; }		//상태이상

	void setPoketmonmanagerMemoryAddressLink(poketmonManager* pM) { _pM = pM; }
	void setCharacterMemoryAddressLink(character* ch) { _ch = ch; }

};


