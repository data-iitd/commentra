def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    
    a = sorted(set(a))  # Remove duplicates and sort the list
    found = False
    
    for i in range(len(a) - 2):
        if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:
            found = True
            break
            
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
