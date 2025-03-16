
import re

# Maps each character to its corresponding Morse code representation
MORSE_MAP = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..',
    'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..'
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
            morse.append(MORSE_MAP.get(c, ""))
        # Append a separator for words, except for the last word
        if word!= words[-1]:
            morse.append("|")
    # Return the Morse code as a string
    return " ".join(morse)

def morse_to_text(morse):
    text = []
    # Split the Morse code into words based on the separator
    words = re.split(r'\s*\|\s*', morse)
    # Iterate through each Morse code word
    for word in words:
        # Iterate through each Morse code character in the word
        for code in re.split(r'\s+', word):
            # Append the corresponding character, or '?' if not found
            text.append(REVERSE_MAP.get(code, "?"))
        # Append a space between words, except for the last word
        if word!= words[-1]:
            text.append(" ")
    # Return the converted text
    return "".join(text)

# Test the functions
print(text_to_morse("Hello, World!"))
print(morse_to_text("... |.-..-.. |.-.. | - |.-. | --- |.-.-. | -.. |"))

# End of code