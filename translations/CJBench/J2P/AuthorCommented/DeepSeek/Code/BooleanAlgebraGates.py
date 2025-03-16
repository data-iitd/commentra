from typing import List

class BooleanGate:
    def evaluate(self, inputs: List[bool]) -> bool:
        raise NotImplementedError("Subclasses must implement this method")

class ANDGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return all(inputs)

class ORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return any(inputs)

class NOTGate:
    def evaluate(self, input_val: bool) -> bool:
        return not input_val

class XORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        result = False
        for input_val in inputs:
            result ^= input_val
        return result

class NANDGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return not ANDGate().evaluate(inputs)

class NORGate(BooleanGate):
    def evaluate(self, inputs: List[bool]) -> bool:
        return not ORGate().evaluate(inputs)

def main():
    n = int(input())
    inputs = [bool(int(input())) for _ in range(n)]
    choice = int(input())

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
