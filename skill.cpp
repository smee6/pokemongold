#include "pch.h"
#include "skill.h"
#include "poketmon.h"

skill::skill()
{
}

skill::~skill()
{
}

HRESULT skill::init()
{
	imageInit();

	STATUS_AILMENT::NONE;	// 상태이상 초기값은 없음

	_imgName = "lightScreen";							//처음에 들어가는 값


	_index = _currentFrame = _frameCount = 0;		//애니메이션 관련 초기화

	_isWhoSkill = false;							//초기화
	_isSkill = false;							//초기화

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{

	//밑에 키매니저들은 체크할려고 만든 것들 나중에 지워도 됨
	if (KEYMANAGER->isOnceKeyDown('P')) _isSkill = true;
	if (KEYMANAGER->isOnceKeyDown('I')) _isWhoSkill = true;	//나 (플레이어)
	if (KEYMANAGER->isOnceKeyDown('U')) _isWhoSkill = false;	//야생

	if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	rc = RectMake(480, _imgPoint.y, 112, 112);	// 포켓몬이 없어서 대신 할 것을 만듬


	skillAni();

}

void skill::skillNone()			//스킬없음
{
	_skillNumber = 0;			//스킬넘버

	_name = "";					//이름

	_power = NULL;				//위력
	_PP = NULL;					//PP
	_accuracy = NULL;			//명중률

	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::tackle()			// 몸통박치기
{

	_skillNumber = 1;			//스킬넘버

	_name = "몸통박치기";		//이름
	_imgName = "attack3";		//이미지이름

	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입

}

void skill::stringShot()		//실뿜기
{
	_skillNumber = 2;			//스킬넘버

	_name = "실뿜기";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 95;				//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);					//타입

}

void skill::confusion()			//염동력
{
	_skillNumber = 3;			//스킬넘버

	_name = "염동력";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 50;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);				//타입	
}

void skill::poisonPowder()		//독가루
{
	_skillNumber = 4;			//스킬넘버

	_name = "독가루";			//이름
	_imgName = "poison";		//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 35;					//PP
	_accuracy = 75;				//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);				//타입
	_ifAilment = STATUS_AILMENT::POISON;		//상태이상
}

void skill::stunSpore()			//저리가루
{
	_skillNumber = 5;			//스킬넘버

	_name = "저리가루";			//이름
	_imgName = "poison";		//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 75;				//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//타입
	_ifAilment = STATUS_AILMENT::PARALYSIS;	//상태이상
}

void skill::sleepPowder()		//수면가루
{
	_skillNumber = 6;			//스킬넘버

	_name = "수면가루";			//이름
	_imgName = "poison";		//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 75;				//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//타입
	_ifAilment = STATUS_AILMENT::SLEEP;		//상태이상
}

void skill::poisonSting()		//독침
{
	_skillNumber = 7;			//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "독침";				//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 15;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);				//타입

	if (_index > 80) STATUS_AILMENT::POISON;	//상태이상 20퍼 확률로..

}

void skill::focusEnergy()		//기충전
{
	_skillNumber = 8;			//스킬넘버

	_name = "기충전";			//이름
	_imgName = "growth";		//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::twineedle()			//더블니들
{
	_skillNumber = 9;			//스킬넘버

	_name = "더블니들";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 25;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);					//타입
}

void skill::sandAttack()		//모래뿌리기
{
	_skillNumber = 10;			//스킬넘버

	_name = "모래뿌리기";		//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GROUND);				//타입

}

void skill::gust()				//바람일으키기
{
	_skillNumber = 11;			//스킬넘버

	_name = "바람일으키기";		//이름
	_imgName = "squall";		//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//타입
}

void skill::quickAttack()		//전광석화
{
	_skillNumber = 12;			//스킬넘버

	_name = "전광석화";			//이름
	_imgName = "move";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::wingAttack()		//날개치기
{
	_skillNumber = 13;			//스킬넘버

	_name = "날개치기";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 60;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//타입
}

void skill::tailWhip()			//꼬리흔들기
{
	_skillNumber = 14;			//스킬넘버

	_name = "꼬리흔들기";		//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::peck()				//쪼기
{
	_skillNumber = 15;			//스킬넘버

	_name = "쪼기";				//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 35;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);				//타입
}

void skill::growl()				//울음소리
{
	_skillNumber = 16;			//스킬넘버

	_name = "울음소리";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::leer()				//째려보기
{
	_skillNumber = 17;			//스킬넘버

	_name = "째려보기";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::thunderShock()		//전기쇼크
{
	_skillNumber = 18;			//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "전기쇼크";			//이름
	_imgName = "spark";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼확률로 마비

}

void skill::thunderbolt()		//10만볼트
{
	_skillNumber = 19;			//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "10만볼트";			//이름
	_imgName = "spark";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 90;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼 확률로 마비
}

void skill::razorLeaf()			//잎날가르기
{
	_skillNumber = 20;			//스킬넘버

	_name = "잎날가르기";		//이름
	_imgName = "bind";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 55;				//위력
	_PP = 25;					//PP
	_accuracy = 95;				//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);				//타입
}

void skill::reflect()			//리플렉터 물리데미지 반감.
{
	_skillNumber = 21;			//스킬넘버

	_name = "리플렉터";			//이름
	_imgName = "lightScreen";	//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = NULL;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);				//타입
}

void skill::smokescreen()		//연막
{
	_skillNumber = 22;			//스킬넘버

	_name = "연막";				//이름
	_imgName = "smokescreen";	//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::ember()				//불꽃세례
{
	_skillNumber = 23;			//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "불꽃세례";			//이름
	_imgName = "fire";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FIRE);					//타입

	if (_index > 90) STATUS_AILMENT::BURN; //상태이상
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//상대가 얼음상태면 녹일 수 있음 --지워질것--
}

void skill::rage()				//분노
{
	_skillNumber = 24;			//스킬넘버

	_name = "분노";				//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 20;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::waterGun()			//물대포
{
	_skillNumber = 25;			//스킬넘버

	_name = "물대포";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::SPECIAL;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::WATER);				//타입
}

void skill::harden()			//단단해지기
{
	_skillNumber = 26;			//스킬넘버

	_name = "단단해지기";		//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	_ifcation = CLASSIFCATION::CHANGE;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::scratch()			//할퀴기
{
	_skillNumber = 27;			//스킬넘버

	_name = "할퀴기";			//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::furyAttack()		//마구찌르기
{
	_skillNumber = 28;			//스킬넘버

	_name = "마구찌르기";		//이름
	_imgName = "cut";			//이미지이름

	//if (_isWhoSkill) _imgPoint = { 100,250 };		//	플레이어 일시
	//if (!_isWhoSkill) _imgPoint = { 450,70 };		//	야생일시

	_power = 15;				//위력
	_PP = 20;					//PP
	_accuracy = 85;				//명중률
	_ifcation = CLASSIFCATION::PHYSICS;		//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);				//타입
}

void skill::render()
{


	char str[128];

	if (_isSkill) Rectangle(getMemDC(), rc);

	if (_isSkill) IMAGEMANAGER->frameRender(_imgName, getMemDC(), _imgPoint.x, _imgPoint.y, _currentFrame, 0);



	//sprintf_s(str, "좌표x : %d ", _imgPoint.x);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
	//sprintf_s(str, "좌표y : % d ", _imgPoint.y);
	//TextOut(getMemDC(), 50, 70, str, strlen(str));
	//sprintf_s(str, "상태 : %d ", _isWhoSkill);
	//TextOut(getMemDC(), 50, 90, str, strlen(str));


}

void skill::skillAni()
{

	// 스킬 애니메이션을 돌릴곳 공격은 턴제이기 때문에 isSkill이라는 값을 주어서 껏다 켯다 해야할거 같음
	// isSkill이 true 값일때 이미지가 뜨고 애니메이션이 끝나면 isSkill이 false값이 되는게 나의 생각
	// 애니메이션이 돌아갈곳이 일단 필요하다.


	if (_isSkill)	//스킬이 활성화 됬을시
	{
		_frameCount++;		//프레임 돌릴거
		_count++;			//일정시간뒤에 꺼지게 할려고

		if (_frameCount % 4 == 0)	//속도 조정 조정안되는거 같습니다.
		{
			_currentFrame++; //현재프레임 재생중

			//IMAGEMANAGER->findImage(_imgName)->setFrameX(IMAGEMANAGER->findImage(_imgName)->getFrameX() + 1);


			if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count < 100)		//일단은 예비이미지 파이어 불러오기 && 일정시간이 200count가 흐르면
			{
				_currentFrame = 0;					//프레임을 초기화 시켜 계속 이미지를 반복시키고
			}
			else if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count > 100)		//맥스프레임이고 카운터가 200이상이면 끝나면 이미지를 끝낸다.
			{
				_isSkill = false;					//조건에 맞으면 스킬을 비활성화 시켜서 이미지를 지우고
				_count = 0;							//카운터를 다시 초기화 시켜준다
			}

		}

	}



}

void skill::imageInit()	//스킬 이미지
{
	IMAGEMANAGER->addFrameImage("attack", "image/skill/attack.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 1440, 90, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 1440, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 176, 100, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 2160, 144, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("horn", "image/skill/horn.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 900, 126, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 440, 112, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 3240, 100, 27, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 960, 40, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 352, 44, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 1118, 57, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("smokescreen", "image/skill/smokescreen.bmp", 560, 20, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("confuseRay", "image/skill/confuseRay.bmp", 312, 78, 4, 1, true, RGB(255, 0, 255));


}

void skill::skillNumLink(int index)		// 스킬을 스킬넘버와 연결 해서 넘겨줌?
{
	_skillNumber = index;
	switch (_skillNumber)
	{
	case 0:
		skillNone();
		break;
	case 1:
		tackle();
		break;
	case 2:
		stringShot();
		break;
	case 3:
		confusion();
		break;
	case 4:
		poisonPowder();
		break;
	case 5:
		stunSpore();
		break;
	case 6:
		sleepPowder();
		break;
	case 7:
		poisonSting();
		break;
	case 8:
		focusEnergy();
		break;
	case 9:
		twineedle();
		break;
	case 10:
		sandAttack();
		break;
	case 11:
		gust();
		break;
	case 12:
		quickAttack();
		break;
	case 13:
		wingAttack();
		break;
	case 14:
		tailWhip();
		break;
	case 15:
		peck();
		break;
	case 16:
		growl();
		break;
	case 17:
		leer();
		break;
	case 18:
		thunderShock();
		break;
	case 19:
		thunderbolt();
		break;
	case 20:
		razorLeaf();
		break;
	case 21:
		reflect();
		break;
	case 22:
		smokescreen();
		break;
	case 23:
		ember();
		break;
	case 24:
		rage();
		break;
	case 25:
		waterGun();
		break;
	case 26:
		harden();
		break;
	case 27:
		scratch();
		break;
	case 28:
		furyAttack();
		break;
	}

}
