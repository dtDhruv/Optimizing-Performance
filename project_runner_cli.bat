@echo off

cls
rem Run the Python script
python .\ascii.py
pause >nul

:menu
cls
echo **************************************
echo *      Welcome to Need For Speed      *
echo **************************************
echo 1. Run Binary Search Tree vs Hash Table: Insertion and Searching
echo 2. Run Merge Sort (Single-threaded vs Multi-threaded)
echo 3. Run Merge Sort vs Bitonic Sort
echo 4. Run Matrix Multiplication CPU vs GPU
echo 5. Exit

choice /C 12345 /N /M "Select an option:"

if errorlevel 5 goto :exit
if errorlevel 4 goto :run_matrix_mult
if errorlevel 3 goto :run_cudamerge
if errorlevel 2 goto :run_merge_sort
if errorlevel 1 goto :run_bst_hash

:run_cudamerge
cls
type merge_bitonic_sort.txt
pause >nul
cls
echo Running CUDA-Merge-and-Bitonic-Sort...
".\CUDA-Merge-and-Bitonic-Sort\x64\Debug\CUDA-Merge-and-Bitonic-Sort.exe"

echo.
echo Process completed. Press any key to return to the menu.
pause >nul
goto :menu

:run_bst_hash
cls
type hashtable_vs_bst.txt
pause >nul
cls
echo Running BST Search...
".\bst_vs_hash\bst_search.exe"

echo.
echo Press any key to run Hash Search...
pause >nul

echo Running Hash Search...
".\bst_vs_hash\hash_search.exe"

echo.
echo Process completed. Press any key to return to the menu.
pause >nul
goto :menu

:run_merge_sort
cls
type merge_single_multi.txt
pause >nul
cls
echo Running Single-threaded Merge Sort...
echo press ENTER to continue...
pause >nul
".\multiThread_mergeSort\merge_single_out.exe"

echo.
echo Press any key to run Multi-threaded Merge Sort...
pause >nul

echo Running Multi-threaded Merge Sort...
echo press ENTER to continue...
pause >nul
".\multiThread_mergeSort\merge_out.exe"

echo.
echo Process completed. Press any key to return to the menu.
pause >nul
goto :menu

:run_matrix_mult
cls
echo Running Matrix Multiplication...
".\matrixmult\x64\Debug\matrixmult.exe"

echo.
echo Process completed. Press any key to return to the menu.
pause >nul
goto :menu

:exit
echo Exiting...
pause >nul
