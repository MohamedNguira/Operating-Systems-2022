mkdir tmp
cd tmp
echo Mohamed Nguira 1 > file1
echo Mohamed Nguira 2 > file2
ln file1 link1
cd ..
gcc ex4.c -o ex4.o
./ex4.o > ex4.txt
