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

int maxid = 10000;
bool stop = 1;
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
int countNode(DSMH root)
{
	DSMH Stack[STACKSIZE];
	DSMH p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			++i;
			p = p->right;
		}
		else
			break;
	} while (1);
	return i;
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
		p->mh = a;
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
NODE *FindNode(DSMH p, int id)
{
    while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->left;
	else
	p = p->right;
	return p;
}
//Nhap mon hoc
monHoc nhapMonHoc(DSMH root){
	monHoc mh;
	cin.ignore();
	cout<<"Nhap MaMonHoc(999 la dung nhap): ";
	getline(cin,mh.MAMH);
	cout<<"Nhap TenMonHoc: ";
	getline(cin, mh.TENMH);
		return mh;
			
}
void DiTimNodeTheMang(DSMH &X, DSMH &Y) // NODE Y là node th? m?ng cho node c?n xóa - node này s? d?m nh?n nhi?m v? tìm ra node trái nh?t(TÌM NODE TRÁI NH?T CÂY CON PH?I) ho?c ph?i nh?t(TÌM NODE PH?I NH?T C?A CÂY CON TRÁI)
{
	// CÁCH 1: TÌM NODE TRÁI NH?T C?A CÂY CON PH?I
	// duy?t sang bên trái nh?t
	if (Y->left != NULL)
	{
		DiTimNodeTheMang(X, Y->left);// tìm ra node trái nh?t ?
	}
	else // tìm ra du?c node trái nh?t r?i nek..
	{
		X->mh = Y->mh; // c?p nh?t cái data c?a node c?n xóa chính là data c?a node th? m?ng
		X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
		Y = Y->right; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng	
	}

	//// CÁCH 2: TÌM NODE PH?I NH?T C?A CÂY CON TRÁI
	//// duy?t sang bên ph?i
	//if (Y->pRight != NULL)
	//{
	//	DiTimNodeTheMang(X, Y->pRight);// tìm ra node ph?i nh?t ?
	//}
	//else // tìm ra du?c node ph?i nh?t r?i nek..
	//{
	//	X->data = Y->data; // c?p nh?t cái data c?a node c?n xóa chính là data c?a node th? m?ng
	//	X = Y; // cho node X(là node mà chúng ta s? di xóa sau này) tr? d?n node th? m?ng ==> ra kh?i hàm thì ta s? xóa node X
	//	Y = Y->pLeft; // b?n ch?t ch? này chính là c?p nh?t l?i m?i liên k?t cho node cha c?a node th? m?ng(mà chúng ta s? xóa) v?i node con c?a node th? m?ng	
	//}
}
// xoa mot mon hoc
void xoaMonHoc(DSMH &root, int maMH){
	if(root == NULL)
		return;
	else{
		if(maMH < root->id){
			xoaMonHoc(root->left,maMH);
		}
		else if(maMH > root->id){
			xoaMonHoc(root->right,maMH);
		}
		else
		{
			NODE *p = root;
			if(root->left == NULL){
				root = root->right;
			}
			else if(root->right == NULL){
				root = root->left;
			}
			else{
				// CÁCH 1: Tìm node trái nh?t c?a cây con ph?i(cây con ph?i c?a cái node c?n xóa)
				DiTimNodeTheMang(p, root->right);
				// CÁCH 2: Tìm node ph?i nh?t c?a cây con trái(cây con trái c?a cái node c?n xóa)
				//DiTimNodeTheMang(X, t->pLeft);
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
	cout<<"\nDap an dung: "<<ch1->dapAn;
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
		while (p != NULL && p->id != id)
		if(id < p->id)
		p = p->left;
		else
		p = p->right;
		themCH(p->mh.cauHoiMH, ch1);
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
		xuatDSCH(p->mh.cauHoiMH);
//		cout<<"ND cau hoi trong mon hoc";
//		cout<<p->mh.cauHoiMH.listCauHoi;
	}else{
		cout<<"khong tim thay mon";
	}
}
void DocFileDSMHV(DSMH &dsm, int arr1[], int arr2[])
{
	string n;
	int id;
	string temp;
	ifstream fileIn;
	fileIn.open("DSMONHOCVACH.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Nope";
	monHoc mh;
	while(!fileIn.eof())
	{
		getline(fileIn,temp,'\n');
		id = StringToInt(temp);
		getline(fileIn,mh.MAMH,'\n');
		getline(fileIn,mh.TENMH,'\n');
		getline(fileIn,n,'\n');
		for(int i = 0; i < StringToInt(n); i ++){
			cauHoi ch1;
			getline(fileIn, ch1.noiDung,'\n');
			getline(fileIn, ch1.A,'\n');
			getline(fileIn, ch1.B,'\n');
			getline(fileIn, ch1.C,'\n');
			getline(fileIn, ch1.D,'\n');
			getline(fileIn, ch1.dapAn,'\n');
			themCH(mh.cauHoiMH, ch1);
		}
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
//			if(p->id == idlonnhat)
//			{
////				cout << "ID lon nhat: " << idlonnhat;
////				system("pause");
//				fileOut << p->id << endl;
//				fileOut << p->mh.MAMH << endl;
//				fileOut << p->mh.TENMH << endl;
//				fileOut << p->mh.cauHoiMH.n << endl;
//				if(p->mh.cauHoiMH.n > 0){
//					for(int i = 0; i < p->mh.cauHoiMH.n; i++){
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->noiDung << endl;
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->A << endl;
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->B << endl;
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->C << endl;
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->D << endl;
//						fileOut << p->mh.cauHoiMH.listCauHoi[i]->dapAn<<endl;
//					}
//				}
//				break;
//			}
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
NODE *Search_CH(DSMH p, int id)
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
	gotoxy(13,4+k);
	cout << ch->id;
	gotoxy(35,4+k);
	cout << ch->mh.MAMH;
	gotoxy(55,4+k);
	cout<< ch->mh.TENMH;
	
}

// ==================== IN DANH SACH mon hoc ==========================
void InDSMH_CoCauHoi(DSMH root, int page, int *arr[])
{
	int k = 2;
	int maxpage;
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
		DSMH temp = Search_CH(root,*arr[j]);
		In1MH_CoCauHoi(temp,k);
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
void FunctionMH(DSMH &dsm, int &idlonnhat, int arr1[], int arr2[])
{
	gotoxy(40,43);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang F1: Them mon hoc F2: Sua mon hoc F3: Xoa mon";
	gotoxy(130,26);
	vekhungTB(10,36);
//	veNut(3,15,150,5,"Them CH",240);
//	veNut(3,15,150,10,"Xoa CH",20);
//	veNut(3,15,150,15,"Xem CH",20);
//	veNut(3,15,150,20,"Xem CH theo mon",20);
	int page = 0;
	int maxpage;
	int hd;
	int td;
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
			p = Stack[sp--];
			//in vao danh sach ch
			*arr[i] = p->id;
			i++;
			p = p->right;
		}
		else break;
	} while (1);
	if(sl > 0)
	{
		idlonnhat = *arr[sl-1];	
	}
	gotoxy(5,2);
	vekhungDSMH_CoCauHoi(34,120,5);
	InDSMH_CoCauHoi(dsm,page,arr);
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
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMH_CoCauHoi(dsm,page,arr);
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
				if(arr[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMH_CoCauHoi(dsm,page,arr);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(arr[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(arr[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				page ++;
				InDSMH_CoCauHoi(dsm,page,arr);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
						
					}
				page--;
				InDSMH_CoCauHoi(dsm,page,arr);
			}
		}
		if(s == F2){
			system("cls");
						NLR(dsm);
						cout<<"\nid lon nhat: "<<idlonnhat<<endl;
						cout<<"so luong: "<<sl<<endl;
						for(int i = 0; i < sl; i++){
							cout<<" ,"<<*arr[i];
						}
						system("pause");
		}
		if(s == F1){
						system("cls");
						NLR(dsm);
						cout<<"\nid lon nhat: "<<idlonnhat<<endl;
						cout<<"so luong: "<<sl<<endl;
						for(int i = 0; i < sl; i++){
							cout<<" ,"<<*arr[i];
						}
						system("pause");
				monHoc mh = nhapMonHoc(dsm);
				Them1MonHoc(dsm, mh, maxid, arr1, arr2);
				int sl = countNode(dsm);
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
						NLR(dsm);
						cout<<"\nid lon nhat: "<<idlonnhat<<endl;
						cout<<"so luong: "<<sl<<endl;
						for(int i = 0; i < sl; i++){
							cout<<" ,"<<*arr[i];
						}
						system("pause");
						gotoxy(5,2);
						vekhungDSMH_CoCauHoi(34,120,5);
//						InDSMH_CoCauHoi(dsm,page,arr);
		}
//		if(s == ENTER)
//		{
//			switch(state)
//			{
//				case 0:
//					{
//						ThemCH(dsch,dsm,arr,arr1,arr2);
//						int sl = countNode(dsch);
//						for(int i = 0; i < sl; i++)
//						{
//							arr[i] = new int;
//						}
//						int i=0;
//						DSMH Stack[STACKSIZE];
//						DSMH p = dsch;
//						int sp = -1;
//						do
//						{ 
//							while (p != NULL)
//							{
//								Stack[++sp]= p;
//								p = p->pLeft;
//							}
//							if (sp != -1)
//							{
//								p = Stack[sp--];
//								//in vao danh sach ch
//								*arr[i] = p->id;
//								i++;
//								p = p->pRight;
//							}
//							else break;
//						} while (1);
//						idlonnhat = *arr[sl-1];
//						system("cls");
//						AnConTro();
//						gotoxy(130,26);
//						vekhungTB(10,36);
//						veNut(3,15,150,5,"Them CH",240);
//						veNut(3,15,150,10,"Xoa CH",20);
//						veNut(3,15,150,15,"Xem CH",20);
//						veNut(3,15,150,20,"Xem CH theo mon",20);
//						gotoxy(5,2);
//						vekhungDSCH(34,120,5);
//						InDSCH(dsch,page,arr);
//						break;
//					}
//				case 1:
//					{
//						XoaCauHoi(dsch,arr,idlonnhat,dsl);
//						AnConTro();
//						break;
//					}
//				case 2:
//					{
//						XemCauHoi(dsch,arr,idlonnhat);
//						AnConTro();
//						break;
//					}
//				case 3: //goi dsm, chon mon, rot cau hoi theo mon vao, cho phep di chuyen trai phai
//					{
//						XemCHtheoMon(dsm,dsch);
//						AnConTro();
//						system("cls");
//						AnConTro();
//						gotoxy(130,26);
//						vekhungTB(10,36);
//						veNut(3,15,150,5,"Them CH",20);
//						veNut(3,15,150,10,"Xoa CH",20);
//						veNut(3,15,150,15,"Xem CH",20);
//						veNut(3,15,150,20,"Xem CH theo mon",240);
//						gotoxy(5,2);
//						vekhungDSCH(34,120,5);
//						InDSCH(dsch,page,arr);
//						break;					
//					}	
//			}
//		}
	batPhim(s,sCheck);
	}
}
void menu(DSMH &dsm, DSCH &ch, monHoc mh, int arr1[], int arr2[]){
int idlonnhat;
	while(true){
		system("cls");
//			int sl = countNode(dsm);
//					int *arr [sl];
//					DSMH Stack[STACKSIZE];
//					DSMH p = dsm;
//					int sp = -1;
//					for(int i = 0; i < sl; i++)
//					{
//						arr[i] = new int;
//					}
//					int i=0;
//					do
//					{ 
//						while (p != NULL)
//						{
//							Stack[++sp]= p;
//							p = p->left;
//						}
//						if (sp != -1)
//						{
//							p = Stack[sp--];
//							//in vao danh sach ch
//							*arr[i] = p->id;
//							i++;
//							p = p->right;
//						}
//						else break;
//					} while (1);
//					if(sl > 0)
//					{
//						idlonnhat = *arr[sl-1];	
//					}
			int n;
			cout<<"\n\n\n==================MENU==================\n";
			cout<<"1.Nhap mon hoc\n";
//			cout<<"2.In mon hoc tu cay\n";
//			cout<<"3.Tim mon hoc\n";
//			cout<<"4.Xoa mon hoc theo ma mon\n";
//			cout<<"5.Them CH Mon Hoc\n";
//			cout<<"6.In danh sach cau hoi\n";
//			cout<<"7.Nhap cau hoi trong mon hoc\n";
//			cout<<"8.In cau hoi trong mon hoc\n";
//			cout<<"9.Luu file mon hoc\n";
			cout<<"0.Thoat\n";
			cout<<"su lua chon cua ban: ";
			cin>>n;
			switch(n){
			case 1:
				{
//					
					FunctionMH(dsm, idlonnhat, arr1, arr2);
					system("pause");
				}
				break;
//			case 2:
//				NLR(dsm);
//				system("pause");
//				break;
//			case 3:
//				{
//					NLR(dsm);
//					int maMHFind;
//					cout<<"\nNhap id mon hoc can tim: ";
//					cin>>maMHFind;
//					NODE *p = FindNode(dsm,maMHFind);
//					if(p == NULL)
//						cout<<"Mon hoc khong ton tai";
//					else
//						inMonHoc(p->mh);
//				}
//				system("pause");
//				break;
//			case 4:
//				{
//					int maMHXoa;
//					cout<<"\nNhap ma mon hoc can Xoa: ";
//					cin>>maMHXoa;
//					if(FindNode(dsm,maMHXoa) != NULL){
//						cout<<"\nDa xoa!";
//						xoaMonHoc(dsm,maMHXoa);
//					}else
//						cout<<"\nKhong tim thay mon can xoa!";
//				}
//				system("pause");
//				break;
//			case 5:
//				{
//					NLR(dsm);
//					int id;
//					cout<<"Nhap id mon can them cau hoi: ";
//					cin>>id;
//					DSMH k = FindNode(dsm, id);
//					if(k){
//						themCHVaoMonHoc(k, id, nhapCauHoi());
//						int sl = countNode(dsm);
//						for(int i = 0; i < sl; i++)
//						{
//							arr[i] = new int;
//						}
//						int i=0;
//						DSMH Stack[STACKSIZE];
//						DSMH p = dsm;
//						int sp = -1;
//						do
//						{ 
//							while (p != NULL)
//							{
//								Stack[++sp]= p;
//								p = p->left;
//							}
//							if (sp != -1)
//							{
//								p = Stack[sp--];
//								//in vao danh sach ch
//								*arr[i] = p->id;
//								i++;
//								p = p->right;
//							}
//							else break;
//						} while (1);
//						idlonnhat = *arr[sl - 1];
//					}else{
//						cout<<"Khong tim thay mon hoc";
//					}
//				}
//				system("pause");
//				break;
//			case 6:
//				xuatDSCH(ch);
//				system("pause");
//				break;
//			case 7:
////				themCHVaoMonHoc(dsm);
//				system("pause");
//				break;
//			case 8:
//				InCHMonHoc(dsm);
//				system("pause");
//				break;
//			case 9:
//				{
//					cout<<"\nID Lon Nhat: "<<idlonnhat<<endl;
//					cout<<"\nDa Luu\n";
//					LuuFileMH(dsm,"DSMONHOCVACH.txt",idlonnhat);
//				}
//				system("pause");
//				break;
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
	menu(dsm, ch, mh, arr1, arr2);
}
