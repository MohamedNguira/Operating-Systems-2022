gcc -pthread ex4.c -o ex4

for i in 1 2 4 10 100
do
    echo "Time taken for range [0,10000000) and $i threads:" >> ex4.txt
    /bin/time -p ./ex4 10000000 $i 2>> ex4.txt
    echo "==============">> ex4.txt
done