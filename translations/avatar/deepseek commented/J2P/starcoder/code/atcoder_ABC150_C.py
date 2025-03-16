
import sys

def permutation(list, target, ans):
    if len(target) <= 1:
        list.append(ans + target)
    else:
        for i in range(len(target)):
            permutation(list, target[:i] + target[i + 1:], ans + target[i])
    return list

if __name__ == "__main__":
    # Read the number of strings
    n = int(sys.stdin.readline())
    # Initialize a 2D array to store the input strings
    line = [["", ""], ["", ""]]
    for i in range(2):
        for j in range(n):
            line[i][0] += sys.stdin.readline()
    # Generate the number string for permutations
    number = ""
    for i in range(1, n + 1):
        number += str(i)
    # Create a list to store permutations
    listA = []
    # Generate all permutations of the number string
    permutation(listA, number, "")
    # Initialize sum to calculate the result
    sum = 0
    # Compare permutations with input strings and calculate the sum
    for j in range(2):
        for i in range(len(listA)):
            if listA[i] == line[j][0]:
                if sum == 0:
                    sum += i
                else:
                    sum -= i
    # Print the absolute value of the sum
    print(abs(sum))

