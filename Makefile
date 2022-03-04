#默认是/bin/sh, 避免有些环境指向bash，有些环境指向dash，两者echo命令有不同，所以这里统一使用bash
SHELL = /bin/bash

CXX?=g++
CC?=gcc

CXX_FLAGS := 
LD_FLAGS := 

CXX_SRCS := 
C_SRCS := 1/rectangle.c 2/list.c 2/vector.c 2/stack.c 2/hanoi.c 2/queue.c 2/apqueue.c 2/Bankqueue.c 2/BankService.c
C_SRCS += 3/node.c 3/linkedlist.c 3/nodelib.c 3/nodelibTest.c 3/linkedlistTest.c

CXX_OBJS := $(CXX_SRCS:%.cc=%.o)
C_OBJS := $(C_SRCS:%.c=%.o)
OBJS := $(CXX_OBJS) $(C_OBJS)

ALL_OBJS := $(OBJS)

ALL_TGTS := 1/rectangle 2/list 2/vector 2/stack 2/hanoi 2/queue 2/apqueue 2/BankService 3/nodelibTest 3/linkedlistTest

DEPFILES := $(ALL_OBJS:%.o=%.d)

.PHONY : clean all  

all : $(ALL_TGTS)

%.o: %.cc	
	$(CXX) $(CXX_FLAGS) -c -o $@ $<
%.o: %.c	
	$(CC) $(CXX_FLAGS) -c -o $@ $<

1/rectangle : 1/rectangle.o 
	$(CC) $(LD_FLAGS) -o $@ 1/rectangle.o

2/list: 2/list.o 
	$(CC) $(LD_FLAGS) -o $@ 2/list.o

2/vector: 2/vector.o 
	$(CC) $(LD_FLAGS) -o $@ 2/vector.o

2/stack: 2/stack.o 
	$(CC) $(LD_FLAGS) -o $@ 2/stack.o

2/hanoi: 2/hanoi.o 
	$(CC) $(LD_FLAGS) -o $@ 2/hanoi.o

2/queue: 2/queue.o 
	$(CC) $(LD_FLAGS) -o $@ 2/queue.o

2/apqueue: 2/apqueue.o 
	$(CC) $(LD_FLAGS) -o $@ 2/apqueue.o

2/BankService: 2/Bankqueue.o 2/BankService.o 
	$(CC) $(LD_FLAGS) -o $@ 2/Bankqueue.o 2/BankService.o

3/nodelibTest: 3/node.o 3/nodelib.o 3/nodelibTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/node.o 3/nodelib.o 3/nodelibTest.o

3/linkedlistTest: 3/node.o 3/linkedlist.o 3/linkedlistTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/node.o 3/linkedlist.o 3/linkedlistTest.o

clean:
	rm -rf $(ALL_TGTS)
	rm -rf $(ALL_OBJS)
	rm -rf $(DEPFILES)