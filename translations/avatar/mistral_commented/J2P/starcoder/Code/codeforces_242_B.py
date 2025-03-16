
import java.util.ArrayList ;  # Importing ArrayList and Scanner classes
import java.util.Scanner ;
import java.lang.Math ;

def main():
    sc = Scanner(System.in)  # Creating a Scanner object to read input
    n = sc.nextInt()  # Reading the number of elements in the arrays

    a = ArrayList()  # Creating an ArrayList to store the first array elements
    b = ArrayList()  # Creating an ArrayList to store the second array elements

    left = INF  # Initializing left variable to store the minimum element
    right = 0  # Initializing right variable to store the maximum element

    # Reading the elements of the arrays and updating the minimum and maximum elements
    for i in range(n):
        a.add(sc.nextInt())  # Reading an element from the first array and adding it to the ArrayList
        b.add(sc.nextInt())  # Reading an element from the second array and adding it to the ArrayList
        left = min(left, a.get(i))  # Finding the minimum element in the first array
        right = max(right, b.get(i))  # Finding the maximum element in the second array

    # Checking if there is an element that has the same minimum and maximum value in both arrays
    for i in range(n):
        if left == a.get(i) and right == b.get(i):  # Checking if the current element in both arrays has the same minimum and maximum value
            print(i + 1)  # If true, printing the index of the element
            return  # Exiting the program after finding the element

    # If no such element is found, printing -1
    print(-1)

if __name__ == '__main__':
    main()

