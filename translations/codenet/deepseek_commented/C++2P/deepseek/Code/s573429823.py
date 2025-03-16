def main():
    # Read the value of n from the standard input
    n = int(input())
    
    # Initialize a boolean variable to False
    flg = False
    
    # Check if n is less than 4. If so, print "No" and exit.
    if n < 4:
        print("No")
    else:
        # Check all possible combinations of 4s and 7s that sum up to n
        for i in range(n // 4 + 1):
            for j in range(n // 7 + 1):
                if (i * 4 + j * 7) == n:
                    flg = True
                    break
            if flg:
                break
        
        # Check the value of flg and print "Yes" or "No" accordingly
        if flg:
            print("Yes")
        else:
            print("No")

# Call the main function
main()

