import sys

def main():
    # Reading the first integer input from the console
    n = int(input().strip())
    # Reading the second string input from the console
    s = input().strip()
    # Initializing the count for 'R' characters to zero
    rc = 0
    # Initializing the count for 'G' characters to zero
    gc = 0
    # Initializing the count for other characters to zero
    bc = 0

    # Iterating through each character in the string
    for char in s:
        if char == 'R':
            rc += 1  # Incrementing the count for 'R' characters
        elif char == 'G':
            gc += 1  # Incrementing the count for 'G' characters
        else:
            bc += 1  # Incrementing the count for other characters

    # Multiplying the counts of 'R', 'G' and other characters to get the initial result
    result = rc * gc * bc

    # Iterating through each pair of indices in the string
    for i in range(n):
        for k in range(i + 1, n):
            if (i + k) % 2 == 0:  # Checking if the sum of the indices is even
                is_ = s[i]  # Storing the character at the index i
                ks_ = s[k]  # Storing the character at the index k
                js_ = s[(i + k) // 2]  # Storing the character at the midpoint between i and k
                if is_ != ks_ and ks_ != js_ and js_ != is_:  # Checking if the characters at the three indices are different
                    result -= 1  # Decrementing the result if they are

    # Printing the final result to the console
    print(result)

if __name__ == "__main__":
    main()

