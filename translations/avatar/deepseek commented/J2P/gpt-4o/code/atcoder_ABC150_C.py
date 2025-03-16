import itertools

def permutation(target):
    # Generates all permutations of a given string
    return [''.join(p) for p in itertools.permutations(target)]

def main():
    # Read the number of strings
    n = int(input())
    # Initialize a list to store the input strings
    line = ["", ""]
    
    for i in range(2):
        # Read n strings and concatenate them
        for j in range(n):
            line[i] += input()
    
    # Generate the number string for permutations
    number = ''.join(str(i) for i in range(1, n + 1))
    
    # Generate all permutations of the number string
    listA = permutation(number)
    
    # Initialize sum to calculate the result
    sum_result = 0
    
    # Compare permutations with input strings and calculate the sum
    for j in range(len(line)):
        for i in range(len(listA)):
            if listA[i] == line[j]:
                if sum_result == 0:
                    sum_result += i
                else:
                    sum_result -= i
    
    # Print the absolute value of the sum
    print(abs(sum_result))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
