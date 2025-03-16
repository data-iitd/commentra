import string
import sys

def encode(message, cipherSmall):
    encoded = ""
    cipherMap = {}
    beginSmallLetter = 'a'
    beginCapitalLetter = 'A'
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()
    for i in range(len(cipherSmall)):
        cipherMap[beginSmallLetter] = cipherSmall[i]
        cipherMap[beginCapitalLetter] = cipherCapital[i]
        beginSmallLetter += 1
        beginCapitalLetter += 1
    for i in range(len(message)):
        if message[i] in cipherMap:
            encoded += cipherMap[message[i]]
        else:
            encoded += message[i]
    return encoded

def decode(encryptedMessage, cipherSmall):
    decoded = ""
    cipherMap = {}
    beginSmallLetter = 'a'
    beginCapitalLetter = 'A'
    cipherSmall = cipherSmall.lower()
    cipherCapital = cipherSmall.upper()
    for i in range(len(cipherSmall)):
        cipherMap[cipherSmall[i]] = beginSmallLetter
        cipherMap[cipherCapital[i]] = beginCapitalLetter
        beginSmallLetter += 1
        beginCapitalLetter += 1
    for i in range(len(encryptedMessage)):
        if encryptedMessage[i] in cipherMap:
            decoded += cipherMap[encryptedMessage[i]]
        else:
            decoded += encryptedMessage[i]
    return decoded

if __name__ == "__main__":
    cipherAlphabet = sys.stdin.readline().strip()
    operation = sys.stdin.readline().strip()
    if operation == "encode":
        message = sys.stdin.readline().strip()
        encryptedMessage = encode(message, cipherAlphabet)
        print("Encrypted Message: " + encryptedMessage)
    elif operation == "decode":
        encryptedMessage = sys.stdin.readline().strip()
        decryptedMessage = decode(encryptedMessage, cipherAlphabet)
        print("Decrypted Message: " + decryptedMessage)
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

