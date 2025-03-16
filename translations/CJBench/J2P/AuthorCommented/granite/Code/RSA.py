

import random
from math import gcd

class Main:
    def __init__(self, bits):
        self.generate_keys(bits)

    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        return pow(int.from_bytes(message.encode(), 'big'), self.public_key, self.modulus)

    def decrypt(self, encrypted_message):
        if not encrypted_message:
            raise ValueError("Message is empty")
        return int.to_bytes(pow(encrypted_message, self.private_key, self.modulus), length=(self.modulus.bit_length() + 7) // 8, byteorder='big').decode()

    def generate_keys(self, bits):
        random = random.SystemRandom()
        p = random.randrange(2**(bits//2 - 1), 2**(bits//2))
        q = random.randrange(2**(bits//2 - 1), 2**(bits//2))
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.public_key = 3
        while gcd(phi, self.public_key) > 1:
            self.public_key += 1
        self.private_key = pow(self.public_key, -1, phi)

if __name__ == "__main__":
    bits = int(input("Enter the number of bits: "))
    rsa = Main(bits)

    print("Public Key:", rsa.public_key)
    print("Modulus:", rsa.modulus)

    operation = input("Enter the operation (encrypt/decrypt): ")

    if operation.lower() == "encrypt":
        message = input("Enter the message to encrypt: ")
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        encrypted_message = int(input("Enter the encrypted message to decrypt: "))
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation")

