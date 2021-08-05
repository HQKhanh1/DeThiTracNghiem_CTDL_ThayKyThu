#include<iostream>
#include<string.h>
#include "struct.h"
#include<fstream>
#include "mylib.h"
#include "function.h"
using namespace std;



int main()
{
	int arr1[4999];
	int arr2[4999];
	taoMangRd(arr1,1,4999);
	taoMangRd(arr2,5001,9999);
	dssv ds;
	dslop dsl;
	DSMH dsm;
	khoiTaoCay(dsm);
//	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
//	system("mode 1080");
//	fullscreen();
//	SetWindowSize(1080,720);
	mainProcess(dsl,ds,dsm,arr1,arr2);
	return 0;
}
