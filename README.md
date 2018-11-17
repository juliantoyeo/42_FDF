# 42_FDF

This project is about basic computer graphic drawing with c.
The library used for the graphic is provided by my school which is base from X.11

The program will read the file with the content from the following format:

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

and the program with display a graphic base on the number provided (0 means flat, higher number will elevate the field)
More project information could be found in the folder project_pdf/fdf.en.pdf
More maps example could be found in the folder maps/

Usage :
./fdf maps/42.fdf
Control:
Use mouse to drag and move the position of the graphic.
Use keyboard arrow up(^) and down(v) to control the elevation of the field
Use keyboard arrow left(<) and right(>) to control the viewing angle
