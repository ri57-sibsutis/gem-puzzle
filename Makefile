.PHONY: clean prepare functions test

bin/gem: prepare obj/main.o obj/func.o
	gcc -Wall -o bin/gem obj/main.o obj/func.o -lncurses

bin/test: prepare obj/func.o obj/gem_test.o obj/cmain.o
	gcc -Wall -o bin/test obj/func.o obj/gem_test.o obj/cmain.o

obj/gem_test.o: prepare test/gem_test.c
	gcc -Wall -c test/gem_test.c -o obj/gem_test.o -Ithirdparty -Isrc

obj/cmain.o: prepare test/main.c
	gcc -Wall -c test/main.c -o obj/cmain.o -Ithirdparty

obj/main.o: prepare src/main.c
	gcc -Wall -c src/main.c -o obj/main.o

obj/func.o: prepare src/func.c
	gcc -Wall -c src/func.c -o obj/func.o

clean:
	rm -f -r bin
	rm -f -r obj

functions: bin/gem
	bin/gem

prepare: bin obj

bin:
	mkdir bin

test: bin/test
	bin/test

obj:
	mkdir obj