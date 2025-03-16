
import sys

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
    morse = ''
    words = text.upper().split(' ')
    for i in range(len(words)):
        for c in words[i]:
            morse += MORSE_MAP.get(c, '') + ' '
        if i < len(words) - 1:
            morse += '| '
    return morse.strip()

def morse_to_text(morse):
    text = ''
    words = morse.split(' | ')
    for i in range(len(words)):
        for code in words[i].split(' '):
            text += REVERSE_MAP.get(code, '?')
        if i < len(words) - 1:
            text += ' '
    return text

if __name__ == '__main__':
    operation = sys.stdin.readline().strip().lower()
    if operation == 'text-to-morse':
        text = sys.stdin.readline().strip()
        morse = text_to_morse(text)
        print('Morse Code:', morse)
    elif operation == 'morse-to-text':
        morse = sys.stdin.readline().strip()
        text = morse_to_text(morse)
        print('Text:', text)
    else:
        print('Invalid operation. Please enter "text-to-morse" or "morse-to-text".')

