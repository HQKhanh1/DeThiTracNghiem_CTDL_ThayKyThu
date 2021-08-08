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
//	for(int i = 0; i < 256; i++){
//		gotoxy(0,i);
//		TextColor(i);
//		cout<<"Mau: "<<i<<" @@@@@@@@@@@@";
//	}
//	system("pause");
	TextColor(9);
	mainProcess(dsl,ds,dsm,arr1,arr2);
	return 0;
}
