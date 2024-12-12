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

struct BSTNode {
    Produk produk;
    BSTNode *left;
    BSTNode *right;
};

node *hashTable[TABLE_SIZE] = { NULL };
node *nb, *db, *bantu;
//  nodebaru, databaru, bantu
BSTNode *root = NULL;
BSTNode *rootHapus = NULL;

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
int hashKey(string kode) ; // Hashing

bool isEmptyBST();
bool isEmptyBSTHistory();   // Binary Search Tree

void postOrder(BSTNode* root);
void preOrder(BSTNode* root);
void inOrder(BSTNode* root);

void insertBST(BSTNode*& root, Produk produk);
void inOrderRange(BSTNode* root, string nama1, string nama2);
void postOrderDescending(BSTNode* root);
void deleteBST(BSTNode*& root, string kode) ;
BSTNode* findMin(BSTNode* root) ;

void errorH();

int main(){
    char yn;

    cout << "===================================" << endl;
    cout << "        Menu Toko Serba Ada" << endl;
    cout << "===================================" << endl;
    getch();
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
            while (bantu->next != NULL) {
                bantu = bantu->next;
            }
            bantu->next = nb;
        }
        //  Menambahkan produk ke dalam BST
        insertBST(root, nb->produk);
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

bool isEmptyBST() {
    return root == NULL;    // True kalau root == null
}

bool isEmptyBSTHistory() {  
    return rootHapus == NULL;   // True kalau roothapus == null
}


void insertBST(BSTNode*& root, Produk produk) {
    if (root == NULL) {
        root = new BSTNode{ produk, NULL, NULL };   //  Jika Pertamakali Insert
    } else if (produk.nama < root->produk.nama) {
        insertBST(root->left, produk);  //  Insert Left
    } else {
        insertBST(root->right, produk); //  Insert Right
    }
}

void inOrderRange(BSTNode* root, string nama1, string nama2) {
    if (root == NULL) {
        return;
    }

    if (nama1 < root->produk.nama) {
        inOrderRange(root->left, nama1, nama2);
    }

    if (root->produk.nama >= nama1 && root->produk.nama <= nama2) {
        cout << "Nama: " << root->produk.nama << ", Harga: Rp." << root->produk.harga << ", Kode: " << root->produk.kode << endl;
    }

    if (nama2 > root->produk.nama) {
        inOrderRange(root->right, nama1, nama2);
    }
}

void postOrderDescending(BSTNode* root) {
    if (root == NULL) {
        return;
    }

    postOrderDescending(root->right);  // Traversal kanan terlebih dahulu untuk urutan descending
    cout << "Nama: " << root->produk.nama << ", Harga: Rp." << root->produk.harga << ", Kode: " << root->produk.kode << endl;
    postOrderDescending(root->left);
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
        //  Jika Terdapat Indeks dengan Data Kosong
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
        //  Memasukkan Node yang ingin dihapus untuk History
        insertBST(rootHapus, bantu->produk);
        delete bantu;
        cout << "Produk dengan kode " << ckode << " berhasil dihapus!" << endl;
    }

    // Hapus dari BST
    deleteBST(root, ckode);
}

void deleteBST(BSTNode*& root, string kode) {
    if (root == NULL) return;

    if (kode < root->produk.kode) {
        deleteBST(root->left, kode);
    } else if (kode > root->produk.kode) {
        deleteBST(root->right, kode);
    } else {
        // Jika node yang ingin dihapus ditemukan
        if (root->left == NULL && root->right == NULL) {
            // Jika node yang ingin dihapus tidak memiliki anak
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            // Jika node yang ingin dihapus hanya memiliki anak kanan
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            // Jika node yang ingin dihapus hanya memiliki anak kiri
            BSTNode* temp = root;
            root = root->left;
            delete temp;
        } else {
            // Jika node yang ingin dihapus memiliki anak kiri dan kanan
            BSTNode* temp = findMin(root->right);
            root->produk = temp->produk;
            deleteBST(root->right, temp->produk.kode);
        }
    }
}

BSTNode* findMin(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
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
    while (bantu != NULL) {
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
    string cnama1, cnama2 ;
    cout << "===========================================================" << endl ;
    cout << "        Pencarian Range Nama Produk Menggunakan BST" << endl ;
    cout << "===========================================================" << endl ;

    if(isEmptyBST()){
        cout << "Binary Search Tree Masih Kosong!" << endl ;
        return ;
    }

    cin.ignore();
    cout << "Masukkan Nama Produk Awal: "; getline(cin, cnama1);
    cout << "Masukkan Nama Produk Akhir: "; getline(cin, cnama2);

    cout << endl;
    cout << "Produk dalam range " << cnama1 << " hingga " << cnama2 << ":" << endl;
    inOrderRange(root, cnama1, cnama2);
}

void menu6(){
    cout << "==============================================================================" << endl ;
    cout << "        Pengurutan Nama Produk (Descending) Menggunakan BST Post-Order" << endl ;
    cout << "==============================================================================" << endl ;

    if(isEmptyBST()){
        cout << "Binary Search Tree Masih Kosong!" << endl ;
        return ;
    }

    postOrderDescending(root);
}

void menu7(){
    int cinputan ;

    cout << "===============================" << endl ;
    cout << "        History Product" << endl ;
    cout << "===============================" << endl ;

    if(isEmptyBSTHistory()){
        cout << "Binary Search Tree Masih Kosong!" << endl ;
        return ;
    }
    
    cout << "[1] In-Order" << endl ;
    cout << "[2] Post-Order" << endl ;
    cout << "[3] Pre-Order" << endl ;
    cout << "[4] Kembali ke Menu Utama" << endl ;
    cout << "Masukkan Inputan[1-4] : "; cin >> cinputan;
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
    case 4:
        return ;
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
    inOrder(rootHapus);
}
void menu7sub2(){
    cout << "==========================" << endl ;
    cout << "        Post-Order" << endl ;
    cout << "==========================" << endl ;
    preOrder(rootHapus);
}
void menu7sub3(){
    cout << "=========================" << endl ;
    cout << "        Pre-Order" << endl ;
    cout << "=========================" << endl ;
    postOrder(rootHapus);
}

void inOrder(BSTNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << "Nama: " << root->produk.nama << ", Harga: Rp." << root->produk.harga << ", Kode: " << root->produk.kode << endl;
    inOrder(root->right);
}

void preOrder(BSTNode* root) {
    if (root == NULL) return;
    cout << "Nama: " << root->produk.nama << ", Harga: Rp." << root->produk.harga << ", Kode: " << root->produk.kode << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BSTNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << "Nama: " << root->produk.nama << ", Harga: Rp." << root->produk.harga << ", Kode: " << root->produk.kode << endl;
}