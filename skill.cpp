#include "pch.h"
#include "skill.h"
#include "poketmon.h"
#include "poketmonManager.h"

skill::skill()
{
}

skill::~skill()
{
}

HRESULT skill::init()
{
	imageInit();

	STATUS_AILMENT::NONE;	// 상태이상 초기값은 없음
		

	_index = _currentFrame = _frameCount = 0;		//애니메이션 관련 초기화

	//_isWhoSkill = true;
	_isSkill = false;								//초기화

	_imgX = 0;
	_imgY = 0;

	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	야생일시
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	플레이어 일시

	SOUNDMANAGER->addSound("몸통박치기", "soundFX/BodySlam.wav", true, false);

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
	

	//밑에 키매니저들은 체크할려고 만든 것들 나중에 지워도 됨
	//if (KEYMANAGER->isOnceKeyDown('K')) _isSkill = true;
	//if (KEYMANAGER->isOnceKeyDown('I')) _isWhoSkill = true;			//나 (플레이어)
	//if (KEYMANAGER->isOnceKeyDown('U')) _isWhoSkill = false;		//야생

	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	야생일시
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	플레이어 일시
	
	skillAni();
	


}

void skill::skillNone()													//스킬없음
{
	//_skillNumber = 0;													//스킬넘버

	_name = " -";														//이름

	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = 0;
		_imgY = 0;
	}
	_power = NULL;														//위력
	_PP = NULL;															//PP
	_accuracy = NULL;													//명중률

	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::tackle()													// 몸통박치기
{

	//_skillNumber = 1;													//스킬넘버

	_name = "몸통박치기";												//이름


	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = 25;
		_imgY = 0;
	}
	_imgName = "attack";												//이미지이름

	

	_power = 40;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입

}

void skill::stringShot()												//실뿜기
{
	//_skillNumber = 2;													//스킬넘버

	_name = "실뿜기";													//이름
	
	if (!_isWhoSkill)
	{

		_imgX = -200;
		_imgY = 0;

		_imgName = "mystringShot";											//이미지이름
	
	}


	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -100;

		_imgName = "wildstringShot";											//이미지이름
		
	}


	_power = NULL;														//위력
	_PP = 40;															//PP
	_accuracy = 95;														//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);						//타입

}

void skill::confusion()													//염동력
{
	//_skillNumber = 3;													//스킬넘버

	_name = "염동력";													//이름
	if (!_isWhoSkill)
	{
		_imgX = -200;
		_imgY = 50;

		_imgName = "myconfusion";											//이미지이름
	}
	
	
	if (_isWhoSkill)
	{
		_imgX = 125;
		_imgY = -100;

		_imgName = "wildconfusion";											//이미지이름
	}										


	_power = 50;														//위력
	_PP = 25;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);					//타입	
}

void skill::poisonPowder()												//독가루
{
	//_skillNumber = 4;													//스킬넘버

	_name = "독가루";													//이름
	_imgName = "poison";												//이미지이름
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;														//위력
	_PP = 35;															//PP
	_accuracy = 75;														//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);					//타입
	_ifAilment = STATUS_AILMENT::POISON;								//상태이상
}

void skill::stunSpore()													//저리가루
{
	//_skillNumber = 5;													//스킬넘버

	_name = "저리가루";													//이름
	_imgName = "poison";												//이미지이름
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;														//위력
	_PP = 30;															//PP
	_accuracy = 75;														//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//타입
	_ifAilment = STATUS_AILMENT::PARALYSIS;								//상태이상
}

void skill::sleepPowder()												//수면가루
{
	//_skillNumber = 6;													//스킬넘버

	_name = "수면가루";													//이름
	_imgName = "poison";												//이미지이름
	if (_isWhoSkill || !_isWhoSkill)
	{
		_imgX = -80;
		_imgY = -50;
	}
	_power = NULL;								 						//위력
	_PP = 15;															//PP
	_accuracy = 75;														//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//타입
	_ifAilment = STATUS_AILMENT::SLEEP;									//상태이상
}

void skill::poisonSting()												//독침
{
	//_skillNumber = 7;													//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "독침";														//이름
	
	
	if (!_isWhoSkill)
	{
		_imgName = "mypoisonSting";											//이미지이름
		
		_imgX = -150;
		_imgY = 70;

	}
	
	if (_isWhoSkill)
	{
		_imgName = "wildpoisonSting";

		_imgX = 150;
		_imgY = -70;
	}


	_power = 15;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::POISON);					//타입

	if (_index > 80) STATUS_AILMENT::POISON;							//상태이상 20퍼 확률로..

}

void skill::focusEnergy()												//기충전
{
	//_skillNumber = 8;													//스킬넘버

	_name = "기충전";													//이름


	_imgName = "growth";

	if (!_isWhoSkill)
	{	

		_imgX = -380;
		_imgY = 160;

	}

	if (_isWhoSkill)
	{	
		_imgX = 300;
		_imgY = -220;
	}


	_power = NULL;														//위력
	_PP = 30;															//PP
	_accuracy = NULL;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::twineedle()													//더블니들
{
	//_skillNumber = 9;													//스킬넘버

	_name = "더블니들";													//이름
	
	if (!_isWhoSkill)
	{
		_imgName = "myhorn";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildhorn";

		_imgX = 150;
		_imgY = -70;
	}




	_power = 25;														//위력
	_PP = 20;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::BUG);						//타입
}

void skill::sandAttack()												//모래뿌리기
{
	//_skillNumber = 10;												//스킬넘버

	_name = "모래뿌리기";												//이름
	
	if (!_isWhoSkill)
	{
		_imgName = "mysandAttack";

		_imgX = -200;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildsandAttack";

		_imgX = 80;
		_imgY = -150;
	}

	_power = NULL;														//위력
	_PP = 15;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GROUND);					//타입

}

void skill::gust()														//바람일으키기
{
	//_skillNumber = 11;												//스킬넘버

	_name = "바람일으키기";												//이름
	_imgName = "squall";												//이미지이름

	if (!_isWhoSkill)
	{
		
		_imgX = 0;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = 25;
	}


	_power = 40;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//타입
}

void skill::quickAttack()												//전광석화
{
	//_skillNumber = 12;												//스킬넘버

	_name = "전광석화";													//이름
	
	if (!_isWhoSkill)
	{
		_imgName = "myquickAttack";

		_imgX = -400;
		_imgY = -15;
	}
	if (_isWhoSkill)
	{
		_imgName = "wildquickAttack";

		_imgX =  -100;
		_imgY = -250;
	}

	_power = 40;														//위력
	_PP = 30;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::wingAttack()												//날개치기
{
	//_skillNumber = 13;												//스킬넘버

	_name = "날개치기";													//이름
	_imgName = "wingAttack";											//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = 0;
	}
	if (_isWhoSkill)
	{

		_imgX = -20;
		_imgY = 20;
	}

	

	_power = 60;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//타입
}

void skill::tailWhip()													//꼬리흔들기
{
	//_skillNumber = 14;												//스킬넘버

	_name = "꼬리흔들기";												//이름
	_imgName = "tailWhip";													//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -50;
	}
	if (_isWhoSkill)
	{

		_imgX = -20;
		_imgY = -50;
	}


	_power = NULL;														//위력
	_PP = 30;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::peck()														//쪼기
{
	//_skillNumber = 15;												//스킬넘버

	_name = "쪼기";														//이름
	
	if (!_isWhoSkill)
	{
		_imgName = "mypoisonSting";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildpoisonSting";

		_imgX = 150;
		_imgY = -70;
	}

	_power = 35;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FLYING);					//타입
}

void skill::growl()														//울음소리
{
	//_skillNumber = 16;												//스킬넘버

	_name = "울음소리";													//이름

	if (!_isWhoSkill)
	{
		_imgName = "mygrowl";

		_imgX = -200;
		_imgY = 50;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildgrowl";

		_imgX = 180;
		_imgY = -270;
	}

	_power = NULL;														//위력
	_PP = 40;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::leer()														//째려보기
{
	//_skillNumber = 17;												//스킬넘버

	_name = "째려보기";													//이름
	

	if (!_isWhoSkill)
	{
		_imgName = "myleer";

		_imgX = -250;
		_imgY = 0;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildleer";

		_imgX = 50;
		_imgY = -150;
	}
	

	_power = NULL;														//위력
	_PP = 30;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::thunderShock()												//전기쇼크
{
	//_skillNumber = 18;												//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "전기쇼크";													//이름
								
	
	_imgName = "thunderShock";

	if (!_isWhoSkill)
	{
		_imgX = -60;
		_imgY = -100;

	}

	if (_isWhoSkill)
	{
		_imgX = -45;
		_imgY = -100;
	}
	
		
	
	

	_power = 40;														//위력
	_PP = 30;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);					//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;							//상태이상 10퍼확률로 마비

}

void skill::thunderbolt()												//10만볼트
{
	//_skillNumber = 19;												//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "10만볼트";													//이름
	
	_imgName = "spark";

	if (!_isWhoSkill)
	{
		_imgX = -10;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -50;
	}
	

	_power = 90;														//위력
	_PP = 15;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::ELECTR);					//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;							//상태이상 10퍼 확률로 마비
}

void skill::razorLeaf()													//잎날가르기
{
	//_skillNumber = 20;												//스킬넘버

	_name = "잎날가르기";												//이름
	

	if (!_isWhoSkill)
	{
		_imgName = "myrazorLeaf";											//이미지이름

		_imgX = -410;
		_imgY = -70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildrazorLeaf";											//이미지이름

		_imgX = -50;
		_imgY = -250;
	}

	_power = 55;														//위력
	_PP = 25;															//PP
	_accuracy = 95;														//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::GRASS);					//타입
}

void skill::reflect()													//리플렉터 물리데미지 반감.
{
	//_skillNumber = 21;												//스킬넘버

	_name = "리플렉터";													//이름
	_imgName = "lightScreen";											//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -300;
		_imgY = 100;

	}

	if (_isWhoSkill)
	{
		_imgX = 300;
		_imgY = -250;
	}

	_power = NULL;														//위력
	_PP = 20;															//PP
	_accuracy = NULL;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::PSYCHC);					//타입
}

void skill::smokescreen()												//연막
{
	//_skillNumber = 22;												//스킬넘버

	_name = "연막";														//이름
	

	if (!_isWhoSkill)
	{
		_imgName = "mysmokescreen";											//이미지이름

		_imgX = -200;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildsmokescreen";

		_imgX = -80;
		_imgY = -250;
	}

	_power = NULL;														//위력
	_PP = 20;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::ember()														//불꽃세례
{
	//_skillNumber = 23;												//스킬넘버

	_index = RND->getFromIntTo(0, 100);

	_name = "불꽃세례";													//이름
														//이미지이름

	if (!_isWhoSkill)
	{
		_imgName = "myember";

		_imgX = -250;
		_imgY = -75;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildember";
		
		_imgX = -40;
		_imgY = -155;
	}

	_power = 40;														//위력
	_PP = 25;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::FIRE);					//타입

	if (_index > 90) STATUS_AILMENT::BURN;								//상태이상
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//상대가 얼음상태면 녹일 수 있음 --지워질것--
}

void skill::rage()														//분노
{
	//_skillNumber = 24;												//스킬넘버

	_name = "분노";														//이름
	_imgName = "rage";													//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -30;
		_imgY = -55;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -25;
	}

	_power = 20;														//위력
	_PP = 20;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::waterGun()													//물대포
{
	//_skillNumber = 25;												//스킬넘버

	_name = "물대포";													//이름
													

	if (!_isWhoSkill)
	{
		_imgName = "mywaterGun";

		_imgX = -250;
		_imgY = -75;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildwaterGun";

		_imgX = -60;
		_imgY = -110;
	}

	_power = 40;														//위력
	_PP = 25;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::SPECIAL;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::WATER);					//타입
}

void skill::harden()													//단단해지기
{
	//_skillNumber = 26;												//스킬넘버

	_name = "단단해지기";												//이름
	_imgName = "harden";													//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -320;
		_imgY = 200;

	}

	if (_isWhoSkill)
	{
		_imgX = 350;
		_imgY = -200;
	}

	_power = NULL;														//위력
	_PP = 30;															//PP
	_accuracy = NULL;													//명중률
	_ifcation = CLASSIFCATION::CHANGE;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::scratch()													//할퀴기
{
	//_skillNumber = 27;												//스킬넘버

	_name = "할퀴기";													//이름
	_imgName = "scratch";												//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -25;
		_imgY = -25;

	}

	if (_isWhoSkill)
	{
		_imgX = 25;
		_imgY = 0;
	}

	_power = 40;														//위력
	_PP = 35;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::furyAttack()												//마구찌르기
{
	//_skillNumber = 28;												//스킬넘버

	_name = "마구찌르기";												//이름
	
	if (!_isWhoSkill)
	{
		_imgName = "myhorn";

		_imgX = -150;
		_imgY = 70;

	}

	if (_isWhoSkill)
	{
		_imgName = "wildhorn";

		_imgX = 150;
		_imgY = -70;
	}

	_power = 15;														//위력
	_PP = 20;															//PP
	_accuracy = 85;														//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}
		
void skill::bind()														//조이기
{
	//_skillNumber = 29;												//스킬넘버

	_name = "조이기";													//이름
	_imgName = "bind";													//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -75;
		_imgY = -25;

	}

	if (_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -25;
	}

	_power = 15;														//위력
	_PP = 20;															//PP
	_accuracy = 85;														//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::NOMAL);					//타입
}

void skill::bite()
{
	//_skillNumber = 30;												//스킬넘버

	_name = "물기";														//이름
	_imgName = "snap";													//이미지이름

	if (!_isWhoSkill)
	{
		_imgX = -50;
		_imgY = -50;

	}

	if (_isWhoSkill)
	{
		_imgX = 0;
		_imgY = -25;
	}
	
	
	_power = 60;														//위력
	_PP = 25;															//PP
	_accuracy = 100;													//명중률
	_ifcation = CLASSIFCATION::PHYSICS;									//분류
	_skilltype = static_cast<int>(SKILL_TYPE::DARK);					//타입
}


void skill::render()
{
	if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	야생일시
	if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	플레이어 일시
	

	char str[128];

	//if (!_isWhoSkill) _imgPoint = { 450 + _imgX ,70 + _imgY };		//	야생일시
	//else if (_isWhoSkill) _imgPoint = { 100 + _imgX,250 + _imgY };		//	플레이어 일시

	
	if (_isSkill) IMAGEMANAGER->frameRender(_imgName, getMemDC(), _imgPoint.x, _imgPoint.y, _currentFrame, 0);



	//sprintf_s(str, "좌표x : %d ", _imgX);
	//TextOut(getMemDC(), 50, 150, str, strlen(str));
	//sprintf_s(str, "좌표y : % d ", _imgY);
	//TextOut(getMemDC(), 50, 170, str, strlen(str));
	//sprintf_s(str, "상태 : %d ", _isWhoSkill);
	//TextOut(getMemDC(), 50, 190, str, strlen(str));


}

void skill::skillAni()
{

	// 스킬 애니메이션을 돌릴곳 공격은 턴제이기 때문에 isSkill이라는 값을 주어서 껏다 켯다 해야할거 같음
	// isSkill이 true 값일때 이미지가 뜨고 애니메이션이 끝나면 isSkill이 false값이 되는게 나의 생각
	// 애니메이션이 돌아갈곳이 일단 필요하다.

	if (_isSound)
	{
		switch (_skillIndex)
		{
		case 0:
			skillNone();
			break;
		case 1:
			tackle();
			SOUNDMANAGER->play("몸통박치기", 0.01f * UIMANAGER->getVolume());
			break;
		case 2:
			stringShot();
			break;
		case 3:
			confusion();
			break;
		case 4:
			poisonPowder();
			break;
		case 5:
			stunSpore();
			break;
		case 6:
			sleepPowder();
			break;
		case 7:
			poisonSting();
			break;
		case 8:
			focusEnergy();
			break;
		case 9:
			twineedle();
			break;
		case 10:
			sandAttack();
			break;
		case 11:
			gust();
			break;
		case 12:
			quickAttack();
			break;
		case 13:
			wingAttack();
			break;
		case 14:
			tailWhip();
			break;
		case 15:
			peck();
			break;
		case 16:
			growl();
			break;
		case 17:
			leer();
			break;
		case 18:
			thunderShock();
			break;
		case 19:
			thunderbolt();
			break;
		case 20:
			razorLeaf();
			break;
		case 21:
			reflect();
			break;
		case 22:
			smokescreen();
			break;
		case 23:
			ember();
			break;
		case 24:
			rage();
			break;
		case 25:
			waterGun();
			break;
		case 26:
			harden();
			break;
		case 27:
			scratch();
			break;
		case 28:
			furyAttack();
			break;
		case 29:
			bind();
			break;
		case 30:
			bite();
		}
	}

	_isSound = false;

	if (_isSkill)	//스킬이 활성화 됬을시
	{	
		

		_frameCount++;		//프레임 돌릴거
		_count++;			//일정시간뒤에 꺼지게 할려고

		if (_frameCount % 4 == 0)	//속도 조정 조정안되는거 같습니다.
		{
			_currentFrame++; //현재프레임 재생중

			//IMAGEMANAGER->findImage(_imgName)->setFrameX(IMAGEMANAGER->findImage(_imgName)->getFrameX() + 1);


			if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count < 30)		//일단은 예비이미지 파이어 불러오기 && 일정시간이 200count가 흐르면
			{
				_currentFrame = 0;					//프레임을 초기화 시켜 계속 이미지를 반복시키고
			}
			else if (_currentFrame > IMAGEMANAGER->findImage(_imgName)->getMaxFrameX() && _count > 30)		//맥스프레임이고 카운터가 200이상이면 끝나면 이미지를 끝낸다.
			{
				_isSkill = false;					//조건에 맞으면 스킬을 비활성화 시켜서 이미지를 지우고
				_count = 0;							//카운터를 다시 초기화 시켜준다
				_currentFrame = 0;					//현재프레임도 초기화

				// 배틀 진행
				if (UIMANAGER->getAttackCount() < 2)
				{

					UIMANAGER->setIsNext(true);
					UIMANAGER->setIsScript(true);
					UIMANAGER->setIsCount(true);
					UIMANAGER->setIsTurn(false);
				}

				else if (UIMANAGER->getAttackCount() > 1)
				{
					UIMANAGER->setIsAttack(false);
					UIMANAGER->setAttackCount(0);
				}
			}
		}
	}
}

void skill::imageInit()	//스킬 이미지
{
	IMAGEMANAGER->addFrameImage("attack", "image/skill/attack.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bind", "image/skill/bind.bmp", 2880, 180, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut", "image/skill/cut.bmp", 1440, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire", "image/skill/fire.bmp", 176, 100, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("growth", "image/skill/growth.bmp", 2400, 150, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myhorn", "image/skill/myhorn.bmp", 900, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildhorn", "image/skill/wildhorn.bmp", 900, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("attack3", "image/skill/attack3.bmp", 192, 64, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cut3", "image/skill/cut3.bmp", 144, 36, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lightScreen", "image/skill/lightScreen.bmp", 1500, 210, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("move", "image/skill/move.bmp", 440, 112, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poison", "image/skill/poison.bmp", 7680, 200, 32, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shine", "image/skill/shine.bmp", 418, 38, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shock", "image/skill/shock.bmp", 138, 42, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snap", "image/skill/snap.bmp", 3840, 160, 24, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("spark", "image/skill/spark.bmp", 1200, 150, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("squall", "image/skill/squall.bmp", 4300, 114, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("slash", "image/skill/slash.bmp", 480, 60, 43, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skyAttack", "image/skill/skyAttack.bmp", 600, 70, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mysmokescreen", "image/skill/mysmokescreen.bmp", 5200, 280, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildsmokescreen", "image/skill/wildsmokescreen.bmp", 8060, 400, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("razonWind", "image/skill/razonWind.bmp", 1456, 112, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("confuseRay", "image/skill/confuseRay.bmp", 312, 78, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mystringShot", "image/skill/mystringShot.bmp", 5940, 150, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildstringShot", "image/skill/wildstringShot.bmp", 5940, 235, 18, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myconfusion", "image/skill/myconfusion.bmp", 1680, 160, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildconfusion", "image/skill/wildconfusion.bmp", 1680, 160, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mypoisonSting", "image/skill/mypoisonSting.bmp", 450, 90, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildpoisonSting", "image/skill/wildpoisonSting.bmp", 450, 90, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mysandAttack", "image/skill/mysandAttack.bmp", 2750, 198, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildsandAttack", "image/skill/wildsandAttack.bmp", 2750, 198, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myquickAttack", "image/skill/myquickAttack.bmp", 6360, 340, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildquickAttack", "image/skill/wildquickAttack.bmp", 7440, 400, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wingAttack", "image/skill/wingAttack.bmp", 1600, 80, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tailWhip", "image/skill/tailWhip.bmp", 1260, 190, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mygrowl", "image/skill/mygrowl.bmp", 1360, 280, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildgrowl", "image/skill/wildgrowl.bmp", 1360, 280, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myleer", "image/skill/myleer.bmp", 2310, 200, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildleer", "image/skill/wildleer.bmp", 2310, 200, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("thunderShock", "image/skill/thunderShock.bmp", 2860, 260, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("scratch", "image/skill/scratch.bmp", 1040, 130, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("harden", "image/skill/harden.bmp", 540, 90, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rage", "image/skill/rage.bmp", 570, 170, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myrazorLeaf", "image/skill/myrazorLeaf.bmp", 9920, 400, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildrazorLeaf", "image/skill/wildrazorLeaf.bmp", 9920, 400, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mywaterGun", "image/skill/mywaterGun.bmp", 4200, 260, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildwaterGun", "image/skill/wildwaterGun.bmp", 4200, 260, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("myember", "image/skill/myember.bmp", 4300, 300, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wildember", "image/skill/wildember.bmp", 4300, 300, 10, 1, true, RGB(255, 0, 255));


}

void skill::skillNumLink(int index)		// 스킬을 스킬넘버와 연결 해서 넘겨줌?
{	
	switch (index)
	{
	case 0:
		skillNone();
		break;
	case 1:
		tackle();
		break;
	case 2:
		stringShot();
		break;
	case 3:
		confusion();
		break;
	case 4:
		poisonPowder();
		break;
	case 5:
		stunSpore();
		break;
	case 6:
		sleepPowder();
		break;
	case 7:
		poisonSting();
		break;
	case 8:
		focusEnergy();
		break;
	case 9:
		twineedle();
		break;
	case 10:
		sandAttack();
		break;
	case 11:
		gust();
		break;
	case 12:
		quickAttack();
		break;
	case 13:
		wingAttack();
		break;
	case 14:
		tailWhip();
		break;
	case 15:
		peck();
		break;
	case 16:
		growl();
		break;
	case 17:
		leer();
		break;
	case 18:
		thunderShock();
		break;
	case 19:
		thunderbolt();
		break;
	case 20:
		razorLeaf();
		break;
	case 21:
		reflect();
		break;
	case 22:
		smokescreen();
		break;
	case 23:
		ember();
		break;
	case 24:
		rage();
		break;
	case 25:
		waterGun();
		break;
	case 26:
		harden();
		break;
	case 27:
		scratch();
		break;
	case 28:
		furyAttack();
		break;
	case 29:
		bind();
		break;
	case 30:
		bite();
	}

}
