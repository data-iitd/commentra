from collections import defaultdict
import sys

def main():
    reader = sys.stdin
    str_input = reader.readline().strip()
    char_count = defaultdict(int)
    odd_count = 0

    for ch in str_input:
        char_count[ch] += 1

    for count in char_count.values():
        if count % 2 != 0:
            odd_count += 1

    if odd_count <= 1 or odd_count % 2 != 0:
        print("First")
    else:
        print("Second")

if __name__ == "__main__":
    main()
