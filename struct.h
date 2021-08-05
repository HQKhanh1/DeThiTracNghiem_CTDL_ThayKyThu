#include<iostream>
#ifndef _STRUCT_H
#define _STRUCT_H
#define MAXMH 100
#define MAXLOP 500
#define MAXCAUHOI 200
#define STACKSIZE 1000

using namespace std;
//// ===============================DANH SACH MON HOC=============================
//struct monHoc
//{
//	string maMH;
//	string tenMH;	
//};
////danh s�ch tuy?n t�nh 
//struct DSMH
//{
//	int somon = 0;
//	monHoc *m[MAXMH] = {NULL};	
//};
//struct CTdethi
//{
//	int sct;
//	int tg;
//	int *bode;
//	int *dapan;
//};
//// ===============================DANH SACH DIEM THI=============================
//struct diemThi
//{
//	string maMH;
//	float diem;
//	CTdethi ctdt;
//};
//struct nodediemThi
//{
//	diemThi info;
//	nodediemThi *pNext = NULL;
//};
//struct dsdiemThi
//{
//	nodediemThi *First = NULL;
//};
//// ===============================DANH SACH SINH VIEN=============================
//struct sinhVien
//{
//	string maSV;
//	string ho;
//	string ten;
//	string gioiTinh;
//	string password;
//	dsdiemThi diem;
//};
//struct nodeSV
//{
//	sinhVien info;
//	nodeSV *pNext = NULL;
//};
//struct dssv
//{
//	nodeSV *First = NULL;
//};
//// ===============================DANH SACH LOP=============================
//struct lop
//{
//	string maLop;
//	string tenLop;
//	string nienKhoa;
//	dssv danhsach;
//};
//struct dslop
//{
//	int solop;
//	lop *l [MAXLOP] = {NULL};
//};
//// ===============================DANH SACH CAU HOI=============================
//struct cauHoi
//{
//	string maMH;
//	string noiDung;
//	string A;
//	string B;
//	string C;
//	string D;
//	string dapAn;
//};
//struct nodecauHoi
//{
//	int id;
//	cauHoi info;
//	nodecauHoi *pLeft = NULL;
//	nodecauHoi *pRight = NULL;
//};
//typedef struct nodecauHoi *NODECH;
//struct dscauhoi
//{
//	nodecauHoi *Root = NULL;
//};
//// ===============================THOI GIAN=============================
//struct TG 
//{
//	int gio;
//	int phut;
//	int giay;
//};
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
struct CTdethi
{
	int sct;
	int tg;
	int *bode;
	int *dapan;
};
void khoiTaoCay(DSMH &tree){
	tree = NULL;
}
// ===============================DANH SACH DIEM THI=============================
struct diemThi
{
	int idMonHoc;
	float diem;
	CTdethi ctdt;
};
struct nodediemThi
{
	diemThi info;
	nodediemThi *pNext = NULL;
};
struct dsdiemThi
{
	nodediemThi *First = NULL;
};
// ===============================DANH SACH SINH VIEN=============================
struct sinhVien
{
	string maSV;
	string ho;
	string ten;
	string gioiTinh;
	string password;
	dsdiemThi diem;
};
struct nodeSV
{
	sinhVien info;
	nodeSV *pNext = NULL;
};
struct dssv
{
	nodeSV *First = NULL;
};
// ===============================DANH SACH LOP=============================
struct lop
{
	string maLop;
	string tenLop;
	dssv danhsach;
};
struct dslop
{
	int solop;
	lop *l [MAXLOP] = {NULL};
};

// ===============================THOI GIAN=============================
struct TG 
{
	int gio;
	int phut;
	int giay;
};
#endif
