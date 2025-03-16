
# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# Scanner structure definition
class scanner:
    # Initialize a new scanner instance
    def __init__(self):
        self.r = bufio.Reader(sys.stdin, 1000)
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = str(self.buf[start:self.p])
        self.p++
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return str(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        v, _ = strconv.Atoi(self.next())
        return v

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(str(self.buf[start:self.p]), 10, 0)
                result.append(int(v))
                start = self.p + 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # ReadLine function to read a line from the standard input
    def readLine(self):
        self.buf = []
        for:
            l, p, e = self.r.readline()
            if e != nil:
                panic(e)
            self.buf = append(self.buf, l...)
            if not p:
                break

# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# Scanner structure definition
class scanner:
    # Initialize a new scanner instance
    def __init__(self):
        self.r = bufio.Reader(sys.stdin, 1000)
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = str(self.buf[start:self.p])
        self.p++
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return str(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        v, _ = strconv.Atoi(self.next())
        return v

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(str(self.buf[start:self.p]), 10, 0)
                result.append(int(v))
                start = self.p + 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # ReadLine function to read a line from the standard input
    def readLine(self):
        self.buf = []
        for:
            l, p, e = self.r.readline()
            if e != nil:
                panic(e)
            self.buf = append(self.buf, l...)
            if not p:
                break

# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# Scanner structure definition
class scanner:
    # Initialize a new scanner instance
    def __init__(self):
        self.r = bufio.Reader(sys.stdin, 1000)
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = str(self.buf[start:self.p])
        self.p++
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return str(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        v, _ = strconv.Atoi(self.next())
        return v

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(str(self.buf[start:self.p]), 10, 0)
                result.append(int(v))
                start = self.p + 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # ReadLine function to read a line from the standard input
    def readLine(self):
        self.buf = []
        for:
            l, p, e = self.r.readline()
            if e != nil:
                panic(e)
            self.buf = append(self.buf, l...)
            if not p:
                break

# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# Scanner structure definition
class scanner:
    # Initialize a new scanner instance
    def __init__(self):
        self.r = bufio.Reader(sys.stdin, 1000)
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = str(self.buf[start:self.p])
        self.p++
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return str(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        v, _ = strconv.Atoi(self.next())
        return v

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = strconv.ParseInt(str(self.buf[start:self.p]), 10, 0)
                result.append(int(v))
                start = self.p + 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # ReadLine function to read a line from the standard input
    def readLine(self):
        self.buf = []
        for:
            l, p, e = self.r.readline()
            if e != nil:
                panic(e)
            self.buf = append(self.buf, l...)
            if not p:
                break

# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# Scanner structure definition
class scanner:
    # Initialize a new scanner instance
    def __init__(self):
      