import sys

def read_string():
    return sys.stdin.readline().strip()

def main():
    S = read_string()
    T = read_string()
    
    max_match = 0
    
    for i in range(len(S) - len(T) + 1):
        match_count = 0
        for j in range(len(T)):
            if S[i + j] == T[j]:
                match_count += 1
        if match_count > max_match:
            max_match = match_count
    
    print(len(T) - max_match)

