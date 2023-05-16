/*
    Nama    : Moch. Avin
    NRP     : 5025221061
    Kelas   : Struktur Data G
*/


#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct {
    string nama;
    int usia;
    string alamat;
    string keluhan;
} Pasien;

int main() {
    queue<Pasien> antrian;

    // program berjalan terus
    while(true) {
        string in; 
        cout << "1. Tambah pasien\t";
        cout << "3. Tampilkan antrian" << endl;
        cout << "2. Panggil pasien\t";
        cout << "9. Keluar" << endl;
        cin >> in;
        // menghapus layar
        system("cls");
        cin.ignore();
        if(in == "1") { // Tambah pasien baru
            Pasien pasien;
            cout << "Nama : ";
            getline(cin, pasien.nama);
            cout << "Usia : ";
            cin >> pasien.usia;
            cin.ignore();
            cout << "Alamat : ";
            getline(cin, pasien.alamat);
            cout << "Keluhan : ";
            getline(cin, pasien.keluhan);
            cout << "Pasien telah ditambahkan" << endl;
            antrian.push(pasien);

        } else if(in == "2") {  // Pasien masuk ke dokter
            if(antrian.empty()) {
                cout << "Antrian kosong" << endl;
            } else {
                Pasien pasien = antrian.front();
                antrian.pop();
                system("cls");
                cout << "Pasien yang masuk ke dokter" << endl;
                cout << "Nama\t: "  << pasien.nama << endl;
                cout << "Usia\t: " << pasien.usia << endl;
                cout << "Alamat\t: " << pasien.alamat << endl;
                cout << "Keluhan\t: " << pasien.keluhan << endl;
            }
        } else if(in == "3") {  // Tampilkan semua data pasien dalam antrian
            system("cls");
            if(antrian.empty()) {
                cout << "Antrian kosong" << endl;
            } else {
                queue<Pasien> antrian2 = antrian;
                int it = 1;
                cout << "-----------------------------" << endl;
                while(!antrian2.empty()) {
                    cout << "Pasien ke-" << it << endl; 
                    Pasien pasien = antrian2.front();
                    antrian2.pop();
                    cout << "Nama\t: "  << pasien.nama << endl;
                    cout << "Usia\t: " << pasien.usia << endl;
                    cout << "Alamat\t: " << pasien.alamat << endl;
                    cout << "Keluhan\t: " << pasien.keluhan << endl;
                    it++;
                    cout << "-----------------------------" << endl;
                }
            }
        } else if(in == "9") {  // Keluar program
            while(!antrian.empty()) {
                antrian.pop();
            }
            cout << "Antrian telah dikosongkan" << endl;
            return 0;
        } else {
            cout << "Input salah" << endl;
        }
        cout << endl;
    }
}