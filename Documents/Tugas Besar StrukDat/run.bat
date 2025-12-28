@echo off
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