

#include <iostream>
#include <limits>
#include <vector>
#include "tubes.hpp"

using namespace std;

int main() {
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "| SELAMAT DATANG DI ARSITEKTUR RELASI PRAMUGARI DAN PENUMPANG |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << endl;

    list_pramugari LP;// Perbaiki tipe data menjadi list_pramugari
    createListPramugari(LP);  // Panggil fungsi untuk membuat list pramugari

    int input = -1;

    while (true) {
        cout << "+-------------------------------------------------+" << endl;
        cout << "|                MENU UTAMA                       |" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "| 1.  Tambahkan Pramugari                         |" << endl;
        cout << "| 2.  Tampilkan semua Pramugari                   |" << endl;
        cout << "| 3.  Hapus Pramugari                             |" << endl;
        cout << "| 4.  Mencari Pramugari                           |" << endl;
        cout << "| 5.  Edit Pramugari                              |" << endl;
        cout << "| 6.  Tambahkan Penumpang                          |" << endl;
        cout << "| 7.  Mencari Penumpang                            |" << endl;
        cout << "| 8.  Edit Penumpang                               |" << endl;
        cout << "| 9.  Hubungkan Pramugari dengan Penumpang         |" << endl;
        cout << "| 10. Tampilkan semua Pramugari beserta Penumpangnya|" << endl;
        cout << "| 11. Pramugari yang paling banyak melayani Penumpang|" << endl;
        cout << "| 12. Cari Penumpang di Pramugari                  |" << endl;
        cout << "| 13. Hapus Penumpang di Pramugari                 |" << endl;
        cout << "| 0.  Keluar                                       |" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "Masukkan Pilihan Menu: ";
        cin >> input;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka 0-13." << endl;
            continue;
        }

        if (input < 0 || input > 13) {
            cout << "Pilihan tidak valid, masukkan 0-13." << endl;
            continue;
        }

        cout << endl;

        if (input == 0) break;

        switch (input) {
            case 1: {
                cout << "+-----------------------------+" << endl;
                cout << "|     Tambahkan Pramugari     |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleAddPramugari(LP) << endl;
                break;
            }
            case 2:
                cout << "+-----------------------------+" << endl;
                cout << "|  Tampilkan semua Pramugari  |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << showAllPramugari(LP) << endl;
                break;
            case 3: {
                cout << "+-----------------------------+" << endl;
                cout << "|     Hapus Pramugari         |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleDeletePramugari(LP) << endl;
                break;
            }
            case 4: {
                cout << "+-----------------------------+" << endl;
                cout << "|     Mencari Pramugari       |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleSearchPramugari(LP) << endl;
                break;
            }
            case 5: {
                cout << "+-----------------------------+" << endl;
                cout << "|      Edit Pramugari         |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleEditPramugari(LP) << endl;
                break;
            }
            case 6: {
                cout << "+-----------------------------+" << endl;
                cout << "|    Tambahkan Penumpang      |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleAddPenumpang(LP) << endl;
                break;
            }
            case 7: {
                cout << "+-----------------------------+" << endl;
                cout << "|    Mencari Penumpang        |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleSearchPenumpang(LP) << endl;
                break;
            }
            case 8: {
                cout << "+-----------------------------+" << endl;
                cout << "|      Edit Penumpang         |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleEditPenumpang(LP) << endl;
                break;
            }
            case 9: {
                cout << "+-----------------------------+" << endl;
                cout << "| Hubungkan Pramugari & Penumpang |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleConnect(LP) << endl;
                break;
            }
            case 10:
                cout << "+-----------------------------+" << endl;
                cout << "| Tampilkan Semua Data        |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << showAllPramugariWithPenumpang(LP) << endl;
                break;
            case 11:
                cout << "+-----------------------------+" << endl;
                cout << "| Pramugari Terbanyak         |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << displayPramugariWithMostPenumpang(LP) << endl;
                break;
            case 12: {
                cout << "+-----------------------------+" << endl;
                cout << "| Cari Penumpang di Pramugari |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleFindPenumpangInPramugari(LP) << endl;
                break;
            }
            case 13: {
                cout << "+-----------------------------+" << endl;
                cout << "| Hapus Penumpang di Pramugari|" << endl;
                cout << "+-----------------------------+" << endl;
                cout << handleDeletePenumpangFromPramugari(LP) << endl;
                break;
            }
            default:
                cout << "+-----------------------------+" << endl;
                cout << "|    Pilihan Tidak Valid      |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << "Tolong masukkan pilihan yang sesuai." << endl;
                break;
        }
    }

    cout << "+-------------------------------------------------+" << endl;
    cout << "|              TERIMA KASIH                       |" << endl;
    cout << "|         Telah Menggunakan Sistem Ini            |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    return 0;
}
