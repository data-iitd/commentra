
class Main:
    # Constructor with key and additional info
    def __init__(self, key, info=None):
        self.key = key
        self.additional_info = info

    # Constructor with key only
    def __init__(self, key):
        self.key = key
        self.additional_info = None

    # Getter for additional info
    def get_info(self):
        return self.additional_info

    # Getter for key
    def get_key(self):
        return self.key

    # Override toString method to display key and additional info
    def __str__(self):
        return "Key: " + str(self.key) + " - " + (self.additional_info if self.additional_info else "No additional info")

    # Override equals method to compare keys and additional info
    def __eq__(self, other):
        if isinstance(other, Main):
            return self.key == other.key and (self.additional_info == other.additional_info if self.additional_info else not other.additional_info)
        return False

    # Override hashCode method to include key and additional info
    def __hash__(self):
        result = 31 * int(self.key)
        result += hash(self.additional_info) if self.additional_info else 0
        return result

# Main method to read commands from user input and process them
def main():
    elements = [] # Initialize empty list to store Main objects

    while True: # Read user input line by line
        command = input().strip() # Trim whitespaces from command

        if not command: # Check if command is empty
            break # Exit the loop if command is empty

        parts = command.split() # Split command into parts based on whitespaces
        operation = parts[0] # Get the operation from the first part

        try: # Begin try block to handle valid commands
            if operation == "create": # Handle "create" command
                key = float(parts[1]) # Parse key from command
                info = parts[2] if len(parts) > 2 else None # Get additional info if it exists
                element = info if info else Main(key) # Create new Main object
                elements.append(element) # Add new Main object to list
                print("Created: " + str(element)) # Print created Main object
            elif operation == "getKey": # Handle "getKey" command
                index = int(parts[1]) # Parse index from command
                if index < 0 or index >= len(elements): # Check if index is valid
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1)) # Print error message if index is invalid
                else: # If index is valid
                    print("Key: " + str(elements[index].get_key())) # Print key of Main object at given index
            elif operation == "getInfo": # Handle "getInfo" command
                index = int(parts[1]) # Parse index from command
                if index < 0 or index >= len(elements): # Check if index is valid
                    print("Error: Index " + str(index) + " is out of bounds. Valid range: 0 to " + str(len(elements) - 1)) # Print error message if index is invalid
                else: # If index is valid
                    print("Info: " + str(elements[index].get_info())) # Print additional info of Main object at given index
            elif operation == "print": # Handle "print" command
                for el in elements: # Iterate through list and print each Main object
                    print(el) # Print Main object
            else: # Handle invalid operation
                print("Unknown operation: " + operation) # Print error message
        except Exception as e: # Catch exceptions thrown during command processing
            print("Error: " + str(e)) # Print error message

if __name__ == "__main__":
    main()

