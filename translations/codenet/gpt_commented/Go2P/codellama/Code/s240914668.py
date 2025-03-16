
import sys

def main():
    # Set the scanner to split input by whitespace
    sc.split(bufio.ScanWords)

    # Read the number of integers
    n = nextInt()
    # Read the integers into a slice
    a = nextInts(n)

    # Initialize the answer counter
    ans = 0

    # Iterate through the slice of integers
    for i in range(n):
        # Set the left and right pointers for the current segment
        l, r = i, i+1

        # Expand the right pointer while the conditions are met
        while r+1 < n and (a[r]-a[l])*(a[r+1]-a[r]) >= 0:
            r += 1

        # Increment the answer for each segment found
        ans += 1
        # Move the left pointer to the end of the current segment
        i = r

    # Output the final count of segments
    puts(ans)
    # Flush the buffered writer to ensure all output is written
    wt.flush()

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    slice = [0.0] * n
    for i in range(n):
        slice[i] = nextFloat64()
    return slice

# Function to read a large block of text from input
def nextMega():
    buf = []
    while True:
        l, p, _ = rdr.readline()
        buf.append(l)
        if not p:
            break
    return ''.join(buf)

# Function to format and write output to the buffered writer
def putf(format, *a):
    fmt.printf(wt, format, *a)

# Function to write a line of output to the buffered writer
def puts(*a):
    fmt.println(wt, *a)

# Function to read the next string from input
def next():
    sc.scan()
    return sc.text()

# Function to read the next integer from input
def nextInt():
    i, _ = strconv.atoi(next())
    return i

# Function to read the next float64 from input
def nextFloat64():
    f, _ = strconv.parseFloat(next(), 64)
    return f

# Function to read a slice of integers from input
def nextInts(n):
    slice = [0] * n
    for i in range(n):
        slice[i] = nextInt()
    return slice

# Function to read a slice of float64 from input
def nextFloat64s(n):
    sl