#include "pch.h"
#include "spearow.h"

//깨비참

spearow::spearow()
{
}

spearow::~spearow()
{
}

HRESULT spearow::init()
{
	switch (RND->getFromIntTo(0, 1))
	{
	case 0:

		_poketmon.name = "깨비참";							//이름 깨비참
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 21;								//전국도감번호 21
		_poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노말 타입
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행 타입
		_poketmon.evolutionLevel = 0;						//진화단계
		_poketmon.attack = 60;								//공격					
		_poketmon.defense = 30;								//방어
		_poketmon.specialAttack = 31;						//특수공격
		_poketmon.specialDefense = 31;						//특수방어
		_poketmon.speed = 70;								//스피드		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 40;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp = 1000000;							//100레벨 경험치량
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;

	case 1:

		_poketmon.name = "깨비드릴조";						//이름 깨비드릴조
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 22;								//전국도감번호 22
		_poketmon.level = RND->getFromIntTo(20, 50);		//처음 등장 레벨 20~50
		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노멀 타입
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행 타입
		_poketmon.evolutionLevel = 1;						//진화단계
		_poketmon.attack = 90;								//공격					
		_poketmon.defense = 65;								//방어
		_poketmon.specialAttack = 61;						//특수공격
		_poketmon.specialDefense = 61;						//특수방어
		_poketmon.speed = 100;								//스피드		

		_poketmon.levelAttack = 1;
		_poketmon.levelDefense;
		_poketmon.levelSpecialAttack;
		_poketmon.levelSpecialDefense;
		_poketmon.levelSpeed;
		_poketmon.levelHP = 2;

		_poketmon.maxHP = _poketmon.currentHP = 65;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//
		_poketmon.skill1;
		_poketmon.skill2;
		_poketmon.skill3;
		_poketmon.skill4;

		break;
	}


	return S_OK;

  
}

void spearow::release()
{
}

void spearow::update()
{
}

void spearow::render()
{
}
