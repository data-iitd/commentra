

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
    morse = re.sub(r'(?<=\s)[A-Z]', lambda m: MORSE_MAP[m.group()], text.upper())
    return morse.replace(' ', '| ')

def morse_to_text(morse):
    text = re.sub(r'(?<=\s)[A-Z]', lambda m: REVERSE_MAP[m.group()], morse)
    return text.replace('|','')

operation = input().strip().lower()
if operation == 'text-to-morse':
    text = input()
    morse = text_to_morse(text)
    print(f"Morse Code: {morse}")
elif operation =='morse-to-text':
    morse = input()
    text = morse_to_text(morse)
    print(f"Text: {text}")
else:
    print("Invalid operation. Please enter 'text-to-morse' or'morse-to-text'.")

