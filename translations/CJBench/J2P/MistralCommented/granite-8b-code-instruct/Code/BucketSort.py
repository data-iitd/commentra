

import math

def sort(array):
    if len(array) == 0: # Base case: empty array is already sorted
        return array

    min_element = min(array) # Find the minimum element in the array
    max_element = max(array) # Find the maximum element in the array
    number_of_buckets = calculate_number_of_buckets(len(array)) # Calculate the number of buckets needed

    # Initialize the buckets list with the specified number of empty lists
    buckets = initialize_buckets(number_of_buckets)

    # Distribute the elements into the buckets based on their hash values
    distribute_elements_into_buckets(array, buckets, min_element, max_element, number_of_buckets)

    # Concatenate the sorted buckets back into a single sorted array
    return concatenate_buckets(buckets, array)

# Helper method to calculate the number of buckets needed based on the array length
def calculate_number_of_buckets(array_length):
    return max(array_length // 10, 1)

# Helper method to initialize the buckets list with the specified number of empty lists
def initialize_buckets(number_of_buckets):
    return [[] for _ in range(number_of_buckets)]

# Helper method to distribute the elements into the buckets based on their hash values
def distribute_elements_into_buckets(array, buckets, min_element, max_element, number_of_buckets):
    for element in array: # Iterate through each element in the array
        bucket_index = hash(element, min_element, max_element, number_of_buckets) # Calculate the hash value for the element
        buckets[bucket_index].append(element) # Add the element to the corresponding bucket

# Helper method to concatenate the sorted buckets back into a single sorted array
def concatenate_buckets(buckets, array):
    index = 0 # Initialize an index to keep track of the array position

    # Iterate through each sorted bucket and add its elements to the array
    for bucket in buckets:
        bucket.sort() # Sort the elements in the bucket
        for element in bucket:
            array[index] = element # Add the element to the array
            index += 1

    return array

# Helper method to calculate the hash value for an element based on the minimum, maximum, and number of buckets
def hash(element, min_element, max_element, number_of_buckets):
    range_ = max_element - min_element # Calculate the range between the minimum and maximum elements
    normalized_value = (element - min_element) / range_ # Calculate the normalized value of the element
    return int(math.floor(normalized_value * (number_of_buckets - 1))) # Calculate the hash value as an index

# Helper methods to find the minimum and maximum elements in the array
def find_min(array):
    min_element = array[0] # Initialize the minimum element as the first element in the array
    for element in array: # Iterate through the remaining elements in the array
        if element < min_element: # If the current element is less than the minimum, update the minimum
            min_element = element
    return min_element

def find_max(array):
    max_element = array[0] # Initialize the maximum element as the first element in the array
    for element in array: # Iterate through the remaining elements in the array
        if element > max_element: # If the current element is greater than the maximum, update the maximum
            max_element = element
    return max_element

# Main method to read input and call the sorting method
if __name__ == "__main__":
    n = int(input("Enter the number of elements in the array: ")) # Read the number of elements in the array from the console
    array = [float(input("Enter element " + str(i+1) + ": ")) for i in range(n)] # Read the elements of the array from the console and store them in the array

    sorted_array = sort(array) # Call the sorting method to sort the array

    # Print the sorted elements to the console
    print("Sorted array:", sorted_array)

