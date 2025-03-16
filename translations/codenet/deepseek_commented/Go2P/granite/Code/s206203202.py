

def Abs(x):
    if x < 0:
        return -x
    return x

def min(a, b):
    if a > b:
        return b
    return a

N, K = map(int, input().split()) # Read two integers from input

x = N % K # Calculate the remainder of N divided by K

x = min(Abs(x-K), x) # Calculate the minimum of the absolute difference and x itself
print(x) # Print the result

