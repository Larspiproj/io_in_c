#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int input(char *s,int length);

int main() {
    char *buffer;
    size_t bufsize = 5;
    size_t characters;
    char *p;
    char *ptr;
    int numa;
    int nums;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("bufsize start: %ld\n", bufsize);
    printf("Please enter a line, max %ld characters\n", sizeof(bufsize));
    characters = getline(&buffer, &bufsize, stdin);
    printf("bufsize after realloc: %ld\n", bufsize);
    printf("%zu characters were read.\n", characters);
    printf("You entered >%s<\n", buffer);

    if ((p = strchr(buffer, '\n')) != NULL) {
            *p = '\0';

        printf("And now it's >%s<\n", buffer);

        numa = atoi(buffer);
        printf("num using atoi is >%d<\n", numa);

        nums = strtol(buffer, &ptr, 10);
        printf("num using strtol is >%d<\n", nums);
        printf("String part is >%s<\n", ptr);
    }

    free(buffer);

    return(0);
}
