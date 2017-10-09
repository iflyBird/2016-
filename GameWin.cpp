#include "StdAfx.h"
#include "GameWin.h"

GameWin::GameWin()																																																								   
{
}


GameWin::~GameWin()
{
}

BOOL GameWin::Create()
{
	g_hWindow = XWnd_CreateWindow(0, 0, 580, 434, L"��Ծ������");
	if (g_hWindow)
	{
		//	HELE hStatic = XStatic_Create(300, 100, 100, 20, L"��̬�ı�����", g_hWindow);
		// 	HFONTX font = XFont_Create2(L"����", 40, TRUE, TRUE, TRUE, TRUE);												    
		// 	XEle_SetFont(hStatic, font);
		// 	XStatic_AdjustSize(hStatic);
		//		HELE hEdit = XEdit_Create(10, 10, 200, 60, g_hWindow);
		//		XEle_SetFont(hEdit, font);
		XWnd_EnableMaxButton(g_hWindow,FALSE);	 	//��󻯰�ť
		XWnd_EnableMinButton(g_hWindow,FALSE);	   //��С����ť
		//       XWnd_EnableCloseButton(g_hWindow,false)  ;//�رհ�ť




		//����jif����
		XWnd_SetBorderSize(g_hWindow,0,0,0,0);
		HELE a=XGif_Create	(0,0,580,406,g_hWindow);
		XGif_SetImage(a,L"img\\005.gif");


		//	XWnd_SetImageNC(g_hWindow, XImage_LoadFile(L"img\\004.jpg", TRUE)); // ���ñ���ͼ
		// �������ֺ�����
		hStatic = XStatic_Create(200, 20, 220, 50, L"��Ծ�ݴ���", g_hWindow); // ����
		XEle_SetBkTransparent(hStatic, TRUE); // ����Ԫ�ر���͸��
		XEle_SetTextColor(hStatic, RGB(0, 0, 160)); // ����Ԫ��������ɫ
		//HFONTX font = XFont_Create(40); // ��������
		HFONTX font2 = XFont_Create2(L"΢���ź�", 42,true, true, true, false);	 
		XEle_SetFont(hStatic, font2); // ����Ԫ������
		//XStatic_AdjustSize(hStatic); // �����ı������Զ�������̬�ı�Ԫ�صĳߴ�

		  
		hBtnTest = XBtn_Create(224, 200, 133, 40, L"��ʼ��Ϸ", g_hWindow);
		XEle_SetFont(hBtnTest, XFont_Create2(L"΢���ź�", 28,true, false, false, false));
		XEle_SetTextColor(hBtnTest, RGB(0, 200,0)); // ����Ԫ��������ɫ
		XBtn_SetImageLeave(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XBtn_SetImageStay(hBtnTest, XImage_LoadFile(L"img\\btn2.png", TRUE));
		XBtn_SetImageDown(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XEle_SetBkTransparent(hBtnTest,true);
		


		//�������Ͻ�ͼƬ	 
		//XWnd_SetImageNC(g_hWindow, XImage_LoadFile(L"img\\005.gif", TRUE));
		HELE hPic = XPic_Create(622, 0, 160, 160, g_hWindow);
		XPic_SetImage(hPic, XImage_LoadFile(L"img\\003.jpg", TRUE));
		XEle_SetBkTransparent(hPic, true); 

		//·��
		wchar_t buff[64]={0};
		for(int i=0;i<21;i++){
			wsprintf(buff,L"img\\RUN\\%d.png",i+1);
			runMan[i]=XImage_LoadFile(buff,false);
			XImage_EnableAutoDestroy(runMan[i],false);
		}

		// 2. ����  ���ڶ�����������֣�
		mciSendString(L"open music\\001.mp3 alias m2", NULL, 0, NULL);
		mciSendString(L"play m2 repeat", NULL, 0, NULL);

		XWnd_ShowWindow(g_hWindow, SW_SHOW);
		XCGUI_RegEleEvent(hBtnTest, XE_BNCLICK, &GameWin::StartGame); //ע�Ὺʼ��Ϸ��ť
		return TRUE;
	}
	return FALSE;
}

BOOL GameWin::WndTimer(HWINDOW hWindow, UINT_PTR nIDEvent, UINT uElapse)
{
	if( nIDEvent==1){
		score++;
		//
		wchar_t buff[32];
		wsprintf(buff,L"����:%d",score*2);
		XStatic_SetText(showScore,buff);

		//Сè����
		static int index = 0;
		XPic_SetImage(m_hPicPat, runMan[index]);
		index++;
		index = index % 21;

		//�ƶ����� 
		RECT rc1,rc2;
		XEle_GetRect(road1, &rc1);
		XEle_GetRect(road2, &rc2);

		const int step=2;

		rc1.left-=step;
		rc1.right-=step;
		rc2.left-=step;
		rc2.right-=step;
		if(rc1.right<=0){
			rc1.left=rc2.right;
			rc1.right=rc1.left+580;
		}
		if(rc2.right<=2){
			rc2.left=rc1.right;
			rc2.right=rc2.left+580;
		}
		XEle_SetRect(road1, &rc1);
		XEle_SetRect(road2, &rc2);
		XWnd_RedrawWnd(hWindow, TRUE);
	}	

	if(nIDEvent==2){
		if(jump){																								    
			RECT rc;

			time++;
			double t=time/5.0;
			double H=60.0*t-5.0*t*t;
			XEle_GetRect(m_hPicPat, &rc);

			rc.top=320-H;
			rc.bottom=320+119-H;

			if(rc.right<575){
				rc.left+=2;
				rc.right+=2;
			}

			if(H<0){
				rc.top=320;
				rc.bottom=320+72;
				jump=false;
				time=0;
			}

			XEle_SetRect(m_hPicPat, &rc);
			XWnd_RedrawWnd(hWindow, TRUE);

		}
	}
	return FALSE;
}

BOOL GameWin::WndKeyDown(HWINDOW hWindow, WPARAM wParam, LPARAM lParam)
{
	RECT rc,rc1;
	XEle_GetRect(m_hPicPat, &rc);

	if((int)wParam==VK_SPACE/*&&rc.top>250*/){
		jump=true;
	}


	int step = 20;
	switch ((int)wParam)
	{
	case VK_LEFT:
		rc.left -= step;
		rc.right -= step;
		break;
	case VK_RIGHT:
		rc.left += step;
		rc.right += step;
		break;
	}
	if(rc.left>0&&rc.right<580){
		XEle_SetRect(m_hPicPat, &rc);
		XWnd_RedrawWnd(hWindow, TRUE);
	}
	return FALSE;
}		

BOOL GameWin::StartGame(HELE hEle, HELE hEventEle){
	showScore=XStatic_Create(10,10,200,30,NULL,this->g_hWindow);
	XEle_SetBkTransparent(showScore, TRUE); // ����Ԫ�ر���͸��
	XEle_SetTextColor(showScore, RGB(150, 150, 150)); // ����Ԫ��������ɫ
	XEle_SetFont(showScore, XFont_Create2(L"΢���ź�", 26,1, 0, 0, 0)); // ����Ԫ������
	XStatic_SetText(showScore,L"����:");

	road1=XPic_Create(0,285,580,120,g_hWindow);
	road2=XPic_Create(580,285,580,120,g_hWindow);
	XPic_SetImage(road1,XImage_LoadFile(L"img\\road.png",false));
	XPic_SetImage(road2,XImage_LoadFile(L"img\\road.png",false));


	//����С����
	m_hPicPat = XPic_Create(20, 320 , 72, 72, g_hWindow);
	XEle_SetBkTransparent(m_hPicPat, TRUE);
	score=0;
	time=0;
	jump =false;
	XEle_ShowEle(hBtnTest,false);
	XEle_ShowEle(hStatic,false);

	XCGUI_RegWndMessage(g_hWindow, WM_TIMER, &GameWin::WndTimer); // ע�ᶨʱ���¼��ص�
	XWnd_SetTimer(g_hWindow, 1, 20); // ���ö�ʱ�����ڶ��������Ƕ�ʱ����id��������������ʱ���������뵥λ	 //��һ��ע��ʱ�为��������ﶯ������
	XWnd_SetTimer(g_hWindow, 2, 10); // ���ö�ʱ�����ڶ��������Ƕ�ʱ����id��������������ʱ���������뵥λ	  //�ڶ���ע����Ǹ���С�����������
	XCGUI_RegWndMessage(g_hWindow, WM_KEYDOWN, &GameWin::WndKeyDown); // ע����̰�����Ϣ�ص�
	return false;
}