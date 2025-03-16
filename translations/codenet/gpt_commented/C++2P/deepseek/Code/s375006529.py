def main():
    # Read the input string from the user
    s = input()
    
    # Get the size of the input string
    n = len(s)
    
    # Initialize an array to count occurrences of each character (a-z)
    v = [0] * 26
    
    # Count the frequency of each character in the string
    for i in range(n):
        v[ord(s[i]) - ord('a')] += 1
    
    # Assume the answer is "Yes" initially
    ans = "Yes"
    
    # Check if each character's count is even
    for count in v:
        if count % 2 != 0:
            ans = "No"
            break
    
    # Output the result
    print(ans)

main()
