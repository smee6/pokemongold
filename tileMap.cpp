#include "pch.h"
#include "tileMap.h"

tileMap::tileMap()
{
}

tileMap::~tileMap()
{
}

HRESULT tileMap::init()
{
	//맵 이미지
	_map = IMAGEMANAGER->addImage("map", "image/pokemon_Map.bmp", 7936, 2304, true, RGB(255, 0, 255));

	//맵 카메라 초기화
	_cameraX = 0;
	_cameraY = 0;

	//타일 속성 초기화 (삭제예정)
	//for (int i = 0; i < TILE; i++)
	//{
	//		_tile[i].type = TILETYPE_CLOSE;
	//}

	load();

	return S_OK;
}

void tileMap::release()
{
}

void tileMap::update()
{
	//움직이는 키(삭제 예정)
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_cameraY % 64 == 0) _direction = LEFT;
		moveX();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_cameraY % 64 == 0)_direction = RIGHT;
		moveX();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_cameraX % 64 == 0) _direction = TOP;
		moveY();
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_cameraX % 64 == 0) _direction = BOTTOM;
		moveY();
	}
	//저장과 불러오기
	//if (KEYMANAGER->isOnceKeyDown('R'))
	//{
	//	save();
	//}
	//if (KEYMANAGER->isOnceKeyDown('Y'))
	//{
	//	load();
	//}
	if (_cameraX % 64 != 0) moveX();
	if (_cameraY % 64 != 0) moveY();
	
	setTile();
}

void tileMap::render()
{
	//맵이미지
	_map->render(getMemDC(), -6400 -_cameraX, -1152 - _cameraY);

	//타일 속성별로 색이 다름(삭제예정)
	for (int i = 0; i < TILE; i++)
	{
			if (_tile[i].type == TILETYPE_CLOSE) continue;
			if (_tile[i].rc.left > WINSIZEX || _tile[i].rc.right < 0 || _tile[i].rc.top > WINSIZEY || _tile[i].rc.bottom < 0) continue;
	
			if (_tile[i].type == TILETYPE_OPEN)
			{
				HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
	
			if (_tile[i].type == TILETYPE_GRASS)
			{
				HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
	
			if (_tile[i].type == TILETYPE_DOOR)
			{
				HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
	
			if (_tile[i].type == TILETYPE_LEFTSLOPE)
			{
				HBRUSH brush = CreateSolidBrush(RGB(125, 0, 0));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
	
			if (_tile[i].type == TILETYPE_RIGHTSLOPE)
			{
				HBRUSH brush = CreateSolidBrush(RGB(0, 125, 0));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
	
			if (_tile[i].type == TILETYPE_BOTTOMSLOPE)
			{
				HBRUSH brush = CreateSolidBrush(RGB(0, 0, 125));
				HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
				Rectangle(getMemDC(), _tile[i].rc);
				SelectObject(getMemDC(), oldBrush);
				DeleteObject(brush);
			}
			char str[128];
			sprintf_s(str, "cameraX : %d", _cameraX);
			TextOut(getMemDC(), 100, 100, str,strlen(str));
	
			sprintf_s(str, "cameraY : %d", _cameraY);
			TextOut(getMemDC(), 100, 130, str, strlen(str));
	}
}

void tileMap::setTile()
{
	//타일 렉트 생성
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			_tile[i * 24 + j].rc = RectMake(j * TILESIZE - _cameraX, i * TILESIZE - _cameraY, TILESIZE, TILESIZE);
		}
	}

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			_tile[431 + i * 60 + j].rc = RectMake(-3840 + j * TILESIZE - _cameraX, i * TILESIZE - _cameraY, TILESIZE, TILESIZE);
		}
	}

	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			_tile[1511 + i * 40 + j].rc = RectMake(-6400 + j * TILESIZE - _cameraX, -1152 + i * TILESIZE - _cameraY, TILESIZE, TILESIZE);
		}
	}
	//속성 부여(삭제 예정)
	for (int i = 0; i < TILE; i++)
	{
		if (PtInRect(&_tile[i].rc, _ptMouse))
		{
			if (KEYMANAGER->isStayKeyDown('C'))
				_tile[i].type = TILETYPE_CLOSE;
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				_tile[i].type = TILETYPE_OPEN;
			if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
				_tile[i].type = TILETYPE_GRASS;
			if (KEYMANAGER->isStayKeyDown('W'))
				_tile[i].type = TILETYPE_DOOR;
			if (KEYMANAGER->isStayKeyDown('A'))
				_tile[i].type = TILETYPE_LEFTSLOPE;
			if (KEYMANAGER->isStayKeyDown('D'))
				_tile[i].type = TILETYPE_RIGHTSLOPE;
			if (KEYMANAGER->isStayKeyDown('S'))
				_tile[i].type = TILETYPE_BOTTOMSLOPE;

		}
	}
}

void tileMap::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("tileSave.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tile, sizeof(tagTile) * (TILE) , &write, NULL);

	CloseHandle(file);
}

void tileMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tile, sizeof(tagTile) * (TILE) , &read, NULL);

	CloseHandle(file);
}

void tileMap::moveX()
{
	switch (_direction)
	{
	case LEFT:
		_cameraX -= 4;
		break;
	case RIGHT:
		_cameraX += 4;
		break;
	}
}

void tileMap::moveY()
{
	switch (_direction)
	{
	case TOP:
		_cameraY -= 4;
		break;
	case BOTTOM:
		_cameraY += 4;
		break;
	}
}
