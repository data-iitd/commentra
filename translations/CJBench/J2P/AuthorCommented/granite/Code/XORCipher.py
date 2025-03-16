

import binascii

def xor(input_bytes, key_bytes):
    output_bytes = bytearray(input_bytes)
    for i in range(len(input_bytes)):
        output_bytes[i] = input_bytes[i] ^ key_bytes[i % len(key_bytes)]
    return output_bytes

def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")

    plain_text_bytes = plain_text.encode()
    key_bytes = key.encode()
    xor_result = xor(plain_text_bytes, key_bytes)
    return binascii.hexlify(xor_result).decode()

def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")

    cipher_bytes = binascii.unhexlify(cipher_text)
    key_bytes = key.encode()
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode()

if __name__ == "__main__":
    operation = input("Enter operation (encrypt/decrypt): ").lower()

    key = input("Enter the key: ")

    if operation == "encrypt":
        plain_text = input("Enter the plaintext: ")
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        cipher_text = input("Enter the ciphertext: ")
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

