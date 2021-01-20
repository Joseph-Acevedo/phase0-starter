/*
 * Name: Joseph Acevedo
 * NetID: josephacevedo
 * Phase0
 */

#include <stdio.h>
#include "usloss.h"

#define SIZE (USLOSS_MIN_STACK)
#define MAX_ITER 10

USLOSS_Context helloCtxt;
USLOSS_Context worldCtxt;

char stack0[SIZE];
char stack1[SIZE];


void hello(void) {
     int i = 0;
     while (++i <= MAX_ITER) {
	USLOSS_Console("%d Hello ", i);
	USLOSS_ContextSwitch(&helloCtxt, &worldCtxt);
     }
     USLOSS_Halt(0);
}

void world(void) {
     int i = 0;
     while (++i <= MAX_ITER) {
	USLOSS_Console("World");
	int j = i;
	while (j-- > 0)
            USLOSS_Console("!");
	USLOSS_Console("\n");
	USLOSS_ContextSwitch(&worldCtxt, &helloCtxt);
     }
}

void startup(int argc, char **argv)
{
    /*
     * Your code here. If you compile and run this as-is you
     * will get a simulator trap, which is a good opportunity
     * to verify that you get a core file and you can use it
     * with gdb.
     */
     USLOSS_ContextInit(&helloCtxt, stack0, sizeof(stack0), NULL, hello);
     USLOSS_ContextInit(&worldCtxt, stack1, sizeof(stack1), NULL, world);
     USLOSS_ContextSwitch(NULL, &helloCtxt);
}

// Do not modify anything below this line.

void finish(int argc, char **argv)
{
    USLOSS_Console("Goodbye.\n");
}

void test_setup(int argc, char **argv)
{
    // Do nothing.
}

void test_cleanup(int argc, char **argv)
{
    // Do nothing.
}

