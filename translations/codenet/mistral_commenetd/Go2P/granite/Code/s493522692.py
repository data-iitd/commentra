

# Util functions

def next_str():
    # Scans the next token, a rune, into sc.Text().
    sc.Scan()
    # Returns the text scanned into sc.Text() as a string.
    return sc.Text()

# With a comment explaining what the function does:
# Scans the next token, a rune, into sc.Text() and returns it as a string.
def next_str():
    # Scans the next token, a rune, into sc.Text().
    sc.Scan()
    # Returns the text scanned into sc.Text() as a string.
    return sc.Text()

def next_int():
    # Scans the next token, a string, into sc.Text().
    # Converts the string to an integer using int() and returns it.
    sc.Scan()
    i = int(sc.Text())
    if e := recover(); e!= None:
        panic(e)
    return i

# With a comment explaining what the function does:
# Scans the next token, a string, into sc.Text() and converts it to an integer.
def next_int():
    # Scans the next token, a string, into sc.Text().
    sc.Scan()
    # Converts the string to an integer using int() and returns it.
    i = int(sc.Text())
    # Recovers from any panic that might occur during the conversion.
    if e := recover(); e!= None:
        panic(e)
    # Returns the integer.
    return i

# Helper functions for mathematical operations

def max_int(a, b):
    # Returns the maximum of two integers.
    if a > b:
        return a
    else:
        return b

# With a comment explaining what the function does:
# Returns the maximum of two integers.
def max_int(a, b):
    # If 'a' is greater than 'b', return 'a'.
    if a > b:
        return a
    else:
        # Otherwise, return 'b'.
        return b

def min_int(a, b):
    # Returns the minimum of two integers.
    if a > b:
        return b
    else:
        return a

# With a comment explaining what the function does:
# Returns the minimum of two integers.
def min_int(a, b):
    # If 'a' is greater than 'b', return 'b'.
    if a > b:
        return b
    else:
        # Otherwise, return 'a'.
        return a

def abs_int(a):
    # Returns the absolute value of an integer.
    if a >= 0:
        return a
    else:
        return -a

# With a comment explaining what the function does:
# Returns the absolute value of an integer.
def abs_int(a):
    # If the integer is non-negative, return it as is.
    if a >= 0:
        return a
    else:
        # Otherwise, return the negative of the integer.
        return -a

def abs_float64(a):
    # Returns the absolute value of a floating-point number.
    if a >= 0:
        return a
    else:
        return -a

# With a comment explaining what the function does:
# Returns the absolute value of a floating-point number.
def abs_float64(a):
    # If the floating-point number is non-negative, return it as is.
    if a >= 0:
        return a
    else:
        # Otherwise, return the negative of the floating-point number.
        return -a

def max_float64(a, b):
    # Returns the maximum of two floating-point numbers.
    if a > b:
        return a
    else:
        return b

# With a comment explaining what the function does:
# Returns the maximum of two floating-point numbers.
def max_float64(a, b):
    # If 'a' is greater than 'b', return 'a'.
    if a > b:
        return a
    else:
        # Otherwise, return 'b'.
        return b

def min_float64(a, b):
    # Returns the minimum of two floating-point numbers.
    if a > b:
        return b
    else:
        return a

# With a comment explaining what the function does:
# Returns the minimum of two floating-point numbers.
def min_float64(a, b):
    # If 'a' is greater than 'b', return 'b'.
    if a > b:
        return b
    else:
        # Otherwise, return 'a'.
        return a

def str2int(s):
    # Converts a string to an integer.
    n = int(s)
    return n

# With a comment explaining what the function does:
# Converts a string to an integer.
def str2int(s):
    # Attempts to convert the string to an integer using int().
    n = int(s)
    # Returns the integer.
    return n

def reverse(s):
    # Reverses a given string.
    runes = list(s)
    # Iterates through the rune slice from both ends and swaps the elements.
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        # Swaps the elements at the current indices.
        runes[i], runes[j] = runes[j], runes[i]
    }
    # Returns the reversed string.
    return ''.join(runes)

# With a comment explaining what the function does:
# Reverses a given string.
def reverse(s):
    # Initializes a rune slice with the given string.
    runes = list(s)
    # Iterates through the rune slice from both ends and swaps the elements.
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        # Swaps the elements at the current indices.
        runes[i], runes[j] = runes[j], runes[i]
    }
    # Returns the reversed string.
    return ''.join(runes)

def pow_int(p, q):
    # Calculates 'p' raised to the power of 'q'.
    return int(math.Pow(float64(p), float64(q))

# With a comment explaining what the function does:
# Calculates 'p' raised to the power of 'q'.
def pow_int(p, q):
    // Calculates 'p' raised to the power of 'q' using the math.Pow() function.
    return int(math.Pow(float64(p), float64(q))

def is_prime(x):
    # Checks if a given number is prime.
    if x == 1:
        // 1 is not a prime number.
        return false
    if x == 2:
        // 2 is a prime number.
        return true
    }
    // If the number is even, it's not a prime number.
    if x%2 == 0 {
        return false
    }
    // If the number is even, it's not a prime number.
    if x%2 == 0 {
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    rootx := int(math.Sqrt(float64(x))
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterates through the numbers from 3 to the square root of 'x'.
    for i := 3; i <= rootx; i++ {
        // Checks if any of the numbers from 3 to the square root of 'x'.
        return false
    }
    // Iterat