cd /D %~dp0
cd ../..
"%CD%\UE_4.26\Engine\Binaries\Win64\UE4Editor.exe" "%CD%\Udemy_PuzzlePlatforms\PuzzlePlatforms.uproject" /Game/PuzzlePlatforms/Maps/Lobby -server -log
exit