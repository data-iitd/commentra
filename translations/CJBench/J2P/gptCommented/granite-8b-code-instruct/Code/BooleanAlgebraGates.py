
import sys

# Define a BooleanGate interface with an evaluate method
class BooleanGate:
    def evaluate(self, inputs):
        pass

# Class representing an AND gate
class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        # Evaluate AND gate: returns true only if all inputs are true
        for input in inputs:
            if not input:
                return False # If any input is false, return false
        return True # All inputs are true

# Class representing an OR gate
class ORGate(BooleanGate):
    def evaluate(self, inputs):
        # Evaluate OR gate: returns true if at least one input is true
        for input in inputs:
            if input:
                return True # If any input is true, return true
        return False # All inputs are false

# Class representing a NOT gate
class NOTGate:
    def evaluate(self, input):
        # Evaluate NOT gate: returns the negation of the input
        return not input

# Class representing an XOR gate
class XORGate(BooleanGate):
    def evaluate(self, inputs):
        # Evaluate XOR gate: returns true if an odd number of inputs are true
        result = False
        for input in inputs:
            result ^= input # Toggle result for each true input
        return result # Return the final result

# Class representing a NAND gate
class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        # Evaluate NAND gate: returns the negation of the AND gate result
        return not ANDGate().evaluate(inputs)

# Class representing a NOR gate
class NORGate(BooleanGate):
    def evaluate(self, inputs):
        # Evaluate NOR gate: returns the negation of the OR gate result
        return not ORGate().evaluate(inputs)

# Main method to execute the program
def main():
    # Read the number of inputs
    n = int(input())
    inputs = []
    
    # Read the boolean inputs from the user
    for _ in range(n):
        inputs.append(bool(int(input())))
    
    # Read the choice of gate from the user
    choice = int(input())
    
    # Evaluate the chosen gate and print the result
    if choice == 1:
        print("AND Gate Result:", ANDGate().evaluate(inputs))
    elif choice == 2:
        print("OR Gate Result:", ORGate().evaluate(inputs))
    elif choice == 3:
        print("XOR Gate Result:", XORGate().evaluate(inputs))
    elif choice == 4:
        print("NAND Gate Result:", NANDGate().evaluate(inputs))
    elif choice == 5:
        print("NOR Gate Result:", NORGate().evaluate(inputs))
    elif choice == 6:
        # Check if the NOT gate has exactly one input
        if len(inputs)!= 1:
            print("NOT Gate requires exactly one input.")
        else:
            print("NOT Gate Result:", NOTGate().evaluate(inputs[0]))
    else:
        # Handle invalid choices
        print("Invalid choice.")

if __name__ == "__main__":
    main()

