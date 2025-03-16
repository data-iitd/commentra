
import sys

# Main class for Boolean logic gates application.
class Main:
    # Interface for Boolean logic gates.
    class BooleanGate:
        # Evaluates the Boolean logic gate with given inputs.
        def evaluate(self, inputs):
            # Iterates through the list of Boolean inputs and returns false as soon as an input is false.
            for input in inputs:
                if not input:
                    return False
            # If all inputs are true, returns true.
            return True

    # AND gate implementation.
    class ANDGate(BooleanGate):
        pass

    # OR gate implementation.
    class ORGate(BooleanGate):
        pass

    # NOT gate implementation.
    class NOTGate:
        # Evaluates the NOT gate with a single Boolean input.
        def evaluate(self, input):
            # Negates the Boolean input.
            return not input

    # XOR gate implementation.
    class XORGate(BooleanGate):
        pass

    # NAND gate implementation.
    class NANDGate(BooleanGate):
        pass

    # NOR gate implementation.
    class NORGate(BooleanGate):
        pass

    # Main method for user input and gate evaluation.
    def main(args):
        # Reads the number of Boolean inputs from the user.
        n = int(input("Enter the number of Boolean inputs: "))

        inputs = []

        # Reads the Boolean inputs from the user.
        for i in range(n):
            inputs.append(bool(input("Enter Boolean input " + str(i + 1) + ": ")))

        choice = int(input("Enter the gate type (1 for AND, 2 for OR, 3 for XOR, 4 for NAND, 5 for NOR, 6 for NOT): "))

        gate = None

        # Instantiates the gate based on the user's choice.
        if choice == 1:
            gate = Main.ANDGate()
        elif choice == 2:
            gate = Main.ORGate()
        elif choice == 3:
            gate = Main.XORGate()
        elif choice == 4:
            gate = Main.NANDGate()
        elif choice == 5:
            gate = Main.NORGate()
        elif choice == 6:
            # NOT gate requires exactly one input.
            if len(inputs) != 1:
                print("NOT Gate requires exactly one input.")
                return
            gate = Main.NOTGate()
        else:
            print("Invalid choice.")
            return

        # Evaluates the gate with the given Boolean inputs and prints the result.
        print("Gate Result: " + str(gate.evaluate(inputs)))

if __name__ == "__main__":
    Main.main(sys.argv[1:])

