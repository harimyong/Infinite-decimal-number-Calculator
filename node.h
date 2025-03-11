#include <stdlib.h>
#include <malloc.h>

typedef struct NODE
{
    char data;
    struct NODE *next;
    struct NODE *prev;
}NODE;

NODE* makeNode(char data);