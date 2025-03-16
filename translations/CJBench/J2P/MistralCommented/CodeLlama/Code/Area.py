
# Import the necessary libraries
import math

# Final class to prevent extension and ensure encapsulation
class Main:
    def __init__(self):
        pass

    # Error message for invalid radius
    POSITIVE_RADIUS = "Must be a positive radius"

    # Error message for invalid height
    POSITIVE_HEIGHT = "Must be a positive height"

    # Error message for invalid base
    POSITIVE_BASE = "Must be a positive base"

    # Method to calculate the surface area of a cube
    def surfaceMainCube(self, sideLength):
        if sideLength <= 0: # Check if sideLength is valid
            raise ValueError("Must be a positive sideLength")
        return 6 * sideLength * sideLength # Calculate the surface area

    # Method to calculate the surface area of a sphere
    def surfaceMainSphere(self, radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return 4 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a rectangle
    def surfaceMainRectangle(self, length, width):
        if length <= 0: # Check if length is valid
            raise ValueError("Must be a positive length")
        if width <= 0: # Check if width is valid
            raise ValueError("Must be a positive width")
        return length * width # Calculate the surface area

    # Method to calculate the surface area of a cylinder
    def surfaceMainCylinder(self, radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return 2 * (math.pi * radius * radius + math.pi * radius * height) # Calculate the surface area

    # Method to calculate the surface area of a square
    def surfaceMainSquare(self, sideLength):
        if sideLength <= 0: # Check if sideLength is valid
            raise ValueError("Must be a positive sideLength")
        return sideLength * sideLength # Calculate the surface area

    # Method to calculate the surface area of a triangle
    def surfaceMainTriangle(self, base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(Main.POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return base * height / 2 # Calculate the surface area using the formula: 1/2 * base * height

    # Method to calculate the surface area of a parallelogram
    def surfaceMainParallelogram(self, base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(Main.POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return base * height # Calculate the surface area

    # Method to calculate the surface area of a trapezium
    def surfaceMainTrapezium(self, base1, base2, height):
        if base1 <= 0: # Check if base1 is valid
            raise ValueError(Main.POSITIVE_BASE + 1)
        if base2 <= 0: # Check if base2 is valid
            raise ValueError(Main.POSITIVE_BASE + 2)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return (base1 + base2) * height / 2 # Calculate the surface area using the formula: 1/2 * (base1 + base2) * height

    # Method to calculate the surface area of a circle
    def surfaceMainCircle(self, radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a hemisphere
    def surfaceMainHemisphere(self, radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return 3 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a cone
    def surfaceMainCone(self, radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return math.pi * radius * (radius + math.sqrt(height * height + radius * radius)) # Calculate the surface area

    # Main method to read user input and calculate the surface area based on the shape selected
    def main(self):
        scanner = input("Enter your choice: ") # Read the user's choice of shape

        result = 0.0 # Initialize the result variable to store the calculated surface area

        if scanner == "1":
            side = input("Enter the side length of the cube: ") # Read the side length of the cube from the user
            result = self.surfaceMainCube(side) # Calculate the surface area of the cube
        elif scanner == "2":
            radiusSphere = input("Enter the radius of the sphere: ") # Read the radius of the sphere from the user
            result = self.surfaceMainSphere(radiusSphere) # Calculate the surface area of the sphere
        elif scanner == "3":
            length = input("Enter the length of the rectangle: ") # Read the length of the rectangle from the user
            width = input("Enter the width of the rectangle: ") # Read the width of the rectangle from the user
            result = self.surfaceMainRectangle(length, width) # Calculate the surface area of the rectangle
        elif scanner == "4":
            radiusCylinder = input("Enter the radius of the cylinder: ") # Read the radius of the cylinder from the user
            heightCylinder = input("Enter the height of the cylinder: ") # Read the height of the cylinder from the user
            result = self.surfaceMainCylinder(radiusCylinder, heightCylinder) # Calculate the surface area of the cylinder
        elif scanner == "5":
            sideSquare = input("Enter the side length of the square: ") # Read the side length of the square from the user
            result = self.surfaceMainSquare(sideSquare) # Calculate the surface area of the square
        elif scanner == "6":
            baseTriangle = input("Enter the base of the triangle: ") # Read the base of the triangle from the user
            heightTriangle = input("Enter the height of the triangle: ") # Read the height of the triangle from the user
            result = self.surfaceMainTriangle(baseTriangle, heightTriangle) # Calculate the surface area of the triangle
        elif scanner == "7":
            baseParallelogram = input("Enter the base of the parallelogram: ") # Read the base of the parallelogram from the user
            heightParallelogram = input("Enter the height of the parallelogram: ") # Read the height of the parallelogram from the user
            result = self.surfaceMainParallelogram(baseParallelogram, heightParallelogram) # Calculate the surface area of the parallelogram
        elif scanner == "8":
            base1 = input("Enter the base1 of the trapezium: ") # Read the base1 of the trapezium from the user
            base2 = input("Enter the base2 of the trapezium: ") # Read the base2 of the trapezium from the user
            heightTrapezium = input("Enter the height of the trapezium: ") # Read the height of the trapezium from the user
            result = self.surfaceMainTrapezium(base1, base2, heightTrapezium) # Calculate the surface area of the trapezium
        elif scanner == "9":
            radiusCircle = input("Enter the radius of the circle: ") # Read the radius of the circle from the user
            result = self.surfaceMainCircle(radiusCircle) # Calculate the surface area of the circle
        elif scanner == "10":
            radiusHemisphere = input("Enter the radius of the hemisphere: ") # Read the radius of the hemisphere from the user
            result = self.surfaceMainHemisphere(radiusHemisphere) # Calculate the surface area of the hemisphere
        elif scanner == "11":
            radiusCone = input("Enter the radius of the cone: ") # Read the radius of the cone from the user
            heightCone = input("Enter the height of the cone: ") # Read the height of the cone from the user
            result = self.surfaceMainCone(radiusCone, heightCone) # Calculate the surface area of the cone
        else:
            print("Invalid choice") # Print an error message if the user enters an invalid choice
            return # Exit the program if the user enters an invalid choice

        print("Calculated Main: %.2f" % result) # Print the calculated surface area

