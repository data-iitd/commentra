# Read the number of elements and the list of integers from input
n, a = int(input()), list(map(int, input().split()))

# Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
if sum(a) % (n * (n + 1) / 2):
    # If not divisible, print "NO" and exit
    print("NO")
else:
    # Calculate the average value 'k' that each element should contribute
    k = sum(a) / (n * (n + 1) / 2)
    
    # Append the first element of 'a' to the end of the list to facilitate circular calculations
    a += [a[0]]
    
    # Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
    if sum([(k - i + j) % n for i, j in zip(a[1:], a)]) or sum([(k - i + j) / n >= 0 for i, j in zip(a[1:], a)]) != n:
        # If either condition fails, print "NO"
        print("NO")
    else:
        # If both conditions are satisfied, print "YES"
        print("YES")
