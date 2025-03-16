from typing import List

a = None  # Declaring and initializing four integer arrays a, b, c, and d to None
b = None
c = None
d = None
n = 0  # Declaring and initializing two integer variables n and m to zero
m = 0
q = 0  # Declaring and initializing an integer variable q to zero
ans = -100  # Declaring and initializing a long variable ans to a very large negative number

def dfs(lst: List[int]) -> None:  # A recursive function named dfs that takes a list named lst as an argument
    global ans  # Declare ans as global to modify it
    if len(lst) == n:  # A conditional statement that checks if the size of the list lst is equal to the integer n
        score = 0  # Declaring and initializing a long variable score to zero

        for i in range(q):  # A for loop that calculates the score based on the condition that (lst[b[i]] - lst[a[i]] == c[i])
            score += d[i] if (lst[b[i]] - lst[a[i]] == c[i]) else 0

        ans = max(ans, score)  # Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
        return  # Returning from the function after updating the value of ans

    if lst:  # A conditional statement that checks if the list lst is not empty
        for num in range(lst[-1], m + 1):  # A for loop that adds the integer num to the list lst and recursively calls the function dfs
            lst.append(num)
            dfs(lst)
            lst.pop()
    else:  # If the list lst is empty
        for num in range(1, m + 1):  # A for loop that adds the integer num to the list lst and recursively calls the function dfs
            lst.append(num)
            dfs(lst)
            lst.pop()

if __name__ == "__main__":
    n = int(input())  # Reading the first integer n from the standard input
    m = int(input())  # Reading the second integer m from the standard input
    q = int(input())  # Reading the third integer q from the standard input

    a = [0] * q  # Allocating memory for the array a of size q
    b = [0] * q  # Allocating memory for the array b of size q
    c = [0] * q  # Allocating memory for the array c of size q
    d = [0] * q  # Allocating memory for the array d of size q

    for i in range(q):  # A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
        a[i] = int(input()) - 1  # Reading the integer a[i] from the standard input and storing it in the array a after subtracting 1 from it
        b[i] = int(input()) - 1  # Reading the integer b[i] from the standard input and storing it in the array b after subtracting 1 from it
        c[i] = int(input())  # Reading the integer c[i] from the standard input and storing it in the array c
        d[i] = int(input())  # Reading the integer d[i] from the standard input and storing it in the array d

    dfs([])  # Calling the recursive function dfs with an empty list as an argument

    print(ans)  # Printing the value of the long variable ans to the standard output

# <END-OF-CODE>
