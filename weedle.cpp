#include "pch.h"
#include "weedle.h"

weedle::weedle()
{
}

weedle::~weedle()
{
}

HRESULT weedle::init()
{
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "뿔충이";							//이름 뿔충이
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 13;								//전국도감번호 13
		_poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//독타입
		_poketmon.evolutionLevel = 0;						//진화단계
		_poketmon.attack = 35;								//공격					
		_poketmon.defense = 30;								//방어
		_poketmon.specialAttack = 20;						//특수공격
		_poketmon.specialDefense = 20;						//특수방어
		_poketmon.speed = 50;								//스피드		

		_poketmon.levelAttack = 1.5f;						//레벨당 공격력
		_poketmon.levelDefense = 1.44f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.32f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.32f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.68f;						//레벨당 스피드
		_poketmon.levelHP = 2.44f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 40;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100레벨 경험치량
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 1:

		_poketmon.name = "딱충이";							//이름 딱충이
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 14;								//전국도감번호 14
		_poketmon.level = RND->getFromIntTo(7, 50);			//처음 등장 레벨 7~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//독타입
		_poketmon.evolutionLevel = 1;						//진화단계
		_poketmon.attack = 25;								//공격					
		_poketmon.defense = 50;								//방어
		_poketmon.specialAttack = 25;						//특수공격
		_poketmon.specialDefense = 25;						//특수방어
		_poketmon.speed = 35;								//스피드		

		_poketmon.levelAttack = 1.38f;						//레벨당 공격력
		_poketmon.levelDefense = 1.68f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.38f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.38f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.5f;						//레벨당 스피드
		_poketmon.levelHP = 2.49f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 45;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 2:

		_poketmon.name = "독침붕";							//이름 독침붕
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 15;								//전국도감번호 15
		_poketmon.level = RND->getFromIntTo(10, 50);		//처음 등장 레벨 10~50
		_poketmon.type1 = static_cast<int>(TYPE::BUG);		//벌레타입
		_poketmon.type2 = static_cast<int>(TYPE::POISON);	//독타입
		_poketmon.evolutionLevel = 2;						//진화단계
		_poketmon.attack = 90;								//공격					
		_poketmon.defense = 40;								//방어
		_poketmon.specialAttack = 45;						//특수공격
		_poketmon.specialDefense = 80;						//특수방어
		_poketmon.speed = 75;								//스피드		

		_poketmon.levelAttack = 2.16f;						//레벨당 공격력
		_poketmon.levelDefense = 1.56f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.62f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 2.04f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.98f;						//레벨당 스피드
		_poketmon.levelHP = 2.69f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 65;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;
	}

	return S_OK;

}

void weedle::release()
{
}

void weedle::update()
{
}

void weedle::render()
{
}
