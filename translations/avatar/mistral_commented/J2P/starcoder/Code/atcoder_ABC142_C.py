import java.util.* ;  # Importing the Java Util Package for using Scanner and HashMap

def main():
    scanner = Scanner(System.in) # Creating a new Scanner object for user input
    N = scanner.nextInt() # Declaring an integer variable 'N' to store the number of elements

    idorder = {} # Declaring and initializing a HashMap 'idorder'

    # Reading the elements and storing their corresponding indices in the HashMap
    for i in range(1, N+1):
        A = scanner.nextInt() # Reading an element 'A' from the user input
        idorder[A] = i # Storing the index 'i' of the element 'A' in the HashMap

    # Printing the indices of the elements in the order they were read
    for i in range(1, N+1):
        print(idorder[i], end=" ") # Printing the index of the current element

    scanner.close() # Closing the Scanner object to save system resources

if __name__ == "__main__":
    main()

