#include "pch.h"
#include "endingScene.h"

endingScene::endingScene()
{
}

endingScene::~endingScene()
{
}

HRESULT endingScene::init()
{
	SOUNDMANAGER->play("ending", 0.01f * UIMANAGER->soundVolume);
	_endingBackground[0] = IMAGEMANAGER->addImage("엔딩배경1", "image/end_image/endingBackground1.bmp", 640, 576, true, RGB(255, 0, 255));				// 엔딩 배경 1
	_endingBackground[1] = IMAGEMANAGER->addImage("엔딩배경2", "image/end_image/endingBackground2.bmp", 640, 576, true, RGB(255, 0, 255));				// 엔딩 배경 1
	_endingBackground[2] = IMAGEMANAGER->addImage("엔딩배경3", "image/end_image/endingBackground3.bmp", 640, 576, true, RGB(255, 0, 255));				// 엔딩 배경 1
	_endingBackground[3] = IMAGEMANAGER->addImage("엔딩배경4", "image/end_image/endingBackground4.bmp", 640, 576, true, RGB(255, 0, 255));				// 엔딩 배경 1

	_endingPokemon[0] = IMAGEMANAGER->addFrameImage("엔딩포켓몬1", "image/end_image/endingPokemon1.bmp", 192, 68, 3, 1, true, RGB(255, 0, 255));		// 엔딩 포켓몬 1(릴리코?)
	_endingPokemon[1] = IMAGEMANAGER->addFrameImage("엔딩포켓몬2", "image/end_image/endingPokemon2.bmp", 162, 56, 3, 1, true, RGB(255, 0, 255));		// 엔딩 포켓몬 1(토게피)
	_endingPokemon[2] = IMAGEMANAGER->addFrameImage("엔딩포켓몬3", "image/end_image/endingPokemon3.bmp", 216, 68, 3, 1, true, RGB(255, 0, 255));		// 엔딩 포켓몬 1(에레키드)
	_endingPokemon[3] = IMAGEMANAGER->addFrameImage("엔딩포켓몬4", "image/end_image/endingPokemon4.bmp", 208, 72, 4, 1, true, RGB(255, 0, 255));		// 엔딩 포켓몬 1(꼬리선)

	_time = TIMEMANAGER->getWorldTime();		// 현재 시간으로 설정

	return S_OK;
}

void endingScene::release()
{
}

void endingScene::update()
{
	static int count = 0;

	if (count % 7 == 0)
	{
		if (_index < 2 && _endCount != 3) _index++;				// 엔딩 포켓몬 프레임 랜더용 변수
		else if (_index < 3 && _endCount == 3) _index++;		// 꼬리선만 프레임이 4장이라서 꼬리선일떄만 루프 값 다르게 설정
		else _index = 0;
	}

	count++;

	// 각 화면이 2초가 지나면 다음 화면으로 넘어가도록 설정
	if (TIMEMANAGER->getWorldTime() >= _time + 2 && _endCount < 3)
	{
		_endCount++;		// 배열번호 + 1
		_time = TIMEMANAGER->getWorldTime();		// 시간 값 다시 받아옴
		_index = 0;			// 프레임 번호 초기화
	}
}

void endingScene::render()
{
	_endingBackground[_endCount]->render(getMemDC());		// n번쨰 배경 렌더
	for (int i = 0; i < 5; i++)
	{
		// n번째 포켓몬 프레임 렌더
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, 20, _index, 0);
		_endingPokemon[_endCount]->frameRender(getMemDC(), 50 + i * 120, WINSIZEY - 30 - 50, _index, 0);
	}

	//글자
	////////////////////////////////////////////////////////////////////////////  			
	_scrCnt++;

	if (_scrCnt <= 200) {
	
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "포켓몬스터 골드버전 모작 팀 프로젝트";


		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 110, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	}
	else if (_scrCnt > 200 && _scrCnt < 400) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);

		const char* s1_1 = "제작 : 경일 29기 진 아재무쌍";

		sprintf_s(str, s1_1);
		TextOut(_backBuffer->getMemDC(), 130, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	
	}
	else if (_scrCnt > 400 && _scrCnt < 600) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(36, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "플레이 해주셔서 감사합니다.";
		const char* s1_1 = "Thanks for Playing this Game";

		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 160, 250, str, strlen(str));
		sprintf_s(str, s1_1);
		TextOut(_backBuffer->getMemDC(), 20, 290, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	}
	else if (_scrCnt > 600) {
		char str[128];

		SetTextColor(_backBuffer->getMemDC(), RGB(0, 0, 0));

		HFONT font2 = CreateFont(50, 0, 0, 0, 700, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

		HFONT oldFont2 = (HFONT)SelectObject(_backBuffer->getMemDC(), font2);
		const char* s1 = "TO BE COUNTINUE";


		sprintf_s(str, s1);
		TextOut(_backBuffer->getMemDC(), 60, 250, str, strlen(str));

		SelectObject(_backBuffer->getMemDC(), oldFont2);
		DeleteObject(font2);
	
	}

	//////////////////////////////////////////////////////////////////////////
	//


}
