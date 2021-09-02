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
	switch (RND->getFromIntTo(0,1))
	{
		case 0:

			_poketmon.name = "피카츄";							//이름 피카츄
			_poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
			_poketmon.index = 25;								//전국도감번호 25
			_poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
			_poketmon.type1 = static_cast<int>(TYPE::ELECTR);	//전기타입
			_poketmon.type2 = static_cast<int>(TYPE::NONE);		//
			_poketmon.evolutionLevel = 0;						//진화단계
			_poketmon.attack = 55;								//공격					
			_poketmon.defense = 40;								//방어
			_poketmon.specialAttack = 50;						//특수공격
			_poketmon.specialDefense = 50;						//특수방어
			_poketmon.speed = 90;								//스피드		

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 35;			//체력
			_poketmon.currentExp;
			_poketmon.maxExp = 1000000;							//100레벨 경험치량
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

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

			_poketmon.levelAttack = 1;
			_poketmon.levelDefense;
			_poketmon.levelSpecialAttack;
			_poketmon.levelSpecialDefense;
			_poketmon.levelSpeed;
			_poketmon.levelHP = 2;

			_poketmon.maxHP = _poketmon.currentHP = 60;			//체력
			_poketmon.currentExp;
			_poketmon.maxExp;									//100레벨 경험치량
			_poketmon.skill1;
			_poketmon.skill2;
			_poketmon.skill3;
			_poketmon.skill4;

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
