

import sys

# Input number of inputs and values
n = int(input())
inputs = [bool(int(x)) for x in input().split()]

# Select the gate
choice = int(input())

class BooleanGate:
    def evaluate(self, inputs):
        pass

class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        return all(inputs)

class ORGate(BooleanGate):
    def evaluate(self, inputs):
        return any(inputs)

class XORGate(BooleanGate):
    def evaluate(self, inputs):
        return sum(inputs) % 2 == 1

class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)

class NORGate(BooleanGate):
    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)

class NOTGate(BooleanGate):
    def evaluate(self, inputs):
        if len(inputs)!= 1:
            print("NOT Gate requires exactly one input.")
            sys.exit(1)
        return not inputs[0]

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
    print("NOT Gate Result:", NOTGate().evaluate(inputs))
else:
    print("Invalid choice.")

