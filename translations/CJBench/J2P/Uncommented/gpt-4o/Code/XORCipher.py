import sys

CS_DEFAULT = 'utf-8'

def bytes_to_hex(bytes_data):
    return ''.join(f'{b:02x}' for b in bytes_data)

def hex_to_bytes(hex_str):
    return bytes(int(hex_str[i:i+2], 16) for i in range(0, len(hex_str), 2))

def xor(input_bytes, key_bytes):
    return bytes(input_bytes[i] ^ key_bytes[i % len(key_bytes)] for i in range(len(input_bytes)))

def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(plain_text_bytes, key_bytes)
    return bytes_to_hex(xor_result)

def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode(CS_DEFAULT)

def main():
    operation = input().strip().lower()
    key = input("Enter the key: ").strip()
    if operation == "encrypt":
        plain_text = input().strip()
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message:", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        cipher_text = input().strip()
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message:", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
