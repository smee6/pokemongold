#include "pch.h"
#include "totodile.h"

//리아코

totodile::totodile()
{
}

totodile::~totodile()
{
}

HRESULT totodile::init()
{
	switch (RND->getFromIntTo(0, 3))
	{
	case 0:

		_poketmon.name = "리아코";							//이름 리아코
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤	
		_poketmon.index = 158;								//전국도감번호 158
		_poketmon.level = RND->getFromIntTo(1, 18);			//처음 등장 레벨 1~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//물타입
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 0;						//진화단계	
		_poketmon.attack = 65;								//공격					
		_poketmon.defense = 64;								//방어	
		_poketmon.specialAttack = 44;						//특수공격	
		_poketmon.specialDefense = 48;						//특수방어	
		_poketmon.speed = 43;								//스피드		

		_poketmon.iconNumX = 14;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.86f;						//레벨당 공격력
		_poketmon.levelDefense = 1.85f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.61f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.66f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.6f;						//레벨당 스피드
		_poketmon.levelHP = 2.54f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 50;			//체력	
		_poketmon.currentExp;
		_poketmon.maxExp = 1059860;							//100레벨 경험치량	

		 //스킬

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "엘리게이";							//이름 엘리게이
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤	
		_poketmon.index = 159;								//전국도감번호 159
		_poketmon.level = RND->getFromIntTo(19, 50);		//처음 등장 레벨 19~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//물타입	
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 1;						//진화단계	
		_poketmon.attack = 80;								//공격					
		_poketmon.defense = 80;								//방어	
		_poketmon.specialAttack = 59;						//특수공격	
		_poketmon.specialDefense = 63;						//특수방어	
		_poketmon.speed = 58;								//스피드			

		_poketmon.iconNumX = 14;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 2.04f;						//레벨당 공격력
		_poketmon.levelDefense = 2.04f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.79f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.84f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.78f;						//레벨당 스피드
		_poketmon.levelHP = 2.69f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 65;			//체력	
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량	

		//스킬

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 24;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 2:

		_poketmon.name = "장크로다일";						//이름 장크로다일
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤	
		_poketmon.index = 160;								//전국도감번호 160
		_poketmon.level = RND->getFromIntTo(30, 50);		//처음 등장 레벨 30~50
		_poketmon.type1 = static_cast<int>(TYPE::WATER);	//물타입	
		_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
		_poketmon.evolutionLevel = 2;						//진화단계	
		_poketmon.attack = 105;								//공격					
		_poketmon.defense = 100;							//방어	
		_poketmon.specialAttack = 79;						//특수공격	
		_poketmon.specialDefense = 83;						//특수방어	
		_poketmon.speed = 78;								//스피드		

		_poketmon.iconNumX = 14;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 2.34f;						//레벨당 공격력
		_poketmon.levelDefense = 2.28f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 2.03f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 2.08f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 2.02f;						//레벨당 스피드
		_poketmon.levelHP = 2.89f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 85;			//체력	
		_poketmon.currentExp;
		_poketmon.maxExp;									//경험치량	

		//스킬

		_poketmon.skill[0] = 27;
		_poketmon.skill[1] = 17;
		_poketmon.skill[2] = 24;
		_poketmon.skill[3] = 25;


		//potketmonEXP();

		genderSettings();

		ability();

		break;
	}

	return S_OK;

}

void totodile::release()
{
}

void totodile::update()
{
}

void totodile::render()
{
}
