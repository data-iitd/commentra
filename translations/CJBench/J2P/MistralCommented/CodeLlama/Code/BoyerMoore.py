
import sys

def find_majority_element(array):
    # Check if the array is empty or None, return None if so
    if array is None or len(array) == 0:
        return None

    candidate = find_candidate(array)
    # Determine the candidate element

    count = count_occurrences(candidate, array)
    # Count the occurrences of the candidate element in the array

    if is_majority(count, len(array)):
        # If the candidate element has more than half the total count in the array, it's the majority element
        return candidate

    return None
    # Return None if the candidate element is not the majority element

def find_candidate(array):
    count = 0
    candidate = None
    # Initialize the count and candidate variables

    for value in array:
        if count == 0:
            # If there's no current candidate, set the first encountered value as the candidate
            candidate = value
        count += (value == candidate) - (value != candidate)
        # Increment the count if the current value is the same as the candidate, otherwise decrement it
    return candidate
    # Return the candidate element after the loop

def count_occurrences(candidate, array):
    count = 0
    # Initialize the count variable

    for value in array:
        if value == candidate:
            count += 1
            # Increment the count if the current value is the same as the candidate
    return count
    # Return the count of occurrences of the candidate element after the loop

def is_majority(count, total_count):
    # Check if the count of the candidate element is more than half the total count in the array
    return 2 * count > total_count

if __name__ == "__main__":
    n = int(input())
    # Read the number of elements in the array from the user input

    array = list(map(int, input().split()))
    # Allocate a list to store the elements

    majority_element = find_majority_element(array)
    # Find the majority element in the array using the find_majority_element function

    if majority_element is not None:
        print(majority_element)
        # Print the majority element if it exists
    else:
        print("No majority element")
        # Print "No majority element" if there's no majority element in the array

