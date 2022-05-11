#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[0x40];

    printf("buf address : %p\n", buf);
    scanf("%s", buf);

    return 0;
}