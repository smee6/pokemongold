#include "pch.h"
#include "poketmonManager.h"
#include "character.h"


poketmonManager::poketmonManager()
{
}

poketmonManager::~poketmonManager()
{
}

HRESULT poketmonManager::init()
{
    _skill = new skill;					//스킬 
    _skill->init();
    _skill->setPoketmonmanagerMemoryAddressLink(this);


    _skill->setCharacterMemoryAddressLink(_character);


    poketmonImage();

    poketmonSpawn();

    startPoketmonSetting();         //스타트 포켓몬
    wildPoketmonSetting();          //야생포켓몬

    championPoketmonSetting();
    trainer1Poketmon();
    trainer2Poketmon();

    

    return S_OK;
}

void poketmonManager::release()
{

}

void poketmonManager::update()
{
    if (KEYMANAGER->isOnceKeyDown('G'))
    {
        _wildPoketmon.currentHP -= 5;       //체력깍는거 확인
    }

   
    _skill->update();
}

void poketmonManager::poketmonSpawn()
{
   
    // 포켓몬을 벡터로 담아주고 불러올때는 셋팅으로 한번 불러오는게 어떨까 라는 느낌이 들어서 만들고 있음
    // 1번 벡터에 담는다.  2번 벡터를 랜덤으로 돌린다. 3번 벡터에 있는걸 몬스터에 담는다. 4번 몬스터를 겟터로 넘긴다.
    // 5번 넘긴 포켓몬의 겟터를 저장한다.
    // 1레벨 능력치 랜덤값으로 받아오는거 확인  

    //치코리타                                              

    chikorita* monster0;
    monster0 = new chikorita;
    monster0->init();
    _vPoketmon.push_back(monster0);

    //브케인
    poketmon* monster1;
    monster1 = new cyndaquil;
    monster1->init();
    _vPoketmon.push_back(monster1);

    //리아코
    poketmon* monster2;
    monster2 = new totodile;
    monster2->init();
    _vPoketmon.push_back(monster2);

    //피카츄
    poketmon* monster3;
    monster3 = new pikachu;
    monster3->init();
    _vPoketmon.push_back(monster3);

    //구구
    poketmon* monster4;
    monster4 = new pidgey;
    monster4->init();
    _vPoketmon.push_back(monster4);

    //뿔충이
    poketmon* monster5;
    monster5 = new weedle;
    monster5->init();
    _vPoketmon.push_back(monster5);

    //캐터피
    poketmon* monster6;
    monster6 = new caterpie;
    monster6->init();
    _vPoketmon.push_back(monster6);

    //깨비참
    poketmon* monster7;
    monster7 = new spearow;
    monster7->init();
    _vPoketmon.push_back(monster7);

    //레트라
    poketmon* monster8;
    monster8 = new rattata;
    monster8->init();
    _vPoketmon.push_back(monster8);
}

void poketmonManager::wildPoketmonSetting()     //야생포켓몬 셋팅
{

    _randomPoketmon = RND->getFromIntTo(0, 9);                           //랜덤 야생포켓몬 변수

    //_randomPoketmon = 0;

    _wildPoketmon.name = _vPoketmon[_randomPoketmon]->getTagPoketmon().name;                                        // 포켓몬 이름
    _wildPoketmon.gender = _vPoketmon[_randomPoketmon]->getTagPoketmon().gender;                                    // 포켓몬 성별
    _wildPoketmon.isGender = _vPoketmon[_randomPoketmon]->getTagPoketmon().isGender;                                // 포켓몬 성별확인
    _wildPoketmon.index = _vPoketmon[_randomPoketmon]->getTagPoketmon().index;                                      // 포켓몬 번호
    _wildPoketmon.level = _vPoketmon[_randomPoketmon]->getTagPoketmon().level;                                      // 포켓몬 레벨
    _wildPoketmon.evolutionLevel = _vPoketmon[_randomPoketmon]->getTagPoketmon().evolutionLevel;                    // 포켓몬 진화단계

    _wildPoketmon.iconNumX = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumX;                                //미니 포켓몬 이미지 아이콘 좌표 X
    _wildPoketmon.iconNumY = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumY;                                //미니 포켓몬 이미지 아이콘 좌표 Y

    _wildPoketmon.type1 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type1;                                      //타입1
    _wildPoketmon.type2 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type2;                                      //타입2

    _wildPoketmon.attack = _vPoketmon[_randomPoketmon]->getTagPoketmon().attack;                                    //1레벨 공격력
    _wildPoketmon.defense = _vPoketmon[_randomPoketmon]->getTagPoketmon().defense;                                  //1레벨 방어력
    _wildPoketmon.specialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialAttack;                      //1레벨 특수공격력   
    _wildPoketmon.specialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialDefense;                    //1레벨 특수방어력
    _wildPoketmon.speed = _vPoketmon[_randomPoketmon]->getTagPoketmon().speed;                                      //1레벨 스피드

    _wildPoketmon.currentHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentHP;                              //현재체력
    _wildPoketmon.maxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxHP;                                      //1레벨 최대체력;

    _wildPoketmon.levelAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelAttack;                         //레벨당 공격력
    _wildPoketmon.levelDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelDefense;                       //레벨당 방어력
    _wildPoketmon.levelSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialAttack;           //레벨당 특수공격력
    _wildPoketmon.levelSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialDefense;         //레벨당 특수방어력
    _wildPoketmon.levelSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpeed;                           //레벨당 스피드
    _wildPoketmon.levelHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelHP;                                 //레벨당 HP

    _wildPoketmon.sumAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumAttack;                             //현재 공결력
    _wildPoketmon.sumDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumDefense;                           //현재 방어력
    _wildPoketmon.sumSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialAttack;               //현재 특수공격력
    _wildPoketmon.sumSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialDefense;             //현재 특수방어력
    _wildPoketmon.sumSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpeed;                               //현재 스피드
    _wildPoketmon.sumMaxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumMaxHP;                               //현재 최대HP

    _wildPoketmon.currentExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentExp;                           //현재 경험치
    _wildPoketmon.maxExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxExp;                                   //레벨계산용
    _wildPoketmon.totalEXP = _vPoketmon[_randomPoketmon]->getTagPoketmon().totalEXP;                               //현재 레벨의 최대 경험치

    _wildPoketmon.skill[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[0];                               //스킬1
    _wildPoketmon.skill[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[1];                               //스킬2
    _wildPoketmon.skill[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[2];                               //스킬3
    _wildPoketmon.skill[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[3];                               //스킬4

    _wildPoketmon.skillPP[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[0];                           //스킬1PP
    _wildPoketmon.skillPP[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[1];                           //스킬2PP
    _wildPoketmon.skillPP[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[2];                           //스킬3PP
    _wildPoketmon.skillPP[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[3];                           //스킬4PP

    _wildPoketmon.item = _vPoketmon[_randomPoketmon]->getTagPoketmon().item;                                       //아이템..

   
}

void poketmonManager::startPoketmonSetting()            // 스타팅 포켓몬 데이터
{
    _startPoketmon[0].name = "브케인";

    _startPoketmon[0].isGender = RND->getFromIntTo(0, 2);
    _startPoketmon[0].index = 155;
    _startPoketmon[0].level = 5;
    _startPoketmon[0].evolutionLevel = 0;

    if (_startPoketmon[0].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _startPoketmon[0].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _startPoketmon[0].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _startPoketmon[0].totalEXP = pow(_startPoketmon[0].level, 3);
    _startPoketmon[0].maxExp = pow(_startPoketmon[0].level + 1, 3) - _startPoketmon[0].totalEXP;
    _startPoketmon[0].currentExp = _startPoketmon[0].totalEXP - pow(_startPoketmon[0].level, 3);

    _startPoketmon[0].iconNumX = 30;
    _startPoketmon[0].iconNumY = 0;

    _startPoketmon[0].type1 = static_cast<int>(TYPE::FIRE);
    _startPoketmon[0].type2 = static_cast<int>(TYPE::NONE);

    _startPoketmon[0].attack = 52;
    _startPoketmon[0].defense = 43;
    _startPoketmon[0].specialAttack = 60;
    _startPoketmon[0].specialDefense = 50;
    _startPoketmon[0].speed = 65;

    _startPoketmon[0].maxHP = _startPoketmon[0].currentHP = 45;

    _startPoketmon[0].levelAttack = 1.71f;
    _startPoketmon[0].levelDefense = 1.6f;
    _startPoketmon[0].levelSpecialAttack = 1.8f;
    _startPoketmon[0].levelSpecialDefense = 1.68f;
    _startPoketmon[0].levelSpeed = 1.86f;
    _startPoketmon[0].levelHP = 2.43f;

    _startPoketmon[0].skill[0] = 1;
    _startPoketmon[0].skill[1] = 17;
    _startPoketmon[0].skill[2] = 12;
    _startPoketmon[0].skill[3] = 23;

    _startPoketmon[0].sumAttack = static_cast<int>(_startPoketmon[0].attack + (_startPoketmon[0].levelAttack * _startPoketmon[0].level));
    _startPoketmon[0].sumDefense = _startPoketmon[0].defense + (_startPoketmon[0].levelDefense * _startPoketmon[0].level);
    _startPoketmon[0].sumSpecialAttack = _startPoketmon[0].specialAttack + (_startPoketmon[0].levelSpecialAttack * _startPoketmon[0].level);
    _startPoketmon[0].sumSpecialDefense = _startPoketmon[0].specialDefense + (_startPoketmon[0].levelSpecialDefense * _startPoketmon[0].level);
    _startPoketmon[0].sumSpeed = _startPoketmon[0].speed + (_startPoketmon[0].levelSpeed * _startPoketmon[0].level);
    _startPoketmon[0].sumMaxHP = _startPoketmon[0].maxHP + (_startPoketmon[0].levelHP * _startPoketmon[0].level);

    _startPoketmon[0].currentHP = _startPoketmon[0].sumMaxHP;
       
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    _startPoketmon[1].name = "리아코";

    _startPoketmon[1].isGender = RND->getFromIntTo(0, 2);
    _startPoketmon[1].index = 158;
    _startPoketmon[1].level = 5;
    _startPoketmon[1].evolutionLevel = 0;

    if (_startPoketmon[1].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _startPoketmon[1].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _startPoketmon[1].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _startPoketmon[1].totalEXP = pow(_startPoketmon[1].level, 3);
    _startPoketmon[1].maxExp = pow(_startPoketmon[1].level + 1, 3) - _startPoketmon[1].totalEXP;
    _startPoketmon[1].currentExp = _startPoketmon[1].totalEXP - pow(_startPoketmon[1].level, 3);

    _startPoketmon[1].iconNumX = 14;
    _startPoketmon[1].iconNumY = 0;
                   
    _startPoketmon[1].type1 = static_cast<int>(TYPE::WATER);
    _startPoketmon[1].type2 = static_cast<int>(TYPE::NONE);
                   
    _startPoketmon[1].attack = 65;
    _startPoketmon[1].defense = 64;
    _startPoketmon[1].specialAttack = 44;
    _startPoketmon[1].specialDefense = 48;
    _startPoketmon[1].speed = 43;
                   
    _startPoketmon[1].maxHP = _startPoketmon[1].currentHP = 50;
                   
    _startPoketmon[1].levelAttack = 1.86f;
    _startPoketmon[1].levelDefense = 1.85f;
    _startPoketmon[1].levelSpecialAttack = 1.61f;
    _startPoketmon[1].levelSpecialDefense = 1.66f;
    _startPoketmon[1].levelSpeed = 1.6f;
    _startPoketmon[1].levelHP = 2.54f;

    _startPoketmon[1].skill[0] = 27;
    _startPoketmon[1].skill[1] = 17;
    _startPoketmon[1].skill[2] = 25;
    _startPoketmon[1].skill[3] = 30;
                   
    _startPoketmon[1].sumAttack = static_cast<int>(_startPoketmon[1].attack + (_startPoketmon[1].levelAttack * _startPoketmon[1].level));
    _startPoketmon[1].sumDefense = _startPoketmon[1].defense + (_startPoketmon[1].levelDefense * _startPoketmon[1].level);
    _startPoketmon[1].sumSpecialAttack = _startPoketmon[1].specialAttack + (_startPoketmon[1].levelSpecialAttack * _startPoketmon[1].level);
    _startPoketmon[1].sumSpecialDefense = _startPoketmon[1].specialDefense + (_startPoketmon[1].levelSpecialDefense * _startPoketmon[1].level);
    _startPoketmon[1].sumSpeed = _startPoketmon[1].speed + (_startPoketmon[1].levelSpeed * _startPoketmon[1].level);
    _startPoketmon[1].sumMaxHP = _startPoketmon[1].maxHP + (_startPoketmon[1].levelHP * _startPoketmon[1].level);
                   
    _startPoketmon[1].currentHP = _startPoketmon[1].sumMaxHP;
                   
    
                   
    
  
    //----------------------------------------------------------------------------------------------------------------------------------
    _startPoketmon[2].name = "치코리타";
                   
    _startPoketmon[2].isGender = RND->getFromIntTo(0, 2);
    _startPoketmon[2].index = 152;
    _startPoketmon[2].level = 5;
    _startPoketmon[2].evolutionLevel = 0;

    if (_startPoketmon[2].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _startPoketmon[2].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _startPoketmon[2].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _startPoketmon[2].totalEXP = pow(_startPoketmon[2].level, 3);
    _startPoketmon[2].maxExp = pow(_startPoketmon[2].level + 1, 3) - _startPoketmon[2].totalEXP;
    _startPoketmon[2].currentExp = _startPoketmon[2].totalEXP - pow(_startPoketmon[2].level, 3);
                   
    _startPoketmon[2].iconNumX = 30;
    _startPoketmon[2].iconNumY = 0;
                   
    _startPoketmon[2].type1 = static_cast<int>(TYPE::GRASS);
    _startPoketmon[2].type2 = static_cast<int>(TYPE::NONE);
                   
    _startPoketmon[2].attack = 49;
    _startPoketmon[2].defense = 65;
    _startPoketmon[2].specialAttack = 49;
    _startPoketmon[2].specialDefense = 65;
    _startPoketmon[2].speed = 45;
                   
    _startPoketmon[2].maxHP = _startPoketmon[2].currentHP = 45;              
                
    _startPoketmon[2].levelAttack = 1.67f;
    _startPoketmon[2].levelDefense = 1.86f;
    _startPoketmon[2].levelSpecialAttack = 1.67f;
    _startPoketmon[2].levelSpecialDefense = 1.86f;
    _startPoketmon[2].levelSpeed = 1.62f;
    _startPoketmon[2].levelHP = 2.49f;
                                   
    _startPoketmon[2].skill[0] = 1;
    _startPoketmon[2].skill[1] = 16;
    _startPoketmon[2].skill[2] = 20;
    _startPoketmon[2].skill[3] = 29;
    
    _startPoketmon[2].sumAttack = static_cast<int>(_startPoketmon[2].attack + (_startPoketmon[2].levelAttack * _startPoketmon[2].level));
    _startPoketmon[2].sumDefense = _startPoketmon[2].defense + (_startPoketmon[2].levelDefense * _startPoketmon[2].level);
    _startPoketmon[2].sumSpecialAttack = _startPoketmon[2].specialAttack + (_startPoketmon[2].levelSpecialAttack * _startPoketmon[2].level);
    _startPoketmon[2].sumSpecialDefense = _startPoketmon[2].specialDefense + (_startPoketmon[2].levelSpecialDefense * _startPoketmon[2].level);
    _startPoketmon[2].sumSpeed = _startPoketmon[2].speed + (_startPoketmon[2].levelSpeed * _startPoketmon[2].level);
    _startPoketmon[2].sumMaxHP = _startPoketmon[2].maxHP + (_startPoketmon[2].levelHP * _startPoketmon[2].level);
                   
    _startPoketmon[2].currentHP = _startPoketmon[2].sumMaxHP;

}

void poketmonManager::championPoketmonSetting() //비상 체육관 챔피온
{
    _championPoketmon[0].name = "피죤";
   
    _championPoketmon[0].isGender = RND->getFromIntTo(0, 2);
    _championPoketmon[0].index = 17;
    _championPoketmon[0].level = 12;
    _championPoketmon[0].evolutionLevel = 1;

    if (_championPoketmon[0].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _championPoketmon[0].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _championPoketmon[0].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _championPoketmon[0].totalEXP = pow(_championPoketmon[0].level, 3);
    _championPoketmon[0].maxExp = pow(_championPoketmon[0].level + 1, 3) - _championPoketmon[0].totalEXP;
    _championPoketmon[0].currentExp = _championPoketmon[0].totalEXP - pow(_championPoketmon[0].level, 3);
    
    _championPoketmon[0].iconNumX = 12;
    _championPoketmon[0].iconNumY = 0;
   
    _championPoketmon[0].type1 = static_cast<int>(TYPE::NOMAL);
    _championPoketmon[0].type2 = static_cast<int>(TYPE::FLYING);
   
    _championPoketmon[0].attack = 60;
    _championPoketmon[0].defense = 55;
    _championPoketmon[0].specialAttack = 50;
    _championPoketmon[0].specialDefense = 50;
    _championPoketmon[0].speed = 71;
    
    _championPoketmon[0].maxHP = _championPoketmon[0].currentHP = 63;
  
    _championPoketmon[0].levelAttack = 1.8f;
    _championPoketmon[0].levelDefense = 1.74f;
    _championPoketmon[0].levelSpecialAttack = 1.68f;
    _championPoketmon[0].levelSpecialDefense = 1.68f;
    _championPoketmon[0].levelSpeed = 1.94f;
    _championPoketmon[0].levelHP = 2.67f;
  
    _championPoketmon[0].skill[0] = 10;
    _championPoketmon[0].skill[1] = 11;
    _championPoketmon[0].skill[2] = 12;
    _championPoketmon[0].skill[3] = 0;
  
    _championPoketmon[0].sumAttack = static_cast<int>(_championPoketmon[0].attack + (_championPoketmon[0].levelAttack * _championPoketmon[0].level));
    _championPoketmon[0].sumDefense = _championPoketmon[0].defense + (_championPoketmon[0].levelDefense * _championPoketmon[0].level);
    _championPoketmon[0].sumSpecialAttack = _championPoketmon[0].specialAttack + (_championPoketmon[0].levelSpecialAttack * _championPoketmon[0].level);
    _championPoketmon[0].sumSpecialDefense = _championPoketmon[0].specialDefense + (_championPoketmon[0].levelSpecialDefense * _championPoketmon[0].level);
    _championPoketmon[0].sumSpeed = _championPoketmon[0].speed + (_championPoketmon[0].levelSpeed * _championPoketmon[0].level);
    _championPoketmon[0].sumMaxHP = _championPoketmon[0].maxHP + (_championPoketmon[0].levelHP * _championPoketmon[0].level);

    _championPoketmon[0].currentHP = _championPoketmon[0].sumMaxHP;

    //-------------------------------------------------------------------------------------------------------------

    _championPoketmon[1].name = "깨비드릴조";

    _championPoketmon[1].isGender = RND->getFromIntTo(0, 2);
    _championPoketmon[1].index = 22;
    _championPoketmon[1].level = 14;
    _championPoketmon[1].evolutionLevel = 1;

    if (_championPoketmon[1].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _championPoketmon[1].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _championPoketmon[1].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _championPoketmon[1].totalEXP = pow(_championPoketmon[1].level, 3);
    _championPoketmon[1].maxExp = pow(_championPoketmon[1].level + 1, 3) - _championPoketmon[1].totalEXP;
    _championPoketmon[1].currentExp = _championPoketmon[1].totalEXP - pow(_championPoketmon[1].level, 3);

    _championPoketmon[1].iconNumX = 12;
    _championPoketmon[1].iconNumY = 0;

    _championPoketmon[1].type1 = static_cast<int>(TYPE::NOMAL);
    _championPoketmon[1].type2 = static_cast<int>(TYPE::FLYING);

    _championPoketmon[1].attack = 90;
    _championPoketmon[1].defense = 65;
    _championPoketmon[1].specialAttack = 61;
    _championPoketmon[1].specialDefense = 61;
    _championPoketmon[1].speed = 100;

    _championPoketmon[1].maxHP = _championPoketmon[1].currentHP = 65;

    _championPoketmon[1].levelAttack = 2.16f;
    _championPoketmon[1].levelDefense = 1.86f;
    _championPoketmon[1].levelSpecialAttack = 1.82f;
    _championPoketmon[1].levelSpecialDefense = 1.82f;
    _championPoketmon[1].levelSpeed = 2.28f;
    _championPoketmon[1].levelHP = 2.69f;

    _championPoketmon[1].skill[0] = 15;
    _championPoketmon[1].skill[1] = 16;
    _championPoketmon[1].skill[2] = 17;
    _championPoketmon[1].skill[3] = 0;

    _championPoketmon[1].sumAttack = static_cast<int>(_championPoketmon[1].attack + (_championPoketmon[1].levelAttack * _championPoketmon[1].level));
    _championPoketmon[1].sumDefense = _championPoketmon[1].defense + (_championPoketmon[1].levelDefense * _championPoketmon[1].level);
    _championPoketmon[1].sumSpecialAttack = _championPoketmon[1].specialAttack + (_championPoketmon[1].levelSpecialAttack * _championPoketmon[1].level);
    _championPoketmon[1].sumSpecialDefense = _championPoketmon[1].specialDefense + (_championPoketmon[1].levelSpecialDefense * _championPoketmon[1].level);
    _championPoketmon[1].sumSpeed = _championPoketmon[1].speed + (_championPoketmon[1].levelSpeed * _championPoketmon[1].level);
    _championPoketmon[1].sumMaxHP = _championPoketmon[1].maxHP + (_championPoketmon[1].levelHP * _championPoketmon[1].level);

    _championPoketmon[1].currentHP = _championPoketmon[1].sumMaxHP;
    
    //---------------------------------------------------------------------------------------------------------------------------------------------

    _championPoketmon[2].name = "피죤투";
                      
    _championPoketmon[2].isGender = RND->getFromIntTo(0, 2);
    _championPoketmon[2].index = 18;
    _championPoketmon[2].level = 16;
    _championPoketmon[2].evolutionLevel = 2;
    
    if (_championPoketmon[2].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _championPoketmon[2].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _championPoketmon[2].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.

    _championPoketmon[2].totalEXP = pow(_championPoketmon[2].level, 3);
    _championPoketmon[2].maxExp = pow(_championPoketmon[2].level + 1, 3) - _championPoketmon[2].totalEXP;
    _championPoketmon[2].currentExp = _championPoketmon[2].totalEXP - pow(_championPoketmon[2].level, 3);
                      
    _championPoketmon[2].iconNumX = 12;
    _championPoketmon[2].iconNumY = 0;
                      
    _championPoketmon[2].type1 = static_cast<int>(TYPE::NOMAL);
    _championPoketmon[2].type2 = static_cast<int>(TYPE::FLYING);
                      
    _championPoketmon[2].attack = 80;
    _championPoketmon[2].defense = 75;
    _championPoketmon[2].specialAttack = 70;
    _championPoketmon[2].specialDefense = 70;
    _championPoketmon[2].speed = 101;
                      
    _championPoketmon[2].maxHP = _championPoketmon[2].currentHP = 83;
                      
    _championPoketmon[2].levelAttack = 2.04f;
    _championPoketmon[2].levelDefense = 1.98f;
    _championPoketmon[2].levelSpecialAttack = 1.92f;
    _championPoketmon[2].levelSpecialDefense = 1.92f;
    _championPoketmon[2].levelSpeed = 2.3f;
    _championPoketmon[2].levelHP = 2.87f;
                      
    _championPoketmon[2].skill[0] = 10;
    _championPoketmon[2].skill[1] = 11;
    _championPoketmon[2].skill[2] = 12;
    _championPoketmon[2].skill[3] = 13;
                      
    _championPoketmon[2].sumAttack = static_cast<int>(_championPoketmon[2].attack + (_championPoketmon[2].levelAttack * _championPoketmon[2].level));
    _championPoketmon[2].sumDefense = _championPoketmon[2].defense + (_championPoketmon[2].levelDefense * _championPoketmon[2].level);
    _championPoketmon[2].sumSpecialAttack = _championPoketmon[2].specialAttack + (_championPoketmon[2].levelSpecialAttack * _championPoketmon[2].level);
    _championPoketmon[2].sumSpecialDefense = _championPoketmon[2].specialDefense + (_championPoketmon[2].levelSpecialDefense * _championPoketmon[2].level);
    _championPoketmon[2].sumSpeed = _championPoketmon[2].speed + (_championPoketmon[2].levelSpeed * _championPoketmon[2].level);
    _championPoketmon[2].sumMaxHP = _championPoketmon[2].maxHP + (_championPoketmon[2].levelHP * _championPoketmon[2].level);
                      
    _championPoketmon[2].currentHP = _championPoketmon[2].sumMaxHP;

}

void poketmonManager::trainer1Poketmon() //트레이너 1
{
    _trainer1Poketmon[0].name = "구구";
 
    _trainer1Poketmon[0].isGender = RND->getFromIntTo(0, 2);
    _trainer1Poketmon[0].index = 16;
    _trainer1Poketmon[0].level = 6;
    _trainer1Poketmon[0].evolutionLevel = 0;

    if (_trainer1Poketmon[0].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _trainer1Poketmon[0].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _trainer1Poketmon[0].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.
  
    _trainer1Poketmon[0].totalEXP = pow(_trainer1Poketmon[0].level, 3);
    _trainer1Poketmon[0].maxExp = pow(_trainer1Poketmon[0].level + 1, 3) - _trainer1Poketmon[0].totalEXP;
    _trainer1Poketmon[0].currentExp = _trainer1Poketmon[0].totalEXP - pow(_trainer1Poketmon[0].level, 3);
 
    _trainer1Poketmon[0].iconNumX = 12;
    _trainer1Poketmon[0].iconNumY = 0;
  
    _trainer1Poketmon[0].type1 = static_cast<int>(TYPE::NOMAL);
    _trainer1Poketmon[0].type2 = static_cast<int>(TYPE::FLYING);

    _trainer1Poketmon[0].attack = 45;
    _trainer1Poketmon[0].defense = 40;
    _trainer1Poketmon[0].specialAttack = 35;
    _trainer1Poketmon[0].specialDefense = 35;
    _trainer1Poketmon[0].speed = 56;
   
    _trainer1Poketmon[0].maxHP = _trainer1Poketmon[0].currentHP = 40;

    _trainer1Poketmon[0].levelAttack = 1.62f;
    _trainer1Poketmon[0].levelDefense = 1.56f;
    _trainer1Poketmon[0].levelSpecialAttack = 1.5f;
    _trainer1Poketmon[0].levelSpecialDefense = 1.5f;
    _trainer1Poketmon[0].levelSpeed = 1.76f;
    _trainer1Poketmon[0].levelHP = 2.44f;

    _trainer1Poketmon[0].skill[0] = 10;
    _trainer1Poketmon[0].skill[1] = 11;
    _trainer1Poketmon[0].skill[2] = 0;
    _trainer1Poketmon[0].skill[3] = 0;

    _trainer1Poketmon[0].sumAttack = static_cast<int>(_trainer1Poketmon[0].attack + (_trainer1Poketmon[0].levelAttack * _trainer1Poketmon[0].level));
    _trainer1Poketmon[0].sumDefense = _trainer1Poketmon[0].defense + (_trainer1Poketmon[0].levelDefense * _trainer1Poketmon[0].level);
    _trainer1Poketmon[0].sumSpecialAttack = _trainer1Poketmon[0].specialAttack + (_trainer1Poketmon[0].levelSpecialAttack * _trainer1Poketmon[0].level);
    _trainer1Poketmon[0].sumSpecialDefense = _trainer1Poketmon[0].specialDefense + (_trainer1Poketmon[0].levelSpecialDefense * _trainer1Poketmon[0].level);
    _trainer1Poketmon[0].sumSpeed = _trainer1Poketmon[0].speed + (_trainer1Poketmon[0].levelSpeed * _trainer1Poketmon[0].level);
    _trainer1Poketmon[0].sumMaxHP = _trainer1Poketmon[0].maxHP + (_trainer1Poketmon[0].levelHP * _trainer1Poketmon[0].level);

    _trainer1Poketmon[0].currentHP = _trainer1Poketmon[0].sumMaxHP;

    //------------------------------------------------------------------------------------------


    _trainer1Poketmon[1].name = "피죤";

    _trainer1Poketmon[1].isGender = RND->getFromIntTo(0, 2);
    _trainer1Poketmon[1].index = 17;
    _trainer1Poketmon[1].level = 11;
    _trainer1Poketmon[1].evolutionLevel = 1;

    if (_trainer1Poketmon[1].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _trainer1Poketmon[1].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _trainer1Poketmon[1].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.
                      
    _trainer1Poketmon[1].totalEXP = pow(_trainer1Poketmon[1].level, 3);
    _trainer1Poketmon[1].maxExp = pow(_trainer1Poketmon[1].level + 1, 3) - _trainer1Poketmon[1].totalEXP;
    _trainer1Poketmon[1].currentExp = _trainer1Poketmon[1].totalEXP - pow(_trainer1Poketmon[1].level, 3);
                      
    _trainer1Poketmon[1].iconNumX = 12;
    _trainer1Poketmon[1].iconNumY = 0;
                      
    _trainer1Poketmon[1].type1 = static_cast<int>(TYPE::NOMAL);
    _trainer1Poketmon[1].type2 = static_cast<int>(TYPE::FLYING);
                      
    _trainer1Poketmon[1].attack = 60;
    _trainer1Poketmon[1].defense = 55;
    _trainer1Poketmon[1].specialAttack = 50;
    _trainer1Poketmon[1].specialDefense = 50;
    _trainer1Poketmon[1].speed = 71;
                      
    _trainer1Poketmon[1].maxHP = _trainer1Poketmon[1].currentHP = 40;
                      
    _trainer1Poketmon[1].levelAttack = 1.8f;
    _trainer1Poketmon[1].levelDefense = 1.74f;
    _trainer1Poketmon[1].levelSpecialAttack = 1.68f;
    _trainer1Poketmon[1].levelSpecialDefense = 1.68f;
    _trainer1Poketmon[1].levelSpeed = 1.94f;
    _trainer1Poketmon[1].levelHP = 2.67f;
                     
    _trainer1Poketmon[1].skill[0] = 10;
    _trainer1Poketmon[1].skill[1] = 11;
    _trainer1Poketmon[1].skill[2] = 12;
    _trainer1Poketmon[1].skill[3] = 0;
                      
    _trainer1Poketmon[1].sumAttack = static_cast<int>(_trainer1Poketmon[1].attack + (_trainer1Poketmon[1].levelAttack * _trainer1Poketmon[1].level));
    _trainer1Poketmon[1].sumDefense = _trainer1Poketmon[1].defense + (_trainer1Poketmon[1].levelDefense * _trainer1Poketmon[1].level);
    _trainer1Poketmon[1].sumSpecialAttack = _trainer1Poketmon[1].specialAttack + (_trainer1Poketmon[1].levelSpecialAttack * _trainer1Poketmon[1].level);
    _trainer1Poketmon[1].sumSpecialDefense = _trainer1Poketmon[1].specialDefense + (_trainer1Poketmon[1].levelSpecialDefense * _trainer1Poketmon[1].level);
    _trainer1Poketmon[1].sumSpeed = _trainer1Poketmon[1].speed + (_trainer1Poketmon[1].levelSpeed * _trainer1Poketmon[1].level);
    _trainer1Poketmon[1].sumMaxHP = _trainer1Poketmon[1].maxHP + (_trainer1Poketmon[1].levelHP * _trainer1Poketmon[1].level);
                      
    _trainer1Poketmon[1].currentHP = _trainer1Poketmon[1].sumMaxHP;

}

void poketmonManager::trainer2Poketmon()  //트레이너2
{
    _trainer2Poketmon[0].name = "깨비참";
                      
    _trainer2Poketmon[0].isGender = RND->getFromIntTo(0, 2);
    _trainer2Poketmon[0].index = 21;
    _trainer2Poketmon[0].level = 7;
    _trainer2Poketmon[0].evolutionLevel = 0;

    if (_trainer2Poketmon[0].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _trainer2Poketmon[0].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _trainer2Poketmon[0].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.
                      
    _trainer2Poketmon[0].totalEXP = pow(_trainer2Poketmon[0].level, 3);
    _trainer2Poketmon[0].maxExp = pow(_trainer2Poketmon[0].level + 1, 3) - _trainer2Poketmon[0].totalEXP;
    _trainer2Poketmon[0].currentExp = _trainer2Poketmon[0].totalEXP - pow(_trainer2Poketmon[0].level, 3);
                      
    _trainer2Poketmon[0].iconNumX = 12;
    _trainer2Poketmon[0].iconNumY = 0;
                      
    _trainer2Poketmon[0].type1 = static_cast<int>(TYPE::NOMAL);
    _trainer2Poketmon[0].type2 = static_cast<int>(TYPE::FLYING);
                      
    _trainer2Poketmon[0].attack = 60;
    _trainer2Poketmon[0].defense = 30;
    _trainer2Poketmon[0].specialAttack = 31;
    _trainer2Poketmon[0].specialDefense = 31;
    _trainer2Poketmon[0].speed = 70;
                      
    _trainer2Poketmon[0].maxHP = _trainer2Poketmon[0].currentHP = 40;
                      
    _trainer2Poketmon[0].levelAttack = 1.8f;
    _trainer2Poketmon[0].levelDefense = 1.44f;
    _trainer2Poketmon[0].levelSpecialAttack = 1.46f;
    _trainer2Poketmon[0].levelSpecialDefense = 1.46f;
    _trainer2Poketmon[0].levelSpeed = 1.92f;
    _trainer2Poketmon[0].levelHP = 2.44f;
                      
    _trainer2Poketmon[0].skill[0] = 15;
    _trainer2Poketmon[0].skill[1] = 16;
    _trainer2Poketmon[0].skill[2] = 0;
    _trainer2Poketmon[0].skill[3] = 0;
                      
    _trainer2Poketmon[0].sumAttack = static_cast<int>(_trainer2Poketmon[0].attack + (_trainer2Poketmon[0].levelAttack * _trainer2Poketmon[0].level));
    _trainer2Poketmon[0].sumDefense = _trainer2Poketmon[0].defense + (_trainer2Poketmon[0].levelDefense * _trainer2Poketmon[0].level);
    _trainer2Poketmon[0].sumSpecialAttack = _trainer2Poketmon[0].specialAttack + (_trainer2Poketmon[0].levelSpecialAttack * _trainer2Poketmon[0].level);
    _trainer2Poketmon[0].sumSpecialDefense = _trainer2Poketmon[0].specialDefense + (_trainer2Poketmon[0].levelSpecialDefense * _trainer2Poketmon[0].level);
    _trainer2Poketmon[0].sumSpeed = _trainer2Poketmon[0].speed + (_trainer2Poketmon[0].levelSpeed * _trainer2Poketmon[0].level);
    _trainer2Poketmon[0].sumMaxHP = _trainer2Poketmon[0].maxHP + (_trainer2Poketmon[0].levelHP * _trainer2Poketmon[0].level);
                      
    _trainer2Poketmon[0].currentHP = _trainer2Poketmon[0].sumMaxHP;

    //-----------------------------------------------------------------------------------------------------------------------------------------

    _trainer2Poketmon[1].name = "깨비드릴조";
                      
    _trainer2Poketmon[1].isGender = RND->getFromIntTo(0, 2);
    _trainer2Poketmon[1].index = 22;
    _trainer2Poketmon[1].level = 12;
    _trainer2Poketmon[1].evolutionLevel = 1;

    if (_trainer2Poketmon[1].isGender)         // 포켓몬 성별체크가 트루일시
    {
        _trainer2Poketmon[1].gender = "♂";  // 포켓몬의 성별은 수컷이 된다
    }
    else  _trainer2Poketmon[1].gender = "♀"; // 그 외의 포켓몬의 성별은 암컷이 된다.
                      
    _trainer2Poketmon[1].totalEXP = pow(_trainer2Poketmon[1].level, 3);
    _trainer2Poketmon[1].maxExp = pow(_trainer2Poketmon[1].level + 1, 3) - _trainer2Poketmon[1].totalEXP;
    _trainer2Poketmon[1].currentExp = _trainer2Poketmon[1].totalEXP - pow(_trainer2Poketmon[1].level, 3);
                      
    _trainer2Poketmon[1].iconNumX = 12;
    _trainer2Poketmon[1].iconNumY = 0;
                      
    _trainer2Poketmon[1].type1 = static_cast<int>(TYPE::NOMAL);
    _trainer2Poketmon[1].type2 = static_cast<int>(TYPE::FLYING);
                      
    _trainer2Poketmon[1].attack = 90;
    _trainer2Poketmon[1].defense = 65;
    _trainer2Poketmon[1].specialAttack = 61;
    _trainer2Poketmon[1].specialDefense = 61;
    _trainer2Poketmon[1].speed = 100;
                      
    _trainer2Poketmon[1].maxHP = _trainer2Poketmon[1].currentHP = 65;
                      
    _trainer2Poketmon[1].levelAttack = 2.16f;
    _trainer2Poketmon[1].levelDefense = 1.86f;
    _trainer2Poketmon[1].levelSpecialAttack = 1.82f;
    _trainer2Poketmon[1].levelSpecialDefense = 1.82f;
    _trainer2Poketmon[1].levelSpeed = 2.28f;
    _trainer2Poketmon[1].levelHP = 2.69f;
                      
    _trainer2Poketmon[1].skill[0] = 15;
    _trainer2Poketmon[1].skill[1] = 16;
    _trainer2Poketmon[1].skill[2] = 17;
    _trainer2Poketmon[1].skill[3] = 0;
                      
    _trainer2Poketmon[1].sumAttack = static_cast<int>(_trainer2Poketmon[1].attack + (_trainer2Poketmon[1].levelAttack * _trainer2Poketmon[1].level));
    _trainer2Poketmon[1].sumDefense = _trainer2Poketmon[1].defense + (_trainer2Poketmon[1].levelDefense * _trainer2Poketmon[1].level);
    _trainer2Poketmon[1].sumSpecialAttack = _trainer2Poketmon[1].specialAttack + (_trainer2Poketmon[1].levelSpecialAttack * _trainer2Poketmon[1].level);
    _trainer2Poketmon[1].sumSpecialDefense = _trainer2Poketmon[1].specialDefense + (_trainer2Poketmon[1].levelSpecialDefense * _trainer2Poketmon[1].level);
    _trainer2Poketmon[1].sumSpeed = _trainer2Poketmon[1].speed + (_trainer2Poketmon[1].levelSpeed * _trainer2Poketmon[1].level);
    _trainer2Poketmon[1].sumMaxHP = _trainer2Poketmon[1].maxHP + (_trainer2Poketmon[1].levelHP * _trainer2Poketmon[1].level);
                      
    _trainer2Poketmon[1].currentHP = _trainer2Poketmon[1].sumMaxHP;
}

void poketmonManager::render()
{
    char str[128];

    char poke[128];

    // string strname = myPokemon[i].name;
    // strcpy_s(poke, strname.c_str());


    string strnmae = _trainer2Poketmon[1].name;
    strcpy_s(poke, strnmae.c_str());

   //sprintf_s(str, "포켓몬 이름 : %s", poke);
   //TextOut(getMemDC(), 280, 180, str, strlen(str));
    //sprintf_s(str, "포켓몬 현재체력 : %d ", _wildPoketmon.currentHP);
    //TextOut(getMemDC(), 280, 200, str, strlen(str));
    //sprintf_s(str, "포켓몬 : %d ", _championPoketmon[1].sumMaxHP);
    //TextOut(getMemDC(), 100, 320, str, strlen(str));
    //sprintf_s(str, "포켓몬 max경험치 : %d ", _wildPoketmon.maxExp);
    //TextOut(getMemDC(), 100, 340, str, strlen(str));
    //sprintf_s(str, "포켓몬 current경험치 : %d ", _wildPoketmon.currentExp);
    //TextOut(getMemDC(), 100, 360, str, strlen(str));
    //sprintf_s(str, "포켓몬 total경험치 : %d ", _wildPoketmon.totalEXP);
    //TextOut(getMemDC(), 100, 380, str, strlen(str));


  
    _skill->render();
}

void poketmonManager::poketmonImage()
{
    //포켓몬 앞
    IMAGEMANAGER->addFrameImage("155F", "image/poketmon/no_155F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156F", "image/poketmon/no_156F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157F", "image/poketmon/no_157F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152F", "image/poketmon/no_152F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("153F", "image/poketmon/no_153F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("154F", "image/poketmon/no_154F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("158F", "image/poketmon/no_158F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("159F", "image/poketmon/no_159F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("160F", "image/poketmon/no_160F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("25F", "image/poketmon/no_25F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("26F", "image/poketmon/no_26F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("19F", "image/poketmon/no_19F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("20F", "image/poketmon/no_20F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("16F", "image/poketmon/no_16F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("17F", "image/poketmon/no_17F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("18F", "image/poketmon/no_18F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("21F", "image/poketmon/no_21F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("22F", "image/poketmon/no_22F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("10F", "image/poketmon/no_10F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("11F", "image/poketmon/no_11F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("12F", "image/poketmon/no_12F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("13F", "image/poketmon/no_13F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("14F", "image/poketmon/no_14F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("15F", "image/poketmon/no_15F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));

}


