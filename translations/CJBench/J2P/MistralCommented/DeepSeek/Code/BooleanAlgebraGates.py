from typing import List

class BooleanGate:
    def evaluate(self, inputs: List[bool]) -> bool:
        pass

class ANDGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        for input in inputs:
            if not input:
                return False
        return True

class ORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        for input in inputs:
            if input:
                return True
        return False

class NOTGate:
    def evaluate(self, input: bool) -> bool:
        return not input

class XORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        result = False
        for input in inputs:
            result ^= input
        return result

class NANDGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return not ANDGate().evaluate(inputs)

class NORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return not ORGate().evaluate(inputs)

def main():
    n = int(input("Enter the number of Boolean inputs: "))
    inputs = []
    for i in range(n):
        inputs.append(bool(int(input(f"Enter Boolean input {i + 1}: "))))

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
        if len(inputs) != 1:
            print("NOT Gate requires exactly one input.")
            return
        gate = NOTGate()
    else:
        print("Invalid choice.")
        return

    result = gate.evaluate(inputs)
    print("Gate Result:", result)

if __name__ == "__main__":
    main()
