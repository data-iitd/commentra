import sys

# Main method starts the execution of the program
def main():
    # Read the first input string from the console
    s = input()
    # Read the second input string from the console
    t = input()

    # Initialize counters for unique characters in the first string and opposite characters in the second string
    ura = 0
    opa = 0

    # Create a dictionary to store the frequency of each character in the second string
    tmap = {}

    # Read the characters of the second string and store their frequencies in the dictionary
    for ch in t:
        if ch not in tmap:
            tmap[ch] = 1
        else:
            tmap[ch] += 1

    # Process the first string
    length = len(s)
    for i in range(length):
        ch = s[i]
        num = tmap.get(ch)
        if num is None:
            continue
        inum = num
        if inum == 1:
            del tmap[ch]
        else:
            tmap[ch] = inum - 1
        s = s[:i] + 'Я' + s[i+1:]
        ura += 1

    # Process the reversed version of the first string
    for i in range(length):
        ch = s[i]
        rch = reverse(ch)
        num = tmap.get(rch)
        if num is None:
            continue
        inum = num
        if inum == 1:
            del tmap[rch]
        else:
            tmap[rch] = inum - 1
        opa += 1

    # Print the results
    print(ura, opa)

# Reverse the given character
def reverse(ch):
    if ch.islower():
        return ch.upper()
    else:
        return ch.lower()

# Call the main method to start the program
if __name__ == "__main__":
    main()
