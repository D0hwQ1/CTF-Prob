#include <stdio.h>
#include <string.h>

int main() {
    char buf[20];

    printf("This program is currently locked.\n");
    printf("Try cracking me\n\n");
    printf("[*] pw : ");

    scanf("%s", buf);
    
    if(strcmp(buf, "Oh!_Y0u_g0t_th3_F1a9") == 0) {
        printf("Success !!\n");
    } else {
        printf("Failed...\n");
    }
    
    return 0;
}