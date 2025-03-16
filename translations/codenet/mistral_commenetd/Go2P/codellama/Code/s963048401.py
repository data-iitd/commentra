
# Initialize the scanner buffer and split function for the scanner
sc = bufio.Scanner(sys.stdin)
sc.buffer(buf, mod)
sc.split(bufio.ScanWords)

# Read the number of elements in the array
n = int(sc.scan())

# Initialize an array of size n to store the elements
as = [0] * n

# Read the elements of the array into the as list
for i in range(n):
    as[i] = int(sc.scan())

# Initialize an empty list xs to store the unique elements
xs = [as[0]]

# Iterate through the array and add unique elements to the xs list
for j in range(1, n):
    # Binary search to find the index where the current element should be inserted in the xs list
    idx = bisect.bisect_left(xs, as[j])

    # If the current element is not already present in the xs list, append it
    if idx == len(xs):
        xs.append(as[j])
    else:
        # Otherwise, replace the element at the found index with the current element
        xs[idx] = as[j]

# Print the length of the xs list
print(len(xs))

