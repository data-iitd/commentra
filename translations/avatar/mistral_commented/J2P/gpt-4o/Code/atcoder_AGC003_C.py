import sys
import heapq

def main():
    # Reading the number of elements in the array
    N = int(sys.stdin.readline().strip())

    # Creating an empty dictionary to store the index of each unique element
    index_map = {}

    # Creating an empty min-heap to store the elements in ascending order
    nums = []

    # Reading the elements one by one and adding them to the min-heap and dictionary
    for i in range(N):
        tmp = int(sys.stdin.readline().strip())  # Reading an element
        heapq.heappush(nums, tmp)  # Adding the element to the min-heap
        index_map[tmp] = i  # Adding the index of the element to the dictionary

    bin = 0  # Initializing a binary index variable
    diff = 0  # Initializing a variable to store the difference in parity between elements

    # Processing the elements in the min-heap
    while nums:
        num = heapq.heappop(nums)  # Polling an element from the min-heap
        idx = index_map[num]  # Getting the index of the element from the dictionary

        # Checking if the binary index and the index of the current element have opposite parity
        if (bin % 2) != (idx % 2):
            diff += 1  # Incrementing the difference if the condition is true

        bin += 1  # Incrementing the binary index
        bin %= 2  # Setting the binary index to 0 or 1 based on the current parity

    # Calculating and printing the answer
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
