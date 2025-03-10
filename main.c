#include <stdio.h>
#include <stdlib.h>
#include <LinkedList.c>
int main(){
    char c=getchar();
    LinkedList* LL=init();
    while(c!=EOF){
        putchar(c);
        c=getchar();
    }
    


    return 0;
}