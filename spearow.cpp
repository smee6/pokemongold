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
	switch (RND->getFromIntTo(0, 2))
	{
	case 0:

		_poketmon.name = "깨비참";							//이름 깨비참
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 21;								//전국도감번호 21
		_poketmon.level = RND->getFromIntTo(1, 19);			//처음 등장 레벨 1~50

		potketmonEXP();										//경험치

		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노말 타입
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행 타입
		_poketmon.evolutionLevel = 0;						//진화단계
		_poketmon.attack = 60;								//공격					
		_poketmon.defense = 30;								//방어
		_poketmon.specialAttack = 31;						//특수공격
		_poketmon.specialDefense = 31;						//특수방어
		_poketmon.speed = 70;								//스피드		

		_poketmon.iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 1.8f;						//레벨당 공격력
		_poketmon.levelDefense = 1.44f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.46f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.46f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 1.92f;						//레벨당 스피드
		_poketmon.levelHP = 2.44f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 40;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//100레벨 경험치량

		//스킬

		_poketmon.skill[0] = 15;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 0;
		_poketmon.skill[3] = 0;

		//potketmonEXP();

		genderSettings();

		ability();

		break;

	case 1:

		_poketmon.name = "깨비드릴조";						//이름 깨비드릴조
		_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
		_poketmon.index = 22;								//전국도감번호 22
		_poketmon.level = RND->getFromIntTo(20, 50);		//처음 등장 레벨 20~50

		potketmonEXP();										//경험치

		_poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노멀 타입
		_poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행 타입
		_poketmon.evolutionLevel = 1;						//진화단계
		_poketmon.attack = 90;								//공격					
		_poketmon.defense = 65;								//방어
		_poketmon.specialAttack = 61;						//특수공격
		_poketmon.specialDefense = 61;						//특수방어
		_poketmon.speed = 100;								//스피드		

		_poketmon.iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
		_poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

		_poketmon.levelAttack = 2.16f;						//레벨당 공격력
		_poketmon.levelDefense = 1.86f;						//레벨당 방어력
		_poketmon.levelSpecialAttack = 1.82f;				//레벨당 특수공격력
		_poketmon.levelSpecialDefense = 1.82f;				//레벨당 특수방어력
		_poketmon.levelSpeed = 2.28f;						//레벨당 스피드
		_poketmon.levelHP = 2.69f;							//레벨당 체력

		_poketmon.maxHP = _poketmon.currentHP = 65;			//체력
		_poketmon.currentExp;
		_poketmon.maxExp;									//

		//스킬

		_poketmon.skill[0] = 15;
		_poketmon.skill[1] = 16;
		_poketmon.skill[2] = 17;
		_poketmon.skill[3] = 0;


		//potketmonEXP();

		genderSettings();

		ability();

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
