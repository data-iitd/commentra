def main():
    # Read input from the user and store it in the variable 's'
    s = input()
    
    # Check if the first three characters are the same or the last three characters are the same
    if (s[0] == s[1] and s[1] == s[2]) or (s[1] == s[2] and s[2] == s[3]):
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

# Call the main function
main()

