
import sys

class Main:
    def __init__(self):
        pass

    class BooleanGate:
        def __init__(self):
            pass

        def evaluate(self, inputs):
            pass

    class ANDGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, inputs):
            for input in inputs:
                if not input:
                    return False
            return True

    class ORGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, inputs):
            for input in inputs:
                if input:
                    return True
            return False

    class NOTGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, input):
            return not input

    class XORGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, inputs):
            result = False
            for input in inputs:
                result ^= input
            return result

    class NANDGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, inputs):
            return not Main.ANDGate().evaluate(inputs)

    class NORGate(BooleanGate):
        def __init__(self):
            super().__init__()

        def evaluate(self, inputs):
            return not Main.ORGate().evaluate(inputs)

    def main(self):
        n = int(input("Enter the number of Boolean inputs: "))
        inputs = []
        for i in range(n):
            inputs.append(bool(input("Enter Boolean input " + str(i + 1) + ": ")))
        choice = int(input("Enter the gate type (1 for AND, 2 for OR, 3 for XOR, 4 for NAND, 5 for NOR, 6 for NOT): "))
        gate = None
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
            if len(inputs)!= 1:
                print("NOT Gate requires exactly one input.")
                return
            gate = Main.NOTGate()
        else:
            print("Invalid choice.")
            return
        print("Gate Result: " + str(gate.evaluate(inputs)))

if __name__ == "__main__":
    Main().main()

