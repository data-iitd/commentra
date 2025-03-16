def read_string():
    return input().strip()

def main():
    S = read_string()
    T = read_string()
    max_count = 0
    
    for i in range(len(S) - len(T) + 1):
        count = 0
        for j in range(len(T)):
            if S[i + j] == T[j]:
                count += 1
        if max_count < count:
            max_count = count
            
    print(len(T) - max_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
