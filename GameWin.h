#pragma once

class GameWin :
	public CXEventMsg
{
public:
	GameWin(void);
	~GameWin(void);

	HWINDOW g_hWindow;
	HELE m_hPicPat,hBtnTest;
	HIMAGE runMan[21];

	HELE road1,road2;
	HELE hStatic ;
	HELE showScore;

	long score;


	bool jump;
	int time;
	BOOL StartGame(HELE hEle, HELE hEventEle);

	BOOL Create();
	BOOL WndTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse);	 //设置消息框
	BOOL WndKeyDown(HWINDOW hWindow, WPARAM wParam, LPARAM lParam);		   //设置消息框（按键）
};

