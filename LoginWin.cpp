#include "StdAfx.h"
#include "LoginWin.h"



//判断注册成功还是失败。(运用到函数重载)		
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
		// 设置窗口的样式
		XWnd_SetBorderSize(m_hWindow, 0, 0, 0, 0); // 设置边框尺寸
		XWnd_SetCaptionHeight(m_hWindow, 30); // 设置标题栏高度
		XWnd_EnableMinButton(m_hWindow, true); // 关闭最小化按钮
		XWnd_EnableMaxButton(m_hWindow, true); // 关闭最大化按钮
		XWnd_EnableCloseButton(m_hWindow, true); // 关闭 关闭按钮
		XWnd_EnableDragWindow(m_hWindow, true); // 启用 拖动窗口

		//设置gif背景
		XWnd_SetBorderSize(m_hWindow,0,0,0,0);
		HELE a=XGif_Create	(0,0,580,434,m_hWindow);
		XGif_SetImage(a,L"img\\009.gif");
	

		//设置静态文本元素

		HELE hStatic = XStatic_Create(125, 20, 240, 40, L"欢迎来到机电萌宠乐园", m_hWindow); // 创建
		XEle_SetBkTransparent(hStatic, TRUE); // 设置元素背景透明
		XEle_SetTextColor(hStatic, RGB(0, 0, 160)); // 设置元素文字颜色
		//HFONTX font = XFont_Create(40); // 创建字体
		HFONTX font2 = XFont_Create2(L"微软雅黑", 42,true, true, true, true);
		XEle_SetFont(hStatic, font2); // 设置元素字体
		XStatic_AdjustSize(hStatic); // 根据文本内容自动调整静态文本元素的尺寸
		HELE b = XStatic_Create(200, 80, 200, 40, L"昵称", m_hWindow); // 创建昵称文本
		HELE c = XStatic_Create(195, 120, 200, 40, L"密码", m_hWindow); // 创建密码文本
		HELE d= XStatic_Create(180, 160, 200, 40, L"确认密码", m_hWindow); // 创建确认密码文本
		


		XEle_SetBkTransparent(b, TRUE); // 设置元素背景透明
		XEle_SetTextColor(b, RGB(128, 0, 0)); // 设置元素文字颜色
		//HFONTX font = XFont_Create(40); // 创建字体
		HFONTX font6 = XFont_Create2(L"微软雅黑", 24,true, true, true, true);
		XEle_SetFont(b, font6); // 设置元素字体
		XStatic_AdjustSize(b); // 根据文本内容自动调整静态文本元素的尺寸

		XEle_SetBkTransparent(c, true); // 设置元素背景透明
		XEle_SetTextColor(c, RGB(128, 0, 0)); // 设置元素文字颜色
		//HFONTX font = XFont_Create(40); // 创建字体
		HFONTX font5= XFont_Create2(L"微软雅黑", 24,true, true, true, true);
		XEle_SetFont(c, font5); // 设置元素字体
		XStatic_AdjustSize(c); // 根据文本内容自动调整静态文本元素的尺寸




		XEle_SetBkTransparent(d, TRUE); // 设置元素背景透明
		XEle_SetTextColor(d, RGB(128, 0, 0)); // 设置元素文字颜色
		//HFONTX font = XFont_Create(40); // 创建字体
		HFONTX font4= XFont_Create2(L"微软雅黑", 24,true, true, true, true);
		XEle_SetFont(d, font4); // 设置元素字体
		XStatic_AdjustSize(d); // 根据文本内容自动调整静态文本元素的尺寸



		//设置编辑框大小(昵称)
		name= XEdit_Create(250, 80, 200, 30, m_hWindow);
	//	XEdit_EnablePassBox(name, TRUE); // 编辑框元素启用输入密码功能,密码只能单行输入
		XEle_SetBkTransparent(name, TRUE); // 对于编辑框、列表这样的元素来说，设置透明需要两步
		XEle_SetBkTransparent(XSView_GetView(name), true); // 本身元素背景透明+内部滚动视图背景透明
		XEle_SetTextColor(name, RGB(0, 0, 255))  ;

		//设置编辑框大小(密码)
		pw1= XEdit_Create(250, 120, 200, 30, m_hWindow); 
		XEdit_EnablePassBox(pw1, TRUE); // 编辑框元素启用输入密码功能,密码只能单行输入
		XEle_SetBkTransparent(pw1, TRUE); // 对于编辑框、列表这样的元素来说，设置透明需要两步
		XEle_SetBkTransparent(XSView_GetView(pw1), true); // 本身元素背景透明+内部滚动视图背景透明
		XEle_SetTextColor(pw1, RGB(0, 0, 255));


		//设置编辑框大小(确认密码)
		pw2= XEdit_Create(250, 160, 200, 30, m_hWindow);
		XEdit_EnablePassBox(pw2, TRUE); // 编辑框元素启用输入密码功能,密码只能单行输入
		XEle_SetBkTransparent(pw2, TRUE); // 对于编辑框、列表这样的元素来说，设置透明需要两步
		XEle_SetBkTransparent(XSView_GetView(pw2), true); // 本身元素背景透明+内部滚动视图背景透明
		XEle_SetTextColor(pw2, RGB(0, 0, 255));

		//设置注册按钮   
		hBtnTest = XBtn_Create(390, 200, 60, 40, L"注册", m_hWindow);
		XEle_SetFont(hBtnTest, XFont_Create2(L"微软雅黑", 28,true, false, false, false));
		XEle_SetTextColor(hBtnTest, RGB(0, 200,0)); // 设置元素文字颜色
		XBtn_SetImageLeave(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XBtn_SetImageStay(hBtnTest, XImage_LoadFile(L"img\\btn2.png", TRUE));
		XBtn_SetImageDown(hBtnTest, XImage_LoadFile(L"img\\btn1.png", TRUE));
		XEle_SetBkTransparent(hBtnTest,true);
		  //第一个界面的音乐设置
		XCGUI_RegEleEvent(hBtnTest, XE_BNCLICK, &LoginWin:: OnBtnTestClick); 
		mciSendString(L"open music\\12.mp3 alias m1", NULL, 0, NULL);
		mciSendString(L"play m1 repeat", NULL, 0, NULL);


		//显示窗口
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
		XMessageBox(hEle, L"注册成功正在登录中..............",L" 提示, ",XMB_OK);
		mciSendString(L"stop m1", NULL, 0, NULL);
		mciSendString(L"close m1", NULL, 0, NULL);
		XWnd_CloseWindow  (m_hWindow); //	   注册成功则跳出界面
		
		
		if(MyGame.Create()) return true;
	
	} else{
		XMessageBox(hEle, L"注册失败", L"提示！", XMB_OK);
		XMessageBox(hEle, L"前后密码不一致,请再次输入密码。", L"提示！", XMB_OK);
	}

	

	return FALSE;

}

