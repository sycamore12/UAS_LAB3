#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Pengeluaran
{
    string kategori;
    double jumlah;
    string tanggal;
};

vector<Pengeluaran> pengeluaran;
double anggaran = 0.0; //utk mengatur anggaran bulanan

void tambahPengeluaran()
{
    Pengeluaran pengeluaranBaru;
    cout<<"Masukkan kategori: ";
    cin>>pengeluaranBaru.kategori;
    cout<<"Masukkan jumlah: ";
    cin>>pengeluaranBaru.jumlah;
    cout<<"Masukkan tanggal (DD-MM-YY): ";
    cin>>pengeluaranBaru.tanggal;

    pengeluaran.push_back(pengeluaranBaru);
}

void lihatPengeluaran()
{
    cout << "Daftar Pengeluaran" << endl;
    cout << "--------------------------------" << endl;
    cout << setw(15) << left << "Kategori"
         << setw(10) << "Jumlah"
         << " Tanggal" << endl;
    cout << "--------------------------------" << endl;

    for (const Pengeluaran &p : pengeluaran)
    {
        cout << setw(15) << left << p.kategori
             << setw(10) << fixed << setprecision(2)
             << p.jumlah << " " << p.tanggal << endl;
    }

    //menghitung dan menampilkan total pengeluaran vs anggaran
    double total = 0.0;
    for (const Pengeluaran &p : pengeluaran)
    {
        total += p.jumlah;
    }

    cout << "---------------------------------" << endl;
    cout << "Total Dikeluarkan: " << setw(10) << total;

    if (anggaran > 0)
    {
        cout << " Sisa: " << setw(10) << max(0.0, anggaran - total);
    }
}

int main()
    {
        int pilihan;
        do 
        {
            cout << "\nTrack pengeluaranmu!\n";
            cout << "1. Tambah Pengeluaran" << endl;
            cout << "2. Lihat Pengeluaran" << endl;
            cout << "3. Keluar" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilihan;

            switch (pilihan)
            {
                case 1: tambahPengeluaran(); break;
                case 2: lihatPengeluaran(); break;
                case 3: cout << "Keluar..." << endl; break;
                default: cout << "Pilihan tidak valid\n";
            }
        } 
        while (pilihan != 3);
}