# Buran
#! DISCLAIMER: This code is not production grade and cannot be expected to be used as a reliable RSA encoder/decoder. Educational purposes only.
# RSA encoder-decoder
# Takes strings (and keys) as input
# Outputs encoded/decoded message

from decimal import *
getcontext().prec = 10000

def encryption(messageText, encryptedMsg, epublickey, npublickey):
    for x in messageText:
        encryptedMsg.append((pow(ord(x), epublickey))%npublickey)

def decryption(encryptedMsg, dprivatekey, npublickey, decryptedMsg):
    for x in encryptedMsg:
        decryptedMsg += (chr(int(((Decimal(x)**Decimal(dprivatekey))%Decimal(npublickey)))))
    return decryptedMsg


def main():
    firstprime = 53
    secondprime = 59
    npublickey = firstprime*secondprime # 3127
    epublickey = 3 # For n = 3127, assume e = 3
    phinum = (firstprime-1)*(secondprime-1) # 3016
    k = 2 # assume k = 2
    dprivatekey = ((k * phinum + 1) / epublickey) # 2011

    encryptedMsg = []
    decryptedMsg = ""
    messageText = "Big integers can be dealt with!"
    encryption(messageText, encryptedMsg, epublickey, npublickey)
    print("Encrypted values: ", encryptedMsg)
    print("Decrypted message: ", decryption(encryptedMsg, dprivatekey, npublickey, decryptedMsg))

if __name__ == "__main__":
    main()
