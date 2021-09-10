#include "pch.h"
#include "poketmon.h"

#include <math.h>

poketmon::poketmon()
{
}

poketmon::~poketmon()
{
}

HRESULT poketmon::init()
{


    return S_OK;
}

void poketmon::release()
{
}

void poketmon::update()
{

}

void poketmon::attackAI()
{

}

void poketmon::genderSettings()
{
    if (_poketmon.isGender)         // 포켓몬 성별체크가 트루일시
    {
        _poketmon.gender = "수컷";  // 포켓몬의 성별은 수컷이 된다
    }
    else _poketmon.gender = "암컷"; // 그 외의 포켓몬의 성별은 암컷이 된다.


}

void poketmon::potketmonEXP()
{

    //포켓몬 레벨은 현제 경험치에서 3제곱근 하고 그걸 int로 변경해야함
    //cbrt 삼제곱근 

    _poketmon.level = static_cast<int>(cbrt(_poketmon.totalEXP));

    //맥스 경험치는  레벨의 3제곱임

    _poketmon.maxExp = pow(_poketmon.level + 1, 3) - pow(_poketmon.level, 3);

    //현재 경험치는 토탈 경험치에서 현제 레벨 3제곱한거를 뺴면 나옴

    _poketmon.currentExp = _poketmon.totalEXP - pow(_poketmon.level, 3);

}

void poketmon::ability()
{
    //현재 능력치는     =     1레벨 능력치  +        레벨당 능력치  * 레벨 이다.
    _poketmon.sumAttack = _poketmon.attack + (_poketmon.levelAttack * _poketmon.level);                               //공격력       
    _poketmon.sumDefense = _poketmon.defense + (_poketmon.levelDefense * _poketmon.level);                            //방어력
    _poketmon.sumMaxHP = _poketmon.maxHP + (_poketmon.levelHP * _poketmon.level);                                     //hp
    _poketmon.sumSpecialAttack = _poketmon.specialAttack + (_poketmon.levelSpecialAttack * _poketmon.level);          //특수공격력
    _poketmon.sumSpecialDefense = _poketmon.specialDefense + (_poketmon.levelSpecialDefense * _poketmon.level);       //특수방어력
    _poketmon.sumSpeed = _poketmon.speed + (_poketmon.levelSpeed * _poketmon.level);                                  //스피드

    _poketmon.currentHP = _poketmon.sumMaxHP;                                                                         //현재체력 포켓몬볼로 잡으면 저장

}

void poketmon::render()
{

}


