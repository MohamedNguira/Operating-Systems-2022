echo `date`
sleep 3
mkdir ~/week1/rootfolder
echo `date`
sleep 3
ls -r --sort=time / > ~/week1/rootfolder/root.txt
echo `date`
sleep 3
mkdir ~/week1/homefolder
ls -r --sort=time ~ > ~/week1/homefolder/home.txt
cat ~/week1/root/root.txt
cat ~/week1/home/home.txt
ls ~/week1/ -R