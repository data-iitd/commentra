
import sys

def find_majority_element(array):
    if len(array) == 0:
        return None
    candidate = find_candidate(array)
    count = count_occurrences(candidate, array)
    if is_majority(count, len(array)):
        return candidate
    return None

def find_candidate(array):
    count = 0
    candidate = -1
    for value in array:
        if count == 0:
            candidate = value
        count += (value == candidate) - (value != candidate)
    return candidate

def count_occurrences(candidate, array):
    count = 0
    for value in array:
        if value == candidate:
            count += 1
    return count

def is_majority(count, total_count):
    return 2 * count > total_count

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    array = list(map(int, sys.stdin.readline().split()))
    majority_element = find_majority_element(array)
    if majority_element is not None:
        print(majority_element)
    else:
        print("No majority element")

