
import sys

# Converts text to the NATO phonetic alphabet.
# Examples:
# "ABC" -> "Alpha Bravo Charlie"
# "Hello" -> "Hotel Echo Lima Lima Oscar"
# "123" -> "One Two Three"
# "A1B2C3" -> "Alpha One Bravo Two Charlie Three"

def text_to_phonetic(text):
    phonetic_map = {
        'A': 'Alpha',
        'B': 'Bravo',
        'C': 'Charlie',
        'D': 'Delta',
        'E': 'Echo',
        'F': 'Foxtrot',
        'G': 'Golf',
        'H': 'Hotel',
        'I': 'India',
        'J': 'Juliett',
        'K': 'Kilo',
        'L': 'Lima',
        'M': 'Mike',
        'N': 'November',
        'O': 'Oscar',
        'P': 'Papa',
        'Q': 'Quebec',
        'R': 'Romeo',
        'S': 'Sierra',
        'T': 'Tango',
        'U': 'Uniform',
        'V': 'Victor',
        'W': 'Whiskey',
        'X': 'X-ray',
        'Y': 'Yankee',
        'Z': 'Zulu',
        '0': 'Zero',
        '1': 'One',
        '2': 'Two',
        '3': 'Three',
        '4': 'Four',
        '5': 'Five',
        '6': 'Six',
        '7': 'Seven',
        '8': 'Eight',
        '9': 'Nine'
    }

    phonetic = ''
    for c in text.upper():
        if c.isspace():
            continue
        phonetic += phonetic_map.get(c, c) + ' '

    return phonetic.strip()


def main():
    while True:
        input_text = input('Enter text to convert to NATO phonetic alphabet: ').strip()
        if input_text == 'exit':
            print('Exiting...')
            break
        if not input_text:
            print('Invalid Input: Input cannot be blank')
            continue
        print('Phonetic Alphabet:', text_to_phonetic(input_text))


if __name__ == '__main__':
    main()

