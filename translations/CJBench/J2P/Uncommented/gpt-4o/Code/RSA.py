import random
from sympy import mod_inverse

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
        return (pow(encrypted_message, self.private_key, self.modulus)).to_bytes((encrypted_message.bit_length() + 7) // 8, 'big').decode()

    def generate_keys(self, bits):
        p = self._generate_large_prime(bits // 2)
        q = self._generate_large_prime(bits // 2)
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.public_key = 3
        while gcd(phi, self.public_key) > 1:
            self.public_key += 2
        self.private_key = mod_inverse(self.public_key, phi)

    def _generate_large_prime(self, bits):
        while True:
            prime_candidate = random.getrandbits(bits)
            if self._is_prime(prime_candidate):
                return prime_candidate

    def _is_prime(self, n, k=5):  # number of tests
        if n <= 1:
            return False
        if n <= 3:
            return True
        if n % 2 == 0:
            return False
        for _ in range(k):
            a = random.randint(2, n - 2)
            if pow(a, n - 1, n) != 1:
                return False
        return True

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == "__main__":
    bits = int(input())
    rsa = RSA(bits)
    print("Public Key:", rsa.public_key)
    print("Modulus:", rsa.modulus)
    operation = input().strip()
    if operation.lower() == "encrypt":
        message = input().strip()
        encrypted_message = rsa.encrypt(message)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decrypt":
        encrypted_message = int(input().strip())
        decrypted_message = rsa.decrypt(encrypted_message)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation")

# <END-OF-CODE>
