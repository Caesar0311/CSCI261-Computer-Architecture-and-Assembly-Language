#Makefile for CSCI 261 Assignment 4

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

all: ${BINARY}/floating_point_arithmetics


${BINARY}/floating_point_arithmetics: ${BUILD}/main.o ${BUILD}/floating_point_arithmetics.o \
	${BUILD}/integer_arithmetics.o ${BUILD}/utility.o ${BUILD}/convert.o
	${CC} ${WFLAG} ${DFLAG} -lm ${OFLAG} ${BINARY}/floating_point_arithmetics \
		${BUILD}/main.o ${BUILD}/floating_point_arithmetics.o ${BUILD}/integer_arithmetics.o \
		${BUILD}/utility.o ${BUILD}/convert.o


${BUILD}/main.o: ${SOURCE}/main.c ${INCLUDE}/floating_point_arithmetics.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILD}/main.o ${SOURCE}/main.c 


${BUILD}/floating_point_arithmetics.o: ${SOURCE}/floating_point_arithmetics.c \
	${INCLUDE}/floating_point_arithmetics.h ${INCLUDE}/integer_arithmetics.h \
	${INCLUDE}/convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/floating_point_arithmetics.o \
		${SOURCE}/floating_point_arithmetics.c


${BUILD}/integer_arithmetics.o: ${SOURCE}/integer_arithmetics.c ${INCLUDE}/integer_arithmetics.h \
	${INCLUDE}/convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/integer_arithmetics.o \
		${SOURCE}/integer_arithmetics.c


${BUILD}/utility.o: ${SOURCE}/utility.c ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILD}/utility.o ${SOURCE}/utility.c


${BUILD}/convert.o: ${SOURCE}/convert.c ${INCLUDE}/convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/convert.o ${SOURCE}/convert.c



.PHONY: clean run run-example debug debug-example

clean:
	rm ${BINARY}/* ${BUILD}/*


run: ${BINARY}/floating_point_arithmetics
	${BINARY}/floating_point_arithmetics


debug: ${BINARY}/floating_point_arithmetics
	gdb ${BINARY}/floating_point_arithmetics


run-example: ${EXAMPLE}/${BINARY}/floating_point_arithmetics
	${EXAMPLE}/${BINARY}/floating_point_arithmetics


debug-example: ${EXAMPLE}/${BINARY}/floating_point_arithmetics
	gdb ${EXAMPLE}/${BINARY}/floating_point_arithmetics

