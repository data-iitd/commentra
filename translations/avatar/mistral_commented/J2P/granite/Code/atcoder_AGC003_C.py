
import sys
import heapq

def main():
    # Reading the number of elements in the array
    N = int(input())

    # Creating an empty list to store the elements
    nums = []

    # Reading the elements one by one and adding them to the list
    for i in range(N):
        tmp = int(input())
        nums.append(tmp)

    # Creating an empty dictionary to store the index of each unique element
    map = {}

    # Adding the elements and their indices to the dictionary
    for i in range(N):
        map[nums[i]] = i

    # Creating an empty list to store the indices of the elements in ascending order
    heapq.heapify(nums)

    bin = 0
    diff = 0

    # Processing the elements in the list
    while nums:
        num = heapq.heappop(nums)
        idx = map[num]

        # Checking if the binary index and the index of the current element have opposite parity
        if (bin % 2)!= (idx % 2):
            diff += 1

        bin += 1
        bin %= 2

    # Calculating and printing the answer
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()

