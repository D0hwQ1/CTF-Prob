#include <stdio.h>
#include <stdlib.h>

static void __attribute__((constructor)) _start(void) {  
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    system((char*) NULL);
}

int main() {
    char buf[40];
    int person;

    printf("Who are you?\n");
    printf("My name is ...\n");

    printf("> ");
    scanf("%s", buf);

    if(person == 1004) {
        system("cat ./flag");
    } else {
        printf("Hi, %s", buf);
    }
    
    return 0;
}