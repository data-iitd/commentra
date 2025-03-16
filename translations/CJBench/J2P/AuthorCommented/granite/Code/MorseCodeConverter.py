

import re

MORSE_MAP = {
    'A': '.-', 'B': '-...',
    'C': '-.-.', 'D': '-..', 'E': '.',
    'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-',
    'L': '.-..', 'M': '--', 'N': '-.',
    'O': '---', 'P': '.--.', 'Q': '--.-',
    'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--',
    'X': '-..-', 'Y': '-.--', 'Z': '--..'
}

REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def text_to_morse(text):
    morse = []
    words = text.upper().split()
    for word in words:
        for char in word:
            morse.append(MORSE_MAP.get(char, ''))
        morse.append('|')
    return''.join(morse[:-1])

def morse_to_text(morse):
    text = []
    words = re.split(r' \|', morse)
    for word in words:
        for code in word.split():
            text.append(REVERSE_MAP.get(code, '?'))
        text.append(' ')
    return ''.join(text[:-1])

operation = input().strip().lower()

if operation == "text-to-morse":
    text = input()
    morse_code = text_to_morse(text)
    print("Morse Code:", morse_code)
elif operation == "morse-to-text":
    morse = input()
    converted_text = morse_to_text(morse)
    print("Text:", converted_text)
else:
    print("Invalid operation. Please enter 'text-to-morse' or'morse-to-text'.")

