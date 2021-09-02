#include "pch.h"
#include "poketmon.h"

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

void poketmon::render()
{
}


