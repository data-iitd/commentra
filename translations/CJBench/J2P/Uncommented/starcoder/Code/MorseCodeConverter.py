
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
    'Z': '--..'
}
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}
def text_to_morse(text):
    morse = []
    for word in re.split(r'\s+', text.upper()):
        for c in word:
            morse.append(MORSE_MAP.get(c, ''))
        morse.append('|')
    return''.join(morse).strip()
def morse_to_text(morse):
    text = []
    for word in re.split(r'\s+\|\s+', morse):
        for code in re.split(r'\s+', word):
            text.append(REVERSE_MAP.get(code, '?'))
        text.append(' ')
    return ''.join(text).strip()
operation = input().strip().lower()
if operation == 'text-to-morse':
    text = input().strip()
    print('Morse Code:'+ text_to_morse(text))
elif operation =='morse-to-text':
    print('Enter the Morse code to convert to text: ', end='')
    morse = input().strip()
    print('Text:'+ morse_to_text(morse))
else:
    print('Invalid operation. Please enter \'text-to-morse\' or \'morse-to-text\'.')
