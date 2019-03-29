cd .
mex -Llib\x64\vc12 -lqhyccd -outdir output\x64  -Iinclude -ULINUX -DWIN32 src\qhyccdmex.cpp
cd 'output\x64';
ImgDat = qhyccdmex;
imshow(ImgDat);
clear qhyccdmex;
cd ..\..