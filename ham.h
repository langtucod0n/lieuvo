#ifndef HAM_H
#define HAM_H
#define MAX 100

struct taiKhoan {
    char tenDangNhap[MAX];
    char pass[MAX];
    char hoTen[MAX];
    char email[MAX];
    int ngay, thang, nam;
};

bool checkTenDangNhap(taiKhoan* tk);
bool checkPass(taiKhoan* tk);
bool checkEmail(taiKhoan* tk);
bool checkHoTen(taiKhoan* tk);
void nhap(taiKhoan* arr);
taiKhoan** listTaiKhoan(taiKhoan** arr, int& n);
void xuat(taiKhoan* arr);
void xuatList(taiKhoan** arr, int n);
void timKiem(taiKhoan** arr, int n);
taiKhoan** themTaiKhoan(taiKhoan** arr, int& n);
void xoaTaiKhoan(taiKhoan** arr, int& n);
bool soSanhTheoTenDangNhap(taiKhoan* a, taiKhoan* b);
bool soSanhTheoHoTen(taiKhoan* a, taiKhoan* b);
bool soSanhTheoNgaySinh(taiKhoan* a, taiKhoan* b);
void sapXepDanhSachTaiKhoan(taiKhoan** arr, int n, bool (*soSanh)(taiKhoan*, taiKhoan*));
void chucMungSinhNhat(taiKhoan** arr, int n);


#endif
