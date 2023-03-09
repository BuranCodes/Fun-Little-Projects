// Buran
// Pointer to string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(const char** s)
{
        char* ns = (char*) malloc(strlen(*s)+1); // or char ns[strlen(*s)+1];
        strcpy(ns, *s);
        printf("%s\n", ns);
}

int main(void)
{
        const char* something = "this is fun!";
        const char** ptr = &something;
        test(ptr);
}
