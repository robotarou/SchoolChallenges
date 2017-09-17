#!/bin/bssh

cd src
make

echo "Select executable program?"
echo "1: make1gram"
echo "2: make2gram"
echo "3: make3gram"
echo "4: make1gram_Not-substituted"
echo -n "sel = "
read sel

case $sel in
    1|2|3)
        ./make[$sel]gram.out | sort -f | uniq -ci | sort -nr | head -50
        ;;
    4)
        ./make1gram_Not-substituted.out | sort -f | uniq -ci | sort -nr
        ;;
esac
