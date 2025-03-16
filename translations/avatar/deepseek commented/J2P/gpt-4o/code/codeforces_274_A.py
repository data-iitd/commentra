# Step 1: Import necessary classes
import sys

def main():
    # Step 2: Initialize input
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Step 3: Read input values
    k = int(data[1])  # Step 3: Read input values
    arr = list(map(int, data[2:n+2]))  # Step 3: Read input values
    set_ = set()  # Step 3: Read input values

    # Step 5: Sort the array
    arr.sort()

    count = 0  # Step 6: Initialize count variable

    # Step 7: Iterate through the array
    for i in range(n):
        if arr[i] % k != 0:  # Check if the element is not divisible by k
            count += 1  # Increment the count
            set_.add(arr[i])  # Add the element to the set
        elif (arr[i] // k) not in set_:  # Check if the quotient is not in the set
            count += 1  # Increment the count
            set_.add(arr[i])  # Add the element to the set

    print(count)  # Step 8: Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
