// Buran
// A program to illustrate the difference between passing a value/parameter to function, a reference and a (smart) pointer.

#include <iostream>

void passByParam(int a, int b) {
    a = 8;
    b = 3;
}

void passByRef(int& x, int& y) {
    x = 4;
    y = 5;
}

void passByPtr(int* a, int* b) {
    *a = 9;
    *b = 6;
}
int main(){
    int a, b;
    a = 5; b= 2;
    std::cout << "Values of a and b: " << a << " " << b << "\n";
    passByParam(a,b);
    std::cout << "Values of a and b after passing by parameter: " << a << " " << b << "\n";
    passByRef(a,b);
    std::cout << "Values of a and b after passing by reference: " << a << " " << b << "\n";
    passByPtr(&a, &b);
    std::cout << "Values of a and b after passing by pointer: " << a << " " << b << "\n";

}
