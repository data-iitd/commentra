public class Main {
    public static void main(String[] args) {
        // Step 1: Input Handling
        // The program starts by taking a string input from the user.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String source = scanner.nextLine();

        // It checks if the length of the input string is within the valid range (1 to 10 characters).
        // If not, it returns -1.
        if(source.length() > 10 || source.length() < 1) {
            System.out.println(-1);
            return;
        }

        // Step 2: Calculation Setup
        // The program calculates the maximum number of combinations that can be formed
        // by placing '+' signs between the digits of the input string.
        // This is done using the formula 2^(n-1), where n is the length of the input string.
        int max_i = (int)Math.pow(2, source.length() - 1);

        // Step 3: Iterating Over Combinations
        // The program iterates over all possible combinations of placing '+' signs between the digits.
        // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
        double sum = 0;

        for (int i = 0; i < max_i; ++i) {
            java.util.BitSet plus = java.util.BitSet.valueOf(new long[]{i});

            double number = 0;

            String working = source;
            while(plus.nextSetBit(0) != -1) {
                int index = plus.nextSetBit(0);
                sum += Double.parseDouble(working.substring(0, index + 1));
                plus.clear(0, index + 1);
                working = working.substring(index + 1);
            }
            sum += Double.parseDouble(working);
        }

        // Step 4: Output
        // Finally, the program outputs the sum of all possible combinations.
        System.out.printf("%.0f\n", sum);
    }
}
