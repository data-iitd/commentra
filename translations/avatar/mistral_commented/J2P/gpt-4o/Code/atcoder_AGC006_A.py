import sys

N = 200 + 10  # Initializing the size of the arrays
f = [0] * N  # Initializing the failure function array
b = [''] * N  # Initializing the character arrays

def getFail(b, m):
    j = 0
    f[0] = f[1] = 0  # Initializing the first two elements of the failure function array

    # Main logic of the function
    for i in range(2, m + 1):
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]  # Searching for the longest common prefix of the current and previous strings
        if b[j + 1] == b[i]:
            j += 1  # If the characters match, move to the next character in the current string
        f[i] = j  # Updating the failure function for the current index

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])  # Reading the number of characters in the strings
    s1 = data[1]  # Reading the first string
    str = data[2]  # Reading the second string

    cnt = 0  # Initializing a counter for the number of characters in the combined string

    # Concatenating the two strings and creating character arrays for each
    for i in range(n):
        b[cnt + 1] = str[i]
        cnt += 1
    for i in range(n):
        b[cnt + 1] = s1[i]
        cnt += 1

    getFail(b, cnt)  # Calling the getFail function to compute the failure function

    len_common_prefix = min(f[cnt], min(n, n))  # Computing the length of the longest common prefix

    print(2 * n - len_common_prefix)  # Writing the output to the console

if __name__ == "__main__":
    main()

# <END-OF-CODE>
