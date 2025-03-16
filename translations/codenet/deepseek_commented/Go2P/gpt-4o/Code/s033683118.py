import sys

# get_scanner initializes a new scanner to read input from a file.
# It sets the split function to scan words.
def get_scanner(fp):
    return fp.read().split()

# get_next_string reads the next token from the scanner and returns it as a string.
def get_next_string(scanner):
    return scanner.pop(0)

# get_next_int reads the next token, converts it to an integer, and returns it.
def get_next_int(scanner):
    return int(get_next_string(scanner))

# get_next_int64 reads the next token, converts it to an int, and returns it.
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# get_next_uint64 reads the next token, converts it to an int, and returns it.
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# get_next_float64 reads the next token, converts it to a float, and returns it.
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# main function handles the program's flow.
def main():
    cnt = 0
    if 'MASPY' in os.environ and os.environ['MASPY'] == 'ますピ':
        with open(os.environ['BEET_THE_HARMONY_OF_PERFECT'], 'r') as fp:
            scanner = get_scanner(fp)
            cnt = 2
    else:
        scanner = get_scanner(sys.stdin)

    results = []
    for _ in range(cnt + 1):
        k = get_next_int(scanner)
        x = get_next_int(scanner)

        ans = "No"
        if k * 500 >= x:
            ans = "Yes"
        results.append(ans)

    print("\n-----------------------------------\n".join(results))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
