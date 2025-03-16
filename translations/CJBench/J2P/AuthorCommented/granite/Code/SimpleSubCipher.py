
import string

def encode(message, cipher_small):
    cipher_map = dict(zip(string.ascii_lowercase, cipher_small))
    return ''.join(cipher_map.get(c, c) for c in message)

def decode(encrypted_message, cipher_small):
    cipher_map = dict(zip(cipher_small, string.ascii_lowercase))
    return ''.join(cipher_map.get(c, c) for c in encrypted_message)

if __name__ == '__main__':
    cipher_alphabet = input()
    operation = input()

    if operation == 'encode':
        message = input()
        encrypted_message = encode(message, cipher_alphabet)
        print('Encrypted Message:', encrypted_message)
    elif operation == 'decode':
        encrypted_message = input()
        decrypted_message = decode(encrypted_message, cipher_alphabet)
        print('Decrypted Message:', decrypted_message)
    else:
        print('Invalid operation. Please enter "encode" or "decode".')

