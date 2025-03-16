

import itertools

def permutation(target, ans):
    if len(target) <= 1:
        return [ans + target]
    else:
        return [ans + target[i] + target[:i] + target[i+1:] for i in range(len(target))]

if __name__ == "__main__":
    # Read the number of strings
    n = int(input())
    # Initialize a 2D array to store the input strings
    line = [[""]] * 2
    for i in range(2):
        # Read n strings and concatenate them
        line[i][0] = "".join([input() for _ in range(n)])
    # Generate the number string for permutations
    number = "".join([str(i+1) for i in range(n)])
    # Create a list to store permutations
    listA = []
    # Generate all permutations of the number string
    for perm in itertools.permutations(number):
        listA.append("".join(perm))
    # Initialize sum to calculate the result
    sum = 0
    # Compare permutations with input strings and calculate the sum
    for j in range(len(line)):
        for i in range(len(listA)):
            if listA[i] == line[j][0]:
                if sum == 0:
                    sum += i
                else:
                    sum -= i
    # Print the absolute value of the sum
    print(abs(sum))

