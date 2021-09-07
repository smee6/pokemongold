#include "pch.h"
#include "rattata.h"

//꼬렛

rattata::rattata()
{
}

rattata::~rattata()
{
}

HRESULT rattata::init()
{
    switch (RND->getFromIntTo(0, 1))
    {
    case 0:

        _poketmon.name = "꼬렛";							    //이름 꼬렛
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
        _poketmon.index = 19;								//전국도감번호 19
        _poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노말 타입
        _poketmon.type2 = static_cast<int>(TYPE::NONE);		//
        _poketmon.evolutionLevel = 0;						//진화단계
        _poketmon.attack = 56;								//공격					
        _poketmon.defense = 35;								//방어
        _poketmon.specialAttack = 25;						//특수공격
        _poketmon.specialDefense = 35;						//특수방어
        _poketmon.speed = 72;								//스피드		

        _poketmon.iconNumX = 28;							//포켓몬 미니 아이콘 좌표x
        _poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

        _poketmon.levelAttack = 1.76f;                      //레벨당 공격력
        _poketmon.levelDefense = 1.5f;                      //레벨당 방어력
        _poketmon.levelSpecialAttack = 1.38f;               //레벨당 특수공격력
        _poketmon.levelSpecialDefense = 1.5f;               //레벨당 특수방어력
        _poketmon.levelSpeed = 1.95f;                       //레벨당 스피드
        _poketmon.levelHP = 2.34f;                          //레벨당 체력

        _poketmon.maxHP = _poketmon.currentHP = 30;			//체력
        _poketmon.currentExp;
        _poketmon.maxExp = 1000000;							//100레벨 경험치량
        _poketmon.skill1;
        _poketmon.skill2;
        _poketmon.skill3;
        _poketmon.skill4;

        break;

    case 1:

        _poketmon.name = "레트라";							//이름 레트라
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
        _poketmon.index = 20;								//전국도감번호 20
        _poketmon.level = RND->getFromIntTo(20, 50);		//처음 등장 레벨 20~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노멀타입
        _poketmon.type2 = static_cast<int>(TYPE::NONE);		//
        _poketmon.evolutionLevel = 1;						//진화단계
        _poketmon.attack = 81;								//공격					
        _poketmon.defense = 60;								//방어
        _poketmon.specialAttack = 50;						//특수공격
        _poketmon.specialDefense = 70;						//특수방어
        _poketmon.speed = 97;								//스피드		

        _poketmon.iconNumX = 28;							//포켓몬 미니 아이콘 좌표x
        _poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

        _poketmon.levelAttack = 2.06f;                      //레벨당 공격력 
        _poketmon.levelDefense  = 1.8f;                     //레벨당 방어력
        _poketmon.levelSpecialAttack = 1.68f;               //레벨당 특수공격력
        _poketmon.levelSpecialDefense = 1.92f;              //레벨당 특수방어력
        _poketmon.levelSpeed = 2.25f;                       //레벨당 스피드
        _poketmon.levelHP = 2.59f;                          //레벨당 체력

        _poketmon.maxHP = _poketmon.currentHP = 55;			//체력
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

void rattata::release()
{
}

void rattata::update()
{
}

void rattata::render()
{
}
