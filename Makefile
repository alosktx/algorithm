#默认是/bin/sh, 避免有些环境指向bash，有些环境指向dash，两者echo命令有不同，所以这里统一使用bash
SHELL = /bin/bash

CXX?=g++
CC?=gcc

CXX_FLAGS := 
CC_FLAGS := 
LD_FLAGS := 

CXX_SRCS := 
C_SRCS := 1/rectangle.c 2/list.c 2/vector.c 2/stack.c 2/hanoi.c 2/queue.c 2/apqueue.c 2/Bankqueue.c 2/BankService.c
C_SRCS += 3/3_1/node.c 3/3_1/linkedlist.c 3/3_1/nodelib.c 3/3_1/nodelibTest.c 3/3_1/linkedlistTest.c
C_SRCS += 3/3_1/linkedstack.c 3/3_1/linkedstackTest.c
C_SRCS += 3/3_1/linkedqueue.c 3/3_1/linkedqueueTest.c
C_SRCS += 3/3_1/clnkqueue.c 3/3_1/clnkqueueTest.c
C_SRCS += 3/3_1/spooler.c 3/3_1/spoolerTest.c
C_SRCS += 3/3_1/cnode.c 3/3_1/clnklist.c 3/3_1/clnklistTest.c
C_SRCS += 4/cmystring.c 4/cmystringTest.c
C_SRCS += 5/sort.c 5/sortTest.c
C_SRCS += 7/binaryTreeNode.c 7/binarytree.c 7/binarytreeTest.c
C_SRCS += 8/maxheap.c 8/maxheapTest.c
C_SRCS += 8/ufset.c 8/ufsetTest.c
C_SRCS += 9/graph.c 9/graphTest.c
C_SRCS += 9/prim.c 9/primTest.c
C_SRCS += 9/dijkstra.c 9/dijkstraTest.c

CXX_OBJS := $(CXX_SRCS:%.cc=%.o)
C_OBJS := $(C_SRCS:%.c=%.o)
OBJS := $(CXX_OBJS) $(C_OBJS)

ALL_OBJS := $(OBJS)

ALL_TGTS := 1/rectangle 2/list 2/vector 2/stack 2/hanoi 2/queue 2/apqueue 2/BankService
ALL_TGTS += 3/3_1/nodelibTest 3/3_1/linkedlistTest 3/3_1/linkedstackTest 3/3_1/linkedqueueTest 3/3_1/clnkqueueTest 3/3_1/spoolerTest
ALL_TGTS += 3/3_1/clnklistTest
ALL_TGTS += 4/cmystringTest
ALL_TGTS += 5/sortTest
ALL_TGTS += 7/binarytreeTest
ALL_TGTS += 8/maxheapTest
ALL_TGTS += 8/ufsetTest
ALL_TGTS += 9/graphTest
ALL_TGTS += 9/primTest
ALL_TGTS += 9/dijkstraTest

DEPFILES := $(ALL_OBJS:%.o=%.d)

.PHONY : clean all  

all : $(ALL_TGTS)

%.o: %.cc	
	$(CXX) $(CXX_FLAGS) -c -o $@ $<
%.o: %.c	
	$(CC) $(CC_FLAGS) -c -o $@ $<

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

3/3_1/nodelibTest: 3/3_1/node.o 3/3_1/nodelib.o 3/3_1/nodelibTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/node.o 3/3_1/nodelib.o 3/3_1/nodelibTest.o

3/3_1/linkedlistTest: 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedlistTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedlistTest.o

3/3_1/linkedstackTest: 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedstack.o 3/3_1/linkedstackTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedstack.o 3/3_1/linkedstackTest.o

3/3_1/linkedqueueTest: 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedqueue.o 3/3_1/linkedqueueTest.o
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/linkedqueue.o 3/3_1/linkedqueueTest.o

3/3_1/clnkqueueTest: 3/3_1/clnkqueue.o 3/3_1/clnkqueueTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/clnkqueue.o 3/3_1/clnkqueueTest.o

#编译时需要加参数 CC_FLAGS ：= -D PRINTJOB
3/3_1/spoolerTest: 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/spooler.o 3/3_1/spoolerTest.o 
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/node.o 3/3_1/linkedlist.o 3/3_1/spooler.o 3/3_1/spoolerTest.o

3/3_1/clnklistTest: 3/3_1/cnode.o 3/3_1/clnklist.o 3/3_1/clnklistTest.o
	$(CC) $(LD_FLAGS) -o $@ 3/3_1/cnode.o 3/3_1/clnklist.o 3/3_1/clnklistTest.o

4/cmystringTest: 4/cmystring.o 4/cmystringTest.o
	$(CC) $(LD_FLAGS) -o $@ 4/cmystring.o 4/cmystringTest.o

5/sortTest: 5/sort.o 5/sortTest.o
	$(CC) $(LD_FLAGS) -o $@ 5/sort.o 5/sortTest.o

7/binarytreeTest: 7/binaryTreeNode.o 7/binarytree.o 7/binarytreeTest.o
	$(CC) $(LD_FLAGS) -o $@ 7/binaryTreeNode.o 7/binarytree.o 7/binarytreeTest.o

8/maxheapTest: 8/maxheap.o 8/maxheapTest.o
	$(CC) $(LD_FLAGS) -o $@ 8/maxheap.o 8/maxheapTest.o

8/ufsetTest: 8/ufset.o 8/ufsetTest.o
	$(CC) $(LD_FLAGS) -o $@ 8/ufset.o 8/ufsetTest.o

9/graphTest: 9/graph.o 9/graphTest.o
	$(CC) $(LD_FLAGS) -o $@ 9/graph.o 9/graphTest.o

9/primTest: 9/prim.o 9/primTest.o
	$(CC) $(LD_FLAGS) -o $@ 9/prim.o 9/primTest.o

9/dijkstraTest: 9/dijkstra.o 9/dijkstraTest.o
	$(CC) $(LD_FLAGS) -o $@ 9/dijkstra.o 9/dijkstraTest.o


clean:
	rm -rf $(ALL_TGTS)
	rm -rf $(ALL_OBJS)
	rm -rf $(DEPFILES)