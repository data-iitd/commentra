def encrypt_message(msg):
    a = 17
    b = 20
    cipher = ""
    for i in range(len(msg)):
        if msg[i] != ' ':
            # Applying the affine cipher encryption formula
            cipher += chr(((a * (ord(msg[i]) - ord('A')) + b) % 26) + ord('A'))
        else:
            cipher += msg[i]
    return cipher


def decrypt_cipher(cipher):
    a = 17
    b = 20
    a_inv = 0
    flag = 0
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            a_inv = i
            break
    msg = ""
    for i in range(len(cipher)):
        if cipher[i] != ' ':
            # Applying the affine cipher decryption formula
            msg += chr(((a_inv * ((ord(cipher[i]) - ord('A')) - b + 26)) % 26) + ord('A'))
        else:
            msg += cipher[i]
    return msg


def main():
    msg = input().upper()
    cipher_text = encrypt_message(msg)
    print("Encrypted Message:", cipher_text)
    decrypted_text = decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)


main()
