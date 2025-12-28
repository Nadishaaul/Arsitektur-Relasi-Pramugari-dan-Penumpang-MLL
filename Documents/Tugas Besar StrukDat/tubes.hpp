
#ifndef tubes_hpp
#define tubes_hpp

#include <iostream>
#include <string>

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
void deletePramugariByID(list_pramugari &LP, int id);
void addPenumpangToPramugari(list_pramugari &LP, int idPramugari, adr_penumpang newPenumpang);
void deletePenumpangByID(list_pramugari &LP, int idPramugari, int idPenumpang);
void addNPramugari(list_pramugari &LP);
void addNPenumpangToPramugari(list_pramugari &LP);
void showPenumpangOfPramugari(list_pramugari &LP, int idPramugari);
void showAllPramugariWithPenumpang(list_pramugari &LP);
void showAllPenumpang(list_pramugari &LP);
void displayPramugariWithMostPenumpang(list_pramugari &LP);
void showAllPramugari(list_pramugari &LP);
void searchPramugariByID(list_pramugari LP, int idPramugari);
void searchPenumpangByID(list_pramugari &LP, int idPenumpang);
void connectPenumpangAndPramugari(list_pramugari &LP, int idPenumpang, int idPramugari);
void findPenumpangInPramugari(list_pramugari &LP, int idPramugari);
void deletePenumpangFromPramugari(list_pramugari &LP, int idPramugari, int idPenumpang);
void editPramugariByID(list_pramugari &LP, int idPramugari);
void editPenumpangByID(list_pramugari &LP, int idPenumpang);
bool isPramugariIDUnique(list_pramugari LP, int id);
bool isPenumpangIDUnique(list_pramugari LP, int id);
adr_pramugari findPramugariByID(list_pramugari LP, int id);
adr_penumpang findPenumpangByID(list_pramugari LP, int id);

#endif // tubes_hpp
