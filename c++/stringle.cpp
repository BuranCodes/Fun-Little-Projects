// Buran
// "String triangle" (Step by step concatenation)
#include <iostream>
#include <string>
#include <vector>



void string_rm_add(std::string Uinput) {
    std::string str = Uinput; // copy string
    for (std::string::size_type i = Uinput.size()-1; i > 0 ; i--) { // size_type preferred over int i; Uinput.size()-1 to avoid going over range; remove character step by step
        str = str.erase(i, 1); // note to self: do not add anything for first parameter that is not a number, it will go out of range.
        std::cout << str << "\n";
        if (i == 1) str.pop_back(); // turn into empty string to fill in next loop
    }
    std::cout << "\n";
    for (int i = 0; i < Uinput.size() ; i++) { // add characters back step by step
        str += Uinput[i];
        std::cout << str << "\n";
    }
}

int main() {
    std::cout << "Insert any word/number or sentence.\n" << "\n";
    std::string Uinput {""};
    std::getline(std::cin >> std::ws, Uinput); // include spaces
    string_rm_add(Uinput); // call function
}
