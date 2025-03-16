
# Scanner to read input from standard input
sc = input()

# Function to read a single line of input
def read():
    return input()

# Function to perform addition of two integers
def add(a, b):
    return a + b

# Function to perform subtraction of two integers
def sub(a, b):
    return a - b

# Function to perform multiplication of two integers
def mul(a, b):
    return a * b

# Function to perform division of two integers
def div(a, b):
    return a / b

# Function to perform modulus of two integers
def mod(a, b):
    return a % b

# Function to perform exponentiation of two integers
def exp(a, b):
    return a ** b

# Function to perform bitwise AND of two integers
def and_(a, b):
    return a & b

# Function to perform bitwise OR of two integers
def or_(a, b):
    return a | b

# Function to perform bitwise XOR of two integers
def xor(a, b):
    return a ^ b

# Function to perform bitwise NOT of an integer
def not_(a):
    return ~a

# Function to perform left shift of an integer
def lshift(a, b):
    return a << b

# Function to perform right shift of an integer
def rshift(a, b):
    return a >> b

# Function to perform floor division of two integers
def floordiv(a, b):
    return a // b

# Function to perform true division of two integers
def truediv(a, b):
    return a / b

# Function to perform remainder of two integers
def remainder(a, b):
    return a % b

# Function to perform power of two integers
def pow(a, b):
    return a ** b

# Function to perform absolute value of an integer
def abs(a):
    return abs(a)

# Function to perform sign of an integer
def sign(a):
    return a if a > 0 else -a

# Function to perform factorial of an integer
def factorial(a):
    if a == 0:
        return 1
    else:
        return a * factorial(a - 1)

# Function to perform gcd of two integers
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# Function to perform lcm of two integers
def lcm(a, b):
    return (a * b) // gcd(a, b)

# Function to perform is_prime of an integer
def is_prime(a):
    if a == 1 or a == 0:
        return False
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return False
    return True

# Function to perform is_even of an integer
def is_even(a):
    return a % 2 == 0

# Function to perform is_odd of an integer
def is_odd(a):
    return a % 2 != 0

# Function to perform is_palindrome of a string
def is_palindrome(a):
    return a == a[::-1]

# Function to perform is_anagram of two strings
def is_anagram(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_substring of two strings
def is_substring(a, b):
    return b in a

# Function to perform is_rotation of two strings
def is_rotation(a, b):
    return b in a * 2

# Function to perform is_interleaving of three strings
def is_interleaving(a, b, c):
    return a + b == c or a + c == b or b + c == a

# Function to perform is_interleaving_of_three_strings of three strings
def is_interleaving_of_three_strings(a, b, c):
    return a + b + c == b + a + c or a + b + c == c + a + b or b + a + c == a + b + c or b + a + c == c + b + a or c + a + b == a + b + c or c + a + b == b + c + a or c + b + a == a + c + b or c + b + a == b + a + c

# Function to perform is_permutation_of_string of two strings
def is_permutation_of_string(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting of two strings
def is_permutation_of_string_using_counting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_sorting of two strings
def is_permutation_of_string_using_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_hashing of two strings
def is_permutation_of_string_using_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bit_manipulation of two strings
def is_permutation_of_string_using_bit_manipulation(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_xor of two strings
def is_permutation_of_string_using_xor(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort of two strings
def is_permutation_of_string_using_counting_sort(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort of two strings
def is_permutation_of_string_using_radix_sort(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort of two strings
def is_permutation_of_string_using_bucket_sort(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing of two strings
def is_permutation_of_string_using_counting_sort_with_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing of two strings
def is_permutation_of_string_using_radix_sort_with_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing of two strings
def is_permutation_of_string_using_bucket_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing_and_sorting of two strings
def is_permutation_of_string_using_counting_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing_and_sorting(a, b):
    return sorted(a) == sorted(b)

# Function to perform is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and_hashing_and_sorting of two strings
def is_permutation_of_string_using_radix_sort_with_hashing_and_sorting_and_xor_and_bit_manipulation_and_sorting_and