import math

class Main:
    # Instance variables to hold the components of the vector
    x = 0
    y = 0
    z = 0

    # Default constructor initializing vector components to zero
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0

    # Parameterized constructor to initialize vector components with given values
    def __init__(self, vectorX, vectorY, vectorZ):
        self.x = vectorX
        self.y = vectorY
        self.z = vectorZ

    # Method to calculate and return the magnitude of the vector
    def magnitude(self):
        return math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z)

    # Method to calculate and return the dot product of this vector with another vector
    def dotProduct(self, b):
        return self.x * b.x + self.y * b.y + self.z * b.z

    # Method to calculate and return the cross product of this vector with another vector
    def crossProduct(self, b):
        product = Main()
        # Calculate the components of the cross product
        product.x = (self.y * b.z) - (self.z * b.y)
        product.y = -((self.x * b.z) - (self.z * b.x))
        product.z = (self.x * b.y) - (self.y * b.x)
        return product

    # Method to display the vector components
    def displayVector(self):
        print("x : " + str(self.x) + "\ty : " + str(self.y) + "\tz : " + str(self.z))

    # Main method to execute the program
    def main(self):
        # Create a scanner object for user input
        scanner = input("Enter the components of the first vector (x y z): ")
        x1 = scanner[0]
        y1 = scanner[1]
        z1 = scanner[2]

        # Create the first vector using user input
        a = Main(x1, y1, z1)

        # Prompt user to enter the components of the second vector
        scanner = input("Enter the components of the second vector (x y z): ")
        x2 = scanner[0]
        y2 = scanner[1]
        z2 = scanner[2]

        # Create the second vector using user input
        b = Main(x2, y2, z2)

        # Calculate and display the cross product of the two vectors
        crossProd = a.crossProduct(b)
        print("Cross Product of the two vectors:")
        crossProd.displayVector()

        # Calculate and display the dot product of the two vectors
        dotProd = a.dotProduct(b)
        print("Dot Product of the two vectors: " + str(dotProd))

        # Calculate and display the magnitude of the first vector
        print("Magnitude of the first vector: " + str(a.magnitude()))

        # Calculate and display the magnitude of the second vector
        print("Magnitude of the second vector: " + str(b.magnitude()))

        # Close the scanner to prevent resource leaks
        scanner.close()

# Call the main method to execute the program
Main().main()

