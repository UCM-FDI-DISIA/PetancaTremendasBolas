@echo off

set WORKDIR=.\bin
set ENGINEBIN=.\Dependencies\FORGE\FORGE\bin

echo Fin de la actualizacion de submodulos

cd Dependencies\FORGE\FORGE
call BuildFORGEAlways.bat
cd ..\..\..

xcopy /y "%ENGINEBIN%\*.dll" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\plugins.cfg" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE.exe" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE_d.exe" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\gamecontrollerdb.txt" "%WORKDIR%"

msbuild UxiaANecoraDeMontealto.sln /p:Configuration=Debug /p:Platform=x64
msbuild UxiaANecoraDeMontealto.sln /p:Configuration=Release /p:Platform=x64