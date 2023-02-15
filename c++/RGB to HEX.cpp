#include <sstream>
#include <ios>
#include <iostream>
#include <string>

std::string RGBtoHEX(int rgb[3]) {
    std::stringstream rgbInput;
    std::string hexvalues;
    for (int i = 0; i < 3; i++) { 
        rgbInput << std::hex << rgb[i];
        if (rgb[i] < 16) {
        hexvalues += "0" + rgbInput.str();
        }
        else hexvalues += rgbInput.str();
        rgbInput << std::hex << rgb[i];
        rgbInput.str(std::string());
        rgbInput.clear();
    }
    if (hexvalues[-1] == ' ') hexvalues.pop_back();
    for (auto & c : hexvalues) { // e.g FF instead of ff
        c = std::toupper(c);  
    }
    return hexvalues;
}

int main() {
    int rgb[3] = {0, 0, 0};
    std::cout << "Given RGB Values: " << rgb[0] << " " << rgb[1] << " " << rgb[2] << "\n"; 
    std::cout << "Hexadecimal values: #" << RGBtoHEX(rgb); 
}