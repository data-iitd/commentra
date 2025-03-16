
# Import the necessary libraries
import sys

# Create a class to represent a Main object
class Main:
    # Initialize the key and additional information
    def __init__(self, key, info=None):
        self.key = key
        self.info = info

    # Getter method to retrieve additional information
    def get_info(self):
        return self.info

    # Getter method to retrieve the key
    def get_key(self):
        return self.key

    # Override the toString method to provide a string representation of the object
    def __str__(self):
        return "Key: " + str(self.key) + " - " + (self.info if self.info else "No additional info")

    # Override the equals method to compare two Main objects based on key and additional info
    def __eq__(self, other):
        return self.key == other.key and (self.info == other.info if self.info else not other.info)

    # Override the hashCode method to generate a hash code based on key and additional info
    def __hash__(self):
        result = 31 * self.key
        result += self.info.hashCode() if self.info else 0
        return result

# Main method to execute the program
def main():
    # Create a list to hold Main objects
    elements = []

    # Loop to continuously read commands until an empty line is entered
    while True:
        # Read a command from the user
        command = input().strip()
        # Exit the loop if the command is empty
        if not command:
            break

        # Split the command into parts for processing
        parts = command.split(" ")
        operation = parts[0]

        try:
            # Switch statement to handle different operations
            if operation == "create":
                # Create a new Main object with the specified key and optional info
                key = float(parts[1])
                info = parts[2] if len(parts) > 2 else None
                element = Main(key, info)
                elements.append(element)
                print("Created: " + str(element))
            elif operation == "getKey":
                # Retrieve and print the key of the Main object at the specified index
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1))
                else:
                    print("Key: " + str(elements[index].get_key()))
            elif operation == "getInfo":
                # Retrieve and print the additional info of the Main object at the specified index
                index = int(parts[1])
                if index < 0 or index >= len(elements):
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1))
                else:
                    print("Info: " + str(elements[index].get_info()))
            elif operation == "print":
                # Print all Main objects in the list
                for el in elements:
                    print(el)
            else:
                # Handle unknown operations
                print("Unknown operation: " + operation)
        except Exception as e:
            # Print any errors that occur during command processing
            print("Error: " + str(e))

# Close the input stream to free resources
sys.stdin.close()

# End of code
