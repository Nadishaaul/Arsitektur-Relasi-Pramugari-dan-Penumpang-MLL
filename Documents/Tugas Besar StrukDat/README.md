# Arsitektur Relasi Pramugari dan Penumpang

## Deskripsi Program
Program ini adalah arsitektur relasi untuk mengelola data pramugari dan penumpang pada suatu maskapai penerbangan. Menggunakan struktur data linked list untuk menyimpan data pramugari dan penumpang yang terhubung.

## Struktur Data
- **Pramugari**: Tersimpan dalam linked list utama, setiap pramugari memiliki daftar penumpang yang dilayaninya.
- **Penumpang**: Tersimpan sebagai sub-list di bawah setiap pramugari.
- ID pramugari dan penumpang harus unik di seluruh sistem.

## Fitur Utama

### 1. Tambahkan Pramugari
- Menambah satu atau lebih pramugari baru.
- Input: Nama dan ID unik.
- Output: Konfirmasi penambahan.

### 2. Tampilkan Semua Pramugari
- Menampilkan daftar semua pramugari dengan ID mereka.
- Output: Tabel nama dan ID pramugari.

### 3. Hapus Pramugari
- Menghapus pramugari berdasarkan ID.
- Juga menghapus semua penumpang yang terkait.
- Output: Konfirmasi penghapusan.

### 4. Cari Pramugari
- Mencari pramugari berdasarkan ID.
- Output: Detail pramugari atau pesan tidak ditemukan.

### 5. Edit Pramugari
- Mengubah nama dan ID pramugari.
- ID baru harus unik.
- Output: Konfirmasi perubahan dan tampilan data terbaru.

### 6. Tambahkan Penumpang
- Menambah satu atau lebih penumpang ke pramugari tertentu.
- Input: ID pramugari, nama penumpang, ID unik penumpang.
- Output: Konfirmasi penambahan dan jumlah penumpang pramugari.

### 7. Cari Penumpang
- Mencari penumpang berdasarkan ID.
- Output: Detail penumpang dan pramugari yang melayani.

### 8. Edit Penumpang
- Mengubah nama dan ID penumpang.
- Opsi untuk memindahkan ke pramugari lain.
- Output: Konfirmasi perubahan.

### 9. Hubungkan Pramugari dengan Penumpang
- Memindahkan penumpang dari satu pramugari ke pramugari lain.
- Input: ID penumpang dan ID pramugari baru.
- Output: Konfirmasi pemindahan.

### 10. Tampilkan Semua Data
- Menampilkan semua pramugari beserta penumpang mereka.
- Output: Format tabel terstruktur.

### 11. Pramugari dengan Penumpang Terbanyak
- Menampilkan pramugari yang melayani penumpang terbanyak.
- Output: Nama, ID, dan jumlah penumpang.

### 12. Cari Penumpang di Pramugari
- Menampilkan semua penumpang dari pramugari tertentu.
- Input: ID pramugari.
- Output: Daftar penumpang atau pesan kosong.

### 13. Hapus Penumpang dari Pramugari
- Menghapus penumpang tertentu dari pramugari.
- Input: ID pramugari dan ID penumpang.
- Output: Konfirmasi penghapusan.

### 0. Keluar
- Menutup program.

## Cara Menjalankan
1. Pastikan compiler g++ (MinGW) terinstall.
2. Jalankan `.\run.bat` dari Command Prompt atau PowerShell.
3. Program akan mengkompilasi otomatis dan menjalankan.

## Optimasi yang Diterapkan
- Validasi ID unik untuk mencegah duplikasi.
- Fungsi helper untuk pencarian guna mengurangi duplikasi kode.
- Penanganan error input yang robust.
- Pembersihan memori otomatis.

## File Program
- `main.cpp`: Entry point dan menu utama.
- `tubes.hpp`: Header dengan definisi struct dan prototipe fungsi.
- `tubes.cpp`: Implementasi semua fungsi.
- `run.bat`: Script untuk kompilasi dan eksekusi.
- `run.ps1`: Alternatif script PowerShell.

## Penjelasan File Eksekusi dan Script
Program ini menggunakan beberapa file executable dan script untuk memfasilitasi proses kompilasi dan eksekusi yang efisien. Berikut adalah penjelasan detail mengapa file-file tersebut digunakan:

### `run.bat`
- **Fungsi**: Script batch (Windows) yang mengotomatisasi proses kompilasi dan eksekusi program.
- **Cara Kerja**:
  - Mengkompilasi file sumber (`main.cpp` dan `tubes.cpp`) menggunakan compiler g++ menjadi executable sementara bernama `temp_program.exe`.
  - Memeriksa apakah kompilasi berhasil; jika gagal, menampilkan pesan error dan berhenti.
  - Menjalankan `temp_program.exe` jika kompilasi berhasil.
  - Setelah program selesai dijalankan, menghapus `temp_program.exe` untuk membersihkan direktori.
- **Alasan Penggunaan**: Memungkinkan pengguna menjalankan program dengan satu perintah tanpa perlu mengetik perintah kompilasi manual. Script ini juga memastikan bahwa executable sementara tidak meninggalkan jejak permanen di direktori proyek, menjaga kebersihan workspace.

### `temp_program.exe`
- **Fungsi**: File executable sementara yang dihasilkan oleh `run.bat` selama proses kompilasi.
- **Cara Kerja**: Dibuat oleh compiler g++ dari kode sumber, kemudian dieksekusi oleh `run.bat`, dan dihapus secara otomatis setelah program berakhir.
- **Alasan Penggunaan**: Digunakan sebagai executable intermediate untuk menghindari konflik dengan file executable permanen lainnya. Dengan menggunakan file sementara, program dapat dijalankan tanpa risiko overwriting file executable utama, dan memungkinkan kompilasi ulang setiap kali script dijalankan tanpa perlu menghapus file manual.

### `program.exe`
- **Fungsi**: File executable permanen yang dikompilasi secara manual dari kode sumber.
- **Cara Kerja**: Dapat dijalankan langsung tanpa perlu kompilasi ulang setiap kali.
- **Alasan Penggunaan**: Menyediakan versi executable yang stabil untuk pengguna yang ingin menjalankan program tanpa melalui proses kompilasi. Berguna untuk distribusi atau testing cepat tanpa script otomatis.

### `program_updated.exe`
- **Fungsi**: File executable permanen yang merupakan versi terbaru atau diperbarui dari program.
- **Cara Kerja**: Mirip dengan `program.exe`, tetapi mungkin berisi perubahan kode terbaru atau optimasi.
- **Alasan Penggunaan**: Digunakan untuk menyimpan versi executable yang telah diperbarui, memungkinkan perbandingan antara versi lama (`program.exe`) dan versi baru. Hal ini berguna dalam pengembangan untuk testing perubahan tanpa mengganggu versi stabil sebelumnya.

## Keunggulan Pendekatan Kompilasi dan Eksekusi
Pendekatan yang digunakan dalam program ini, terutama melalui `run.bat`, menawarkan beberapa keunggulan dalam pengembangan dan penggunaan:

- **Otomatisasi Proses**: Dengan menjalankan `run.bat`, pengguna tidak perlu mengetik perintah kompilasi manual (`g++ main.cpp tubes.cpp -o temp_program.exe`) setiap kali. Script mengotomatisasi seluruh proses, mengurangi kesalahan manusia dan mempercepat workflow.
- **Kompilasi Ulang Otomatis**: Jika kode sumber diubah (misalnya, mengedit `main.cpp`, `tubes.cpp`, atau `tubes.hpp`), menjalankan `run.bat` lagi akan secara otomatis mengkompilasi versi terbaru menjadi `temp_program.exe` baru. Tidak perlu menambahkan atau mengelola file compiler tambahan; script menangani semuanya.
- **Pembersihan Otomatis**: Penggunaan `temp_program.exe` sebagai file sementara memastikan bahwa direktori proyek tetap bersih. File executable sementara dihapus setelah eksekusi, menghindari akumulasi file yang tidak perlu.
- **Fleksibilitas untuk Pengembangan**: File executable permanen seperti `program.exe` dan `program_updated.exe` memungkinkan testing cepat atau distribusi tanpa kompilasi ulang, sementara script menyediakan cara cepat untuk menjalankan versi terbaru selama pengembangan.
- **Portabilitas**: Script ini kompatibel dengan lingkungan Windows yang memiliki MinGW, memudahkan pengguna lain untuk menjalankan program tanpa setup compiler manual.
- **Error Handling**: Script memeriksa kesalahan kompilasi dan memberikan feedback jelas, mencegah eksekusi program yang rusak.

Pendekatan ini membuat pengembangan lebih efisien, terutama untuk proyek yang sering diubah, dengan meminimalkan langkah-langkah manual dan memaksimalkan keamanan serta kebersihan kode.

## Contoh Output
```
+---------------------------------------------------------------+
| SELAMAT DATANG DI ARSITEKTUR RELASI PRAMUGARI DAN PENUMPANG |
+---------------------------------------------------------------+

+-------------------------------------------------+
|                MENU UTAMA                       |
+-------------------------------------------------+
| 1.  Tambahkan Pramugari                         |
| 2.  Tampilkan semua Pramugari                   |
...
Masukkan Pilihan Menu: 1

+-----------------------------+
|     Tambahkan Pramugari     |
+-----------------------------+
Berapa banyak pramugari yang ingin ditambahkan? 1
Data Pramugari ke-1
Nama Pramugari: Alice
ID Pramugari: 101
Pramugari Alice telah ditambahkan.
```

Program ini memastikan data integrity dan user experience yang baik dengan validasi input dan pesan error yang jelas.