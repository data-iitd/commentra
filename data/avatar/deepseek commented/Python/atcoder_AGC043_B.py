def twos_in_factorial(n):
    # Calculate the number of factors of 2 in the factorial of n
    return n - bin(n).count('1')

def parity_of_nCr(n, i):
    # Determine the parity (odd or even) of the binomial coefficient nCr
    f = twos_in_factorial
    return f(n) - f(n - i) - f(i) > 0

if __name__ == "__main__":
    # Read an integer n and a list of integers from the input
    n = int(input())
    nums = list(map(lambda x: int(x) - 1, input().strip()))
    
    # If the list does not contain the number 1, halve each number in the list and set no_one to True
    no_one = False
    if 1 not in nums:
        nums = [num // 2 for num in nums]
        no_one = True
    
    # Initialize is_odd to False
    is_odd = False
    
    # Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for i, num in enumerate(nums):
        if not parity_of_nCr(n - 1, i) and num & 1:
            is_odd ^= 1
    
    # If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if not is_odd:
        print(0)
    else:
        print(1 << no_one)
