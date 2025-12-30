#ifndef tubes_hpp
#define tubes_hpp
#include <iostream>
#include <string>
#include <vector>

#define infoPramugari(P) (P)->infoPramugari
#define infoPenumpang(P) (P)->infoPenumpang
#define nextPramugari(P) (P)->nextPramugari
#define nextPenumpang(P) (P)->nextPenumpang
using namespace std;

// Pointer
typedef struct elmPramugari *adr_pramugari;
typedef struct elmPenumpang *adr_penumpang;
// Struktur Pramugari
struct pramugari {
    string nama;
    int id;
    adr_penumpang firstPenumpang;
};
// Struktur Penumpang
struct penumpang {
    string nama;
    int id;
    adr_pramugari pramugari;
};
// Elemen Pramugari
struct elmPramugari {
    pramugari infoPramugari;
    adr_pramugari nextPramugari;
};
// Elemen Penumpang
struct elmPenumpang {
    penumpang infoPenumpang;
    adr_penumpang nextPenumpang;
};
// List Pramugari
struct list_pramugari {
    adr_pramugari first;
    adr_pramugari last;
};
struct list_penumpang {
    adr_penumpang first;
    adr_penumpang last;
};

// Prototipe fungsi
void createListPramugari(list_pramugari &LP);
adr_pramugari alokasiPramugari(string nama, int id);
adr_penumpang alokasiPenumpang(string nama, int id);
void insertPramugari(list_pramugari &LP, adr_pramugari newPramugari);
void insertPenumpang(list_penumpang &Lp, adr_penumpang newPenumpang);
string deletePramugariByID(list_pramugari &LP, int id);
void addPenumpangToPramugari(list_pramugari &LP, int idPramugari, adr_penumpang newPenumpang);
void deletePenumpangByID(list_pramugari &LP, int idPramugari, int idPenumpang);
string addNPramugari(list_pramugari &LP, const vector<pair<string, int>>& pramugariList);
string addNPenumpangToPramugari(list_pramugari &LP, int idPramugari, const vector<pair<string, int>>& penumpangList);
void showPenumpangOfPramugari(list_pramugari &LP, int idPramugari);
string showAllPramugariWithPenumpang(list_pramugari &LP);
void showAllPenumpang(list_pramugari &LP);
string displayPramugariWithMostPenumpang(list_pramugari &LP);
string showAllPramugari(list_pramugari &LP);
string searchPramugariByID(list_pramugari LP, int idPramugari);
string searchPenumpangByID(list_pramugari &LP, int idPenumpang);
string connectPenumpangAndPramugari(list_pramugari &LP, int idPenumpang, int idPramugari);
string findPenumpangInPramugari(list_pramugari &LP, int idPramugari);
string deletePenumpangFromPramugari(list_pramugari &LP, int idPramugari, int idPenumpang);
string editPramugariByID(list_pramugari &LP, int idPramugari, string namaBaru, int idBaru);
string editPenumpangByID(list_pramugari &LP, int idPenumpang, string namaBaru, int idBaru, bool changePramugari, int newPramugariId);
bool isPramugariIDUnique(list_pramugari LP, int id);
bool isPenumpangIDUnique(list_pramugari LP, int id);
adr_pramugari findPramugariByID(list_pramugari LP, int id);
adr_penumpang findPenumpangByID(list_pramugari LP, int id);

// Handler functions for menu choices
string handleAddPramugari(list_pramugari &LP);
string handleDeletePramugari(list_pramugari &LP);
string handleSearchPramugari(list_pramugari &LP);
string handleEditPramugari(list_pramugari &LP);
string handleAddPenumpang(list_pramugari &LP);
string handleSearchPenumpang(list_pramugari &LP);
string handleEditPenumpang(list_pramugari &LP);
string handleConnect(list_pramugari &LP);
string handleFindPenumpangInPramugari(list_pramugari &LP);
string handleDeletePenumpangFromPramugari(list_pramugari &LP);

#endif // tubes_hpp
