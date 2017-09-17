all: make1gram_Not-substituted make1gram make2gram make3gram

make1gram_Not-substituted: make1gram_Not-substituted.cpp
	g++ -o make1gram_Not-substituted.out make1gram_Not-substituted.cpp
make1gram: make1gram.cpp
	g++ -o make1gram.out make1gram.cpp
make2gram: make2gram.cpp
	g++ -o make2gram.out make2gram.cpp
make3gram: make3gram.cpp
	g++ -o make3gram.out make3gram.cpp
clean:
	rm -rf *.out
