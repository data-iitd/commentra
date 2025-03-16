
import sys
import binascii

def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode("utf-8")
    key_bytes = key.encode("utf-8")
    xor_result = bytearray(len(plain_text_bytes))
    for i in range(len(plain_text_bytes)):
        xor_result[i] = plain_text_bytes[i] ^ key_bytes[i % len(key_bytes)]
    return binascii.hexlify(xor_result).decode("utf-8")

def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    cipher_bytes = binascii.unhexlify(cipher_text.encode("utf-8"))
    key_bytes = key.encode("utf-8")
    xor_result = bytearray(len(cipher_bytes))
    for i in range(len(cipher_bytes)):
        xor_result[i] = cipher_bytes[i] ^ key_bytes[i % len(key_bytes)]
    return xor_result.decode("utf-8")

if __name__ == "__main__":
    operation = sys.stdin.readline().strip().lower()
    key = sys.stdin.readline().strip()
    if operation == "encrypt":
        plain_text = sys.stdin.readline().strip()
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        cipher_text = sys.stdin.readline().strip()
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

