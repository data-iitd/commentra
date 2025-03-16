
import sys

class Main:
    def __init__(self):
        pass

    class BooleanGate:
        def evaluate(self, inputs):
            pass

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
            return not self.ANDGate().evaluate(inputs)

    class NORGate(BooleanGate):
        def evaluate(self, inputs):
            return not self.ORGate().evaluate(inputs)

    def main(self):
        n = int(sys.stdin.readline())
        inputs = []
        for i in range(n):
            inputs.append(bool(int(sys.stdin.readline())))
        choice = int(sys.stdin.readline())
        if choice == 1:
            print("AND Gate Result: " + str(self.ANDGate().evaluate(inputs)))
        elif choice == 2:
            print("OR Gate Result: " + str(self.ORGate().evaluate(inputs)))
        elif choice == 3:
            print("XOR Gate Result: " + str(self.XORGate().evaluate(inputs)))
        elif choice == 4:
            print("NAND Gate Result: " + str(self.NANDGate().evaluate(inputs)))
        elif choice == 5:
            print("NOR Gate Result: " + str(self.NORGate().evaluate(inputs)))
        elif choice == 6:
            if len(inputs)!= 1:
                print("NOT Gate requires exactly one input.")
            else:
                print("NOT Gate Result: " + str(self.NOTGate().evaluate(inputs[0])))
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    Main().main()

