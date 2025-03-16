import base64

def bytes_to_hex(bytes):
    return ''.join(f'{byte:02x}' for byte in bytes)

def hex_to_bytes(hex_str):
    return bytes(int(hex_str[i:i+2], 16) for i in range(0, len(hex_str), 2))

def xor(input_bytes, key_bytes):
    output_bytes = bytearray(input_bytes)
    for i in range(len(input_bytes)):
        output_bytes[i] ^= key_bytes[i % len(key_bytes)]
    return bytes(output_bytes)

def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode('utf-8')
    key_bytes = key.encode('utf-8')
    xor_result = xor(plain_text_bytes, key_bytes)
    return bytes_to_hex(xor_result)

def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode('utf-8')
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode('utf-8')

def main():
    import sys
    input_operation = input().lower()
    print("Enter the key: ", end='')
    key = input()
    if input_operation == "encrypt":
        try:
            plain_text = input()
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message: " + cipher_text)
        except ValueError as e:
            print(e)
    elif input_operation == "decrypt":
        try:
            cipher_text = input()
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message: " + plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

if __name__ == "__main__":
    main()

