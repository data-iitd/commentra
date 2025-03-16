
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Main class for Boolean logic gates application.
 */
public final class Main {
    private Main() {
    }

    /**
     * Interface for Boolean logic gates.
     */
    interface BooleanGate {
        /**
         * Evaluates the Boolean logic gate with given inputs.
         *
         * @param inputs the list of Boolean inputs.
         * @return the result of the Boolean logic gate evaluation.
         */
        boolean evaluate(List<Boolean> inputs);
    }

    /**
     * AND gate implementation.
     */
    static class ANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            /**
             * Iterates through the list of Boolean inputs and returns false as soon as an input is false.
             */
            for (boolean input : inputs) {
                if (!input) {
                    return false;
                }
            }
            /**
             * If all inputs are true, returns true.
             */
            return true;
        }
    }

    /**
     * OR gate implementation.
     */
    static class ORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            /**
             * Iterates through the list of Boolean inputs and returns true as soon as an input is true.
             */
            for (boolean input : inputs) {
                if (input) {
                    return true;
                }
            }
            /**
             * If all inputs are false, returns false.
             */
            return false;
        }
    }

    /**
     * NOT gate implementation.
     */
    static class NOTGate {
        /**
         * Evaluates the NOT gate with a single Boolean input.
         *
         * @param input the Boolean input.
         * @return the negated Boolean result.
         */
        public boolean evaluate(boolean input) {
            /**
             * Negates the Boolean input.
             */
            return !input;
        }
    }

    /**
     * XOR gate implementation.
     */
    static class XORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            boolean result = false;
            /**
             * XOR operation is performed by XORing each input with the result and updating the result.
             */
            for (boolean input : inputs) {
                result ^= input;
            }
            /**
             * Returns the final result of the XOR operation.
             */
            return result;
        }
    }

    /**
     * NAND gate implementation.
     */
    static class NANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            /**
             * Negates the result of an AND gate.
             */
            return !new ANDGate().evaluate(inputs);
        }
    }

    /**
     * NOR gate implementation.
     */
    static class NORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            /**
             * Negates the result of an OR gate.
             */
            return !new ORGate().evaluate(inputs);
        }
    }

    /**
     * Main method for user input and gate evaluation.
     *
     * @param args command-line arguments (not used).
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;

        /**
         * Reads the number of Boolean inputs from the user.
         */
        System.out.print("Enter the number of Boolean inputs: ");
        n = scanner.nextInt();

        List<Boolean> inputs = new ArrayList<>();

        /**
         * Reads the Boolean inputs from the user.
         */
        for (int i = 0; i < n; i++) {
            System.out.print("Enter Boolean input " + (i + 1) + ": ");
            inputs.add(scanner.nextBoolean());
        }

        int choice;

        /**
         * Reads the gate type choice from the user.
         */
        System.out.print("Enter the gate type (1 for AND, 2 for OR, 3 for XOR, 4 for NAND, 5 for NOR, 6 for NOT): ");
        choice = scanner.nextInt();

        BooleanGate gate;

        /**
         * Instantiates the gate based on the user's choice.
         */
        switch (choice) {
            case 1:
                gate = new ANDGate();
                break;
            case 2:
                gate = new ORGate();
                break;
            case 3:
                gate = new XORGate();
                break;
            case 4:
                gate = new NANDGate();
                break;
            case 5:
                gate = new NORGate();
                break;
            case 6:
                /**
                 * NOT gate requires exactly one input.
                 */
                if (inputs.size() != 1) {
                    System.out.println("NOT Gate requires exactly one input.");
                    return;
                }
                gate = new NOTGate();
                break;
            default:
                System.out.println("Invalid choice.");
                return;
        }

        /**
         * Evaluates the gate with the given Boolean inputs and prints the result.
         */
        System.out.println("Gate Result: " + gate.evaluate(inputs));

        scanner.close();
    }
}