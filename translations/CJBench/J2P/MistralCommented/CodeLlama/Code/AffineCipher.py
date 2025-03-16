
import math

def encrypt_message(msg):
    cipher = ""
    for i in range(len(msg)):
        if msg[i] != " ":
            cipher += chr((((a * (ord(msg[i]) - ord("A"))) + b) % 26) + ord("A"))
        else:
            cipher += msg[i]
    return cipher

def decrypt_cipher(cipher):
    msg = ""
    a_inv = 0
    flag = 0
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            a_inv = i
            break
    for i in range(len(cipher)):
        if cipher[i] != " ":
            msg += chr((((a_inv * ((ord(cipher[i]) - ord("A")) - b + 26)) % 26) + ord("A")))
        else:
            msg += cipher[i]
    return msg

a = 17
b = 20

msg = input("Enter message: ").upper()
cipher_text = encrypt_message(msg)
print("Encrypted message:", cipher_text)
decrypted_text = decrypt_cipher(cipher_text)
print("Decrypted message:", decrypted_text)

