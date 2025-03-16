
import math
import random
import string

class RSA:
    def __init__(self, bits):
        self.generate_keys(bits)

    def generate_keys(self, bits):
        p = random.getrandbits(bits // 2)
        q = random.getrandbits(bits // 2)
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.public_key = 3
        while self.public_key.gcd(phi) > 1:
            self.public_key += 2
        self.private_key = self.public_key.mod_inverse(phi)

    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        return pow(int(message), self.public_key, self.modulus)

    def decrypt(self, encrypted_message):
        if not encrypted_message:
            raise ValueError("Message is empty")
        return bytes(pow(int(encrypted_message), self.private_key, self.modulus)).decode()

def main():
    bits = int(input())
    rsa = RSA(bits)
    print("Public Key:", rsa.public_key)
    print("Modulus:", rsa.modulus)
    operation = input()
    if operation.lower() == "encrypt":
        message = input()
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        encrypted_message = input()
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation")

if __name__ == "__main__":
    main()

