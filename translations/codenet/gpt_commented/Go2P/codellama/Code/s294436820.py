
# -----------------------------------------------------------------------------

# IO helper functions

# nextToken and nextLine are function variables that will be initialized 
# by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
nextToken = None
nextLine = None

# OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
OutputBuffer = None

# OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
OutputWriter = None

# SetInteractive configures the IO functions for interactive input/output.
def SetInteractive(w, r):
    SetUnbufferedInput(r) # Set unbuffered input for reading
    global OutputBuffer
    OutputBuffer = None # No output buffer for interactive mode
    global OutputWriter
    OutputWriter = w # Set the output writer

# Setup OutputBuffer and OutputWriter for buffered output.
def SetOutput(w):
    global OutputBuffer
    OutputBuffer = io.BufferedWriter(w) # Initialize the output buffer
    global OutputWriter
    OutputWriter = OutputBuffer # Set the output writer to the buffer

# Flushes OutputBuffer to ensure all buffered data is written out.
def Flush():
    if OutputBuffer is not None:
        OutputBuffer.flush() # Flush the buffer if it is initialized

# IsSpace checks if a byte is a whitespace character.
def IsSpace(c):
    if c == '\t' or c == '\n' or c == '\v' or c == '\f' or c == '\r' or c == ' ':
        return True
    return False

# IsNewLine checks if a byte is a newline character.
def IsNewLine(c):
    if c == '\n' or c == '\r':
        return True
    return False

# SetInput initializes the nextToken function with an input buffer.
def SetInput(r):
    global nextToken
    global nextLine
    buf = io.BytesIO() # Create a new bytes buffer
    b = [] # Buffer to hold input bytes

    i = 0 # Index for reading from buffer
    # Function to read the next token from the input
    def rest():
        nonlocal i
        while i < len(b) and IsSpace(b[i]):
            i += 1 # Skip whitespace
        if i == len(b):
            return None, io.ErrUnexpectedEOF # Return error if end of buffer is reached
        j = i
        while i < len(b) and not IsSpace(b[i]):
            i += 1 # Read until whitespace is found
        return b[j:i], None # Return the token

    # Function to initialize reading from the input
    def initial():
        nonlocal nextToken
        nonlocal nextLine
        buf.write(r.read()) # Copy input to buffer
        b = buf.getvalue() # Get bytes from the buffer
        nextToken = rest # Set nextToken to the rest function
        return rest() # Read the first token

    # Function to read the next line from the input
    def restLn():
        nonlocal i
        while i < len(b) and IsNewLine(b[i]):
            i += 1 # Skip new line characters
        if i == len(b):
            return None, io.ErrUnexpectedEOF # Return error if end of buffer is reached
        j = i
        while i < len(b) and not IsNewLine(b[i]):
            i += 1 # Read until new line is found
        return b[j:i], None # Return the line

    # Function to initialize reading lines from the input
    def initialLn():
        nonlocal nextToken
        nonlocal nextLine
        buf.write(r.read()) # Copy input to buffer
        b = buf.getvalue() # Get bytes from the buffer
        nextLine = restLn # Set nextLine to the restLn function
        return restLn() # Read the first line

    nextToken = initial # Initialize nextToken
    nextLine = initialLn # Initialize nextLine

# SetUnbufferedInput configures the nextToken function for unbuffered input.
def SetUnbufferedInput(r):
    global nextToken
    global nextLine
    buf = io.BufferedReader(r) # Create a new buffered reader
    b = [] # Buffer to hold input bytes

    i = 0 # Index for reading from buffer
    # Function to read the next token from the input
    def nextToken():
        nonlocal i
        if i == len(b): # If the buffer is empty
            b = buf.readline() # Read until newline
            if b == '':
                return None, io.ErrUnexpectedEOF # Return error if reading fails
            i = 0 # Reset index
            j = len(b) - 1
            while 0 <= j and IsSpace(b[j]):
                j -= 1 # Trim trailing whitespace
            b = b[0:j+1] # Resize buffer to remove whitespace
        while i < len(b) and IsSpace(b[i]):
            i += 1 # Skip whitespace
        j = i
        while i < len(b) and not IsSpace(b[i]):
            i += 1 # Read until whitespace is found
        if i == j:
            return None, io.ErrUnexpectedEOF # Return error if no token found
        return b[j:i], None # Return the token

# -----------------------------------------------------------------------------

# IO functions

# readb reads the next token and returns it as a byte slice.
def readb():
    b, err = nextToken() # Read the next token
    if err is not None:
        raise err # Panic if an error occurs
    return b[:len(b):len(b)] # Return the token

# reads reads the next token and returns it as a string.
def reads():
    return str(readb()) # Convert byte slice to string

# readbln reads the next line as a byte slice, excluding the trailing newline.
def readbln():
    b, err = nextLine() # Read the next line
    if err is not None:
        raise err # Panic if an error occurs
    return b[:len(b):len(b)] # Return the line

# readsln reads the next line and returns it as a string.
def readsln():
    return str(readbln()) # Convert byte slice to string

# readll reads the next token and returns it as an int64.
def readll():
    i, err = strconv.ParseInt(reads(), 10, 64) # Parse the next token as int64
    if err is not None:
        raise err.Error() # Panic if parsing fails
    return i # Return the parsed int64

# readi reads the next token and returns it as an int.
def readi():
    return int(readll()) # Convert int64 to int

# readf reads the next token and returns it as a float64.
def readf():
    f, err = strconv.ParseFloat(reads(), 64) # Parse the next token as float64
    if err is not None:
        raise err.Error() # Panic if parsing fails
    return f # Return the parsed float64

# printf writes formatted output to OutputWriter.
def printf(f, *args):
    return io.Fprintf(OutputWriter, f, *args) # Write formatted output

# println writes output to OutputWriter without formatting.
def println(*args):
    return io.Fprintln(OutputWriter, *args) # Write output without formatting

# eprintf writes formatted output to stderr.
def eprintf(f, *args):
    return io.Fprintf(os.Stderr, f, *args) # Write formatted output to stderr

# eprintln writes output to stderr without formatting.
def eprintln(*args):
    return io.Fprintln(os.Stderr, *args) # Write output without formatting to stderr

# debugf writes formatted debug output to stderr if DEBUG is enabled.
def debugf(f, *args):
    if not DEBUG:
        return # Do nothing if DEBUG is not enabled
    io.Fprintf(os.Stderr, f, *args) # Write formatted debug output

# debug writes debug output to stderr if DEBUG is enabled.
def debug(*args):
    if not DEBUG:
        return # Do nothing if DEBUG is not enabled
    io.Fprintln(os.Stderr, *args) # Write debug output

# -----------------------------------------------------------------------------

# Utilities

# sumSlice calculates the sum of a slice of integers.
def sumSlice(a):
    res = 0
    for v in a:
        res += v # Accumulate the sum
    return res # Return the total sum

# sumSlicell calculates the sum of a slice of int64.
def sumSlicell(a):
    res = 0
    for v in a:
        res += v # Accumulate the sum
    return res # Return the total sum

# readInts reads N integers from input and returns the count and the slice.
def readInts(N):
    if N == 0:
        N = readi() # Read N if it is zero
    a = [] # Create a slice of integers
    for i in range(N):
        a.append(readi()) # Read each integer
    return N, a # Return the count and the slice

# readIntsll reads N int64 values from input and returns the count and the slice.
def readIntsll(N):
    if N == 0:
        N = readi() # Read N if it is zero
    a = [] # Create a slice of int64
    for i in range(N):
        a.append(readll()) # Read each int64 value
    return N, a # Return the count and the slice

# -----------------------------------------------------------------------------

# Simple math functions

# Define large prime constants for calculations
INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

# min returns the smaller of two integers.
def min(a, b):
    if a < b:
        return a # Return a if it is smaller
    return b # Otherwise return b

# minll returns the smaller of two int64 values.
def minll(a, b):
    if a < b:
        return a # Return a if it is smaller
    return b # Otherwise return b

# minf returns the smaller of two float64 values.
def minf(a, b):
    if a < b:
        return a # Return a if it is smaller
    return b # Otherwise return b

# max returns the larger of two integers.
def max(a, b):
    if a < b:
        return b # Return b if it is larger
    return a # Otherwise return a

# maxll returns the larger of two int64 values.
def maxll(a, b):
    if a < b:
        return b # Return b if it is larger
    return a # Otherwise return a

# maxf returns the larger of two float64 values.
def maxf(a, b):
    if a < b:
        return b # Return b if it is larger
    return a # Otherwise return a

# abs returns the absolute value of an integer.
def abs(a):
    if a < 0:
        return -a # Return negative if a is less than zero
    return a # Otherwise return a

# absll returns the absolute value of an int64.
def absll(a):
    if a < 0:
        return -a # Return negative if a is less than zero
    return a # Otherwise return a

# absf returns the absolute value of a float64.
def absf(a):
    if a < 0:
        return -a # Return negative if a is less than zero
    return a # Otherwise return a

# egcd computes the extended GCD of a