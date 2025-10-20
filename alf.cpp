#include <iostream>
#include <string>
using namespace std;
// Struktur node / simpul mahasiswa
struct Mahasiswa {
    int nim;
    string nama;
    float nilai;
    Mahasiswa* kiri;
    Mahasiswa* kanan;
};
// Fungsi untuk membuat node baru
Mahasiswa* buatSimpul(int nim, string nama, float nilai) {
    Mahasiswa* baru = new Mahasiswa();
    baru->nim = nim;
    baru->nama = nama;
    baru->nilai = nilai;
    baru->kiri = nullptr;
    baru->kanan = nullptr;
    return baru;
}
// 1️ Tambah data mahasiswa (insert)
Mahasiswa* tambahMahasiswa(Mahasiswa* akar, int nim, string nama, float nilai) {
    if (akar == nullptr) {
        return buatSimpul(nim, nama, nilai);
    }
    if (nim < akar->nim)
        akar->kiri = tambahMahasiswa(akar->kiri, nim, nama, nilai);
    else if (nim > akar->nim)
        akar->kanan = tambahMahasiswa(akar->kanan, nim, nama, nilai);
    else
        cout << "NIM sudah ada, data tidak ditambahkan.\n";
    return akar;
}
// 2️ Cari data mahasiswa berdasarkan NIM
Mahasiswa* cariMahasiswa(Mahasiswa* akar, int nim) {
    if (akar == nullptr || akar->nim == nim)
        return akar;
    if (nim < akar->nim)
        return cariMahasiswa(akar->kiri, nim);
    else
        return cariMahasiswa(akar->kanan, nim);
}
// 3️ Tampilkan semua data (inorder traversal)
void tampilkanData(Mahasiswa* akar) {
    if (akar != nullptr) {
        tampilkanData(akar->kiri);
        cout << "NIM   : " << akar->nim << endl;
        cout << "Nama  : " << akar->nama << endl;
        cout << "Nilai : " << akar->nilai << endl;
        cout << "---------------------------\n";
        tampilkanData(akar->kanan);
    }
}
//  Fungsi utama (menu interaktif)
int main() {
    Mahasiswa* akar = nullptr;
    int pilihan;
    int nim;
    string nama;
    float nilai;
    do {
        cout << "\n=== SISTEM DATA MAHASISWA (BST DASAR) ===\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Cari data mahasiswa\n";
        cout << "3. Tampilkan semua data (Inorder)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM   : ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan Nama  : ";
                getline(cin, nama);
                cout << "Masukkan Nilai : ";
                cin >> nilai;
                akar = tambahMahasiswa(akar, nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                {
                    Mahasiswa* m = cariMahasiswa(akar, nim);
                    if (m != nullptr) {
                        cout << "\nData ditemukan!\n";
                        cout << "NIM   : " << m->nim << endl;
                        cout << "Nama  : " << m->nama << endl;
                        cout << "Nilai : " << m->nilai << endl;
                    } else {
                        cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
                    }
                }
                break;
            case 3:
                cout << "\n=== Data Mahasiswa (Urut NIM) ===\n";
                tampilkanData(akar);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
    return 0;
}
