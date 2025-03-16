import sys

def main():
    n = int(input().strip())  # Step 1: Read the input value N
    a = list(map(int, input().strip().split()))  # Step 2: Read the elements of the array A
    count = 0  # Step 3: Initialize a counter 'count' to zero
    i = 0
    while i < n:
        if i == n - 1:
            count += 1  # Step 5: Check if the current index i is the last index
        elif a[i] == a[i + 1]:  # Step 6: If the current element is equal to the next element
            pass
        elif a[i] < a[i + 1]:  # Step 7: If the current element is less than the next element
            while i < n - 1 and a[i] <= a[i + 1]:
                i += 1
            count += 1
        else:  # Step 8: If the current element is greater than the next element
            while i < n - 1 and a[i] >= a[i + 1]:
                i += 1
            count += 1
        i += 1
    print(count)  # Step 9: Print the value of the counter 'count'

if __name__ == "__main__":
    main()
