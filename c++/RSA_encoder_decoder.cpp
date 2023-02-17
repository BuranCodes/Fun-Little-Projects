// Buran
//! DISCLAIMER: This code is not production grade and cannot be expected to be used as a reliable RSA encoder/decoder. Educational purposes only.
// RSA encoder-decoder
// Takes strings (and keys) as input
// Outputs encoded/decoded message

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

void encryption(std::string testString, std::vector<uint64_t>& encryptedMessages, int ePublicKey, int nPublicKey){
    for (char c : testString) {
    encryptedMessages.push_back(std::fmod(std::pow(int(c), ePublicKey), nPublicKey));
    }
}

std::string decryption(std::vector<uint64_t> testEncryptedMessage, int dPrivateKey, int nPublicKey) {
    std::string decryptedMsg;
    for (int i : testEncryptedMessage) {
        decryptedMsg.push_back(char(std::fmod((std::pow(i, dPrivateKey)), nPublicKey))); // number too big!
    }
    return decryptedMsg;
}

int main(){
    std::string testString = "Hello, world!";
    std::vector<uint64_t> testEncryptedMessage;
    // TODO: Random prime numbers
    int firstprime = 53;
    int secondprime = 59;
    int nPublicKey = firstprime*secondprime; // 3127
    int ePublicKey = 3; // For nPublicKey = 3127, assume ePublicKey = 3
    int phiNum = 3016; // assume phi(3127) = 3016
    int k = 2; // assume k = 2
    int dPrivateKey = ((k * phiNum + 1) / ePublicKey); // 2011 
    encryption(testString, testEncryptedMessage, ePublicKey, nPublicKey);
    std::cout << decryption(testEncryptedMessage, dPrivateKey, nPublicKey);
}