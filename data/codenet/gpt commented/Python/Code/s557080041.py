# Get user input
N = input()

# Check if the input is zero
if N == 0:
    print('Yes')  # If N is zero, print 'Yes' as it meets the condition
else:
    # Convert the input to a string for processing
    N = str(N)
    
    # Create a list of characters from the string representation of N
    L = list(N)
    
    # Convert each character in the list back to an integer
    L = [int(s) for s in L]
    
    # Calculate the sum of the digits in the list
    X = sum(L)
    
    # Check if the sum of the digits is divisible by 9
    if X % 9 == 0:
        print('Yes')  # If divisible by 9, print 'Yes'
    else:
        print('No')   # If not divisible by 9, print 'No'
