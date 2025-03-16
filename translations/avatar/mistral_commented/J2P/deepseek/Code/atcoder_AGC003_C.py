import sys
from collections import defaultdict, deque

# Final static constant for the maximum size of the array
NUM = int(1e5 + 2)

def main():
    # Creating a Scanner object to read input
    sc = sys.stdin
    N = int(sc.readline().strip())  # Reading the number of elements in the array

    # Creating an empty HashMap to store the index of each unique element
    map_ = defaultdict(int)

    # Creating an empty PriorityQueue to store the elements in ascending order
    nums = []

    # Reading the elements one by one and adding them to the PriorityQueue and HashMap
    for i in range(N):
        tmp = int(sc.readline().strip())  # Reading an element
        nums.append(tmp)  # Adding the element to the PriorityQueue
        map_[tmp] = i  # Adding the index of the element to the HashMap

    bin_ = 0  # Initializing a binary index variable
    diff = 0  # Initializing a variable to store the difference in parity between elements

    # Processing the elements in the PriorityQueue
    nums.sort()
    for num in nums:
        idx = map_[num]  # Getting the index of the element from the HashMap

        # Checking if the binary index and the index of the current element have opposite parity
        if (bin_ % 2) != (idx % 2):
            diff += 1  # Incrementing the difference if the condition is true

        bin_ += 1  # Incrementing the binary index
        bin_ %= 2  # Setting the binary index to 0 or 1 based on the current parity

    # Calculating and printing the answer
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()
