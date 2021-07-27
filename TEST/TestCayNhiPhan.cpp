#include<iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include <thread>
#include <sstream>
#include <Windows.h>
#include"D:\CTDL\DeThiTracNghiem_CTDL_ThayKyThu\mylib.h"
#define MAXMH 100
#define MAXLOP 500
#define MAXCAUHOI 200
#define STACKSIZE 1000
int maxid = 10000;
bool stop = 1;
using namespace std;

//==============================================================================================================
// ===========================================tao cau truc moi===========================================
// DANH SACH CAU HOI THEO DANH SACH TUYEN TINH
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
	int n = 0;;
  	cauHoi *listCauHoi[MAXCAUHOI] = {NULL}; // danh sach mang 1 chieu
} DSCH;
// DANH SACH MON HOC THEO CAY NHI PHAN TIM KIEM
struct monHoc{
	string MAMH;
	string TENMH;
	DSCH cauHoiMH;
};
struct nodeMonHoc{
	int id;
	monHoc mh;
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef struct nodeMonHoc NODE;
typedef NODE* DSMH;
//khoi tao node
NODE *CreateNode(monHoc init)
{
    NODE *p = new NODE;
    p->mh = init;
    p->left = NULL;
    p->right = NULL;
    return p;
}
//khoi tao cay
void khoiTaoCay(DSMH &tree){
	tree = NULL;
}
bool checkFistNode(DSMH p);
//them mon hoc vao dsmh
void themMonHoc(DSMH &tree, monHoc input){
	//cay rong
	if(tree == NULL){
		NODE *p = new NODE;
	    p->mh = input;
	    p->left = NULL;
	    p->right = NULL;
	    tree = p;
	}
	else{
			if(input.MAMH.compare(tree->mh.MAMH) < 0){
				themMonHoc(tree->left, input);
			}
			else if(input.MAMH.compare(tree->mh.MAMH) > 0){
				themMonHoc(tree->right, input);
			}
		}
}


void taoMangRd (int arr[], int min, int max)
{
	for(int i = min; i <= max ; i++)
	{
		if(min == 1 )
		{
			arr[i-1] = i;	
		}
		else if (min == 5001)
		{
			arr[i-5000-1] = i;
		}
	}
}
int random(int minN, int maxN)
{
	srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}
int rdMang (int arr[], int sch)
{
	int x = random(0,4998 - sch);
	swap(arr[x],arr[4998-sch]);
	return arr[4998-sch];
}
int countNodeTong(DSMH p){
	if(p == NULL){
		return 0;
	}else{
		return 1 + countNodeTong(p->left) + countNodeTong(p->right);
	}
}
int countNode(DSMH p){
	if(checkFistNode(p) == false)
		return countNodeTong(p) - 1;
	else
		return countNodeTong(p) ;
}
//void XoaConTroCuoi(DSMH dsm, int &a, int &n, int vt)
//{
//	for(int i = vt + 1; i < n; i++)
//	{
//		a[i - 1] = a[i];
//	}
//	n = countNode(dsm);
//	int *temp = new int[n]; 
//	for(int i = 0; i < n; i++)
//	{
//		temp[i] = a[i]; 
//	}
//	delete[] a;
//	a = new int[n]; 
//	for(int i = 0; i < n; i++)
//	{
//		a[i] = temp[i];
//	}
//	delete[] temp; 	
//}
bool checkFistNode(DSMH p){
	if(p){
		if(p->id == 5000 && p->mh.MAMH.compare(" ") == 0 && p->mh.TENMH.compare(" ") == 0)
			return false;
		return true;
	}
}
void Insert_node(DSMH &p, int x, monHoc a)
{
	if(x == -1)
	{
		return;
	}
	if(p == NULL) // nút lá
	{
		p = new NODE;
		p->id = x;
		p->mh.MAMH = a.MAMH;
		p->mh.TENMH = a.TENMH;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(x < p->id )
			Insert_node(p->left, x, a);
		else if(x > p->id )
			Insert_node(p->right, x, a);
	}
	
}
void Them1MonHoc(DSMH &tree, monHoc ch, int maxid , int arr1[], int arr2[])
{
	int x;
	if (tree == NULL)
	{
		x = maxid/2;
		Insert_node(tree,x,ch);
	}
	else
	{
		// khi = false thi tiep tuc random 1 so cho toi khi khac tat ca id trong dsch
		//neu node dau rong info thi them vao node dau truoc
		if(checkFistNode(tree) == false){
			tree->mh = ch;
		}else{
			if (countNode(tree->left) < countNode(tree->right))
			{
				int nt = countNode(tree->left);
				x =	rdMang(arr1,nt);
			}
			else 
			{
				int np = countNode(tree->right);
				x =	rdMang(arr2,np);
			}
			Insert_node(tree,x,ch);
		}
	}
}
//
//void Them1MonHocDaSua(DSMH &tree, monHoc ch, int maxid , int arr1[], int arr2[])
//{
//	int x;
//	if (tree == NULL)
//	{
//		x = maxid/2;
//		Insert_node(tree,x,ch);
//	}
//	else
//	{
//		// khi = false thi tiep tuc random 1 so cho toi khi khac tat ca id trong dsch
//		
//		if (countNode(tree->left) < countNode(tree->right))
//		{
//			int nt = countNode(tree->left);
//			x =	rdMang(arr1,nt);
//		}
//		else 
//		{
//			int np = countNode(tree->right);
//			x =	rdMang(arr2,np);
//		}
//		Insert_node(tree,x,ch);
//	}
//}
void suaThongTin1MonHoc(DSMH &p, int id, monHoc mh){
	if(p){
		if(id == p->id){
			p->mh = mh;
		}else if(id < p->id){
			suaThongTin1MonHoc(p->left, id, mh);
		}else if(id > p->id){
			suaThongTin1MonHoc(p->right, id, mh);
		}
	}
}
void inMonHoc(monHoc mh){
	cout<<"Ma MH: "<<mh.MAMH<<"\n";
	cout<<"Ten MH: "<<mh.TENMH<<"\n";
}
void NLR(DSMH root)
{
	if (root)
    {
    	cout<<"\n"<<root->id<<endl;
        inMonHoc(root->mh);
        cout<<"=========================\n";
        NLR(root->left);
        NLR(root->right);
    }
}
DSMH FindNode(DSMH p, int id)
{
    while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->left;
	else
	p = p->right;
	return p;
}
//void DiTimNodeTheMang(DSMH &X, DSMH &Y) // NODE Y là node th? m?ng cho node c?n xóa - node này s? d?m nh?n nhi?m v? tìm ra node trái nh?t(TÌM NODE TRÁI NH?T CÂY CON PH?I) ho?c ph?i nh?t(TÌM NODE PH?I NH?T C?A CÂY CON TRÁI)
//{
//	// CÁCH 1: TÌM NODE TRÁI NH?T C?A CÂY CON PH?I
//	// duy?t sang bên trái nh?t
//	if (Y->left != NULL)
//	{
//		DiTimNodeTheMang(X, Y->left);// tìm ra node trái nh?t ?
//	}
//	else // tìm ra du?c node trái nh?t r?i nek..
//	{
//		X->mh = Y->mh; // c?p nh?t cái data c?a node c?n xóa chính là data c?a node th? m?ng
//		X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
//		Y = Y->right; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng	
//	}
//
//	//// CÁCH 2: TÌM NODE PH?I NH?T C?A CÂY CON TRÁI
//	//// duy?t sang bên ph?i
//	//if (Y->pRight != NULL)
//	//{
//	//	DiTimNodeTheMang(X, Y->pRight);// tìm ra node ph?i nh?t ?
//	//}
//	//else // tìm ra du?c node ph?i nh?t r?i nek..
//	//{
//	//	X->data = Y->data; // c?p nh?t cái data c?a node c?n xóa chính là data c?a node th? m?ng
//	//	X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
//	//	Y = Y->pLeft; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng	
//	//}
//}
//// xoa mot mon hoc
//void xoaMonHoc(DSMH &root, int id){
//	if(root == NULL)
//		return;
//	else{
//		if(id < root->id){
//			xoaMonHoc(root->left,id);
//		}
//		else if(id > root->id){
//			xoaMonHoc(root->right,id);
//		}
//		else
//		{
//			NODE *p = root;
//			if(root->left == NULL){
//				root = root->right;
//			}
//			else if(root->right == NULL){
//				root = root->left;
//			}
//			else{
//				// CÁCH 1: Tìm node trái nh?t c?a cây con ph?i(cây con ph?i c?a cái node c?n xóa)
//				DiTimNodeTheMang(p, root->right);
//				// CÁCH 2: Tìm node ph?i nh?t c?a cây con trái(cây con trái c?a cái node c?n xóa)
//				//DiTimNodeTheMang(X, t->pLeft);
//			}
//		}
//	}
//}
void remove_case_3 ( DSMH &r , DSMH &rp )
{
	if (r->left != NULL)
	{
		remove_case_3 (r->left,rp);	
	}
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		rp->id = r->id; //Chep noi dung cua r sang rp ";
		rp->mh = r->mh; // de lat nua free(rp)
		rp = r;
		r = rp->right;
	}
}
void remove (DSMH &p, int x)
{
	DSMH rp;
	if (p == NULL)
	{
		cout <<  "Khong tim thay";
	} 
	else
	{
		if (x < p->id)
		{
			remove (p->left, x);
		} 
		else
		{
			if (x > p->id)
			{
				remove (p->right, x);
			}
			else // p->key = x
			{
				rp = p;
				if (rp->right == NULL) 
				{
					p = rp->left;	
				}
				// p là nút lá hoac la nut chi co cay con ben trai
				else 
				{
					if (rp->left == NULL)
					{
						p = rp->right; // p là nut co cay con ben phai
					}
					else
					{
						remove_case_3 (rp->right,rp);
					}
				}
				delete rp;
			}	
		}
	}
}
//===============cau hoi================================
cauHoi nhapCauHoi(){
	cauHoi a;
	cout<<"\nNhap noi dung cau hoi: ";
	cin.ignore();
	getline(cin,a.noiDung);
	cout<<"\nNhap cau A: ";
	getline(cin, a.A);
	cout<<"\nNhap cau B: ";
	getline(cin, a.B);
	cout<<"\nNhap cau C: ";
	getline(cin, a.C);
	cout<<"\nNhap cau D: ";
	getline(cin, a.D);
	cout<<"\nNhap Dap an: ";
	getline(cin, a.dapAn);
	return a;
}
void xuat1CH(cauHoi *ch1){
	cout<<"\n======================\n";
	cout<<"\nNOI DUNG CAU HOI: "<<ch1->noiDung;
	cout<<"\nDap an A: "<<ch1->A;
	cout<<"\nDap an B: "<<ch1->B;
	cout<<"\nDap an C: "<<ch1->C;
	cout<<"\nDap an D: "<<ch1->D;
	cout<<"\nDap an dung: "<<ch1->dapAn<<endl;
}
void themCH(DSCH &ch, cauHoi ch1){
	if(ch.listCauHoi[0] == NULL){
		ch.listCauHoi[ch.n] = new cauHoi;
		*ch.listCauHoi[ch.n] = ch1; 
		ch.n++;
	}
	else{		
		for(int i = ch.n - 1; i >= ch.n; i--)
		{
			ch.listCauHoi[i + 1] = ch.listCauHoi[i];
		}
		ch.listCauHoi[ch.n] = new cauHoi;
		*ch.listCauHoi[ch.n] = ch1;
		ch.n++;
	}
}
void xuatDSCH(DSCH ch){
	cout<<"So cau hoi: "<<ch.n;
	for(int i = 0; i < ch.n; i ++){
		xuat1CH(ch.listCauHoi[i]);
	}
}
void themCHVaoMonHoc(DSMH &p,int id, cauHoi ch1){
		if(p){
			if(id == p->id){
				themCH(p->mh.cauHoiMH, ch1);
			}else if(id < p->id){
				themCHVaoMonHoc(p->left,id,ch1);
			}else if(id > p->id){
				themCHVaoMonHoc(p->right,id,ch1);
			}
		}
}
void InCHMonHoc(DSMH &p){
	NLR(p);
	int id;
	cout<<"nhap id mon can in cau hoi: ";
	cin>>id;
	if(FindNode(p, id) !=NULL){
		while (p != NULL && p->id != id)
		if(id < p->id)
		p = p->left;
		else
		p = p->right;
		cout<<"So luong cau hoi: "<<p->mh.cauHoiMH.n;
		for(int i = 0; i < p->mh.cauHoiMH.n; i++){
				cout<<"\n============================================================"<<endl;
				cout<<"\nNOI Dung: "<<p->mh.cauHoiMH.listCauHoi[i]->noiDung<<endl;
				cout<<"\nA: "<<p->mh.cauHoiMH.listCauHoi[i]->A<<endl;
				cout<<"\nB: "<<p->mh.cauHoiMH.listCauHoi[i]->B<<endl;
				cout<<"\nC: "<<p->mh.cauHoiMH.listCauHoi[i]->C<<endl;
				cout<<"\nD: "<<p->mh.cauHoiMH.listCauHoi[i]->D<<endl;
				cout<<"\nDap an: "<<p->mh.cauHoiMH.listCauHoi[i]->dapAn<<endl;
		}
//		cout<<"ND cau hoi trong mon hoc";
//		cout<<p->mh.cauHoiMH.listCauHoi;
	}else{
		cout<<"khong tim thay mon";
	}
	system("pause");
}

void DocFileDSMHV(DSMH &dsm, int arr1[], int arr2[])
{
	ifstream fileIn;
	fileIn.open("DSMONHOCVACH.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Nope";
	monHoc mh;
	while(!fileIn.eof())
	{
		string nTam;
		int nINT;
		int id;
		string temp;
		getline(fileIn,temp,'\n');
		id = StringToInt(temp);
		getline(fileIn,mh.MAMH,'\n');
		getline(fileIn,mh.TENMH,'\n');
		getline(fileIn,nTam,'\n');
		nINT = StringToInt(nTam);
//		cout<<"\n\nID: "<<id<<endl;
//		cout<<"Ma MH: "<<mh.MAMH;
//		cout<<"\nTen MH: "<<mh.TENMH;
//		cout<<"\nSLCH: "<<mh.cauHoiMH.n;
//		if(mh.cauHoiMH.n > 0){
//			for(int i = 0; i < mh.cauHoiMH.n; i++){
//				cout<<"\n============================================================"<<endl;
//				cout<<"\nNOI Dung: "<<mh.cauHoiMH.listCauHoi[i]->noiDung<<endl;
//				cout<<"\nA: "<<mh.cauHoiMH.listCauHoi[i]->A<<endl;
//				cout<<"\nB: "<<mh.cauHoiMH.listCauHoi[i]->B<<endl;
//				cout<<"\nC: "<<mh.cauHoiMH.listCauHoi[i]->C<<endl;
//				cout<<"\nD: "<<mh.cauHoiMH.listCauHoi[i]->D<<endl;
//				cout<<"\nDap an: "<<mh.cauHoiMH.listCauHoi[i]->dapAn<<endl;
//			}
//		}
		if (id < 5000)
		{
			swap(arr1[id], arr1[4999-countNode(dsm->left)]);
			Insert_node(dsm,id,mh);
		}
		else if (id > 5000)
		{
			swap(arr2[id-5001],arr2[4999-countNode(dsm->right)]);
			Insert_node(dsm,id,mh);
		}
		else 
		{
			Insert_node(dsm,id,mh);
		}
		if(nINT > 0){
			cauHoi ch1;
			for(int i = 0; i < nINT; i ++){
				getline(fileIn, ch1.noiDung,'\n');
				getline(fileIn, ch1.A,'\n');
				getline(fileIn, ch1.B,'\n');
				getline(fileIn, ch1.C,'\n');
				getline(fileIn, ch1.D,'\n');
				getline(fileIn, ch1.dapAn,'\n');
				themCH(mh.cauHoiMH, ch1);
			}
			themCHVaoMonHoc(dsm,id,ch1);
		}else
			mh.cauHoiMH.n = 0;
		if(mh.cauHoiMH.n > 0){
			for(int i = 0; i < mh.cauHoiMH.n; i++){
				delete mh.cauHoiMH.listCauHoi[i];
			}
			mh.cauHoiMH.n = 0;	
		}
	
//		cout<<"ID: "<<id<<" slCH: "<<mh.cauHoiMH.n<<"\n";
	}
	fileIn.close();
}
void LuuFileMH(DSMH root, string filename, int idlonnhat) // NLR
{
	DSMH q;
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (!fileOut.is_open())
	{
		cout << "khong mo duoc";
		return;
	}
	else
	{
		if(countNode(root) == 0)
		{
			cout << "DS trong";
			return;		
		}
		DSMH Stack[STACKSIZE];
		int sp= -1; // Khoi tao Stack rong
		DSMH p = root;
		while (p != NULL )
		{
			if(p->id == idlonnhat){
				fileOut << p->id << endl;
				fileOut << p->mh.MAMH << endl;
				fileOut << p->mh.TENMH << endl;
				fileOut << p->mh.cauHoiMH.n << endl;
				if(p->mh.cauHoiMH.n > 0){
					for(int i = 0; i < p->mh.cauHoiMH.n; i++){
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->noiDung << endl;
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->A << endl;
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->B << endl;
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->C << endl;
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->D << endl;
							fileOut << p->mh.cauHoiMH.listCauHoi[i]->dapAn<<endl;
					}
				}
				break;
			}
			fileOut << p->id << endl;
			fileOut << p->mh.MAMH << endl;
			fileOut << p->mh.TENMH << endl;
			fileOut << p->mh.cauHoiMH.n << endl;
			if(p->mh.cauHoiMH.n > 0){
				for(int i = 0; i < p->mh.cauHoiMH.n; i++){
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->noiDung << endl;
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->A << endl;
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->B << endl;
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->C << endl;
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->D << endl;
						fileOut << p->mh.cauHoiMH.listCauHoi[i]->dapAn<<endl;
				}
			}
			if (p->right != NULL)
			{
				Stack[++sp]= p->right;	
			}
			if (p->left != NULL)
			{
				p = p->left;	
			}
			else if (sp == -1)
			{
				break;	
			}
			else
			{
				p = Stack[sp--];	
			}
		}
	}
	fileOut.close();
	return ;
}
// ==================== TIM KIEM CAU HOI ==========================
DSMH Search_MH(DSMH p, int id)
{
	while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->left;
	else
	p = p->right;
	return p;
}
void In1MH_CoCauHoi(NODE* ch, int k)
{
	gotoxy(15,4+k);
	cout << ch->id;
	gotoxy(37,4+k);
	cout << ch->mh.MAMH;
	gotoxy(57,4+k);
	cout<< ch->mh.TENMH;
	
}
void ChuanHoaTen (string &text)
{
	if(text[0] == 32)
	{
		text.erase(0,1);
		ChuanHoaTen(text);
	}
	if(text[text.length()-1] == 32)
	{
		text.erase(text.length()-1,1);
		ChuanHoaTen(text);
	}
} 
bool CheckMonNhap_Test(DSMH dsm, int* arr[],int sl, string mamon, string tenmon)
{
	
	for(int i = 0; i < sl; i++)
	{
		DSMH p = FindNode(dsm, *arr[i]);
		if(mamon.compare(p->mh.MAMH) == 0 || tenmon.compare(p->mh.MAMH) == 0)
		{
			return false;
		}
	}
	return true;
}
bool CheckMonSua_Test(DSMH dsm, int* arr[],int sl,int idTam, string mamon, string tenmon)
{
	
	for(int i = 0; i < sl; i++)
	{
		if(idTam != *arr[i]){
			DSMH p = FindNode(dsm, *arr[i]);
			if(mamon.compare(p->mh.MAMH) == 0 || tenmon.compare(p->mh.MAMH) == 0)
			{
				return false;
			}
		}else if(idTam == *arr[i]){
			return true;
		}
	}
	return true;
}
void xoaKhungTTMH(int dai, int rong){
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			cout<<" ";
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
void vekhungTTMH(monHoc mh, int dai, int rong)
{
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == 1)
			{
				if (j == 0 || j == rong-1) cout << doc;
				else if(j == (rong - 15)/2)
				{
					cout << "Cau hoi mon Hoc";
					j = j+14;
				}
				else cout << " ";
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else cout << ngang;
			}
			else if(i == 4)
			{
				if(j == 0) cout << doc;
				else if (j ==2) 
				{
					cout<<"MA MON: "<<mh.MAMH;
					j = j +7 + mh.MAMH.length();
				}
				else if (j == rong -1) cout << doc;
				else cout << " ";
			}
			else if(i == 7)
			{
				if(j == 0) cout << doc;
				else if (j == 2 ) 
				{
					cout<<"TEN MON: "<<mh.TENMH;
					j = j +8 + mh.TENMH.length();
				}
				else if (j == rong -1) cout << doc;
				else cout << " ";
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else cout << ngang;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			//sleep(1);
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
bool Exit (char &s, bool &sCheck)
{
	AnConTro();
	gotoxy(127,26);
	vekhungTB(10,36);
	string tb = "Ban co chac chan muon thoat ? (Y/N)";
	InTB(tb,130,30);
	batPhim(s,sCheck);
	while(1)
	{
		AnConTro();
		if((s == 'y' || s == 'Y')&& sCheck == true)
		{
			XoaTB(130,26);
			return true;
		}
		else if((s == 'n' || s == 'N') && sCheck == true)
		{
			XoaTB(130,26);
			return false;
		}else if((s == ESC) && sCheck == true)
		{
			XoaTB(130,26);
			return false;
		}
		batPhim(s,sCheck);
	}
}
void InDSCHMon (DSCH ch, int &page)
{
	if (ch.n == 0)
	{
		return;
	}
	int k = 2;
	int maxpage;
	if (ch.n % 10 == 0)
	{
		maxpage = ch.n/10;
	}
	else maxpage = ch.n/10 +1;
	for(int i = page*10; i < (page+1)*10; i++)
	{
		if(ch.listCauHoi[i] == NULL)
		{
			break;
		}
		gotoxy(10,4+k);
		cout << i + 1;
		gotoxy(25 ,4+k);
		if(ch.listCauHoi[i]->noiDung.length() < 87 )
			cout << ch.listCauHoi[i]->noiDung;
		else{
			string temp = ch.listCauHoi[i]->noiDung.substr(0,87);
			cout << temp << "...";
		}
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage;
}
// ==================== IN DANH SACH mon hoc ==========================
void InDSMH_CoCauHoi(DSMH root, int page,int& maxpage, int *arr[])
{
	int k = 2;
	int sl = countNode(root);
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	for(int j = page*10; (j < (page + 1)*10) && (j<sl);j++)
	{
		DSMH temp = Search_MH(root,*arr[j]);
		In1MH_CoCauHoi(temp,k);
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 <<"/" << maxpage + 1;
}
void NhapMonHoc_Test(DSMH &dsm, int &sl, int &page, int &maxpage, int &idlonnhat, int *arr[], int arr1[], int arr2[])
{	
	gotoxy(5,38);
	veKhung(5,120);
	gotoxy(7,40);
	cout << "Ma mon :";
	gotoxy(15,39);
	veKhung(3,30);
	gotoxy(80,40);
	cout << "Ten mon :";
	gotoxy(88,39);
	veKhung(3,35);
	string tenmon;
	string mamon;
	char s;
	bool state = true;
	bool sCheck;
	string tb;
	int hd;
	int td;
	gotoxy(17,40);
	HienConTro();
	batPhim(s,sCheck);
	while (1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;				
			}
			else
			{
				if (state == true)
				{
					gotoxy(17+mamon.length(),40);
				}
				else gotoxy(90+tenmon.length(),40);
				HienConTro();
				batPhim(s,sCheck);
			}
		}
		if(sl <= 10)
		{
			maxpage = 0;
		}
		else if(sl % 10 == 0) 
		{
			maxpage = sl/10 -1;
		}
		else maxpage = sl/10;
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+mamon.length(),40);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenmon.length(),40);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')  ) && sCheck == true)
		{
			HienConTro();
			if (state == false )
			{
				if (tenmon.length() < 30)
				{
					cout << InHoa(s);
					tenmon += InHoa(s);
				}
			}
			else 
			{
				if (mamon.length() < 15)
				{
					cout << InHoa(s);
					mamon += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenmon.length() == 0)
					{
						gotoxy(90+tenmon.length(),40);
					}
					else if(tenmon[tenmon.length()-1]!= ' ')
					{
						cout << InHoa(s);
						tenmon += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenmon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					tenmon.erase(tenmon.length()-1);
				}
			}
			else
			{
				if (mamon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					mamon.erase(mamon.length()-1);
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			int sl = countNode(dsm);
			if(sl <= 10)
			{
				maxpage = 0;
			}
			else if (sl % 10 == 0)
			{
				maxpage = sl/10 - 1;
			}
			else maxpage = sl/10;
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(15,6+i);
						cout << "      ";
						gotoxy(37,6+i);
						cout << "               ";
						gotoxy(57,6+i);
						cout << "                                                             ";
					}
				page ++;
				InDSMH_CoCauHoi(dsm,page,maxpage, arr);
			}
			if(state == true)
			{
				gotoxy(17+mamon.length(),40);
			}
			else
			{
				gotoxy(90+tenmon.length(),40);	
			}
			HienConTro();
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(15,6+i);
						cout << "      ";
						gotoxy(37,6+i);
						cout << "               ";
						gotoxy(57,6+i);
						cout << "                                                             ";
						
					}
				page--;
				InDSMH_CoCauHoi(dsm,page, maxpage, arr);
			}
			if(state == true)
			{
				gotoxy(17+mamon.length(),40);
			}
			else
			{
				gotoxy(90+tenmon.length(),40);	
			}
			HienConTro();
		}
		if (s == ENTER)
		{
			AnConTro();
			ChuanHoaTen(tenmon);
			if(tenmon.length() == 0 || mamon.length() == 0)
			{
				tb = "Ban chua nhap ma mon hoac ten mon, vui long dien day du thong tin";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+mamon.length(),40);
				state = true;
				HienConTro();
			}
			else
			{
				if(CheckMonNhap_Test(dsm,arr,sl,mamon,tenmon) == false)
				{
					XoaTB(130,26);
					tb = "Ma mon hoac ten mon da bi trung, vui long nhap lai";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(17+mamon.length(),40);
					state = true;
					HienConTro();
				}
				else
				{
					monHoc mh ;
					mh.MAMH = mamon;
					mh.TENMH = tenmon;
					Them1MonHoc(dsm, mh, maxid, arr1, arr2);
					sl = countNode(dsm);
						for(int i = 0; i < sl; i++)
						{
							arr[i] = new int;
						}
						int i=0;
						DSMH Stack[STACKSIZE];
						DSMH p = dsm;
						int sp = -1;
						do
						{ 
							while (p != NULL)
							{
								Stack[++sp]= p;
								p = p->left;
							}
							if (sp != -1)
							{
								p = Stack[sp--];
								//in vao danh sach ch
								*arr[i] = p->id;
								i++;
								p = p->right;
							}
							else break;
						} while (1);
					idlonnhat = *arr[sl-1];
					LuuFileMH(dsm, "DSMONHOCVACH.txt", idlonnhat);
					AnConTro();
					XoaTB(130,26);
					gotoxy(129,30);
					tb = "Them mon vao danh sach thanh     cong";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					for(int i = 0; i < 28;i++)
					{
						gotoxy(15,6+i);
						cout << "      ";
						gotoxy(37,6+i);
						cout << "              ";
						gotoxy(57,6+i);
						cout << "                                                             ";
					}
			InDSMH_CoCauHoi(dsm,page, maxpage, arr);
			mamon = "";
			tenmon = "";
			gotoxy(17,40);
			cout << "                           ";
			gotoxy(90,40);
			cout << "                           ";
			gotoxy(17+mamon.length(),40);
			HienConTro();
			state = true;
				}
			}
		}
	batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,38+i);
		cout << "                                                                                                                        ";
	}
} 
void suaMonHoc_Test(DSMH &dsm, int &state, int &page,int sl, int idlonnhat, int *arr[])
{	
	int iTam = page*10 +state;
	int idTam = *arr[iTam];
	DSMH pTam = Search_MH(dsm,idTam);
	int slCH = pTam->mh.cauHoiMH.n;
	if(slCH != 0){
		AnConTro();
		XoaTB(130,26);
		gotoxy(129,30);
		string tb = "Mon hoc da co cau hoi!        Khong the xoa!";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}else{
		string mamon = pTam->mh.MAMH;
		string tenmon = pTam->mh.TENMH;
		char s;
		bool stateCheck = true;
		bool sCheck;
		string tb;
		int hd;
		int td;
		gotoxy(37 + mamon.length(),6 +3*state);
		HienConTro();
		batPhim(s,sCheck);
		while (1)
		{
			if(s == ESC)
			{
				if(Exit(s,sCheck) == true)
				{
					break;
				}
				else
				{
					if (stateCheck == true)
					{
						gotoxy(37+mamon.length(),6 +3*state);
					}
					else gotoxy(57+tenmon.length(),6 +3*state);
					HienConTro();
					batPhim(s,sCheck);
				}
			}
			if (s == LEFT && sCheck == false)
			{
				if (stateCheck == false)
				{
					gotoxy(37+mamon.length(),6 +3*state);
					stateCheck = true;
				}
			}
			if (s == RIGHT && sCheck == false)
			{
				if (stateCheck == true)
				{
					gotoxy(57+tenmon.length(),6 +3*state);
					stateCheck = false;
				}
			}
			if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')  ) && sCheck == true)
			{
				HienConTro();
				if (stateCheck == false )
				{
					if (tenmon.length() < 30)
					{
						cout << InHoa(s);
						tenmon += InHoa(s);
					}
				}
				else 
				{
					if (mamon.length() < 15)
					{
						cout << InHoa(s);
						mamon += InHoa(s);
					}
				}
			}
			if(s == ' ')
			{
				if(stateCheck == false)
					{
						if(tenmon.length() == 0)
						{
							gotoxy(57+tenmon.length(),6 +3*state);
						}
						else if(tenmon[tenmon.length()-1]!= ' ')
						{
							cout << InHoa(s);
							tenmon += InHoa(s);	
						}
					}
			}
			if (s == BACKSPACE)
			{
				if (stateCheck == false)
				{
					if (tenmon.length() > 0)
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(wherex()-1,wherey());
						HienConTro();
						tenmon.erase(tenmon.length()-1);
					}
				}
				else
				{
					if (mamon.length() > 0)
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(wherex()-1,wherey());
						HienConTro();
						mamon.erase(mamon.length()-1);
					}
				}
			}
			if (s == ENTER)
			{
				AnConTro();
				ChuanHoaTen(tenmon);
				if(tenmon.length() == 0 || mamon.length() == 0)
				{
					tb = "Ban chua nhap ma mon hoac ten mon, vui long dien day du thong tin";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(37+mamon.length(),6 +3*state);
					stateCheck = true;
					HienConTro();
				}
				else
				{
					if(CheckMonSua_Test(dsm, arr, sl, idTam, mamon, tenmon) == false)
					{
						XoaTB(130,26);
						tb = "Ma mon hoac ten mon da bi trung, vui long nhap lai";
						InTB(tb,129,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						gotoxy(37+mamon.length(),6 +3*state);
						stateCheck = true;
						HienConTro();
					}
					else
					{
						monHoc mh ;
						mh.MAMH = mamon;
						mh.TENMH = tenmon;
						suaThongTin1MonHoc(dsm, idTam, mh);
						LuuFileMH(dsm, "DSMONHOCVACH.txt", idlonnhat);
						AnConTro();
						XoaTB(130,26);
						gotoxy(129,30);
						tb = "Sua mon hoc trong danh sach thanh cong!";
						InTB(tb,129,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						break;
					}
				}
			}
		batPhim(s,sCheck);
		}
	}
}
void xoaCauHoiTrongMH(DSMH &p, int id, int state, int &page){
	
}
void NhapCauHoiThem(DSMH &dsm, int id)
{
	vekhungThemCH();
	gotoxy(20,43);
	cout << "                                                                                                                           ";
	gotoxy(5 + (120 - 43)/2,43);
	cout << "ENTER: Chon    ESC: Thoat    LEN/XUONG: CHON NOI DUNG";
	cauHoi ch;
	int state = 0;
	int n;
	int dem;
	string temp;
	char s;
	bool sCheck;
	gotoxy(20,5);
	int hdnd,tdnd,hda,tda,hdb,tdb,hdc,tdc,hdd,tdd;
	hdnd = 20;
	tdnd = 5;
	hda = 20;
	tda = 14;
	hdb = 20;
	tdb = 20;
	hdc = 20;
	tdc = 26;
	hdd = 20;
	tdd = 32;
	HienConTro();
	batPhim(s,sCheck);
	while(1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				switch(state)
				{
					case 0:
						{
							HienConTro();
							gotoxy(hdnd,tdnd);
							break;
						}
					case 1:
						{
							HienConTro();
							gotoxy(hda,tda);
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							break;
						}
					case 4:
						{
							HienConTro();
							gotoxy(hdd,tdd);
							break;
						}
					case 5:
						{
							veNut(3,11,59,38,"LUU",30);
							HienConTro();
							gotoxy(hdd,tdd);
							state = 4;
							break;
							
						}	
				}
				HienConTro();
				batPhim(s,sCheck);
			}
		}
		if(s == UP && sCheck == false)
		{
			if(state > 0)
			{
				switch(state)
				{
					case 1:
						{
							HienConTro();
							gotoxy(hdnd,tdnd);
							state--;
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hda,tda);
							state--;
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							state--;
							break;
						}
					case 4:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							state--;
							break;
						}
					case 5:
						{
							veNut(3,11,59,38,"LUU",30);
							HienConTro();
							gotoxy(hdd,tdd);
							state--;
							break;
						}	
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state < 5)
			{
				switch(state)
				{
					case 0:
						{
							HienConTro();
							gotoxy(hda,tda);
							state ++;
							break;
						}
					case 1:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							state ++;
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							state ++;
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdd,tdd);
							state ++;
							break;
						}
					case 4:
						{
							AnConTro();
							veNut(3,11,59,38,"LUU",240);
							state ++;
							break;
						}	
				}
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || (s == '?') || (s == ','))  && sCheck == true)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						if(ch.noiDung.length() < 280)
						{
							if(wherex() == 115 && wherey() == 5 )
							{
								n = ch.noiDung.length()-1;
								temp = "";
								if(ch.noiDung[n] == ' ')
								{
									gotoxy(20,7);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else
								{
									while(ch.noiDung[n] != ' ')
									{
										temp += ch.noiDung[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
										dem = n;
									}
									dem++;
									temp = DaoChuoi(temp);
									gotoxy(20,7);
									cout << temp;
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
							}
							else if (wherex() == 115 && wherey() == 7)
							{
								n = ch.noiDung.length()-1;
								temp = "";
								if(ch.noiDung[n] == ' ')
								{
									gotoxy(20,9);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else
								{
									while(ch.noiDung[n] != ' ')
									{
										temp += ch.noiDung[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,9);
									cout << temp;
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.noiDung += InHoa(s);
							}
						}
						hdnd = wherex();
						tdnd = wherey();
						break;
					}
				case 1:	
					{
						if(ch.A.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.A.length()-1;
								temp = "";
								dem = 0;
								if(ch.A[n] == ' ')
								{
									gotoxy(20,16);
									cout << InHoa(s);
									ch.A += InHoa(s);
								}
								else
								{
									while(ch.A[n] != ' ')
									{
										temp += ch.A[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,16);
									cout << temp;
									cout << InHoa(s);
									ch.A += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.A += InHoa(s);
							}
						}
						hda = wherex();
						tda = wherey();
						break;
					}
				case 2:
					{
						if(ch.B.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.B.length()-1;
								temp = "";
								dem = 0;
								if(ch.B[n] == ' ')
								{
									gotoxy(20,22);
									cout << InHoa(s);
									ch.B += InHoa(s);
								}
								else
								{
									while(ch.B[n] != ' ')
									{
										temp += ch.B[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,22);
									cout << temp;
									cout << InHoa(s);
									ch.B += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.B += InHoa(s);
							}	
						}
						hdb = wherex();
						tdb = wherey();
						break;
					}
				case 3:
					{
						if(ch.C.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.C.length()-1;
								temp = "";
								dem = 0;
								if(ch.C[n] == ' ')
								{
									gotoxy(20,28);
									cout << InHoa(s);
									ch.C += InHoa(s);
								}
								else
								{
									while(ch.C[n] != ' ')
									{
										temp += ch.C[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,28);
									cout << temp;
									cout << InHoa(s);
									ch.C += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.C += InHoa(s);
							}	
						}
						hdc = wherex();
						tdc = wherey();
						break;
					}
				case 4:
					{
						if(ch.D.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.D.length()-1;
								temp = "";
								dem = 0;
								if(ch.D[n] == ' ')
								{
									gotoxy(20,34);
									cout << InHoa(s);
									ch.D += InHoa(s);
								}
								else
								{
									while(ch.D[n] != ' ')
									{
										temp += ch.D[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,34);
									cout << temp;
									cout << InHoa(s);
									ch.D += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.D += InHoa(s);
							}	
						}
						hdd = wherex();
						tdd = wherey();
						break;
					}
								
			}
		}
		if(s == ' ')
		{
			switch(state)
				{
					case 0:
						{
							if(ch.noiDung.length() == 0)
							{
								gotoxy(20+ch.noiDung.length()-1,5);
							}
							if(ch.noiDung[ch.noiDung.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.noiDung += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								if(wherey() == 5)
								{
									dem = wherex() - 20;
									gotoxy(20,7);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else if(wherey() == 7)
								{
									gotoxy(20,9);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}									
							}
							hdnd = wherex();
							tdnd = wherey();
							break;	
						}
					case 1:
						{
							if(ch.A.length() == 0)
							{
								gotoxy(20+ch.A.length()-1,14);
							}
							if(ch.A[ch.A.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.A += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,16);
								cout << InHoa(s);
								ch.A += InHoa(s);
							}
							hda = wherex();
							tda = wherey();
							break;	
						}
					case 2:
						{
							if(ch.B.length() == 0)
							{
								gotoxy(20+ch.B.length()-1,20);
							}
							if(ch.B[ch.B.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.B += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,22);
								cout << InHoa(s);
								ch.B += InHoa(s);
							}
							hdb = wherex();
							tdb = wherey();
							break;	
						}
					case 3:
						{
							if(ch.C.length() == 0)
							{
								gotoxy(20+ch.C.length()-1,26);
							}
							if(ch.C[ch.C.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.C += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,28);
								cout << InHoa(s);
								ch.C += InHoa(s);
							}
							hdc = wherex();
							tdc = wherey();
							break;	
						}
					case 4:
						{
							if(ch.D.length() == 0)
							{
								gotoxy(20+ch.D.length()-1,32);
							}
							if(ch.D[ch.D.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.D += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,34);
								cout << InHoa(s);
								ch.D += InHoa(s);
							}
							hdd = wherex();
							tdd = wherey();
							break;	
						}				
				}
		}
		if (s == BACKSPACE)
		{
			switch(state)
			{
				case 0:
					{
						if (ch.noiDung.length() > 0)
						{
							if(wherex() == 20 && wherey() == 7)
							{
								gotoxy(20 + ch.noiDung.length(),5);
								hdnd = wherex();
								tdnd = wherey();
							}
							else if(wherex() == 20 && wherey() == 9)
							{
								gotoxy(20 + ch.noiDung.length() - dem,7);
								hdnd = wherex();
								tdnd = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.noiDung.erase(ch.noiDung.length()-1);
								hdnd = wherex();
								tdnd = wherey();
							}
						}
						break;
					}
				case 1:
					{
						if (ch.A.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.A.length(),14);
								hda = wherex();
								tda = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.A.erase(ch.A.length()-1);
								hda = wherex();
								tda = wherey();
							}
						}
						break;
					}
				case 2:
					{
						if (ch.B.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.B.length(),20);
								hdb = wherex();
								tdb = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.B.erase(ch.B.length()-1);
								hdb = wherex();
								tdb = wherey();
							}
						}
						break;
					}
				case 3:
					{
						if (ch.C.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.C.length(),26);
								hdc = wherex();
								tdc = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.C.erase(ch.C.length()-1);
								hdc = wherex();
								tdc = wherey();
							}
						}
						break;					
					}
				case 4:
					{
						
						if (ch.D.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.D.length(),32);
								hdd = wherex();
								tdd = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.D.erase(ch.D.length()-1);
								hdd = wherex();
								tdd = wherey();
							}
						}
						break;
					}		
			}
		}
		if ( s == ENTER)
		{
			if(state == 5)
			{
				if(ch.noiDung.length() == 0 || ch.A.length() == 0 || ch.B.length() == 0 || ch.C.length() == 0 || ch.D.length() == 0)
				{
					string tb = "Vui long nhap day du thong tin";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
				else
				{	
					int state1 = 0;
					string da = "A";
					string tb = "Dap an dang chon: " + da;
					InTB(tb,129,30);
					AnConTro();
					gotoxy(4,14);
					cout << muiten;
					batPhim(s,sCheck);
					while(1)
					{
						
						if(s == ESC){
							break;
						}
						if(s == UP && sCheck == false)
						{
							switch(state1)
							{
								case 1:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1--;
										da = "A";
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										gotoxy(4,14);
										cout << muiten;
										break;
									}
								case 2:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1--;
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										da = "B";
										gotoxy(4,20);
										cout << muiten;
										break;
									}
								case 3:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1--;
										da = "C";
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										gotoxy(4,26);
										cout << muiten;
										break;
									}
							}	
						}
						if(s == DOWN && sCheck == false)
						{
							switch(state1)
							{
								case 0:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1++;
										da = "B";
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										gotoxy(4,20);
										cout << muiten;
										break;
									}
								case 1:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1++;
										da = "C";
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										gotoxy(4,26);
										cout << muiten;
										break;
									}
								case 2:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										state1++;
										da = "D";
										XoaTB(130,26);
										string tb = "Dap an dang chon: " + da;
										InTB(tb,129,30);
										AnConTro();
										gotoxy(4,32);
										cout << muiten;
										break;
									}
							}
						}
						if(s == ENTER)
						{
							ch.dapAn = da;
							themCHVaoMonHoc(dsm, id, ch);
							XoaTB(130, 26);
							string tb = "Them cau hoi thanh cong!";
							InTB(tb,132,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							break;
						}
						batPhim(s,sCheck);
					}
					for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				}
				for(int i = 0; i < 30;i++)
				{
					gotoxy(20,5+i);
					if(i == 4) i = 8;
					if (i == 11) i = 14;
					if (i == 17) i = 20;
					if (i == 23) i = 26;
					cout << "                                                                                                  ";
				}
				veNut(3,11,59,38,"LUU",30);
				ch.noiDung = "";
				ch.A = "";
				ch.B = "";
				ch.C = "";
				ch.D = "";
				state = 0;
				gotoxy(20+ch.noiDung.length(),5);
				hdnd = 20;
				tdnd = 5;
				hda = 20;
				tda = 14;
				hdb = 20;
				tdb = 20;
				hdc = 20;
				tdc = 26;
				hdd = 20;
				tdd = 32;
				HienConTro();
			}
		}
		batPhim(s,sCheck);
	}
}
void FunctionCauHoi(DSMH & dsm,int id)
{
	DSMH pTam = Search_MH(dsm,id);
	gotoxy(0,0);
	veKhungThuCong();
	xoaKhungThemCH();
	AnConTro();
	gotoxy(20,43);
	cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
	gotoxy(127, 2);
	vekhungTTMH(pTam->mh, 10, 36);
	gotoxy(127,26);
	vekhungTB(10,36);
	AnConTro();
	gotoxy(5,2);
	vekhungDSCH_Test(34,120,2);
	int page = 0;
	int maxpage;	
	int state = 0;
	if (pTam->mh.cauHoiMH.n != 0) 
	{
		InDSCHMon(pTam->mh.cauHoiMH,page);
	}
	char s;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while(1)
	{
		if(pTam->mh.cauHoiMH.n <= 10)
		{
			maxpage = 0;
		}
		else if(pTam->mh.cauHoiMH.n % 10 == 0) 
		{
			maxpage = pTam->mh.cauHoiMH.n/10 -1;
		}
		else maxpage = pTam->mh.cauHoiMH.n/10;
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{	
				gotoxy(127,6);
				xoaKhungTTMH(10,36);
				gotoxy(20,43);
				cout << "                                                                                                                           ";
				break;
			}
			else
			{	
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
			}
			batPhim(s,sCheck);
		}
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
			if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(8,6+i);
						cout << "      ";
						gotoxy(17,6+i);
						cout << "                                                                          ";
					}
					gotoxy(7,6);
					cout << " ";
					page --;
					InDSCHMon(pTam->mh.cauHoiMH,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(pTam->mh.cauHoiMH.listCauHoi[state + page*10 + 1] != NULL && (page*10 +state + 1) < pTam->mh.cauHoiMH.n)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(8,6+i);
							cout << "      ";
							gotoxy(17,6+i);
							cout << "                                                                          ";
						}
					}
					page++;
					InDSCHMon(pTam->mh.cauHoiMH,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(pTam->mh.cauHoiMH.listCauHoi[state + page*10 + 1] != NULL &&(page*10 +state + 1) < pTam->mh.cauHoiMH.n)
				{
					gotoxy(7,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				gotoxy(wherex()-1,wherey());
				cout << " ";
				for(int i = 0; i < 28;i++)
				{
						gotoxy(8,6+i);
						cout << "      ";
						gotoxy(17,6+i);
						cout << "                                                                          ";
				}
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				InDSCHMon(pTam->mh.cauHoiMH,page);
				gotoxy(7,6);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				gotoxy(wherex()-1,wherey());
				cout << " ";
				for(int i = 0; i < 28;i++)
				{
						gotoxy(8,6+i);
						cout << "      ";
						gotoxy(17,6+i);
						cout << "                                                                          ";
				}
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				InDSCHMon(pTam->mh.cauHoiMH,page);
				gotoxy(7,6);
			}
		}
		if(s == F1){
			NhapCauHoiThem(dsm, id);
			xoaKhungThemCH();
			gotoxy(5,2);
			vekhungDSCH_Test(34,120,2);
			DSMH pTam = Search_MH(dsm,id);
			InDSCHMon(pTam->mh.cauHoiMH, page);
			state = 0;
			gotoxy(20,43);
			cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
			gotoxy(7, 6 + 3*state);
			AnConTro();
			cout<<muiten;
		}
		if(s == F2){
		}
		if(s == ENTER){
		}
	batPhim(s,sCheck);
	}
}

void xoaMMH_Test(DSMH &dsm, int &sl,int &state ,int &page, int &maxpage, int &idlonnhat, int *arr[]){
			int iTam = page*10 +state;
			int idTam = *arr[iTam];
			DSMH pTam = Search_MH(dsm,idTam);
			int slCH = pTam->mh.cauHoiMH.n;
			if(slCH == 0){
				if(pTam->id == 5000){
					pTam->mh.MAMH = " ";
					pTam->mh.TENMH = " ";
				}else{
					remove(dsm, idTam);
				}
				for(int i = state + page*10; i < sl - 1; i++)
				{
					*arr[i] = *arr[i+1];	
				}
				sl--;
				if(sl > 0)
				{
					idlonnhat = *arr[sl-1];	
				}
				LuuFileMH(dsm, "DSMONHOCVACH.txt", idlonnhat);
				AnConTro();
				XoaTB(130,26);
				gotoxy(129,30);
				string tb = "Xoa mon trong danh sach thanh cong";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				for(int i = 0; i < 28;i++)
				{
					gotoxy(15,6+i);
					cout << "      ";
					gotoxy(37,6+i);
					cout << "              ";
					gotoxy(57,6+i);
					cout << "                                                             ";
				}
			}else{
				AnConTro();
				XoaTB(130,26);
				gotoxy(129,30);
				string tb = "Mon hoc da co cau hoi!        Khong the xoa!";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
}
void FunctionMH(DSMH &dsm, int &idlonnhat, int arr1[], int arr2[])
{
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(20,43);
	cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them mon hoc    F2: Sua mon hoc    F3: Xoa mon";
	gotoxy(127,26);
	vekhungTB(10,36);
	AnConTro();
	int page = 0;
	int maxpage;
	int sl = countNode(dsm);
	int *arr [sl];
	for(int i = 0; i < sl; i++)
	{
		arr[i] = new int;
	}
	int i=0;
	DSMH Stack[STACKSIZE];
	DSMH p = dsm;
	int sp = -1;
	do
	{
		while (p != NULL)
		{
			Stack[++sp]= p;
			p = p->left;
		}
		if (sp != -1)
		{
			//in vao danh sach mh
				p = Stack[sp--];
			if(p->id == 5000 && p->mh.MAMH.compare(" ") == 0 && p->mh.TENMH.compare(" ") == 0){
				p = p->right;
			}else{
				*arr[i] = p->id;
				i++;
				p = p->right;
			}
		}
		else break;
	} while (1);
	if(sl > 0)
	{
		idlonnhat = *arr[sl-1];	
	}
	gotoxy(5,2);
	vekhungDSMH_CoCauHoi(34,120,5);
	if(sl == 0){
		AnConTro();
		XoaTB(130,26);
		gotoxy(129,30);
		string tb = "Danh sach mon hoc trong!";
		InTB(tb,129,30);
		Sleep(2000);
		XoaTB(129,30);
		AnConTro();
	}		
		InDSMH_CoCauHoi(dsm,page, maxpage,arr);
		int state = 0;
		char s;
		bool sCheck;
		gotoxy(7,6);
		cout << muiten;
		batPhim(s,sCheck);
		while(s != ESC)
		{
			if(sl <= 10)
			{
				maxpage = 0;
			}
			else if(sl % 10 == 0) 
			{
				maxpage = sl/10 -1;
			}
			else maxpage = sl/10;
			
			if(s == UP && sCheck == false)
			{
				if(page == 0)
				{
					if(state > 0)
					{
						gotoxy(wherex()-1,wherey());
						cout << " ";
						state --;
						gotoxy(7,wherey() - 3);
						cout << muiten;
					}
				}
				if(page > 0)
				{
					if((state > 0) )
					{
						gotoxy(wherex()-1,wherey());
						cout << " ";
						state --;
						gotoxy(7,wherey()-3);
						cout << muiten;
					}
					else if(state == 0)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(15,6+i);
							cout << "      ";
							gotoxy(37,6+i);
							cout << "          ";
							gotoxy(57,6+i);
							cout << "                                                             ";
						}
						gotoxy(7,6);
						cout << " ";
						page --;
						InDSMH_CoCauHoi(dsm,page, maxpage, arr);
						gotoxy(7,33);
						cout << muiten;
						state = 9;
					}
				}
			}
			if(s == DOWN && sCheck == false)
			{
				if(state == 9)
				{
					sl = countNode(dsm);
					if(arr[state + page*10 + 1] != NULL && (page*10 +state + 1) < sl)
					{
						gotoxy(wherex()-1,wherey());
						cout << " ";
						//cap nhat maxpage
						if(page < maxpage)
						{
							for(int i = 0; i < 28;i++)
							{
								gotoxy(15,6+i);
								cout << "      ";
								gotoxy(37,6+i);
								cout << "              ";
								gotoxy(57,6+i);
								cout << "                                                             ";
							}
						}
						page++;
						InDSMH_CoCauHoi(dsm,page, maxpage, arr);
						state = 0;
						gotoxy(7,6);
						cout << muiten;
					}
				}
				else
				{
					sl = countNode(dsm);
					if(arr[state + page*10 + 1] != NULL &&(page*10 +state + 1) < sl)
					{
						gotoxy(7,wherey());
						cout << " ";
						state ++;
						gotoxy(7,wherey() + 3);
						cout << muiten;	
					}
				}
			}
			if (s == PAGEDOWN && sCheck == false)
			{
				AnConTro();
				if(page < maxpage)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					for(int i = 0; i < 28;i++)
					{
						gotoxy(15,6+i);
						cout << "      ";
						gotoxy(37,6+i);
						cout << "              ";
						gotoxy(57,6+i);
						cout << "                                                             ";
					}
					gotoxy(7,6);
					cout << muiten;
					state = 0;
					page ++;
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);
					gotoxy(7,6);
				}
			}
			if(s == PAGEUP && sCheck == false)
			{
				AnConTro();
				if (page > 0 )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					for(int i = 0; i < 28;i++)
					{
						gotoxy(15,6+i);
						cout << "      ";
						gotoxy(37,6+i);
						cout << "              ";
						gotoxy(57,6+i);
						cout << "                                                             ";
					}
					gotoxy(7,6);
					cout << muiten;
					state = 0;
					page--;
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);
					gotoxy(7,6);
				}
			}
			if(s == F2){
					suaMonHoc_Test(dsm, state, page, sl, idlonnhat, arr);
					gotoxy(7,6 + 3*state);
					cout<<muiten;
			}
			if(s == F3){
				xoaMMH_Test(dsm,sl,state, page, maxpage, idlonnhat, arr);
				if(state > 0 && sl == (page * 10 + state)){
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state--;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state == 0 && sl == (page * 10 + state) && page !=0){
					page--;
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state = 9;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state > 0 && sl < 10 && page ==0 ){
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				} else{
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);	
				}	
			}
			if(s == F1){
				NhapMonHoc_Test(dsm,sl, page, maxpage, idlonnhat, arr,arr1,arr2);
				gotoxy(0,0);
				cout<<"ID lon nhat: "<<idlonnhat;
				gotoxy(7,6 +3*state);
				cout<<muiten;
			}
			if(s == ENTER)
			{
				int iEntner = page*10 +state;
				int idEntner = *arr[iEntner];
				system("cls");
				FunctionCauHoi(dsm, idEntner);
				LuuFileMH(dsm, "DSMONHOCVACH.txt", idlonnhat);
				gotoxy(127,2);
				xoaKhungTTMH(10,36);
				XoaTB(130, 26);
				gotoxy(20,43);
				cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them mon hoc    F2: Sua mon hoc    F3: Xoa mon";
				gotoxy(5,2);
				vekhungDSMH_CoCauHoi(34,120,5);
				InDSMH_CoCauHoi(dsm, page, maxpage, arr);
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
				
			}
		batPhim(s,sCheck);
	}
}
void menu(DSMH &dsm, DSCH &ch, monHoc mh, int arr1[], int arr2[]){
int idlonnhat;
	while(true){
		system("cls");
			int n;
			cout<<"\n\n\n==================MENU==================\n";
			cout<<"1.Nhap mon hoc\n";
			cout<<"su lua chon cua ban: ";
			cin>>n;
			switch(n){
			case 1:
				{
					FunctionMH(dsm, idlonnhat, arr1, arr2);
				}
				break;
			case 0:
				return;
		}
	}
}
int main(){
	int arr1[4999];
	int arr2[4999];
	taoMangRd(arr1,1,4999);
	taoMangRd(arr2,5001,9999);
	DSMH dsm;
	DSCH ch;
	khoiTaoCay(dsm);
	monHoc mh;
	DocFileDSMHV(dsm,arr1,arr2);
	
//	InCHMonHoc(dsm);
//	cout<<"SL: "<<countNode(dsm);
	menu(dsm, ch, mh, arr1, arr2);
}
