
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public final class BooleanAlgebraGates {
    private BooleanAlgebraGates() {
    }
    interface BooleanGate {
        boolean evaluate(List<Boolean> inputs);
    }
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
    static class NOTGate {
        public boolean evaluate(boolean input) {
            return !input;
        }
    }
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
    static class NANDGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            return !new ANDGate().evaluate(inputs); 
        }
    }
    static class NORGate implements BooleanGate {
        @Override
        public boolean evaluate(List<Boolean> inputs) {
            return !new ORGate().evaluate(inputs); 
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Boolean> inputs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            inputs.add(scanner.nextBoolean());
        }
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
