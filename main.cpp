/*
Tema Proyek : Sistem Manajemen Toko

Programmed by Kelompok 4 :
1. /1232300
2. /1232300
3. /1232300
4. /1232300
5. /1232300
*/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void errorH();

int main(){
    buatStack() ;
    char yn;

    cout << "===================================" << endl;
    cout << "        Menu Toko Serba Ada" << endl;
    cout << "===================================" << endl;
    // getch();
    system("cls");
    menu();
    do{
        cout << endl << endl;
        cout << "Kembali ke Menu[y/n] : ";
        cin >> yn;
        cout << endl;
        if (yn == 'n' || yn == 'N'){
            cout << "Terimakasih Telah Menggunakan Program Ini!";
            exit(0);
        }
        else if (!(yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N')){
            errorH();
        }

        system("cls");
        menu();
    } while (yn == 'y' || yn == 'Y');

    return 0;
}

void menu(){

    int pilih;

    cout << "===================================" << endl;
    cout << "            Menu Utama" << endl;
    cout << "===================================" << endl;
    cout << "[1] Penyisipan Data Menggunakan Hash" << endl;
    cout << "[2] Tampil Data Menggunakan Hash" << endl;
    cout << "[3] Penghapusan Data Menggunakan Hash" << endl;
    cout << "[4] Pencarian Kode Produk Menggunakan Hash" << endl;
    cout << "[5] Pencarian Nama Produk Menggunakan BST" << endl;
    cout << "[6] Pengurutan Nama Produk (Descending) Menggunakan BST Post-Order" << endl;
    cout << "[7] History Product" << endl; // Menampilkan Data yang Telah di Hapus menggunakan in-order, post-order, dan pre-order
    cout << "[8] Keluar" << endl;
    cout << "===================================" << endl;
    cout << "Masukkan Inputan[1-8] : ";
    cin >> pilih;
    system("cls");
    cout << endl;

    switch (pilih){
    case 1:
        menu1();
        break;
    case 2:
        menu2();
        break;
    case 3:
        menu3();
        break ;
    case 4:
        menu4();
        break;
    case 5:
        menu5();
        break;
    case 6:
        menu6();
        break;
    case 7:
        menu7();
        break;
    case 8:
        cout << "Terimakasih Telah Menggunakan Program Ini!";
        exit(0);
        break;
    default:
        errorH();
        break;
    }
}

void errorH(){

    char yn;
    cout << endl << endl;

    cout << "Masukkan yang Anda Masukkan Salah" << endl;
    cout << "Kembali ke Menu[y/n] : ";
    cin >> yn;
    if (yn == 'n' || yn == 'N'){
        cout << "Terimakasih Telah Menggunakan Program Ini!";
        exit(0);
    }
    else if (yn == 'y' || yn == 'Y'){
        menu();
    }
    else
        errorH();
}

void menu1(){
    cout << "Testing" << endl ;
}

void menu2(){
    cout << "Testing" << endl ;
}

void menu3(){
    cout << "Testing" << endl ;
}

void menu4(){
    cout << "Testing" << endl ;
}

void menu5(){
    cout << "Testing" << endl ;
}

void menu6(){
    cout << "Testing" << endl ;
}

void menu7(){
    cout << "Testing" << endl ;
}



// void buatStack();
// bool isEmptyStack();
// int countStack();

// bool isEmptyQueue();
// int countQueue();



// struct dataS{
//     string namaS;
//     int absenS;
// } ;

// struct node{
//     dataS siswa ;

//     node *next ;
//     node *prev ;
// } ;

// node *nb, *head, *tail, *bantu, *cur, *top, *bottom ;



// bool isEmptyStack(){
//     if (bottom == NULL) {
//         return true ;
//     } return false ;
// }

// void buatStack(){
//     bottom = NULL ;
//     top = NULL ;
// }

// int countStack(){
//     if (bottom == NULL){
//         return 0 ;
//     } else {
//         int i = 0 ;
//         bantu = bottom ;
//         while(bantu != NULL) {
//             bantu = bantu->next ;
//             i++ ;
//         }
//         return i ;
//     }
// }

// bool isEmptyQueue(){
//     if (head == NULL) {
//         return true ;
//     } return false ;
// }

// int countQueue(){

//   if (head == NULL) {
//     return 0;
//   } else {
//     int banyak = 0;
//     cur = head;
//     while (cur != NULL) {
//       cur = cur->next;
//       banyak++;
//     }
//     return banyak;
//   }
// }

// void menu1(){   // push stack
//     int banyakSiswa ;
//     string cinNamaS ;
//     int cinAbsenS ;

//     cout << "==========================" << endl ;
//     cout << "        Input Data" << endl ;
//     cout << "==========================" << endl ;
//     cout << "Jumlah Siswa : " ; cin >> banyakSiswa ;

//     cin.ignore() ;
//     for(int i = 0; i < banyakSiswa; i++){
//         cout << "Siswa-" << i+1 << endl ;
//         cout << "Masukkan Nama : " ; getline(cin, cinNamaS) ;
//         cout << "Masukkan Absen : " ; cin >> cinAbsenS ;
//         cin.ignore() ;

//         nb = new node();
//         nb->siswa.namaS = cinNamaS;
//         nb->siswa.absenS = cinAbsenS;
//         nb->next = NULL;
//         nb->prev = top;

//         if(isEmptyStack()){
//             bottom = nb;
//         } else {
//             top->next = nb;
//         }
//         top = nb;
//     }

//     cout << "Siswa Berhasil ditambah!" << endl ;
// }

// void menu2(){   // display stack

//     cout << "==========================" << endl ;
//     cout << "        Lihat Data" << endl ;
//     cout << "==========================" << endl ;

//     if (isEmptyStack()){
//         cout << "Data Siswa Kosong!" << endl ;
//         return ;
//     }

//     bantu = top; 
//     while (bantu != NULL){
//         cout << "[" << bantu->siswa.namaS << ", " << bantu->siswa.absenS << "]" << endl;
//         bantu = bantu->prev;
//     }
// }

// void menu3(){   // pop stack

//     cout << "==========================" << endl ;
//     cout << "        Hapus Data" << endl ;
//     cout << "==========================" << endl ;

//     if (isEmptyStack()){
//         cout << "Data Siswa Kosong!" << endl ;
//         return ;
//     }

//     cout << "Data Siswa" << endl ;
//     cout << "Nama : " << top->siswa.namaS << endl ;
//     cout << "Absen : " << top->siswa.absenS << endl << endl ;
//     cout << "Berhasil diambil!" << endl ;

//     bantu = top;
//     top = top->prev; 

//     if (top != NULL) {
//         top->next = NULL; 
//     } else {
//         bottom = NULL; 
//     }

//     delete bantu;
// }

// void menu4(){   // edit stack

//     string cinCari, namaBaru ;
//     int absenBaru ;
//     bool cari = false ;

//     cout << "=========================" << endl ;
//     cout << "        Edit Data" << endl ;
//     cout << "=========================" << endl ;

//     if (isEmptyStack()){
//         cout << "Data Siswa Kosong!" << endl ;
//         return ;
//     }

//     cin.ignore();
//     cout << "Masukkan Data Siswa yang Ingin Diedit: "; getline(cin, cinCari);
//     cout << endl ;

//     bantu = bottom;
//     while (bantu != NULL) {
//         if (bantu->siswa.namaS == cinCari) {
//             cari = true;
//             cout << "Data ditemukan!" << endl ;

//             cout << "Masukkan Data Siswa Baru : "; getline(cin, namaBaru);
//             cout << "Masukkan Absen Baru : "; cin >> absenBaru ;
//             cin.ignore() ;

//             cout << endl ;
//             bantu->siswa.namaS = namaBaru;
//             bantu->siswa.absenS = absenBaru;
//             cout << "Data Berhasil diedit!" << endl;
//             break;
//         }
//         bantu = bantu->next;
//     }

//     if (!cari) {
//         cout << "Siswa Bernama " << cinCari << " Tidak Ditemukan." << endl;
//     }
// }


// void menu5(){   // enqueue tapi dari stack

//     cout << "=========================================" << endl;
//     cout << "        Masukkan ke Dalam Antrian" << endl;
//     cout << "=========================================" << endl;

//     if (isEmptyStack()){
//         cout << "Data Siswa dalam Stack Kosong!" << endl ;
//         return ;
//     }

//     bantu = top; 
//     while (bantu != NULL){
//         nb = new node();
//         nb->siswa = bantu->siswa; 
//         nb->next = NULL;

//         if (isEmptyQueue()) {
//             head = nb;
//             tail = nb;
//         } else {
//             tail->next = nb;
//             tail = nb;
//         }
//         bantu = bantu->prev;
//     }

//     //  destroy stack

//     while (top != NULL) {
//         bantu = top;
//         top = top->prev;
//         delete bantu;
//     }
//     bottom = NULL;


//     cout << "Semua Data di Stack Dimasukkan ke dalam Antrian" << endl ;

// }

// void menu6(){   // display
//     int i = 1 ;

//     cout << "=============================" << endl ;
//     cout << "        Lihat Antrian" << endl ;
//     cout << "=============================" << endl ;

//     if (isEmptyQueue()){
//         cout << "Antrian Kosong!" << endl ;
//         return ;
//     }

//     int banyakAntrian = countQueue();

//     cur = head;
//     while (cur != NULL) {
//         cout << i << ".[" << cur->siswa.namaS << ", " << cur->siswa.absenS << "]" << endl ; 
//         i++ ;
//       cur = cur->next;
//     }

// }

// void menu7(){   // dequeue

//     cout << "==============================" << endl ;
//     cout << "        Layani Antrian" << endl ;
//     cout << "==============================" << endl ;
//     if (isEmptyQueue()){
//         cout << "Antrian Kosong!" << endl ;
//         return ;
//     }
//     cout << "[" << head->siswa.namaS << ", " << head->siswa.absenS << "]" << endl ;
    
//     cout << "Dilayani!" << endl ;
    
//     bantu = head ;
//     head = head->next ;
//     bantu->next = NULL ;
//     delete bantu ; 
// }