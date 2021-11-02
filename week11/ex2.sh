#Important:
#Arch linux vm was used
#You need to be in the week 11 directory with existing lofsdisk by constrains (complete task 1)
sudo echo 'Murat' > file1
sudo echo 'Shaikhutdinov' > file2
sudo cp file1 lofsdisk/file1
sudo cp file2 lofsdisk/file2
rm file1
rm file2
# Copy bash, cat, echo, ls commands to the disk + their shared libraries (You better use linux)
# While you could add them one by one or simply "import" ready linux
# library (overkill for this - a cannon at sparrows)

# copying everything that we need by using regular expresions to our disk
# so that we will have bash and lib
sudo cp -v --parents /bin/bash lofsdisk
for i in $(ldd /bin/bash | egrep -o '/lib.*\.[0-9]');
do
sudo cp -v --parents "$i" "lofsdisk";
done

sudo cp -v --parents /bin/cat lofsdisk
for i in $(ldd /bin/cat | egrep -o '/lib.*\.[0-9]');
do
sudo cp -v --parents "$i" "lofsdisk";
done

sudo cp -v --parents /bin/ls lofsdisk
for i in $(ldd /bin/ls | egrep -o '/lib.*\.[0-9]');
do
sudo cp -v --parents "$i" "lofsdisk";
done

sudo cp -v --parents /bin/echo lofsdisk
for i in $(ldd /bin/echo | egrep -o '/lib.*\.[0-9]');
do
sudo cp -v --parents "$i" "lofsdisk";
done

# firstly compile the program at week11 dir, then
# move it to lofsdisk where proceed its work
# Notifying you again, you should start this
# program at week11 dir
gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk/ex2.out
sudo chroot lofsdisk /ex2.out > ex2.txt

#Running again and appending the output
./ex2.out >> ex2.txt

