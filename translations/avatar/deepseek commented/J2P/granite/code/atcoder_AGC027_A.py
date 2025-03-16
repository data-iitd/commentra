

import sys

def main():
    # Step 1: Read an integer N and a long integer x from the standard input
    N = int(sys.stdin.readline())
    x = int(sys.stdin.readline())

    # Step 2: Read N long integers and store them in a list called sweet
    sweet = []
    for i in range(N):
        a = int(sys.stdin.readline())
        sweet.append(a)

    # Step 3: Sort the list sweet
    sweet.sort()

    # Step 4: Initialize a counter num to 0 and iterate through the sorted list sweet
    num = 0
    for i in range(N):
        # Step 5: Check if subtracting the element from x results in a non-negative value
        if x - sweet[num] >= 0:
            # Step 6: Subtract the element from x and increment the counter num
            x = x - sweet[num]
            num += 1
        else:
            # Step 7: Break out of the loop if the condition is not met
            break

    # Step 8: After the loop, if num equals N and x is greater than 0, decrement num by 1
    if (num == N) and (x > 0):
        num -= 1

    # Step 9: Print the value of num
    print(num)

if __name__ == "__main__":
    main()

