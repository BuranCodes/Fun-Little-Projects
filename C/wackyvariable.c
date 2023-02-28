// Buran
// How to undefined behaviour easy style! y is just random register
#include <stdio.h>

int main() {
    int x = 5;
    int y = y+x;
    printf("%d", y);
}

// Undefined behaviour!
