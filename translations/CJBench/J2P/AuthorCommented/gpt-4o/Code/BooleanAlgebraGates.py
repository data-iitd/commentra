class BooleanGate:
    def evaluate(self, inputs):
        raise NotImplementedError("This method should be overridden.")


class ANDGate(BooleanGate):
    def evaluate(self, inputs):
        return all(inputs)


class ORGate(BooleanGate):
    def evaluate(self, inputs):
        return any(inputs)


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
    n = int(input("Enter number of inputs: "))
    inputs = [input(f"Enter input {i + 1} (True/False): ").strip().lower() == 'true' for i in range(n)]

    choice = int(input("Select gate (1: AND, 2: OR, 3: XOR, 4: NAND, 5: NOR, 6: NOT): "))

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
