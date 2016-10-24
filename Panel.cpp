//
//  That's Panel class come true.
//
//

#include "Panel.h"
#include <iostream>
#include<conio.h>
#include <time.h>
using namespace std;

//全局变量 
extern bool boolgameover = false;
extern int numberOfMarkBomb = 0;
extern int correctMark = 0;


void Panel::Hello()
{
	for(int i=0 ; i<5 ; i++)
		cout<<endl;
	cout<<"                            "<<"*********************"<<endl;
	cout<<"                            "<<"*****扫雷小游戏******"<<endl;
	cout<<"                            "<<"*********************"<<endl;
	cout<<"                            "<<"*********************"<<endl;
	cout<<"注:按任意键进入游戏"<<endl; 
	getch();
	system("cls");
	interface();	
}

void Panel::interface()
{
	for(int i=0 ; i<10 ; i++) //gridFace数组初始化 
		for(int j=0 ;j<10 ; j++)
			gridFace[i][j] = 45;
	displayConditionNow();
}

void Panel::MarkAllGridNumber()
{
	for(int i=0 ; i<10 ; i++)
		for(int j=0 ; j<10 ; j++)
			if(grid[i][j].condition != 2)
			{
			if(i-1>=0 && j-1>=0 && grid[i-1][j-1].condition==2) //上 ，左 
					grid[i][j].numberOfBomb++;
				if(i-1>=0 && j>=0 && grid[i-1][j].condition==2)  //上 ，中 
					grid[i][j].numberOfBomb++;
				if(i-1>=0 && j+1<=9 && grid[i-1][j+1].condition==2) //上 ，右 
					grid[i][j].numberOfBomb++;
				if(j-1>=0 && grid[i][j-1].condition==2)  //左 
					grid[i][j].numberOfBomb++;
				if(j+1<=9 && grid[i][j+1].condition==2)  //右 
					grid[i][j].numberOfBomb++;
				if(i+1<=9 && j-1>=0 && grid[i+1][j-1].condition==2) //下 ，左 
					grid[i][j].numberOfBomb++;
				if(i+1<=9 && j>=0 && grid[i+1][j].condition==2)  //下 ，中 
					grid[i][j].numberOfBomb++;
				if(i+1<=9 && j+1<=9 && grid[i+1][j+1].condition==2) //下 ，右 
					grid[i][j].numberOfBomb++;
			}
	for(int i=0 ; i<10 ; i++)
		for(int j=0 ; j<10 ; j++)
		{
			if(grid[i][j].condition != 2 && grid[i][j].numberOfBomb != 0)
				grid[i][j].condition = grid[i][j].numberOfBomb + 48;
		}
}
// 1翻开  2标记 
void Panel::openGrid(int x , int y , int choose )
{
	if(x<0 || x>9 || y<0 || y>9 || choose<1 || choose>2)
	{
		cout<<"您的输入有误！请重新输入"<<endl;
		return ; 
	}
	
	if(grid[x][y].condition == 2 && choose == 1)  //踩到雷，点开 
	{
		boolgameover = true;
		return ;
	}
	if(grid[x][y].condition == 2 && choose == 2 )  //踩到雷，标记 
		correctMark ++;
	if(correctMark == 10)   //正确标记地雷数目达到10 
	{
		boolgameover = true;
		return ;
	}
	if(choose == 1 && grid[x][y].condition == 0)  //踩到空格，并点开 
	{
		gridFace[x][y] = 0;
		interation(x , y); 
	}
	if(choose == 1 && grid[x][y].condition != 0 && grid[x][y].condition != 2)  //踩到数字，并点开 
		gridFace[x][y] = grid[x][y].condition;
	if(choose == 2)  //标记地雷 
	{
		if(grid[x][y].condition == 2)
			numberOfMarkBomb++;
		gridFace[x][y] = 5;
	}
	system("cls");
	displayConditionNow();
}
void Panel::displayConditionNow()
{
	cout<<"   ";   
	for(int i=0 ; i<10 ; i++)
		cout<<i<<"  ";
	cout<<endl;
	for(int i=0 ; i<10 ; i++)
	{
		cout<<i<<"  ";
		for(int j=0 ; j<10 ;j++)
			cout<<gridFace[i][j]<<"  ";
		cout<<endl;
	}
	cout<<"请输入x , y 坐标 , 并且 输入1表示翻开格子 , 输入2表示标记格子\n"
		<<"按ENTER键结束输入"<<endl;
}
void Panel::displayEndingPanel()
{	
	if(boolgameover == true && correctMark != 10)
	{
	cout<<"    很遗憾，你输了！"<<endl; 
		cout<<"	   您一共标记对了"<<numberOfMarkBomb<<"颗地雷"<<endl;
		cout<<"   ";
	}
	if(correctMark == 10)
	{
		cout<<endl;
		cout<<"    恭喜你 ，你成功扫完了所有的地雷，扫雷胜利"<<endl; 
		cout<<"         特封你为“扫雷小英雄”称号"<<endl;
		cout<<endl; 
		cout<<"   ";
	}
	for(int i=0 ; i<10 ; i++)
		cout<<i<<"  ";
	cout<<endl;
	for(int i=0 ; i<10 ; i++)
	{
		cout<<i<<"  ";
		for(int j=0 ; j<10 ;j++)
			cout<<grid[i][j].condition<<"  ";
		cout<<endl;
	}
}

void Panel::canInteration (int x , int y)
{
	if(grid[x][y].condition == 0)
		grid[x][y].canInteration = true;
}

void Panel::interation(int x , int y) //核心部分，迭代算法 
{ 
	if(x-1>=0) //向上运动
	{
		canInteration(x-1 , y);
		if(grid[x-1][y].condition != 0)   
			gridFace[x-1][y] = grid[x-1][y].condition;
		if(grid[x-1][y].condition == 0 && grid[x-1][y].canInteration == true && gridFace[x-1][y] == 45)
		{
			gridFace[x-1][y] = 0;
			interation(x-1 , y);
		}
	}
	if(x+1<=9) //向下运动
	{
		canInteration(x+1 , y);
		if(grid[x+1][y].condition != 0)   
			gridFace[x+1][y] = grid[x+1][y].condition;
		if(grid[x+1][y].condition == 0 && grid[x+1][y].canInteration == true && gridFace[x+1][y] == 45)
		{
			gridFace[x+1][y] = 0;
			interation(x+1 , y);
		}
	}
	if(y-1>=0) //向左运动
	{
		canInteration(x , y-1);
		if(grid[x][y-1].condition != 0)  
			gridFace[x][y-1] = grid[x][y-1].condition;
		if(grid[x][y-1].condition == 0 && grid[x][y-1].canInteration == true && gridFace[x][y-1] == 45)
		{
			gridFace[x][y-1] = 0;
			interation(x , y-1);
		}
	}
	if(y+1<=9) //向右运动
	{
		canInteration(x , y+1);
		if(grid[x][y+1].condition != 0)
			gridFace[x][y+1] = grid[x][y+1].condition; 
		if(grid[x][y+1].condition == 0 && grid[x][y+1].canInteration == true && gridFace[x][y+1] == 45)
		{
			gridFace[x][y+1] = 0;
			interation(x , y+1);
		}
	}
}

void Panel::initialRandBomb(int x , int y)
{
	for(int i=0 ; i<10 ; i++)  //所有格子初始化 
		for(int j=0 ; j<10 ; j++)
		{
			grid[i][j].canInteration = false;
			grid[i][j].condition = 0;
			grid[i][j].numberOfBomb = 0;
		}
	int count = 0;
	int m , n;
	srand(time(NULL));
	while(count<10)  //给其中10个格子布雷 
	{
		m = rand()%10;
		n = rand()%10;
		if(grid[m][n].condition == 0 && m != x && n != y)
		{
			grid[m][n].condition = 2;
			count++;
		}
	}
}
