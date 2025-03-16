import sys

def main():
    # Reading the number of elements in the array from the input
    n = int(input().strip())
    
    # Reading 'n' integers from the user and storing them in a list
    arr = list(map(int, input().strip().split()))
    
    # Initialize the answer with the absolute value of the first element
    answer = abs(arr[0])
    
    # Loop to calculate the sum of absolute differences between consecutive elements
    for i in range(1, n):
        answer += abs(arr[i] - arr[i - 1])
    
    # Output the final calculated answer
    print(answer)

if __name__ == "__main__":
    main()
