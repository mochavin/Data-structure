#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct {
    string nrp;
    string nama;
    string judul_buku;
    string tanggal_pinjam;
}DataBuku;

typedef struct {
    string nrp;
    string nama;
}KeyPeminjam;

int main() {
    stack<DataBuku> data;
    queue<KeyPeminjam> antrian;
    while(true) {
        printf("1. Pinjam Buku\t\t 3. Layani pengembalian\n");
        printf("2. Kembalikan buku\t 4. Tampilkan data peminjaman\n");
        printf("9. Keluar\n");
        printf("Pilihan: ");
        string pilihan;
        cin >> pilihan;
        cin.ignore();
        if(pilihan == "1") {
            DataBuku data_buku;
            printf("NRP\t\t: ");
            getline(cin, data_buku.nrp);
            printf("Nama\t\t: ");
            getline(cin, data_buku.nama);
            printf("Judul Buku\t: ");
            getline(cin, data_buku.judul_buku);
            printf("Tanggal Pinjam\t: ");
            getline(cin, data_buku.tanggal_pinjam);
            data.push(data_buku);
        } else if(pilihan == "2") {
            KeyPeminjam key_peminjam;
            printf("NRP\t: ");
            getline(cin, key_peminjam.nrp);
            printf("Nama\t: ");
            getline(cin, key_peminjam.nama);
            antrian.push(key_peminjam);
        } else if(pilihan == "3") {
            if(antrian.empty()) {
                printf("Tidak ada yang antri\n");
                continue;
            }
            KeyPeminjam depan = antrian.front();
            antrian.pop();
            stack<DataBuku> temp;
            while(!data.empty()) {
                DataBuku data_buku = data.top();
                temp.push(data_buku);
                if(data_buku.nrp == depan.nrp) {
                    cout << "--------------------------------" << endl;
                    cout << "Pengembalian buku :" << endl;
                    cout << "NRP\t\t: " << data_buku.nrp << endl;
                    cout << "Nama\t\t: " << data_buku.nama << endl;
                    cout << "Judul Buku\t: " << data_buku.judul_buku << endl;
                    cout << "Tanggal Pinjam\t: " << data_buku.tanggal_pinjam << endl;
                    cout << "--------------------------------" << endl;
                    data.pop();
                    while(!temp.empty()) {
                        data.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
                data.pop();
            }
            if(data.empty()) {
                printf("Data tidak ditemukan\n");
                while(!temp.empty()) {
                    data.push(temp.top());
                    temp.pop();
                }
            }
        } else if(pilihan == "4") {
            system("cls");
            if(data.empty()) {
                printf("Tidak ada data peminjaman\n");
            } else {
                stack<DataBuku> temp = data;
                printf("--------------------------------\n");
                while(!temp.empty()) {
                    DataBuku data_buku = temp.top();
                    printf("NRP: %s\n", data_buku.nrp.c_str());
                    printf("Nama: %s\n", data_buku.nama.c_str());
                    printf("Judul Buku: %s\n", data_buku.judul_buku.c_str());
                    printf("Tanggal Pinjam: %s\n", data_buku.tanggal_pinjam.c_str());
                    printf("--------------------------------\n");
                    temp.pop();
                }
            }
        } else if(pilihan == "9") {
            while(!data.empty()) {
                data.pop();
            }
            while(!antrian.empty()) {
                antrian.pop();
            }
            break;
        } else {
            printf("Pilihan tidak tersedia\n");
        }
    }

}