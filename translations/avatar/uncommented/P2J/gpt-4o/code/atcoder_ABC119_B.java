import java.util.Scanner;

public class CurrencyConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        double total = 0.0;

        for (int i = 0; i < N; i++) {
            String input = scanner.nextLine();
            input = input.replace("JPY", "* 1.0").replace("BTC", "* 380000.0");
            total += eval(input);
        }

        System.out.println(total);
        scanner.close();
    }

    private static double eval(String expression) {
        // This method evaluates the mathematical expression in the string
        // Note: In a real application, you should use a library for safe evaluation
        // Here we use a simple approach for demonstration purposes
        return new Object() {
            public double evaluate(String expression) {
                return new Object() {
                    public double eval() {
                        try {
                            return (double) new javax.script.ScriptEngineManager()
                                    .getEngineByName("JavaScript")
                                    .eval(expression);
                        } catch (Exception e) {
                            e.printStackTrace();
                            return 0.0;
                        }
                    }
                }.eval();
            }
        }.evaluate(expression);
    }
}
