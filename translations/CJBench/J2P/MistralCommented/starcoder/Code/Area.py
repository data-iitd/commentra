
# Final class to prevent extension and ensure encapsulation
class Main:
    # Error message for invalid radius
    POSITIVE_RADIUS = "Must be a positive radius"

    # Error message for invalid height
    POSITIVE_HEIGHT = "Must be a positive height"

    # Error message for invalid base
    POSITIVE_BASE = "Must be a positive base"

    # Method to calculate the surface area of a cube
    @staticmethod
    def surfaceMainCube(sideLength):
        if sideLength <= 0: # Check if sideLength is valid
            raise ValueError("Must be a positive sideLength")
        return 6 * sideLength * sideLength # Calculate the surface area

    # Method to calculate the surface area of a sphere
    @staticmethod
    def surfaceMainSphere(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(POSITIVE_RADIUS)
        return 4 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a rectangle
    @staticmethod
    def surfaceMainRectangle(length, width):
        if length <= 0: # Check if length is valid
            raise ValueError("Must be a positive length")
        if width <= 0: # Check if width is valid
            raise ValueError("Must be a positive width")
        return length * width # Calculate the surface area

    # Method to calculate the surface area of a cylinder
    @staticmethod
    def surfaceMainCylinder(radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(POSITIVE_HEIGHT)
        return 2 * (math.pi * radius * radius + math.pi * radius * height) # Calculate the surface area

    # Method to calculate the surface area of a square
    @staticmethod
    def surfaceMainSquare(sideLength):
        if sideLength <= 0: # Check if sideLength is valid
            raise ValueError("Must be a positive sideLength")
        return sideLength * sideLength # Calculate the surface area

    # Method to calculate the surface area of a triangle
    @staticmethod
    def surfaceMainTriangle(base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(POSITIVE_HEIGHT)
        return base * height / 2 # Calculate the surface area using the formula: 1/2 * base * height

    # Method to calculate the surface area of a parallelogram
    @staticmethod
    def surfaceMainParallelogram(base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(POSITIVE_HEIGHT)
        return base * height # Calculate the surface area

    # Method to calculate the surface area of a trapezium
    @staticmethod
    def surfaceMainTrapezium(base1, base2, height):
        if base1 <= 0: # Check if base1 is valid
            raise ValueError(POSITIVE_BASE + 1)
        if base2 <= 0: # Check if base2 is valid
            raise ValueError(POSITIVE_BASE + 2)
        if height <= 0: # Check if height is valid
            raise ValueError(POSITIVE_HEIGHT)
        return (base1 + base2) * height / 2 # Calculate the surface area using the formula: 1/2 * (base1 + base2) * height

    # Method to calculate the surface area of a circle
    @staticmethod
    def surfaceMainCircle(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(POSITIVE_RADIUS)
        return math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a hemisphere
    @staticmethod
    def surfaceMainHemisphere(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(POSITIVE_RADIUS)
        return 3 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a cone
    @staticmethod
    def surfaceMainCone(radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(POSITIVE_HEIGHT)
        return math.pi * radius * (radius + math.sqrt(height * height + radius * radius)) # Calculate the surface area

    # Main method to read user input and calculate the surface area based on the shape selected
    @staticmethod
    def main():
        choice = int(input("Enter choice: ")) # Read the user's choice of shape

        result = 0.0 # Initialize the result variable to store the calculated surface area

        if choice == 1:
            side = float(input("Enter side length: ")) # Read the side length of the cube from the user
            result = Main.surfaceMainCube(side) # Calculate the surface area of the cube
        elif choice == 2:
            radiusSphere = float(input("Enter radius: ")) # Read the radius of the sphere from the user
            result = Main.surfaceMainSphere(radiusSphere) # Calculate the surface area of the sphere
        elif choice == 3:
            length = float(input("Enter length: ")) # Read the length of the rectangle from the user
            width = float(input("Enter width: ")) # Read the width of the rectangle from the user
            result = Main.surfaceMainRectangle(length, width) # Calculate the surface area of the rectangle
        elif choice == 4:
            radiusCylinder = float(input("Enter radius: ")) # Read the radius of the cylinder from the user
            heightCylinder = float(input("Enter height: ")) # Read the height of the cylinder from the user
            result = Main.surfaceMainCylinder(radiusCylinder, heightCylinder) # Calculate the surface area of the cylinder
        elif choice == 5:
            sideSquare = float(input("Enter side length: ")) # Read the side length of the square from the user
            result = Main.surfaceMainSquare(sideSquare) # Calculate the surface area of the square
        elif choice == 6:
            baseTriangle = float(input("Enter base: ")) # Read the base of the triangle from the user
            heightTriangle = float(input("Enter height: ")) # Read the height of the triangle from the user
            result = Main.surfaceMainTriangle(baseTriangle, heightTriangle) # Calculate the surface area of the triangle
        elif choice == 7:
            baseParallelogram = float(input("Enter base: ")) # Read the base of the parallelogram from the user
            heightParallelogram = float(input("Enter height: ")) # Read the height of the parallelogram from the user
            result = Main.surfaceMainParallelogram(baseParallelogram, heightParallelogram) # Calculate the surface area of the parallelogram
        elif choice == 8:
            base1 = float(input("Enter base1: ")) # Read the base1 of the trapezium from the user
            base2 = float(input("Enter base2: ")) # Read the base2 of the trapezium from the user
            heightTrapezium = float(input("Enter height: ")) # Read the height of the trapezium from the user
            result = Main.surfaceMainTrapezium(base1, base2, heightTrapezium) # Calculate the surface area of the trapezium
        elif choice == 9:
            radiusCircle = float(input("Enter radius: ")) # Read the radius of the circle from the user
            result = Main.surfaceMainCircle(radiusCircle) # Calculate the surface area of the circle
        elif choice == 10:
            radiusHemisphere = float(input("Enter radius: ")) # Read the radius of the hemisphere from the user
            result = Main.surfaceMainHemisphere(radiusHemisphere) # Calculate the surface area of the hemisphere
        elif choice == 11:
            radiusCone = float(input("Enter radius: ")) # Read the radius of the cone from the user
            heightCone = float(input("Enter height: ")) # Read the height of the cone from the user
            result = Main.surfaceMainCone(radiusCone, heightCone) # Calculate the surface area of the cone
        else:
            print("Invalid choice") # Print an error message if the user enters an invalid choice
            return # Exit the program if the user enters an invalid choice

        print("Calculated Main: %.2f" % result) # Print the calculated surface area

