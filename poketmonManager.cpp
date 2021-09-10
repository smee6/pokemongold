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


    poketmonImage();

    poketmonSpawn();

    wildPoketmonSetting();

    

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

    _randomPoketmon = RND->getFromIntTo(0, 8);                           //랜덤 야생포켓몬 변수

    _wildPoketmon.name = _vPoketmon[_randomPoketmon]->getTagPoketmon().name;                         //야생포켓몬 이름
    _wildPoketmon.gender = _vPoketmon[_randomPoketmon]->getTagPoketmon().gender;                       //야생포켓몬 성별
    _wildPoketmon.isGender = _vPoketmon[_randomPoketmon]->getTagPoketmon().isGender;                     //야생포켓몬 성별확인
    _wildPoketmon.index = _vPoketmon[_randomPoketmon]->getTagPoketmon().index;                        //야생포켓몬 번호
    _wildPoketmon.level = _vPoketmon[_randomPoketmon]->getTagPoketmon().level;                        //야생포켓몬 레벨
    _wildPoketmon.evolutionLevel = _vPoketmon[_randomPoketmon]->getTagPoketmon().evolutionLevel;               //야생포켓몬 진화단계

    _wildPoketmon.iconNumX = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumX;                     //미니 포켓몬 이미지 아이콘 좌표 X
    _wildPoketmon.iconNumY = _vPoketmon[_randomPoketmon]->getTagPoketmon().iconNumY;                     //미니 포켓몬 이미지 아이콘 좌표 Y

    _wildPoketmon.type1 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type1;                        //타입1
    _wildPoketmon.type2 = _vPoketmon[_randomPoketmon]->getTagPoketmon().type2;                        //타입2

    _wildPoketmon.attack = _vPoketmon[_randomPoketmon]->getTagPoketmon().attack;                       //1레벨 공격력
    _wildPoketmon.defense = _vPoketmon[_randomPoketmon]->getTagPoketmon().defense;                      //1레벨 방어력
    _wildPoketmon.specialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialAttack;                //1레벨 특수공격력   
    _wildPoketmon.specialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().specialDefense;               //1레벨 특수방어력
    _wildPoketmon.speed = _vPoketmon[_randomPoketmon]->getTagPoketmon().speed;                        //1레벨 스피드

    _wildPoketmon.currentHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentHP;                    //현재체력
    _wildPoketmon.maxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxHP;                        //1레벨 최대체력;

    _wildPoketmon.levelAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelAttack;                  //레벨당 공격력
    _wildPoketmon.levelDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelDefense;                 //레벨당 방어력
    _wildPoketmon.levelSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialAttack;           //레벨당 특수공격력
    _wildPoketmon.levelSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpecialDefense;          //레벨당 특수방어력
    _wildPoketmon.levelSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelSpeed;                   //레벨당 스피드
    _wildPoketmon.levelHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().levelHP;                      //레벨당 HP

    _wildPoketmon.sumAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumAttack;                    //현재 공결력
    _wildPoketmon.sumDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumDefense;                   //현재 방어력
    _wildPoketmon.sumSpecialAttack = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialAttack;             //현재 특수공격력
    _wildPoketmon.sumSpecialDefense = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpecialDefense;            //현재 특수방어력
    _wildPoketmon.sumSpeed = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumSpeed;                     //현재 스피드
    _wildPoketmon.sumMaxHP = _vPoketmon[_randomPoketmon]->getTagPoketmon().sumMaxHP;                     //현재 최대HP

    _wildPoketmon.currentExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().currentExp;                   //현재 경험치
    _wildPoketmon.maxExp = _vPoketmon[_randomPoketmon]->getTagPoketmon().maxExp;                       //레벨계산용
    _wildPoketmon.totalEXP = _vPoketmon[_randomPoketmon]->getTagPoketmon().totalEXP;                     //현재 레벨의 최대 경험치

    _wildPoketmon.skill[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[0];                       //스킬1
    _wildPoketmon.skill[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[1];                       //스킬2
    _wildPoketmon.skill[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[2];                       //스킬3
    _wildPoketmon.skill[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skill[3];                       //스킬4

    _wildPoketmon.skillPP[0] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[0];                     //스킬1PP
    _wildPoketmon.skillPP[1] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[1];                     //스킬2PP
    _wildPoketmon.skillPP[2] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[2];                     //스킬3PP
    _wildPoketmon.skillPP[3] = _vPoketmon[_randomPoketmon]->getTagPoketmon().skillPP[3];                     //스킬4PP

    _wildPoketmon.item = _vPoketmon[_randomPoketmon]->getTagPoketmon().item;                         //아이템..

   
}

void poketmonManager::render()
{
    char str[128];

    char poke[128];

    // string strname = myPokemon[i].name;
    // strcpy_s(poke, strname.c_str());


    string strnmae = _wildPoketmon.name;
    strcpy_s(poke, strnmae.c_str());

  sprintf_s(str, "포켓몬 이름 : %s", poke);
  TextOut(getMemDC(), 280, 180, str, strlen(str));
  sprintf_s(str, "포켓몬 현재체력 : %d ", _wildPoketmon.currentHP);
  TextOut(getMemDC(), 280, 200, str, strlen(str));
   // sprintf_s(str, "포켓몬 레벨 : %d ", _wildPoketmon.level);
   // TextOut(getMemDC(), 100, 320, str, strlen(str));
   // sprintf_s(str, "포켓몬 스킬번호 : %d ", _wildPoketmon.skill1);
   // TextOut(getMemDC(), 100, 340, str, strlen(str));

    _skill->render();
}

void poketmonManager::poketmonImage()
{
    //포켓몬 앞
    IMAGEMANAGER->addFrameImage("155F", "image/poketmon/no_155F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156F", "image/poketmon/no_156F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157F", "image/poketmon/no_157F.bmp", 180, 180, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152F", "image/poketmon/no_152Fbmp", 160, 160, 1, 1, true, RGB(255, 0, 255));
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


