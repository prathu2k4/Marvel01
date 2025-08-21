@echo off
REM === Create folders and README.md in each ===

setlocal enabledelayedexpansion

REM List of folder names
set folders=^
1-3D-Printing^
2-API-Project^
3-GitHub-Workflows^
4-Ubuntu-Command-Line^
5-Kaggle-Titanic-ML-Contest^
6-Pandas-Matplotlib^
7-Portfolio-Webpage^
8-Markdown-Resource-Article^
9-Tinkercad-Circuit^
10-DC-Motor-Speed-Control^
11-LED-Toggle-Using-ESP32^
12-Soldering-Prerequisites^
13-555-Timer-Multivibrator^
14-Karnaugh-Map-Logic-Circuit^
15-Active-Participation^
16-Datasheet-Report^
17-Introduction-to-VR^
18-Sad-Servers-Linux-Troubleshooting^
19-Web-App-Resource-Library

for %%f in (%folders%) do (
    echo Creating folder: %%f
    mkdir "%%f" 2>nul
    echo # %%f > "%%f\README.md"
)

echo.
echo === All folders with README.md created successfully! ===
pause
