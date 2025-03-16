import random
import sys
from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes

class RSA:
    def __init__(self, bits):
        self.bits = bits
        self.generate_keys()

    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        encrypted = pow(bytes_to_long(message.encode()), self.public_key, self.modulus)
        return str(encrypted)

    def decrypt(self, encrypted_message):
        if not encrypted_message:
            raise ValueError("Message is empty")
        decrypted = pow(int(encrypted_message), self.private_key, self.modulus)
        return long_to_bytes(decrypted).decode()

    def generate_keys(self):
        p = getPrime(self.bits // 2)
        q = getPrime(self.bits // 2)
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.public_key = 3
        while True:
            if phi % self.public_key != 0:
                break
            self.public_key += 2
        self.private_key = inverse(self.public_key, phi)

if __name__ == "__main__":
    bits = int(sys.stdin.readline().strip())
    rsa = RSA(bits)
    print("Public Key: " + str(rsa.public_key))
    print("Modulus: " + str(rsa.modulus))
    operation = sys.stdin.readline().strip().lower()
    if operation == "encrypt":
        message = sys.stdin.readline().strip()
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message: " + encrypted_message)
    elif operation == "decrypt":
        encrypted_message = sys.stdin.readline().strip()
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message: " + decrypted_message)
    else:
        print("Invalid operation")
