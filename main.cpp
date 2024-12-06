/*
Tema Proyek : Sistem Manajemen Toko

Programmed by Kelompok 4 :
1. Valentino Abinata        / 123230013
2. Adi Setya Nur Pradipta   / 123230026
3. Rheza Priya Anargya      / 123230032
4. Muhammad David Firdaus   / 123230039
5. Gusti Rama               / 123230040
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#define TABLE_SIZE 10

using namespace std;

struct Produk{
    string nama ;
    string kode ;
    int harga ;
} ;

struct node{
    Produk produk ; 
    node *next ;
} ;

node *hashTable[TABLE_SIZE] = {nullptr} ;
node *nb, *db, *bantu ;
// nodebaru, databaru, 

void menu();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void menu7sub1();
void menu7sub2();
void menu7sub3();

bool isEmptyHash() ;
int hashKey(string kode) ;

void errorH();

int main(){
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

    int cinputan;

    cout << "===================================" << endl;
    cout << "            Menu Utama" << endl;
    cout << "===================================" << endl;
    cout << "[1] Penyisipan Data" << endl;
    cout << "[2] Tampil Data" << endl;
    cout << "[3] Penghapusan Data" << endl;
    cout << "[4] Pencarian Kode Produk" << endl;
    cout << "[5] Pencarian Range Nama Produk" << endl;
    cout << "[6] Pengurutan Nama Produk (Descending)" << endl;
    cout << "[7] History Product" << endl;
    cout << "[8] Keluar" << endl;
    cout << "===================================" << endl;
    cout << "Masukkan Inputan[1-8] : "; cin >> cinputan;
    system("cls");
    cout << endl;

    switch (cinputan){
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
    string cnama, ckode ;
    int cjum, charga ;

    cout << "================================================" << endl ;
    cout << "        Penyisipan Data Menggunakan Hash" << endl ;
    cout << "================================================" << endl ;
    cout << "Masukkan Jumlah Jenis Produk : " ; cin >> cjum ; 

    for(int i = 0; i < cjum; i++){
    cin.ignore() ;
    cout << "Jenis Produk ke-" << i+1 << endl ;
    cout << "Masukkan Nama Produk : " ; getline(cin, cnama) ;
    cout << "Masukkan Kode Produk : " ; getline(cin, ckode) ;
    cout << "Masukkan Harga Produk[Tanpa Titik/ Koma] : Rp." ; cin >> charga ;
    cout << endl << endl;
    
    int index = hashKey(ckode);
    cout << "indeksnya : " << index ; // testing
    nb = new node();
    nb->produk.nama = cnama;
    nb->produk.kode = ckode;
    nb->produk.harga = charga;
    nb->next = NULL ;

    if (!hashTable[index]) {
            hashTable[index] = nb; // Tidak ada collision, langsung masukkan
        } else {
            // Penanganan collision dengan chaining
            bantu = hashTable[index];
            while (bantu->next != nullptr) {
                bantu = bantu->next;
            }
            bantu->next = nb;
        }
    }

    cout << "Data produk berhasil disisipkan!" << endl;
    
}

bool isEmptyHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            return false;
        }
    }
    return true;
}


int hashKey(string kode) {
    int hashValue = 0;
    for (char c : kode) {
        hashValue += static_cast<int>(c); // Menjumlahkan nilai ASCII
    }
    return hashValue % TABLE_SIZE; // Mengambil modulus dengan ukuran tabel
}

void menu2(){
    bool ada = false;

    cout << "============================================" << endl ;
    cout << "        Tampil Data Menggunakan Hash" << endl ;
    cout << "============================================" << endl ;

    if(isEmptyHash()){
        cout << "Hash Masih Kosong!" << endl ;
        return ;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        bantu = hashTable[i];
        cout << "index " << i << endl ;
        while (bantu) {
            cout << "[" << bantu->produk.nama << ", " ;
            cout << bantu->produk.harga << ", " ;
            cout << bantu->produk.kode << "]" << endl ;
            bantu = bantu->next ;
            ada = true ;
        }
        if(!ada){
            cout << "Data Indeks Ini Kosong!" << endl ;
        }
        ada = false ;
        cout << endl ;
    }

}

void menu3(){
    string ckode ;

    cout << "=================================================" << endl ;
    cout << "        Penghapusan Data Menggunakan Hash" << endl ;
    cout << "=================================================" << endl ;

    if(isEmptyHash()){
        cout << "Hash Masih Kosong!" << endl ;
        return ;
    }

    cin.ignore();
    cout << "Masukkan Kode Produk : " ; getline(cin, ckode) ;
    int index = hashKey(ckode);
    
    if (!hashTable[index]) {
        cout << "Data dengan Kode '" << ckode << "' Tidak Ditemukan pada Indeks Ini" << endl;
        return;
    }

    bantu = hashTable[index];
    node *prev = NULL;

    // Cari data yang ingin dihapus
    while (bantu != NULL && bantu->produk.kode != ckode) {
        prev = bantu;
        bantu = bantu->next;
    }

    if (!bantu) {
        cout << "Produk dengan kode " << ckode << " tidak ditemukan!" << endl;
    } else {
            // Hapus node
        if (!prev) {
            // Jika node yang dihapus adalah head
            hashTable[index] = bantu->next;
        } else {
            // Jika node yang dihapus ada di tengah atau akhir
            prev->next = bantu->next;
        }

        delete bantu;
        cout << "Produk dengan kode " << ckode << " berhasil dihapus!" << endl;
    }

}

void menu4(){
    string ckode ;

    cout << "======================================================" << endl ;
    cout << "        Pencarian Kode Produk Menggunakan Hash" << endl ;
    cout << "======================================================" << endl ;

    if(isEmptyHash()){
        cout << "Hash Masih Kosong!" << endl ;
        return ;
    }

    cin.ignore();
    cout << "Masukkan Kode Produk : " ; getline(cin, ckode) ;
    int index = hashKey(ckode);
    
    if (!hashTable[index]) {
        cout << "Data dengan Kode '" << ckode << "' Tidak Ditemukan pada Indeks Ini" << endl;
        return;
    }

    bantu = hashTable[index];
    while (bantu != nullptr) {
        if (bantu->produk.kode == ckode) {
            cout << "Produk Ditemukan!" << endl << endl;
            cout << "Nama: " << bantu->produk.nama << endl;
            cout << "Harga: Rp." << bantu->produk.harga << endl;
            cout << "Kode: " << bantu->produk.kode << endl;
            return;
        }
        bantu = bantu->next;
    }

    // Jika produk tidak ditemukan
    cout << "Produk dengan kode '" << ckode << "' tidak ditemukan!" << endl;

}

void menu5(){
    cout << "===========================================================" << endl ;
    cout << "        Pencarian Range Nama Produk Menggunakan BST" << endl ;
    cout << "===========================================================" << endl ;

    //if isEmptyBST
}

void menu6(){
    cout << "==============================================================================" << endl ;
    cout << "        Pengurutan Nama Produk (Descending) Menggunakan BST Post-Order" << endl ;
    cout << "==============================================================================" << endl ;

    //if isEmptyBST
}

void menu7(){
    int cinputan ;

    cout << "===============================" << endl ;
    cout << "        History Product" << endl ;
    cout << "===============================" << endl ;
    //if isEmptyBST
    cout << "[1] In-Order" << endl ;
    cout << "[2] Post-Order" << endl ;
    cout << "[3] Pre-Order" << endl ;
    cout << "Masukkan Inputan[1-3] : "; cin >> cinputan;
    system("cls");
    cout << endl;

    switch (cinputan){
    case 1:
        menu7sub1();
        break;
    case 2:
        menu7sub2();
        break;
    case 3:
        menu7sub3();
        break ;
    default:
        errorH();
        break;
    }
}

void menu7sub1(){
    cout << "========================" << endl ;
    cout << "        In-Order" << endl ;
    cout << "========================" << endl ;
}
void menu7sub2(){
    cout << "==========================" << endl ;
    cout << "        Post-Order" << endl ;
    cout << "==========================" << endl ;
}
void menu7sub3(){
    cout << "=========================" << endl ;
    cout << "        Pre-Order" << endl ;
    cout << "=========================" << endl ;
}



// PUNYA MBA WINDY
// #include <bits/stdc++.h>
// #include <conio.h>

// using namespace std;

// struct Buku {
//     string judul;
//     string penulis;
//     int kodeReferensi;
// };

// struct HashNode {
//     Buku buku;
//     HashNode* next;
// };

// struct BinaryTree {
//     Buku buku;
//     BinaryTree* left;
//     BinaryTree* right;
// };

// struct HistoryNode {
//     Buku buku;
//     HistoryNode* left;
//     HistoryNode* right;
// };

// HashNode* hashTable[1000] = {nullptr};
// BinaryTree* root = nullptr;
// HistoryNode* historyTree = nullptr;

// // Function prototypes
// int hashFunction(int kodeReferensi);
// void TambahBukuKeHash(const Buku& buku);
// void HapusDariHash(int kodeReferensi);
// void TampilBukuHash();
// HashNode* CariBukuHash(int kodeReferensi);
// void TambahBukuPTB(const Buku& buku);
// void inOrderTraversal(BinaryTree* node);
// void HapusDariPTB(const int& kodeReferensi);
// void TambahBukuRiwayat(const Buku& buku);
// void RiwayatInOrder(HistoryNode* node);
// void RiwayatPostOrder(HistoryNode* node);
// void RiwayatPreOrder(HistoryNode* node);
// bool CekKosongHash();
// bool suksesInputhash;


// int main() {
//     int pilih;

//     do {
//         suksesInputhash = false;
//         system("cls");
//         cout << "Library Management System\n";
//         cout << "1. Tambah Buku\n";
//         cout << "2. Hapus Data Buku\n";
//         cout << "3. Display Books\n";
//         cout << "4. Cari Buku Berdasarkan Kode\n";
//         cout << "5. Cari Buku Berdasarkan Range Judul\n";
//         cout << "6. Urutkan Buku Berdasarkan Judul\n";
//         cout << "7. Lihat Riwayat\n";
//         cout << "8. Exit\n";
//         cout << "Masukkan Pilihan: ";
//         cin >> pilih;

//         switch (pilih) {
//             case 1: {
//                 Buku bukuBaru;
//                 cout << "Masukkan Judul: ";
//                 cin.ignore();
//                 getline(cin, bukuBaru.judul);
//                 cout << "Masukkan Penulis: ";
//                 getline(cin, bukuBaru.penulis);
//                 cout << "Masukkan Kode Referensi: ";
//                 cin >> bukuBaru.kodeReferensi;
//                 TambahBukuKeHash(bukuBaru);
//                 if(suksesInputhash)
//                     TambahBukuPTB(bukuBaru);
//                 break;
//             }
//             case 2: {
//                 int refNumber;
//                 if(CekKosongHash()){
//                     cout << "\nTidak Ada Buku Untuk Dihapus!\n";
//                     break;
//                 }
//                 cout << "Masukkan Kode Referensi Untuk Dihapus: ";
//                 cin >> refNumber;
//                 HapusDariHash(refNumber);
//                 HapusDariPTB(refNumber);
//                 break;
//             }
//             case 3: {
//                 if(CekKosongHash()){
//                     cout << "\nTidak Ada Buku Untuk Ditampilkan!\n";
//                     break;
//                 }
//                 TampilBukuHash();
//                 break;
//             }
//             case 4: {
//                 int refNumber;
//                  if(CekKosongHash()){
//                     cout << "\nTidak Ada Buku Untuk Dicari!\n";
//                     break;
//                 }
//                 cout << "Masukkan Kode Referensi Untuk Dicari: ";
//                 cin >> refNumber;
//                 HashNode* result = CariBukuHash(refNumber);
//                 if (result != nullptr) {
//                     cout << "\nBuku Ditemukan!\n";
//                     cout << "Judul : " << result->buku.judul << "\n";
//                     cout << "Penulis : " << result->buku.penulis << "\n";
//                     cout << "Kode Referensi : " << result->buku.kodeReferensi << "\n";
//                 } else {
//                     cout << "\nBuku Tidak Ditemukan!\n";
//                 }
//                 break;
//             }
//             case 5: {
//                 string startTitle, endTitle;
//                 if(root == nullptr){
//                     cout << "\nTidak Ada Buku Untuk Dicari!\n";
//                     break;
//                 }
//                 cout << "Masukkan Inisial Judul Awal: ";
//                 cin.ignore();
//                 getline(cin, startTitle);
//                 cout << "Masukkan Inisial Judul Akhir: ";
//                 getline(cin, endTitle); 
//                 cout << endl;
//                 BinaryTree* current = root;
//                 while (current != nullptr) {
//                     if (current->buku.judul >= startTitle && current->buku.judul <= endTitle) {
//                         cout << "Judul : " << current->buku.judul << "\n";
//                         cout << "Penulis : " << current->buku.penulis << "\n";
//                         cout << "Kode Referensi : " << current->buku.kodeReferensi << "\n";
//                         cout << "-------------------------\n";
//                     }
//                     current = current->right;
//                 }
//                 break;
//             }
//             case 6: {
//                 if(root == nullptr){
//                     cout << "\nTidak Ada Buku Untuk Diurutkan!\n";
//                     break;
//                 }
//                 cout << "\nUrutan Buku Berdasarkan Judul (In-Order Traversal):\n";
//                 inOrderTraversal(root);
//                 break;
//             }
//             case 7: {
//                 if(historyTree == nullptr){
//                     cout << "\nTidak Ada Buku Untuk Ditampilkan!\n";
//                     break;
//                 }
//                 cout << "\nRiwayat Hapus Buku (In-Order Traversal):\n";
//                 RiwayatInOrder(historyTree);
//                 cout << "\nRiwayat Hapus Buku (Post-Order Traversal):\n";
//                 RiwayatPostOrder(historyTree);
//                 cout << "\nRiwayat Hapus Buku (Pre-Order Traversal):\n";
//                 RiwayatPreOrder(historyTree);
//                 break;
//             }
//             case 8:
//                 cout << "Keluar...\n";
//                 break;
//             default:
//                 cout << "Invalid. Coba Lagi.\n";
//                 getch();
//                 break;
            
//         }
//             cout << "Press anything to back to main menu.";
//             getch();
//     } while (pilih != 8);

//     return 0;
// }

// int hashFunction(int kodeReferensi) {
//     return kodeReferensi % 1000;
// }

// void TambahBukuKeHash(const Buku& buku) {
//     int index = hashFunction(buku.kodeReferensi);
//     HashNode* newNode = new HashNode{buku, nullptr};

//     if (hashTable[index] == nullptr) {
//         hashTable[index] = newNode;
//         suksesInputhash = true;
//         cout <<   "\nBuku dengan judul : " << newNode->buku.judul <<" berhasil ditambahkan!\n";
//     } else {
//         HashNode* current = hashTable[index];
//         while (current->next != nullptr) {
//             current = current->next;
//         }
//         if(current->buku.kodeReferensi == buku.kodeReferensi){
//             cout << "\nKode Referensi Sudah Digunakan!\n";
//             return;
//         }
//         else{
//             suksesInputhash = true;
//             current->next = newNode;
//             cout <<   "\nBuku dengan judul : " << current->buku.judul <<" berhasil ditambahkan!\n";
//         }
//     }
// }

// void HapusDariHash(int kodeReferensi) {
//     int index = hashFunction(kodeReferensi);
//     HashNode* current = hashTable[index];
//     HashNode* prev = nullptr;

//     while (current != nullptr && current->buku.kodeReferensi != kodeReferensi) {
//         prev = current;
//         current = current->next;
//     }

//     if (current != nullptr) {
//         if (prev == nullptr) {
//             hashTable[index] = current->next;
//         } else {
//             prev->next = current->next;
//         }
//         cout << "\nBuku dengan judul : " << current->buku.judul <<" berhasil dihapus!\n";
//         TambahBukuRiwayat(current->buku);
//         delete current;
//     }
//     else{
//         cout << "\nKode Referensi Tidak Ditemukan!\n";
//     }
// }
// void TampilBukuHash() {
//     cout << "\nBuku di Library (Hash Table):\n";
//     cout << "-------------------------\n";

//     for (int i = 0; i < 1000; ++i) {
//         HashNode* current = hashTable[i];
//         while (current != nullptr) {
//             cout << "Judul : " << current->buku.judul << "\n";
//             cout << "Penulis : " << current->buku.penulis << "\n";
//             cout << "Kode Referensi : " << current->buku.kodeReferensi << "\n";
//             cout << "-------------------------\n";
//             current = current->next;
//         }
//     }
// }

// HashNode* CariBukuHash(int kodeReferensi) {
//     int index = hashFunction(kodeReferensi);
//     HashNode* current = hashTable[index];

//     while (current != nullptr && current->buku.kodeReferensi != kodeReferensi) {
//         current = current->next;
//     }

//     return current;
// }

// void TambahBukuPTB(const Buku& buku) {
//     BinaryTree* newNode = new BinaryTree{buku, nullptr, nullptr};
//     if (root == nullptr) {
//         root = newNode;
//     } else {
//         BinaryTree* current = root; //p
//         BinaryTree* parent = root; //b
//         while (current != nullptr) {
//             parent = current;
//             if (buku.judul < current->buku.judul) {
//                 current = current->left;
//             } else {
//                 current = current->right;
//             }
//         }
//         if (buku.judul < parent->buku.judul) {
//             parent->left = newNode;
//         } else {
//             parent->right = newNode;
//         }
//     }
// }

// void inOrderTraversal(BinaryTree* node) {
//     if (node != nullptr) {
//         inOrderTraversal(node->left);
//         cout << "Judul : " << node->buku.judul << "\n";
//         cout << "Penulis : " << node->buku.penulis << "\n";
//         cout << "Kode Referensi : " << node->buku.kodeReferensi << "\n";
//         cout << "-------------------------\n";
//         inOrderTraversal(node->right);
//     }
// }
// void HapusDariPTB(const int& kodeReferensi) {
//     BinaryTree* current = root;
//     BinaryTree* parent = nullptr;
//     while (current != nullptr && current->buku.kodeReferensi != kodeReferensi) {
//         parent = current;
//         if (kodeReferensi < current->buku.kodeReferensi) {
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//     }

//     if (current != nullptr) {
//         if (current->left == nullptr && current->right == nullptr) {
//             // Case 1: No child
//             if (parent == nullptr) {
//                 root = nullptr;
//             } else if (parent->left == current) {
//                 parent->left = nullptr;
//             } else {
//                 parent->right = nullptr;
//             }
//             delete current;
//         } else if (current->left != nullptr && current->right == nullptr) {
//             // Case 2: One child (left)
//             if (parent == nullptr) {
//                 root = current->left;
//             } else if (parent->left == current) {
//                 parent->left = current->left;
//             } else {
//                 parent->right = current->left;
//             }
//             delete current;
//         } else if (current->left == nullptr && current->right != nullptr) {
//             // Case 2: One child (right)
//             if (parent == nullptr) {
//                 root = current->right;
//             } else if (parent->left == current) {
//                 parent->left = current->right;
//             } else {
//                 parent->right = current->right;
//             }
//             delete current;
//         } else {
//             // Case 3: Two children
//             BinaryTree* successor = current->right;
//             while (successor->left != nullptr) {
//                 successor = successor->left;
//             }
//             current->buku = successor->buku;
//             HapusDariPTB(successor->buku.kodeReferensi);
//         }
//     }
// }

// void TambahBukuRiwayat(const Buku& buku) {
//     HistoryNode* newNode = new HistoryNode{buku, nullptr, nullptr};
//     if (historyTree == nullptr) {
//         historyTree = newNode;
//     } else {
//         HistoryNode* current = historyTree;
//         HistoryNode* parent = nullptr;
//         while (current != nullptr) {
//             parent = current;
//             if (buku.judul < current->buku.judul) {
//                 current = current->left;
//             } else {
//                 current = current->right;
//             }
//         }
//         if (buku.judul < parent->buku.judul) {
//             parent->left = newNode;
//         } else {
//             parent->right = newNode;
//         }
//     }
// }

// void RiwayatInOrder(HistoryNode* node) {
//     if (node != nullptr) {
//         RiwayatInOrder(node->left);
//         cout << "Judul : " << node->buku.judul << "\n";
//         cout << "Penulis : " << node->buku.penulis << "\n";
//         cout << "Kode Referensi : " << node->buku.kodeReferensi << "\n";
//         cout << "-------------------------\n";
//         RiwayatInOrder(node->right);
//     }
// }

// void RiwayatPostOrder(HistoryNode* node) {
//     if (node != nullptr) {
//         RiwayatPostOrder(node->left);
//         RiwayatPostOrder(node->right);
//         cout << "Judul : " << node->buku.judul << "\n";
//         cout << "Penulis : " << node->buku.penulis << "\n";
//         cout << "Kode Referensi : " << node->buku.kodeReferensi << "\n";
//         cout << "-------------------------\n";
//     }
// }

// void RiwayatPreOrder(HistoryNode* node) {
//     if (node != nullptr) {
//         cout << "Judul : " << node->buku.judul << "\n";
//         cout << "Penulis : " << node->buku.penulis << "\n";
//         cout << "Kode Referensi: " << node->buku.kodeReferensi << "\n";
//         cout << "-------------------------\n";
//         RiwayatPostOrder(node->left);
//         RiwayatPostOrder(node->right);
//     }
// }

// bool CekKosongHash(){
//     for (int i = 0; i < 1000; ++i) {
//         HashNode* current = hashTable[i];
//         while (current != nullptr) {
//             return false;
//         }
//     }
//     return true;
// }