#ifndef _FUNCTION_H
#define _FUNCTION_H
#include<iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include <thread>
#include <sstream>
#include <Windows.h>
#define xDangNhap 50
#define yDangNhap 5
#define xVeThiTracNghiem 10
#define yVeThiTracNghiem 26
#define xKhungCoDinh 45
#define yKhungCoDinh 165
HANDLE wHnd;
HANDLE rHnd;
using namespace std;
// ==================== MAIN PROCESS ==========================
int DangNhap(dslop &dsl ,string &masv);
int mainMenu();
void mainProcess(dslop &dsl, dssv &ds, DSMH &dsm, int arr1[], int arr2[]);

// ==================== Function Lop  ==========================
void FunctionLop(dslop &dsl);

void ThemLop(dslop &dsl, int page);
void NhapLop(dslop &dsl, int page);

void XoaLop (dslop &dsl, int &page);
void NhapLopXoa(dslop &dsl,int &page);

void ChinhLop(dslop &dsl, int &page);
void NhapLopChinh(dslop &dsl , int &page);
void SuaLop(lop *&l);

// ==================== Function SV  ==========================
void FunctionSV(dslop &dsl);

void selectFunctionSV(lop *&l ,int page);

void NhapSinhVien(lop *&l );
void Them1SinhVien(lop *l, sinhVien sv);

void XoaSinhVien(lop *&l ,int page);
void DeleteInfo_SV(dssv &ds , string maSV);

// ==================== Function MH ==========================
//void FunctionMon(DSMH &dsm, dslop dsl, NODECH &dsch);
void FunctionMH(DSMH &dsm, dslop dsl, int &idlonnhat, int arr1[], int arr2[]);
int countNode(DSMH p);
void themCHVaoMonHoc(DSMH &p,int id, cauHoi ch1);
bool CheckMonNhap_Test(DSMH dsm, int* arr[],int sl, string mamon, string tenmon);
void Them1MonHoc(DSMH &tree, monHoc ch, int maxid , int arr1[], int arr2[]);
void LuuFileMH(DSMH root, string filename, int idlonnhat);
int rdMang (int arr[], int sch);
void suaMonHoc_Test(DSMH &dsm, int &state, int &page,int sl, int idlonnhat, int *arr[]);
bool ExitXoa (string tb, char &s, bool &sCheck);
void xoaMMH_Test(DSMH &dsm, int &sl,int &state ,int &page, int &maxpage, int &idlonnhat, int *arr[]);
void FunctionCauHoi(DSMH & dsm, dslop dsl, int id, int idlonnhat);
void xoaKhungTTMH(int dai, int rong);
void NhapCauHoiThem(DSMH &dsm, int id);
void SuaCauHoiTrongMH(DSCH &cauhoi, cauHoi ch, int id, int vitri);
void xoaCauHoi(DSMH &p, int id, int state, int page);
void xemCauHoi(cauHoi ch);
void suaCH(DSCH &ch, cauHoi ch1, int state);
bool CheckMonSua_Test(DSMH dsm, int* arr[],int sl,int idTam, string mamon, string tenmon);
void suaThongTin1MonHoc(DSMH &p, int id, monHoc mh);
void LuuFileDiem(lop *l, string filename,DSMH dsm);
//// ==================== Function THI  ==========================
int *LayDeThi(DSCH dsch, int sct);



int maxid = 10000;
bool stop = 1;

// ==================== THOAT  ==========================
bool Exit (char &s, bool &sCheck)
{
	AnConTro();
	gotoxy(127,26);
	vekhungTB(10,36);
	string tb = "Ban co chac chan muon thoat ? (Y/N)";
	InTB(tb,129,30);
	batPhim(s,sCheck);
	while(s != ESC)
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
		}
		batPhim(s,sCheck);
	}
		XoaTB(130,26);
}
// ==================== CHIA STRING  ==========================
int doiso( char n)
{
    return n - '0';
}
char doichar (int n)
{
	return (char)(n+48);
}
string IntToString(int s)
{
	int x;
	string p;
	while(s>=10)
	{
		x = s%10;
		p.insert(0,1,doichar(x));
		s = s/10;
	}
	p.insert(0,1,doichar(s));
	return p;
}
string FloatToString(float s)
{
	int x;
	int nguyen = (int)s;
	float du = (s - (int)s) * 10;
	string p;
	while(nguyen >= 10)
	{
		x = nguyen%10;
		p.insert(0,1,doichar(x));
		nguyen = nguyen/10;
	}
	p.insert(0,1,doichar(nguyen));
	p.insert(p.length(),1,'.');
	for(int i = 0; i < 2; i++){
		int duNguyen = (int)du;
		p.insert(p.length(),1,doichar(duNguyen));
		du = (du - duNguyen) * 10;
	}
	return p;
}
void xoakhongdau (string &s1)
{
	while (s1[0]==48)
	{
		s1.erase(0,1);
	}
}
void xoakhongcuoi (string &s1)
{
	int n = s1.length()-1;
	while (s1[n]==48 && n >= 1)
	{
		s1.erase(n,1);
		n--;
	}
}
void lambangso (string &s1, string &s2)
{
	if (s1.length()>s2.length())
	{
		int x = s1.length () - s2.length();
		s2.insert  (0,x,'0');
	}
	if (s2.length()>s1.length())
	{
		int y = s2.length () - s1.length();
		s1.insert  (0,y,'0');
	}
}
int sosanh1(string &s1,string &s2)
{
	lambangso(s1,s2);
	for (int i = 0; i < s1.length();i++)
	{
		int x = doiso(s1[i]);
		int y = doiso(s2[i]);
		if (x>y)
		{
			xoakhongdau(s1);
			xoakhongdau(s2);
			return 1;
		}
		if (x==y)
		{
			continue;
		}
		if (x<y)
		{
			xoakhongdau(s1);
			xoakhongdau(s2);
			return 2;
		}
	}
	xoakhongdau(s1);
	xoakhongdau(s2);
	return 0;
}
string cong (string s1, string s2)
{
	string s3;
	lambangso(s1,s2);
	int x = 0;
	int temp = 0;
	for (int i =s1.length()-1; i >= 0 ; i--)
	{
		if ((doiso(s1[i]) + doiso(s2[i])) + temp >= 10)
		{
			temp = doiso(s1[i]) + doiso(s2[i]) + temp;
			s3.insert(0,1,doichar(temp%10));
			temp /=10;
		}
		else
		{
			x = doiso(s1[i]) + doiso(s2[i])+temp;
			s3.insert(0,1,doichar(x));
			temp = 0;
		}		
	}
	s3.insert(0,1,doichar(temp));
	return s3;
}
string tru (string s1, string s2)
{
	string s3;
	lambangso(s1,s2);
	int x = 0;
	int temp = 0;
	for (int i =s1.length()-1; i >= 0 ; i--)
	{
		x = doiso(s1[i]) - doiso(s2[i]) - temp;
		if (x>0)
		{
			s3.insert(0,1,doichar(x));
			temp = 0;
		}
		else if (x < 0)
		{
			x = 10 + x;
			s3.insert(0,1,doichar(x));
			temp = 1;
		}
		else if (x == 0)
		{
			s3.insert(0,1,'0');
			temp = 0;
		}
	}
	return s3;
}
string nhan1so (string b, char n)
{
	string s;
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)      
    {
        temp = doiso(n) * doiso(b[i]) + temp;
        s.insert(0,1,doichar(temp%10));
        temp = temp/10;
    }
	s.insert(0,1,doichar(temp));
    return s;
}
string nhan (string s1, string s2)
{
	lambangso(s1,s2);
	string s3;
	string s = "";
	for (int i = s2.length()-1; i >=0; i--)
	{
		s3 = nhan1so(s1,s2[i]);
		s3.insert(s3.length(), s3.length()-i-1, '0'); 
		s = cong(s,s3);
	}
	s.insert(s.length()-1,1,'.');
	return s;
}
void xoadutich(string &tich)
{
	int k = tich.length()-1;
	for (int i = 0; i < 2; i++)
	{
		tich.erase(k,1);
		k--;
	}
}
string chia (string s1, string s2)
{
	string s = "";
	string c = "";
	string kq = "";
	string du = "";
	for (int i = 0; i < s1.length(); i++)
	{
		s.push_back(s1[i]);
		if (sosanh1(s,s2)==1||sosanh1(s,s2)==0 )
		{
			for (int j = 1; j <=9; j++)
			{
				c = nhan1so(s2,doichar(j));
				if (sosanh1(c,s)==1  )
				{
					j--;
					kq.push_back(doichar(j));
					c = nhan1so(s2,doichar(j));
					xoakhongdau(c);
					xoakhongdau(kq);
					string hieu = tru (s,c);
					s = hieu;
					j=1;
					break;
				}
				if (j==9 && sosanh1 (c,s)==2)
				{
					kq.push_back(doichar(j));
					c = nhan1so(s2,doichar(j));
					xoakhongdau(c);
					xoakhongdau(kq);
					string hieu = tru (s,c);
					s = hieu;
					j=1;
					break;
				}
				
			}
		}
		else if(sosanh1(s,s2)==2)
				{
					kq.push_back('0');
				}
	}
	xoakhongdau(kq);
	string tich = nhan(s2,kq);
	xoakhongdau(tich);
	xoadutich(tich);
	du = tru(s1,tich);
	if (sosanh1(s1,s2)==2)
	{
		kq = "0";
		du = s1;
	}
	string kq2 = "";
	int t = kq2.length()-1;
	string p = "";
		for(int u = 0; u < 5; u++)
		{
			du.push_back('0');
			
			if (sosanh1(du,s2)==1 || sosanh1(du,s2)==0)
			{
				for(int k = 1; k <=9;k++)
				{
					p = nhan1so(s2,doichar(k));
					if (sosanh1(p,du)==1)
					{
						k--;
						kq2.push_back(doichar(k));
						p = nhan1so(s2,doichar(k));
						xoakhongdau(p);
						string hieu2 = tru (du,p);
						du = hieu2;
						k=1;
						break;
					}
					else if (k==9 && sosanh1 (p,du)==2)
					{
						kq2.push_back(doichar(k));
						p = nhan1so(s2,doichar(k));
						xoakhongdau(p);
						string hieu2 = tru (du,p);
						du = hieu2;
						k=1;
						break;
					}
				}
			}
			else if(sosanh1(du,s2)==2)
					{
						kq2.push_back('0');
					}	
		}
	xoakhongcuoi(kq2);
	int y = kq.length();
	while(kq2.length() > 3)
	{
		kq2.erase(kq2.length()-2,kq2.length()-1);		
	}
	int r = kq2.length();
	if (doiso(kq2[r-1])>5 && r >2)
	{
		int e = doiso(kq2[r-2]);
		e++;
		kq2.erase(r-2,2);
		kq2.push_back(doichar(e));
	}
	else if(doiso(kq2[r-1])<=5 && r > 2)
	{
		kq2.erase(r-1,1);
	}
	kq.insert(y,1,'.');
	y++;
	kq.insert(y,kq2);
	return kq;
}

// ==================== DEM SO SV  ==========================
int DemSV(dssv ds)
{
	int dem = 0;
	
	for (nodeSV *k = ds.First; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
// ==================== XOA CAU HOI TRUONG HOP 3 ==========================
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
// ==================== XOA 1 CAU HOI ==========================

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
// ==================== TIM KIEM SINH VIEN ==========================
nodeSV* search_SV(dssv &ds, string maSV)
{
	nodeSV *Psv = ds.First;
		while(Psv!=NULL){
			if(Psv->info.maSV.compare(maSV) == 0){
				return Psv;
			}
			Psv = Psv->pNext;
		}
		return NULL;
}
void search_SV_Test(dssv &ds)
{
		nodeSV *Psv = ds.First;
		while(Psv!=NULL){
			cout<<"\nMSSV: "<<Psv->info.maSV;
			Psv = Psv->pNext;
		}
		cout<<"\nKhong tim thay sinh vien";
}
// ==================== TIM KIEM LOP ==========================
lop* Search_Lop(dslop dsl, string maLop)
{
	for(int i = 0; i < dsl.solop ; i++)
	{
		if(dsl.l[i]->maLop.compare(maLop) == 0)
		{
			return dsl.l[i];
		}
	}
}
// ==================== TIM KIEM MON HOC ==========================
DSMH Search_MH(DSMH p, int id)
{
	while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->left;
	else
	p = p->right;
	return p;
}
// ==================== TIM KIEM CAU HOI ==========================
//NODECH Search_CH(NODECH p, int id)
//{
//	while (p != NULL && p->id != id)
//	if(id < p->id)
//	p = p->pLeft;
//	else
//	p = p->pRight;
//	return p;
//}

// ==================== TACH MA SINH VIEN ==========================
int TachMSSV (string maSV) 
{
	maSV.erase(0,maSV.length()-3);
	return StringToInt(maSV);
}
// ==================== TACH HO SINH VIEN ==========================
string TachHoSV(string hoten)
{
	string ho;
	for(int i = 0; i < hoten.length(); i ++)
	{
		if(hoten[i] == 32)
		{
			return ho;
		}
		ho += hoten[i];
	}
}
// ==================== TACH TEN SINH VIEN ==========================
string TachTenSV(string hoten)
{
	string ten ;
	for(int i = 0; i < hoten.length(); i ++)
	{
		if (hoten[i] == ' ')
		{
			for(int j = i + 1;j < hoten.length();j++)
			{
				ten += hoten[j];
			}
			return ten;
		}
	}
}
// ==================== SO SANH MA SINH VIEN ==========================
int SoSanhMaSo (sinhVien sv1, sinhVien sv2)
{
	if(TachMSSV(sv1.maSV) < TachMSSV(sv2.maSV) ) 
	{
		return -1;
	}
	if (TachMSSV(sv1.maSV) > TachMSSV(sv2.maSV)) 
	{
		return 1;
	}
	if (TachMSSV(sv1.maSV) == TachMSSV(sv2.maSV)) 
	{
		return 0;
	}
}
// ==================== THEM DIEM VAO SAU ==========================
void Insert_After_Diem(nodeSV *sv, nodediemThi *diem)
{	
	if(sv->info.diem.First == NULL)
	{
		nodediemThi *p;
		p = new nodediemThi;
		p->info = diem->info;
		p->pNext = sv->info.diem.First;
		sv->info.diem.First = p;
	}
	else
	{
		nodediemThi *k;
		for(k = sv->info.diem.First; k->pNext != NULL; k = k->pNext);
		k->pNext = diem;
		diem->pNext = NULL;
	}
}
// ==================== THEM SINH VIEN VAO DAU DS ==========================
void Insert_SV_First(nodeSV *&First, sinhVien sv)
{
	nodeSV *p;
	p = new nodeSV;
	p->info = sv;
	p->pNext = First;
	First = p;

}
// ==================== THEM SINH VIEN VAO SAU ==========================
void Insert_after_SV(nodeSV *p, sinhVien sv)
{
	nodeSV *q;
	if(p == NULL)
	{
		string tb = "Khong them sinh vien vao danh sach duoc";
		InTB(tb,129,30);
		AnConTro();
		Sleep(650);
		XoaTB(130,26);
	}
	else
	{ 
		nodeSV *q = new nodeSV;
		q->info = sv;
		q->pNext = p->pNext;
		p->pNext = q;
	}
}
// ==================== SO SANH MA MH ==========================
int SoSanhMaMH(string mA, string mB)
{
	int x = mA.length();
	int y = mB.length();
	int z;
	if(x < y)
	{
		z = x;
	}
	else z = y;
	for(int i = 0; i < z; i++)
	{
		if(mA[i] < mB[i])
		{
			return 1;
		}
		else if(mA[i] >  mB[i])
		{
			return -1;
		}
		//else continue;
	}
	return 0;
}
// ==================== THEM MON THEO ==========================
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
// ==================== THEM SINH VIEN ==========================
void Them1SinhVien(lop *l, sinhVien sv)
{ 
	nodeSV *t,*s;
	if(l->danhsach.First == NULL)
	{
		Insert_SV_First(l->danhsach.First,sv);
	}
	else 
	{
		if(SoSanhMaSo(l->danhsach.First->info,sv) > 0)
		{
			Insert_SV_First(l->danhsach.First,sv);
		}
		else
		{
			for(s = l->danhsach.First; s != NULL && SoSanhMaSo(s->info,sv) < 0 ; t=s, s = s->pNext) ;
			Insert_after_SV(t,sv);	
		}
	}
	
}
// ==================== XOA SINH VIEN DAU ==========================
void DeleteFirst_SV(dssv &ds)
{
	nodeSV *s;
	if(ds.First== NULL)
	{
		return;
	}
	s = ds.First;
	ds.First = s->pNext;
	delete s;
		
	
}
// ==================== XOA SINH VIEN SAU ==========================
void DeleteAfter_SV(nodeSV *s)
{
	nodeSV *svS;
	if (s == NULL || s->pNext == NULL)
	{
		return;
	}
	svS = s->pNext;
	s->pNext = svS->pNext;
	delete svS;
	
}
// ==================== XOA SINH THEO INFO ==========================
void DeleteInfo_SV(dssv &ds , string maSV)
{
	nodeSV *s;
	nodeSV *svS;
	s = search_SV(ds,maSV);
	if ( s == NULL)
	{
		return;
	}
	if (s == ds.First)
	{
		DeleteFirst_SV(ds);
	}
	else 
	{
		svS = ds.First;
		while(svS->pNext != s)
		{
			svS = svS->pNext;
		}
		DeleteAfter_SV(svS);
	}
}
// ==================== THEM DIEM THI VAO DAU DS ==========================
void Insert_Diem_First(nodediemThi *&First, diemThi diem)
{
	nodediemThi *p;
	p = new nodediemThi;
	p->info = diem;
	p->pNext = First;
	First = p;

}
// ==================== THEM DIEM THI VAO SAU ==========================
void Insert_Diem_after(nodediemThi *p , diemThi diem)
{
	nodeSV *q;
	if(p == NULL)
	cout <<"khong them sinh vien vao danh sach duoc";
	else
	{ 
		nodediemThi *q = new nodediemThi;
		q->info = diem;
		q->pNext = p->pNext;
		p->pNext = q; 
	}
}

// ==================== KIEM TRA DIEM THI ==========================
//void checkdiemThi(dsdiemThi &dsm, string x)
//{
//	int s = x.find(':');
//	string p = x.substr(s,1);
//	string maMh = x.substr(0,s);
//	diemThi d;
//	d.maMH = maMh;
//	d.diem = StringToInt(p);
//	Insert_Diem_after(dsm.First,d);
//}
// ==================== KIEM TRA SL THI ==========================
bool CheckSLThi (dsdiemThi dsd, int idMon)
{
	for(nodediemThi *k = dsd.First; k != NULL; k = k->pNext)
	{
		if(k->info.idMonHoc == idMon)
		{
			return true;
		}
	}
	return false;
}
// ==================== DOC FILE DIEM 1 LOP ==========================
void DocFileDiem1Lop ( lop *l)
{
	ifstream fileIn;
	fileIn.open("DIEM_"+l->maLop+".txt", ios_base :: in);
	if(fileIn.fail())
	{
		cout << "Khong mo duoc file diem 1 lop\n";
		return;	
	} 
	string masv;
	string x;
	int slt;
	nodediemThi *diem = new nodediemThi;
	while(!fileIn.eof())
	{
		getline(fileIn,masv,'\n');
		getline(fileIn,x,'\n');
		slt = StringToInt(x);
		if(slt == 0)
		{
			fileIn.ignore();
		}
		else
		{
			string temp;
			for(int i = 0; i < slt; i++)
			{
				getline(fileIn,temp,':');
				diem->info.idMonHoc = StringToInt(temp);
				getline(fileIn,temp,':');
				diem->info.diem = StringToFloat(temp);
				getline(fileIn,temp,':');
				diem->info.ctdt.sct = StringToInt(temp);
				getline(fileIn,temp,':');
				diem->info.ctdt.tg = StringToInt(temp);
				diem->info.ctdt.bode = new int [diem->info.ctdt.sct];
				diem->info.ctdt.dapan = new int [diem->info.ctdt.sct];
				for(int i = 0 ; i < diem->info.ctdt.sct; i++)
				{
					getline(fileIn,temp,'@');
					diem->info.ctdt.bode[i] = StringToInt(temp);
				}
				for(int i = 0 ; i < diem->info.ctdt.sct; i++)
				{
					getline(fileIn,temp,'#');
					diem->info.ctdt.dapan[i] = StringToInt(temp);
					if(i == diem->info.ctdt.sct -1)
					{
						fileIn.ignore();
					}
				}
				diemThi diemsv;
 				diemsv = diem->info;
				if (search_SV(l->danhsach,masv)->info.diem.First == NULL) 
				{
					Insert_Diem_First(search_SV(l->danhsach,masv)->info.diem.First,diemsv);
				}
				else 
				{
					nodediemThi *p = search_SV(l->danhsach,masv)->info.diem.First;
					while (p->pNext != NULL)
					{
						p = p->pNext;
					}
					Insert_Diem_after(p,diemsv);
				}
			}	
		}
	}
}
// ==================== DOC FILE 1 LOP ==========================
void DocFileLop (lop *&l, string filename )
{
	ifstream fileIn;
	fileIn.open(filename.c_str(),ios_base :: in );
	if(fileIn.fail()) cout << "Khong mo duoc file lop hoc\n";
	sinhVien sv ;
	while(!fileIn.eof())
	{	
		if(fileIn.peek() == std::ifstream::traits_type::eof()) break;
		getline(fileIn,sv.maSV,'\n');
		getline(fileIn,sv.ho,' ');
		getline(fileIn,sv.ten,'\n');
		getline(fileIn,sv.gioiTinh,'\n');
		getline(fileIn,sv.password,'\n');
		InHoaChuoi(sv.maSV);
		InHoaChuoi(sv.ho);
		InHoaChuoi(sv.ten);
		if(StringToInt(sv.gioiTinh) == 1)
		{
			sv.gioiTinh = "NAM";
		}
		else if(StringToInt(sv.gioiTinh) == 0)
		{
			sv.gioiTinh = "NU";
		}
		Them1SinhVien(l,sv);
	}
	fileIn.close();
}
// ==================== DOC DANH SACH LOP TU FILE ==========================
void DocFileDSLop (dslop &dsl)
{
	ifstream fileIn;
	fileIn.open("DSLOP.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Khong doc duoc file danh sach lop\n";
	fileIn >> dsl.solop;
	fileIn.ignore();
	for(int i = 0; i < dsl.solop; i++)
	{
		dsl.l[i] = new lop;
		getline(fileIn,dsl.l[i]->tenLop,'\n');
		getline(fileIn,dsl.l[i]->maLop,'\n');
		DocFileLop(dsl.l[i],dsl.l[i]->maLop+".txt");
		DocFileDiem1Lop(dsl.l[i]);
	}
	fileIn.close();
}
// ==================== DOC DANH SACH MON HOC TU FILE ==========================

void DocFileDSMHV(DSMH &dsm, int arr1[], int arr2[])
{
	ifstream fileIn;
	fileIn.open("DSMONHOCVACH.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Khong doc duoc danh sach mon hoc va cau hoi\n";
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
				themCHVaoMonHoc(dsm, id, ch1);
			}
		}else
			mh.cauHoiMH.n = 0;
	}
	fileIn.close();
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
// ==================== IN DS MON HOC ==========================
void In1MH_CoCauHoi(NODE* ch, int k)
{
	gotoxy(15,4+k);
	cout << ch->id;
	gotoxy(37,4+k);
	cout << ch->mh.MAMH;
	gotoxy(57,4+k);
	cout<< ch->mh.TENMH;
	
}
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
// ==================== IN DS LOP ==========================
void InDSLop (dslop dsl, int &page)
{
	TextColor(241);
	if (dsl.solop == 0)
	{
		return;
	}
	int k = 2;
	int maxpage;
	if (dsl.solop % 10 == 0)
	{
		maxpage = dsl.solop/10;
	}
	else maxpage = dsl.solop/10 +1;
	for(int i = page*10; i < (page+1)*10; i++)
	{
		if(dsl.l[i] == NULL)
		{
			break;
		}
		gotoxy(5+6,4+k);
		TextColor(241);
		cout << dsl.l[i]->tenLop;
		gotoxy(5+6+50+8,4+k);
		TextColor(241);
		cout << dsl.l[i]->maLop;
		k += 3;
	}
	gotoxy(125/2,36);
	TextColor(241);
	cout << "Trang " << page + 1 << "/" << maxpage;
	
}

// ==================== KIEM TRA MA LOP & TEN LOP TRONG DS ==========================
bool CheckLopNhap (dslop dsl, string malop, string tenlop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(malop.compare(dsl.l[i]->maLop) == 0 || tenlop.compare(dsl.l[i]->tenLop) == 0)
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA MON & TEN MON TRONG DS ==========================

// ==================== KIEM TRA TEN LOP TRONG DS  ==========================
bool CheckTenLop (dslop dsl, string tenlop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(tenlop.compare(dsl.l[i]->tenLop) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP TRONG DS  ==========================
bool CheckMaLop (dslop dsl, string malop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(malop.compare(dsl.l[i]->maLop) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP TRONG DS  ==========================
bool CheckMaSV (lop *l, string masv)
{
	for(nodeSV *k = l->danhsach.First; k != NULL; k = k->pNext)
	{
		if(masv.compare(k->info.maSV) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP  ==========================
bool CheckFormMaLop (string malop)
{
	if (malop.length() != 9 || malop[0] != 'D')
	{
		return false;
	}
	if (malop[1] < '0' || malop[1] > '9' || malop[2] < '0' || malop[2] > '9')				//1,2,7,8,9
	{
		return false;
	}
	for(int i = 7; i < 9; i++)
	{
		if(malop[i] < '0' || malop[i] > '9')
		{
			return false;
		}
	}
	for(int i = 3; i < 7; i++)
	{
		if(malop[i] < 'A' || malop[i] > 'Z')
		{
			return false;
		}
	}	
	return true;
}
// ==================== CHUAN HOA TEN  ==========================
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
// ==================== KTRA NHAP MA SV ==========================
bool CheckFormMaSv (string masv)
{
	if (masv.length() != 10 || masv[0] != 'N')
	{
		return false;
	}
	if (masv[1] < '0' || masv[1] > '9' || masv[2] < '0' || masv[2] > '9')				//1,2,7,8,9
	{
		return false;
	}
	for(int i = 7; i < 10; i++)
	{
		if(masv[i] < '0' || masv[i] > '9')
		{
			return false;
		}
	}
	for(int i = 3; i < 7; i++)
	{
		if(masv[i] < 'A' || masv[i] > 'Z')
		{
			return false;
		}
	}	
	
	return true;
}
// ==================== CHECK CH DA THI ==========================
bool CheckCHDaThi (dslop dsl, int idMH, int idCH)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		for(nodeSV *k = dsl.l[i]->danhsach.First;k != NULL ;k=k->pNext)
		{
			for(nodediemThi *p = k->info.diem.First; p != NULL; p=p->pNext)
			{
				if(p->info.idMonHoc == idMH){
					for(int j = 0; j < p->info.ctdt.sct; j++)
					{
						if(p->info.ctdt.bode[j] == idCH)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
// ==================== KIEM TRA NHAP DU HO TEN  ==========================
bool CheckFormTen (string text)
{
	for(int i = 0; i < text.length();i++)
	{
		if(text[i] == ' ')
		{
			return true;
		}
	}
	return false;
}
// ==================== DEM SO LAN THI  ==========================
int DemLanThi(dsdiemThi diem)
{
	int dem = 0;
	for (nodediemThi *k = diem.First; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
// ==================== NHAP LOP THEM ==========================
void NhapLop(dslop &dsl, int page)
{	
	TextColor(241);
	gotoxy(5,38);
	veKhung(5,120);
	gotoxy(7,40);
	cout << "Ma lop :";
	gotoxy(15,39);
	veKhung(3,30);
	gotoxy(80,40);
	cout << "Ten lop :";
	gotoxy(88,39);
	veKhung(3,35);
	int maxpage;
	string tenlop;
	string malop;
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
				if(state == true)
				{
					gotoxy(17+malop.length(),40);
				}
				else
				{
					gotoxy(90+tenlop.length(),40);	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+malop.length(),40);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenlop.length(),40);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')  ) && sCheck == true)
		{
			HienConTro();
			if (state == false )
			{
				if (tenlop.length() < 30)
				{
					cout << InHoa(s);
					tenlop += InHoa(s);
				}
			}
			else 
			{
				if (malop.length() < 20)
				{
					cout << InHoa(s);
					malop += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenlop.length() == 0)
					{
						gotoxy(90+tenlop.length(),40);
					}
					else if(tenlop[tenlop.length()-1]!= ' ')
					{
						cout << InHoa(s);
						tenlop += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenlop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					tenlop.erase(tenlop.length()-1);
				}
			}
			else
			{
				if (malop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					malop.erase(malop.length()-1);
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						TextColor(241);
						cout << "                                      ";
						gotoxy(68,6+i);
						TextColor(241);
						HienConTro();
						cout << "                                      ";
					}
				page ++;
				InDSLop(dsl,page);
				
			}
			if(state == true)
			{
				gotoxy(17+malop.length(),40);
			}
			else
			{
				gotoxy(90+tenlop.length(),40);	
			}
			HienConTro();
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 29;i++)
				{
						gotoxy(6,6+i);
						TextColor(241);
						cout << "                                      ";
						gotoxy(68,6+i);
						TextColor(241);
						HienConTro();
						cout << "                                      ";
				}
				page--;
				InDSLop(dsl,page);
			}
			if(state == true)
			{
				gotoxy(17+malop.length(),40);
			}
			else
			{
				gotoxy(90+tenlop.length(),40);	
			}
			HienConTro();
		}
		if (s == ENTER)
		{
			AnConTro();
			ChuanHoaTen(tenlop);
			if(tenlop.length() == 0 || malop.length() == 0)
			{
				tb = "Ban chua nhap ten lop hoac ma lop, vui long dien day du thong tin";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+malop.length(),40);
			}
			else
			{
				if(CheckFormMaLop(malop) == false)
				{
					XoaTB(130,26);
					tb = "Ban nhap sai dinh dang ma lop, vui long nhap lai";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(17+malop.length(),40);
				}
				else
				{
					if(CheckLopNhap(dsl,malop,tenlop) == false)
					{
						XoaTB(130,26);
						tb = "Ma lop hoac ten lop da bi trung, vui long nhap lai";
						InTB(tb,129,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						gotoxy(17+malop.length(),40);
					}
					else
					{
						int n = dsl.solop;
						dsl.l[n] = new lop;
						dsl.l[n]->maLop = malop;
						dsl.l[n]->tenLop = tenlop;
						dsl.solop++; 
						AnConTro();
						XoaTB(130,26);
						gotoxy(130,30);
						tb = "Them thanh cong";
						InTB(tb,129,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						HienConTro();
					}
				}
			}
			for(int i = 0; i < 29;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(68,6+i);
				HienConTro();
				cout << "                                      ";
			}
			InDSLop(dsl,page);
			malop = "";
			tenlop = "";
			gotoxy(17,40);
			cout << "                           ";
			gotoxy(90,40);
			cout << "                           ";
			gotoxy(17+malop.length(),40);
			HienConTro();
			state = true;
		}
		batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,38+i);
		TextColor(241);
		cout << "                                                                                                                        ";
	}
}
// ==================== THEM LOP ==========================
void ThemLop(dslop &dsl, int page)
{
	TextColor(241);
	int n = dsl.solop;
	if(n  == MAXLOP)
	{
		gotoxy(130,26);
		string tb = "Khong the them lop, danh sach lop da day";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLop(dsl,page);
	}
}
// ==================== IN DANH SACH SINH VIEN ==========================
void InDSSV (lop *l,int page)
{
	if (l->danhsach.First == NULL)
	{
		return;
	}
	int k = 2;
	int sl = DemSV(l->danhsach);
	int maxpage;
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	nodeSV *j = new nodeSV;
	if (page == 0)
	{
		j = l->danhsach.First;
	}
	else
	{
		j = l->danhsach.First;
		for (int i=0; i<page*10; i++)
		{
			if (j->pNext != NULL)
			{
				j = j->pNext;
			}
		}	
	}
	
	for(int i = 0; i < 10; i++)
	{
		if (j->pNext != NULL) 
		{ 
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(40,4+k);
			cout << j->info.ho << " " << j->info.ten;
			gotoxy(80+(25-j->info.gioiTinh.length())/2,4+k);
			cout << j->info.gioiTinh;
			k += 3;
			j = j->pNext;
		}
		else {
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(40,4+k);
			cout << j->info.ho << " " << j->info.ten;
			gotoxy(80+(25-j->info.gioiTinh.length())/2,4+k);
			cout << j->info.gioiTinh;
			k += 3;
			break;
		}
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
// ==================== NHAP SINH VIEN ==========================
void NhapSinhVien(lop *&l )
{
	AnConTro();
	int maxpage;
	TextColor(241);
	gotoxy(127,26);
	vekhungTB(10,36);
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	gotoxy(140-18,22);
	cout << "NHAP SINH VIEN";
	gotoxy(110,2);
	veKhung(20,44);
	gotoxy(112,2+3);
	cout << "Ma SV:";
	gotoxy(122,2+2);
	veKhung(3,30);
	gotoxy(112,2+7);
	cout << "Ho va Ten:";
	gotoxy(122,2+6);
	veKhung(3,30);
	gotoxy(112,2+11);
	cout << "Gioi Tinh:";
	veNut(3,9,123,12,"NAM",112);
	veNut(3,9,142,12,"NU",30);
	gotoxy(112,2+15);
	cout << "Mat khau:";
	gotoxy(122,2+14);
	veKhung(3,30);
	int hd , td;
	int page = 0;
	string mk;
	string masv;
	string hoten;
	string gt = "NAM";
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(124,2+3);
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
				switch(state)
				{
					case 0:
						{
							gotoxy(124+masv.length(),3+2);
							break;
						}
					case 1:	
						{
							gotoxy(124+hoten.length(),3+6);
							break;
						}
					case 2:
						{
							gotoxy(124+mk.length(),3+14);
							break;
						}	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if(DemSV(l->danhsach) < 10)
		{
			maxpage = 0;
		}
		else if(DemSV(l->danhsach) % 10 == 0)
		{
			maxpage = DemSV(l->danhsach)/10 - 1;
		}
		else maxpage = DemSV(l->danhsach)/10;
		HienConTro();
		if(s == LEFT )
		{
			hd = wherex();
			td = wherey();
			veNut(3,9,123,12,"NAM",112);
			veNut(3,9,142,12,"NU",30);
			gotoxy(hd,td);
			gt = "NAM";
			
		}
		if(s == RIGHT )
		{
			hd = wherex();
			td = wherey();
			veNut(3,9,123,12,"NAM",30);
			veNut(3,9,142,12,"NU",112);
			gotoxy(hd,td);
			gt = "NU";
		}
		if (s == UP && sCheck == false)
		{
			HienConTro();
			switch(state)
			{
				case 1:
					{
						gotoxy(124+masv.length(),3+2);
						state --;
						break;
					}
				case 2:	
					{
						gotoxy(124+hoten.length(),3+6);
						state --;
						break;
					}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						gotoxy(124+hoten.length(),3+6);
						state ++;
						break;
					}
				case 1:	
					{
						gotoxy(124+mk.length(),3+14);
						state ++;
						break;
					}
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))  && sCheck == true)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						if(masv.length() < 11)
						{
							cout << InHoa(s);
							masv += InHoa(s);
						}
						break;
					}
				case 1:	
					{
						if(hoten.length() < 26)
						{
							cout << InHoa(s);
							hoten += InHoa(s);
						}
						break;
					}
				case 2:
					{
						if(mk.length() < 26)
						{
							cout << "*";
							mk += s;	
						}
						break;
					}	
			}
		}
		if(s == ' ')
		{
			if(state == 1)
				{
					if(hoten.length() == 0)
					{
						gotoxy(124+hoten.length()-1,3+6);
					}
					if(hoten[hoten.length()-1]!= ' ')
					{
						cout << InHoa(s);
						hoten += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			switch(state)
			{
				case 0:
					{
						if (masv.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							cout << " ";
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							HienConTro();
							masv.erase(masv.length()-1);
						}
						break;
					}
				case 1:
					{
						if (hoten.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							cout << " ";
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							HienConTro();
							hoten.erase(hoten.length()-1);
						}
						break;
					}
				case 2:
					{
						if (mk.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							cout << " ";
							gotoxy(wherex()-1,wherey());
						TextColor(241);
							HienConTro();
							mk.erase(mk.length()-1);
						}
						break;
					}	
			}	
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page ++;
				InDSSV(l,page);
				gotoxy(124+masv.length(),3+2);
				HienConTro();
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page--;
				InDSSV(l,page);
				gotoxy(124+masv.length(),3+2);
				HienConTro();
			}
		}
		if (s == ENTER)
		{
			for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
			bool ktten = false;
			ChuanHoaTen(hoten);
			sinhVien sv;
			sv.maSV = masv;
			sv.ho = TachHoSV(hoten);
			gotoxy(1,1);
			sv.ten = TachTenSV(hoten);
			sv.password = mk;
			sv.gioiTinh = gt;
			for(int i = 0; i < hoten.length(); i ++)				// can it nhat 1 dau cach de phan biet ho va ten
			{
				if (hoten[i] == ' ')
				{
					ktten = true;
					break;
				}
			}	
			if (masv.length() == 0 || hoten.length() == 0 || mk.length() == 0)
			{
				string tb = "Vui long dien day du thong tin sinh vien";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				if(CheckFormMaSv(masv) == true)
				{
						if(CheckMaSV(l,masv) == false)
						{
							string tb = "Ma sinh vien da co trong danh sach";
							InTB(tb,129,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
						}
						else
						{
							if(ktten == true)
							{
								Them1SinhVien(l,sv);
								string tb = "Them sinh vien vao danh sach thanh cong";
								InTB(tb,129,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
							}
							else
							{
								string tb = "Ho ten khong dung dinh dang, vui long nhap lai";
								InTB(tb,129,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
							}
						} 
				}
				else
				{
					string tb = "Ma sinh vien khong dung dinh dang, vui long nhap lai";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
			}			
			InDSSV(l,page);
			masv = "";
			hoten = "";
			mk = "";
			gotoxy(124+masv.length(),3+2);
			cout << "                           ";
			gotoxy(124+masv.length(),7+2);
			cout << "                           ";
			gotoxy(124+masv.length(),15+2);
			cout << "                           ";
			gotoxy(124+masv.length(),3+2);
			HienConTro();
			state = 0;
		}
	batPhim(s,sCheck);
	}
	for (int i=2; i<23; i++)
	{
		gotoxy(110,i);
		cout << "                                             ";
	}
	AnConTro();
}
// ==================== XOA SINH VIEN ==========================
void XoaSinhVien(lop *&l ,int page)
{
	for (int i=2; i<23; i++)
	{
		gotoxy(110,i);
		cout << "                                             ";
	}
	AnConTro();
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	gotoxy(110,2);
	gotoxy(7,6);
	cout << muiten;
	int maxpage;
	int state = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) % 10 == 0) 
		{
			maxpage = DemSV(l->danhsach)/10;
		}
		else maxpage = DemSV(l->danhsach)/10 + 1;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
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
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InDSSV(l,page);
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
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < maxpage)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                      ";
							gotoxy(31,6+i);
							cout << "                                             ";
							gotoxy(81,6+i);
							cout << "                      ";
						}
					}
					page++;
					InDSSV(l,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(k->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage -1)
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSSV(l,page);
				gotoxy(hd,td);
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
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSSV(l,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			string tb = "Ban co chac chan muon sinh vien nay ? (Y/N)";
			InTB(tb,129,30);
			nodeSV *k = l->danhsach.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (k->pNext != NULL)
				{
					k = k->pNext;
				}
			}
			batPhim(s,sCheck);
			while(s != ESC)
			{
				AnConTro();
				if((s == 'y' || s == 'Y')&& sCheck == true)
				{
					DeleteInfo_SV(l->danhsach, k->info.maSV);
					XoaTB(130,26);
					gotoxy(132,30);
					tb = "Xoa sinh vien thanh cong";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					break;
					
				}
				else if((s == 'n' || s == 'N') && sCheck == true)
				{
					XoaTB(130,26);
					break;
				}
				batPhim(s,sCheck);
			}
			for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}	
			page = 0;
			int hd = wherex();
			int td = wherey();
			if (l->danhsach.First != NULL)
			{
				InDSSV(l,page);
				gotoxy(hd,td);
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;	
			}
			else 
			{
				break;
			}
				
		}
	batPhim(s,sCheck);
	}
	
}
// ==================== NHAP MON HOC THEM ==========================
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
				if (tenmon.length() < 70)
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
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
//Tim node
DSMH FindNode(DSMH p, int id)
{
    while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->left;
	else
	p = p->right;
	return p;
}
//check mon nhap
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
// Kiem Tra Node dau
bool checkFistNode(DSMH p){
	if(p){
		if(p->id == 5000 && p->mh.MAMH.compare(" ") == 0 && p->mh.TENMH.compare(" ") == 0)
			return false;
		return true;
	}
}
// ==================== THEM MON ==========================
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
// ==================== CHECK MON DA THI ==========================
bool CheckDaThi (int idMon,dslop dsl)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		for(nodeSV *k = dsl.l[i]->danhsach.First;k != NULL ;k=k->pNext)
		{
			for(nodediemThi *p = k->info.diem.First; p != NULL; p=p->pNext)
			{
				if(p->info.idMonHoc == idMon)
				{
					return true;// co thi roi
				}
			}
		}
	}
	return false;
}
// ==================== FUNCTION MON HOC ==========================
void FunctionMH(DSMH &dsm, dslop dsl, int &idlonnhat, int arr1[], int arr2[])
{
	gotoxy(0,0);
	TextColor(241);
	veKhungThuCong();
	gotoxy(20,43);
	TextColor(241);
	TextColor(241);
	cout << "ENTER: Chon xem cau hoi   ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them mon hoc    F2: Sua mon hoc    F3: Xoa mon";
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
						TextColor(241);
						cout << " ";
						state --;
						gotoxy(7,wherey() - 3);
						TextColor(241);
						cout << muiten;
					}
				}
				if(page > 0)
				{
					if((state > 0) )
					{
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						TextColor(241);
						cout << " ";
						state --;
						gotoxy(7,wherey()-3);
						TextColor(241);
						cout << muiten;
					}
					else if(state == 0)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(15,6+i);
							TextColor(241);
							cout << "      ";
							gotoxy(37,6+i);
							TextColor(241);
							cout << "          ";
							gotoxy(57,6+i);
							TextColor(241);
							cout << "                                                             ";
						}
						gotoxy(7,6);
						TextColor(241);
						cout << " ";
						page --;
						InDSMH_CoCauHoi(dsm,page, maxpage, arr);
						gotoxy(7,33);
						cout << muiten;
						TextColor(241);
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
						TextColor(241);
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
					gotoxy(7,6 + 3*state);
					cout<<muiten;
			}
			if(s == F3){
				if(ExitXoa("Ban co chac chan xoa mon hoc?   (Y/N)", s, sCheck) == true){
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
						gotoxy(7, 6 + 3*state);
						cout<<" ";
						gotoxy(7, 6 + 3*state);
						cout<<muiten;
					}	
				}else{
						gotoxy(7, 6 + 3*state);
						cout<<" ";
						gotoxy(7, 6 + 3*state);
						cout<<muiten;
				}
			}
			if(s == F1){
				NhapMonHoc_Test(dsm,sl, page, maxpage, idlonnhat, arr,arr1,arr2);
				gotoxy(7,6 +3*state);
				cout<<muiten;
			}
			if(s == ENTER)
			{
				int iEntner = page*10 +state;
				int idEntner = *arr[iEntner];
				system("cls");
				FunctionCauHoi(dsm, dsl, idEntner, idlonnhat);
				gotoxy(127,2);
				xoaKhungTTMH(10,36);
				XoaTB(130, 26);
				gotoxy(20,43);
	TextColor(241);
				cout << "ENTER: Chon xem cau hoi   ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them mon hoc    F2: Sua mon hoc    F3: Xoa mon";
				gotoxy(5,2);
				vekhungDSMH_CoCauHoi(34,120,5);
				InDSMH_CoCauHoi(dsm, page, maxpage, arr);
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
				
			}
		batPhim(s,sCheck);
	}
}
void xoaKhungTTMH(int dai, int rong)
{
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			cout<<" ";
		}
		gotoxy(wherex() - rong,wherey()+1);
	}
}

void InDSCHMon (DSCH ch, int &page, int maxpage)
{
	if (ch.n == 0)
	{
		return;
	}
	int k = 2;
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
//Cau Hoi trong mon hoc

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
void FunctionCauHoi(DSMH & dsm, dslop dsl, int id, int idlonnhat)
{
	DSMH pTam = Search_MH(dsm,id);
	gotoxy(0,0);
	veKhungThuCong();
	xoaKhungThemCH();
	AnConTro();
	gotoxy(20,43);
	TextColor(241);
	cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
	gotoxy(127, 2);
	vekhungTTMH(pTam->mh, 10, 56);
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
		InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
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
				LuuFileMH(dsm,"DSMONHOCVACH.txt",idlonnhat);
				gotoxy(127,2);
				xoaKhungTTMH(10,56);
				gotoxy(20,43);
	TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						cout << "                                                                                              ";
					}
					gotoxy(7,6);
					cout << " ";
					page --;
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
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
						TextColor(241);
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(8,6+i);
							cout << "      ";
							gotoxy(17,6+i);
							cout << "                                                                                              ";
						}
					}
					page++;
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
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
						TextColor(241);
				cout << " ";
				for(int i = 0; i < 28;i++)
				{
						gotoxy(8,6+i);
						cout << "      ";
						gotoxy(17,6+i);
						cout << "                                                                                              ";
				}
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
				gotoxy(7,6);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				for(int i = 0; i < 28;i++)
				{
						gotoxy(8,6+i);
						cout << "      ";
						gotoxy(17,6+i);
						cout << "                                                                                              ";
				}
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
				gotoxy(7,6);
			}
		}
		if(s == F1){
			NhapCauHoiThem(dsm, id);
			xoaKhungThemCH();
			gotoxy(5,2);
			vekhungDSCH_Test(34,120,2);
			pTam = Search_MH(dsm,id);
			InDSCHMon(pTam->mh.cauHoiMH, page, maxpage);
			state = 0;
			gotoxy(20,43);
	TextColor(241);
			cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
			gotoxy(7, 6 + 3*state);
			AnConTro();
			cout<<muiten;
		}
		if(s == F2){
			if(CheckCHDaThi(dsl, id, (page*10 +state)) == true){
							XoaTB(130, 26);
							string tb = "Cau hoi da thi, Khong the sua!";
							InTB(tb,129,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
							gotoxy(7, 6 + 3*state);
							cout<<" ";
							gotoxy(7, 6 + 3*state);
							cout<<muiten;
			}
			else
			{
				SuaCauHoiTrongMH(pTam->mh.cauHoiMH, *pTam->mh.cauHoiMH.listCauHoi[page*10 + state],id, state);
				XoaKhungXemCH();
				gotoxy(5,2);
				vekhungDSCH_Test(34,120,2);
				gotoxy(127, 2);
				vekhungTTMH(pTam->mh, 10, 36);
				pTam = Search_MH(dsm,id);
				InDSCHMon(pTam->mh.cauHoiMH, page, maxpage);
				gotoxy(20,43);
	TextColor(241);
				cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
				gotoxy(7, 6 + 3*state);
				AnConTro();
				cout<<muiten;	
			}
		}
		if(s == F3){
			if(CheckCHDaThi(dsl, id, (page*10 +state)) == true){
							XoaTB(130, 26);
							string tb = "Cau hoi da thi, Khong the xoa!";
							InTB(tb,129,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
							gotoxy(7, 6 + 3*state);
							cout<<" ";
							gotoxy(7, 6 + 3*state);
							cout<<muiten;
			}
			else if(ExitXoa("Ban co chac chan xoa cau hoi?   (Y/N)", s, sCheck) == true)
			{
				xoaCauHoi(dsm, id, state, page);
				pTam = Search_MH(dsm,id);
				if(state > 0 && pTam->mh.cauHoiMH.n == (page * 10 + state)){
					XoaCauHoiDaXoa();
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state--;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state == 0 && pTam->mh.cauHoiMH.n == (page * 10 + state) && page !=0){
					page--;
					XoaCauHoiDaXoa();
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state = 9;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state > 0 && pTam->mh.cauHoiMH.n < 10 && page ==0 ){
					XoaCauHoiDaXoa();
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				} else{
					XoaCauHoiDaXoa();
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}
			}else{
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					InDSCHMon(pTam->mh.cauHoiMH,page, maxpage);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
			}
		}
		if(s == ENTER){
			xemCauHoi(*pTam->mh.cauHoiMH.listCauHoi[page*10 + state]);
			gotoxy(5,2);
			vekhungDSCH_Test(34,120,2);
			gotoxy(127, 2);
			vekhungTTMH(pTam->mh, 10, 36);
			pTam = Search_MH(dsm,id);
			InDSCHMon(pTam->mh.cauHoiMH, page, maxpage);
			gotoxy(20,43);
	TextColor(241);
			cout << "ENTER: Chon    ESC: Thoat    PGUP: Qua trang    PGDOWN: Lui trang    F1: Them cau hoi    F2: Sua cau hoi    F3: Xoa cau hoi";
			gotoxy(7, 6 + 3*state);
			AnConTro();
			cout<<muiten;
		}
	batPhim(s,sCheck);
	}
}

void inCH(cauHoi ch){
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
	//in noi dung
	if(ch.noiDung.length() >95){
		int n = 95 ;
		if(ch.noiDung[n] == ' ')
		{
			gotoxy(hdnd, tdnd);
			for(int i = 0; i < 95; i++){
				cout<<ch.noiDung[i];
			}
			
			string temp = "";
			for(int i = n + 1; i < ch.noiDung.length(); i++){
				temp+= ch.noiDung[i];
			}
			if(temp.length() >95){
				int m = 95;
				if(temp[m] =' '){
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < 95; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
				}
				else
				{
					while(temp[m] != ' ')
					{
						n--;
					}
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < m; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
				}
			}
			else{
				gotoxy(hdnd, tdnd + 2);
				for(int i = n + 1; i < ch.noiDung.length(); i++){
					cout<<ch.noiDung[i];
				}
			}
		}
		else
		{
			while(ch.noiDung[n] != ' ')
			{
				n--;
			}
			gotoxy(hdnd, tdnd);
			for(int i = 0; i < n; i++){
				cout<<ch.noiDung[i];
			}
			string temp = "";
			for(int i = n + 1; i < ch.noiDung.length(); i++){
				temp+= ch.noiDung[i];
			}
			if(temp.length() >95){
				int m = 95;
				if(temp[m] =' '){
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < 95; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
				}
				else
				{
					while(temp[m] != ' ')
					{
						n--;
					}
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < m; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
				}
			}
			else{
				gotoxy(hdnd, tdnd + 2);
				for(int i = n + 1; i < ch.noiDung.length(); i++){
					cout<<ch.noiDung[i];
				}
			}
		}
	}else{
		gotoxy(hdnd, tdnd);
		cout<<ch.noiDung;
	}
	//in cau a
	if(ch.A.length() >95){
		int n = 95 ;
		if(ch.A[n] == ' ')
		{
			gotoxy(hda, tda);
			for(int i = 0; i < 95; i++){
				cout<<ch.A[i];
			}
			gotoxy(hda, tda + 2);
			for(int i = n + 1; i < ch.A.length(); i++){
				cout<<ch.A[i];
			}
		}
		else
		{
			while(ch.A[n] != ' ')
			{
				n--;
			}
			gotoxy(hda, tda);
			for(int i = 0; i < n; i++){
				cout<<ch.A[i];
			}
			gotoxy(hda, tda + 2);
			for(int i = n + 1; i < ch.A.length(); i++){
				cout<<ch.A[i];
			}
		}
	}else{
		gotoxy(hda, tda);
		cout<<ch.A;
	}
	//in cau b
	if(ch.B.length() >95){
		int n = 95 ;
		if(ch.B[n] == ' ')
		{
			gotoxy(hdb, tdb);
			for(int i = 0; i < 95; i++){
				cout<<ch.B[i];
			}
			gotoxy(hdb, tdb + 2);
			for(int i = n + 1; i < ch.B.length(); i++){
				cout<<ch.B[i];
			}
		}
		else
		{
			while(ch.B[n] != ' ')
			{
				n--;
			}
			gotoxy(hdb, tdb);
			for(int i = 0; i < n; i++){
				cout<<ch.B[i];
			}
			gotoxy(hdb, tdb + 2);
			for(int i = n + 1; i < ch.B.length(); i++){
				cout<<ch.B[i];
			}
		}
	}else{
		gotoxy(hdb, tdb);
		cout<<ch.B;
	}
	//in cau c
	if(ch.C.length() >95){
		int n = 95 ;
		if(ch.C[n] == ' ')
		{
			gotoxy(hdc, tdc);
			for(int i = 0; i < 95; i++){
				cout<<ch.C[i];
			}
			gotoxy(hdc, tdc + 2);
			for(int i = n + 1; i < ch.C.length(); i++){
				cout<<ch.C[i];
			}
		}
		else
		{
			while(ch.C[n] != ' ')
			{
				n--;
			}
			gotoxy(hdc, tdc);
			for(int i = 0; i < n; i++){
				cout<<ch.C[i];
			}
			gotoxy(hdc, tdc + 2);
			for(int i = n + 1; i < ch.C.length(); i++){
				cout<<ch.C[i];
			}
		}
	}else{
		gotoxy(hdc, tdc);
		cout<<ch.C;
	}
	//in cau d
	if(ch.D.length() >95){
		int n = 95 ;
		if(ch.D[n] == ' ')
		{
			gotoxy(hdd, tdd);
			for(int i = 0; i < 95; i++){
				cout<<ch.D[i];
			}
			gotoxy(hdd, tdd + 2);
			for(int i = n + 1; i < ch.D.length(); i++){
				cout<<ch.D[i];
			}
		}
		else
		{
			while(ch.D[n] != ' ')
			{
				n--;
			}
			gotoxy(hdd, tdd);
			for(int i = 0; i < n; i++){
				cout<<ch.D[i];
			}
			gotoxy(hdd, tdd + 2);
			for(int i = n + 1; i < ch.D.length(); i++){
				cout<<ch.D[i];
			}
		}
	}else{
		gotoxy(hdd, tdd);
		cout<<ch.D;
	}
	
		if(ch.dapAn == "A")
		{
			ChangeColor(175);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "B")
		{
			ChangeColor(175);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "C")
		{
			ChangeColor(175);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "D")
		{
			ChangeColor(175);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}	
}
void xemCauHoi(cauHoi ch)
{
	gotoxy(20,43);
	TextColor(241);
	cout << "                                                                                                                           ";
	gotoxy(5 + (120 - 2)/2,43);
	cout << "ENTER: Chon    ESC: Thoat";
	vekhungXemCH();
	inCH(ch);
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(1){
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{	
				XoaKhungXemCH();
				gotoxy(20,43);
	TextColor(241);
				cout << "                                                                                                                           ";
				break;
			}
			batPhim(s,sCheck);
		}
		batPhim(s,sCheck);
	}
}
void xoaCauHoi(DSMH &p, int id, int state, int page)
{
	if(p){
		if(id == p->id){
			for(int i = state + page*10; i < p->mh.cauHoiMH.n; i++){
				p->mh.cauHoiMH.listCauHoi[i] = p->mh.cauHoiMH.listCauHoi[i + 1];
			}
			p->mh.cauHoiMH.n--;
		}else if(id < p->id)
			xoaCauHoi(p->left, id, state, page);
		else
			xoaCauHoi(p->right, id, state, page);
	}
}
void inSuaCH(cauHoi ch, int &dem, int &xND, int &yND, int &xA, int &yA, int &xB, int &yB, int &xC, int &yC, int & xD, int &yD){
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
	//in noi dung
	if(ch.noiDung.length() >95){
		int n = 95 ;
		if(ch.noiDung[n] == ' ')
		{
			gotoxy(hdnd, tdnd);
			for(int i = 0; i < 95; i++){
				cout<<ch.noiDung[i];
			}
			
			string temp = "";
			for(int i = n + 1; i < ch.noiDung.length(); i++){
				temp+= ch.noiDung[i];
			}
			if(temp.length() >95){
				int m = 95;
				if(temp[m] =' '){
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < 95; i++){ 
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
					xND = wherex();
					yND = wherey();
				}
				else
				{
					while(temp[m] != ' ')
					{
						n--;
					}
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < m; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
					xND = wherex();
					yND = wherey();
				}
			}
			else{
				gotoxy(hdnd, tdnd + 2);
				for(int i = n + 1; i < ch.noiDung.length(); i++){
					cout<<ch.noiDung[i];
				}
				xND = wherex();
				yND = wherey();
			}
		}
		else
		{
			while(ch.noiDung[n] != ' ')
			{
				n--;
			}
			gotoxy(hdnd, tdnd);
			for(int i = 0; i < n; i++){
				cout<<ch.noiDung[i];
			}
			string temp = "";
			for(int i = n + 1; i < ch.noiDung.length(); i++){
				temp+= ch.noiDung[i];
			}
			if(temp.length() >95){
				int m = 95;
				if(temp[m] =' '){
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < 95; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
					xND = wherex();
					yND = wherey();
				}
				else
				{
					while(temp[m] != ' ')
					{
						n--;
					}
					gotoxy(hdnd, tdnd + 2);
					for(int i = 0; i < m; i++){
						cout<<temp[i];
					}
					gotoxy(hdnd, tdnd + 2 + 2);
					for(int i = m + 1; i < temp.length(); i++){
						cout<<temp[i];
					}
					xND = wherex();
					yND = wherey();
				}
			}
			else{
				gotoxy(hdnd, tdnd + 2);
				for(int i = n + 1; i < ch.noiDung.length(); i++){
					cout<<ch.noiDung[i];
				}
				xND = wherex();
				yND = wherey();
			}
		}
	}else{
		gotoxy(hdnd, tdnd);
		cout<<ch.noiDung;
		xND = wherex();
		yND = wherey();
	}
	//in cau a
	if(ch.A.length() >95){
		int n = 95 ;
		if(ch.A[n] == ' ')
		{
			gotoxy(hda, tda);
			for(int i = 0; i < 95; i++){
				cout<<ch.A[i];
			}
			gotoxy(hda, tda + 2);
			for(int i = n + 1; i < ch.A.length(); i++){
				cout<<ch.A[i];
			}
			xA = wherex();
			yA = wherey();
		}
		else
		{
			while(ch.A[n] != ' ')
			{
				n--;
			}
			gotoxy(hda, tda);
			for(int i = 0; i < n; i++){
				cout<<ch.A[i];
			}
			gotoxy(hda, tda + 2);
			for(int i = n + 1; i < ch.A.length(); i++){
				cout<<ch.A[i];
			}
			xA = wherex();
			yA = wherey();
		}
	}else{
		gotoxy(hda, tda);
		cout<<ch.A;
		xA = wherex();
		yA = wherey();
	}
	//in cau b
	if(ch.B.length() >95){
		int n = 95 ;
		if(ch.B[n] == ' ')
		{
			gotoxy(hdb, tdb);
			for(int i = 0; i < 95; i++){
				cout<<ch.B[i];
			}
			gotoxy(hdb, tdb + 2);
			for(int i = n + 1; i < ch.B.length(); i++){
				cout<<ch.B[i];
			}
			xB = wherex();
			yB = wherey();
		}
		else
		{
			while(ch.B[n] != ' ')
			{
				n--;
			}
			gotoxy(hdb, tdb);
			for(int i = 0; i < n; i++){
				cout<<ch.B[i];
			}
			gotoxy(hdb, tdb + 2);
			for(int i = n + 1; i < ch.B.length(); i++){
				cout<<ch.B[i];
			}
			xB = wherex();
			yB = wherey();
		}
	}else{
		gotoxy(hdb, tdb);
		cout<<ch.B;
		xB = wherex();
		yB = wherey();
	}
	//in cau c
	if(ch.C.length() >95){
		int n = 95 ;
		if(ch.C[n] == ' ')
		{
			gotoxy(hdc, tdc);
			for(int i = 0; i < 95; i++){
				cout<<ch.C[i];
			}
			gotoxy(hdc, tdc + 2);
			for(int i = n + 1; i < ch.C.length(); i++){
				cout<<ch.C[i];
			}
			xC = wherex();
			yC = wherey();
		}
		else
		{
			while(ch.C[n] != ' ')
			{
				n--;
			}
			gotoxy(hdc, tdc);
			for(int i = 0; i < n; i++){
				cout<<ch.C[i];
			}
			gotoxy(hdc, tdc + 2);
			for(int i = n + 1; i < ch.C.length(); i++){
				cout<<ch.C[i];
			}
			xC = wherex();
			yC = wherey();
		}
	}else{
		gotoxy(hdc, tdc);
		cout<<ch.C;
		xC = wherex();
		yC = wherey();
	}
	//in cau d
	if(ch.D.length() >95){
		int n = 95 ;
		if(ch.D[n] == ' ')
		{
			gotoxy(hdd, tdd);
			for(int i = 0; i < 95; i++){
				cout<<ch.D[i];
			}
			gotoxy(hdd, tdd + 2);
			for(int i = n + 1; i < ch.D.length(); i++){
				cout<<ch.D[i];
			}
			xD = wherex();
			yD = wherey();
		}
		else
		{
			while(ch.D[n] != ' ')
			{
				n--;
			}
			gotoxy(hdd, tdd);
			for(int i = 0; i < n; i++){
				cout<<ch.D[i];
			}
			gotoxy(hdd, tdd + 2);
			for(int i = n + 1; i < ch.D.length(); i++){
				cout<<ch.D[i];
			}
			xD = wherex();
			yD = wherey();
		}
	}else{
		gotoxy(hdd, tdd);
		cout<<ch.D;
		
		xD = wherex();
		yD = wherey();
	}
	
		if(ch.dapAn == "A")
		{
			ChangeColor(112);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "B")
		{
			ChangeColor(112);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "C")
		{
			ChangeColor(112);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "D")
		{
			ChangeColor(112);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}	
}
void SuaCauHoiTrongMH(DSCH &cauhoi, cauHoi ch, int id, int vitri)
{
	vekhungThemCH();
	gotoxy(20,43);
	TextColor(241);
	cout << "                                                                                                                           ";
	gotoxy(5 + (120 - 43)/2,43);
	cout << "ENTER: Chon    ESC: Thoat    LEN/XUONG: CHON NOI DUNG";
	int state = 0;
	int n;
	int dem = 0;
	string temp;
	char s;
	bool sCheck;
	int hdnd,tdnd,hda,tda,hdb,tdb,hdc,tdc,hdd,tdd;
	int xND, yND, xA,yA, xB, yB, xC, yC, xD, yD;
	inSuaCH(ch,dem, xND,yND, xA, yA, xB, yB, xC,yC, xD, yD);
	dem = 93;
	hdnd = xND;
	tdnd = yND;
	hda = xA;
	tda = yA;
	hdb = xB;
	tdb = yB;
	hdc = xC;
	tdc = yC;
	hdd = xD;
	tdd = yD;
	gotoxy(xND,yND);
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
							gotoxy(xND,yND);
							break;
						}
					case 1:
						{
							HienConTro();
							gotoxy(xA,yA);
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(xB,yB);
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(xC,yC);
							break;
						}
					case 4:
						{
							HienConTro();
							gotoxy(xD,yD);
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
							veNut(3,11,59,38,"LUU",112);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
								gotoxy(20 + ch.noiDung.length() - dem ,7);
								hdnd = wherex();
								tdnd = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
//							themCHVaoMonHoc(dsm, id, ch);
							suaCH(cauhoi, ch, vitri);
							XoaTB(130, 26);
							string tb = "Sua cau hoi thanh cong!";
							InTB(tb,129,30);
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
			}
		}
		batPhim(s,sCheck);
	}
}

void suaCH(DSCH &ch, cauHoi ch1, int state)
{
	for(int i = 0; i < ch.n; i++){
		if(i == state){
			ch.listCauHoi[i]->noiDung = ch1.noiDung;
			ch.listCauHoi[i]->A = ch1.A;
			ch.listCauHoi[i]->B = ch1.B;
			ch.listCauHoi[i]->C = ch1.C;
			ch.listCauHoi[i]->D = ch1.D;
			ch.listCauHoi[i]->dapAn = ch1.dapAn;
		}
	}
}
void NhapCauHoiThem(DSMH &dsm, int id)
{
	vekhungThemCH();
	gotoxy(20,43);
	TextColor(241);
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
							veNut(3,11,59,38,"LUU",112);
							state ++;
							break;
						}	
				}
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || (s == '?') || (s == ',')
		|| (s == ',')|| (s == '*')|| (s == '+')|| (s == '-')|| (s == '=')|| (s == '^')|| (s == '%')|| (s == '!')
		|| (s == '(')|| (s == ')')|| (s == '.')|| (s == '>')|| (s == '<')|| (s == '/')|| (s == '|')|| (s == '[')
		|| (s == ']')|| (s == '{')|| (s == '}')|| (s == ';')|| (s == ':')|| (s == '"')|| (s == '\''))  && sCheck == true)
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
										cout << " ";
										gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
								cout << " ";
								gotoxy(wherex()-1,wherey());
						TextColor(241);
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
			if(state == 0){
				gotoxy(0,0);
				cout<<"Dem: "<<dem;
			}
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
							InTB(tb,129,30);
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
//TB Xoa
bool ExitXoa (string tb, char &s, bool &sCheck)
{
	AnConTro();
	gotoxy(127,26);
	vekhungTB(10,36);
	InTB(tb,129,30);
	batPhim(s,sCheck);
	while(s != ESC)
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
		}
		batPhim(s,sCheck);
	}
	XoaTB(130,26);
}
//Xoa Mon

void xoaMMH_Test(DSMH &dsm, int &sl,int &state ,int &page, int &maxpage, int &idlonnhat, int *arr[])
{
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
//Sua mon
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
					if (tenmon.length() < 70)
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
						TextColor(241);
						cout << " ";
						gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
						cout << " ";
						gotoxy(wherex()-1,wherey());
						TextColor(241);
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
void suaThongTin1MonHoc(DSMH &p, int id, monHoc mh)
{
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
lop *traVeLopTuMSSV(dslop l, string MSSV){
	for(int i = 0; i < l.solop; i++){
		for(nodeSV *sv = l.l[i]->danhsach.First; sv != NULL; sv = sv->pNext){
			if(sv->info.maSV.compare(MSSV) == 0){
				return l.l[i];
			}
		}
	}
	return NULL;
}
void themDiemvaoDSLtheoMSV(dslop &l, string MSSV,diemThi diemsv){
	for(int i = 0; i < l.solop; i++){
		for(nodeSV *sv = l.l[i]->danhsach.First; sv != NULL; sv = sv->pNext){
			if(sv->info.maSV.compare(MSSV) == 0){
				if (sv->info.diem.First == NULL) 
						Insert_Diem_First(sv->info.diem.First,diemsv);
				else 
				{
					nodediemThi *p = sv->info.diem.First;
					while (p->pNext != NULL)
					{
						p = p->pNext;
					}
					Insert_Diem_after(p,diemsv);
				}
			}
		}
	}
}
// ==================== NHAP LOP XOA ==========================
void NhapLopXoa(dslop &dsl,int &page)
{
	AnConTro();
	string tb;
	int maxpage;
	InDSLop(dsl,page);
	string malop;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			AnConTro();
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			AnConTro();
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(68,6+i);
							HienConTro();
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
					cout << "                                      ";
					gotoxy(68,6+i);
					HienConTro();
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
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
					cout << "                                      ";
					gotoxy(68,6+i);
					HienConTro();
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if( DemSV(dsl.l[state + page * 10]->danhsach) > 0)
			{
				tb = "Lop ton tai sinh vien";
				string tb1 = "Khong the xoa!" ;
				InTB(tb,129,30);
				InTB(tb1,130,31);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				tb = "Ban co chac chan muon xoa lop nay ? (Y/N)";
				InTB(tb,129,30);
				batPhim(s,sCheck);
				while(s != ESC)
				{
					AnConTro();
					if((s == 'y' || s == 'Y')&& sCheck == true)
					{
						for(int i = state + page*10; i < dsl.solop; i++)
						{
							dsl.l[i] = dsl.l[i+1];
						}
						dsl.solop --;
						XoaTB(130,26);
						gotoxy(130,30);
						tb = "Xoa lop thanh cong";
						InTB(tb,129,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						break;
					}
					else if((s == 'n' || s == 'N') && sCheck == true)
					{
						XoaTB(130,26);
						break;
					}
					batPhim(s,sCheck);
				}
			}
			for(int i = 0; i < 28;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(68,6+i);
				HienConTro();
				cout << "                                      ";
			}
				
			page = 0;
			int hd = wherex();
			int td = wherey();
			InDSLop(dsl,page);
			gotoxy(hd,td);
			cout << " ";
			state = 0;
			gotoxy(7,6);
			cout << muiten;	
		}
	batPhim(s,sCheck);
	}
}
// ==================== XOA LOP ==========================
void XoaLop (dslop &dsl, int &page)
{
	int n = dsl.solop;
	string tb;
	if(n  == 0)
	{
		tb = "Danh sach lop hien tai dang trong";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopXoa(dsl, page);
	}
}
// ==================== SUA LOP ==========================
void SuaLop(lop *&l)
{
	gotoxy(5,38);
	veKhung(5,120);
	gotoxy(7,40);
	cout << "Ma lop :";
	gotoxy(15,39);
	veKhung(3,30);
	gotoxy(80,40);
	cout << "Ten lop :";
	gotoxy(88,39);
	veKhung(3,35);
	bool state = true;
	char s;
	bool sCheck;
	string tenlop = l->tenLop;
	string malop = l->maLop;
	gotoxy(17,40);
	cout << malop;
	gotoxy(90,40);
	cout << tenlop;
	gotoxy(17+malop.length(),40);
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
				if(state == true)
				{
					gotoxy(17+malop.length(),40);
				}
				else
				{
					gotoxy(90+tenlop.length(),40);	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+malop.length(),40);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenlop.length(),40);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (state == true)
			{
				if (malop.length() < 10)
				{
					cout << InHoa(s);
					malop += InHoa(s);
				}
			}
			else
			{
				if (tenlop.length() < 30)
				{
					cout << InHoa(s);
					tenlop += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenlop.length() == 0)
					{
						gotoxy(90+tenlop.length()-1,40);
					}
					if(tenlop[tenlop.length()-1] != ' ')
					{
						cout << InHoa(s);
						tenlop += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenlop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					tenlop.erase(tenlop.length()-1);
				}
			}
			else
			{
				if (malop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					malop.erase(malop.length()-1);
				}
			}
		}
		if(s == ENTER)
		{
			if(malop.length() == 0 && tenlop.length() == 0)
			{
				string tb = "Khong duoc de thieu thong tin!";
				gotoxy(129,30);
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+malop.length(),40);
				HienConTro();
				state = true;
			}
			else if(malop.length() == 0)
			{
				string tb = "Khong de trong ma lop!";
				gotoxy(129,30);
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+malop.length(),40);
				HienConTro();
				state = true;
			}
			else if(tenlop.length() == 0)
			{
				string tb = "Khong de trong ma lop!";
				gotoxy(129,30);
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(90+tenlop.length(),40);
				HienConTro();
				state = false;
			}
			else
			{
				if(CheckFormMaLop(malop) == false)
				{
					string tb = "Sai dinh dang ma lop!";
					gotoxy(129,30);
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					state = true;
					gotoxy(17+malop.length(),40);
					HienConTro();
				}
				else
				{
					l->tenLop = tenlop;
					l->maLop = malop;
					break;
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
// ==================== NHAP LOP CHINH ==========================
void NhapLopChinh(dslop &dsl , int &page)
{
	AnConTro();
	int maxpage;
	InDSLop(dsl,page);
	string malop;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			AnConTro();
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			AnConTro();
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(68,6+i);
							HienConTro();
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
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
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if( DemSV(dsl.l[state + page * 10]->danhsach) > 0)
			{
				string tb = "Lop ton tai sinh vien";
				string tb1 = "Khong the chinh sua";
				InTB(tb,129,30);
				InTB(tb1,130,31);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				// ham nhap thong tin de sua
				SuaLop(dsl.l[state + page * 10]);
				AnConTro();
			}
			for(int i = 0; i < 28;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(68,6+i);
				HienConTro();
				cout << "                                      ";
			}
			page = 0;
			int hd = wherex();
			int td = wherey();
			InDSLop(dsl,page);
			gotoxy(hd,td);
			cout << " ";
			state = 0;
			gotoxy(7,6);
			cout << muiten;
		}
	batPhim(s,sCheck);
	}
}

// ==================== CHINH LOP ==========================
void ChinhLop(dslop &dsl, int &page)
{
	int n = dsl.solop;
	if(n  == 0)
	{
		string tb = "Danh sach lop hien tai dang trong";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopChinh(dsl, page);
	}
}

// ==================== FUNCTION LOP ==========================
void FunctionLop(dslop &dsl)
{
	// ve bang + chuc nang trai phai de qua trang;
	// 3 nut them xoa sua lop + len xuong
	// thong bao
	// bang nhap thong tin
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(50,43);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	int maxpage;
	gotoxy(127,26);
	vekhungTB(10,36);
	int page = 0;
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	vekhungDS(34,120,2);	
	veNut(3,15,140,10,"Them lop",112);
	veNut(3,15,140,15,"Xoa lop",30);
	veNut(3,15,140,20,"Sua lop",30);
	gotoxy(35,3);
	cout << "TEN LOP";
	gotoxy(90,3);
	cout << "MA LOP";
	if (dsl.solop != 0) 
	{
		InDSLop(dsl,page);
	}
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,140,15,"Xoa lop",30);
					veNut(3,15,140,10,"Them lop",112);
					break;
				}
			case 2:
				{
					state--;
					veNut(3,15,140,20,"Sua lop",30);
					veNut(3,15,140,15,"Xoa lop",112);
					break;
				}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,140,10,"Them lop",30);
					veNut(3,15,140,15,"Xoa lop",112);
					break;
				}
			case 1:
				{
					state++;
					veNut(3,15,140,15,"Xoa lop",30);
					veNut(3,15,140,20,"Sua lop",112);
					break;
				}
			case 2:
				{
					break;
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
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
					}
				page ++;
				InDSLop(dsl,page);
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
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
				}
				page--;
				InDSLop(dsl,page);
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						ThemLop(dsl,page);
						AnConTro();
						break;
					}
				case 1:
					{
						XoaLop(dsl,page);
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(68,6+i);
							cout << "                                      ";
						}
						InDSLop(dsl,page);
						AnConTro();
						break;
					}
				case 2:
					{
						ChinhLop(dsl,page);
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(68,6+i);
							cout << "                                      ";
						}
						InDSLop(dsl,page);
						AnConTro();
						break;
					}	
			}
		}
	batPhim(s,sCheck);	
	}
}
// ====================SELECT FUNCTION SV ==========================
void selectFunctionSV(lop *&l ,int page)
{
	system("cls");
	gotoxy(0,0);
	TextColor(241);
	veKhungThuCong();
	gotoxy(50,43);
	TextColor(241);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang	LEFT,RIGHT: Chon gioi tinh";
	gotoxy(127,26);
	vekhungTB(10,36);
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	gotoxy(5,2);
	VeKhungDSLop(34,100,4);
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	InDSSV(l,page);	
	veNut(3,15,120,10,"Them SV",112);
	veNut(3,15,120,15,"Xoa SV",30);
	int maxpage;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) < 10)
		{
			maxpage = 0;
		}
		else if(DemSV(l->danhsach) % 10 == 0)
		{
			maxpage = DemSV(l->danhsach)/10 - 1;
		}
		else maxpage = DemSV(l->danhsach)/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,120,15,"Xoa SV",30);
					veNut(3,15,120,10,"Them SV",112);
					break;
				}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,120,10,"Them SV",30);
					veNut(3,15,120,15,"Xoa SV",112);
					break;
				}
			case 1:
				{
					break;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page ++;
				InDSSV(l,page);
				AnConTro();
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page--;
				InDSSV(l,page);
				AnConTro();
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						gotoxy(120,10);
						cout << "               ";
						cout << "               ";
						cout << "               ";
						gotoxy(120,15);
						cout << "               ";
						cout << "               ";
						cout << "               ";
						NhapSinhVien(l);
						gotoxy(15,3);
						cout << "MA SV";
						gotoxy(50,3);
						cout << "HO VA TEN";
						gotoxy(88,3);
						cout << "GIOI TINH";
						InDSSV(l,page);	
						veNut(3,15,120,10,"Them SV",112);
						veNut(3,15,120,15,"Xoa SV",30);	
						break;
					}
				case 1:
					{
						if (l->danhsach.First == NULL)
						{
							string tb = "Danh sach SV hien dang trong! Khong the xoa!";
							InTB(tb,129,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							break;
						}
						else 
						{
							gotoxy(120,10);
							cout << "               ";
							cout << "               ";
							cout << "               ";
							gotoxy(120,15);
							cout << "               ";
							cout << "               ";
							cout << "               ";
							XoaSinhVien(l,page);	
							gotoxy(15,3);
							cout << "MA SV";
							gotoxy(50,3);
							cout << "HO VA TEN";
							gotoxy(88,3);
							cout << "GIOI TINH";
							if (l->danhsach.First == NULL)
							{
								string tb = "Danh sach SV hien dang trong! Khong the tiep tuc xoa!";
								InTB(tb,129,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
								gotoxy(7,6);
								cout << " ";
								veNut(3,15,120,10,"Them SV",30);
								veNut(3,15,120,15,"Xoa SV",112);
								break;
							}
							else 
							{
								InDSSV(l,page);	
								gotoxy(7,6);
								cout << " ";
								veNut(3,15,120,10,"Them SV",30);
								veNut(3,15,120,15,"Xoa SV",112);	
								break;	
							}							
						}
					}
			}
		}
	batPhim(s,sCheck);	
	}
}
int countDemThiTrongSV(dsdiemThi dsDiem ){
	int dem = 0;
	for(nodediemThi *p = dsDiem.First; p != NULL; p = p->pNext){
		dem++;
	}
	return dem;
}
// ==================== FUNCTION SINH VIEN ==========================
void FunctionSV(dslop &dsl)
{
	gotoxy(0,0);
	TextColor(241);
	veKhungThuCong();
	gotoxy(50,43);
	TextColor(241);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(127,26);
	vekhungTB(10,36);
	int page = 0;
	int maxpage;
	int hd;
	int td;	
	gotoxy(5,2);
	vekhungDS(34,120,2);
	gotoxy(35,3);
	cout << "TEN LOP";
	gotoxy(90,3);
	cout << "MA LOP";
	InDSLop(dsl,page);
	string malop = "";
	gotoxy(7,6);
	cout << muiten;
	int state = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		ChangeColor(15);
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					TextColor(241);
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
					TextColor(241);
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
						TextColor(241);
						cout << "                                      ";
						gotoxy(68,6+i);
						TextColor(241);
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
					TextColor(241);
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					TextColor(241);
					cout << muiten;
					state = 9;	
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					TextColor(241);
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							TextColor(241);
							cout << "                                      ";
							gotoxy(68,6+i);
							TextColor(241);
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					TextColor(241);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					TextColor(241);
					cout << " ";
					gotoxy(7,wherey());
					TextColor(241);
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
					TextColor(241);
					cout << "                                      ";
					gotoxy(68,6+i);
					TextColor(241);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				hd = wherex();
				td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
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
					TextColor(241);
					cout << "                                      ";
					gotoxy(68,6+i);
					TextColor(241);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				hd = wherex();
				td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if ( s == ENTER)
		{
			//qua phai ve 2 nut them sinh vien, xoa sinh vien, enter chon chuc nang (giong funclop)
			selectFunctionSV(dsl.l[state + page*10],page);
			system("cls"); 
			gotoxy(0,0);
			TextColor(241);
			veKhungThuCong();
			gotoxy(50,43);
			cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
			gotoxy(127,26);
			vekhungTB(10,36);
			gotoxy(5,2);
			vekhungDS(34,120,2);
			gotoxy(35,3);
			cout << "TEN LOP";
			gotoxy(90,3);
			cout << "MA LOP";
			InDSLop(dsl,page);
			state = 0;
			AnConTro();
			gotoxy(7,6);
			cout << muiten;	
		}
		batPhim(s,sCheck);
	}
}
// ==================== KHOI TAO MANG RANDOM ==========================
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
// ==================== RAMDOM 1 SO ==========================
int random(int minN, int maxN)
{
	srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}
// ==================== DEM NUT CAY ==========================
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
int rdMang (int arr[], int sch)
{
	int x = random(0,4998-sch);
	swap(arr[x],arr[4998-sch]);
	return arr[4998-sch];
}
// ==================== CAP NHAP MANG TGIAN DE IN ==========================
void insertarray(char *h, TG *j) 
{
	int temp = 0;
	temp = j->giay;
	h[7] = doichar(temp % 10);
	h[6] = doichar(temp /= 10);

	temp = j->phut;
	h[4] = doichar(temp % 10);
	h[3] = doichar(temp /= 10);

	temp = j->gio;
	h[1] = doichar(temp % 10);
	h[0] = doichar(temp /= 10);

}
// ==================== CAP NHAP THOI GIAN THI ==========================
bool changetime(TG *h)
{
	if (h->giay > 0) --h->giay;
	else if (h->phut > 0)
	{
		h->giay = 59;
		--h->phut;
	}
	else if (h->gio > 0)
	{
		--h->gio;
		h->phut = 59;
		h->giay = 59;
	}
	else return false;
	return true;
}
// ==================== HAM THAY THE COUT IN RA 1 CHUOI ==========================
void WriteBlockChar(char *Arraych,int x, int y,int color)
{
	CHAR_INFO *charater = new CHAR_INFO[8];
	for (int i = 0; i < 8; i++)
	{
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { 8,1 };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + 8 - 1,y + 1 - 1 }; // vung dem
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
// ==================== IN DONG HO ==========================
void printClock(int tg)
{
	TG h;
	if(tg < 60)
	{
		h = { 0,tg,0};
	}
	else if (tg == 60)
	{
		h = { 1,0,0};
	}
	else
	{
		int gio = tg/60;
		int phut = tg%60;
		h = { gio,phut,0};
	}
	char a[8] = { '0','0',':','0','0',':','0','0'};
	while (stop)
	{
		if (changetime(&h) == false) stop = 0;
		insertarray(a, &h);
		WriteBlockChar(a, 115, 1,0x007|0x000);
		Sleep(1000);
	}
	return;
}
// ==================== NHAP TG THI ==========================
void NhapTG (int &tg, int &sct, DSMH pMonThi)
{
	system("cls");
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(40,45);
	cout << "ENTER: Lam bai thi      Left/Right: Di chuyen chon thoi gian va cau hoi thi     ";
	gotoxy(127,26);
	vekhungTB(10,36);
	string ntg;
	string nsct;
	vekhungNhapTG();
	gotoxy(68,20);
	char s;
	bool sCheck;
	int state = 0;
	HienConTro();
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(s == LEFT && sCheck == false)
		{
			if(state == 1)
			{
				gotoxy(68+ntg.length(),20);
				state --;
			}
		}
		if(s == RIGHT && sCheck == false)
		{
			if(state == 0)
			{
				gotoxy(112+nsct.length(),20);
				state ++;
			}
		}
		if((s >= '0' && s <= '9')  && sCheck == true)
		{
			if(state == 0 && ntg.length() < 3)
			{
				cout << s;
				ntg += s;	
			}
			else if(state == 1 && nsct.length() < 3)
			{
				cout << s;
				nsct +=s;
			}
		}
		if (s == BACKSPACE)
		{
			if (ntg.length() > 0 && state == 0)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				HienConTro();
				ntg.erase(ntg.length()-1);
			}
			else if(nsct.length() > 0 && state == 1)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				HienConTro();
				nsct.erase(nsct.length()-1);
			}	
		}
		if(s == ENTER)
		{
			if(ntg.length() == 0 || nsct.length() == 0)
			{
				string tb = "Thoi gian thi hoac so cau thi khong hop le";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);	
			}
			else
			{
				if(StringToInt(ntg) > 0 && StringToInt(nsct) > 0)
					{
						
						tg = StringToInt(ntg);
						sct = StringToInt(nsct);
						int sch = pMonThi->mh.cauHoiMH.n;
						if (sct > sch)
						{
							string tb = "Khong the thi, so cau thi vuot qua so cau hoi trong ngan hang de thi";
							InTB(tb,129,30);
							AnConTro();
							Sleep(1500);
							XoaTB(130,26);
							gotoxy(112+nsct.length(),20);
							HienConTro();		
						}
						else
						{
							gotoxy(40,45);
							cout << "                                                                                ";
							return;	
						}
					}
				else
				{
					string tb = "Thoi gian thi hoac so cau thi phai lon hon '0'";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);	
					gotoxy(68,20);
					cout << "   ";
					gotoxy(112,20);
					cout << "   ";
					ntg = "";
					nsct = "";
					state = 0;
					gotoxy(68+ntg.length(),20);
					HienConTro();
				}
			}		
		}
		batPhim(s,sCheck);
	}
}
// ==================== NHAP MON THI ==========================
void NhapMonThi(DSMH dsm, DSMH &pTam, int &idlonnhat, int &tg, int &sct, bool &check)
{
	AnConTro();
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(40,45);
	cout << "ENTER: Chon mon thi      ESC: Thoat";
	gotoxy(127,26);
	vekhungTB(10,36);
	string tb;
	int maxpage;
	int page = 0;
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
	InDSMH_CoCauHoi(dsm,page, maxpage,arr);
	char s;
	int state = 0;
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
			if (s == ENTER)
			{
				//nhap tg
				pTam = FindNode(dsm,*arr[page*10 + state]);
				if(pTam->mh.cauHoiMH.n > 0){
					NhapTG(tg,sct, pTam);
					if(tg > 0 && sct > 0)
					{
						check = true;
						return;
					}
					gotoxy(0,0);
					veKhungThuCong();
					gotoxy(127,26);
					vekhungTB(10,36);
					gotoxy(5,2);
					vekhungDSMH_CoCauHoi(34,120,5);
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);
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
						gotoxy(7, 6 + 3*state);
						cout<<" ";
						gotoxy(7, 6 + 3*state);
						cout<<muiten;
					}
					AnConTro();
				}
				else
				{
					AnConTro();
					XoaTB(130,26);
					gotoxy(129,30);
					string tb = "Mon hoc chua co cau hoi!";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
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
						gotoxy(7, 6 + 3*state);
						cout<<" ";
						gotoxy(7, 6 + 3*state);
						cout<<muiten;
					}
					AnConTro();
				}
			}
		batPhim(s,sCheck);
	}
	check = false;
	return;
}
// ==================== VE KHUNG DAP AN THI SINH DA CHON ==========================
void VeKhungDA(int page, int sct,CTdethi ctdt)
{
	gotoxy(15,38);
	int socau;
	if(sct <= 10)
	{
		socau = sct;
	}
	else if((page + 1)*10 <= sct)
	{
		socau = 10;
	}
	else socau = sct%10;
	int rong = socau*10;
	int x = rong/socau;
	int dem = 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socau)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socau)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == 5)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socau)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socau)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socau)) dem++;
			if(dem == socau) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
	int temp = page*10 + 1;
	for(int i = 0; i < socau ; i++)
	{
		gotoxy(15 + 4 + (i*10),38+1);
		cout << temp;
		temp ++;
	}
	for(int i = 0; i < socau; i++)
	{
		gotoxy(15 + 4 + (i*10),38+3);
		if(ctdt.dapan[(page*10) + i] == 1)
		{
			cout << "A";
		}
		else if (ctdt.dapan[(page*10) + i] == 2)
		{
			cout << "B";
		}
		else if(ctdt.dapan[(page*10) + i] == 3)
		{
			cout << "C";
		}
		else if(ctdt.dapan[(page*10) + i] == 4)
		{
			cout << "D";
		}
		else continue;
	}
}
// ==================== XOA KHUNG DAP AN THI SINH DA CHON ==========================
void XoaDA()
{
	for(int i = 0; i < 6; i++)
	{
		gotoxy(14,38+i);
		cout <<"                                                                                                     "; 
	}
}
// ==================== CAP NHAP BANG DAP AN THI SINH DA CHON ==========================
void InDA(int page, int sct, CTdethi ctdt)
{
	int socau;
	if(sct <= 10)
	{
		socau = sct;
	}
	else if((page + 1)*10 <= sct)
	{
		socau = 10;
	}
	else socau = sct%10;
	for(int i = 0; i < socau; i++)
	{
		gotoxy(15 + 4 + (i*10),38+3);
		if(ctdt.dapan[(page*10) + i] == 1)
		{
			cout << "A";
		}
		else if (ctdt.dapan[(page*10) + i] == 2)
		{
			cout << "B";
		}
		else if(ctdt.dapan[(page*10) + i] == 3)
		{
			cout << "C";
		}
		else if(ctdt.dapan[(page*10) + i] == 4)
		{
			cout << "D";
		}
		else continue;
	}
}
void In1CauThi (DSCH dsch, int id)
{
	for(int i = 0; i < 30;i++)
	{
		gotoxy(20,5+i);
		if(i == 4) i = 8;
		if (i == 11) i = 14;
		if (i == 17) i = 20;
		if (i == 23) i = 26;
		cout << "                                                                                                  ";
	}
	
	InNDCH(dsch.listCauHoi[id]->noiDung);
	gotoxy(20,14);
	InDA_XemCH(dsch.listCauHoi[id]->A);
	gotoxy(20,20);
	InDA_XemCH(dsch.listCauHoi[id]->B);
	gotoxy(20,26);
	InDA_XemCH(dsch.listCauHoi[id]->C);
	gotoxy(20,32);
	InDA_XemCH(dsch.listCauHoi[id]->D);
}
// ==================== LAY DE THI THEO MA MON HOC ==========================
int *LayDeThi(DSCH dsch, int sct)
{
	int temp[10000];
	int *dethi = new int [sct];
	int dem = 0;
	int i=0;
	for(int i = 0; i < dsch.n; i++){
		temp[i] = i;
		dem++;
	}
	if(dem < sct)
	{
		string tb = "Khong du cau hoi de thi";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
		return NULL;
	}
	else
	{
		for(int j = 0; j < sct; j++)
		{
			int r = random(0,dem-j-1);
			dethi[j] = temp[r];
			swap(temp[r],temp[dem-1-j]); 
		}
	}
	return dethi;
}
// ==================== TINH DIEM ==========================
int TinhDiem(CTdethi ctdt, DSCH dsch)
{
	int socaudung = 0;
	string dapan="";
	for(int i = 0; i < ctdt.sct ; i++)
	{
		if(ctdt.dapan[i] == 1)
		{
			dapan = "A";
		}
		else if(ctdt.dapan[i] == 2)
		{
			dapan = "B";
		}
		else if(ctdt.dapan[i] == 3)
		{
			dapan = "C";
		}
		else if(ctdt.dapan[i] == 4)
		{
			dapan = "D";
		}
		if(dsch.listCauHoi[ctdt.bode[i]]->dapAn.compare(dapan) == 0)
		{
			socaudung++;
		}
		dapan="";
	}
	return socaudung;
}
int ketThucBaiThi (CTdethi ctdt, DSCH dsch, string &diem)
{
	system("cls");
	TextColor(241);
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(15,7);
	cout << "	 _______  _______  __    _  _______  ______    _______  _______  __   __  ___      _______  _______  ___   _______  __    _  __  ";
	gotoxy(15,8);
	cout << "	|       ||       ||  |  | ||       ||    _ |  |   _   ||       ||  | |  ||   |    |   _   ||       ||   | |       ||  |  | ||  | ";
	gotoxy(15,9);
	cout << "	|       ||   _   ||   |_| ||    ___||   | ||  |  |_|  ||_     _||  | |  ||   |    |  |_|  ||_     _||   | |   _   ||   |_| ||  | ";
	gotoxy(15,10);
	cout << "	|       ||  | |  ||       ||   | __ |   |_||_ |       |  |   |  |  |_|  ||   |    |       |  |   |  |   | |  | |  ||       ||  | ";
	gotoxy(15,11);
	cout << "	|      _||  |_|  ||  _    ||   ||  ||    __  ||       |  |   |  |       ||   |___ |       |  |   |  |   | |  |_|  ||  _    ||__| ";
	gotoxy(15,12);
	cout << "	|     |_ |       || | |   ||   |_| ||   |  | ||   _   |  |   |  |       ||       ||   _   |  |   |  |   | |       || | |   | __  ";
	gotoxy(15,13);
	cout << "	|_______||_______||_|  |__||_______||___|  |_||__| |__|  |___|  |_______||_______||__| |__|  |___|  |___| |_______||_|  |__||__| ";
	float a = (float)TinhDiem(ctdt,dsch);
	int b = (float)ctdt.sct;
	float diemtam = (a / b)*10;
	diem = FloatToString(diemtam);
	gotoxy(50,25);
	cout << "CHUC MUNG BAN DA HOAN THANH BAI THI!";
	gotoxy(50,30);
	ChangeColor(175);
	cout << "DIEM CUA BAN LA: " << diem;
	ChangeColor(241);
	char s;
	bool sCheck;
	string tbThoat = "Ban co muon tiep tuc thi mon khac khong?(Y/N)";
	if(ExitXoa(tbThoat,s, sCheck) == true) return 1;
	else return 0;
}
// ==================== FUNCTION THI ==========================
int FunctionThi(lop *l, string mssv, DSMH dsm, DSMH monThi, int tg, int sct, string &diem, CTdethi &ctdt)
{
	TextColor(241);
	ctdt.sct = sct;
	ctdt.tg = tg;
	for(int i = 0; i < sct; i++)
	{
		ctdt.dapan[i] = 0;
	}
	ctdt.bode = LayDeThi(monThi->mh.cauHoiMH,sct);
	thread clock;
	clock = thread(printClock,tg);
	gotoxy(40,45);
	cout << "ENTER: Chon       F1: Nop bai       Left/Right: Di chuyen cau hoi     ";
	gotoxy(50,1);
	cout << "BAI THI MON: " << monThi->mh.MAMH;
	int cauthi = 0;
	int page = 0;
	int maxpage;
	if(sct <= 10)
	{
		maxpage = 0;
	}
	else if(sct > 10 && sct % 10 == 0)
	{
		maxpage = (sct/10) - 1;
	}
	else maxpage = sct/10;
	gotoxy(5,2);
	veKhung(36,120);
	gotoxy(6,7-2);
	cout << "NOI DUNG CH: ";
	gotoxy(19,6-2);
	veKhung(7,100);
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(19,15-2);
	veKhung(5,100);
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(19,21-2);
	veKhung(5,100);
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(19,27-2);
	veKhung(5,100);
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	gotoxy(19,33-2);
	veKhung(5,100);
	InNDCH(monThi->mh.cauHoiMH.listCauHoi[ctdt.bode[cauthi]]->noiDung);
	gotoxy(20,14);
	InDA_XemCH(monThi->mh.cauHoiMH.listCauHoi[ctdt.bode[cauthi]]->A);
	gotoxy(20,20);
	InDA_XemCH(monThi->mh.cauHoiMH.listCauHoi[ctdt.bode[cauthi]]->B);
	gotoxy(20,26);
	InDA_XemCH(monThi->mh.cauHoiMH.listCauHoi[ctdt.bode[cauthi]]->C);
	gotoxy(20,32);
	InDA_XemCH(monThi->mh.cauHoiMH.listCauHoi[ctdt.bode[cauthi]]->D);
	VeKhungDA(page,sct,ctdt);
	gotoxy(7,1);
	TextColor(241);
	cout << "CAU " << cauthi + 1;
	gotoxy(19 + (cauthi%10)*10,44);
	TextColor(241);
	TextColor(241);
	cout << muitenlen;
	gotoxy(4,14);
	TextColor(241);
	TextColor(241);
	cout << muiten;
	AnConTro();
	int state1 = 0;
	char s;
	bool sCheck;
	bool qt = false;
	batPhim(s,sCheck);
	string da = "A";
	gotoxy(19,44);
	TextColor(241);
	cout << muitenlen;
	gotoxy(4,14);
	while (1)
	{
		if(s == PAGEUP)
		{
			if(page > 0 )
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi -= 10;
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				page --;
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(monThi->mh.cauHoiMH,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					TextColor(241);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					TextColor(241);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					TextColor(241);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					TextColor(241);
					cout << muiten;
				}
			}
		}
		if(s == PAGEDOWN)
		{
			if(page < maxpage )
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				if(cauthi < sct - 10)
				{
					cauthi += 10;
					gotoxy(19 + (cauthi%10)*10,44);
					TextColor(241);
					cout << muitenlen;
				}
				else cauthi += sct - cauthi - 1;
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				page ++;
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(monThi->mh.cauHoiMH,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					TextColor(241);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					TextColor(241);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					TextColor(241);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					TextColor(241);
					cout << muiten;
				}
			}
		}
		if (s == LEFT && sCheck == false)
		{
			if(page > 0 && (cauthi + 1) % 10 == 1)
			{
				page--;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				qt = false;
			}
			else InDA(page,sct,ctdt);
			if (cauthi > 0)
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi--;
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(monThi->mh.cauHoiMH,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					TextColor(241);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					TextColor(241);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					TextColor(241);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					TextColor(241);
					cout << muiten;
				}
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if(page < maxpage && (cauthi + 1) % 10 == 0)
			{
				page++;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				qt = false;
			}
			else InDA(page,sct,ctdt);
			if (cauthi < sct - 1)
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi++;
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "            ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(monThi->mh.cauHoiMH,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					TextColor(241);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					TextColor(241);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					TextColor(241);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					TextColor(241);
					cout << muiten;
				}
			}
		}
		if(s == UP && sCheck == false)
		{
			switch(state1)
			{
				case 1:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						gotoxy(4,14);
						TextColor(241);
						cout << muiten;
						state1--;
						da = "A";
						break;
					}
				case 2:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						gotoxy(4,20);
						TextColor(241);
						cout << muiten;
						state1--;
						da = "B";
						break;
					}
				case 3:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						gotoxy(4,26);
						TextColor(241);
						cout << muiten;
						state1--;
						da = "C";
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
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						gotoxy(4,14);
						cout << " ";
						gotoxy(4,20);
						TextColor(241);
						cout << muiten;
						state1++;
						da = "B";
						break;
					}
				case 1:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						gotoxy(4,26);
						TextColor(241);
						cout << muiten;
						state1++;
						da = "C";
						break;
					}
				case 2:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						gotoxy(4,32);
						TextColor(241);
						cout << muiten;
						state1++;
						da = "D";
						break;
					}
			}
		}
		if(s == ENTER)
		{
			if(da == "A")
			{
				ctdt.dapan[cauthi] = 1;
			}
			else if(da == "B")
			{
				ctdt.dapan[cauthi] = 2;
			}
			else if(da == "C")
			{
				ctdt.dapan[cauthi] = 3;
			}
			else if (da == "D")
			{
				ctdt.dapan[cauthi] = 4;
			}
			if (cauthi < sct -1)
			{
				if(page < maxpage && (cauthi + 1) % 10 == 0)
				{
					page++;
					qt = true;
				}
				if (qt == true)
				{
					XoaDA();
					VeKhungDA(page,sct,ctdt);
					qt = false;
				}
				else InDA(page,sct,ctdt);
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi++;
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(monThi->mh.cauHoiMH,ctdt.bode[cauthi]);
				state1 = 0;
				da = "A";
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}	
				gotoxy(4,14);
				TextColor(241);
				cout << muiten;
			}
			else if(cauthi == sct -1)
			{
				InDA(page,sct,ctdt);
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				gotoxy(19 + (cauthi%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				gotoxy(10,1);
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					TextColor(241);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					TextColor(241);
						cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					TextColor(241);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					TextColor(241);
					cout << muiten;
				}
			}
		}
		if ((s == F1  && sCheck == false) || s == ESC)
		{
			string tb = "Ban chac chan muon nop bai ? (Y/N)";
			InTB(tb,129,30);
			batPhim(s,sCheck);
			while(s != ESC)
			{
				if((s == 'y' || s == 'Y')&& sCheck == true)
				{
					stop = 0;
					clock.join();
					if(ketThucBaiThi(ctdt,monThi->mh.cauHoiMH, diem) == 1) return 1;
					else return 0;
				}
				else if((s == 'n' || s == 'N') && sCheck == true)
				{
					XoaTB(130,26);
					break;
				}
				batPhim(s,sCheck);
				
			}
			InTB(tb,129,30);
		}
		if(stop == 0)
		{
			string tb = "Het thoi gian lam bai, bam phim bat ky de ket thuc!";
			InTB(tb,129,30);
			Sleep(1000);
			clock.join();
			if(ketThucBaiThi(ctdt,monThi->mh.cauHoiMH, diem) == 1) return 1;
			else return 0;
		}
		batPhim(s,sCheck);
	}
	stop = 0;
	clock.join();
}

// ==================== IN 1 CH + DAN AN CUA SV ==========================
void InCH_DASV(cauHoi ch, string da)
{
	TextColor(241);
	for(int i = 0; i < 30;i++)
	{
		gotoxy(20,5+i);
		if(i == 4) i = 8;
		if (i == 11) i = 14;
		if (i == 17) i = 20;
		if (i == 23) i = 26;
		cout << "                                                                                                  ";
	}
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	InNDCH(ch.noiDung);
	gotoxy(20,14);
	InDA_XemCH(ch.A);
	gotoxy(20,20);
	InDA_XemCH(ch.B);
	gotoxy(20,26);
	InDA_XemCH(ch.C);
	gotoxy(20,32);
	InDA_XemCH(ch.D);
	if(ch.dapAn == da)
	{
		if(ch.dapAn == "A")
		{
			ChangeColor(175);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "B")
		{
			ChangeColor(175);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "C")
		{
			ChangeColor(175);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "D")
		{
			ChangeColor(175);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
	}
	else
	{
		if(da == "A")
		{
			ChangeColor(79);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(da == "B")
		{
			ChangeColor(79);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(da == "C")
		{
			ChangeColor(79);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(da == "D")
		{
			ChangeColor(79);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
		if(ch.dapAn == "A")
		{
			ChangeColor(112);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "B")
		{
			ChangeColor(112);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "C")
		{
			ChangeColor(112);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch.dapAn == "D")
		{
			ChangeColor(112);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
	}
}
// ==================== IN CHI TIET 1 LAN THI CUA SV ==========================
void InChiTiet1LanThi(nodediemThi *p, DSCH dsch, nodeSV *k)
{
	system("cls");
	gotoxy(0,0);
	TextColor(241);
	veKhungThuCong();
	string diem = FloatToString(p->info.diem);
	gotoxy(130,2);
	veKhung(21,35);
	gotoxy(133,4);
	cout << "MSSV: ";
	gotoxy(139,4);
	cout << k->info.maSV;
	gotoxy(133,7);
	cout << "HO VA TEN: ";
	gotoxy(144,7);
	cout << k->info.ho << " " << k->info.ten;
	gotoxy(133,10);
	cout << "GIOI TINH: ";
	gotoxy(144,10);
	cout << k->info.gioiTinh;
	gotoxy(133,13);
	cout << "SO CAU DUNG: ";
	gotoxy(150,13);
	cout << TinhDiem(p->info.ctdt,dsch);
	gotoxy(133,16);
	cout << "SO CAU THI: ";
	gotoxy(150,16);
	cout << p->info.ctdt.sct;
	gotoxy(133,19);
	cout << "DIEM: ";
	gotoxy(150,19);
	cout << diem;
	gotoxy(5,2);
	veKhung(36,125);
	gotoxy(6,7-2);
	cout << "NOI DUNG CH: ";
	gotoxy(19,6-2);
	veKhung(7,100);
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(19,15-2);
	veKhung(5,100);
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(19,21-2);
	veKhung(5,100);
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(19,27-2);
	veKhung(5,100);
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	gotoxy(19,33-2);
	veKhung(5,100);
	int page = 0;
	int stt = 0;
	int maxpage;
	VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
	bool qt = false;
	int max = p->info.ctdt.sct;
	if(max <= 10)
	{
		maxpage = 0;
	}
	else if(max > 10 && max % 10 == 0)
	{
		maxpage = (max/10) - 1;
	}
	else maxpage = max/10;
	string da;
	if(p->info.ctdt.dapan[stt] == 1)
	{
		da = "A";
	}
	else if (p->info.ctdt.dapan[stt] == 2)
	{
		da = "B";
	}
	else if(p->info.ctdt.dapan[stt] == 3)
	{
		da = "C";
	}
	else if(p->info.ctdt.dapan[stt] == 4)
	{
		da = "D";
	}
	else if(p->info.ctdt.dapan[stt] == 0)
	{
		da = "";
	}
	InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
	gotoxy(5,1);
	TextColor(241);
	cout << "CAU " << stt + 1;
	gotoxy(19,44);
	TextColor(241);
	cout << muitenlen;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(s == LEFT && sCheck == false)
		{
			if(page > 0 && (stt + 1) % 10 == 1)
			{
				page--;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				qt = false;
			}
			if(stt > 0)
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt--;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
				gotoxy(5,1);
				TextColor(241);
				cout << "       ";
				gotoxy(5,1);
				TextColor(241);
				cout << "CAU " << stt + 1;
			}
		}
		if(s == RIGHT && sCheck == false)
		{
			if(page < maxpage && (stt + 1) % 10 == 0)
			{
				page++;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				qt = false;
			}
			if(stt < max - 1)
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt++;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
				gotoxy(5,1);
				TextColor(241);
				cout << "       ";
				gotoxy(5,1);
				TextColor(241);
				cout << "CAU " << stt + 1;
			} 
		}
		if(s == PAGEUP && sCheck == false)
		{
			if(stt > 9)
			{
				page--;
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt -= 10;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
//				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
			else
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt = 0;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
//				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
		}
		if(s == PAGEDOWN && sCheck == false)
		{
			if(stt < max - 10)
			{
				page++;
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt += 10;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
//				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(*dsch.listCauHoi[p->info.ctdt.bode[stt]],da);
				gotoxy(5,1);
				TextColor(241);
				cout << "       ";
				gotoxy(5,1);
				TextColor(241);
				cout << "CAU " << stt + 1;	
			}
			else
			{
				if((max - 1)/10 > stt/10)
				{
					page++;
					XoaDA();
					VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt); 
				}
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << " ";
				stt = max - 1;
				gotoxy(19 + (stt%10)*10,44);
				TextColor(241);
				cout << muitenlen;
				cauHoi ch = *dsch.listCauHoi[p->info.ctdt.bode[stt]];
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				TextColor(241);
				cout << "       ";
				gotoxy(5,1);
				TextColor(241);
				cout << "CAU " << stt + 1;
			}
		}
		batPhim(s,sCheck);
	}
}
// ==================== IN BANG DIEM THI TN 1 MH CUA SV ==========================
void InBangDiemSV (nodeSV *sv, int page, DSCH dsch)
{
	int maxpage;
	string diem;
	int slt = DemLanThi(sv->info.diem);
	if(slt <= 10)
	{
		maxpage = 0;
	}
	else if(slt > 10 && slt % 10 == 0)
	{
		maxpage = (slt/10) - 1;
	}
	else maxpage = slt/10;
	nodediemThi *p;
	if (page == 0)
	{
		p = sv->info.diem.First;
	}
	else
	{
		p = sv->info.diem.First;
		for (int i=0; i < page*10; i++)
		{
			if (p->pNext != NULL)
			{
				p = p->pNext;
			}
		}	
	}
	int dem = 1;
	int k = 0;
	for(int i = 0; i < 10; i++)
	{
		if(p->pNext != NULL)
		{
			gotoxy(20,6+k);
			cout << dem;
			gotoxy(50,6+k);
			cout << p->info.ctdt.sct;
			gotoxy(78,6+k);
			cout << p->info.ctdt.tg << " phut";
			gotoxy(109,6+k);
			diem = FloatToString(p->info.diem);
			cout << diem;
			dem ++;
			k += 3;
			p = p->pNext;
		}
		else
		{
			gotoxy(20,6+k);
			cout << dem;
			gotoxy(50,6+k);
			cout << p->info.ctdt.sct;
			gotoxy(78,6+k);
			cout << p->info.ctdt.tg << " phut";
			gotoxy(109,6+k);
			diem = FloatToString(p->info.diem);
			cout << diem;
			dem ++;
			k += 3;
			break;
		}
	}
	gotoxy(62,37);
	cout << "Trang" << page + 1 << "/" << maxpage + 1;
}
// ==================== XEM BANG DIEM THI TN 1 MH CUA SV ==========================
void XemBangDiemSV(nodeSV *k, DSCH dsch)
{
	system("cls");
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(126,2);
	veKhung(11,40);
	gotoxy(128,4);
	cout << "MSSV: ";
	gotoxy(134,4);
	cout << k->info.maSV;
	gotoxy(128,7);
	cout << "HO VA TEN: ";
	gotoxy(139,7);
	cout << k->info.ho << " " << k->info.ten;
	gotoxy(128,10);
	cout << "GIOI TINH: ";
	gotoxy(139,10);
	cout << k->info.gioiTinh;
	gotoxy(5,2);
	vekhungDS(34,120,4);
	gotoxy(17,3);
	cout << "LAN THI";
	gotoxy(46,3);
	cout << "SO CAU THI";
	gotoxy(76,3);
	cout << "THOI GIAN";
	gotoxy(108,3);
	cout << "DIEM";
	int state = 0;
	int maxpage;
	int page = 0;
	int sl = countDemThiTrongSV(k->info.diem);
	InBangDiemSV(k,page,dsch);
	int slt = DemLanThi(k->info.diem);
	char s;
	bool sCheck;
	gotoxy(7,6);
	TextColor(241);
	cout << muiten;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(slt <= 10)
		{
			maxpage = 0;
		}
		else if(slt % 10 == 0) 
		{
			maxpage = slt/10 -1;
		}
		else maxpage = slt/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					TextColor(241);
	cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					TextColor(241);
	cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                             ";
						gotoxy(36,6+i);
						cout << "                             ";
						gotoxy(66,6+i);
						cout << "                             ";
						gotoxy(96,6+i);
						cout << "                            ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InBangDiemSV(k,page,dsch);
					gotoxy(7,33);
					TextColor(241);
	cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				nodediemThi *p = k->info.diem.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (p->pNext != NULL)
					{
						p = p->pNext;
					}
				}
				if(p->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                             ";
							gotoxy(36,6+i);
							cout << "                             ";
							gotoxy(66,6+i);
							cout << "                             ";
							gotoxy(96,6+i);
							cout << "                            ";
						}
					}
					page++;
					InBangDiemSV(k,page,dsch);
					state = 0;
					gotoxy(7,6);
					TextColor(241);
	cout << muiten;
				}
			}
			else
			{
				nodediemThi *p = k->info.diem.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (p->pNext != NULL)
					{
						p = p->pNext;
					}
				}
				if(p->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					TextColor(241);
	cout << muiten;	
				}
				if(p->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(7,wherey());
					TextColor(241);
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
					cout << "                             ";
					gotoxy(36,6+i);
					cout << "                             ";
					gotoxy(66,6+i);
					cout << "                             ";
					gotoxy(96,6+i);
					cout << "                            ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				TextColor(241);
	cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InBangDiemSV(k,page,dsch);
				gotoxy(hd,td);
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
					cout << "                             ";
					gotoxy(36,6+i);
					cout << "                             ";
					gotoxy(66,6+i);
					cout << "                             ";
					gotoxy(96,6+i);
					cout << "                            ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				TextColor(241);
	cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InBangDiemSV(k,page,dsch);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			nodediemThi *p = k->info.diem.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (p->pNext != NULL)
				{
					p = p->pNext;
				}
			}
			InChiTiet1LanThi(p,dsch,k);
			system("cls");
			gotoxy(0,0);
			veKhungThuCong();
			gotoxy(126,2);
			veKhung(11,40);
			gotoxy(128,4);
			cout << "MSSV: ";
			gotoxy(134,4);
			cout << k->info.maSV;
			gotoxy(128,7);
			cout << "HO VA TEN: ";
			gotoxy(139,7);
			cout << k->info.ho << " " << k->info.ten;
			gotoxy(128,10);
			cout << "GIOI TINH: ";
			gotoxy(139,10);
			cout << k->info.gioiTinh;
			gotoxy(5,2);
			vekhungDS(34,120,4);
			gotoxy(17,3);
			cout << "LAN THI";
			gotoxy(46,3);
			cout << "SO CAU THI";
			gotoxy(76,3);
			cout << "THOI GIAN";
			gotoxy(108,3);
			cout << "DIEM";
			if(state > 0 && sl == (page * 10 + state)){
				InBangDiemSV(k,page,dsch);
				gotoxy(7, 6 + 3*state);
				cout<<" ";
				state--;
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
			}else if(state == 0 && sl == (page * 10 + state) && page !=0){
				page--;
				InBangDiemSV(k,page,dsch);
				gotoxy(7, 6 + 3*state);
				cout<<" ";
				state = 9;
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
			}else if(state > 0 && sl < 10 && page ==0 ){
				InBangDiemSV(k,page,dsch);
				gotoxy(7, 6 + 3*state);
				cout<<" ";
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
			} else{
				InBangDiemSV(k,page,dsch);		
				gotoxy(7, 6 + 3*state);
				cout<<" ";
				gotoxy(7, 6 + 3*state);
				cout<<muiten;
			}	
		}else{
			gotoxy(7, 6 + 3*state);
			cout<<" ";
			gotoxy(7, 6 + 3*state);
			cout<<muiten;
		}
		batPhim(s,sCheck);
	}
}
// ==================== IN DANH SACH DIEM THEO MH ==========================
void InDSDiemMH (lop *l,int page, DSMH m)
{
	if (l->danhsach.First == NULL)
	{
		return;
	}
	int k = 2;
	int sl = DemSV(l->danhsach);
	int maxpage;
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	nodeSV *j = new nodeSV;
	if (page == 0)
	{
		j = l->danhsach.First;
	}
	else
	{
		j = l->danhsach.First;
		for (int i=0; i<page*10; i++)
		{
			if (j->pNext != NULL)
			{
				j = j->pNext;
			}
		}	
	}
	nodediemThi *p;
	for(int i = 0; i < 10; i++)
	{
		p = j->info.diem.First;
		int slt = 0;
		if (j->pNext != NULL) //j khong cuoi 
		{
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(32,4+k);
			cout << j->info.ho << " " << j->info.ten;
			if(p == NULL) //j chua thi
			{	
				gotoxy(109,4+k);
				cout << "CHUA THI";
			}
			else //j co thi
			{
				while(p != NULL) //tim slt cua mon
				{
					if(p->info.idMonHoc == m->id)
					{
						slt++;
					}
					p = p->pNext;
				}
				if(slt == 0) //neu chi thi mon
				{
					gotoxy(109,4+k);
					cout << "CHUA THI";
				}
				else //neu co thi mon
				{
					gotoxy(113,4+k);
					cout << slt;
				}
			}
			k += 3;
			j = j->pNext;
		}
		else //j la cuoi
		{
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(32,4+k);
			cout << j->info.ho << " " << j->info.ten;
			if(p == NULL)
			{	
				gotoxy(109,4+k);
				cout << "CHUA THI";
			}
			else //j co thi
			{
				while(p != NULL) //tim slt cua mon
				{
					if(p->info.idMonHoc == m->id)
					{
						slt++;
					}
					p = p->pNext;
				}
				if(slt == 0) //neu chi thi mon
				{
					gotoxy(109,4+k);
					cout << "CHUA THI";
				}
				else //neu co thi mon
				{
					gotoxy(113,4+k);
					cout << slt;
				}
			}
			k += 3;
			break;
		}
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
// ==================== XEM DIEM ==========================
void XemDiem1Lop(lop *l, DSMH monhoc)
{
	AnConTro();
	system("cls");
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(10,1);
	cout << "Diem mon : " << monhoc->mh.MAMH;
	gotoxy(105,1);
	cout << "Lop : " << l->maLop;
	gotoxy(5,2);
	VeKhungDSLop1(34,120,10);
	gotoxy(127,26);
	vekhungTB(10,36);
	int page = 0;
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(60,3);
	cout << "HO VA TEN";
	gotoxy(108,3);
	cout << "SO LAN THI";
	InDSDiemMH(l,page,monhoc);
	int maxpage;
	int state = 0;
	char s;
	bool sCheck;
	gotoxy(7,6);
	TextColor(241);
	cout << muiten;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) % 10 == 0) 
		{
			maxpage = DemSV(l->danhsach)/10;
		}
		else maxpage = DemSV(l->danhsach)/10 + 1;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					TextColor(241);
	cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					TextColor(241);
	cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InDSDiemMH(l,page,monhoc);
					gotoxy(7,33);
					TextColor(241);
	cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < maxpage)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                      ";
							gotoxy(31,6+i);
							cout << "                                             ";
							gotoxy(79,6+i);
							cout << "                     ";
							gotoxy(103,6+i);
							cout << "                     ";
						}
					}
					page++;
					InDSDiemMH(l,page,monhoc);
					state = 0;
					gotoxy(7,6);
					TextColor(241);
	cout << muiten;
				}
			}
			else
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					TextColor(241);
	cout << muiten;	
				}
				if(k->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(7,wherey());
					TextColor(241);
	cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage -1)
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				TextColor(241);
	cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSDiemMH(l,page,monhoc);
				gotoxy(hd,td);
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
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				TextColor(241);
	cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSDiemMH(l,page,monhoc);
				gotoxy(hd,td);
			}
		}
		if(s == ENTER)
		{
			//XEM BANG DIEM SINH VIEN
			nodeSV *k = l->danhsach.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (k->pNext != NULL)
				{
					k = k->pNext;
				}
			}
			if(k->info.diem.First == NULL)
			{
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				string tb = "Sinh vien chua thi lan nao";
				InTB(tb,129,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(7,6);
				TextColor(241);
	cout << muiten;
				state = 0;
			}
			else
			{
				//In chi tiet bang diem cua 1 sinh vien
				if(CheckSLThi(k->info.diem, monhoc->id) == false)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					string tb = "Sinh vien chua thi lan nao";
					InTB(tb,129,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(7,6);
					TextColor(241);
	cout << muiten;
					state = 0;
				}
				else
				{
					XemBangDiemSV(k,monhoc->mh.cauHoiMH);
					system("cls");
					gotoxy(0,0);
					veKhungThuCong();
					gotoxy(10,1);
					cout << "Diem mon : " << monhoc->mh.MAMH;
					gotoxy(105,1);
					cout << "Lop : " << l->maLop;
					gotoxy(5,2);
					VeKhungDSLop1(34,120,10);
					gotoxy(127,26);
					vekhungTB(10,36);
					int page = 0;
					gotoxy(15,3);
					cout << "MA SV";
					gotoxy(60,3);
					cout << "HO VA TEN";
					gotoxy(108,3);
					cout << "SO LAN THI";
					InDSDiemMH(l,page,monhoc);
					gotoxy(7,6);
					TextColor(241);
	cout << muiten;
					state = 0;
				}
			}
		}
	batPhim(s,sCheck);
	}
}
// ==================== NHAP MON XEM DIEM ==========================
void NhapMonXemDiem(lop *l, DSMH dsm, int idlonnhat)
{
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
	if( sl == 0)
	{
		string tb = "Danh sach mon hien tai dang trong";
		InTB(tb,129,30);
		AnConTro();
		Sleep(850);
		XoaTB(130,26);
		return;
	}
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(5,2);
	vekhungDSMH_CoCauHoi(34,120,5);
	int page = 0;
	int maxpage;
	InDSMH_CoCauHoi(dsm,page, maxpage, arr);
	gotoxy(127,26);
	vekhungTB(10,36);
	char s;
	int state = 0;
	bool sCheck;
	string tb = "Vui long chon 1 mon hoc de xem diem";
	InTB(tb,129,30);
	AnConTro();
	gotoxy(7,6);
	TextColor(241);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
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
						TextColor(241);
						cout << " ";
						state --;
						gotoxy(7,wherey() - 3);
						TextColor(241);
	cout << muiten;
					}
				}
				if(page > 0)
				{
					if((state > 0) )
					{
						gotoxy(wherex()-1,wherey());
						TextColor(241);
						cout << " ";
						state --;
						gotoxy(7,wherey()-3);
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
						TextColor(241);
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
					TextColor(241);
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
						TextColor(241);
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
					TextColor(241);
	cout << muiten;
					state = 0;
					page--;
					InDSMH_CoCauHoi(dsm,page, maxpage, arr);
					gotoxy(7,6);
				}
			}
			if(s == ENTER)
			{
				DSMH pTam = FindNode(dsm,*arr[page*10 + state]);
				XemDiem1Lop(l, pTam);
				system("cls");
				gotoxy(0,0);
				veKhungThuCong();
				gotoxy(5,2);
				vekhungDSMH_CoCauHoi(34,120,5);
				gotoxy(127,26);
				vekhungTB(10,36);
				tb = "Vui long chon 1 mon hoc de xem diem";
				InTB(tb,129,30);
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
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}
				
			}
		batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}
// ==================== NHAP LOP  ==========================
void NhapLopXemDiem(dslop dsl , DSMH dsm, int idlonnhat)
{
	system("cls");
	gotoxy(0,0);
	veKhungThuCong();
	gotoxy(127,26);
	vekhungTB(10,36);
	gotoxy(50,43);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(5,2);
	vekhungDS(34,120,2);
	gotoxy(35,3);
	cout << "TEN LOP";
	gotoxy(90,3);
	cout << "MA LOP";
	int page = 0;
	int maxpage;
	int sl = dsl.solop;
	InDSLop(dsl,page);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
						TextColor(241);
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(68,6+i);
						HienConTro();
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					page --;
					InDSLop(dsl,page);
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
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";	
							gotoxy(68,6+i);
							HienConTro();
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
						TextColor(241);
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
					cout << "                                      ";
					gotoxy(68,6+i);
					HienConTro();
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
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
					cout << "                                      ";
					gotoxy(68,6+i);
					HienConTro();
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
						TextColor(241);
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if(dsl.l[state + page*10]->danhsach.First == NULL)
			{
				string tb = "Lop khong co sinh vien khong the xem diem !";
				InTB(tb,129,30);
				AnConTro();
				Sleep(850);
				XoaTB(130,26);
				if(state > 0 && sl == (page * 10 + state)){
					InDSLop(dsl,page);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state--;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state == 0 && sl == (page * 10 + state) && page !=0){
					page--;
					InDSLop(dsl,page);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state = 9;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state > 0 && sl < 10 && page ==0 ){
					InDSLop(dsl,page);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				} else{
					InDSLop(dsl,page);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}
			}
			else
			{
				NhapMonXemDiem(dsl.l[state + page*10], dsm, idlonnhat);
				system("cls");
				gotoxy(0,0);
				veKhungThuCong();
				gotoxy(127,26);
				vekhungTB(10,36);
				gotoxy(5,2);
				vekhungDS(34,120,2);
				gotoxy(35,3);
				cout << "TEN LOP";
				gotoxy(90,3);
				cout << "MA LOP";
				if(state > 0 && sl == (page * 10 + state)){
					InDSLop(dsl,page);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state--;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state == 0 && sl == (page * 10 + state) && page !=0){
					page--;
					InDSLop(dsl,page);
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					state = 9;
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}else if(state > 0 && sl < 10 && page ==0 ){
					InDSLop(dsl,page);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				} else{
					InDSLop(dsl,page);	
					gotoxy(7, 6 + 3*state);
					cout<<" ";
					gotoxy(7, 6 + 3*state);
					cout<<muiten;
				}
			}
			
		}
	batPhim(s,sCheck);
	}
}
// ==================== FUNCTION DIEM ==========================
void FunctionDiem(dslop dsl, dssv ds,DSMH dsm, int idlongnhat)
{
	int page = 0;
	gotoxy(127,26);
	vekhungTB(10,36);
	string tb;
	if(dsl.solop == 0)
	{
		string tb = "Danh sach lop hien tai dang trong";
		InTB(tb,129,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopXemDiem(dsl,dsm, idlongnhat);
	}
}
// ==================== LUU FILE LOP ==========================
void LuuFileLop(lop *l, string filename) 
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (fileOut.fail()) 
	{
		cout << "Khong mo duoc file " << filename << endl;
		return;
	}

	for (nodeSV *p = l->danhsach.First; p != NULL; p = p->pNext) 
	{
		fileOut << p->info.maSV << '\n';
		fileOut << p->info.ho << ' ';
		fileOut << p->info.ten << '\n';
		if(p->info.gioiTinh == "NAM")
		{
			fileOut << "1" << '\n';
		}
		else
		{
			fileOut << "0" << '\n';
		}
		fileOut << p->info.password << endl;
	}
	fileOut.close();
	return;
}
// ==================== LUU FILE DIEM 1 LOP ==========================
void LuuFileDiem(lop *l, string filename, DSMH dsm)
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (fileOut.fail())
	{
		cout << "Khong mo duoc file diem " << filename << endl;
		return;
	}
	else
	{
		nodeSV *p = l->danhsach.First;
		while ( p != NULL)
		{
			fileOut << p->info.maSV << endl;
			int slt =  DemLanThi(p->info.diem);
			fileOut <<slt<< endl;
			if(slt == 0){
				fileOut << endl;
				p = p->pNext;
			}
			else
			{
				nodediemThi *pd = p->info.diem.First;
				while(pd != NULL)
				{
					string diemthi;
					DSMH pTam = FindNode(dsm, pd->info.idMonHoc);
					diemthi = FloatToString(pd->info.diem);
					fileOut << pd->info.idMonHoc << ":" << diemthi << ":" << pd->info.ctdt.sct << ":"<<pd->info.ctdt.tg<<":";
					for(int i = 0; i < pd->info.ctdt.sct; i++)
					{
						fileOut << pd->info.ctdt.bode[i] << "@";
					}
					for(int i = 0; i < pd->info.ctdt.sct; i++)
					{
						fileOut << pd->info.ctdt.dapan[i] << "#";
					}
					if(pd->pNext == NULL)
					{
						break;
					}
					else fileOut << endl;
					pd = pd->pNext;
				}
				if(p->pNext == NULL){
					break;
				}
				else fileOut << endl;
				p = p->pNext;
			}
		}
	}
	fileOut.close();
}
// ==================== LUU FILE DS LOP ==========================
void LuuFileDSlop(DSMH dsm, dslop dsl, string filename)
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (!fileOut.is_open()) 
	{
		cout << "Khong mo duoc file " << filename << endl;
		return;
	}
	fileOut << dsl.solop << endl;
	gotoxy(0,0);
	for (int i = 0; i < dsl.solop; i++) 
	{
		fileOut << dsl.l[i]->tenLop << '\n'<< dsl.l[i]->maLop << '\n';
		LuuFileLop(dsl.l[i],dsl.l[i]->maLop+".txt");
		LuuFileDiem(dsl.l[i],"DIEM_"+dsl.l[i]->maLop+".txt",dsm);
	}
}
// ==================== LUU FILE MON ==========================
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

//=============================DANG NHAP================================
int DangNhap(dslop &dsl ,string &masv)
{
	system("cls");
	veKhungThuCong();
	InTen();
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem);
	cout << " /$$$$$$$$ /$$   /$$ /$$$$$$       /$$$$$$$$ /$$$$$$$   /$$$$$$   /$$$$$$        /$$   /$$  /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$$ /$$      /$$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 1);
	cout << "|__  $$__/| $$  | $$|_  $$_/      |__  $$__/| $$__  $$ /$$__  $$ /$$__  $$      | $$$ | $$ /$$__  $$| $$  | $$|_  $$_/| $$_____/| $$$    /$$$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 2);
	cout << "   | $$   | $$  | $$  | $$           | $$   | $$  \\ $$| $$  \\ $$| $$  \\__/      | $$$$| $$| $$  \\__/| $$  | $$  | $$  | $$      | $$$$  /$$$$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 3);
	cout << "   | $$   | $$$$$$$$  | $$           | $$   | $$$$$$$/| $$$$$$$$| $$            | $$ $$ $$| $$ /$$$$| $$$$$$$$  | $$  | $$$$$   | $$ $$/$$ $$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 4);
	cout << "   | $$   | $$__  $$  | $$           | $$   | $$__  $$| $$__  $$| $$            | $$  $$$$| $$|_  $$| $$__  $$  | $$  | $$__/   | $$  $$$| $$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 5);
	cout << "   | $$   | $$  | $$  | $$           | $$   | $$  \\ $$| $$  | $$| $$    $$      | $$\\  $$$| $$  \\ $$| $$  | $$  | $$  | $$      | $$\\  $ | $$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 6);
	cout << "   | $$   | $$  | $$ /$$$$$$         | $$   | $$  | $$| $$  | $$|  $$$$$$/      | $$ \\  $$|  $$$$$$/| $$  | $$ /$$$$$$| $$$$$$$$| $$ \\/  | $$";
	gotoxy(xVeThiTracNghiem,yVeThiTracNghiem + 7);
	cout << "   |__/   |__/  |__/|______/         |__/   |__/  |__/|__/  |__/ \\______/       |__/  \\__/ \\______/ |__/  |__/|______/|________/|__/     |__/";
                                                                                                                                             
                                                                                                                             
	gotoxy(xDangNhap,yDangNhap);
	veKhung(12,50);
	gotoxy(xDangNhap+3,yDangNhap +3);
	cout << "Ten dang nhap";
	gotoxy(xDangNhap+17,yDangNhap+2);
	veKhung(3,30);
	gotoxy(xDangNhap+3,yDangNhap+7);
	cout << "Mat khau";
	gotoxy(xDangNhap+17,yDangNhap+6);
	veKhung(3,30);
	gotoxy(xDangNhap+21,yDangNhap+10);
	cout << "DANG NHAP";

	string user;
	string pass;
	char s;
	bool state = false;
	bool sCheck;
	gotoxy(xDangNhap+18 + user.length(),yDangNhap+3);
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if (s == UP && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(xDangNhap+18+user.length(),yDangNhap+3);
				state = !state;
			}
		}
		if (s == DOWN && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(xDangNhap+18+pass.length(),yDangNhap+7);
				state = !state;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (state == true)
			{
				if (pass.length() < 20)
				{
					cout << "*";
					pass += s;
				}
			}
			else
			{
				if (user.length() < 20)
				{
					cout << InHoa(s);
					user += InHoa(s);
				}
			}
		}
		if (s == BACKSPACE)
		{
			if (state == true)
			{
				if (pass.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					pass.erase(pass.length()-1);
				}
			}
			else
			{
				if (user.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					cout << " ";
					gotoxy(wherex()-1,wherey());
						TextColor(241);
					HienConTro();
					user.erase(user.length()-1);
				}
			}
		}
		if (s == ENTER)
		{
			// Duyet trong dssv kiem tra masv voi mat khau. neu dung thi return 0 la quyen sv
			if(user.length() == 0 && pass.length() == 0)
			{
				AnConTro();
				gotoxy(35,43);
				cout<<"Ten dang nhap va mat khau khong duoc de trong";
				Sleep(2000);
				gotoxy(35,43);
				cout<<"                                             ";
				gotoxy(xDangNhap+18+user.length(),yDangNhap+3);
				state = false;
				HienConTro();
				
			}
			else if(user.length() == 0 )
			{
				AnConTro();
				InTB("Ten dang nhap khong duoc de trong",35,43);
				Sleep(2000);
				gotoxy(35,43);
				cout<<"                                             ";
				gotoxy(xDangNhap+18+user.length(),yDangNhap+3);
				state = false;
				HienConTro();
			}
			else if(pass.length() == 0)
			{
				AnConTro();
				InTB("Mat khau khong duoc de trong",35,43);
				Sleep(2000);
				gotoxy(35,43);
				cout<<"                                             ";
				gotoxy(xDangNhap+18+pass.length(),yDangNhap+7);
				state = true;
				HienConTro();
			}
			else
			// neu user = "GV" va mat khau = "GV" thi return 1 la quyen giang vien
			if((user == "GV" && pass == "GV") || (user == "GV") && (pass == "gv"))
			{
				return 1;
			}
			else
			{	
				for(int i = 0; i < dsl.solop; i++)
				{
					for(nodeSV *k = dsl.l[i]->danhsach.First; k != NULL; k = k->pNext)
					{
						string x;
						for (int i = 0; i < k->info.maSV.length(); i++)
						{
							x += InHoa(k->info.maSV[i]);
						}
						string y = k->info.password;
						if(x == user && y == pass)
						{
							masv = user;
							return 0;
						}
					}
				}
				AnConTro();
				gotoxy(35,43);
				cout<<"Dang nhap khong thanh cong! Vui long thu lai";
				Sleep(2000);
				gotoxy(35,43);
				cout<<"                                                ";
				gotoxy(xDangNhap+18+user.length(),yDangNhap+3);
				state = false;
				HienConTro();
				
			}
		}
	batPhim(s,sCheck);
	}
	return -1;
}

//==================================MAIN MENU GIANG VIEN===============================
int mainMenu()
{
	system("cls");
	TextColor(241);
	veKhungThuCong();
	InTB("ENTER: Chon	ESC: Thoat",35,43);
	gotoxy(80,10);
	cout << " __   __  _______  __    _  __   __ ";
	gotoxy(80,11);
	cout << "|  |_|  ||       ||  |  | ||  | |  |";
	gotoxy(80,12);
	cout << "|       ||    ___||   |_| ||  | |  |";
	gotoxy(80,13);
	cout << "|       ||   |___ |       ||  |_|  |";
	gotoxy(80,14);
	cout << "|       ||    ___||  _    ||       |";
	gotoxy(80,15);
	cout << "| ||_|| ||   |___ | | |   ||       |";
	gotoxy(80,16);
	cout << "|_|   |_||_______||_|  |__||_______|";
	gotoxy(60,20);
	cout << " _______  ___   _______  __    _  _______    __   __  ___   _______  __    _ ";
	gotoxy(60,21);
	cout << "|       ||   | |   _   ||  |  | ||       |  |  | |  ||   | |       ||  |  | |";
	gotoxy(60,22);
	cout << "|    ___||   | |  |_|  ||   |_| ||    ___|  |  |_|  ||   | |    ___||   |_| |";
	gotoxy(60,23);
	cout << "|   | __ |   | |       ||       ||   | __   |       ||   | |   |___ |       |";
	gotoxy(60,24);
	cout << "|   ||  ||   | |       ||  _    ||   ||  |  |       ||   | |    ___||  _    |";
	gotoxy(60,25);
	cout << "|   |_| ||   | |   _   || | |   ||   |_| |   |     | |   | |   |___ | | |   |";
	gotoxy(60,26);
	cout << "|_______||___| |__| |__||_|  |__||_______|    |___|  |___| |_______||_|  |__|";
	veNutMenu(3,10,6,"Lop",112);
	veNutMenu(3,10,11,"Sinh vien",30);
	veNutMenu(3,10,16,"Mon hoc",30);
	veNutMenu(3,10,21,"Diem",30);
	gotoxy(50,5);
	AnConTro();
	int choose = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(1)
	{
		if (s == ESC)
		{
			if (Exit(s,sCheck) == true)
			{
				return -1;
			}
			else 
			{
				system("cls");
				TextColor(241);
				veKhungThuCong();
				InTB("ENTER: Chon	ESC: Thoat",35,43);
				gotoxy(80,10);
				cout << " __   __  _______  __    _  __   __ ";
				gotoxy(80,11);
				cout << "|  |_|  ||       ||  |  | ||  | |  |";
				gotoxy(80,12);
				cout << "|       ||    ___||   |_| ||  | |  |";
				gotoxy(80,13);
				cout << "|       ||   |___ |       ||  |_|  |";
				gotoxy(80,14);
				cout << "|       ||    ___||  _    ||       |";
				gotoxy(80,15);
				cout << "| ||_|| ||   |___ | | |   ||       |";
				gotoxy(80,16);
				cout << "|_|   |_||_______||_|  |__||_______|";
				gotoxy(60,20);
				cout << " _______  ___   _______  __    _  _______    __   __  ___   _______  __    _ ";
				gotoxy(60,21);
				cout << "|       ||   | |   _   ||  |  | ||       |  |  | |  ||   | |       ||  |  | |";
				gotoxy(60,22);
				cout << "|    ___||   | |  |_|  ||   |_| ||    ___|  |  |_|  ||   | |    ___||   |_| |";
				gotoxy(60,23);
				cout << "|   | __ |   | |       ||       ||   | __   |       ||   | |   |___ |       |";
				gotoxy(60,24);
				cout << "|   ||  ||   | |       ||  _    ||   ||  |  |       ||   | |    ___||  _    |";
				gotoxy(60,25);
				cout << "|   |_| ||   | |   _   || | |   ||   |_| |   |     | |   | |   |___ | | |   |";
				gotoxy(60,26);
				cout << "|_______||___| |__| |__||_|  |__||_______|    |___|  |___| |_______||_|  |__|";
				
				veNutMenu(3,10,6,"Lop",112);
				veNutMenu(3,10,11,"Sinh vien",30);
				veNutMenu(3,10,16,"Mon hoc",30);
				veNutMenu(3,10,21,"Diem",30);
				choose = 0;
			}
		}
		if (s == UP && sCheck == false )
		{	
			if(choose > 0 )
			{
				switch(choose)
				{
					case 1:
						{
							veNutMenu(3,10,6,"Lop",112);
							veNutMenu(3,10,11,"Sinh vien",30);
							break;
						}
					case 2:
						{
							veNutMenu(3,10,11,"Sinh vien",112);
							veNutMenu(3,10,16,"Mon hoc",30);
							break;
						}
					case 3:
						{
							veNutMenu(3,10,16,"Mon hoc",112);
							veNutMenu(3,10,21,"Diem",30);
							break;
						}	
				}
				choose --;
			}
		}
		if (s == DOWN && sCheck == false )
		{
			if(choose < 3 )
			{
				switch(choose)
				{
					case 0:
						{
							veNutMenu(3,10,6,"Lop",30);
							veNutMenu(3,10,11,"Sinh vien",112);
							break;
						}
					case 1:
						{
							veNutMenu(3,10,11,"Sinh vien",30);
							veNutMenu(3,10,16,"Mon hoc",112);
							break;
						}
					case 2:
						{
							veNutMenu(3,10,16,"Mon hoc",30);
							veNutMenu(3,10,21,"Diem",112);
							break;
						}
				}
				choose ++;
			}
		}
		if (s == ENTER)
		{
			return choose;
		}
	{
		batPhim(s,sCheck);
	}
	}
	
	return -1;
}


void mainProcess(dslop &dsl, dssv &ds, DSMH &dsm, int arr1[], int arr2[])
{
	string masv;
	DocFileDSMHV(dsm, arr1, arr2);
	DocFileDSLop(dsl);
	int idlonnhat;
	DSMH pMonThi;
	while(1)
	{
		HienConTro();
		switch(DangNhap(dsl,masv))
		{
		case 0:
			{
				while(1)
				{
					system("cls");
					TextColor(241);
					int tg = 0;
					int sct = 0;
					bool check;
					NhapMonThi(dsm, pMonThi, idlonnhat, tg,sct, check);
					if(check == false)
					{
						break;
					}
					//THI
					string diem;
					CTdethi ctdt;
					ctdt.bode = new int [sct];
					ctdt.dapan = new int [sct];
					lop *l = traVeLopTuMSSV(dsl, masv);
					int checkThi = FunctionThi(l, masv, dsm, pMonThi,tg,sct,diem,ctdt);
					stop = 1;
					if(ctdt.bode != NULL)
					{
						float diemthi = StringToFloat(diem);
						nodeSV *sv;
						for(int i = 0; i < dsl.solop; i++)
						{
							sv = search_SV(dsl.l[i]->danhsach,masv);
							if(sv == NULL)
							{
								continue;
							}
							else
							{
								break;
							}
						}
						diemThi diemsv;
						diemsv.ctdt = ctdt;
						diemsv.diem = diemthi;
						diemsv.idMonHoc = pMonThi->id;
						if (sv->info.diem.First == NULL) 
						{
							Insert_Diem_First(sv->info.diem.First,diemsv);
						}
						else 
						{
							nodediemThi *p = sv->info.diem.First;
							while (p->pNext != NULL)
							{
								p = p->pNext;
							}
							Insert_Diem_after(p,diemsv);
						}
					}
					else break;
					if(checkThi == 0) {LuuFileDSlop(dsm,dsl,"DSLOP.txt"); break;}
					LuuFileDSlop(dsm,dsl,"DSLOP.txt");
				}
				break;
			}
		case 1:
			{
				system("cls");
				bool check = true;
				while(check != false)
				{
					switch(mainMenu())
					{
						case 0: //LOP
						{
							ChangeColor(15);
							system("cls");
							TextColor(241);
							FunctionLop(dsl);
							break;
						}
						case 1: //SINH VIEN
						{
							system("cls");
							TextColor(241);
							FunctionSV(dsl);
							break;
						}
						case 2://MON HOC
						{
							system("cls");
							TextColor(241);
							FunctionMH(dsm, dsl, idlonnhat, arr1, arr2);
							break;
						}	
						case 3://DIEM
						{
							system("cls");
							TextColor(241);
							FunctionDiem(dsl,ds,dsm,idlonnhat);
							break;	
						}
						case -1://THOAT
						{
							check = false;
							break;
						}
					}
				}
				break;
			}	
		case -1:
			{
				char s;
				bool sCheck;
				if(Exit(s,sCheck)== true)
				{	
					system("cls");
					gotoxy(0,0);
					TextColor(241);
					veKhungThuCong();
					LuuFileDSlop(dsm, dsl,"DSLOP.txt");
					LuuFileMH(dsm,"DSMONHOCVACH.txt", idlonnhat);
					gotoxy(30,20);
					cout << " _________  ____  ____       _       ____  _____  ___  ____    ____  ____   ___   _____  _____  _  ";
					gotoxy(30,21);
					cout << "|  _   _  ||_   ||   _|     / \\     |_   \\|_   _||_  ||_  _|  |_  _||_  _|.'   `.|_   _||_   _|| | ";
					gotoxy(30,22);
					cout << "|_/ | | \\_|  | |__| |      / _ \\      |   \\ | |    | |_/ /      \\ \\  / / /  .-.  \\ | |    | |  | | ";
    				gotoxy(30,23);
					cout << "    | |      |  __  |     / ___ \\     | |\\ \\| |    |  __'.       \\ \\/ /  | |   | | | '    ' |  | | ";
					gotoxy(30,24);
					cout << "   _| |_    _| |  | |_  _/ /   \\ \\_  _| |_\\   |_  _| |  \\ \\_     _|  |_  \\  `-'  /  \\ \\__/ /   |_| ";
					gotoxy(30,25);
					cout << "  |_____|  |____||____||____| |____||_____|\\____||____||____|   |______|  `.___.'    `.__.'    (_) ";
					getch();
					return;
			 	}
				else
				{
					break;
				}
			}
		}
	}
}
#endif
