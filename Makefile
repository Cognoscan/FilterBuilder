# Makefile for generating example program
#

CFLAGS=-I/usr/local/include -std=c99
LDFLAGS=-Wall
LDLIBS= -lm

SRCS=$(shell find ./src -type f -name "*.c")
OBJS=$(patsubst %.c, %.o, $(SRCS))

.PHONY: all

all: filterbuilder


filterbuilder: $(OBJS)
	$(CC) $(LDFLAGS) -o filterbuilder $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend

clean:
	$(RM) $(OBJS)
	$(RM) filterbuilder

dist-clean: clean
	$(RM) *~ .dependtool

include .depend

