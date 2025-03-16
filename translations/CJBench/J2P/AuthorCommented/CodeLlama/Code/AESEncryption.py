
import base64
import hashlib
import hmac
import os
import sys

from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


def encrypt(key, plaintext):
    # The key must be 16, 24, or 32 bytes long.
    # The IV must be 16 bytes long.
    iv = get_random_bytes(16)
    cipher = AES.new(key, AES.MODE_GCM, nonce=iv)
    ciphertext, tag = cipher.encrypt_and_digest(plaintext)
    return iv + ciphertext + tag


def decrypt(key, ciphertext):
    iv = ciphertext[:16]
    cipher = AES.new(key, AES.MODE_GCM, nonce=iv)
    plaintext = cipher.decrypt(ciphertext[16:-16])
    tag = ciphertext[-16:]
    try:
        cipher.verify(tag)
        return plaintext
    except ValueError:
        raise Exception("Tag doesn't match")


def main():
    if len(sys.argv) != 2:
        print("Usage: python aes_gcm.py <plaintext>")
        sys.exit(1)

    plaintext = sys.argv[1]
    key = hashlib.sha256(os.urandom(16)).digest()
    ciphertext = encrypt(key, plaintext.encode("utf-8"))
    print("Ciphertext:", base64.b64encode(ciphertext).decode("utf-8"))
    print("Key:", base64.b64encode(key).decode("utf-8"))
    print("Plaintext:", decrypt(key, ciphertext).decode("utf-8"))


if __name__ == "__main__":
    main()

