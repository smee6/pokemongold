#include "pch.h"
#include "caterpie.h"

//캐터피

caterpie::caterpie()
{
}

caterpie::~caterpie()
{
}

HRESULT caterpie::init()
{
	switch (RND->getFromIntTo(0, 3))
	{
	case 0:

		_poketmon.name = "캐터피";							//이름 캐터피
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//성별체크 랜덤
		_poketmon.index = 10;								//전국도감번호 10
		_poketmon.level = RND->getFromIntTo(1, 6);			//처음 등장 레벨 1~50

		potketmonEXP();										//경험치

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 0;						//진화단계
		_poketmon.attack = 30;								//공격					
		_poketmon.defense = 35;								//방어
		_poketmon.specialAttack = 20;						//특수공격
		_poketmon.specialDefense = 20;						//특수방어
		_poketmon.speed = 45;								//스피드		

		_poketmon.iconNumX = 14;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 1;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.44f;						//레벨당 공격력
		_poketmon.levelDefense = 1.5f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.32f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.32f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.62f;						//레벨당 스피드
		_poketmon.levelHP = 2.49f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 45;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;

		//스킬

		_poketmon.skill[0] = 1;
		_poketmon.skill[1] = 2;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "단데기";							//이름 단데기
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//성별체크 랜덤
		_poketmon.index = 11;								//전국도감번호 11
		_poketmon.level = RND->getFromIntTo(7, 50);			//처음 등장 레벨 7~50

		potketmonEXP();										//경험치

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 1;						//진화단계
		_poketmon.attack = 20;								//공격					
		_poketmon.defense = 55;								//방어
		_poketmon.specialAttack = 25;						//특수공격
		_poketmon.specialDefense = 25;						//특수방어
		_poketmon.speed = 30;								//스피드	

		_poketmon.iconNumX = 14;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 1;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.32f;						//레벨당 공격력
		_poketmon.levelDefense = 1.74f;					//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.38f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.38f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.44f;						//레벨당 스피드
		_poketmon.levelHP = 2.54f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 50;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량

		//스킬

		_poketmon.skill[0] = 26;
		_poketmon.skill[1] = 0;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 2:

		_poketmon.name = "버터플";							//이름 버터플
		_poketmon.isGender = RND->getFromIntTo(0, 2);		//성별체크 랜덤
		_poketmon.index = 12;								//전국도감번호 12
		_poketmon.level = RND->getFromIntTo(10, 50);		//처음 등장 레벨 10~50

		potketmonEXP();										//경험치

		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행타입
		_poketmon.evolutionLevel = 2;						//진화단계
		_poketmon.attack = 45;								//공격					
		_poketmon.defense = 50;								//방어
		_poketmon.specialAttack = 80;						//특수공격
		_poketmon.specialDefense = 80;						//특수방어
		_poketmon.speed = 70;								//스피드		

		_poketmon.iconNumX = 26;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 1;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.62f;						//레벨당 공격력
		_poketmon.levelDefense = 1.68f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 2.16f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 2.04f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.92f;						//레벨당 스피드
		_poketmon.levelHP = 2.64f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 60;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량

		//스킬

		_poketmon.skill[0] = 3;
		_poketmon.skill[1] = 4;
		_poketmon.skill[2] = 5;
		_poketmon.skill[3] = 6;

		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}



	return S_OK;

}

void caterpie::release()
{
}

void caterpie::update()
{

}

void caterpie::render()
{
}
