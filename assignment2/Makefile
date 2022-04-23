#Makefile for CSCI 261 Assignment 2

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

all: ${BINARY}/signed_convert

${BINARY}/signed_convert: ${BUILD}/main.o ${BUILD}/signed_convert.o ${BUILD}/utility.o
	${CC} ${WFLAG} ${DFLAG} -lm ${OFLAG} ${BINARY}/signed_convert ${BUILD}/main.o ${BUILD}/signed_convert.o ${BUILD}/utility.o

${BUILD}/main.o: ${SOURCE}/main.c ${INCLUDE}/signed_convert.h 
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILD}/main.o ${SOURCE}/main.c 

${BUILD}/signed_convert.o: ${SOURCE}/signed_convert.c ${INCLUDE}/signed_convert.h ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} -lm ${OFLAG} ${BUILD}/signed_convert.o ${SOURCE}/signed_convert.c

${BUILD}/utility.o: ${SOURCE}/utility.c ${INCLUDE}/utility.h
	${CC} ${WFLAG} ${CFLAG} ${DFLAG} ${IFLAG} ${INCLUDE} ${OFLAG} ${BUILD}/utility.o ${SOURCE}/utility.c


.PHONY: clean run run-example debug debug-example

clean:
	rm ${BINARY}/* ${BUILD}/*

run: ${BINARY}/signed_convert
	${BINARY}/signed_convert

debug: ${BINARY}/signed_convert
	gdb ${BINARY}/signed_convert



run-example: ${EXAMPLE}/${BINARY}/signed_convert
	${EXAMPLE}/${BINARY}/signed_convert

debug-example: ${EXAMPLE}/${BINARY}/signed_convert
	gdb ${EXAMPLE}/${BINARY}/signed_convert


