#exercice 1

mkdir lofsdisk
#creating the lofs.img file
fallocate -l $((51*1024*1024)) lofs.img

#loop setup
sudo losetup -fP lofs.img

#mounting the image file
sudo mkfs -t ext4 lofs.img
sudo mount -o loop lofs.img lofsdisk
