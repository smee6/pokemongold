#include "poketmon.h"

class spearow : public poketmon
{

private:


public:
	spearow();
	~spearow();

	HRESULT init();
	void release();
	void update();
	void render();
};