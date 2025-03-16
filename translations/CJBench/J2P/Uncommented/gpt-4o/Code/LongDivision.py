class DivisionByZeroError(Exception):
    pass

def divide(dividend, divisor):
    if divisor == 0:
        raise DivisionByZeroError("Division by zero")
    
    new_dividend = abs(dividend)
    new_divisor = abs(divisor)
    
    if dividend == 0 or new_dividend < new_divisor:
        return 0
    
    answer = []
    remainder = ""
    
    for i in range(len(str(new_dividend))):
        part = remainder + str(new_dividend)[i]
        part_value = int(part)
        
        if part_value >= new_divisor:
            quotient = 0
            while part_value >= new_divisor:
                part_value -= new_divisor
                quotient += 1
            answer.append(str(quotient))
        else:
            answer.append('0')
        
        remainder = str(part_value) if part_value != 0 else ""
    
    result = int(''.join(answer))
    
    if (dividend < 0) ^ (divisor < 0):
        result = -result
    
    if result < -2**31:
        return -2**31
    elif result > 2**31 - 1:
        return 2**31 - 1
    
    return result

if __name__ == "__main__":
    dividend = int(input())
    divisor = int(input())
    try:
        result = divide(dividend, divisor)
        print("Result:", result)
    except DivisionByZeroError as e:
        print("Error:", e)

# <END-OF-CODE>
