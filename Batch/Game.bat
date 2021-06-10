cd /D %~dp0
cd ../..
"%CD%\UE_4.26\Engine\Binaries\Win64\UE4Editor.exe" "%CD%\Udemy_PuzzlePlatforms\PuzzlePlatforms.uproject" -game -ResX=1280 -ResY=720 -WINDOWED -log
exit