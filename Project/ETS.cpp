/*
-    Kelas   : Struktur Data (G)
-    Nama    : Moch. Avin
-    NRP     : 5025221061
-    Program : Gudang barang
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Barang {
    int jumlah;
    string tanggal;
};
vector<int> stokBarang(17);
queue <Barang> barang[17];

void greeting();
string perintahInput();
void barangMasuk();
void barangKeluar();
void printBarang();
void kosongkanBarang();
void printNotValid(string);

int main() {
    greeting();
    while(true) {
        printf("\n");
        string inp = perintahInput();
        if(inp == "1") {
            barangMasuk();
        }else if(inp == "2") {
            barangKeluar();
        }else if(inp == "3") {
            printBarang();
        }else if(inp == "9") {
            kosongkanBarang();
            return 0;
        }else {
            printNotValid(inp);
        }
    }
}

void greeting() {
    printf("\n\"Program ini untuk penyimpanan gudang\"\n");
    return;
}

string perintahInput() {
    printf("---------------------------------------------\n");
    printf("1. Masukkan barang \t 3. Lihat stok barang\n");
    printf("2. Keluarkan barang \t 9. Keluar program\n");
    printf("Pilih perintah : ");
    string inp; 
    getline(cin, inp);
    printf("---------------------------------------------\n\n");
    return inp;
}

void barangMasuk() {
    printf("Memasukkan barang \n");
    Barang tmp;
    int jenis, jumlah;
    string tanggal;
    printf("Jenis barang (1 - 17) \t: ");
    cin >> jenis; cin.ignore();
    while(jenis < 1 or jenis > 17) {
        printf("Masukkan angka 1 - 17\t: ");
        cin >> jenis; cin.ignore();
    }
    jenis--;
    printf("Jumlah barang masuk \t: ");
    cin >> jumlah; cin.ignore();
    printf("Tanggal masuk \t\t: ");
    getline(cin, tanggal);
    tmp.jumlah = jumlah;
    tmp.tanggal = tanggal;
    barang[jenis].push(tmp);
    stokBarang[jenis] += jumlah;
    return;
}

void barangKeluar() {
    printf("Keluarkan barang\n");
    int jenis, jumlah;
    printf("Jenis barang (1 - 17) \t: ");
    cin >> jenis; cin.ignore();
    while(jenis < 1 or jenis > 17) {
        printf("Masukkan angka 1 - 17\t: ");
        cin >> jenis; cin.ignore();
    }
    jenis--;
    if(stokBarang[jenis] == 0) {
        printf("Stok barang habis\n");
        return;
    }
    printf("Jumlah barang keluar \t: ");
    cin >> jumlah; cin.ignore();
    while(jumlah < 0) {
        printf("Masukkan bilangan positif :");
        cin >> jumlah; cin.ignore();
    }
    while(jumlah > stokBarang[jenis]) {
        printf("Stok barang %d tersisa %d\n", jenis+1, stokBarang[jenis]);
        printf("Jumlah barang keluar \t: ");
        cin >> jumlah; cin.ignore();
    }
    stokBarang[jenis] -= jumlah;
    while(jumlah > barang[jenis].front().jumlah) {
        printf("Barang tanggal %s keluar semuanya\n", barang[jenis].front().tanggal.c_str());
        jumlah -= barang[jenis].front().jumlah;
        barang[jenis].pop();
    }
    if(jumlah > 0) {
        printf("Barang tanggal %s keluar sebanyak %d \n", barang[jenis].front().tanggal.c_str(), jumlah);
        barang[jenis].front().jumlah -= jumlah;
        jumlah = 0;
    }
    return;
}

void printBarang() {
    printf("Stok barang saat ini \n");
    for(int i = 0; i < 17; i++) {
        printf("Barang %d\t: %d\n", i+1, stokBarang[i]);
    }
    return;
}

void printNotValid(string inp) {
    printf("\"%s\" merupakan input tidak valid\n", inp.c_str());
    return;
}

void kosongkanBarang() {
    for(int i = 0; i < 17; i++) {
        while(!barang[i].empty()) barang[i].pop();
    }
    printf("Semua data berhasil dihapus \n\n");
    return;
}