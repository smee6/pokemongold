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
    
    _poketmon.maxExp = pow(_poketmon.level + 1, 3) - pow(_poketmon.level,3);
    
    //현재 경험치는 토탈 경험치에서 현제 레벨 3제곱한거를 뺴면 나옴

    _poketmon.currentExp = _poketmon.totalEXP - pow(_poketmon.level, 3);

}

void poketmon::render()
{
}


