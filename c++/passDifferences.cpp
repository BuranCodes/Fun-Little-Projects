// Buran
// A program to illustrate the difference between passing a value/parameter to function, a reference and a (smart) pointer.

#include <iostream>
#include <memory>

void passByParam(int a, int b) {

}

void passByRef(int &a, int &b) {

}

void passByPtr() {

}

int main(){
    int a, b;
    std::shared_ptr<int> aPointer = std::make_shared(a);
    a = 5; b= 2;
    std::cout << "Values of a and b:" << a << " " << b "\n";
}
