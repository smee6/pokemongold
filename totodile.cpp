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
	switch (RND->getFromIntTo(0,2))
	{
		case 0:

			_poketmon.name = "리아코";							//이름 리아코
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤	
			_poketmon.index = 158;								//전국도감번호 158
			_poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
			_poketmon.type1 = static_cast<int>(TYPE::WATER);	//물타입
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
			_poketmon.evolutionLevel = 0;						//진화단계	
			_poketmon.attack = 65;								//공격					
			_poketmon.defense = 64;								//방어	
			_poketmon.specialAttack = 44;						//특수공격	
			_poketmon.specialDefense = 48;						//특수방어	
			_poketmon.speed = 43;								//스피드			

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 50;			//체력	
			_poketmon.currentExp;
			_poketmon.maxExp = 1059860;							//100레벨 경험치량	
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

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

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 65;			//체력	
			_poketmon.currentExp;
			_poketmon.maxExp;									//경험치량	
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

			break;

		case 2:

			_poketmon.name = "장크로다일";						//이름 장크로다일
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤	
			_poketmon.index = 160;								//전국도감번호 160
			_poketmon.level = RND->getFromIntTo(30, 50);		//처음 등장 레벨 30~50
			_poketmon.type1 = static_cast<int>(TYPE::WATER);	//물타입	
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//	
			_poketmon.evolutionLevel = 0;						//진화단계	
			_poketmon.attack = 105;								//공격					
			_poketmon.defense = 100;							//방어	
			_poketmon.specialAttack = 79;						//특수공격	
			_poketmon.specialDefense = 83;						//특수방어	
			_poketmon.speed = 78;								//스피드			

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 85;			//체력	
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

void totodile::release()
{
}

void totodile::update()
{
}

void totodile::render()
{
}
