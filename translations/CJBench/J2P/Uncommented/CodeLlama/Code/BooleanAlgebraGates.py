
import sys

def main():
    n = int(sys.stdin.readline())
    inputs = []
    for i in range(n):
        inputs.append(bool(int(sys.stdin.readline())))
    choice = int(sys.stdin.readline())
    if choice == 1:
        print("AND Gate Result: " + str(ANDGate(inputs)))
    elif choice == 2:
        print("OR Gate Result: " + str(ORGate(inputs)))
    elif choice == 3:
        print("XOR Gate Result: " + str(XORGate(inputs)))
    elif choice == 4:
        print("NAND Gate Result: " + str(NANDGate(inputs)))
    elif choice == 5:
        print("NOR Gate Result: " + str(NORGate(inputs)))
    elif choice == 6:
        if len(inputs) != 1:
            print("NOT Gate requires exactly one input.")
        else:
            print("NOT Gate Result: " + str(NOTGate(inputs[0])))
    else:
        print("Invalid choice.")

def ANDGate(inputs):
    for input in inputs:
        if not input:
            return False
    return True

def ORGate(inputs):
    for input in inputs:
        if input:
            return True
    return False

def XORGate(inputs):
    result = False
    for input in inputs:
        result ^= input
    return result

def NANDGate(inputs):
    return not ANDGate(inputs)

def NORGate(inputs):
    return not ORGate(inputs)

def NOTGate(input):
    return not input

if __name__ == "__main__":
    main()

