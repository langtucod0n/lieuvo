#include "ham.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool checkTenDangNhap(taiKhoan* tk) {
    return strstr(tk->tenDangNhap, "admin") == nullptr;
}

bool checkPass(taiKhoan* tk) {
    if (strlen(tk->pass) < 6) return false;
    bool inHoa = false, inThuong = false, coSo = false, kiTu = false;
    char kiTuDacBiet[] = ";.?:~-_";
    for (int i = 0; i < strlen(tk->pass); i++) {
        if (isupper(tk->pass[i])) inHoa = true;
        if (islower(tk->pass[i])) inThuong = true;
        if (isdigit(tk->pass[i])) coSo = true;
        if (strchr(kiTuDacBiet, tk->pass[i])) kiTu = true;
    }
    return inHoa && inThuong && coSo && kiTu;
}

bool checkEmail(taiKhoan* tk) {
    return strchr(tk->email, '@') && strchr(tk->email, '.');
}

bool checkHoTen(taiKhoan* tk) {
    int count = 0;
    for (int i = 0; i < strlen(tk->hoTen); i++) {
        if (tk->hoTen[i] == ' ') {
            count++;
        }
    }
    return count >= 2;
}

void nhap(taiKhoan* arr) {
    cout << "Ten dang nhap: ";
    cin.ignore();
    cin.getline(arr->tenDangNhap, MAX);
    while (!checkTenDangNhap(arr)) {
        cout << "Ten dang nhap khong hop le, nhap lai: ";
        cin.getline(arr->tenDangNhap, MAX);
    }

    char check[MAX];
    do {
        cout << "Nhap mat khau: ";
        cin.getline(arr->pass, MAX);
        cout << "Nhap lai mat khau: ";
        cin.getline(check, MAX);

        if (strcmp(arr->pass, check) != 0 || !checkPass(arr)) {
            cout << "Mat khau khong hop le hoac khong trung khop! Nhap lai.\n";
        }

    } while (strcmp(arr->pass, check) != 0 || !checkPass(arr));

    cout << "Ho ten: ";
    cin.getline(arr->hoTen, MAX);
    while (!checkHoTen(arr)) {
        cout << "Ten chua hop le, nhap lai: ";
        cin.getline(arr->hoTen, MAX);
    }

    cout << "Email: ";
    cin.getline(arr->email, MAX);
    while (!checkEmail(arr)) {
        cout << "Email chua hop le, nhap lai: ";
        cin.getline(arr->email, MAX);
    }

    cout << "Ngay thang nam sinh: ";
    cin >> arr->ngay >> arr->thang >> arr->nam;
    cin.ignore(); // B? qua ký t? newline sau khi nh?p s?
}

taiKhoan** listTaiKhoan(taiKhoan** arr, int& n) {
    cout << "Nhap so luong tai khoan: ";
    cin >> n;
    cin.ignore();
    arr = new taiKhoan * [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new taiKhoan;
        nhap(arr[i]);
    }
    return arr;
}

void xuat(taiKhoan* arr) {
    cout << "Ten dang nhap: " << arr->tenDangNhap << endl;
    cout << "Mat khau: " << arr->pass << endl;

    char ho[MAX], ten[MAX], tenlot[MAX];
    char temp[MAX];
    char* word[10];
    int count = 0;

    strcpy_s(temp, arr->hoTen);
    char* next_token = nullptr;
    char* token = strtok_s(temp, " ", &next_token);
    while (token != nullptr) {
        word[count] = token;
        count++;
        token = strtok_s(nullptr, " ", &next_token);
    }

    strcpy_s(ho, word[0]);
    strcpy_s(ten, word[count - 1]);
    tenlot[0] = '\0';
    for (int i = 1; i < count - 1; i++) {
        strcat_s(tenlot, word[i]);
        if (i < count - 2) {
            strcat_s(tenlot, " ");
        }
    }

    cout << "Ho: " << ho << endl;
    cout << "Ten lot: " << tenlot << endl;
    cout << "Ten: " << ten << endl;
    cout << "Email: " << arr->email << endl;
    cout << "Tuoi: " << 2024 - arr->nam << endl;
}

void xuatList(taiKhoan** arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin tai khoan " << i + 1 << " :" << endl;
        xuat(arr[i]);
    }
}

void timKiem(taiKhoan** arr, int n) {
    char nguon[MAX];
    cout << "Nhap ten can tim: ";
    cin.ignore();
    cin.getline(nguon, MAX);
    for (int i = 0; i < n; i++) {
        if (strstr(arr[i]->hoTen, nguon)) {
            xuat(arr[i]);
        }
    }
}

taiKhoan** themTaiKhoan(taiKhoan** arr, int& n) {
    taiKhoan** newarr = new taiKhoan * [n + 1];
    for (int i = 0; i < n; i++) {
        newarr[i] = arr[i];
    }
    newarr[n] = new taiKhoan;
    nhap(newarr[n]);
    n++;
    delete[] arr; // Gi?i phóng m?ng c?
    return newarr;
}

void xoaTaiKhoan(taiKhoan** arr, int& n) {
    char tendangnhap[MAX];
    cout << "Nhap ten dang nhap can xoa: ";
    cin.ignore();
    cin.getline(tendangnhap, MAX);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i]->tenDangNhap, tendangnhap) == 0) {
            delete arr[i];
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--;
            cout << "Xoa tai khoan thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay tai khoan voi ten dang nhap: " << tendangnhap << endl;
}

bool soSanhTheoTenDangNhap(taiKhoan* a, taiKhoan* b) {
    return strcmp(a->tenDangNhap, b->tenDangNhap) > 0;
}

bool soSanhTheoHoTen(taiKhoan* a, taiKhoan* b) {
    return strcmp(a->hoTen, b->hoTen) > 0;
}

bool soSanhTheoNgaySinh(taiKhoan* a, taiKhoan* b) {
    if (a->nam != b->nam) return a->nam > b->nam;
    if (a->thang != b->thang) return a->thang > b->thang;
    return a->ngay > b->ngay;
}

void chucMungSinhNhat(taiKhoan** arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i]->thang == 11) {
            cout << "Chuc mung sinh nhat " << arr[i]->hoTen << endl;
        }
    }
}
