import sys

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
    morse = ""
    # Split the input text into words
    words = text.upper().split(" ")
    # Iterate through each word
    for i, word in enumerate(words):
        # Iterate through each character in the word
        for c in word:
            # Append the Morse code for the character, or an empty string if not found
            morse += MORSE_MAP.get(c, "") + " "
        # Append a separator for words, except for the last word
        if i < len(words) - 1:
            morse += "| "
    # Return the Morse code as a trimmed string
    return morse.strip()

def morse_to_text(morse):
    text = ""
    # Split the Morse code into words based on the separator
    words = morse.split(" | ")
    # Iterate through each Morse code word
    for i, word in enumerate(words):
        # Iterate through each Morse code character in the word
        for code in word.split(" "):
            # Append the corresponding character, or '?' if not found
            text += REVERSE_MAP.get(code, '?')
        # Append a space between words, except for the last word
        if i < len(words) - 1:
            text += " "
    # Return the converted text
    return text

# Determine the operation based on user input
operation = sys.stdin.readline().strip().lower()

# Handle invalid operation input
if operation not in ("text-to-morse", "morse-to-text"):
    print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")
    sys.exit(1)

# Read the input text or Morse code
input_text = sys.stdin.readline().strip()

# Convert the input text to Morse code or the Morse code to text
if operation == "text-to-morse":
    output_text = text_to_morse(input_text)
elif operation == "morse-to-text":
    output_text = morse_to_text(input_text)

# Output the resulting text
print(output_text)

