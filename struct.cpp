#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 10; // Maksimal 10 data mahasiswa

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(const Mahasiswa mhs[], int jumlahData) {
    cout << "Daftar Mahasiswa:" << endl;
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Data ke-" << (i + 1) << ":" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Umur: " << mhs[i].umur << " tahun" << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << endl;
    }
}

// Fungsi untuk menambahkan data mahasiswa
int tambahData(Mahasiswa mhs[], int jumlahData) {
    if (jumlahData < MAX_MAHASISWA) {
        cout << "Masukkan data mahasiswa baru:" << endl;
        cout << "Nama: ";
        cin >> mhs[jumlahData].nama;
        cout << "Umur: ";
        cin >> mhs[jumlahData].umur;
        cout << "IPK: ";
        cin >> mhs[jumlahData].ipk;
        cout << "Data mahasiswa telah ditambahkan." << endl;
        return jumlahData + 1; // Mengembalikan jumlahData yang telah diperbarui
    } else {
        cout << "Maaf, daftar mahasiswa sudah penuh." << endl;
        return jumlahData;
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan indeks
int hapusData(Mahasiswa mhs[], int jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        for (int i = indeks; i < jumlahData - 1; ++i) {
            mhs[i] = mhs[i + 1];
        }
        cout << "Data mahasiswa telah dihapus." << endl;
        return jumlahData - 1; // Mengembalikan jumlahData yang telah diperbarui
    } else {
        cout << "Indeks tidak valid." << endl;
        return jumlahData;
    }
}

// Fungsi untuk mengubah data mahasiswa berdasarkan indeks
void ubahData(Mahasiswa mhs[], int jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        cout << "Masukkan data mahasiswa yang baru:" << endl;
        cout << "Nama: ";
        cin >> mhs[indeks].nama;
        cout << "Umur: ";
        cin >> mhs[indeks].umur;
        cout << "IPK: ";
        cin >> mhs[indeks].ipk;
        cout << "Data mahasiswa telah diubah." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

int main() {
    Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
    int jumlahData = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarMahasiswa, jumlahData);
                break;
            case 2:
                jumlahData = tambahData(daftarMahasiswa, jumlahData);
                break;
            case 3:
                if (jumlahData > 0) {
                    cout << "Masukkan indeks data yang akan dihapus (0-" << (jumlahData - 1) << "): ";
                    int indeksHapus;
                    cin >> indeksHapus;
                    jumlahData = hapusData(daftarMahasiswa, jumlahData, indeksHapus);
                } else {
                    cout << "Tidak ada data mahasiswa yang bisa dihapus." << endl;
                }
                break;
            case 4:
                if (jumlahData > 0) {
                    cout << "Masukkan indeks data yang akan diubah (0-" << (jumlahData - 1) << "): ";
                    int indeksUbah;
                    cin >> indeksUbah;
                    ubahData(daftarMahasiswa, jumlahData, indeksUbah);
                } else {
                    cout << "Tidak ada data mahasiswa yang bisa diubah." << endl;
                }
                break;
            case 5:
                cout << "Terima kasih! Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan menu tidak valid." << endl;
                break;
        }
    }

    return 0;
}
