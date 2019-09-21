EXE := main

compile:
	g++ *.cpp -o $(EXE) `pkg-config --libs allegro`

run: compile
	./$(EXE)

dep-install:	format-install
	sudo apt install pkg-config liballegro4-dev libjpgalleg4-dev

format-install:
	sudo apt-get install clang-format

format:
	find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;

clean:
	rm -f $(EXE) 