.PHONY: clean bin test prepare


bin/gem: prepare obj/main.o obj/func.o
	gcc -Wall -o bin/quadEqu obj/main.o obj/func.o -lncurses

obj/main.o: src/main.c
	gcc -Wall -c src/main.c -o obj/main.o

obj/func.o: src/func.c
	gcc -Wall -c src/func.c -o obj/func.o


bin/test: prepare obj/func.o obj/gem_test.o obj/ctest.o
	gcc -Wall -o bin/test obj/func.o obj/gem_test.o obj/ctest.o -lncurses

obj/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o obj/ctest.o -Ithirdparty

obj/gem_test.o: test/gem_test.c
	gcc -Wall -c test/gem_test.c -o obj/gem_test.o -Ithirdparty -Isrc


prepare:
	mkdir -p bin
	mkdir -p obj

bin: bin/gem

test: bin/test
	bin/test

clean:
	rm -f bin/* obj/*.o