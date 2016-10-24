/**************************************************
*			The small MineSweeping game
*Description: this samll project is based on win32
*		appllication game. It have'n interface And
*		only display in console. This project cont-
*		ained four files , it's a small program for 
*		studying C++ and make me more interested to
*		coding , it's not difficult , number of lin-
*		es a total of 270 line . There must have ma-
*		ny shortcoming , if you have good idea agout
*		it , you can pull it and do it better . If 
*		you are newbie as me and you are benefited 
*		from this small program , it's my honor.
**************************************************/


#include <iostream>
#include<conio.h>
#include "Panel.h"
using namespace std;

//全局变量 
extern bool boolgameover;
extern int numberOfMarkBomb;
extern int correctMark;

int main()
{
	Panel pal;
	pal.Hello();
	int x , y , choose; 
	cin>>x>>y>>choose;   //第一次翻开格子 
	pal.initialRandBomb(x , y);
	pal.MarkAllGridNumber();
	pal.openGrid(x , y , choose);
	do
	{
		cin>>x>>y>>choose;
		pal.openGrid(x , y , choose);
		if(boolgameover)
		{
			system("cls");
			pal.displayEndingPanel();
		}
	}while(!boolgameover);
	cout<<"	 [按任意键退出游戏]"<<endl;
	getch();
	return 0;
}
