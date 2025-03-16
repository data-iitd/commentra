def main():
    # Read a string from the standard input and store it in s
    s = input()
    
    # Assign the first character of s to t
    t = s[0]
    
    # Append the size of s minus 2 to t
    t += str(len(s) - 2)
    
    # Append the last character of s to t
    t += s[-1]
    
    # Print the modified string t
    print(t)

main()
