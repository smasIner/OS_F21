while [ $(tail -1 f.txt ) -le 100 ]; # Althogh it obvious by task, be sure that f.txt contains at least one number.
  do
  if ln f.txt f.lock # locking the file
  then
    temp=$(tail -1 f.txt | grep -oE '^[0-9]+$') # greap to find last number
    echo $((temp + 1)) >> f.txt # add last number + 1 at the end
    rm f.lock # unlocking the file
    fi
  done
