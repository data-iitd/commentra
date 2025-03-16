from typing import List

class BooleanGate:
    def evaluate(self, inputs: List[bool]) -> bool:
        raise NotImplementedError("This method should be overridden.")

class ANDGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return all(inputs)

class ORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return any(inputs)

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
        value = input(f"Enter Boolean input {i + 1} (True/False): ")
        inputs.append(value.lower() == 'true')

    choice = int(input("Enter the gate type (1 for AND, 2 for OR, 3 for XOR, 4 for NAND, 5 for NOR, 6 for NOT): "))
    
    gate = None

    if choice in [1, 2, 3, 4, 5]:
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

    if choice == 6:
        result = gate.evaluate(inputs[0])
    else:
        result = gate.evaluate(inputs)

    print("Gate Result:", result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
