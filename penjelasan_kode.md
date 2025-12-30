# Penjelasan Kode Program Arsitektur Relasi Pramugari dan Penumpang

## 1. Struktur File Program
Program ini terdiri dari beberapa file:
- `main.cpp`: Entry point program, menangani menu utama dan pemanggilan fungsi.
- `tubes.hpp`: Header file berisi definisi struct, typedef, dan prototipe fungsi.
- `tubes.cpp`: Implementasi semua fungsi dan fitur program.
- `run.bat`: Script untuk kompilasi dan eksekusi otomatis.
- `README.md`: Dokumentasi program.
- `laporan.md`: Laporan pengembangan.

## 2. Penjelasan main.cpp
File `main.cpp` adalah titik masuk program. Ia menampilkan menu utama dengan 13 fitur, menerima input pengguna, dan memanggil fungsi terkait dari `tubes.cpp`.

### Struktur Utama:
- **Inisialisasi**: Membuat list pramugari kosong menggunakan `createListPramugari(LP)`.
- **Loop Menu**: Menggunakan `while(true)` untuk menampilkan menu berulang hingga pengguna memilih keluar (input 0).
- **Validasi Input**: Memeriksa input integer, menangani error dengan `cin.clear()` dan `cin.ignore()`.
- **Switch Case**: Berdasarkan input, memanggil fungsi fitur yang sesuai.

### Fitur Menu:
- Case 1-13: Memanggil fungsi dari `tubes.cpp` untuk setiap fitur.
- Setiap case diakhiri dengan `cout << endl;` untuk pemisah.

### Proses Jalannya Kode di main.cpp:
1. **Inisialisasi Program**:
   - Deklarasi variabel `list_pramugari LP`.
   - Panggil `createListPramugari(LP)` untuk menginisialisasi list kosong (first dan last = NULL).
   - Tampilkan header program.

2. **Loop Menu Utama**:
   - Masuk `while(true)` loop.
   - Tampilkan menu dengan 13 opsi + keluar.
   - Baca input dari user dengan `cin >> input`.
   - Validasi input:
     - Jika `cin.fail()`, clear error, ignore buffer, tampilkan pesan error, continue.
     - Jika input < 0 atau > 13, tampilkan pesan invalid, continue.
   - Jika input == 0, break loop.
   - Gunakan `switch(input)` untuk memanggil handle function sesuai case.
   - Setiap case tampilkan header fitur, panggil handle function, output hasil, cout endl.

3. **Penutupan Program**:
   - Setelah loop, tampilkan pesan terima kasih.
   - Return 0.

### Algoritma Loop Menu:
```
while true:
    tampilkan menu
    baca input
    if input invalid:
        handle error
        continue
    if input == 0:
        break
    switch input:
        case 1: handleAddPramugari(LP)
        ...
        case 13: handleDeletePenumpangFromPramugari(LP)
    end switch
end while
```

## 3. Penjelasan tubes.hpp
Header file yang mendefinisikan struktur data dan prototipe fungsi untuk program.

### Macro dan Typedef:
- **Macro Akses**: `#define infoPramugari(P) (P)->infoPramugari` - Akses info pramugari dari node.
- `#define infoPenumpang(P) (P)->infoPenumpang` - Akses info penumpang dari node.
- `#define nextPramugari(P) (P)->nextPramugari` - Akses next pointer pramugari.
- `#define nextPenumpang(P) (P)->nextPenumpang` - Akses next pointer penumpang.
- **Typedef Pointer**: `adr_pramugari` untuk pointer ke elmPramugari, `adr_penumpang` untuk pointer ke elmPenumpang.

### Struct Definisi:
- **pramugari**: Berisi `string nama`, `int id`, `adr_penumpang firstPenumpang` (pointer ke sub-list penumpang).
- **penumpang**: Berisi `string nama`, `int id` (pointer pramugari dihapus karena redundant dengan struktur multi linked list).
- **elmPramugari**: Node list utama - `pramugari infoPramugari`, `adr_pramugari nextPramugari`.
- **elmPenumpang**: Node sub-list - `penumpang infoPenumpang`, `adr_penumpang nextPenumpang`.
- **list_pramugari**: List utama - `adr_pramugari first`, `adr_pramugari last`.
- **list_penumpang**: (Tidak digunakan dalam implementasi utama, mungkin untuk ekstensi).

### Prototipe Fungsi:
- **Fungsi Dasar**: `createListPramugari`, `alokasiPramugari`, `alokasiPenumpang`, `insertPramugari`, `addPenumpangToPramugari`, dll.
- **Fungsi CRUD**: Tambah, hapus, cari, edit untuk pramugari dan penumpang.
- **Fungsi Tampilan**: `showAllPramugari`, `showAllPramugariWithPenumpang`, dll.
- **Handler Functions**: `handleAddPramugari`, dll. - Fungsi yang menangani input user dan memanggil core functions.
- **Helper Functions**: `isPramugariIDUnique`, `findPramugariByID`, dll.

### Proses Definisi:
Header ini menggunakan include guard `#ifndef tubes_hpp` untuk mencegah multiple inclusion.
Semua deklarasi di sini memungkinkan kompilasi terpisah antara header dan implementasi.

## 4. Penjelasan tubes.cpp
File ini berisi implementasi semua fungsi, diatur berurutan sesuai fitur untuk memudahkan presentasi.

### Helper Functions Dasar:
- `createListPramugari`: Menginisialisasi list kosong (first dan last = NULL).
- `alokasiPramugari`: Mengalokasikan node pramugari baru dengan `new`, mengisi field, dan set pointer next ke NULL.
- `alokasiPenumpang`: Mirip, untuk node penumpang.
- `insertPramugari`: Menambahkan node pramugari ke list (seperti insert last).
- `addPenumpangToPramugari`: Menambahkan penumpang ke sub-list pramugari tertentu (helper untuk fitur 6).

### Fitur 1: Tambahkan Pramugari (`addNPramugari`)
- **Deskripsi**: Memungkinkan pengguna menambah N pramugari sekaligus.
- **Kode Utama**:
  - Input N dengan validasi (positif, handle error).
  - Loop N kali: Input nama dan ID (unik), alokasi node, insert ke list.
- **Validasi**: ID unik menggunakan `isPramugariIDUnique`.

#### Algoritma:
1. Input jumlah N pramugari yang ingin ditambah.
2. Validasi N > 0, handle input error.
3. Untuk setiap pramugari (i=1 to N):
   - Input nama (string).
   - Input ID (int), validasi unik.
4. Untuk setiap pramugari, alokasi node, insert ke list, output pesan sukses.

#### Pseudocode:
```
function handleAddPramugari(LP):
    while true:
        print "Berapa banyak pramugari?"
        read N
        if N > 0: break
        else: print "Masukkan positif"
    ignore buffer
    for i in 1 to N:
        print "Data ke-", i
        print "Nama: "
        read nama
        while true:
            print "ID: "
            read id
            if isPramugariIDUnique(LP, id): break
            else: print "ID digunakan"
        ignore buffer
        pramugariList.add({nama, id})
    return addNPramugari(LP, pramugariList)

function addNPramugari(LP, list):
    for each p in list:
        newPramugari = alokasiPramugari(p.nama, p.id)
        insertPramugari(LP, newPramugari)
        print "Pramugari", p.nama, "ditambahkan"
    return string output
```

#### Penjelasan Kode handleAddPramugari:
- Loop untuk input N, validasi dengan cin.fail() dan N > 0.
- cin.ignore() untuk handle newline.
- Loop N kali: getline untuk nama, loop untuk ID dengan validasi unik.
- Push ke vector<pair<string,int>>.
- Panggil addNPramugari.

#### Penjelasan Kode addNPramugari:
- Loop vector, alokasi, insert, oss << pesan.
- Return oss.str().

### Fitur 2: Tampilkan Semua Pramugari (`showAllPramugari`)
- **Deskripsi**: Menampilkan daftar semua pramugari dalam format tabel.
- **Kode Utama**:
  - Cek jika list kosong, tampilkan pesan.
  - Traverse list, tampilkan nama dan ID dengan `setw` untuk alignment.

#### Algoritma:
1. Jika LP.first == NULL, tampilkan "List Pramugari Kosong".
2. Jika tidak, tampilkan header tabel.
3. Traverse dari LP.first sampai NULL.
4. Untuk setiap node, tampilkan nama dan ID dengan setw untuk alignment.
5. Tampilkan footer tabel.

#### Pseudocode:
```
function showAllPramugari(LP):
    if LP.first == NULL:
        return "List Kosong"
    else:
        oss << header tabel
        P = LP.first
        while P != NULL:
            oss << "| " << setw(14) << P.nama << " | " << setw(10) << P.id << " |" << endl
            P = P.next
        oss << footer tabel
        return oss.str()
```

#### Penjelasan Kode:
- Gunakan ostringstream untuk build string output.
- setw dari <iomanip> untuk format kolom tetap.
- Traverse sederhana dari first sampai NULL.

### Fitur 3: Hapus Pramugari (`deletePramugariByID`)
- **Deskripsi**: Menghapus pramugari berdasarkan ID, termasuk semua penumpangnya.
- **Kode Utama**:
  - Cari pramugari dengan `findPramugariByID`.
  - Hapus semua penumpang di sub-list dengan loop delete.
  - Hapus node pramugari dari list utama (handle first, middle, last).

#### Algoritma:
1. Cari pramugari dengan ID menggunakan findPramugariByID.
2. Jika tidak ditemukan, return pesan error.
3. Hapus semua penumpang di sub-list: traverse firstPenumpang, delete setiap node.
4. Cari posisi pramugari di list utama: traverse, simpan prev.
5. Hapus dari list: jika first, update first; jika last, update last; else update next prev.
6. Delete node pramugari.
7. Return pesan sukses.

#### Pseudocode:
```
function deletePramugariByID(LP, id):
    P = findPramugariByID(LP, id)
    if P == NULL: return "Tidak ditemukan"
    
    // Hapus penumpang
    Q = P.firstPenumpang
    while Q != NULL:
        temp = Q
        Q = Q.next
        delete temp
    
    // Hapus pramugari
    prev = NULL
    temp = LP.first
    while temp != NULL and temp != P:
        prev = temp
        temp = temp.next
    
    if prev == NULL:
        LP.first = temp.next
        if LP.first == NULL: LP.last = NULL
    else:
        prev.next = temp.next
        if temp.next == NULL: LP.last = prev
    
    delete P
    return "Dihapus"
```

#### Penjelasan Kode:
- findPramugariByID: traverse LP.first sampai id cocok.
- Loop delete penumpang: simpan next, delete current.
- Untuk delete pramugari: handle kasus first, middle, last dengan pointer prev.
- Update first/last jika perlu.

### Fitur 4: Mencari Pramugari (`searchPramugariByID`)
- **Deskripsi**: Mencari dan menampilkan detail pramugari berdasarkan ID.
- **Kode Utama**:
  - Traverse list, jika ID cocok, tampilkan detail dalam box.

### Fitur 5: Edit Pramugari (`editPramugariByID`)
- **Deskripsi**: Mengubah nama dan ID pramugari.
- **Kode Utama**:
  - Cari pramugari, input nama baru dan ID baru (unik).
  - Update field, tampilkan semua data setelah edit.

### Fitur 6: Tambahkan Penumpang (`addNPenumpangToPramugari`)
- **Deskripsi**: Menambah N penumpang ke pramugari tertentu.
- **Kode Utama**:
  - Input ID pramugari, validasi ada.
  - Loop N kali: Input nama dan ID (unik), alokasi, tambah ke sub-list dengan `addPenumpangToPramugari`.
  - Hitung dan tampilkan jumlah penumpang akhir.

### Fitur 7: Mencari Penumpang (`searchPenumpangByID`)
- **Deskripsi**: Mencari penumpang berdasarkan ID, tampilkan detail dan pramugari yang melayani.
- **Kode Utama**:
  - Nested loop: Traverse pramugari dan penumpangnya.
  - Jika ditemukan, tampilkan detail dengan flag `found`.

### Fitur 8: Edit Penumpang (`editPenumpangByID`)
- **Deskripsi**: Mengubah data penumpang, opsi pindah pramugari.
- **Kode Utama**:
  - Cari penumpang, update nama dan ID.
  - Jika pilih pindah: Hapus dari pramugari asal, tambah ke baru (mirip fitur 9).

### Fitur 9: Hubungkan Pramugari dengan Penumpang (`connectPenumpangAndPramugari`)
- **Deskripsi**: Memindahkan penumpang dari pramugari asal ke baru.
- **Kode Utama**:
  - Cari penumpang dan pramugari baru.
  - Jika asal berbeda: Hapus dari sub-list asal (reset next pointer).
  - Tambah ke sub-list baru.

### Fitur 10: Tampilkan Semua Data (`showAllPramugariWithPenumpang`)
- **Deskripsi**: Menampilkan semua pramugari dan penumpangnya dalam format terstruktur.
- **Kode Utama**:
  - Traverse list pramugari, untuk setiap: Tampilkan detail, lalu traverse sub-list penumpang.

### Fitur 11: Pramugari Terbanyak Penumpang (`displayPramugariWithMostPenumpang`)
- **Deskripsi**: Menemukan dan menampilkan pramugari dengan penumpang terbanyak.
- **Kode Utama**:
  - Traverse semua pramugari, hitung penumpang per pramugari.
  - Track max count dan pointer, tampilkan hasil.

### Fitur 12: Cari Penumpang di Pramugari (`findPenumpangInPramugari`)
- **Deskripsi**: Menampilkan semua penumpang dari pramugari tertentu.
- **Kode Utama**:
  - Cari pramugari, traverse sub-list penumpang, tampilkan.

### Fitur 13: Hapus Penumpang di Pramugari (`deletePenumpangFromPramugari`)
- **Deskripsi**: Menghapus penumpang spesifik dari pramugari.
- **Kode Utama**:
  - Cari pramugari, traverse sub-list, hapus node (handle first, middle, last), delete memori.

#### Algoritma (Mirip delete pramugari, tapi di sub-list):
1. Cari pramugari by ID.
2. Jika ditemukan, traverse sub-list, simpan prev.
3. Jika ditemukan penumpang, hapus: update next prev, delete node.
4. Handle first, middle, last di sub-list.

#### Pseudocode:
```
function deletePenumpangFromPramugari(LP, idPramugari, idPenumpang):
    P = LP.first
    while P != NULL and P.id != idPramugari:
        P = P.next
    if P == NULL: return "Pramugari tidak ditemukan"
    
    Q = P.firstPenumpang
    prev = NULL
    while Q != NULL and Q.id != idPenumpang:
        prev = Q
        Q = Q.next
    if Q == NULL: return "Penumpang tidak ditemukan"
    
    if prev == NULL:
        P.firstPenumpang = Q.next
    else:
        prev.next = Q.next
    delete Q
    return "Dihapus"
```

### Catatan untuk Fitur Lain:
Fitur 4-12 mengikuti pola serupa: cari, traverse, update, validasi. Misalnya:
- Fitur 4: Traverse list, if id match, tampilkan.
- Fitur 5: Cari, update field, tampilkan all.
- Fitur 6: Cari pramugari, loop add penumpang, hitung.
- Fitur 7: Nested traverse pramugari dan penumpang.
- Fitur 8: Cari penumpang, update, optional pindah (hapus dari asal, add ke baru).
- Fitur 9: Mirip 8, tapi tanpa update data.
- Fitur 10: Traverse all, tampilkan nested.
- Fitur 11: Traverse, count max.
- Fitur 12: Cari pramugari, tampilkan sub-list.

Semua menggunakan traversal linear, kompleksitas O(n) atau O(n*m) untuk nested.

### Helper Functions Tambahan:
- `isPramugariIDUnique` / `isPenumpangIDUnique`: Cek unik ID dengan traverse.
- `findPramugariByID`: Return pointer pramugari berdasarkan ID.
- `findPenumpangByID`: Return pointer penumpang berdasarkan ID (untuk operasi internal).

## 5. Detail Proses Jalannya Kode untuk Setiap Fitur

### Helper Functions Dasar

#### createListPramugari
- **Deskripsi**: Inisialisasi list pramugari kosong.
- **Kode**:
  ```
  void createListPramugari(list_pramugari &LP) {
      LP.first = NULL;
      LP.last = NULL;
  }
  ```
- **Proses**: Set first dan last pointer ke NULL, menandakan list kosong.

#### alokasiPramugari
- **Deskripsi**: Alokasi memori untuk node pramugari baru.
- **Kode**:
  ```
  adr_pramugari alokasiPramugari(string nama, int id) {
      adr_pramugari newPramugari = new elmPramugari;
      infoPramugari(newPramugari).nama = nama;
      infoPramugari(newPramugari).id = id;
      infoPramugari(newPramugari).firstPenumpang = NULL;
      nextPramugari(newPramugari) = NULL;
      return newPramugari;
  }
  ```
- **Proses**:
  1. Alokasi memori dengan `new elmPramugari`.
  2. Isi field nama dan id dari parameter.
  3. Set firstPenumpang ke NULL (sub-list kosong).
  4. Set nextPramugari ke NULL.
  5. Return pointer ke node baru.

#### alokasiPenumpang
- **Mirip alokasiPramugari**, tapi untuk elmPenumpang, tanpa firstPenumpang.

#### insertPramugari
- **Deskripsi**: Insert node pramugari ke akhir list (insert last).
- **Kode**:
  ```
  void insertPramugari(list_pramugari &LP, adr_pramugari newPramugari) {
      if (LP.first == NULL) {
          LP.first = newPramugari;
          LP.last = newPramugari;
      } else {
          nextPramugari(LP.last) = newPramugari;
          LP.last = newPramugari;
      }
  }
  ```
- **Proses**:
  1. Jika list kosong (first == NULL), set first dan last ke newPramugari.
  2. Jika tidak, set next dari last ke newPramugari, update last ke newPramugari.

#### addPenumpangToPramugari
- **Deskripsi**: Tambah penumpang ke sub-list pramugari tertentu (insert last di sub-list).
- **Kode**:
  ```
  void addPenumpangToPramugari(list_pramugari &LP, int idPramugari, adr_penumpang newPenumpang) {
      adr_pramugari P = LP.first;
      while (P != NULL && infoPramugari(P).id != idPramugari) {
          P = nextPramugari(P);
      }
      if (P != NULL) {
          if (infoPramugari(P).firstPenumpang == NULL) {
              infoPramugari(P).firstPenumpang = newPenumpang;
          } else {
              adr_penumpang Q = infoPramugari(P).firstPenumpang;
              while (nextPenumpang(Q) != NULL) {
                  Q = nextPenumpang(Q);
              }
              nextPenumpang(Q) = newPenumpang;
          }
      }
  }
  ```
- **Proses**:
  1. Traverse list pramugari sampai menemukan idPramugari.
  2. Jika ditemukan, cek jika sub-list kosong.
  3. Jika kosong, set firstPenumpang ke newPenumpang.
  4. Jika tidak, traverse sub-list sampai akhir, set next dari last ke newPenumpang.

## 6. Kesimpulan
Program ini berhasil mengimplementasikan sistem manajemen relasi pramugari dan penumpang menggunakan struktur data Multi Linked List, di mana list utama pramugari memiliki sub-list penumpang.

### Keunggulan Implementasi:
- **Modularitas**: Fungsi-fungsi terpisah, mudah di-maintain dan di-extend.
- **Validasi Input**: Handling error untuk input invalid, unik ID, dll.
- **Error Handling**: Cin.clear dan ignore untuk input non-integer.
- **Format Output**: Menggunakan ostringstream dan setw untuk tampilan tabel yang rapi.
- **Memory Management**: Alokasi dengan new, de-alokasi dengan delete untuk mencegah leak.

### Kompleksitas Algoritma:
- Operasi dasar (insert, delete, search): O(n) untuk list utama, O(m) untuk sub-list.
- Operasi nested (cari penumpang): O(n*m).
- Cocok untuk dataset kecil hingga menengah.

### Proses Keseluruhan Program:
1. Inisialisasi struktur data.
2. Loop interaktif menu-driven.
3. Input handling dan validasi.
4. Eksekusi operasi pada linked list.
5. Output hasil ke console.
6. Cleanup memori otomatis saat exit (C++ destructor).

Kode ini mendemonstrasikan penerapan konsep struktur data dalam konteks aplikasi nyata, dengan fokus pada relasi one-to-many antara pramugari dan penumpang.