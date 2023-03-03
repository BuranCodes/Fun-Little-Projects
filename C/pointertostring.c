// Buran
// Pointer to string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(const char** s) {
    char* news = (char*) malloc(strlen(*s)+1); // or char news[strlen(*s)+1];
    strcpy(news, *s);
    printf("%s\n", news);
};

int main(void) {
const char* something = "this is fun!";
const char** point = &something;
test(point);
}
