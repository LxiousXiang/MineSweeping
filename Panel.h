//
//	Panel class definition
// **NOTE：grid class will be regarded as member of panel class  

#include "Grid.h"

class Panel
{
public:
	Grid grid[10][10];    //将grid作为panel成员，并定义grid二维数组 
	char gridFace[10][10];  //此数组仅用作外部显示 
	void Hello();   //欢迎界面
	void interface(); //显示棋盘
	void initialRandBomb(int , int); //初始化布雷 
	void MarkAllGridNumber();   //标记所有grid.number 
	void openGrid(int , int , int);   //点击格子 
	void displayConditionNow();    //显示目前棋盘每个格子状态 
	void displayEndingPanel();   //游戏结束画面 
	void interation(int , int);  //迭代算法
	void canInteration(int , int); //判断是否具有迭代条件
};
