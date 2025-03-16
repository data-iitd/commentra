import re

# Maps each character to its corresponding Morse code representation
MORSE_MAP = {
    'A': ".-",
    'B': "-...",
    'C': "-.-.",
    'D': "-..",
    'E': ".",
    'F': "..-.",
    'G': "--.",
    'H': "....",
    'I': "..",
    'J': ".---",
    'K': "-.-",
    'L': ".-..",
    'M': "--",
    'N': "-.",
    'O': "---",
    'P': ".--.",
    'Q': "--.-",
    'R': ".-.",
    'S': "...",
    'T': "-",
    'U': "..-",
    'V': "...-",
    'W': ".--",
    'X': "-..-",
    'Y': "-.--",
    'Z': "--.."
}

# Maps each Morse code representation back to its corresponding character
REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def text_to_morse(text):
    morse = []
    # Split the input text into words
    words = re.split(r'\s+', text.upper())
    # Iterate through each word
    for word in words:
        # Iterate through each character in the word
        for c in word:
            # Append the Morse code for the character, or an empty string if not found
            morse.append(MORSE_MAP.get(c, ''))
        # Append a separator for words, except for the last word
        if word!= words[-1]:
            morse.append('|')
    # Return the Morse code as a trimmed string
    return''.join(morse).strip()

def morse_to_text(morse):
    text = []
    # Split the Morse code into words based on the separator
    words = re.split(r'\s+\|\s+', morse)
    # Iterate through each Morse code word
    for word in words:
        # Iterate through each Morse code character in the word
        for code in re.split(r'\s+', word):
            # Append the corresponding character, or '?' if not found
            text.append(REVERSE_MAP.get(code, '?'))
        # Append a space between words, except for the last word
        if word!= words[-1]:
            text.append(' ')
    # Return the converted text
    return ''.join(text)

if __name__ == '__main__':
    # Create a scanner to read user input
    scanner = input()
    # Read the operation type (text-to-morse or morse-to-text)
    operation = scanner.strip().lower()
    
    # Determine the operation based on user input
    if operation == 'text-to-morse':
        # Read the text input to convert to Morse code
        text = input()
        # Convert the text to Morse code
        morse_code = text_to_morse(text)
        # Output the resulting Morse code
        print('Morse Code:'+ morse_code)
    elif operation =='morse-to-text':
        # Prompt user for Morse code input
        print('Enter the Morse code to convert to text: ')
        morse = input()
        # Convert the Morse code to text
        converted_text = morse_to_text(morse)
        # Output the resulting text
        print('Text:'+ converted_text)
    else:
        # Handle invalid operation input
        print('Invalid operation. Please enter \'text-to-morse\' or \'morse-to-text\'.')

# 