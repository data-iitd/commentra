import random
from sympy import isprime, mod_inverse

class RSA:
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
        if not encrypted_message:
            raise ValueError("Message is empty")
        decrypted_bytes = pow(encrypted_message, self.private_key, self.modulus)
        return decrypted_bytes.to_bytes((decrypted_bytes.bit_length() + 7) // 8, 'big').decode()

    def generate_keys(self, bits):
        # Generate two large prime numbers p and q
        p = self.generate_large_prime(bits // 2)
        q = self.generate_large_prime(bits // 2)

        # Calculate the modulus as p * q
        self.modulus = p * q

        # Calculate phi(n) = (p-1)(q-1)
        phi = (p - 1) * (q - 1)

        # Initialize the public key with a small odd number
        self.public_key = 3

        # Ensure that public_key is coprime to phi(n)
        while gcd(phi, self.public_key) != 1:
            self.public_key += 2

        # Calculate the private key as the modular inverse of publicKey mod phi(n)
        self.private_key = mod_inverse(self.public_key, phi)

    def generate_large_prime(self, bits):
        while True:
            num = random.getrandbits(bits)
            if isprime(num):
                return num

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == "__main__":
    bits = int(input("Enter the bit length for key generation: "))
    rsa = RSA(bits)

    print("Public Key:", rsa.public_key)
    print("Modulus:", rsa.modulus)

    operation = input("Enter operation (encrypt/decrypt): ").strip().lower()

    if operation == "encrypt":
        message = input("Enter message to encrypt: ")
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    elif operation == "decrypt":
        encrypted_message = int(input("Enter encrypted message: "))
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation")

# <END-OF-CODE>
