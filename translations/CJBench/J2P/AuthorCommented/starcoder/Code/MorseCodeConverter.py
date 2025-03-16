
import re

MORSE_MAP = {
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
}

REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def text_to_morse(text):
    morse = []
    for word in text.upper().split(' '):
        for c in word:
            morse.append(MORSE_MAP.get(c, ''))
        morse.append('|')
    return''.join(morse).strip()

def morse_to_text(morse):
    text = []
    for word in morse.split(' | '):
        for code in word.split(' '):
            text.append(REVERSE_MAP.get(code, '?'))
        text.append(' ')
    return ''.join(text).strip()

if __name__ == '__main__':
    import sys

    operation = sys.stdin.readline().strip().lower()

    if operation == 'text-to-morse':
        text = sys.stdin.readline().strip()
        print('Morse Code:'+ text_to_morse(text))
    elif operation =='morse-to-text':
        print('Enter the Morse code to convert to text: ')
        morse = sys.stdin.readline().strip()
        print('Text:'+ morse_to_text(morse))
    else:
        print('Invalid operation. Please enter \'text-to-morse\' or \'morse-to-text\'.')

