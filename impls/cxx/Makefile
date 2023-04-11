uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifeq ($(uname_S),Darwin)
	# Native build on yosemite. Requires: brew install readline
	CXX=g++
	READLINE=/usr/local/opt/readline
	INCPATHS=-I$(READLINE)/include
	LIBPATHS=-L$(READLINE)/lib
endif

LD=$(CXX)
AR=ar

DEBUG=-ggdb
CXXFLAGS=-O3 -Wall $(DEBUG) $(INCPATHS) -std=c++11
LDFLAGS=-O3 $(DEBUG) $(LIBPATHS) -L. -lreadline -lhistory

LIBSOURCES=ReadLine.cc
LIBOBJS=$(LIBSOURCES:%.cc=%.o)

MAINS=$(wildcard step*.cc)
TARGETS=$(MAINS:%.cc=%)

.PHONY:	all clean

.SUFFIXES: .cc .o

all: $(TARGETS)

dist: mal

mal: stepA_mal
	cp $< $@

.deps: *.cc *.h
	$(CXX) $(CXXFLAGS) -MM *.cc > .deps

$(TARGETS): %: %.o libmal.a
	$(LD) $^ -o $@ $(LDFLAGS)

libmal.a: $(LIBOBJS)
	$(AR) rcs $@ $^

.cc.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS) libmal.a .deps mal

-include .deps
