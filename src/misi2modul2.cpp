#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk menyimpan informasi menu
struct Menu 
{
    int id;
    string nama;
    string kategori;
    int harga;
};

// Struktur data untuk menyimpan informasi penjualan
struct Penjualan 
{
    string namaPelanggan;
    string namaMenu;
    int jumlah;
    int totalHarga;
};

// Fungsi untuk menampilkan daftar menu
void tampilkanMenu(vector<Menu> menuList) 
{
    cout << "Daftar Menu" << endl;
    cout << "-----------" << endl;
    for (int i = 0; i < menuList.size(); i++) 
    {
        cout << menuList[i].id << ". " << menuList[i].nama << " (" << menuList[i].kategori << ") - Rp" << menuList[i].harga << endl;
    }
    cout << endl;
}

// Fungsi untuk mencari menu berdasarkan nama atau ID
Menu cariMenu(vector<Menu> menuList, string keyword) 
{
    for (int i = 0; i < menuList.size(); i++) 
    {
        if (menuList[i].nama == keyword || to_string(menuList[i].id) == keyword) 
        {
            return menuList[i];
        }
    }
    return { -1, "", "", -1 };
}

int main() 
{   // Inisialisasi data menu
    vector<Menu> menuList = 
    {
        { 1, "Landak Goreng", "Makanan", 15000 },
        { 2, "Mie Goreng", "Makanan", 12000 },
        { 3, "Ayam Goreng", "Makanan", 20000 },
        { 4, "Es Teh", "Minuman", 3000 },
        { 5, "Es Jeruk", "Minuman", 5000 },
        { 6, "Kopi", "Minuman", 7000 },
        { 7, "Bakso", "Makanan", 10000 },
        { 8, "Sate Ayam", "Makanan", 15000 },
        { 9, "Soto Ayam", "Makanan", 12000 },
        { 10, "Jus Alpukat", "Minuman", 10000 }
    };

    // Inisialisasi data penjualan
    vector<Penjualan> penjualanList;

    // Program utama
    bool isClosed = false;
    while (!isClosed) 
    {
        // Meminta input dari pemilik toko
        cout << "Selamat datang!" << endl;
        cout << "1. Tutup toko" << endl;
        cout << "2. Pelanggan masuk" << endl;
        cout << "Pilihan: ";
        int pilihanPemilik;
        cin >> pilihanPemilik;

        if (pilihanPemilik == 1) 
        {
            // Menampilkan riwayat penjualan jika ada
            if (penjualanList.size() > 0) 
            {
                cout << "Riwayat Penjualan" << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < penjualanList.size(); i++) 
                {
                    cout << penjualanList[i].namaPelanggan << " membeli " << penjualanList[i].namaMenu << " sebanyak " << penjualanList[i].jumlah << " dengan total harga Rp" << penjualanList[i].totalHarga << endl;
                }
            } 
            else 
            {
                cout << "Tidak ada penjualan" << endl;
            }
            isClosed = true;
        } 
        else if (pilihanPemilik == 2) 
        {
            // Meminta input dari pelanggan
            string namaPelanggan;
            cout << "Nama pelanggan: ";
            cin >> namaPelanggan;

            bool isSelesai = false;
            while (!isSelesai) 
            {
                // Menampilkan menu pilihan untuk pelanggan
                cout << endl;
                cout << "Halo, " << namaPelanggan << endl;
                cout << "1. Lihat daftar menu" << endl;
                cout << "2. Beli makanan/minuman" << endl;
                cout << "3. Keluar dari warung" << endl;
                cout << "Pilihan: ";
                int pilihanPelanggan;
                cin >> pilihanPelanggan;

                if (pilihanPelanggan == 1) 
                {
                    // Menampilkan daftar menu
                    cout << endl;
                    tampilkanMenu(menuList);
                } 
                else if (pilihanPelanggan == 2) 
                {
                    // Meminta input untuk membeli makanan/minuman
                    string keyword;
                    int jumlah;
                    cout << "Masukkan nama atau ID menu: ";
                    cin >> keyword;
                    cout << "Jumlah: ";
                    cin >> jumlah;

                    // Mencari menu yang ingin dibeli
                    Menu menuDibeli = cariMenu(menuList, keyword);

                    if (menuDibeli.id == -1) 
                    {
                        cout << "Menu tidak ditemukan" << endl;
                    } 
                    else 
                    {
                        // Menambahkan data penjualan
                        int totalHarga = menuDibeli.harga * jumlah;
                        Penjualan penjualan = { namaPelanggan, menuDibeli.nama, jumlah, totalHarga };
                        penjualanList.push_back(penjualan);
                        cout << "Anda telah membeli " << jumlah << " " << menuDibeli.nama << " dengan total harga Rp" << totalHarga << endl;
                    }
                } 
                else if (pilihanPelanggan == 3) 
                {
                    // Keluar dari warung
                    isSelesai = true;
                } 
                else 
                {
                    cout << "Pilihan tidak valid" << endl;
                }
            }
        } 
        else 
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }
return 0;
}