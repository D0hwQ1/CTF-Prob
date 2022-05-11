#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void __attribute__((constructor)) _start(void) {  
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    system((char*) NULL);
}

int main() {
    char buf[4];

    printf("This is the First step.\n");
    printf("Let's move on to Second step.\n");

    printf("> ");
    scanf("%s", buf);
    return 0;
}

int Second() {
    int dummy;
    char buf[8];

    printf("\nThis is the Second step.\n");
    printf("Let's move on to Final step.\n");

    printf("> ");
    scanf("%d", &dummy);
    return 0;
}

int Final() {
    char buf[13];

    printf("\nThis is the Final step.\n");
    printf("Let's move on to Success step.\n");

    printf("> ");
    scanf("%s", buf);

    if(strcmp(buf, "Dobby is free") != 0) {
        return 0;
    } else {
        exit(0);
    }

    return 0;
}

int Success() {
    printf("\nSuccess !!");
    system("cat ./flag");
    return 0;
}
