#include "pch.h"
#include "chikorita.h"

//치코리타

chikorita::chikorita()
{
}

chikorita::~chikorita()
{
}

HRESULT chikorita::init()
{   
    switch (RND->getFromIntTo(0,2))
    {
     case 0:                                               

         _poketmon.name = "치코리타";						//이름 치코리타
         _poketmon.isGender = RND->getFromIntTo(0, 1);	    //성별체크 랜덤
         _poketmon.index = 152;							    //전국도감번호 152
         _poketmon.level = RND->getFromIntTo(1, 50);		//처음 등장 레벨 1~50
         _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //풀타입
         _poketmon.type2 = static_cast<int>(TYPE::NONE);    //
         _poketmon.evolutionLevel = 0;					    //진화단계
         _poketmon.attack = 49;							    //공격					
         _poketmon.defense = 65;						    //방어
         _poketmon.specialAttack = 49;                      //특수공격
         _poketmon.specialDefense = 65;                     //특수방어
         _poketmon.speed = 45;							    //스피드		

         _poketmon.levelAttack;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP;

         _poketmon.maxHP = _poketmon.currentHP = 45;		//체력
         _poketmon.currentExp;
         _poketmon.maxExp = 1059860;						//100레벨 경험치량
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;

         break;
    
     case 1:                                                

         _poketmon.name = "베이리프";						//이름 베어리프
         _poketmon.isGender = RND->getFromIntTo(0, 1);	    //성별체크 랜덤
         _poketmon.index = 153;							    //전국도감번호 153
         _poketmon.level = RND->getFromIntTo(16, 50);	    //처음 등장 레벨 16~50
         _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //풀타입
         _poketmon.type2 = static_cast<int>(TYPE::NONE);	//
         _poketmon.evolutionLevel = 1;					    //진화단계
         _poketmon.attack = 62;							    //공격					
         _poketmon.defense = 80;							//방어
         _poketmon.specialAttack = 63;                      //특수공격
         _poketmon.specialDefense = 80;                     //특수방어
         _poketmon.speed = 60;							    //스피드		

         _poketmon.levelAttack;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP;

         _poketmon.maxHP = _poketmon.currentHP = 60;		//체력
         _poketmon.currentExp;
         _poketmon.maxExp;						            //경험치량
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;

         break;

     case 2:                                                
         
         _poketmon.name = "메가니움";						//이름 메가니움
         _poketmon.isGender = RND->getFromIntTo(0, 1);	    //성별체크 랜덤
         _poketmon.index = 154;							    //전국도감번호 154
         _poketmon.level = RND->getFromIntTo(33, 70);	    //처음 등장 레벨 33~70
         _poketmon.type1 = static_cast<int>(TYPE::GRASS);   //풀타입
         _poketmon.type2 = static_cast<int>(TYPE::NONE);	//
         _poketmon.evolutionLevel = 0;					    //진화단계
         _poketmon.attack = 82;							    //공격					
         _poketmon.defense = 100;						    //방어
         _poketmon.specialAttack = 83;                      //특수공격
         _poketmon.specialDefense = 100;                    //특수방어
         _poketmon.speed = 80;							    //스피드		

         _poketmon.levelAttack = 1;
         _poketmon.levelDefense;
         _poketmon.levelSpecialAttack;
         _poketmon.levelSpecialDefense;
         _poketmon.levelSpeed;
         _poketmon.levelHP = 2;

         _poketmon.maxHP = _poketmon.currentHP = 80;		//체력
         _poketmon.currentExp;
         _poketmon.maxExp;						            //경험치량
         _poketmon.skill1;
         _poketmon.skill2;
         _poketmon.skill3;
         _poketmon.skill4;
                  
         break;
     }
   


    return S_OK;
}

void chikorita::release()
{
}

void chikorita::update()
{
    _poketmon.sumMaxHP = _poketmon.maxHP + (_poketmon.levelHP * _poketmon.level);
    _poketmon.sumAttack = _poketmon.attack + (_poketmon.levelAttack * _poketmon.level);



}

void chikorita::render()
{
}
