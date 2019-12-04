#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int *argc, char **argv) {
    char buf[10];
    char *p;
    int num;

    printf("Please enter a line, max %ld characters\n", sizeof(buf));
    //printf("Please enter a line!\n");

    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        printf("You entered >%s<\n", buf);

        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';

        printf("And now it's >%s<\n", buf);

        num = atoi(buf);
        printf("num is >%d<\n", num);
    }
    return 0;
}
