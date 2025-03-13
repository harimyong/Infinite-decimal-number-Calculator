#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
typedef int bool;
#define false 0
#define true 1
typedef struct NODE
{
    char data;
    struct NODE *next;
    struct NODE *prev;
}NODE;

NODE* makeNode(char data);