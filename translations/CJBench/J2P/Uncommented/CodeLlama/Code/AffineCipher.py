
import math

def encryptMessage(msg):
    cipher = ""
    for i in range(len(msg)):
        if msg[i] != " ":
            cipher += chr((((a * (ord(msg[i]) - ord("A"))) + b) % 26) + ord("A"))
        else:
            cipher += msg[i]
    return cipher

def decryptCipher(cipher):
    msg = ""
    aInv = 0
    flag = 0
    for i in range(26):
        flag = (a * i) % 26
        if flag == 1:
            aInv = i
            break
    for i in range(len(cipher)):
        if cipher[i] != " ":
            msg += chr((((aInv * ((ord(cipher[i]) - ord("A")) - b + 26)) % 26) + ord("A"))
        else:
            msg += cipher[i]
    return msg

a = 17
b = 20

msg = input("Enter message: ").upper()
cipherText = encryptMessage(msg)
print("Encrypted Message:", cipherText)
decryptedText = decryptCipher(cipherText)
print("Decrypted Message:", decryptedText)

