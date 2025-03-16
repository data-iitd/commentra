
# Importing the Scanner class for user input
import java.util.Scanner;

class Main: # Defining the Main class
    def __init__(self, vectorX, vectorY, vectorZ): # Constructor with three arguments
        self.x = vectorX; # Initializing x, y, and z with the given values
        self.y = vectorY;
        self.z = vectorZ;

    def magnitude(self): # Method to calculate the magnitude of the vector
        return math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z); # Calculating the square of each component and then taking the square root

    def dotProduct(self, b): # Method to calculate the dot product of two vectors
        return self.x * b.x + self.y * b.y + self.z * b.z; # Multiplying corresponding components and summing them up

    def crossProduct(self, b): # Method to calculate the cross product of two vectors
        product = Main(0, 0, 0); # Creating a new Main object to store the result
        product.x = (self.y * b.z) - (self.z * b.y); # Calculating the x component using the cross product formula
        product.y = -((self.x * b.z) - (self.z * b.x)); # Calculating the y component using the cross product formula
        product.z = (self.x * b.y) - (self.y * b.x); # Calculating the z component using the cross product formula
        return product; # Returning the result

    def displayVector(self): # Method to display the components of the vector
        print("x : " + self.x + "\ty : " + self.y + "\tz : " + self.z); # Printing the components of the vector

if __name__ == "__main__": # Main method
    scanner = Scanner(System.in); # Creating a new Scanner object for user input
    print("Enter the components of the first vector (x y z): "); # Asking the user to input the components of the first vector
    x1 = scanner.nextInt(); # Reading the x component of the first vector from user input
    y1 = scanner.nextInt(); # Reading the y component of the first vector from user input
    z1 = scanner.nextInt(); # Reading the z component of the first vector from user input
    a = Main(x1, y1, z1); # Creating a new Main object 'a' with the given components
    print("Enter the components of the second vector (x y z): "); # Asking the user to input the components of the second vector
    x2 = scanner.nextInt(); # Reading the x component of the second vector from user input
    y2 = scanner.nextInt(); # Reading the y component of the second vector from user input
    z2 = scanner.nextInt(); # Reading the z component of the second vector from user input
    b = Main(x2, y2, z2); # Creating a new Main object 'b' with the given components
    crossProd = a.crossProduct(b); # Calculating the cross product of vectors 'a' and 'b'
    print("Cross Product of the two vectors:"); # Printing the header for the cross product result
    crossProd.displayVector(); # Displaying the components of the cross product result
    dotProd = a.dotProduct(b); # Calculating the dot product of vectors 'a' and 'b'
    print("Dot Product of the two vectors: " + dotProd); # Printing the dot product result
    print("Magnitude of the first vector: %.2f" % a.magnitude()); # Printing the magnitude of vector 'a' with two decimal places
    print("Magnitude of the second vector: %.2f" % b.magnitude()); # Printing the magnitude of vector 'b' with two decimal places
    scanner.close(); # Closing the Scanner object

