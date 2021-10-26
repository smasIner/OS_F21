# You need to be in week 10 directory
mkdir ../week1 # just in case you do not have it
touch ../week1/file.txt
echo "Murat Shaikhutdinov" > ../week1/file.txt
link ../week1/file.txt  _ex2.txt
node=($(ls -i _ex2.txt));
find ../week1/file.txt -inum $node > ex2.txt
cp ../week1/file.txt file.txt # copy from source to dest
find ../week1/file.txt -inum $node -exec rm {} \; >> ex2.txt
