
import sys

# Implements various Boolean algebra gates (AND, OR, NOT, XOR, NAND, NOR)


class BooleanGate:
    """Represents a Boolean gate that takes multiple inputs and returns a result."""

    def evaluate(self, inputs):
        """Evaluates the gate with the given inputs.

        Args:
            inputs: The input values for the gate.

        Returns:
            The result of the evaluation.
        """
        raise NotImplementedError()


class ANDGate(BooleanGate):
    """AND Gate implementation.

    Returns true if all inputs are true; otherwise, false.
    """

    def evaluate(self, inputs):
        for input in inputs:
            if not input:
                return False
        return True


class ORGate(BooleanGate):
    """OR Gate implementation.

    Returns true if at least one input is true; otherwise, false.
    """

    def evaluate(self, inputs):
        for input in inputs:
            if input:
                return True
        return False


class NOTGate:
    """NOT Gate implementation (Unary operation).

    Negates a single input value.
    """

    def evaluate(self, input):
        return not input


class XORGate(BooleanGate):
    """XOR Gate implementation.

    Returns true if an odd number of inputs are true; otherwise, false.
    """

    def evaluate(self, inputs):
        result = False
        for input in inputs:
            result ^= input
        return result


class NANDGate(BooleanGate):
    """NAND Gate implementation.

    Returns true if at least one input is false; otherwise, false.
    """

    def evaluate(self, inputs):
        return not ANDGate().evaluate(inputs)  # Equivalent to negation of AND


class NORGate(BooleanGate):
    """NOR Gate implementation.

    Returns true if all inputs are false; otherwise, false.
    """

    def evaluate(self, inputs):
        return not ORGate().evaluate(inputs)  # Equivalent to negation of OR


def main():
    # Input number of inputs and values
    n = int(input())

    inputs = []
    for _ in range(n):
        inputs.append(bool(input()))

    # Select the gate
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


