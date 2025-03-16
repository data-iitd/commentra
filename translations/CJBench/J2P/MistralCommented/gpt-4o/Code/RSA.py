import random
from sympy import isprime, mod_inverse

class RSA:
    def __init__(self, bits):
        self.modulus = None
        self.private_key = None
        self.public_key = None
        self.generate_keys(bits)

    def encrypt(self, message):
        if not message:  # Check if message is empty
            raise ValueError("Message is empty")
        return pow(int.from_bytes(message.encode(), 'big'), self.public_key, self.modulus)  # Encrypt the message

    def decrypt(self, encrypted_message):
        if encrypted_message is None:  # Check if encrypted message is empty
            raise ValueError("Message is empty")
        return (pow(encrypted_message, self.private_key, self.modulus)).to_bytes((encrypted_message.bit_length() + 7) // 8, 'big').decode()  # Decrypt the message

    def generate_keys(self, bits):
        p = self.generate_prime(bits // 2)  # Generate prime number p
        q = self.generate_prime(bits // 2)  # Generate prime number q
        self.modulus = p * q  # Calculate modulus
        phi = (p - 1) * (q - 1)  # Calculate phi(n) = (p-1)*(q-1)
        self.public_key = 3  # Initialize public key as 3

        # Find a public key such that gcd(phi, publicKey) = 1
        while gcd(phi, self.public_key) != 1:
            self.public_key += 2  # Increment public key by 2 until gcd(phi, publicKey) = 1

        self.private_key = mod_inverse(self.public_key, phi)  # Calculate private key

    def generate_prime(self, bits):
        while True:
            num = random.getrandbits(bits)
            if isprime(num):
                return num

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

if __name__ == "__main__":
    bits = int(input("Enter the number of bits: "))  # Read the number of bits from the user
    rsa = RSA(bits)  # Create an instance of RSA class
    print("Public Key:", rsa.public_key)  # Print the public key
    print("Modulus:", rsa.modulus)  # Print the modulus
    operation = input("Enter operation (encrypt/decrypt): ")  # Read the operation from the user

    if operation.lower() == "encrypt":  # If the operation is 'encrypt'
        message = input("Enter message to encrypt: ")  # Read the message from the user
        encrypted_message = rsa.encrypt(message)  # Encrypt the message
        print("Encrypted Message:", encrypted_message)  # Print the encrypted message
    elif operation.lower() == "decrypt":  # If the operation is 'decrypt'
        encrypted_message = int(input("Enter encrypted message to decrypt: "))  # Read the encrypted message from the user
        decrypted_message = rsa.decrypt(encrypted_message)  # Decrypt the message
        print("Decrypted Message:", decrypted_message)  # Print the decrypted message
    else:  # If the operation is not 'encrypt' or 'decrypt'
        print("Invalid operation")  # Print an error message
