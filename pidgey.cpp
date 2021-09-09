#include "pch.h"
#include "pidgey.h"

//구구

pidgey::pidgey()
{
}

pidgey::~pidgey()
{
}

HRESULT pidgey::init()
{
    switch (RND->getFromIntTo(0, 3))
    {
    case 0:

        _poketmon.name = "구구";							    //이름 구구
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
        _poketmon.index = 16;								//전국도감번호 16
        _poketmon.level = RND->getFromIntTo(1, 50);			//처음 등장 레벨 1~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노말타입
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행타입
        _poketmon.evolutionLevel = 0;						//진화단계
        _poketmon.attack = 45;								//공격					
        _poketmon.defense = 40;								//방어
        _poketmon.specialAttack = 35;						//특수공격
        _poketmon.specialDefense = 35;						//특수방어
        _poketmon.speed = 56;								//스피드		

        _poketmon.iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
        _poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

        _poketmon.levelAttack = 1.62f;                      //레벨당 공격력
        _poketmon.levelDefense = 1.56f;                     //레벨당 방어력
        _poketmon.levelSpecialAttack = 1.5f;                //레벨당 특수공격력       
        _poketmon.levelSpecialDefense = 1.5f;               //레벨당 특수방어력       
        _poketmon.levelSpeed = 1.76f;                       //레벨당 스피드        
        _poketmon.levelHP = 2.44f;                          //레벨당 체력    

        _poketmon.maxHP = _poketmon.currentHP = 40;			//체력
        _poketmon.currentExp;
        _poketmon.maxExp = 1059860;							//100레벨 경험치량

        //스킬

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 0;
        _poketmon.skill[3] = 0;

        //potketmonEXP();

        genderSettings();

        ability();

        break;

    case 1:

        _poketmon.name = "피죤";							    //이름 피죤
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
        _poketmon.index = 17;								//전국도감번호 17
        _poketmon.level = RND->getFromIntTo(19, 50);		//처음 등장 레벨 19~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노멀타입
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행타입
        _poketmon.evolutionLevel = 1;						//진화단계
        _poketmon.attack = 60;								//공격					
        _poketmon.defense = 55;								//방어
        _poketmon.specialAttack = 50;						//특수공격
        _poketmon.specialDefense = 50;						//특수방어
        _poketmon.speed = 71;								//스피드		

        _poketmon.iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
        _poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

        _poketmon.levelAttack = 1.8f;                       //레벨당 공격력
        _poketmon.levelDefense = 1.74f;                     //레벨당 방어력
        _poketmon.levelSpecialAttack = 1.68f;               //레벨당 특수공격력
        _poketmon.levelSpecialDefense = 1.68f;              //레벨당 특수방어력
        _poketmon.levelSpeed = 1.94f;                       //레벨당 스피드
        _poketmon.levelHP = 2.67f;                          //레벨당 체력

        _poketmon.maxHP = _poketmon.currentHP = 63;			//체력
        _poketmon.currentExp;
        _poketmon.maxExp;									//경험치량

        //스킬

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 12;
        _poketmon.skill[3] = 0;

        //potketmonEXP();

        genderSettings();

        ability();

        break;

    case 2:

        _poketmon.name = "피죤투";							//이름 피죤투
        _poketmon.isGender = RND->getFromIntTo(0, 1);		//성별체크 랜덤
        _poketmon.index = 18;								//전국도감번호 18
        _poketmon.level = RND->getFromIntTo(36, 50);		//처음 등장 레벨 36~50
        _poketmon.type1 = static_cast<int>(TYPE::NOMAL);	//노멀타입
        _poketmon.type2 = static_cast<int>(TYPE::FLYING);	//비행타입
        _poketmon.evolutionLevel = 2;						//진화단계
        _poketmon.attack = 80;								//공격					
        _poketmon.defense = 75;								//방어
        _poketmon.specialAttack = 70;						//특수공격
        _poketmon.specialDefense = 70;						//특수방어
        _poketmon.speed = 101;								//스피드		

        _poketmon.iconNumX = 12;							//포켓몬 미니 아이콘 좌표x
        _poketmon.iconNumY = 0;								//포켓몬 미니 아이콘 좌표y

        _poketmon.levelAttack = 2.04f;                      //레벨당 공격력
        _poketmon.levelDefense = 1.98f;                     //레벨당 방어력
        _poketmon.levelSpecialAttack = 1.92f;               //레벨당 특수공격력
        _poketmon.levelSpecialDefense = 1.92f;              //레벨당 특수방어력
        _poketmon.levelSpeed = 2.3f;                        //레벨당 스피드
        _poketmon.levelHP = 2.87f;                          //레벨당 체력

        _poketmon.maxHP = _poketmon.currentHP = 83;			//체력
        _poketmon.currentExp;
        _poketmon.maxExp;									//경험치량

        //스킬

        _poketmon.skill[0] = 10;
        _poketmon.skill[1] = 11;
        _poketmon.skill[2] = 12;
        _poketmon.skill[3] = 13;


        //potketmonEXP();

        genderSettings();

        ability();

        break;
    }

    return S_OK;

}

void pidgey::release()
{
}

void pidgey::update()
{
}

void pidgey::render()
{
}
