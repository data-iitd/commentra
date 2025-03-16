
import sys

# This method finds the majority element in the array, if it exists.
def find_majority_element(array):
    # Check if the array is null or empty.
    if array is None or len(array) == 0:
        return None

    # Find a candidate for the majority element using the Boyer-Moore Voting Algorithm.
    candidate = find_candidate(array)

    # Count the occurrences of the candidate in the array.
    count = count_occurrences(candidate, array)

    # Check if the candidate is the majority element.
    if is_majority(count, len(array)):
        return candidate

    # Return None if no majority element is found.
    return None

# Helper method to find a candidate for the majority element using the Boyer-Moore Voting Algorithm.
def find_candidate(array):
    count = 0
    candidate = -1
    for value in array:
        if count == 0:
            candidate = value
        count += (value == candidate) and 1 or -1
    return candidate

# Helper method to count the occurrences of the candidate in the array.
def count_occurrences(candidate, array):
    count = 0
    for value in array:
        if value == candidate:
            count += 1
    return count

# Helper method to check if the candidate is the majority element.
def is_majority(count, total_count):
    return 2 * count > total_count

# The entry point of the program.
def main():
    # Read the input.
    n = int(sys.stdin.readline())
    array = [int(x) for x in sys.stdin.readline().split()]

    # Find the majority element in the array.
    majority_element = find_majority_element(array)

    # Print the result.
    if majority_element is not None:
        print(majority_element)
    else:
        print("No majority element")

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
    main()

