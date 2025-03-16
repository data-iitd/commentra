
n = int(input()) # 1. Reading the input number of elements (n)
a = [int(input()) for _ in range(n)] # 2. Reading the elements into a list (a)
b = [] # 3. Creating a list (b) to store the longest increasing subsequence
for v in a: # 4. Finding the longest increasing subsequence
    x = bisect.bisect_left(b, v)
    if x == len(b):
        b.append(v)
    else:
        b[x] = v
print(len(b)) # 5. Outputting the length of the longest increasing subsequence
