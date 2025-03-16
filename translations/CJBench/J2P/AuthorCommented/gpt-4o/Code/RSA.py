import random
from sympy import isprime, mod_inverse

class Main:
    def __init__(self, bits):
        self.modulus = None
        self.private_key = None
        self.public_key = None
        self.generate_keys(bits)

    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        return pow(int.from_bytes(message.encode(), 'big'), self.public_key, self.modulus)

    def decrypt(self, encrypted_message):
        if encrypted_message is None:
            raise ValueError("Message is empty")
        decrypted_bytes = pow(encrypted_message, self.private_key, self.modulus)
        return decrypted_bytes.to_bytes((decrypted_bytes.bit_length() + 7) // 8, 'big').decode()

    def generate_keys(self, bits):
        p = self.generate_large_prime(bits // 2)
        q = self.generate_large_prime(bits // 2)
        self.modulus = p * q

        phi = (p - 1) * (q - 1)

        self.public_key = 3
        while gcd(phi, self.public_key) != 1:
            self.public_key += 2

        self.private_key = mod_inverse(self.public_key, phi)

    def generate_large_prime(self, bits):
        while True:
            prime_candidate = random.getrandbits(bits)
            if isprime(prime_candidate):
                return prime_candidate

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == "__main__":
    bits = int(input("Enter key size in bits: "))
    rsa = Main(bits)

    print("Public Key:", rsa.public_key)
    print("Modulus:", rsa.modulus)

    operation = input("Enter operation (encrypt/decrypt): ").strip().lower()

    if operation == "encrypt":
        message = input("Enter message to encrypt: ")
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    elif operation == "decrypt":
        encrypted_message = int(input("Enter message to decrypt: "))
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation")

# <END-OF-CODE>
