def print_sequence(x, n):
    max_value = n * 2 - 1
    
    if x == 1 or x == max_value:
        print("No")
        return
    
    print("Yes")
    
    # Generate the sequence
    sequence = []
    for i in range(x + n - 1, x + n + max_value):
        sequence.append(str((i % max_value) + 1) + "\n")
    
    # Join the sequence into a single string
    result = ''.join(sequence)
    print(result)

# Read input from the user
n = int(input())
x = int(input())

# Call the print_sequence function with the inputs x and n
print_sequence(x, n)
