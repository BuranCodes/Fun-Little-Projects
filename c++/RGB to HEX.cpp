// Buran
// RGB to Hex converter
#include <sstream>
#include <ios>
#include <iostream>
#include <string>

std::string RGBtoHEX(int rgb[3]) {
    std::stringstream rgbInput;
    std::string hexvalues;
    for (int i = 0; i < 3; i++) { 
        if (rgb[i] > 255) {
            hexvalues += "FF"; continue;
        }
        else if (rgb[i] < 0) {
            hexvalues += "00"; continue;
        }
        rgbInput << std::hex << rgb[i];
        if (rgb[i] < 16) {
            hexvalues += "0" + rgbInput.str(); // any value below 16 in hex is just one character
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
    int rgb[3] = {255, 255, 255};
    std::cout << "Hexadecimal values for the first iteration: #" << RGBtoHEX(rgb) << "\n";
    rgb[2] = 300;
    std::cout << "Hexadecimal values for the second iteration: #" << RGBtoHEX(rgb) << "\n";
    rgb[0] = 0; rgb[1] = 0; rgb[2] = 0;
    std::cout << "Hexadecimal values for the third iteration: #" << RGBtoHEX(rgb) << "\n";
    rgb[0] = 148; rgb[2] = 211;
    std::cout << "Hexadecimal values for the fourth iteration: #" << RGBtoHEX(rgb) << "\n";



}