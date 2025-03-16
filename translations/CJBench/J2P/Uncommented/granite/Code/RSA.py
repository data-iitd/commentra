

import random
from Crypto.Util.number import *

class Main:
    def __init__(self, bits):
        self.generateKeys(bits)

    def encrypt(self, message):
        if message == "":
            raise ValueError("Message is empty")
        return pow(int.from_bytes(message.encode(), "big"), self.publicKey, self.modulus)

    def decrypt(self, encryptedMessage):
        if encryptedMessage == "":
            raise ValueError("Message is empty")
        return bytes.from_hex(hex(pow(int(encryptedMessage), self.privateKey, self.modulus))[2:]).decode()

    def generateKeys(self, bits):
        random.seed()
        p = getPrime(bits // 2)
        q = getPrime(bits // 2)
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.publicKey = 3
        while gcd(phi, self.publicKey) > 1:
            self.publicKey += 2
        self.privateKey = inverse(self.publicKey, phi)

if __name__ == "__main__":
    bits = int(input())
    rsa = Main(bits)
    print("Public Key:", rsa.publicKey)
    print("Modulus:", rsa.modulus)
    operation = input()
    if operation.lower() == "encrypt":
        message = input()
        encryptedMessage = rsa.encrypt(message)
        print("Encrypted Message:", encryptedMessage)
    elif operation.lower() == "decrypt":
        encryptedMessage = input()
        decryptedMessage = rsa.decrypt(encryptedMessage)
        print("Decrypted Message:", decryptedMessage)
    else:
        print("Invalid operation")

