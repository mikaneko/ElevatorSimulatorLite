#include "stdafx.h"
#include "CMainView.h"
#include "CMainDoc.h"

IMPLEMENT_DYNCREATE(CMainView,CView)

CMainView::CMainView()
{

}
CMainView::~CMainView()
{

}

void CMainView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类

	CMainDoc* pDoc=(CMainDoc*)GetDocument();
	///fj

		// TODO: 在此添加专用代码和/或调用基类
	CPen pen(PS_SOLID,0,RGB(0,0,0));
	CPen * oldPen;
	oldPen=pDC->SelectObject(&pen);
	CBrush brush;
	//brush.CreateHatchBrush(HS_BDIAGONAL,RGB(255,165,0));
	brush.CreateSolidBrush(RGB(255,165,0));
	CBrush * oldBrush=pDC->SelectObject(&brush);
	pDC->SetBkMode(0);


	//楼层上下按钮显示
	pDC->SelectObject(oldBrush);

	pDC->Rectangle(CRect(25,15,195,285));
	for(int i=1;i<=8;i++) {
		pDC->MoveTo(25,15+30*i);
		pDC->LineTo(195,15+30*i);
	} 
	pDC->MoveTo(75,15);
	pDC->LineTo(75,285);
	pDC->MoveTo(135,15);
	pDC->LineTo(135,285);//格子框架

	pDC->SelectObject(&brush);
	for(int i=0;i<=8;i++) {
		switch(pDoc->elevsys.m_request[i]){
			case ELESYS_DOWN:
				pDC->Rectangle(CRect(135,255-30*i,195,285-30*i));
				break;
			case ELESYS_UP:
				pDC->Rectangle(CRect(75,255-30*i,135,285-30*i));
				break;
			case ELESYS_UP_AND_DOWN:{
				pDC->Rectangle(CRect(135,255-30*i,195,285-30*i));
				pDC->Rectangle(CRect(75,255-30*i,135,285-30*i));}
				break;
		}
	} 
	pDC->SelectObject(oldBrush);

	CString txtouttmp;
	for(int i=1;i<=9;i++)  {txtouttmp.Format(TEXT("%d"),i);pDC->TextOut(45,290-30*i,txtouttmp);}//先测试效果

	for(int i=1;i<=9;i++) {
		pDC->MoveTo(155,30*i-5);
		pDC->LineTo(175,30*i-5);
		pDC->LineTo(165,30*i+5);
		pDC->LineTo(155,30*i-5);
	} //右侧【下】按钮

	for(int i=1;i<=9;i++) {
		pDC->MoveTo(95,30*i+5);
		pDC->LineTo(115,30*i+5);
		pDC->LineTo(105,30*i-5);
		pDC->LineTo(95,30*i+5);
	} //左侧【上】按钮



	//电梯图形演示
	pDC->Rectangle(CRect(215,15,575,285));
	for(int i=1;i<=8;i++) {
		pDC->MoveTo(215,15+30*i);
		pDC->LineTo(575,15+30*i);
	} 
	for(int i=1;i<=2;i++) {
		pDC->MoveTo(215+120*i,15);
		pDC->LineTo(215+120*i,285);
	} //格子框架

	pDC->SelectObject(&brush);
	for(int i=0;i<=2;i++) pDC->Rectangle(CRect(215+120*i,
					285-30*(pDoc->elevsys.elev[i]. now_floor_int+(double)pDoc->elevsys.elev[i]. now_floor_point/(pDoc->elevsys).elev[0].M_tick_per_floor),
					335+120*i,
					315-30*(pDoc->elevsys.elev[i]. now_floor_int+(double)pDoc->elevsys.elev[i]. now_floor_point/(pDoc->elevsys).elev[0].M_tick_per_floor)));
	pDC->SelectObject(oldBrush);//电梯位置



	//电梯内按钮显示
	pDC->Rectangle(CRect(15,310,195,496));
	pDC->Rectangle(CRect(210,310,390,496));
	pDC->Rectangle(CRect(405,310,585,496));//框架
	for(int j=0;j<=2;j++){
		
		pDC->Rectangle(CRect(90+195*j,316,120+195*j,346));
		for(int i=1;i<=4;i++) {
			pDC->Rectangle(CRect(60+195*j,316+36*i,90+195*j,346+36*i));
			pDC->Rectangle(CRect(120+195*j,316+36*i,150+195*j,346+36*i));
		}//格子

		pDC->SelectObject(&brush);
		for(int i=1;i<=9;i++){
			if(pDoc->elevsys.elev[j]. m_btn_status[i-1]==ELE_BTN_ON){
				switch(i){
					case 1: case 3: case 5: case 7: pDC->Rectangle(CRect(60+195*j,460-(i-1)/2*36,90+195*j,490-(i-1)/2*36));
					break;
					case 2: case 4: case 6: case 8: pDC->Rectangle(CRect(120+195*j,460-(i-2)/2*36,150+195*j,490-(i-2)/2*36));
					break;
					case 9:pDC->Rectangle(CRect(90+195*j,316,120+195*j,346));
					break;
				}
			}
		}
		pDC->SelectObject(oldBrush);//按钮高亮

		//haixin
		txtouttmp.Format(TEXT("%d"),9);
		pDC->TextOut(100+195*j,321,txtouttmp);
		for(int i=1;i<=4;i++) {
			//zhanghaixin
			txtouttmp.Format(TEXT("%d"),9-i*2);
			pDC->TextOut(70+195*j,321+36*i,txtouttmp);
			txtouttmp.Format(TEXT("%d"),10-i*2);
			pDC->TextOut(130+195*j,321+36*i,txtouttmp);
		}//数字显示
	}

	//ticker

	
	CString timecounter1;
	CString timecounter2;
	timecounter1.Format(TEXT("Tick: %d"),pDoc->tickc);
	timecounter2.Format(TEXT("Sec: %d"),(pDoc->tickc)/(pDoc->ticks_in_second));
	pDC->TextOutW(820,10,timecounter1);
	pDC->TextOutW(820,30,timecounter2);


	CString ele1info;
	ele1info.Format(TEXT("ele[0].now_floor_int: %d"),pDoc->elevsys.elev[0].now_floor_int);
	pDC->TextOutW(680,70,ele1info);
	ele1info.Format(TEXT("ele[0].now_floor_point: %d"),pDoc->elevsys.elev[0].now_floor_point);
	pDC->TextOutW(680,90,ele1info);

	CString ele2info;
	ele1info.Format(TEXT("ele[1].now_floor_int: %d"),pDoc->elevsys.elev[1].now_floor_int);
	pDC->TextOutW(680,110,ele1info);
	ele1info.Format(TEXT("ele[1].now_floor_point: %d"),pDoc->elevsys.elev[1].now_floor_point);
	pDC->TextOutW(680,130,ele1info);

	CString ele3info;
	ele1info.Format(TEXT("ele[2].now_floor_int: %d"),pDoc->elevsys.elev[2].now_floor_int);
	pDC->TextOutW(680,150,ele1info);
	ele1info.Format(TEXT("ele[2].now_floor_point: %d"),pDoc->elevsys.elev[2].now_floor_point);
	pDC->TextOutW(680,170,ele1info);
}
