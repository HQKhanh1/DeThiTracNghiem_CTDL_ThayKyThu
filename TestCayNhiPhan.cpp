#include<iostream>
#include <string.h>
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
	int n;
  	cauHoi *listCauHoi[MAXCAUHOI]; // danh sach mang 1 chieu
} DSCH;
// DANH SACH MON HOC THEO CAY NHI PHAN TIM KIEM
struct monHoc{
	string MAMH;
	string TENMH;
	DSCH cauHoiMH;
};
struct nodeMonHoc{
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
void inMonHoc(monHoc mh){
	cout<<"Ma MH: "<<mh.MAMH<<"\n";
	cout<<"Ten MH: "<<mh.TENMH<<"\n";
}
void NLR(DSMH root)
{
    if (root)
    {
        inMonHoc(root->mh);
        cout<<"=========================\n";
        NLR(root->left);
        NLR(root->right);
    }
}
NODE *FindNode(DSMH root, string maMH)
{
    if (root)
    {
        if (maMH.compare(root->mh.MAMH) == 0)
            return root;
        if (maMH.compare(root->mh.MAMH) < 0)
            return FindNode(root->left, maMH);
        return FindNode(root->right, maMH);
    }
    return NULL;
}
//Nhap mon hoc
monHoc nhapMonHoc(DSMH root){
	monHoc mh;
	cin.ignore();
	cout<<"Nhap MaMonHoc(999 la dung nhap): ";
	getline(cin,mh.MAMH);
	if(FindNode(root, mh.MAMH) != NULL)
		cout<<"Ma mon hoc bi trung";
	else
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
void xoaMonHoc(DSMH &root, string maMH){
	if(root == NULL)
		return;
	else{
		if(maMH.compare(root->mh.MAMH) < 0){
			xoaMonHoc(root->left,maMH);
		}
		else if(maMH.compare(root->mh.MAMH) > 0){
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
void menu(DSMH &dsm, monHoc mh){
	while(true){
		system("cls");
			int n;
			cout<<"\n\n\n==================MENU==================\n";
			cout<<"1.Nhap mon hoc\n";
			cout<<"2.In mon hoc tu cay\n";
			cout<<"3.Tim mon hoc theo ma mon\n";
			cout<<"4.Xoa mon hoc theo ma mon\n";
			cout<<"0.Thoat\n";
			cout<<"su lua chon cua ban: ";
			cin>>n;
			switch(n){
			case 1:
				mh = nhapMonHoc(dsm);
				themMonHoc(dsm,mh);
				break;
			case 2:
				NLR(dsm);
				system("pause");
				break;
			case 3:
				{
					string maMHFind;
					cout<<"\nNhap ma mon hoc can tim: ";
					cin.ignore();
					getline(cin,maMHFind);
					NODE *p = FindNode(dsm,maMHFind);
					if(p == NULL)
						cout<<"Mon hoc khong ton tai";
					else
						inMonHoc(p->mh);
				}
				system("pause");
				break;
			case 4:
				{
					string maMHXoa;
					cout<<"\nNhap ma mon hoc can Xoa: ";
					cin.ignore();
					getline(cin,maMHXoa);
					if(FindNode(dsm,maMHXoa) != NULL){
						cout<<"\nDa xoa!";
						xoaMonHoc(dsm,maMHXoa);
					}else
						cout<<"\nKhong tim thay mon can xoa!";
				}
				system("pause");
				break;
			case 0:
				return;
		}
	}
}
int main(){
	DSMH dsm;
	khoiTaoCay(dsm);
	monHoc mh;
	menu(dsm, mh);
}
