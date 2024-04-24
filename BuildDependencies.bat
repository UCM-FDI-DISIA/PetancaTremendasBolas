@echo off

set WORKDIR=.\bin
set ENGINEBIN=.\Dependencies\FORGE\FORGE\bin

git submodule update --init --recursive

echo Fin de la actualizacion de submodulos

cd Dependencies\FORGE\FORGE
call BuildFORGE.bat
cd ..\..\..

xcopy /y "%ENGINEBIN%\*.dll" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\plugins.cfg" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE.exe" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE_d.exe" "%WORKDIR%"

pause