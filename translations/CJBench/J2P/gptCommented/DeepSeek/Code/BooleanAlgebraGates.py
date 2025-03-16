class BooleanGate:
    def evaluate(self, inputs):
        pass

class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        return all(inputs)

class ORGate(BooleanGate):
    def evaluate(self, inputs):
        return any(inputs)

class NOTGate:
    def evaluate(self, input_):
        return not input_

class XORGate(BooleanGate):
    def evaluate(self, inputs):
        result = False
        for input_ in inputs:
            result ^= input_
        return result

class NANDGate(BooleanGate):
    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)

class NORGate(BooleanGate):
    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)

def main():
    n = int(input())
    inputs = list(map(bool, map(int, input().split())))
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
