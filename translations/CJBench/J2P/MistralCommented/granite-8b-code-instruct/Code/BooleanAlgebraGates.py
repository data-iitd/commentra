

import sys

class BooleanGate:
    def evaluate(self, inputs):
        raise NotImplementedError("evaluate() method must be implemented in subclass.")

class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        for input in inputs:
            if not input:
                return False
        return True

class ORGate(BooleanGate):
    def evaluate(self, inputs):
        for input in inputs:
            if input:
                return True
        return False

class NOTGate:
    def evaluate(self, input):
        return not input

class XORGate(BooleanGate):
    def evaluate(self, inputs):
        result = False
        for input in inputs:
            result ^= input
        return result

class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)

class NORGate(BooleanGate):
    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)

def main():
    n = int(input("Enter the number of Boolean inputs: "))
    inputs = []
    for i in range(n):
        input_value = input("Enter Boolean input " + str(i + 1) + ": ")
        inputs.append(input_value)

    choice = int(input("Enter the gate type (1 for AND, 2 for OR, 3 for XOR, 4 for NAND, 5 for NOR, 6 for NOT): "))

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
        gate = NOTGate()
    else:
        print("Invalid choice.")
        sys.exit(1)

    result = gate.evaluate(inputs)
    print("Gate Result: " + str(result))

if __name__ == "__main__":
    main()

