
# Importing Scanner class for user input
import java.util.Scanner;

# Method to sort an array of comparable elements using dual pivot quicksort algorithm
def sort(array):
    if (array.length > 1): # Check if the array has more than one element to sort
        dualPivotQuicksort(array, 0, array.length - 1); # Call dualPivotQuicksort method to sort the array

# Recursive method to implement dual pivot quicksort algorithm
def dualPivotQuicksort(array, left, right):
    if (left < right): # Check if the left index is less than the right index
        pivots = partition(array, left, right); # Call partition method to find the pivots
        dualPivotQuicksort(array, left, pivots[0] - 1); # Recursively sort elements before the first pivot
        dualPivotQuicksort(array, pivots[0] + 1, pivots[1] - 1); # Recursively sort elements between the pivots
        dualPivotQuicksort(array, pivots[1] + 1, right); # Recursively sort elements after the second pivot

# Method to partition the array and find the pivots
def partition(array, left, right):
    if (array[left].compareTo(array[right]) > 0): # Swap the first and last elements if the first is greater than the last
        swap(array, left, right);
    pivot1 = array[left]; # Set the first element as the first pivot
    pivot2 = array[right]; # Set the last element as the second pivot
    pivot1End = left + 1; # Initialize the index for the first pivot's end
    low = left + 1; # Initialize the index for the first iteration
    high = right - 1; # Initialize the index for the last iteration

    # Iterate through the array to find the correct positions for the pivots
    while (low <= high):
        if (array[low].compareTo(pivot1) < 0): # If the current element is less than the first pivot, swap it with the element at pivot1End and increment pivot1End
            swap(array, low, pivot1End);
            pivot1End++;
        elif (array[low].compareTo(pivot2) >= 0): # If the current element is greater than or equal to the second pivot, swap it with the element at high and decrement high
            while (low < high and array[high].compareTo(pivot2) > 0): # If the current high element is greater than the second pivot, swap it with the element at low and decrement high
                swap(array, low, high);
                high--;
            swap(array, low, high); # Swap the current low and high elements
            high--;
            if (array[low].compareTo(pivot1) < 0): # If the current low element is less than the first pivot, swap it with the element at pivot1End and increment pivot1End
                swap(array, low, pivot1End);
                pivot1End++;
        low++; # Increment the low index for the next iteration
    # Swap the pivots with the elements at pivot1End and high indices
    pivot1End--;
    high++;
    swap(array, left, pivot1End);
    swap(array, right, high);

    # Return the indices of the pivots
    return new int[]{pivot1End, high};

# Method to swap two elements in the array
def swap(array, i, j):
    temp = array[i]; # Store the element at index i
    array[i] = array[j]; # Assign the element at index j to index i
    array[j] = temp; # Assign the element at index i to index j

# Main method to read user input and call sort method
def main():
    scanner = Scanner(System.in); # Create a new Scanner object for user input
    n = scanner.nextInt(); # Read the number of elements in the array from user input
    array = [0] * n; # Create an array of Integers with the given size
    for i in range(n): # Iterate through the array to read user input and assign it to the corresponding index
        array[i] = scanner.nextInt();
    sort(array); # Call the sort method to sort the array
    for num in array: # Iterate through the sorted array and print each element
        print(num, end=" ");
    scanner.close(); # Close the Scanner object

if __name__ == "__main__":
    main();

