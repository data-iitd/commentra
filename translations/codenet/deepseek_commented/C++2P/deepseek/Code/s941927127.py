def main():
    W = input()
    
    # Sort the string
    W = ''.join(sorted(W))
    
    # Check for character pairs
    i = 0
    while i < len(W):
        if W.count(W[i]) % 2 != 0:
            print("No")
            return
        i += 2
    
    # Output result
    print("Yes")

if __name__ == "__main__":
    main()

