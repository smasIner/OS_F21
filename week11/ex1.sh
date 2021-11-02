fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
mkdir lofsdisk # to mount on next step
sudo mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk
