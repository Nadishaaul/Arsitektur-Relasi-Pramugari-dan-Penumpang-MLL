//
//  tubes.cpp
//  TUBES STRUKTUR DATA
//
//  Created by afr on 12/1/24.
//

#include "tubes.hpp"
#include <iomanip>
#include <limits>

// Fungsi untuk membuat list pramugari
void createListPramugari(list_pramugari &LP) {
    LP.first = NULL;
    LP.last = NULL;
}


// Fungsi untuk mengalokasikan pramugari
adr_pramugari alokasiPramugari(string nama, int id) {
    adr_pramugari newPramugari = new elmPramugari;
    infoPramugari(newPramugari).nama = nama;
    infoPramugari(newPramugari).id = id;
    infoPramugari(newPramugari).firstPenumpang = NULL;
    nextPramugari(newPramugari) = NULL;
    return newPramugari;
}

// Fungsi untuk menambahkan pramugari ke list
void insertPramugari(list_pramugari &LP, adr_pramugari newPramugari) {
    if (LP.first == NULL) {
        LP.first = newPramugari;
        LP.last = newPramugari; // Set last jika ini adalah pramugari pertama
    } else {
        nextPramugari(LP.last) = newPramugari; // Menghubungkan pramugari terakhir dengan yang baru
        LP.last = newPramugari; // Memperbarui last
    }
}



// Fungsi untuk mengalokasikan penumpang
adr_penumpang alokasiPenumpang(string nama, int id) {
    adr_penumpang newPenumpang = new elmPenumpang;
    infoPenumpang(newPenumpang).nama = nama;
    infoPenumpang(newPenumpang).id = id;
    nextPenumpang(newPenumpang) = NULL;
    return newPenumpang;
}

// Fungsi untuk menambahkan penumpang ke pramugari tertentu
void addPenumpangToPramugari(list_pramugari &LP, int idPramugari, adr_penumpang newPenumpang) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }
    if (P != NULL) {
        if (infoPramugari(P).firstPenumpang == NULL) {
            infoPramugari(P).firstPenumpang = newPenumpang; // Jika belum ada penumpang, set sebagai penumpang pertama
        } else {
            adr_penumpang Q = infoPramugari(P).firstPenumpang;
            while (nextPenumpang(Q) != NULL) {
                Q = nextPenumpang(Q); // Mencari penumpang terakhir
            }
            nextPenumpang(Q) = newPenumpang; // Menghubungkan penumpang terakhir dengan yang baru
        }
    } else {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua penumpang dari pramugari tertentu
void showPenumpangOfPramugari(list_pramugari LP, int idPramugari) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }
    if (P != NULL) {
        adr_penumpang Q = infoPramugari(P).firstPenumpang;
        if (Q == NULL) {
            cout << "Tidak ada penumpang untuk pramugari ini." << endl;
        } else {
            cout << "Penumpang untuk Pramugari " << infoPramugari(P).nama << ":" << endl;
            while (Q != NULL) {
                cout << "Nama Penumpang: " << infoPenumpang(Q).nama << ", ID: " << infoPenumpang(Q).id << endl;
                Q = nextPenumpang(Q);
            }
        }
    } else {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menghapus pramugari berdasarkan ID
void deletePramugariByID(list_pramugari &LP, int idPramugari) {
    adr_pramugari P = findPramugariByID(LP, idPramugari);
    if (P == NULL) {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
        return;
    }

    adr_pramugari prev = NULL;
    adr_pramugari temp = LP.first;
    while (temp != NULL && temp != P) {
        prev = temp;
        temp = nextPramugari(temp);
    }

    // Hapus semua penumpang di bawah pramugari ini
    adr_penumpang Q = infoPramugari(P).firstPenumpang;
    while (Q != NULL) {
        adr_penumpang temp = Q;
        Q = nextPenumpang(Q);
        delete temp;
    }

    if (prev == NULL) {
        LP.first = nextPramugari(P); // Menghapus pramugari pertama
        if (LP.first == NULL) LP.last = NULL;
    } else {
        nextPramugari(prev) = nextPramugari(P); // Menghapus pramugari di tengah atau akhir
        if (nextPramugari(P) == NULL) LP.last = prev;
    }

    delete P; // Menghapus memori
    cout << "Pramugari dengan ID " << idPramugari << " dan semua penumpangnya telah dihapus." << endl;
}

// Fungsi untuk menghapus penumpang berdasarkan ID dari pramugari tertentu
void deletePenumpangByID(list_pramugari &LP, int idPramugari, int idPenumpang) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }

    if (P == NULL) {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
        return;
    }

    adr_penumpang Q = infoPramugari(P).firstPenumpang;
    adr_penumpang prev = NULL;

    while (Q != NULL && infoPenumpang(Q).id != idPenumpang) {
        prev = Q;
        Q = nextPenumpang(Q);
    }

    if (Q == NULL) {
        cout << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan." << endl;
        return;
    }

    if (prev == NULL) {
        infoPramugari(P).firstPenumpang = nextPenumpang(Q); // Menghapus penumpang pertama
    } else {
        nextPenumpang(prev) = nextPenumpang(Q); // Menghapus penumpang di tengah atau akhir
    }

    delete Q; // Menghapus memori
    cout << "Penumpang dengan ID " << idPenumpang << " telah dihapus." << endl;
}

// Fungsi untuk menampilkan semua penumpang
void showAllPenumpang(list_pramugari &LP){
    adr_pramugari P = LP.first;
    while (P != NULL) {
        cout << "Pramugari: " << infoPramugari(P).nama << " (ID: " << infoPramugari(P).id << ")" << endl;
        adr_penumpang Q = infoPramugari(P).firstPenumpang;
        while (Q != NULL) {
            cout << "  Penumpang: " << infoPenumpang(Q).nama << " (ID: " << infoPenumpang(Q).id << ")" << endl;
            Q = nextPenumpang(Q);
        }
        P = nextPramugari(P);
    }
}

// Fungsi untuk menambahkan N pramugari
void addNPramugari(list_pramugari &LP) {
    int N;
    while (true) {
        cout << "Berapa banyak pramugari yang ingin ditambahkan? ";
        if (cin >> N) {
            if (N > 0) break;
            else cout << "Masukkan angka positif." << endl;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka." << endl;
        }
    }
    cin.ignore(); // Mengabaikan newline setelah input integer

    for (int i = 0; i < N; i++) {
        string nama;
        int id;
        cout << "Data Pramugari ke-" << (i + 1) << endl;
        cout << "Nama Pramugari: ";
        getline(cin, nama);
        cout << "ID Pramugari: ";
        while (true) {
            if (cin >> id) {
                if (isPramugariIDUnique(LP, id)) break;
                else cout << "ID sudah digunakan, masukkan ID unik: ";
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid, masukkan angka untuk ID: ";
            }
        }
        cin.ignore(); // Mengabaikan newline setelah input integer

        adr_pramugari newPramugari = alokasiPramugari(nama, id);
        insertPramugari(LP, newPramugari);
        cout << "Pramugari " << nama << " telah ditambahkan." << endl;
    }
}

// Fungsi untuk menambahkan N penumpang ke pramugari tertentu
void addNPenumpangToPramugari(list_pramugari &LP) {
    int idPramugari, N;
    while (true) {
        cout << "Masukkan ID Pramugari: ";
        if (cin >> idPramugari) break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka." << endl;
        }
    }
    cin.ignore(); // Mengabaikan newline setelah input integer

    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }

    if (P == NULL) {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
        return;
    }

    while (true) {
        cout << "Berapa banyak penumpang yang ingin ditambahkan? ";
        if (cin >> N) {
            if (N > 0) break;
            else cout << "Masukkan angka positif." << endl;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka." << endl;
        }
    }
    cin.ignore(); // Mengabaikan newline setelah input integer

    for (int i = 0; i < N; i++) {
        string nama;
        int id;
        cout << "Data Penumpang ke-" << (i + 1) << endl;
        cout << "Nama Penumpang: ";
        getline(cin, nama);
        cout << "ID Penumpang: ";
        while (true) {
            if (cin >> id) {
                if (isPenumpangIDUnique(LP, id)) break;
                else cout << "ID sudah digunakan, masukkan ID unik: ";
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid, masukkan angka untuk ID: ";
            }
        }
        cin.ignore(); // Mengabaikan newline setelah input integer

        adr_penumpang newPenumpang = alokasiPenumpang(nama, id);
        addPenumpangToPramugari(LP, idPramugari, newPenumpang);
        cout << "Penumpang " << nama << " telah ditambahkan ke pramugari " << infoPramugari(P).nama << "." << endl;
    }

    // Hitung jumlah penumpang setelah penambahan
    int count = 0;
    adr_penumpang Q = infoPramugari(P).firstPenumpang;
    while (Q != NULL) {
        count++;
        Q = nextPenumpang(Q);
    }
    cout << "Pramugari " << infoPramugari(P).nama << " sekarang melayani " << count << " penumpang." << endl;
}


// Fungsi untuk menampilkan semua pramugari dan penumpang
void showAllPramugariWithPenumpang(list_pramugari &LP) {
    if (LP.first == NULL) {
        cout << "+-----------------------------+" << endl;
        cout << "|      List Pramugari Kosong  |" << endl;
        cout << "+-----------------------------+" << endl;
    } else {
        cout << "+-------------------------------------+" << endl;
        cout << "|         DATA PRAMUGARI & PENUMPANG  |" << endl;
        cout << "+-------------------------------------+" << endl;
        adr_pramugari P = LP.first;
        while (P != NULL) {
            cout << "+-------------------------------------+" << endl;
            cout << "| Pramugari: " << left << setw(25) << infoPramugari(P).nama << " |" << endl;
            cout << "| ID: " << left << setw(30) << infoPramugari(P).id << " |" << endl;
            cout << "+-------------------------------------+" << endl;

            // Menampilkan penumpang untuk pramugari ini
            adr_penumpang Q = infoPramugari(P).firstPenumpang;
            if (Q == NULL) {
                cout << "|  Tidak ada penumpang.               |" << endl;
                cout << "+-------------------------------------+" << endl;
            } else {
                cout << "|  Penumpang:                         |" << endl;
                cout << "+-------------------------------------+" << endl;
                while (Q != NULL) {
                    cout << "|  - Nama: " << left << setw(20) << infoPenumpang(Q).nama << " |" << endl;
                    cout << "|    ID: " << left << setw(22) << infoPenumpang(Q).id << " |" << endl;
                    cout << "+-------------------------------------+" << endl;
                    Q = nextPenumpang(Q);
                }
            }
            cout << endl;  // Baris kosong untuk memisahkan antar pramugari
            P = nextPramugari(P);
        }
    }
}

void displayPramugariWithMostPenumpang(list_pramugari &LP) {
    if (LP.first == NULL) {
        cout << "+-----------------------------+" << endl;
        cout << "|      List Pramugari Kosong  |" << endl;
        cout << "+-----------------------------+" << endl;
        return;
    }

    adr_pramugari current = LP.first;
    adr_pramugari maxPramugari = NULL;
    int maxCount = 0;

    while (current != NULL) {
        int count = 0;
        adr_penumpang penumpang = infoPramugari(current).firstPenumpang;

        // Hitung jumlah penumpang untuk pramugari ini
        while (penumpang != NULL) {
            count++;
            penumpang = nextPenumpang(penumpang);
        }

        // Perbarui pramugari dengan penumpang terbanyak
        if (count > maxCount) {
            maxCount = count;
            maxPramugari = current;
        }

        current = nextPramugari(current);
    }

    if (maxPramugari != NULL) {
        cout << "+-----------------------------+" << endl;
        cout << "| Pramugari Terbanyak Penumpang|" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| Nama: " << left << setw(21) << infoPramugari(maxPramugari).nama << " |" << endl;
        cout << "| Jumlah Penumpang: " << left << setw(8) << maxCount << " |" << endl;
        cout << "+-----------------------------+" << endl;
    } else {
        cout << "+-----------------------------+" << endl;
        cout << "| Tidak Ada Penumpang         |" << endl;
        cout << "+-----------------------------+" << endl;
    }
}

void showAllPramugari(list_pramugari &LP) {
    if (LP.first == NULL) {
        cout << "+-----------------------------+" << endl;
        cout << "|      List Pramugari Kosong  |" << endl;
        cout << "+-----------------------------+" << endl;
    } else {
        cout << "+-----------------------------+" << endl;
        cout << "|         DAFTAR PRAMUGARI    |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "| Nama Pramugari | ID         |" << endl;
        cout << "+----------------+------------+" << endl;
        adr_pramugari P = LP.first;
        while (P != NULL) {
            cout << "| " << left << setw(14) << infoPramugari(P).nama << " | " << setw(10) << infoPramugari(P).id << " |" << endl;
            P = nextPramugari(P);
        }
        cout << "+----------------+------------+" << endl;
    }
}

void searchPramugariByID(list_pramugari LP, int idPramugari) {
    adr_pramugari P = LP.first;
    bool found = false;
    while (P != NULL) {
        if (infoPramugari(P).id == idPramugari) {
            cout << "+-----------------------------+" << endl;
            cout << "|     Pramugari Ditemukan     |" << endl;
            cout << "+-----------------------------+" << endl;
            cout << "| Nama: " << left << setw(21) << infoPramugari(P).nama << " |" << endl;
            cout << "| ID: " << left << setw(23) << infoPramugari(P).id << " |" << endl;
            cout << "+-----------------------------+" << endl;
            found = true;
            break; // Jika ditemukan, keluar dari loop
        }
        P = nextPramugari(P);
    }
    if (!found) {
        cout << "+-----------------------------+" << endl;
        cout << "|   Pramugari Tidak Ditemukan |" << endl;
        cout << "+-----------------------------+" << endl;
    }
}

// Fungsi untuk mencari data penumpang berdasarkan ID penumpang
void searchPenumpangByID(list_pramugari &LP, int idPenumpang) {
    adr_pramugari pramugari = LP.first;
    bool found = false;

    while (pramugari != NULL) {
        adr_penumpang penumpang = infoPramugari(pramugari).firstPenumpang;
        while (penumpang != NULL) {
            if (infoPenumpang(penumpang).id == idPenumpang) {
                cout << "+-----------------------------+" << endl;
                cout << "|     Penumpang Ditemukan     |" << endl;
                cout << "+-----------------------------+" << endl;
                cout << "| Nama Penumpang: " << left << setw(11) << infoPenumpang(penumpang).nama << " |" << endl;
                cout << "| ID Penumpang: " << left << setw(13) << infoPenumpang(penumpang).id << " |" << endl;
                cout << "| Dilayani oleh Pramugari: " << left << setw(3) << infoPramugari(pramugari).nama << " |" << endl;
                cout << "| ID Pramugari: " << left << setw(13) << infoPramugari(pramugari).id << " |" << endl;
                cout << "+-----------------------------+" << endl;
                found = true;
                break;
            }
            penumpang = nextPenumpang(penumpang);
        }
        if (found) break; // Keluar dari loop jika penumpang ditemukan
        pramugari = nextPramugari(pramugari);
    }

    if (!found) {
        cout << "+-----------------------------+" << endl;
        cout << "|   Penumpang Tidak Ditemukan |" << endl;
        cout << "+-----------------------------+" << endl;
    }
}


// Fungsi untuk menambahkan penumpang ke pramugari tertentu dan menghubungkannya
void connectPenumpangAndPramugari(list_pramugari &LP, int idPenumpang, int idPramugari) {
    // Mencari pramugari berdasarkan ID
    adr_pramugari pramugari = LP.first; // Menggunakan LP yang diterima sebagai parameter
    while (pramugari != NULL && infoPramugari(pramugari).id != idPramugari) {
        pramugari = nextPramugari(pramugari);
    }

    // Mencari penumpang berdasarkan ID
    adr_penumpang penumpang = NULL;
    adr_pramugari pramugariAsal = NULL;
    adr_pramugari temp = LP.first; // Menggunakan LP yang diterima sebagai parameter
    while (temp != NULL) {
        adr_penumpang p = infoPramugari(temp).firstPenumpang;
        while (p != NULL) {
            if (infoPenumpang(p).id == idPenumpang) {
                penumpang = p;
                pramugariAsal = temp;
                break;
            }
            p = nextPenumpang(p);
        }
        if (penumpang != NULL) break;
        temp = nextPramugari(temp);
    }

    // Menghubungkan penumpang dan pramugari jika ditemukan
    if (pramugari != NULL && penumpang != NULL) {
        // Jika penumpang sudah di pramugari lain, hapus dari asal
        if (pramugariAsal != pramugari) {
            adr_penumpang Q = infoPramugari(pramugariAsal).firstPenumpang;
            adr_penumpang prev = NULL;
            while (Q != NULL && Q != penumpang) {
                prev = Q;
                Q = nextPenumpang(Q);
            }
            if (prev == NULL) {
                infoPramugari(pramugariAsal).firstPenumpang = nextPenumpang(Q);
            } else {
                nextPenumpang(prev) = nextPenumpang(Q);
            }
            // Reset next pointer dari penumpang yang dipindahkan
            nextPenumpang(penumpang) = NULL;
        }

        // Menambahkan penumpang ke daftar penumpang pramugari
        if (infoPramugari(pramugari).firstPenumpang == NULL) {
            infoPramugari(pramugari).firstPenumpang = penumpang;
        } else {
            adr_penumpang lastPenumpang = infoPramugari(pramugari).firstPenumpang;
            while (nextPenumpang(lastPenumpang) != NULL) {
                lastPenumpang = nextPenumpang(lastPenumpang);
            }
            nextPenumpang(lastPenumpang) = penumpang;
        }

        cout << "Penumpang dengan ID " << idPenumpang << " berhasil dihubungkan dengan pramugari dengan ID " << idPramugari << "." << endl;
    } else {
        cout << "Pramugari atau penumpang tidak ditemukan." << endl;
    }
}

void findPenumpangInPramugari(list_pramugari &LP, int idPramugari) {
    adr_pramugari P = LP.first; // Menelusuri list pramugari
    bool found = false; // Menandakan apakah pramugari ditemukan

    while (P != NULL) {
        if (infoPramugari(P).id == idPramugari) {
            found = true;
            cout << "+-----------------------------+" << endl;
            cout << "| Penumpang dari Pramugari    |" << endl;
            cout << "+-----------------------------+" << endl;
            cout << "| Pramugari: " << left << setw(16) << infoPramugari(P).nama << " |" << endl;
            cout << "| ID: " << left << setw(23) << infoPramugari(P).id << " |" << endl;
            cout << "+-----------------------------+" << endl;

            adr_penumpang Q = infoPramugari(P).firstPenumpang;
            if (Q == NULL) {
                cout << "|  Tidak ada penumpang.       |" << endl;
                cout << "+-----------------------------+" << endl;
            } else {
                while (Q != NULL) {
                    cout << "|  Nama: " << left << setw(20) << infoPenumpang(Q).nama << " |" << endl;
                    cout << "|  ID: " << left << setw(22) << infoPenumpang(Q).id << " |" << endl;
                    cout << "+-----------------------------+" << endl;
                    Q = nextPenumpang(Q);
                }
            }
            break; // Keluar dari loop jika pramugari ditemukan
        }
        P = nextPramugari(P); // Melanjutkan pencarian ke pramugari berikutnya
    }

    if (!found) {
        cout << "+-----------------------------+" << endl;
        cout << "| Pramugari Tidak Ditemukan   |" << endl;
        cout << "+-----------------------------+" << endl;
    }
}

void deletePenumpangFromPramugari(list_pramugari &LP, int idPramugari, int idPenumpang) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);  // Menelusuri list pramugari
    }

    if (P != NULL) {
        // Jika pramugari ditemukan, kita akan mencari penumpang di dalam pramugari tersebut
        adr_penumpang Q = infoPramugari(P).firstPenumpang;
        adr_penumpang prev = NULL;

        while (Q != NULL && infoPenumpang(Q).id != idPenumpang) {
            prev = Q;
            Q = nextPenumpang(Q);  // Menelusuri list penumpang
        }

        if (Q != NULL) {
            // Jika penumpang ditemukan
            if (prev == NULL) {
                // Jika penumpang yang akan dihapus adalah penumpang pertama
                infoPramugari(P).firstPenumpang = nextPenumpang(Q);
            } else {
                // Jika penumpang yang akan dihapus ada di tengah atau akhir
                nextPenumpang(prev) = nextPenumpang(Q);
            }

            delete Q;  // Menghapus penumpang dari memori
            cout << "Penumpang dengan ID " << idPenumpang << " telah dihapus dari pramugari " << infoPramugari(P).nama << "." << endl;
        } else {
            // Jika penumpang tidak ditemukan
            cout << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan pada pramugari " << infoPramugari(P).nama << "." << endl;
        }
    } else {
        // Jika pramugari tidak ditemukan
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengedit data pramugari berdasarkan ID
void editPramugariByID(list_pramugari &LP, int idPramugari) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }

    if (P != NULL) {
        cout << "Pramugari ditemukan: " << infoPramugari(P).nama << " (ID: " << infoPramugari(P).id << ")" << endl;
        cout << "Masukkan nama baru: ";
        string namaBaru;
        getline(cin, namaBaru);
        cout << "Masukkan ID baru: ";
        int idBaru;
        while (true) {
            cin >> idBaru;
            if (isPramugariIDUnique(LP, idBaru) || idBaru == infoPramugari(P).id) break;
            else cout << "ID sudah digunakan, masukkan ID unik: ";
        }
        cin.ignore(); // Mengabaikan newline

        infoPramugari(P).nama = namaBaru;
        infoPramugari(P).id = idBaru;
        cout << "Data pramugari telah diperbarui." << endl;
        cout << "Pramugari yang baru diedit: " << infoPramugari(P).nama << " (ID: " << infoPramugari(P).id << ")" << endl;
        cout << "Daftar semua pramugari beserta penumpang:" << endl;
        showAllPramugariWithPenumpang(LP);
    } else {
        cout << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengedit data penumpang berdasarkan ID
void editPenumpangByID(list_pramugari &LP, int idPenumpang) {
    adr_pramugari pramugari = LP.first;
    adr_penumpang penumpang = NULL;
    adr_pramugari pramugariAsal = NULL;

    // Cari penumpang
    while (pramugari != NULL) {
        adr_penumpang Q = infoPramugari(pramugari).firstPenumpang;
        while (Q != NULL) {
            if (infoPenumpang(Q).id == idPenumpang) {
                penumpang = Q;
                pramugariAsal = pramugari;
                break;
            }
            Q = nextPenumpang(Q);
        }
        if (penumpang != NULL) break;
        pramugari = nextPramugari(pramugari);
    }

    if (penumpang != NULL) {
        cout << "Penumpang ditemukan: " << infoPenumpang(penumpang).nama << " (ID: " << infoPenumpang(penumpang).id << ")" << endl;
        cout << "Masukkan nama baru: ";
        string namaBaru;
        getline(cin, namaBaru);
        cout << "Masukkan ID baru: ";
        int idBaru;
        while (true) {
            cin >> idBaru;
            if (isPenumpangIDUnique(LP, idBaru) || idBaru == infoPenumpang(penumpang).id) break;
            else cout << "ID sudah digunakan, masukkan ID unik: ";
        }
        cin.ignore(); // Mengabaikan newline

        infoPenumpang(penumpang).nama = namaBaru;
        infoPenumpang(penumpang).id = idBaru;
        cout << "Data penumpang telah diperbarui." << endl;

        // Opsi untuk mengubah pramugari
        cout << "Apakah ingin mengubah pramugari? (y/n): ";
        char pilihan;
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 'y' || pilihan == 'Y') {
            cout << "Masukkan ID pramugari baru: ";
            int idPramugariBaru;
            cin >> idPramugariBaru;
            cin.ignore();

            if (idPramugariBaru == infoPramugari(pramugariAsal).id) {
                cout << "Itu adalah pramugari yang sama seperti sebelumnya." << endl;
            } else {
                // Hapus dari pramugari asal
            adr_penumpang Q = infoPramugari(pramugariAsal).firstPenumpang;
            adr_penumpang prev = NULL;
            while (Q != NULL && Q != penumpang) {
                prev = Q;
                Q = nextPenumpang(Q);
            }
            if (prev == NULL) {
                infoPramugari(pramugariAsal).firstPenumpang = nextPenumpang(Q);
            } else {
                nextPenumpang(prev) = nextPenumpang(Q);
            }

            // Tambah ke pramugari baru
            adr_pramugari baru = LP.first;
            while (baru != NULL && infoPramugari(baru).id != idPramugariBaru) {
                baru = nextPramugari(baru);
            }
            if (baru != NULL) {
                nextPenumpang(penumpang) = NULL; // Reset next
                if (infoPramugari(baru).firstPenumpang == NULL) {
                    infoPramugari(baru).firstPenumpang = penumpang;
                } else {
                    adr_penumpang last = infoPramugari(baru).firstPenumpang;
                    while (nextPenumpang(last) != NULL) {
                        last = nextPenumpang(last);
                    }
                    nextPenumpang(last) = penumpang;
                }
                cout << "Penumpang telah dipindahkan ke pramugari baru." << endl;
            } else {
                cout << "Pramugari baru tidak ditemukan, penumpang tetap di pramugari asal." << endl;
                // Kembalikan ke asal
                if (prev == NULL) {
                    infoPramugari(pramugariAsal).firstPenumpang = penumpang;
                } else {
                    nextPenumpang(prev) = penumpang;
                }
            }
        }
    }

    // Tampilkan data penumpang yang telah diedit
    adr_pramugari currentPramugari = LP.first;
    while (currentPramugari != NULL) {
        adr_penumpang Q = infoPramugari(currentPramugari).firstPenumpang;
        while (Q != NULL) {
            if (Q == penumpang) {
                cout << "Penumpang yang baru diedit: " << infoPenumpang(penumpang).nama << " (ID: " << infoPenumpang(penumpang).id << ")" << endl;
                cout << "Dilayani oleh Pramugari: " << infoPramugari(currentPramugari).nama << " (ID: " << infoPramugari(currentPramugari).id << ")" << endl;
                break;
            }
            Q = nextPenumpang(Q);
        }
        if (Q != NULL) break;
        currentPramugari = nextPramugari(currentPramugari);
    }
} else {
    cout << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan." << endl;
}
}

// Fungsi untuk memeriksa apakah ID pramugari unik
bool isPramugariIDUnique(list_pramugari LP, int id) {
    adr_pramugari P = LP.first;
    while (P != NULL) {
        if (infoPramugari(P).id == id) {
            return false;
        }
        P = nextPramugari(P);
    }
    return true;
}

// Fungsi untuk memeriksa apakah ID penumpang unik
bool isPenumpangIDUnique(list_pramugari LP, int id) {
    adr_pramugari P = LP.first;
    while (P != NULL) {
        adr_penumpang Q = infoPramugari(P).firstPenumpang;
        while (Q != NULL) {
            if (infoPenumpang(Q).id == id) {
                return false;
            }
            Q = nextPenumpang(Q);
        }
        P = nextPramugari(P);
    }
    return true;
}

// Fungsi helper untuk mencari pramugari berdasarkan ID
adr_pramugari findPramugariByID(list_pramugari LP, int id) {
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != id) {
        P = nextPramugari(P);
    }
    return P;
}

// Fungsi helper untuk mencari penumpang berdasarkan ID
adr_penumpang findPenumpangByID(list_pramugari LP, int id) {
    adr_pramugari P = LP.first;
    while (P != NULL) {
        adr_penumpang Q = infoPramugari(P).firstPenumpang;
        while (Q != NULL) {
            if (infoPenumpang(Q).id == id) {
                return Q;
            }
            Q = nextPenumpang(Q);
        }
        P = nextPramugari(P);
    }
    return NULL;
}

