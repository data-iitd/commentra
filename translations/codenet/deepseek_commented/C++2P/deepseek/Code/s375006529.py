def main():
    # Step 1: Reading the Input
    s = input()

    # Step 2: Calculating the Size of the String
    n = len(s)

    # Step 3: Initializing an Array to Count Character Frequencies
    v = [0] * 26

    # Step 4: Counting Character Frequencies
    for i in range(n):
        v[ord(s[i]) - ord('a')] += 1

    # Step 5: Determining the Result
    ans = "Yes"
    for i in range(26):
        if v[i] % 2 != 0:
            ans = "No"
            break

    # Step 6: Outputting the Result
    print(ans)

main()
