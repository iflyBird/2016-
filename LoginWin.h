#pragma once
#include "GameWin.h"

class LoginWin :
	public CXEventMsg
{
public:	
	HELE	 name,pw1,pw2,d,hBtnTest,m_hList;
	HWINDOW m_hWindow;
	/*GameWin MyGame;*/
	GameWin MyGame;
	BOOL Create();


	std::string  str1,str2;
	BOOL OnBtnTestClick(HELE hEle, HELE hEventEle);
	//BOOL OnListSelect(HELE hEle, HELE hEventEle, int index);

	LoginWin(void);
	~LoginWin(void);
};



