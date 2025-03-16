
n = int(input()) # Read the number of elements in the sequence
k = int(input()) # Read the initial value of k

i = 1
req = 1

while k - req >= 0:
    if k - req >= 0:
        k = k - req
    else:
        break
    i += 1
    if i % n!= 0:
        req = i % n
    else:
        req = n

print(k) # Print the final value of k

