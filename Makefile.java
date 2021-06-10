# Makefile for compiling java code

CLASSNAME = $(shell echo $(FILE) | cut -d . -f1)

## run code
all: clean compile run

## compile files
compile:
	@javac $(FILE)

## create input files
create_input_file:
	@touch input.txt

## run files
run:
	@java -cp . $(CLASSNAME) < input.txt

## clean files
clean:
	@rm -rf *.class