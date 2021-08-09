#include<iostream>
#include<string.h>
#include <string>
#define MAXMH 100
#define MAXLOP 500
#define MAXCAUHOI 200
#define STACKSIZE 1000
using namespace std;
struct cauHoi
{
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	string dapAn;
};
typedef struct dsCauHoi {
	int n = 0;
  	cauHoi listCauHoi[MAXCAUHOI]; // danh sach mang 1 chieu
} DSCH;
cauHoi nhapMang(){
	cauHoi ch;
	cout<<"Nhap noi dung(nd bang 1 dung: )";
	getline(cin,ch.noiDung);
	if(ch.noiDung.compare("1") == 0) return ch;
	getline(cin,ch.A);
	getline(cin,ch.B);
	getline(cin,ch.C);
	getline(cin,ch.D);
	getline(cin,ch.dapAn);
	return ch;
}
void showCH(DSCH ds){
	for(int i = 0; i < ds.n; i++){
		cout<<"\nNoi dung: "<<ds.listCauHoi[i].noiDung;
		cout<<"\nA: "<<ds.listCauHoi[i].A;
		cout<<"\nB: "<<ds.listCauHoi[i].B;
		cout<<"\nC: "<<ds.listCauHoi[i].C;
		cout<<"\nD: "<<ds.listCauHoi[i].D;
		cout<<"\nDap An: "<<ds.listCauHoi[i].dapAn<<endl;
	}
}
void nhapCHNhieu(DSCH &ds){
	while(1){
		ds.listCauHoi[ds.n] = nhapMang();
		if(ds.listCauHoi[ds.n].noiDung.compare("1") == 0) break;
		ds.n++;
		
	}
}

