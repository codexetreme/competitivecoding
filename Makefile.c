# Makefile for compiling C/C++ code

compile:
	@g++ $(FILE)

create_input_file:
	@touch input.txt

run:
	@./a.out < input.txt

clean:
	@rm -rf a.out