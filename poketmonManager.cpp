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
    poketmonImage();



    return S_OK;
}

void poketmonManager::release()
{

}

void poketmonManager::update()
{

}

void poketmonManager::poketmonSpawn()
{
    // 랜덤값 넣고
    // RND->getFromIntTo(0, 10);

    // 스위치문으로 벡터 담고
    
    ////치코리타
    //poketmon* monster;
    //monster = new chikorita;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////브케인
    //poketmon* monster;
    //monster = new cyndaquil;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////리아코
    //poketmon* monster;
    //monster = new totodile;
    //monster->init();
    //_vPoketmon.push_back(monster);

    ////피카츄
    //poketmon* monster;
    //monster = new pikachu;
    //monster->init();
    //_vPoketmon.push_back(monster);

}

void poketmonManager::render()
{

}

void poketmonManager::poketmonImage()
{
    //포켓몬 앞
    IMAGEMANAGER->addFrameImage("브케인_앞", "image/poketmon/no_155F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("마그케인_앞", "image/poketmon/no_156F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("블레이범_앞", "image/poketmon/no_157F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("치코리타_앞", "image/poketmon/no_152Fbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("베이리프_앞", "image/poketmon/no_153F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("메가니움_앞", "image/poketmon/no_154F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("리아코_앞", "image/poketmon/no_158F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("엘리게이_앞", "image/poketmon/no_159F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("장크로다일_앞", "image/poketmon/no_160F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피카츄_앞", "image/poketmon/no_25F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("라이츄_앞", "image/poketmon/no_26F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("꼬렛_앞", "image/poketmon/no_19F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("레트라_앞", "image/poketmon/no_20F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("구구_앞", "image/poketmon/no_16F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피죤_앞", "image/poketmon/no_17F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("피죤투_앞", "image/poketmon/no_18F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("깨비참_앞", "image/poketmon/no_21F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("깨비드릴조_앞", "image/poketmon/no_22F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("캐터피_앞", "image/poketmon/no_10F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("단데기_앞", "image/poketmon/no_11F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("버터플_앞", "image/poketmon/no_12F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("뿔충이_앞", "image/poketmon/no_13F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("딱충이_앞", "image/poketmon/no_14F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("독침붕_앞", "image/poketmon/no_15F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));

}


