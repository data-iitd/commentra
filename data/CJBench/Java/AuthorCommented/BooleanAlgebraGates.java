
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Implements various Boolean algebra gates (AND, OR, NOT, XOR, NAND, NOR)
 */
public final class BooleanAlgebraGates {

    private BooleanAlgebraGates() {
        // Prevent instantiation
    }

    /**
     * Represents a Boolean gate that takes multiple inputs and returns a result.
     */
    interface BooleanGate {
        /**
         * Evaluates the gate with the given inputs.
         *
         * @param inputs The input values for the gate.
         * @return The result of the evaluation.
         */
        boolean evaluate(List<Boolean> inputs);
    }

    /**
     * AND Gate implementation.
     * Returns true if all inputs are true; otherwise, false.
     */
    static class ANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            for (boolean input : inputs) {
                if (!input) {
                    return false;
                }
            }
            return true;
        }
    }

    /**
     * OR Gate implementation.
     * Returns true if at least one input is true; otherwise, false.
     */
    static class ORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            for (boolean input : inputs) {
                if (input) {
                    return true;
                }
            }
            return false;
        }
    }

    /**
     * NOT Gate implementation (Unary operation).
     * Negates a single input value.
     */
    static class NOTGate {
        /**
         * Evaluates the negation of the input.
         *
         * @param input The input value to be negated.
         * @return The negated value.
         */
        public boolean evaluate(boolean input) {
            return !input;
        }
    }

    /**
     * XOR Gate implementation.
     * Returns true if an odd number of inputs are true; otherwise, false.
     */
    static class XORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            boolean result = false;
            for (boolean input : inputs) {
                result ^= input;
            }
            return result;
        }
    }

    /**
     * NAND Gate implementation.
     * Returns true if at least one input is false; otherwise, false.
     */
    static class NANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            return !new ANDGate().evaluate(inputs); // Equivalent to negation of AND
        }
    }

    /**
     * NOR Gate implementation.
     * Returns true if all inputs are false; otherwise, false.
     */
    static class NORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            return !new ORGate().evaluate(inputs); // Equivalent to negation of OR
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input number of inputs and values
        int n = scanner.nextInt();

        List<Boolean> inputs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            inputs.add(scanner.nextBoolean());
        }

        // Select the gate
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                System.out.println("AND Gate Result: " + new ANDGate().evaluate(inputs));
                break;
            case 2:
                System.out.println("OR Gate Result: " + new ORGate().evaluate(inputs));
                break;
            case 3:
                System.out.println("XOR Gate Result: " + new XORGate().evaluate(inputs));
                break;
            case 4:
                System.out.println("NAND Gate Result: " + new NANDGate().evaluate(inputs));
                break;
            case 5:
                System.out.println("NOR Gate Result: " + new NORGate().evaluate(inputs));
                break;
            case 6:
                if (inputs.size() != 1) {
                    System.out.println("NOT Gate requires exactly one input.");
                } else {
                    System.out.println("NOT Gate Result: " + new NOTGate().evaluate(inputs.get(0)));
                }
                break;
            default:
                System.out.println("Invalid choice.");
        }

        scanner.close();
    }
}
