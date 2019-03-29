cd .
mex -Llib\x86\vc12 -lqhyccd -outdir output\x86  -Iinclude -ULINUX -DWIN32 src\qhyccdmex.cpp
cd 'output\x86';
ImgDat = qhyccdmex;
imshow(ImgDat);
clear qhyccdmex;
cd ..\..