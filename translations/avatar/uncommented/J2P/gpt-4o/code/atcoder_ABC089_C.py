import sys
from collections import defaultdict

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    cnt = defaultdict(int)
    
    for i in range(1, n + 1):
        str_value = data[i]
        if str_value[0] == 'M':
            cnt['M'] += 1
        elif str_value[0] == 'A':
            cnt['A'] += 1
        elif str_value[0] == 'R':
            cnt['R'] += 1
        elif str_value[0] == 'C':
            cnt['C'] += 1
        elif str_value[0] == 'H':
            cnt['H'] += 1
    
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
    
    print(res)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
