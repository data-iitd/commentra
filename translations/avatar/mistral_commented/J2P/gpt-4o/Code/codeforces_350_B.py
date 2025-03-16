# Importing the necessary modules
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the number of test cases

    a = [0] * (n + 1)  # Creating an integer list 'a' of size 'n+1'
    b = [0] * (n + 1)  # Creating an integer list 'b' of size 'n+1'
    num = [0] * (n + 1)  # Creating an integer list 'num' of size 'n+1'

    for i in range(1, n + 1):  # Loop to read the elements of lists 'a' and 'b'
        a[i], b[i] = map(int, sys.stdin.readline().strip().split())

    ss = ""  # Initializing an empty string 'ss' to store the final answer
    ans = 0  # Initializing an integer variable 'ans' to store the maximum length of the answer
    st = [False] * (n + 1)  # Creating a boolean list 'st' of size 'n+1'

    for i in range(1, n + 1):  # Loop to find the longest chain of numbers
        if a[i] == 1:  # If the current number 'i' in list 'a' is 1
            st[i] = True  # Mark the current number as visited
            sb = []  # Creating a list 'sb' to store the answer
            x = b[i]  # Assigning the value of 'b[i]' to 'x'
            sss = str(i)[::-1]  # Reversing the string of the current number 'i'
            sb.append(sss)  # Appending the reversed string of 'sss' to 'sb'
            s = 1  # Initializing an integer variable 's' to 1

            while not st[x] and num[x] == 1 and x != 0 and a[x] != 1:  # Loop to traverse the graph
                sss = str(x)[::-1]  # Reversing the string of the current number 'x'
                sb.append(sss)  # Appending the reversed string of 'sss' to 'sb'
                st[x] = True  # Marking the current number 'x' as visited
                x = b[x]  # Assigning the value of 'b[x]' to 'x'
                s += 1  # Incrementing the length of the current chain

            if s > ans:  # If the length of the current chain is greater than the current maximum length
                ans = s  # Updating the maximum length
                ss = ''.join(reversed(sb))  # Updating the final answer

    print(ans)  # Printing the maximum length of the longest chain
    print(ss)  # Printing the longest chain as a string

if __name__ == "__main__":
    main()

# <END-OF-CODE>
