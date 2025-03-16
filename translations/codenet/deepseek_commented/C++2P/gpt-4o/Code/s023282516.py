def main():
    S = input().strip()
    
    divide = ["dream", "dreamer", "erase", "eraser"]
    
    # Reverse the string and the words in divide
    S = S[::-1]
    divide = [word[::-1] for word in divide]

    can = True
    i = 0
    while i < len(S):
        can2 = False  # Check if we can divide with any of the words
        for d in divide:
            if S[i:i + len(d)] == d:  # Check if we can divide with d
                can2 = True
                i += len(d)  # Move i forward
                break  # Break to avoid checking other words once we find a match
        if not can2:  # If we couldn't divide
            can = False
            break

    if can:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
