// 0413418.cpp : �w�q�D���x���ε{�����i�J�I�C
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
