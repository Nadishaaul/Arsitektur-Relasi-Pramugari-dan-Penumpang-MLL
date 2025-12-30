# Laporan Pengembangan Sistem Arsitektur Relasi Pramugari dan Penumpang Menggunakan Multi Linked List

## BAB I – PENDAHULUAN

### 1.1 Latar Belakang

Dalam industri penerbangan, pengelolaan data penumpang dan pramugari merupakan aspek krusial untuk memastikan operasional yang efisien dan aman. Setiap pramugari bertanggung jawab atas sejumlah penumpang, menciptakan relasi one-to-many antara pramugari dan penumpang. Jika relasi data ini tidak terstruktur dengan baik, dapat menyebabkan kesulitan dalam pencarian, pembaruan, dan penghapusan data, serta berpotensi menimbulkan kesalahan dalam pelayanan.

Untuk mengatasi hal tersebut, penggunaan struktur data yang tepat sangat diperlukan. Multi Linked List (MLL) dipilih karena kemampuannya dalam merepresentasikan relasi kompleks antar entitas dengan efisien. MLL memungkinkan penyimpanan data yang terhubung melalui multiple pointer, sehingga cocok untuk menggambarkan hubungan dinamis antara pramugari dan penumpang.

Bahasa pemrograman C++ dipilih karena kekuatannya dalam manipulasi pointer dan struktur data, serta performa tinggi yang dibutuhkan untuk operasi linked list. C++ juga menyediakan kontrol memori yang baik, yang penting untuk implementasi struktur data manual seperti MLL.

### 1.2 Deskripsi Studi Kasus

Studi kasus ini menggambarkan sistem penerbangan sederhana di mana pramugari melayani penumpang. Setiap pramugari dapat melayani multiple penumpang, sementara setiap penumpang dilayani oleh satu pramugari dalam konteks ini. Sistem ini menangani kondisi operasional seperti penambahan pramugari baru, penugasan penumpang ke pramugari tertentu, pemindahan penumpang antar pramugari, serta penghapusan data yang tidak lagi relevan.

### 1.3 Rumusan Masalah

1. Bagaimana merancang relasi antara penumpang dan pramugari menggunakan Multi Linked List?
2. Bagaimana mengimplementasikan Multi Linked List dalam bahasa pemrograman C++ untuk sistem manajemen data penerbangan?
3. Bagaimana memastikan integritas data dan efisiensi operasi dalam struktur relasi tersebut?

### 1.4 Tujuan Penelitian / Pengembangan

Tujuan utama pengembangan sistem ini adalah menciptakan aplikasi yang dapat mengelola relasi antara pramugari dan penumpang secara efisien menggunakan struktur data Multi Linked List. Secara spesifik, sistem ini bertujuan untuk:
- Mengimplementasikan operasi CRUD (Create, Read, Update, Delete) pada data pramugari dan penumpang.
- Mendemonstrasikan penggunaan MLL dalam merepresentasikan relasi one-to-many.
- Menyediakan antarmuka pengguna yang sederhana untuk interaksi dengan sistem.

### 1.5 Manfaat Penelitian

**Manfaat Akademis:**
- Memberikan contoh implementasi praktis struktur data Multi Linked List dalam konteks relasi data.
- Meningkatkan pemahaman tentang penggunaan pointer dan alokasi memori dinamis di C++.

**Manfaat Praktis:**
- Memfasilitasi pengelolaan data penerbangan secara terstruktur dan efisien.
- Mengurangi risiko kesalahan dalam penugasan penumpang ke pramugari.

**Pengembangan Sistem Selanjutnya:**
- Sistem ini dapat dikembangkan lebih lanjut dengan integrasi database dan antarmuka grafis.

### 1.6 Batasan Masalah

- Data disimpan sementara dalam memori (tanpa persistensi ke database).
- Fokus utama pada relasi antara pramugari dan penumpang.
- Tidak mencakup aspek lain seperti sistem tiket, jadwal penerbangan, atau manajemen pesawat.

### 1.7 Struktur Data yang Digunakan

Multi Linked List (MLL) adalah struktur data yang terdiri dari node-node yang saling terhubung melalui multiple pointer. Dalam konteks ini, MLL digunakan untuk merepresentasikan relasi one-to-many antara pramugari (sebagai parent) dan penumpang (sebagai child). Setiap node pramugari memiliki pointer ke node penumpang pertama yang dilayaninya, sementara node penumpang terhubung dalam linked list di bawah pramugari tersebut.

Kelebihan MLL dalam sistem ini adalah fleksibilitas dalam menambah/menghapus relasi tanpa mempengaruhi struktur keseluruhan, serta kemampuan untuk traversal yang efisien dalam mencari data terkait.

## BAB II – LANDASAN TEORI

### 2.1 Konsep Struktur Data

Struktur data adalah cara mengorganisir dan menyimpan data dalam memori komputer sehingga dapat diakses dan dimanipulasi secara efisien. Struktur data memainkan peran penting dalam sistem informasi karena mempengaruhi kompleksitas waktu dan ruang dari algoritma yang digunakan.

### 2.2 Linked List

Linked List adalah struktur data linear di mana elemen-elemen terhubung melalui pointer. Terdapat beberapa jenis:
- **Single Linked List**: Setiap node memiliki satu pointer ke node berikutnya.
- **Double Linked List**: Setiap node memiliki pointer ke node sebelumnya dan berikutnya.
- **Circular Linked List**: Node terakhir menunjuk kembali ke node pertama.

### 2.3 Multi Linked List (MLL)

MLL adalah ekstensi dari linked list di mana node dapat memiliki multiple pointer ke node lain, memungkinkan representasi relasi kompleks. Dalam MLL, node dapat berperan sebagai parent dan child secara bersamaan, cocok untuk merepresentasikan hierarki atau relasi many-to-many.

### 2.4 Konsep Relasi Data

- **Relasi One-to-Many**: Satu entitas dapat berhubungan dengan banyak entitas lain (contoh: satu pramugari melayani banyak penumpang).
- **Relasi Many-to-Many**: Banyak entitas dapat berhubungan dengan banyak entitas lain.
Dalam MLL, relasi diimplementasikan melalui pointer yang menghubungkan node-node terkait.

### 2.5 Bahasa Pemrograman C++

C++ adalah bahasa pemrograman yang mendukung pemrograman berorientasi objek dan prosedural. C++ dipilih karena kemampuannya dalam manipulasi memori langsung melalui pointer, yang essential untuk implementasi linked list. Struktur dasar program C++ meliputi header files, fungsi main, dan penggunaan class/struct untuk mendefinisikan tipe data kustom.

## BAB III – ANALISIS DAN PERANCANGAN SISTEM

### 3.1 Analisis Kebutuhan Sistem

**Kebutuhan Fungsional:**
- Menambah, mengedit, menghapus, dan menampilkan data pramugari.
- Menambah, mengedit, menghapus, dan menampilkan data penumpang.
- Menghubungkan penumpang dengan pramugari tertentu.
- Menampilkan relasi antara pramugari dan penumpang.

**Kebutuhan Non-Fungsional:**
- Antarmuka berbasis teks yang user-friendly.
- Validasi input untuk mencegah kesalahan.
- Efisiensi operasi pada struktur data MLL.

### 3.2 Identifikasi Entitas dan Atribut

- **Entitas Pramugari:**
  - Atribut: ID (unik), Nama, Pointer ke penumpang pertama.

- **Entitas Penumpang:**
  - Atribut: ID (unik), Nama, Pointer ke penumpang berikutnya.

### 3.3 Perancangan Struktur Multi Linked List

- **Node Pramugari:** Struct dengan field id, nama, firstPenumpang (pointer ke node penumpang), nextPramugari.
- **Node Penumpang:** Struct dengan field id, nama, nextPenumpang.
- Relasi: firstPenumpang pada node pramugari menunjuk ke linked list penumpang.

### 3.4 Perancangan Arsitektur Relasi Sistem

Pramugari utama disimpan dalam linked list utama. Setiap pramugari memiliki sub-list penumpang. Operasi relasi meliputi penambahan penumpang ke pramugari, pemindahan penumpang antar pramugari, dan penghapusan relasi.

## BAB IV – IMPLEMENTASI SISTEM

### 4.1 Lingkungan Pengembangan

- Sistem Operasi: Windows 11
- Compiler: MinGW g++ (GCC)
- Tools: Visual Studio Code, Git untuk version control

### 4.2 Implementasi Struktur Data

Struct elmPramugari dan elmPenumpang didefinisikan dengan pointer yang sesuai untuk membentuk MLL.

### 4.3 Implementasi Fitur Sistem

- Tambah pramugari/penumpang
- Hubungkan penumpang dengan pramugari
- Edit dan hapus data
- Tampilkan semua relasi

### 4.4 Penjelasan Kode Program

Program menggunakan file terpisah (main.cpp, tubes.cpp, tubes.hpp) untuk modularitas. Fungsi utama menangani menu dan pemanggilan fungsi operasi MLL.

## BAB V – PENGUJIAN DAN ANALISIS

### 5.1 Metode Pengujian

Pengujian dilakukan secara manual dengan input berbagai skenario untuk memastikan fungsionalitas CRUD dan relasi data.

### 5.2 Hasil Pengujian

Semua fitur berjalan sesuai spesifikasi, dengan validasi input yang robust.

### 5.3 Analisis Hasil

Sistem berhasil mengimplementasikan MLL untuk relasi pramugari-penumpang, dengan performa yang baik untuk dataset kecil hingga menengah.

## BAB VI – PENUTUP

### 6.1 Kesimpulan

Pengembangan sistem arsitektur relasi menggunakan MLL berhasil menunjukkan efektivitas struktur data ini dalam mengelola relasi kompleks. Implementasi di C++ memungkinkan kontrol penuh atas memori dan pointer.

### 6.2 Saran

- Integrasi dengan database untuk persistensi data.
- Pengembangan antarmuka grafis.
- Penambahan fitur seperti pencarian lanjutan dan statistik.