#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct menu {
    int id;
    string nama;
    string kategori;
    int harga;
};

struct transaksi {
    string nama_pelanggan;
    string nama_menu;
    int jumlah;
    int total_harga;
};

vector<menu> daftar_menu = {
    {1, "Nasi Goreng", "Makanan", 15000},
    {2, "Mie Goreng", "Makanan", 12000},
    {3, "Bakso", "Makanan", 10000},
    {4, "Es Teh", "Minuman", 5000},
    {5, "Es Jeruk", "Minuman", 6000},
    {6, "Kopi", "Minuman", 7000},
    {7, "Jus Mangga", "Minuman", 8000},
    {8, "Sate Ayam", "Makanan", 20000},
    {9, "Soto Ayam", "Makanan", 18000},
    {10, "Rawon", "Makanan", 17000}
};

vector<transaksi> riwayat_penjualan;

void display_menu() {
    cout << "ID Menu\tNama Menu\tKategori\tHarga" << endl;
    for (auto m : daftar_menu) {
        cout << m.id << "\t\t" << m.nama << "\t\t" << m.kategori << "\t\t" << m.harga << endl;
    }
}

void display_riwayat_penjualan() {
    if (riwayat_penjualan.empty()) {
        cout << "Tidak Ada Penjualan" << endl;
        return;
    }
    cout << "Nama Pelanggan\tNama Menu\tJumlah\tTotal Harga" << endl;
    for (auto t : riwayat_penjualan) {
        cout << t.nama_pelanggan << "\t\t" << t.nama_menu << "\t\t" << t.jumlah << "\t\t" << t.total_harga << endl;
    }
}

int main() {
    bool is_open = true;
    while (is_open) {
        cout << "Pemilik Toko" << endl;
        cout << "1. Buka Toko" << endl;
        cout << "2. Tutup Toko" << endl;
        cout << "Masukkan pilihan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
                display_menu();
            } else if (pilihan == 2) {
                int id_menu, jumlah;
                cout << "Masukkan ID menu: ";
                cin >> id_menu;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                for (auto &m : daftar_menu) {
                    if (m.id == id_menu) {
                        transaksi t;
                        t.nama_pelanggan = nama_pelanggan;
                        t.nama_menu = m.nama;
                        t.jumlah = jumlah;
                        t.total_harga = jumlah * m.harga;
                        riwayat_penjualan.push_back(t);
                    }
                }
            } else {
                break;
            }
        }
    } else if (pilihan == 2) {
        display_riwayat_penjualan();
        is_open = false;
    }
}
return 0;