
#include "tubes.hpp"
#include <iomanip>
#include <limits>
#include <sstream>
#include <vector>

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

// Fungsi untuk mengalokasikan penumpang
adr_penumpang alokasiPenumpang(string nama, int id) {
    adr_penumpang newPenumpang = new elmPenumpang;
    infoPenumpang(newPenumpang).nama = nama;
    infoPenumpang(newPenumpang).id = id;
    nextPenumpang(newPenumpang) = NULL;
    return newPenumpang;
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
    }
}

// Fitur 1: Tambahkan Pramugari
// Fungsi untuk menambahkan N pramugari
string addNPramugari(list_pramugari &LP, const vector<pair<string, int>>& pramugariList) {
    ostringstream oss;
    for (auto& p : pramugariList) {
        adr_pramugari newPramugari = alokasiPramugari(p.first, p.second);
        insertPramugari(LP, newPramugari);
        oss << "Pramugari " << p.first << " telah ditambahkan." << endl;
    }
    return oss.str();
}

string handleAddPramugari(list_pramugari &LP) {
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
    cin.ignore();
    vector<pair<string, int>> pramugariList;
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
        cin.ignore();
        pramugariList.push_back({nama, id});
    }
    return addNPramugari(LP, pramugariList);
}

// Fitur 2: Tampilkan semua Pramugari
string showAllPramugari(list_pramugari &LP) {
    ostringstream oss;
    if (LP.first == NULL) {
        oss << "+-----------------------------+" << endl;
        oss << "|      List Pramugari Kosong  |" << endl;
        oss << "+-----------------------------+" << endl;
    } else {
        oss << "+-----------------------------+" << endl;
        oss << "|         DAFTAR PRAMUGARI    |" << endl;
        oss << "+-----------------------------+" << endl;
        oss << "| Nama Pramugari | ID         |" << endl;
        oss << "+----------------+------------+" << endl;
        adr_pramugari P = LP.first;
        while (P != NULL) {
            oss << "| " << left << setw(14) << infoPramugari(P).nama << " | " << setw(10) << infoPramugari(P).id << " |" << endl;
            P = nextPramugari(P);
        }
        oss << "+----------------+------------+" << endl;
    }
    return oss.str();
}

// Fitur 3: Hapus Pramugari
// Fungsi untuk menghapus pramugari berdasarkan ID
string deletePramugariByID(list_pramugari &LP, int idPramugari) {
    ostringstream oss;
    adr_pramugari P = findPramugariByID(LP, idPramugari);
    if (P == NULL) {
        oss << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
        return oss.str();
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
    oss << "Pramugari dengan ID " << idPramugari << " dan semua penumpangnya telah dihapus." << endl;
    return oss.str();
}

string handleDeletePramugari(list_pramugari &LP) {
    int idPramugari;
    cout << "Masukkan ID Pramugari yang ingin dihapus: ";
    cin >> idPramugari;
    return deletePramugariByID(LP, idPramugari);
}

// Fitur 4: Mencari Pramugari
string searchPramugariByID(list_pramugari LP, int idPramugari) {
    ostringstream oss;
    adr_pramugari P = LP.first;
    bool found = false;
    while (P != NULL) {
        if (infoPramugari(P).id == idPramugari) {
            oss << "+-----------------------------+" << endl;
            oss << "|     Pramugari Ditemukan     |" << endl;
            oss << "+-----------------------------+" << endl;
            oss << "| Nama: " << left << setw(21) << infoPramugari(P).nama << " |" << endl;
            oss << "| ID: " << left << setw(23) << infoPramugari(P).id << " |" << endl;
            oss << "+-----------------------------+" << endl;
            found = true;
            break; // Jika ditemukan, keluar dari loop
        }
        P = nextPramugari(P);
    }
    if (!found) {
        oss << "+-----------------------------+" << endl;
        oss << "|   Pramugari Tidak Ditemukan |" << endl;
        oss << "+-----------------------------+" << endl;
    }
    return oss.str();
}

string handleSearchPramugari(list_pramugari &LP) {
    int idPramugari;
    cout << "Masukkan ID Pramugari yang ingin dicari: ";
    cin >> idPramugari;
    return searchPramugariByID(LP, idPramugari);
}

// Fitur 5: Edit Pramugari
// Fungsi untuk mengedit data pramugari berdasarkan ID
string editPramugariByID(list_pramugari &LP, int idPramugari, string namaBaru, int idBaru) {
    ostringstream oss;
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }

    if (P != NULL) {
        oss << "Pramugari ditemukan: " << infoPramugari(P).nama << " (ID: " << infoPramugari(P).id << ")" << endl;
        infoPramugari(P).nama = namaBaru;
        infoPramugari(P).id = idBaru;
        oss << "Data pramugari telah diperbarui." << endl;
        oss << "Pramugari yang baru diedit: " << infoPramugari(P).nama << " (ID: " << infoPramugari(P).id << ")" << endl;
        oss << "Daftar semua pramugari beserta penumpang:" << endl;
        oss << showAllPramugariWithPenumpang(LP);
    } else {
        oss << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
    return oss.str();
}

string handleEditPramugari(list_pramugari &LP) {
    int idPramugari;
    cout << "Masukkan ID Pramugari yang ingin diedit: ";
    cin >> idPramugari;
    cin.ignore();
    string namaBaru;
    cout << "Masukkan nama baru: ";
    getline(cin, namaBaru);
    int idBaru;
    cout << "Masukkan ID baru: ";
    while (true) {
        cin >> idBaru;
        if (isPramugariIDUnique(LP, idBaru) || idBaru == idPramugari) break;
        else cout << "ID sudah digunakan, masukkan ID unik: ";
    }
    cin.ignore();
    return editPramugariByID(LP, idPramugari, namaBaru, idBaru);
}

// Fitur 6: Tambahkan Penumpang
// Fungsi untuk menambahkan N penumpang ke pramugari tertentu
string addNPenumpangToPramugari(list_pramugari &LP, int idPramugari, const vector<pair<string, int>>& penumpangList) {
    ostringstream oss;
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }

    if (P == NULL) {
        oss << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
        return oss.str();
    }

    for (auto& p : penumpangList) {
        adr_penumpang newPenumpang = alokasiPenumpang(p.first, p.second);
        addPenumpangToPramugari(LP, idPramugari, newPenumpang);
        oss << "Penumpang " << p.first << " telah ditambahkan ke pramugari " << infoPramugari(P).nama << "." << endl;
    }

    // Hitung jumlah penumpang setelah penambahan
    int count = 0;
    adr_penumpang Q = infoPramugari(P).firstPenumpang;
    while (Q != NULL) {
        count++;
        Q = nextPenumpang(Q);
    }
    oss << "Pramugari " << infoPramugari(P).nama << " sekarang melayani " << count << " penumpang." << endl;
    return oss.str();
}

string handleAddPenumpang(list_pramugari &LP) {
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
    cin.ignore();
    adr_pramugari P = LP.first;
    while (P != NULL && infoPramugari(P).id != idPramugari) {
        P = nextPramugari(P);
    }
    if (P == NULL) {
        return "Pramugari dengan ID " + to_string(idPramugari) + " tidak ditemukan.";
    } else {
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
        cin.ignore();
        vector<pair<string, int>> penumpangList;
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
            cin.ignore();
            penumpangList.push_back({nama, id});
        }
        return addNPenumpangToPramugari(LP, idPramugari, penumpangList);
    }
}

// Fitur 7: Mencari Penumpang
// Fungsi untuk mencari data penumpang berdasarkan ID penumpang
string searchPenumpangByID(list_pramugari &LP, int idPenumpang) {
    ostringstream oss;
    adr_pramugari pramugari = LP.first;
    bool found = false;

    while (pramugari != NULL) {
        adr_penumpang penumpang = infoPramugari(pramugari).firstPenumpang;
        while (penumpang != NULL) {
            if (infoPenumpang(penumpang).id == idPenumpang) {
                oss << "+-----------------------------+" << endl;
                oss << "|     Penumpang Ditemukan     |" << endl;
                oss << "+-----------------------------+" << endl;
                oss << "| Nama Penumpang: " << left << setw(11) << infoPenumpang(penumpang).nama << " |" << endl;
                oss << "| ID Penumpang: " << left << setw(13) << infoPenumpang(penumpang).id << " |" << endl;
                oss << "| Dilayani oleh Pramugari: " << left << setw(3) << infoPramugari(pramugari).nama << " |" << endl;
                oss << "| ID Pramugari: " << left << setw(13) << infoPramugari(pramugari).id << " |" << endl;
                oss << "+-----------------------------+" << endl;
                found = true;
                break;
            }
            penumpang = nextPenumpang(penumpang);
        }
        if (found) break; // Keluar dari loop jika penumpang ditemukan
        pramugari = nextPramugari(pramugari);
    }

    if (!found) {
        oss << "+-----------------------------+" << endl;
        oss << "|   Penumpang Tidak Ditemukan |" << endl;
        oss << "+-----------------------------+" << endl;
    }
    return oss.str();
}

string handleSearchPenumpang(list_pramugari &LP) {
    int idPenumpang;
    cout << "Masukkan ID Penumpang yang ingin dicari: ";
    cin >> idPenumpang;
    return searchPenumpangByID(LP, idPenumpang);
}

// Fitur 8: Edit Penumpang
// Fungsi untuk mengedit data penumpang berdasarkan ID
string editPenumpangByID(list_pramugari &LP, int idPenumpang, string namaBaru, int idBaru, bool changePramugari, int newPramugariId) {
    ostringstream oss;
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
        oss << "Penumpang ditemukan: " << infoPenumpang(penumpang).nama << " (ID: " << infoPenumpang(penumpang).id << ")" << endl;
        infoPenumpang(penumpang).nama = namaBaru;
        infoPenumpang(penumpang).id = idBaru;
        oss << "Data penumpang telah diperbarui." << endl;

        if (changePramugari) {
            if (newPramugariId == infoPramugari(pramugariAsal).id) {
                oss << "Itu adalah pramugari yang sama seperti sebelumnya." << endl;
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
                while (baru != NULL && infoPramugari(baru).id != newPramugariId) {
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
                    oss << "Penumpang telah dipindahkan ke pramugari baru." << endl;
                } else {
                    oss << "Pramugari baru tidak ditemukan, penumpang tetap di pramugari asal." << endl;
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
                    oss << "Penumpang yang baru diedit: " << infoPenumpang(penumpang).nama << " (ID: " << infoPenumpang(penumpang).id << ")" << endl;
                    oss << "Dilayani oleh Pramugari: " << infoPramugari(currentPramugari).nama << " (ID: " << infoPramugari(currentPramugari).id << ")" << endl;
                    break;
                }
                Q = nextPenumpang(Q);
            }
            if (Q != NULL) break;
            currentPramugari = nextPramugari(currentPramugari);
        }
    } else {
        oss << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan." << endl;
    }
    return oss.str();
}

string handleEditPenumpang(list_pramugari &LP) {
    int idPenumpang;
    cout << "Masukkan ID Penumpang yang ingin diedit: ";
    cin >> idPenumpang;
    cin.ignore();
    // Find if exists
    adr_pramugari pramugari = LP.first;
    adr_penumpang penumpang = NULL;
    while (pramugari != NULL) {
        adr_penumpang Q = infoPramugari(pramugari).firstPenumpang;
        while (Q != NULL) {
            if (infoPenumpang(Q).id == idPenumpang) {
                penumpang = Q;
                break;
            }
            Q = nextPenumpang(Q);
        }
        if (penumpang != NULL) break;
        pramugari = nextPramugari(pramugari);
    }
    if (penumpang == NULL) {
        return "Penumpang dengan ID " + to_string(idPenumpang) + " tidak ditemukan.";
    } else {
        cout << "Penumpang ditemukan: " << infoPenumpang(penumpang).nama << " (ID: " << infoPenumpang(penumpang).id << ")" << endl;
        string namaBaru;
        cout << "Masukkan nama baru: ";
        getline(cin, namaBaru);
        int idBaru;
        cout << "Masukkan ID baru: ";
        while (true) {
            cin >> idBaru;
            if (isPenumpangIDUnique(LP, idBaru) || idBaru == infoPenumpang(penumpang).id) break;
            else cout << "ID sudah digunakan, masukkan ID unik: ";
        }
        cin.ignore();
        bool changePramugari = false;
        int newPramugariId = -1;
        cout << "Apakah ingin mengubah pramugari? (y/n): ";
        char pilihan;
        cin >> pilihan;
        cin.ignore();
        if (pilihan == 'y' || pilihan == 'Y') {
            cout << "Masukkan ID pramugari baru: ";
            cin >> newPramugariId;
            cin.ignore();
            changePramugari = true;
        }
        return editPenumpangByID(LP, idPenumpang, namaBaru, idBaru, changePramugari, newPramugariId);
    }
}

// Fitur 9: Hubungkan Pramugari dengan Penumpang
// Fungsi untuk menambahkan penumpang ke pramugari tertentu dan menghubungkannya
string connectPenumpangAndPramugari(list_pramugari &LP, int idPenumpang, int idPramugari) {
    ostringstream oss;
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

        oss << "Penumpang dengan ID " << idPenumpang << " berhasil dihubungkan dengan pramugari dengan ID " << idPramugari << "." << endl;
    } else {
        oss << "Pramugari atau penumpang tidak ditemukan." << endl;
    }
    return oss.str();
}

string handleConnect(list_pramugari &LP) {
    int idPenumpang, idPramugari;
    cout << "Masukkan ID Penumpang yang ingin dihubungkan: ";
    cin >> idPenumpang;
    cout << "Masukkan ID Pramugari yang akan melayani: ";
    cin >> idPramugari;
    cin.ignore();
    return connectPenumpangAndPramugari(LP, idPenumpang, idPramugari);
}

// Fitur 10: Tampilkan semua Pramugari beserta Penumpangnya
// Fungsi untuk menampilkan semua pramugari dan penumpang
string showAllPramugariWithPenumpang(list_pramugari &LP) {
    ostringstream oss;
    if (LP.first == NULL) {
        oss << "+-----------------------------+" << endl;
        oss << "|      List Pramugari Kosong  |" << endl;
        oss << "+-----------------------------+" << endl;
    } else {
        oss << "+-------------------------------------+" << endl;
        oss << "|         DATA PRAMUGARI & PENUMPANG  |" << endl;
        oss << "+-------------------------------------+" << endl;
        adr_pramugari P = LP.first;
        while (P != NULL) {
            oss << "+-------------------------------------+" << endl;
            oss << "| Pramugari: " << left << setw(25) << infoPramugari(P).nama << " |" << endl;
            oss << "| ID: " << left << setw(30) << infoPramugari(P).id << " |" << endl;
            oss << "+-------------------------------------+" << endl;

            // Menampilkan penumpang untuk pramugari ini
            adr_penumpang Q = infoPramugari(P).firstPenumpang;
            if (Q == NULL) {
                oss << "|  Tidak ada penumpang.               |" << endl;
                oss << "+-------------------------------------+" << endl;
            } else {
                oss << "|  Penumpang:                         |" << endl;
                oss << "+-------------------------------------+" << endl;
                while (Q != NULL) {
                    oss << "|  - Nama: " << left << setw(20) << infoPenumpang(Q).nama << " |" << endl;
                    oss << "|    ID: " << left << setw(22) << infoPenumpang(Q).id << " |" << endl;
                    oss << "+-------------------------------------+" << endl;
                    Q = nextPenumpang(Q);
                }
            }
            oss << endl;  // Baris kosong untuk memisahkan antar pramugari
            P = nextPramugari(P);
        }
    }
    return oss.str();
}

// Fitur 11: Pramugari yang paling banyak melayani Penumpang
string displayPramugariWithMostPenumpang(list_pramugari &LP) {
    ostringstream oss;
    if (LP.first == NULL) {
        oss << "+-----------------------------+" << endl;
        oss << "|      List Pramugari Kosong  |" << endl;
        oss << "+-----------------------------+" << endl;
        return oss.str();
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
        oss << "+-----------------------------+" << endl;
        oss << "| Pramugari Terbanyak Penumpang|" << endl;
        oss << "+-----------------------------+" << endl;
        oss << "| Nama: " << left << setw(21) << infoPramugari(maxPramugari).nama << " |" << endl;
        oss << "| Jumlah Penumpang: " << left << setw(8) << maxCount << " |" << endl;
        oss << "+-----------------------------+" << endl;
    } else {
        oss << "+-----------------------------+" << endl;
        oss << "| Tidak Ada Penumpang         |" << endl;
        oss << "+-----------------------------+" << endl;
    }
    return oss.str();
}

// Fitur 12: Cari Penumpang di Pramugari
string findPenumpangInPramugari(list_pramugari &LP, int idPramugari) {
    ostringstream oss;
    adr_pramugari P = LP.first; // Menelusuri list pramugari
    bool found = false; // Menandakan apakah pramugari ditemukan

    while (P != NULL) {
        if (infoPramugari(P).id == idPramugari) {
            found = true;
            oss << "+-----------------------------+" << endl;
            oss << "| Penumpang dari Pramugari    |" << endl;
            oss << "+-----------------------------+" << endl;
            oss << "| Pramugari: " << left << setw(16) << infoPramugari(P).nama << " |" << endl;
            oss << "| ID: " << left << setw(23) << infoPramugari(P).id << " |" << endl;
            oss << "+-----------------------------+" << endl;

            adr_penumpang Q = infoPramugari(P).firstPenumpang;
            if (Q == NULL) {
                oss << "|  Tidak ada penumpang.       |" << endl;
                oss << "+-----------------------------+" << endl;
            } else {
                while (Q != NULL) {
                    oss << "|  Nama: " << left << setw(20) << infoPenumpang(Q).nama << " |" << endl;
                    oss << "|  ID: " << left << setw(22) << infoPenumpang(Q).id << " |" << endl;
                    oss << "+-----------------------------+" << endl;
                    Q = nextPenumpang(Q);
                }
            }
            break; // Keluar dari loop jika pramugari ditemukan
        }
        P = nextPramugari(P); // Melanjutkan pencarian ke pramugari berikutnya
    }

    if (!found) {
        oss << "+-----------------------------+" << endl;
        oss << "| Pramugari Tidak Ditemukan   |" << endl;
        oss << "+-----------------------------+" << endl;
    }
    return oss.str();
}

string handleFindPenumpangInPramugari(list_pramugari &LP) {
    int idPramugari;
    cout << "Masukkan ID Pramugari: ";
    cin >> idPramugari;
    cin.ignore();
    return findPenumpangInPramugari(LP, idPramugari);
}

// Fitur 13: Hapus Penumpang di Pramugari
string deletePenumpangFromPramugari(list_pramugari &LP, int idPramugari, int idPenumpang) {
    ostringstream oss;
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
            oss << "Penumpang dengan ID " << idPenumpang << " telah dihapus dari pramugari " << infoPramugari(P).nama << "." << endl;
        } else {
            // Jika penumpang tidak ditemukan
            oss << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan pada pramugari " << infoPramugari(P).nama << "." << endl;
        }
    } else {
        // Jika pramugari tidak ditemukan
        oss << "Pramugari dengan ID " << idPramugari << " tidak ditemukan." << endl;
    }
    return oss.str();
}

string handleDeletePenumpangFromPramugari(list_pramugari &LP) {
    int idPramugari, idPenumpang;
    cout << "Masukkan ID Pramugari: ";
    cin >> idPramugari;
    cout << "Masukkan ID Penumpang yang ingin dihapus: ";
    cin >> idPenumpang;
    cin.ignore();
    return deletePenumpangFromPramugari(LP, idPramugari, idPenumpang);
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

// Helper function untuk mencari penumpang berdasarkan ID (digunakan dalam operasi internal seperti edit dan delete)
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


