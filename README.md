# 42_FDF

This project is about basic computer graphic drawing with c.</br>
The library used for the graphic is provided by my school which is base from X.11</br>
</br>
The program will read the file with the content from the following format:</br>
</br>
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0</br>
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0</br>
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0</br>
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0</br>
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0</br>
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0</br>
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0</br>
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0</br>
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0</br>
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0</br>
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0</br>
</br>
and the program with display a graphic base on the number provided (0 means flat, higher number will elevate the field)</br>
More project information could be found in the folder project_pdf/fdf.en.pdf</br>
More maps example could be found in the folder maps/</br>
</br>
Usage :</br>
./fdf maps/42.fdf</br>
Control:</br>
Use mouse to drag and move the position of the graphic.</br>
Use mouse scroll to zoom in and out the graphic.</br>
Use keyboard arrow up(^) and down(v) to control the elevation of the field.</br>
Use keyboard arrow left(<) and right(>) to control the viewing angle.</br>
Press 'c' to reset the screen.</br>
Press 'ESC' to quit and close the screen.</br>
