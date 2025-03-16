import sys
from collections import defaultdict

def main():
    input_str = sys.stdin.readline().strip()
    char_count = defaultdict(int)
    odd_count = 0

    for ch in input_str:
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

# <END-OF-CODE>
