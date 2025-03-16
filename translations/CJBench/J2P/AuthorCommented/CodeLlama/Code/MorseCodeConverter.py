
import re

# Converts text to Morse code and vice-versa.
# Text to Morse code: Each letter is separated by a space and each word is separated by a pipe (|).
# Example: "HELLO WORLD" -> ".... . .-.. .-.. --- | .-- --- .-. .-.. -.."
#
# Morse code to text: Each letter is separated by a space and each word is separated by a pipe (|).
# Example: ".... . .-.. .-.. --- | .-- --- .-. .-.. -.." -> "HELLO WORLD"

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

REVERSE_MAP = {v: k for k, v in MORSE_MAP.items()}

def text_to_morse(text):
    morse = ""
    words = text.upper().split(" ")
    for i in range(len(words)):
        for c in words[i]:
            morse += MORSE_MAP.get(c, "") + " "
        if i < len(words) - 1:
            morse += "| "
    return morse.strip()

def morse_to_text(morse):
    text = ""
    words = re.split(r" \| ", morse)
    for i in range(len(words)):
        for code in words[i].split(" "):
            text += REVERSE_MAP.get(code, '?')
        if i < len(words) - 1:
            text += " "
    return text.strip()

if __name__ == "__main__":
    operation = input("Enter 'text-to-morse' or 'morse-to-text': ").strip().lower()

    if operation == "text-to-morse":
        text = input("Enter the text to convert to Morse code: ").strip()
        morse = text_to_morse(text)
        print("Morse Code:", morse)
    elif operation == "morse-to-text":
        morse = input("Enter the Morse code to convert to text: ").strip()
        text = morse_to_text(morse)
        print("Text:", text)
    else:
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

