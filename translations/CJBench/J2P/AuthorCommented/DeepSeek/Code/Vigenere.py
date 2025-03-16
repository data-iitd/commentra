def encrypt(message, key):
    if not key:
        raise ValueError("Key cannot be empty.")

    result = []
    key = key.upper()
    j = 0
    for i in range(len(message)):
        c = message[i]
        if c.isalpha():
            if c.isupper():
                result.append(chr((ord(c) + ord(key[j]) - 2 * ord('A')) % 26 + ord('A')))
            else:
                result.append(chr((ord(c) + ord(key[j]) - 2 * ord('a')) % 26 + ord('a')))
            j = (j + 1) % len(key)
        else:
            result.append(c)
    return ''.join(result)


def decrypt(message, key):
    if not key:
        raise ValueError("Key cannot be empty.")

    result = []
    key = key.upper()
    j = 0
    for i in range(len(message)):
        c = message[i]
        if c.isalpha():
            if c.isupper():
                result.append(chr(ord('A') + (25 - (ord(c) - ord(key[j]))) % 26))
            else:
                result.append(chr(ord('a') + (25 - (ord(c) - ord(key[j]))) % 26))
            j = (j + 1) % len(key)
        else:
            result.append(c)
    return ''.join(result)


def main():
    operation = input().lower()
    key = input()

    if operation == "encrypt":
        plaintext = input()
        encrypted = encrypt(plaintext, key)
        print("Encrypted Message:", encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        decrypted = decrypt(ciphertext, key)
        print("Decrypted Message:", decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")


if __name__ == "__main__":
    main()
