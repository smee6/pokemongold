#include "pch.h"
#include "pikachu.h"

//피카츄

pikachu::pikachu()
{
}

pikachu::~pikachu()
{
}

HRESULT pikachu::init()
{
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "피카츄";							//이름 피카츄
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 25;								//전국도감번호 25
		_poketmon.level = RND->getFromIntTo(1, 19);			//처음 등장 레벨 1~50
		_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//전기타입
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 0;						//진화단계
		_poketmon.attack = 55;								//공격					
		_poketmon.defense = 40;								//방어
		_poketmon.specialAttack = 50;						//특수공격
		_poketmon.specialDefense = 50;						//특수방어
		_poketmon.speed = 90;								//스피드		

		_poketmon.iconNumX = 28;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.74f;						//레벨당 공격력
		_poketmon.levelDefense = 1.56f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.68f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.68f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 2.16f;						//레벨당 스피드
		_poketmon.levelHP = 2.39f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 35;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100레벨 경험치량

		//스킬

		_poketmon.skill[0] = 18;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "라이츄";							//이름 라이츄
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 26;								//전국도감번호 26
		_poketmon.level = RND->getFromIntTo(20, 50);		//처음 등장 레벨 1~15
		_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//전기타입
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
		_poketmon.evolutionLevel = 1;						//진화단계
		_poketmon.attack = 90;								//공격					
		_poketmon.defense = 55;								//방어
		_poketmon.specialAttack = 90;						//특수공격
		_poketmon.specialDefense = 80;						//특수방어
		_poketmon.speed = 110;								//스피드		

		_poketmon.iconNumX = 28;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 2.16f;						//레벨당 공격력
		_poketmon.levelDefense = 1.74f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 2.16f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 2.04f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 2.4f;						//레벨당 스피드
		_poketmon.levelHP = 2.64f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 60;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//100레벨 경험치량

		//스킬

		_poketmon.skill[0] = 18;
		_poketmon.skill[1] = 14;
		_poketmon.skill[2] = 12;
		_poketmon.skill[3] = 19;

		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}


	return S_OK;


}

void pikachu::release()
{
}

void pikachu::update()
{
}

void pikachu::render()
{
}
