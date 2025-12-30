# Penjelasan Lengkap run.bat, program_updated.exe, dan program.exe

## 1. run.bat - Script Kompilasi dan Eksekusi

`run.bat` adalah file batch script untuk sistem operasi Windows yang digunakan untuk mengkompilasi dan menjalankan program C++ secara otomatis.

### Struktur Kode:

```batch
@echo off
taskkill /f /im temp_program.exe >nul 2>&1
del temp_program.exe 2>nul
echo Compiling program...
g++ main.cpp tubes.cpp -o temp_program.exe
if %errorlevel% neq 0 (
    echo Compilation failed. Please check for errors.
    pause
    exit /b 1
)
echo Running program...
temp_program.exe
echo Program finished.
del temp_program.exe
pause
```

### Penjelasan Baris per Baris:

1. `@echo off`: Menonaktifkan echo command, sehingga hanya output yang diinginkan yang ditampilkan.

2. `taskkill /f /im temp_program.exe >nul 2>&1`: Memaksa menghentikan proses `temp_program.exe` jika masih berjalan (cleanup dari eksekusi sebelumnya). `>nul 2>&1` mengarahkan output dan error ke null (silent).

3. `del temp_program.exe 2>nul`: Menghapus file executable lama jika ada, `2>nul` menyembunyikan error jika file tidak ada.

4. `echo Compiling program...`: Menampilkan pesan bahwa kompilasi sedang berlangsung.

5. `g++ main.cpp tubes.cpp -o temp_program.exe`: Mengkompilasi `main.cpp` dan `tubes.cpp` menjadi executable `temp_program.exe` menggunakan compiler g++ (dari MinGW atau GCC).

6-10. `if %errorlevel% neq 0 (...)`: Mengecek jika kompilasi gagal (`errorlevel` != 0). Jika ya, tampilkan pesan error, pause untuk user melihat, exit dengan kode 1.

11. `echo Running program...`: Pesan bahwa program akan dijalankan.

12. `temp_program.exe`: Menjalankan executable yang baru dikompilasi.

13. `echo Program finished.`: Pesan bahwa program selesai.

14. `del temp_program.exe`: Menghapus executable temporary setelah selesai.

15. `pause`: Menjeda command prompt agar user dapat melihat output sebelum window tertutup.

### Proses Jalannya Script:

1. **Cleanup**: Hentikan dan hapus executable lama.
2. **Kompilasi**: Compile source code menjadi executable.
3. **Error Check**: Jika kompilasi gagal, tampilkan error dan stop.
4. **Eksekusi**: Jalankan program.
5. **Cleanup**: Hapus executable temporary.
6. **Exit**: Tunggu user tekan key untuk close.

### Keuntungan:
- Otomatisasi kompilasi dan eksekusi.
- Cleanup otomatis untuk menghindari konflik.
- Error handling sederhana.

## 2. program_updated.exe dan program.exe - Executable Program

`program.exe` dan `program_updated.exe` adalah file executable hasil kompilasi dari kode C++ (main.cpp, tubes.cpp, tubes.hpp).

### Bagaimana Mereka Dibuat:

1. **Kompilasi**: Menggunakan compiler C++ seperti g++:
   ```
   g++ main.cpp tubes.cpp -o program.exe
   ```
   - `main.cpp`: Entry point.
   - `tubes.cpp`: Implementasi fungsi.
   - `-o program.exe`: Output file executable.

2. **Dependencies**: Membutuhkan header `tubes.hpp` yang di-include.

3. **Library**: Menggunakan standard library C++ (iostream, string, vector, dll.), tidak ada external library.

### Struktur Internal (Konseptual):

Executable berisi:
- **Machine Code**: Instruksi binary yang dieksekusi oleh CPU.
- **Data Section**: String literals, constants.
- **BSS Section**: Uninitialized data.
- **Symbol Table**: Referensi ke fungsi dan variabel (untuk debugging).
- **Entry Point**: Fungsi main().

### Proses Jalannya Saat Dijalankan:

1. **Loader**: OS memuat executable ke memory.
2. **Initialization**: Setup heap, stack, global variables.
3. **Entry**: Panggil main().
4. **Execution**: Jalankan kode program (inisialisasi list, loop menu, dll.).
5. **Termination**: Return 0, cleanup memory, exit.

### Perbedaan program.exe dan program_updated.exe:

- **program.exe**: Versi lama atau asli.
- **program_updated.exe**: Versi terbaru setelah update kode.

Keduanya hasil kompilasi dari source code yang sama, tapi mungkin `program_updated.exe` dari versi kode yang lebih baru.

### Cara Menjalankan:

- Double-click file .exe di Windows.
- Atau via command line: `program.exe`
- Membutuhkan terminal/console untuk input/output.

### Dependencies Runtime:

- Windows OS (karena compiled untuk Windows).
- Tidak ada external DLL kecuali standard Windows libraries.

### Debugging:

Jika ada error, gunakan debugger seperti gdb (untuk MinGW) atau Visual Studio debugger.

### Keamanan:

- Executable bisa di-scan antivirus.
- Tidak mengandung malware (asumsi dari source code bersih).

## 3. autopush.ps1 dan autopush.sh - Fitur Auto Push ke GitHub

`autopush.ps1` adalah script PowerShell untuk Windows yang secara otomatis melakukan commit dan push perubahan kode ke repository GitHub.

`autopush.sh` adalah versi Bash script untuk sistem Unix/Linux atau Git Bash di Windows.

### Struktur Kode:

```powershell
param(
    [string]$CommitMessage = "Auto commit from PowerShell script"
)

# Check if git is installed
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Git is not installed. Please install Git first." -ForegroundColor Red
    exit 1
}

# Check if this is a git repository
if (-not (Test-Path ".git")) {
    Write-Host "This is not a Git repository. Please initialize Git first." -ForegroundColor Red
    exit 1
}

# Check git status
$status = git status --porcelain
if ($status -eq $null -or $status -eq "") {
    Write-Host "No changes to commit." -ForegroundColor Yellow
    exit 0
}

# Add all changes
Write-Host "Adding changes..." -ForegroundColor Green
git add .

# Commit changes
Write-Host "Committing changes..." -ForegroundColor Green
git commit -m $CommitMessage

# Check if commit was successful
if ($LASTEXITCODE -ne 0) {
    Write-Host "Commit failed. Please check for errors." -ForegroundColor Red
    exit 1
}

# Push to remote
Write-Host "Pushing to GitHub..." -ForegroundColor Green
git push

# Check if push was successful
if ($LASTEXITCODE -ne 0) {
    Write-Host "Push failed. Please check your remote configuration and network." -ForegroundColor Red
    exit 1
}

Write-Host "Successfully pushed to GitHub!" -ForegroundColor Green
```

### Penjelasan Baris per Baris:

1. `param([string]$CommitMessage = "Auto commit from PowerShell script")`: Parameter opsional untuk pesan commit, default "Auto commit...".

2-5. **Check Git Installation**: Verifikasi jika Git terinstall, exit jika tidak.

6-9. **Check Git Repository**: Pastikan folder ini adalah git repo (.git folder ada).

10-13. **Check Changes**: Gunakan `git status --porcelain` untuk cek ada perubahan. Jika tidak ada, exit.

14-15. **Add Changes**: `git add .` untuk stage semua perubahan.

16-17. **Commit**: `git commit -m $CommitMessage` dengan pesan yang diberikan.

18-22. **Commit Check**: Jika commit gagal, tampilkan error.

23-24. **Push**: `git push` ke remote repository.

25-29. **Push Check**: Jika push gagal, tampilkan error.

30. **Success Message**: Jika semua berhasil.

### Cara Penggunaan:

1. **Setup Git**: Pastikan repository Git sudah diinisialisasi dan remote GitHub sudah dikonfigurasi.
   ```
   git init
   git remote add origin https://github.com/username/repo.git
   ```

2. **Jalankan Script**:
   - Default: `.\autopush.ps1`
   - Custom message: `.\autopush.ps1 -CommitMessage "Updated code"`

3. **Execution Policy**: Jika PowerShell block script, jalankan:
   ```
   Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
   ```

### Proses Jalannya Script:

1. **Validasi**: Cek Git dan repo.
2. **Status Check**: Lihat ada perubahan.
3. **Stage**: Add semua file.
4. **Commit**: Buat commit dengan pesan.
5. **Push**: Upload ke GitHub.
6. **Feedback**: Tampilkan status.

### Keuntungan:

- Otomatisasi workflow Git.
- Error handling untuk berbagai skenario.
- Custom commit message.
- Integrasi dengan development process.

### Cara Penggunaan autopush.sh:

1. **Di Linux/Unix atau Git Bash di Windows:**
   - Jalankan: `./autopush.sh`
   - Dengan custom message: `./autopush.sh "Your commit message"`

2. **Di Windows CMD (jika bash tersedia):**
   - `bash autopush.sh`
   - `bash autopush.sh "Custom message"`

### Prerequisites untuk autopush.sh:

- Bash shell (tersedia di Linux, macOS, atau Git Bash di Windows).
- Git terinstall.
- Repository Git dengan remote GitHub (sudah di-setup).

### Prerequisites untuk autopush.ps1:

- Git terinstall.
- Repository Git dengan remote GitHub (sudah di-setup ke https://github.com/Nadishaaul/Arsitektur-Relasi-Pramugari-dan-Penumpang-MLL.git).
- PowerShell execution policy allow scripts (gunakan -ExecutionPolicy Bypass saat run).

## 4. Kesimpulan

- `run.bat`: Script otomatisasi kompilasi dan eksekusi.
- `program.exe` & `program_updated.exe`: Executable hasil kompilasi.
- `autopush.ps1`: Script auto-push ke GitHub.
- Workflow lengkap: Code -> Compile -> Run -> Push to GitHub.