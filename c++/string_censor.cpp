// Buran
// Basic string censor with regex
#include <iostream>
#include <string>
#include <regex>

int main(){
std::string str {"hello I am Bob, show me your wallet now!"};
std::regex reg("(bob|wallet)", std::regex_constants::icase); // ignore upper or lowercase
std::cout << "Old string: " << str << "\nNew string: ";
str = std::regex_replace(str, reg, "****");
std::cout << str;
}
