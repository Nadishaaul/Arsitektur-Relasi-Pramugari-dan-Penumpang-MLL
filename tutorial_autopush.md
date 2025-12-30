# Tutorial Menjalankan autopush.sh

## Pendahuluan
`autopush.sh` adalah script Bash yang secara otomatis melakukan commit dan push perubahan kode ke GitHub. Tutorial ini menjelaskan cara menjalankannya di Windows menggunakan Git Bash atau Command Prompt.

## Prerequisites
1. **Git terinstall**: Download dari https://git-scm.com/downloads
2. **Repository Git**: Pastikan folder proyek sudah diinisialisasi sebagai Git repo
3. **Remote GitHub**: Remote origin sudah dikonfigurasi
4. **Bash shell**: Git Bash (terinstall dengan Git) atau WSL

## Metode 1: Menggunakan Git Bash (Direkomendasikan)

### Langkah 1: Buka Git Bash
1. Klik kanan di folder proyek (`Tugas Besar StrukDat`)
2. Pilih "Git Bash Here" atau "Open Git Bash here"
3. Terminal Git Bash akan terbuka

### Langkah 2: Navigasi ke Folder Proyek
```bash
cd "c:/Users/asus/Documents/Tugas Besar StrukDat"
```
Atau jika sudah di folder yang benar, lanjut ke langkah 3.

### Langkah 3: Beri Permission Execute ke Script (Opsional di Windows)
**Di Linux/Unix:**
```bash
chmod +x autopush.sh
```

**Di Windows (Git Bash):** Tidak perlu chmod, langsung lanjut ke langkah 4.

### Langkah 4: Jalankan Script
**Default commit message:**
```bash
./autopush.sh
```

**Custom commit message:**
```bash
./autopush.sh "Update fitur baru"
```

**Multiple words:**
```bash
./autopush.sh "Fix bug di fungsi search"
```

### Langkah 5: Lihat Output
Script akan menampilkan:
```
Adding changes...
Committing changes...
Commit successful.
Pushing to GitHub...
Successfully pushed to GitHub!
```

## Metode 2: Menggunakan Command Prompt (CMD) dengan Bash

### Langkah 1: Buka Command Prompt
1. Tekan Win + R
2. Ketik `cmd`
3. Enter

### Langkah 2: Navigasi ke Folder Proyek
```cmd
cd "c:\Users\asus\Documents\Tugas Besar StrukDat"
```

### Langkah 3: Jalankan dengan bash
**Default:**
```cmd
bash autopush.sh
```

**Custom message:**
```cmd
bash autopush.sh "Update dokumentasi"
```

## Metode 3: Menggunakan PowerShell (Alternatif)

Jika bash tidak tersedia, gunakan PowerShell script:
```powershell
powershell -ExecutionPolicy Bypass -File autopush.ps1
```

## Troubleshooting

### Error: "bash: ./autopush.sh: Permission denied"
**Solusi di Linux/Unix:**
```bash
chmod +x autopush.sh
```

**Di Windows:** Permission denied jarang terjadi di Git Bash. Jika terjadi, coba:
- Jalankan Git Bash as Administrator
- Atau gunakan PowerShell script sebagai alternatif

### Error: "bash: autopush.sh: command not found"
**Solusi:** Pastikan di folder yang benar dan script ada.

### Error: "fatal: not a git repository"
**Solusi:** Inisialisasi Git repo:
```bash
git init
git remote add origin https://github.com/username/repo.git
```

### Error: "fatal: The current branch master has no upstream branch"
**Solusi:** Set upstream:
```bash
git push --set-upstream origin master
```

## Contoh Lengkap

### Skenario: Update kode dan push
1. Edit file (misal main.cpp)
2. Simpan perubahan
3. Buka Git Bash
4. Jalankan:
   ```bash
   ./autopush.sh "Update main.cpp dengan fitur baru"
   ```
5. Lihat output sukses

## Tips
- Selalu cek status dengan `git status` sebelum push
- Gunakan commit message yang deskriptif
- Jika ada konflik, resolve manual dulu
- Backup kode penting sebelum push

## File yang Dibutuhkan
- `autopush.sh` (sudah ada di folder proyek)
- Git terinstall
- Repository GitHub dengan akses write