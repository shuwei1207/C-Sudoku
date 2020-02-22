// 0413418.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include "kernel.h"



int _tmain(int argc, _TCHAR* argv[])
{
	kernel x;
	x.read("Question3.txt");
	x.printQ();
	x.solve();
	x.printA();
	return 0;
}
