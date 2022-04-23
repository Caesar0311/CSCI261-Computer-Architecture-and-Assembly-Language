#Makefile for CSCI 261 Assignment 3

CC = gcc
WFLAG = -Wall
CFLAG = -c
DFLAG = -ggdb
IFLAG = -I
OFLAG = -o

BINARY = bin
BUILD = build
INCLUDE = include
SOURCE = src
TEST = test
EXAMPLE = example

all: ${BINARY}/integer_arithmetics

${BINARY}/integer_arithmetics: ${BUILD}/main.o ${BUILD}/integer_arithmetics.o ${BUILD}/convert.o ${BUILD}/utility.o
	${CC} ${WFLAG} ${DFLAG} -lm ${OFLAG} ${BINARY}/integer_arithmetics ${BUILD}/main.o \
		${BUILD}/integer_arithmetics.o ${BUILD}/convert.o ${BUILD}/utility.o

${BUILD}/main.o: ${SOURCE}/main.c ${INCLUDE}/integer_arithmetics.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILD}/main.o ${SOURCE}/main.c 

${BUILD}/integer_arithmetics.o: ${SOURCE}/integer_arithmetics.c ${INCLUDE}/integer_arithmetics.h \
	${INCLUDE}/convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/integer_arithmetics.o ${SOURCE}/integer_arithmetics.c

${BUILD}/convert.o: ${SOURCE}/convert.c ${INCLUDE}/convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/convert.o ${SOURCE}/convert.c


${BUILD}/utility.o: ${SOURCE}/utility.c ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/utility.o ${SOURCE}/utility.c


.PHONY: clean run-example debug-example

clean:
	rm ${BINARY}/* ${BUILD}/*

run: ${BINARY}/integer_arithmetics
	${BINARY}/integer_arithmetics

debug: ${BINARY}/integer_arithmetics
	gdb ${BINARY}/integer_arithmetics

run-example: ${EXAMPLE}/${BINARY}/integer_arithmetics
	${EXAMPLE}/${BINARY}/integer_arithmetics

debug-example: ${EXAMPLE}/${BINARY}/integer_arithmetics
	gdb ${EXAMPLE}/${BINARY}/integer_arithmetics

