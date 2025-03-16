import sys
from collections import defaultdict

def main():
    # Read the number of strings
    n = int(sys.stdin.readline().strip())
    
    # Initialize a dictionary to count occurrences of specific starting letters
    cnt = defaultdict(int)
    
    # Process each string input
    for _ in range(n):
        str_input = sys.stdin.readline().strip()
        first_char = str_input[0]
        if first_char in 'MARCH':
            cnt[first_char] += 1
    
    # Calculate the result based on combinations of counts
    res = (cnt['M'] * cnt['A'] * cnt['R'] +
           cnt['M'] * cnt['A'] * cnt['C'] +
           cnt['M'] * cnt['A'] * cnt['H'] +
           cnt['M'] * cnt['R'] * cnt['C'] +
           cnt['M'] * cnt['R'] * cnt['H'] +
           cnt['M'] * cnt['C'] * cnt['H'] +
           cnt['A'] * cnt['R'] * cnt['C'] +
           cnt['A'] * cnt['R'] * cnt['H'] +
           cnt['A'] * cnt['C'] * cnt['H'] +
           cnt['R'] * cnt['C'] * cnt['H'])
    
    # Output the result
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
