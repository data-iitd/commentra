
def encode(message, cipher_small):
    encoded = []
    cipher_map = {}
    begin_small_letter = 'a'
    begin_capital_letter = 'A'
    cipher_small = cipher_small.lower()
    cipher_capital = cipher_small.upper()
    for i in range(len(cipher_small)):
        cipher_map[begin_small_letter] = cipher_small[i]
        cipher_map[begin_capital_letter] = cipher_capital[i]
        begin_small_letter = chr(ord(begin_small_letter) + 1)
        begin_capital_letter = chr(ord(begin_capital_letter) + 1)
    for char in message:
        if char.isalpha():
            encoded.append(cipher_map[char])
        else:
            encoded.append(char)
    return ''.join(encoded)

def decode(encrypted_message, cipher_small):
    decoded = []
    cipher_map = {}
    begin_small_letter = 'a'
    begin_capital_letter = 'A'
    cipher_small = cipher_small.lower()
    cipher_capital = cipher_small.upper()
    for i in range(len(cipher_small)):
        cipher_map[cipher_small[i]] = begin_small_letter
        cipher_map[cipher_capital[i]] = begin_capital_letter
        begin_small_letter = chr(ord(begin_small_letter) + 1)
        begin_capital_letter = chr(ord(begin_capital_letter) + 1)
    for char in encrypted_message:
        if char.isalpha():
            decoded.append(cipher_map[char])
        else:
            decoded.append(char)
    return ''.join(decoded)

if __name__ == '__main__':
    import sys
    cipher_alphabet = sys.stdin.readline().strip()
    operation = sys.stdin.readline().strip()
    if operation == 'encode':
        message = sys.stdin.readline().strip()
        encrypted_message = encode(message, cipher_alphabet)
        print('Encrypted Message: {}'.format(encrypted_message))
    elif operation == 'decode':
        encrypted_message = sys.stdin.readline().strip()
        decrypted_message = decode(encrypted_message, cipher_alphabet)
        print('Decrypted Message: {}'.format(decrypted_message))
    else:
        print('Invalid operation. Please enter "encode" or "decode".')

