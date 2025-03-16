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
    'Z': "--..",
}

REVERSE_MAP = {value: key for key, value in MORSE_MAP.items()}

def text_to_morse(text):
    words = text.upper().split()
    morse_code = []
    for word in words:
        morse_word = []
        for char in word:
            morse_word.append(MORSE_MAP.get(char, ""))
        morse_code.append(" ".join(morse_word))
    return " | ".join(morse_code)

def morse_to_text(morse):
    words = morse.split(" | ")
    text_words = []
    for word in words:
        chars = word.split()
        text_word = []
        for char in chars:
            text_word.append(REVERSE_MAP.get(char, '?'))
        text_words.append("".join(text_word))
    return " ".join(text_words)

def main():
    operation = input().strip().lower()
    if operation == "text-to-morse":
        text = input()
        morse_code = text_to_morse(text)
        print("Morse Code: " + morse_code)
    elif operation == "morse-to-text":
        morse = input("Enter the Morse code to convert to text: ")
        converted_text = morse_to_text(morse)
        print("Text: " + converted_text)
    else:
        print("Invalid operation. Please enter 'text-to-morse' or 'morse-to-text'.")

if __name__ == "__main__":
    main()
