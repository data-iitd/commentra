import random
import sys
from Crypto.Util.number import isPrime, getPrime, inverse, bytes_to_long, long_to_bytes

class Main:

    def __init__(self, bits):
        self.generate_keys(bits)

    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        return str(pow(bytes_to_long(message.encode()), self.public_key, self.modulus))

    def decrypt(self, encrypted_message):
        if not encrypted_message:
            raise ValueError("Message is empty")
        return long_to_bytes(pow(int(encrypted_message), self.private_key, self.modulus)).decode()

    def generate_keys(self, bits):
        p = getPrime(bits // 2)
        q = getPrime(bits // 2)
        self.modulus = p * q

        phi = (p - 1) * (q - 1)

        self.public_key = 3
        while True:
            if phi % self.public_key != 0 and isPrime(self.public_key):
                break
            self.public_key += 2

        self.private_key = inverse(self.public_key, phi)

if __name__ == "__main__":
    bits = int(input().strip())
    rsa = Main(bits)

    print("Public Key: " + str(rsa.public_key))
    print("Modulus: " + str(rsa.modulus))

    operation = input().strip()

    if operation.lower() == "encrypt":
        message = input().strip()
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message: " + encrypted_message)
    elif operation.lower() == "decrypt":
        encrypted_message = input().strip()
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message: " + decrypted_message)
    else:
        print("Invalid operation")
