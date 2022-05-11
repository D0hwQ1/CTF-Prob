#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int initialization(){
    char buf[4];

    printf("Wow !!, how did you find this function !?!?\n");
    printf("You must be tired. Why don't you go to bed?\n");
    read(0, buf, 0x400);
}

static void __attribute__((constructor)) _start(void) {  
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    system((char*) NULL);
}

int main() {
    char buf[4];

    printf("What food do you want to eat the most right now?\n");
    read(0, buf, 0x20);
    printf("Oh, that sounds good ~! , but I want to sleep now...\n", buf);

    return 0;
}