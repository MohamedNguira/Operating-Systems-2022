#exercice2

#creating the required folders
sudo mkdir -p lofsdisk/bin lofsdisk/lib64 lofsdisk/lib/x86_64-linux-gnu

#copying the {echo,cat,ls,bash} commands + libraries
sudo cp /lib/x86_64-linux-gnu/{libtinfo.so.6,libselinux.so.1,libc.so.6,libpcre2-8.so.0} lofsdisk/lib/x86_64-linux-gnu/
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64
sudo cp /bin/{bash,echo,cat,ls} lofsdisk/bin/

gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk/

#adding files to lofsdisk folder
echo "Mohamed" > file1
echo "Nguira" > file2
sudo mv {file1,file2} lofsdisk/

echo "Original root" > ex2.txt
./ex2.out >> ex2.txt
echo >> ex2.txt
echo "Loop device root" >> ex2.txt
sudo chroot lofsdisk ./ex2.out >> ex2.txt
