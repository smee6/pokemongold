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

	_index = 0;

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
	skillAni();

	if (KEYMANAGER->isOnceKeyDown('P')) _isSkill = true;
	//if(KEYMANAGER->isOnceKeyDown('O')) _isSkill = false;

	//rc = RectMake(_ptMouse.x, _ptMouse.y, 100, 100);
}

void skill::render()
{
	char str[128];

	Rectangle(getMemDC(), rc);

	_imgName = "cut";

	if (_isSkill) IMAGEMANAGER->frameRender(_imgName, getMemDC(), 320, 270, _index, 0);


	//sprintf_s(str, "mouse좌표x : %d ", _ptMouse.x);
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
	//sprintf_s(str, "mouse좌표y : %d ", _ptMouse.y);
	//TextOut(getMemDC(), 50, 70, str, strlen(str));
	//sprintf_s(str, "count : %d ", _count);
	//TextOut(getMemDC(), 50, 90, str, strlen(str));


}

void skill::tackle()			// 몸통박치기
{
	_name = "몸통박치기";		//이름
	_imgName = "cut";			//이미지이름

	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입

}

void skill::stringShot()		//실뿜기
{
	_name = "실뿜기";			//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 95;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::BUG;					//타입

}

void skill::harden()			//단단해지기
{
	_name = "단단해지기";		//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::confusion()			//염동력
{
	_name = "염동력";			//이름
	_imgName = "cut";			//이미지이름

	_power = 50;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::PSYCHC;				//타입	
}

void skill::poisonPowder()		//독가루
{
	_name = "독가루";			//이름
	_imgName = "poison";		//이미지이름

	_power = NULL;				//위력
	_PP = 35;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::POISON;				//타입
	STATUS_AILMENT::POISON;		//상태이상
}

void skill::stunSpore()			//저리가루
{
	_name = "저리가루";			//이름
	_imgName = "poison";		//이미지이름

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GRASS;				//타입
	STATUS_AILMENT::PARALYSIS;	//상태이상
}

void skill::sleepPowder()		//수면가루
{
	_name = "수면가루";			//이름
	_imgName = "poison";		//이미지이름

	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GRASS;				//타입
	STATUS_AILMENT::SLEEP;		//상태이상
}

void skill::poisonSting()		//독침
{
	_index = RND->getFromIntTo(0, 100);

	_name = "독침";				//이름
	_imgName = "cut";			//이미지이름

	_power = 15;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::POISON;				//타입

	if (_index > 80) STATUS_AILMENT::POISON;	//상태이상 20퍼 확률로..

}

void skill::focusEnergy()		//기충전
{
	_name = "기충전";			//이름
	_imgName = "growth";			//이미지이름

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::twineedle()			//더블니들
{
	_name = "더블니들";			//이름
	_imgName = "cut";			//이미지이름

	_power = 25;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::BUG;					//타입
}

void skill::sandAttack()		//모래뿌리기
{
	_name = "모래뿌리기";		//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GROUND;				//타입

}

void skill::gust()				//바람일으키기
{
	_name = "바람일으키기";		//이름
	_imgName = "squall";		//이미지이름

	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::FLYING;				//타입
}

void skill::quickAttack()		//전광석화
{
	_name = "전광석화";			//이름
	_imgName = "cut";			//이미지이름

	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입
}

void skill::wingAttack()		//날개치기
{
	_name = "날개치기";			//이름
	_imgName = "cut";			//이미지이름

	_power = 60;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::FLYING;				//타입
}

void skill::tailWhip()			//꼬리흔들기
{
	_name = "꼬리흔들기";		//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::peck()				//쪼기
{
	_name = "쪼기";				//이름
	_imgName = "cut";			//이미지이름

	_power = 35;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::FLYING;				//타입
}

void skill::growl()				//울음소리
{
	_name = "울음소리";			//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::leer()				//째려보기
{
	_name = "째려보기";			//이름
	_imgName = "cut";			//이미지이름

	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::thunderShock()		//전기쇼크
{
	_index = RND->getFromIntTo(0, 100);

	_name = "전기쇼크";			//이름
	_imgName = "spark";			//이미지이름

	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::ELECTR;				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼확률로 마비

}

void skill::thunderbolt()		//10만볼트
{
	_index = RND->getFromIntTo(0, 100);

	_name = "10만볼트";			//이름
	_imgName = "spark";			//이미지이름

	_power = 90;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::ELECTR;				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼 확률로 마비
}

void skill::razorLeaf()			//잎날가르기
{
	_name = "잎날가르기";		//이름
	_imgName = "cut";			//이미지이름

	_power = 55;				//위력
	_PP = 25;					//PP
	_accuracy = 95;				//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::GRASS;				//타입
}

void skill::reflect()			//리플렉터 물리데미지 반감.
{
	_name = "리플렉터";			//이름
	_imgName = "lightScreen";	//이미지이름

	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::PSYCHC;				//타입
}

void skill::smokescreen()		//연막
{
	_name = "연막";				//이름
	_imgName = "smokescreen";	//이미지이름

	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::ember()				//불꽃세례
{
	_index = RND->getFromIntTo(0, 100);

	_name = "불꽃세례";			//이름
	_imgName = "fire";			//이미지이름

	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::FIRE;					//타입

	if (_index > 90) STATUS_AILMENT::BURN; //상태이상
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//상대가 얼음상태면 녹일 수 있음 --지워질것--
}

void skill::rage()				//분노
{
	_name = "분노";				//이름
	_imgName = "cut";			//이미지이름

	_power = 20;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입
}

void skill::waterGun()			//물대포
{
	_name = "물대포";			//이름
	_imgName = "cut";			//이미지이름

	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::WATER;				//타입
}

void skill::skillAni()
{

	// 스킬 애니메이션을 돌릴곳 공격은 턴제이기 때문에 isSkill이라는 값을 주어서 껏다 켯다 해야할거 같음
	// isSkill이 true 값일때 이미지가 뜨고 애니메이션이 끝나면 isSkill이 false값이 되는게 나의 생각
	// 애니메이션이 돌아갈곳이 일단 필요하다.


	if (_isSkill)	//스킬이 활성화 됬을시
	{
		_index++;	//프레임 돌릴거
		_count++;	//일정시간뒤에 꺼지게 할려고

		if (_index % 5)	//속도 조정 조정안되는거 같습니다.
		{
			if (_index > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count < 50)		//일단은 예비이미지 파이어 불러오기 && 일정시간이 200count가 흐르면
			{
				_index = 0;					//프레임을 초기화 시켜 계속 이미지를 반복시키고
			}
			if (_index > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count > 50)		//맥스프레임이고 카운터가 200이상이면 끝나면 이미지를 끝낸다.
			{
				_isSkill = false;		//조건에 맞으면 스킬을 비활성화 시켜서 이미지를 지우고
				_count = 0;				//카운터를 다시 초기화 시켜준다
			}
		}

	}



}

void skill::imageInit()	//스킬 이미지
{
	IMAGEMANAGER->addImage("attack", "image/skill/attack.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 720, 45, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 600, 50, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 352, 20, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 1152, 72, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("horn", "image/skill/horn.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 450, 63, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 220, 56, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 1620, 50, 27, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 960, 40, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 352, 44, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 1118, 57, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("smokescreen", "image/skill/smokescreen.bmp", 560, 20, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));


}
