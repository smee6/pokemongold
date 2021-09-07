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
    IMAGEMANAGER->addFrameImage("155F", "image/poketmon/no_155F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("156F", "image/poketmon/no_156F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("157F", "image/poketmon/no_157F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("152F", "image/poketmon/no_152Fbmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("153F", "image/poketmon/no_153F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("154F", "image/poketmon/no_154F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("158F", "image/poketmon/no_158F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("159F", "image/poketmon/no_159F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("160F", "image/poketmon/no_160F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("25F", "image/poketmon/no_25F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("26F", "image/poketmon/no_26F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("19F", "image/poketmon/no_19F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("20F", "image/poketmon/no_20F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("16F", "image/poketmon/no_16F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("17F", "image/poketmon/no_17F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("18F", "image/poketmon/no_18F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("21F", "image/poketmon/no_21F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("22F", "image/poketmon/no_22F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("10F", "image/poketmon/no_10F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("11F", "image/poketmon/no_11F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("12F", "image/poketmon/no_12F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("13F", "image/poketmon/no_13F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("14F", "image/poketmon/no_14F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("15F", "image/poketmon/no_15F.bmp", 112, 112, 1, 1, true, RGB(255, 0, 255));

}


