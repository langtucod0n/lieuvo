#include <iostream>
#include "ham.h"

using namespace std;

int main() {
    int luaChon;
    taiKhoan** arr = nullptr;
    int n;
    do {
        cout << "=== Quan ly tai khoan ===" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. Hien thi danh sach" << endl;
        cout << "3. Tim kiem theo ho ten" << endl;
        cout << "4. Nhap vao 1 tai khoan" << endl;
        cout << "5. Xoa tai khoan" << endl;
        cout << "6. Chuc mung sinh nhat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            arr = listTaiKhoan(arr, n);
            break;
        case 2:
            xuatList(arr, n);
            break;
        case 3:
            timKiem(arr, n);
            break;
        case 4:
            arr = themTaiKhoan(arr, n);
            break;
        case 5:
            xoaTaiKhoan(arr, n);
            break;
        case 6: 
            chucMungSinhNhat(arr, n);
            break;
        case 0:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);

    return 0;
}
