import sys
import io

def main():
    # Define a constant number for modulo operations
    num = 998244353
    
    # Initialize input and output
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    
    # Read the number of pairs (n) from input
    n = int(input_stream.readline().strip())
    
    # Create two lists to store the two sets of integers
    ai = []
    bi = []
    
    # Read n pairs of integers from input
    for _ in range(n):
        a, b = map(int, input_stream.readline().strip().split())
        ai.append(a)
        bi.append(b)
    
    # Sort both lists to prepare for median calculation
    ai.sort()
    bi.sort()
    
    # Check if the number of elements is odd
    if n % 2 == 1:
        # Calculate the result for odd n using the median values
        result = bi[n // 2] - ai[n // 2] + 1
    else:
        # Calculate the average of the two middle values for even n
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        # Calculate the result for even n and print it
        result = int(2 * (c - b) + 1)
    
    # Output the result
    output_stream.write(f"{result}\n")
    output_stream.flush()

if __name__ == "__main__":
    main()
