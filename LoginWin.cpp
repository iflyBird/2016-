#include "StdAfx.h"
#include "LoginWin.h"



//�ж�ע��ɹ�����ʧ�ܡ�(���õ���������)		
bool operator==(const std::string &a,const std::string &bb)	 {
	if(a.size()==bb.size()){
		for(int i=0;i<a.size();i++){
			if(a[i]!=bb[i]){
				return false;
			} 
		}
		return true;
	}
	return false;
}		   


LoginWin::LoginWin(void)
{
}


LoginWin::~LoginWin(void)
{
}

BOOL LoginWin::Create()
{
	m_hWindow = XWnd_CreateWindow(0, 0, 580,434 , L"GAME");
	if (m_hWindow)
	{
		// ���ô��ڵ���ʽ
		XWnd_SetBorderSize(m_hWindow, 0, 0, 0, 0); // ���ñ߿�ߴ�
		XWnd_SetCaptionHeight(m_hWindow, 30); // ���ñ������߶�
		XWnd_EnableMinButton(m_hWindow, true); // �ر���С����ť
		XWnd_EnableMaxButton(m_hWindow, true); // �ر���󻯰�ť
		XWnd_EnableCloseButton(m_hWindow, true); // �ر� �رհ�ť
		XWnd_EnableDragWindow(m_hWindow, true); // ���� �϶�����

		//����gif����
		XWnd_SetBorderSize(m_hWindow,0,0,0,0);
		HELE a=XGif_Create	(0,0,580,434,m_hWindow);
		XGif_SetImage(a,L"img\\009.gif");
	

		//���þ�̬�ı�Ԫ��

		HELE hStatic = XStatic_Create(125, 20, 240, 40, L"��ӭ���������ȳ���԰", m_hWindow); // ����
		XEle_SetBkTransparent(hStatic, TRUE); // ����Ԫ�ر���͸��
		XEle_SetTextColor(hStatic, RGB(0, 0, 160)); // ����Ԫ��������ɫ
		//HFONTX font = XFont_Create(40); // ��������
		HFONTX font2 = XFont_Create2(L"΢���ź�", 42,true, true, true, true);
		XEle_SetFont(hStatic, font2); // ����Ԫ������
		XStatic_AdjustSize(hStatic); // �����ı������Զ�������̬�ı�Ԫ�صĳߴ�
		HELE b = XStatic_Create(200, 80, 200, 40, L"�ǳ�", m_hWindow); // �����ǳ��ı�
		HELE c = XStatic_Create(195, 120, 200, 40, L"����", m_hWindow); // ���������ı�
		HELE d= XStatic_Create(180, 160, 200, 40, L"ȷ������", m_hWindow); // ����ȷ�������ı�
		


		XEle_SetBkTransparent(b, TRUE); // ����Ԫ�ر���͸��
		XEle_SetTextColor(b, RGB(128, 0, 0)); // ����Ԫ��������ɫ
		//HFONTX font = XFont_Create(40); // ��������
		HFONTX font6 = XFont_Create2(L"΢���ź�", 24,true, true, true, true);
		XEle_SetFont(b, font6); // ����Ԫ������
		XStatic_AdjustSize(b); // �����ı������Զ�������̬�ı�Ԫ�صĳߴ�

		XEle_SetBkTransparent(c, true); // ����Ԫ�ر���͸��
		XEle_SetTextColor(c, RGB(128, 0, 0)); // ����Ԫ��������ɫ
		//HFONTX font = XFont_Create(40); // ��������
		HFONTX font5= XFont_Create2(L"΢���ź�", 24,true, true, true, true);
		XEle_SetFont(c, font5); // ����Ԫ������
		XStatic_AdjustSize(c); // �����ı������Զ�������̬�ı�Ԫ�صĳߴ�




		XEle_SetBkTransparent(d, TRUE); // ����Ԫ�ر���͸��
		XEle_SetTextColor(d, RGB(128, 0, 0)); // ����Ԫ��������ɫ
		//HFONTX font = XFont_Create(40); // ��������
		HFONTX font4= XFont_Create2(L"΢���ź�", 24,true, true, true, true);
		XEle_SetFont(d, font4); // ����Ԫ������
		XStatic_AdjustSize(d); // �����ı������Զ�������̬�ı�Ԫ�صĳߴ�



		//���ñ༭���С(�ǳ�)
		name= XEdit_Create(250, 80, 200, 30, m_hWindow);
	//	XEdit_EnablePassBox(name, TRUE); // �༭��Ԫ�������������빦��,����ֻ�ܵ�������
		XEle_SetBkTransparent(name, TRUE); // ���ڱ༭���б�������Ԫ����˵������͸����Ҫ����
		XEle_SetBkTransparent(XSView_GetView(name), true); // ����Ԫ�ر���͸��+�ڲ�������ͼ����͸��
		XEle_SetTextColor(name, RGB(0, 0, 255))  ;

		//���ñ༭���С(����)
		pw1= XEdit_Create(250, 120, 200, 30, m_hWindow); 
		XEdit_EnablePassBox(pw1, TRUE); // �༭��Ԫ�������������빦��,����ֻ�ܵ�������
		XEle_SetBkTransparent(pw1, TRUE); // ���ڱ༭���б�������Ԫ����˵������͸����Ҫ����
		XEle_SetBkTransparent(XSView_GetView(pw1), true); // ����Ԫ�ر���͸��+�ڲ�������ͼ����͸��
		XEle_SetTextColor(pw1, RGB(0, 0, 255));


		//���ñ༭���С(ȷ������)
		pw2= XEdit_Create(250, 160, 200, 30, m_hWindow);
		XEdit_EnablePassBox(pw2, TRUE); // �༭��Ԫ�������������빦��,����ֻ�ܵ�������
		XEle_SetBkTransparent(pw2, TRUE); // ���ڱ༭���б�������Ԫ����˵������͸����Ҫ����
		XEle_SetBkTransparent(XSView_GetView(pw2), true); // ����Ԫ�ر���͸��+�ڲ�������ͼ����͸��
		XEle_SetTextColor(pw2, RGB(0, 0, 255));

		//����ע�ᰴť   
		hBtnTest = XBtn_Create(390, 200, 60, 40, L"ע��", m_hWindow);
		XEle_SetFont(hBtnTest, XFont_Create2(L"΢���ź�", 28,true, false, false, false));
		XEle_SetTextColor(hBtnTest, RGB(0, 200,0)); // ����Ԫ��������ɫ
		XBtn_SetImageLeave(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XBtn_SetImageStay(hBtnTest, XImage_LoadFile(L"img\\btn2.png", TRUE));
		XBtn_SetImageDown(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XEle_SetBkTransparent(hBtnTest,true);
		  //��һ���������������
		XCGUI_RegEleEvent(hBtnTest, XE_BNCLICK, &LoginWin:: OnBtnTestClick); 
		mciSendString(L"open music\\12.mp3 alias m1", NULL, 0, NULL);
		mciSendString(L"play m1 repeat", NULL, 0, NULL);


		//��ʾ����
		XWnd_ShowWindow(m_hWindow, SW_SHOW);

	}
	return false;
}


BOOL LoginWin::OnBtnTestClick(HELE hEle, HELE hEventEle){

	wchar_t wzText2[64]={0},wzText1[64]={0};

	XEdit_GetText(pw1, wzText1, 64);
	str1= XCUtil::Wchart2string(wzText1);

	XEdit_GetText(pw2, wzText2, 64);
	str2 = XCUtil::Wchart2string(wzText2);

	if(str1==str2){
		XMessageBox(hEle, L"ע��ɹ����ڵ�¼��..............",L" ��ʾ, ",XMB_OK);
		mciSendString(L"stop m1", NULL, 0, NULL);
		mciSendString(L"close m1", NULL, 0, NULL);
		XWnd_CloseWindow  (m_hWindow); //	   ע��ɹ�����������
		
		
		if(MyGame.Create()) return true;
	
	} else{
		XMessageBox(hEle, L"ע��ʧ��", L"��ʾ��", XMB_OK);
		XMessageBox(hEle, L"ǰ�����벻һ��,���ٴ��������롣", L"��ʾ��", XMB_OK);
	}

	

	return FALSE;

}

