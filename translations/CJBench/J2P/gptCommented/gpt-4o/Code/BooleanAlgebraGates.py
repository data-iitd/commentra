class BooleanGate:
    def evaluate(self, inputs):
        raise NotImplementedError("Subclasses should implement this!")

class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        return all(inputs)  # Returns True only if all inputs are True

class ORGate(BooleanGate):
    def evaluate(self, inputs):
        return any(inputs)  # Returns True if at least one input is True

class NOTGate:
    def evaluate(self, input):
        return not input  # Returns the negation of the input

class XORGate(BooleanGate):
    def evaluate(self, inputs):
        return sum(inputs) % 2 == 1  # Returns True if an odd number of inputs are True

class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)  # Negation of AND gate result

class NORGate(BooleanGate):
    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)  # Negation of OR gate result

def main():
    n = int(input("Enter the number of inputs: "))
    inputs = [bool(int(input(f"Input {i + 1} (0 or 1): "))) for i in range(n)]
    
    choice = int(input("Choose a gate (1: AND, 2: OR, 3: XOR, 4: NAND, 5: NOR, 6: NOT): "))
    
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
        if len(inputs) != 1:
            print("NOT Gate requires exactly one input.")
        else:
            print("NOT Gate Result:", NOTGate().evaluate(inputs[0]))
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
