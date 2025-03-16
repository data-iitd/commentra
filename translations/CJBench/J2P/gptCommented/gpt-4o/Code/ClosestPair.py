import math

class Main:
    # Number of points to be processed
    number_points = 0
    # Array to hold the locations of the points
    array = []
    # Variables to store the closest pair of points
    point1 = None
    point2 = None
    # Minimum distance initialized to maximum possible value
    min_num = float('inf')

    # Counter for the number of points in the second window
    second_count = 0

    # Constructor to initialize the number of points and the array
    def __init__(self, points):
        self.number_points = points
        self.array = [None] * self.number_points

    # Inner class to represent a location with x and y coordinates
    class Location:
        def __init__(self, xpar, ypar):
            self.x = xpar
            self.y = ypar

    # Method to create a new Location object
    def build_location(self, x, y):
        return self.Location(x, y)

    # Partitioning method for quicksort based on x-coordinate
    def x_partition(self, a, first, last):
        pivot = a[last]  # Choosing the last element as pivot
        i = first - 1  # Index of smaller element

        # Rearranging the array based on the pivot
        for j in range(first, last):
            if a[j].x <= pivot.x:
                i += 1
                # Swap elements
                a[i], a[j] = a[j], a[i]
        # Swap the pivot element to its correct position
        i += 1
        a[i], a[last] = a[last], a[i]
        return i  # Return the partitioning index

    # Quicksort method for sorting the locations based on x-coordinate
    def x_quick_sort(self, a, first, last):
        if first < last:
            q = self.x_partition(a, first, last)  # Partition the array
            self.x_quick_sort(a, first, q - 1)  # Recursively sort the left subarray
            self.x_quick_sort(a, q + 1, last)  # Recursively sort the right subarray

    # Method to find the closest pair of points using divide and conquer
    def closest_pair(self, a, index_num):
        # Create a subarray to work with
        divide_array = a[:index_num]
        divide_x = index_num // 2  # Find the midpoint
        left_array = divide_array[:divide_x]
        right_array = divide_array[divide_x:]

        # Base case for small arrays
        if index_num <= 3:
            return self.brute_force(divide_array)  # Use brute force for small number of points

        # Recursively find the minimum distances in both halves
        min_left_area = self.closest_pair(left_array, divide_x)
        min_right_area = self.closest_pair(right_array, index_num - divide_x)
        min_value = min(min_left_area, min_right_area)  # Minimum distance found so far

        # Check points in the strip around the dividing line
        for i in range(index_num):
            x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
            if x_gap < min_value:
                self.second_count += 1  # Update second count

        # Create an array for points within the strip
        first_window = [None] * self.second_count
        k = 0
        for i in range(index_num):
            x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
            if x_gap < min_value:
                first_window[k] = divide_array[i]  # Add point to the strip
                k += 1

        # Check for the closest pair within the strip
        for i in range(self.second_count - 1):
            for j in range(i + 1, self.second_count):
                x_gap = abs(first_window[i].x - first_window[j].x)
                y_gap = abs(first_window[i].y - first_window[j].y)
                if y_gap < min_value:
                    length = math.sqrt(x_gap ** 2 + y_gap ** 2)  # Calculate distance
                    if length < min_value:
                        min_value = length  # Update minimum distance
                        if length < self.min_num:
                            self.min_num = length  # Update global minimum distance
                            self.point1 = first_window[i]  # Update closest points
                            self.point2 = first_window[j]

        self.second_count = 0  # Reset second count for next call
        return min_value  # Return the minimum distance found

    # Brute force method to find the closest pair of points for small arrays
    def brute_force(self, array_param):
        min_value = float('inf')  # Initialize minimum distance

        # Check all pairs of points
        for i in range(len(array_param) - 1):
            for j in range(i + 1, len(array_param)):
                x_gap = array_param[i].x - array_param[j].x
                y_gap = array_param[i].y - array_param[j].y
                length = math.sqrt(x_gap ** 2 + y_gap ** 2)  # Calculate distance
                if length < min_value:
                    min_value = length  # Update minimum distance
                    if length < self.min_num:
                        self.min_num = length  # Update global minimum distance
                        self.point1 = array_param[i]  # Update closest points
                        self.point2 = array_param[j]

        return min_value  # Return the minimum distance found

# Main method to execute the program
if __name__ == "__main__":
    n = int(input())  # Read number of points
    cp = Main(n)  # Create Main object with number of points

    # Read points from input
    for i in range(n):
        x, y = map(float, input().split())
        cp.array[i] = cp.build_location(x, y)  # Build location objects

    # Sort the array of locations based on x-coordinate
    cp.x_quick_sort(cp.array, 0, len(cp.array) - 1)
    # Find the closest pair of points
    result = cp.closest_pair(cp.array, len(cp.array))

    # Output the closest pair of points and the minimum distance
    print(f"({cp.point1.x}, {cp.point1.y})")
    print(f"({cp.point2.x}, {cp.point2.y})")
    print(f"Minimum Distance : {result}")
