# Include standard input/output library
# Include string manipulation library

def main():  # Declare the main function
    str_input, p = input().split()  # Read two strings from the standard input and store them in str_input and p respectively
    tmp = str_input  # Copy the contents of str_input to tmp
    str_input += tmp  # Concatenate the contents of str_input with itself

    slen = len(str_input)  # Get the length of str_input and store it in slen
    plen = len(p)  # Get the length of p and store it in plen

    flag = 0  # Initialize flag to 0
    for i in range(slen - plen):  # Iterate through the string str_input from the beginning to the end - plen characters
        if str_input[i:i + plen] == p:  # Compare the substring of str_input starting from index i with length plen to p
            flag = 1  # If the comparison is successful, set flag to 1

    if flag: 
        print("Yes")  # If flag is 1, print "Yes" to the standard output
    else: 
        print("No")  # If flag is 0, print "No" to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
