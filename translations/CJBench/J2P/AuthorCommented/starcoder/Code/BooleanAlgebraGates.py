
import sys

# Represents a Boolean gate that takes multiple inputs and returns a result.
class BooleanGate:
    def evaluate(self, inputs):
        pass


# AND Gate implementation.
# Returns true if all inputs are true; otherwise, false.
class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        for input in inputs:
            if not input:
                return False
        return True


# OR Gate implementation.
# Returns true if at least one input is true; otherwise, false.
class ORGate(BooleanGate):
    def evaluate(self, inputs):
        for input in inputs:
            if input:
                return True
        return False


# NOT Gate implementation (Unary operation).
# Negates a single input value.
class NOTGate(BooleanGate):
    def evaluate(self, input):
        return not input


# XOR Gate implementation.
# Returns true if an odd number of inputs are true; otherwise, false.
class XORGate(BooleanGate):
    def evaluate(self, inputs):
        result = False
        for input in inputs:
            result ^= input
        return result


# NAND Gate implementation.
# Returns true if at least one input is false; otherwise, false.
class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)


# NOR Gate implementation.
# Returns true if all inputs are false; otherwise, false.
class NORGate(BooleanGate):
    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)


def main():
    # Input number of inputs and values
    n = int(input())

    inputs = []
    for i in range(n):
        inputs.append(bool(int(input())))

    # Select the gate
    choice = int(input())

    gate = None
    if choice == 1:
        gate = ANDGate()
    elif choice == 2:
        gate = ORGate()
    elif choice == 3:
        gate = XORGate()
    elif choice == 4:
        gate = NANDGate()
    elif choice == 5:
        gate = NORGate()
    elif choice == 6:
        if len(inputs)!= 1:
            print("NOT Gate requires exactly one input.")
            return
        gate = NOTGate()
    else:
        print("Invalid choice.")
        return

    print(gate.evaluate(inputs))


if __name__ == "__main__":
    main()

