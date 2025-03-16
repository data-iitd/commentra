
import re

# Morse code map for character to Morse code conversion
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

# Reverse map for Morse code to character conversion
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

# Function to convert text to Morse code
def text_to_morse(text):
    morse = []
    for word in text.upper().split():
        for char in word:
            morse.append(MORSE_MAP.get(char, ''))
        morse.append('|')
    return''.join(morse[:-1])

# Function to convert Morse code to text
def morse_to_text(morse):
    text = []
    for word in morse.split(' | '):
        for code in word.split():
            text.append(REVERSE_MAP.get(code, '?'))
        text.append(' ')
    return ''.join(text[:-1])

# Main function to run the program
def main():
    operation = input("Enter the operation type (text-to-morse or morse-to-text): ").strip().lower()
    if operation == "text-to-morse":
        text = input("Enter the text to convert to Morse code: ")
        morse_code = text_to_morse(text)
        print("Morse Code:", morse_code)
    elif operation == "morse-to-text":
        morse = input("Enter the Morse code to convert to text: ")
        converted_text = morse_to_text(morse)
        print("Text:", converted_text)
    else:
        print("Invalid operation. Please enter 'text-to-morse' or'morse-to-text'.")

if __name__ == "__main__":
    main()
