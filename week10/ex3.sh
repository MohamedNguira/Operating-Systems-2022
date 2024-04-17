echo Mohamed Nguira > _ex3.txt
chmod a-x _ex3.txt
ls -la _ex3.txt* > ex3.txt
chmod uo+rwx _ex3.txt
ls -la _ex3.txt* >> ex3.txt
chmod g=u _ex3.txt
ls -la _ex3.txt* >> ex3.txt
echo 660 means user and group have only read and write permissions while others have no permission >> ex3.txt
echo 775 means All have read and execute permissions but only user and group have write permission >> ex3.txt
echo 777 means all have all permissions for that file >> ex3.txt
