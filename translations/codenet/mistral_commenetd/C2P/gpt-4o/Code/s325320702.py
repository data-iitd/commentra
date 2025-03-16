# Include necessary standard libraries

def cin():
    return int(input())

# Function to find the number of multiples of d in the range [l, r]

def main():
    l = cin()
    r = cin()
    d = cin()
    
    ans = 0
    for i in range(l, r + 1):
        if i % d == 0:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
