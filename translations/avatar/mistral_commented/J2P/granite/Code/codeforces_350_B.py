

n = int(input())  # Reading the number of test cases from the standard input stream
a = []  # Creating an empty list 'a' to store the elements of array 'a'
b = []  # Creating an empty list 'b' to store the elements of array 'b'
num = []  # Creating an empty list 'num' to store the elements of array 'num'

for i in range(n):  # Loop to read the elements of arrays 'a' and 'b'
    a.append(int(input()))
    b.append(int(input()))

ss = ""  # Initializing an empty string'ss' to store the final answer
ans = 0  # Initializing an integer variable 'ans' to store the maximum length of the answer
st = [False] * (n + 1)  # Creating a boolean list'st' of size 'n+1'

for i in range(1, n + 1):  # Loop to find the longest chain of numbers
    if a[i - 1] == 1:  # If the current number 'i' in array 'a' is 1
        st[i] = True  # Mark the current number as visited
        sb = ""  # Initializing an empty string'sb' to store the answer
        x = b[i - 1]  # Assigning the value of 'b[i]' to 'x'
        sss = str(i)  # Converting the current number 'i' to a string and storing it in'sss'
        sb += " " + sss[::-1]  # Appending the reversed string of'sss' to'sb'
        s = 1  # Initializing an integer variable's' to 1

        while st[x] == False and num[x] == 1 and x!= 0 and a[x - 1]!= 1:  # Loop to traverse the graph
            sss = str(x)  # Converting the current number 'x' to a string and storing it in'sss'
            sb += " " + sss[::-1]  # Appending the reversed string of'sss' to'sb'
            st[x] = True  # Marking the current number 'x' as visited
            x = b[x - 1]  # Assigning the value of 'b[x]' to 'x'
            s += 1  # Incrementing the length of the current chain

        if s > ans:  # If the length of the current chain is greater than the current maximum length
            ans = s  # Updating the maximum length
            ss = sb[::-1]  # Updating the final answer

print(ans)  # Printing the maximum length of the longest chain
print(ss)  # Printing the longest chain as a string

