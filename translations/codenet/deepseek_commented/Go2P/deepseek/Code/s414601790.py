def main():
    n = int(input())  # Read the number of characters in the string
    s = input()       # Read the input string

    max_cnt = 0       # Initialize max_cnt to 0, this will store the maximum value of cnt
    cnt = 0           # Initialize cnt to 0, this will keep track of the count of 'I' minus 'D'
    for r in s:       # Loop through each character in the string s
        if r == 'I':  # If the character is 'I'
            cnt += 1  # Increment cnt
        elif r == 'D':# If the character is 'D'
            cnt -= 1  # Decrement cnt

        if cnt > max_cnt:# Check if the current cnt is greater than max_cnt
            max_cnt = cnt # Update max_cnt to be equal to cnt

    print(max_cnt)    # Print the maximum value of cnt encountered

main()
