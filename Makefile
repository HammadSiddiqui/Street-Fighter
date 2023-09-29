EXE    := main
CFLAGS := -Iinc `allegro-config --cflags release` -Wl,-rpath,/usr/local/lib
LIBS   := `allegro-config --libs --static release`

all:
	g++ src/*.cpp -o $(EXE) $(CFLAGS)  $(LIBS)

run: all
	./$(EXE)

dep-install:	format-install
	sudo apt install pkg-config liballegro4-dev libjpgalleg4-dev

format-install:
	sudo apt get install clang-format

format:
	find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;

clean:
	rm -f $(EXE) 