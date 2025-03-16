import sys

def main():
    inp = sys.stdin.readline().strip()  # Reading the first line and stripping whitespace
    n = int(inp[0])  # Extracting the integer n from the input
    m = int(inp[1])  # Extracting the integer m from the input

    ans = []  # Initializing a list to store the resulting strings

    for i in range(n):  # Looping through each row
        str_row = sys.stdin.readline().strip()  # Reading the current row as a string
        temp = []  # Creating a list to build the resulting string for the current row

        for j in range(m):  # Looping through each character in the row
            if str_row[j] == '-':  # Checking if the character is a '-'
                temp.append("-")  # Appending '-' to the list
            else:
                if (i + j) % 2 == 1:  # Checking if the sum of indices is odd
                    temp.append("W")  # Appending 'W' if the sum is odd
                else:
                    temp.append("B")  # Appending 'B' if the sum is even

        ans.append(''.join(temp))  # Joining the list into a string and storing it in the ans list

    for row in ans:  # Looping through each row again to print the results
        print(row)  # Printing the resulting string for the current row

if __name__ == "__main__":
    main()

# <END-OF-CODE>
