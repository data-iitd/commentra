import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    // Interface defining a Boolean gate with an evaluate method
    interface BooleanGate {
        boolean evaluate(List<Boolean> inputs);
    }

    // Class representing an AND gate
    static class ANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            // Evaluate AND gate: returns true only if all inputs are true
            for (boolean input : inputs) {
                if (!input) {
                    return false; // If any input is false, return false
                }
            }
            return true; // All inputs are true
        }
    }

    // Class representing an OR gate
    static class ORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            // Evaluate OR gate: returns true if at least one input is true
            for (boolean input : inputs) {
                if (input) {
                    return true; // If any input is true, return true
                }
            }
            return false; // All inputs are false
        }
    }

    // Class representing a NOT gate
    static class NOTGate {
        public boolean evaluate(boolean input) {
            // Evaluate NOT gate: returns the negation of the input
            return !input;
        }
    }

    // Class representing an XOR gate
    static class XORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            // Evaluate XOR gate: returns true if an odd number of inputs are true
            boolean result = false;
            for (boolean input : inputs) {
                result ^= input; // Toggle result for each true input
            }
            return result; // Return the final result
        }
    }

    // Class representing a NAND gate
    static class NANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            // Evaluate NAND gate: returns the negation of the AND gate result
            return !new ANDGate().evaluate(inputs); 
        }
    }

    // Class representing a NOR gate
    static class NORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            // Evaluate NOR gate: returns the negation of the OR gate result
            return !new ORGate().evaluate(inputs); 
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of inputs
        int n = scanner.nextInt();
        List<Boolean> inputs = new ArrayList<>();
        
        // Read the boolean inputs from the user
        for (int i = 0; i < n; i++) {
            inputs.add(scanner.nextBoolean());
        }
        
        // Read the choice of gate from the user
        int choice = scanner.nextInt();
        
        // Evaluate the chosen gate and print the result
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
                // Check if the NOT gate has exactly one input
                if (inputs.size() != 1) {
                    System.out.println("NOT Gate requires exactly one input.");
                } else {
                    System.out.println("NOT Gate Result: " + new NOTGate().evaluate(inputs.get(0)));
                }
                break;
            default:
                // Handle invalid choices
                System.out.println("Invalid choice.");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
