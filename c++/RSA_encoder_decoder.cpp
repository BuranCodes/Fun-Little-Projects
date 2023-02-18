// Buran
//! DISCLAIMER: This code is not production grade and cannot be expected to be used as a reliable RSA encoder/decoder. Educational purposes only.
// RSA encoder-decoder
// Takes strings (and keys) as input
// Outputs encoded/decoded message

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

// CODE FROM CHATGPT
int64_t modPow(int64_t base, int64_t exponent, const int64_t modulus) {
    int64_t result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

std::vector<int64_t> encrypt(const std::string plaintext, const int ePublicKey, const int nPublicKey) {
    std::vector<int64_t> ciphertext;

    for (char c : plaintext) {
        ciphertext.push_back(modPow(c, ePublicKey, nPublicKey));
    }
    return ciphertext;
}

std::string decrypt(const std::vector<int64_t> ciphertext, const int dPrivateKey, const int nPublicKey) {
    std::string plaintext;

    for (int64_t i : ciphertext) {
        plaintext.push_back(modPow(i, dPrivateKey, nPublicKey));
    }
    return plaintext;
}

int main() {
    const std::string plaintext = "Hello, world!";

    // TODO: Random prime numbers
    const int firstPrime = 53;
    const int secondPrime = 59;
    const int nPublicKey = firstPrime * secondPrime; // 3127
    const int ePublicKey = 3; // For nPublicKey = 3127, assume ePublicKey = 3
    const int phiNum = (firstPrime - 1) * (secondPrime - 1); // assume phi(3127) = 3016
    const int k = 2; // assume k = 2
    const int dPrivateKey = ((k * phiNum + 1) / ePublicKey); // 2011

    const std::vector<int64_t> ciphertext = encrypt(plaintext, ePublicKey, nPublicKey);
    std::cout << decrypt(ciphertext, dPrivateKey, nPublicKey);
}
