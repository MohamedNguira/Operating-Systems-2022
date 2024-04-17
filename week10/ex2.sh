cd ../week01/
echo Mohamed Nguira > file.txt
link file.txt ../week10/_ex2.txt
find .. -inum $(ls -i file.txt* | head -n1 | cut -d " " -f1) > ../week10/ex2.txt
find .. -inum $(ls -i file.txt* | head -n1 | cut -d " " -f1) -exec rm {} \; >> ../week10/ex2.txt
