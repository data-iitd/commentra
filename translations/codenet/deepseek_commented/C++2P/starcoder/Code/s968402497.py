
# Python 3 program to check if a number is a multiple of 
# a given number

# Function to check if a number is a multiple of a given number
def isMultiple(n, m):
    if (n % m == 0):
        return True
    else:
        return False

# Driver Code
if __name__ == '__main__':
    tc, n, m = map(int, input().split())
    if (n > m):
        n, m = m, n
    for i in range(1, m + 1):
        if (isMultiple(i, tc) and isMultiple(i, n)):
            print("OK")
            break
    else:
        print("NG")

