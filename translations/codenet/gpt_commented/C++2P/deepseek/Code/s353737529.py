def convert_to_negabinary(n):
    if n == 0:
        return '0'
    
    s = ""
    while n != 0:
        if n % 2 == 0:
            s += '0'
        else:
            s += '1'
        
        n -= abs(n % 2)
        n //= -2
    
    return s[::-1]

# Read an integer from standard input
n = int(input())

# Convert the number to negabinary and output the result
result = convert_to_negabinary(n)
print(result)
