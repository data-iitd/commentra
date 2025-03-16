public class Main {
    public static void main(String[] args) {
        // Declare a string variable to hold the input
        String source = "";
        // Read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        source = scanner.nextLine();

        // Check if the input length is valid (between 1 and 10 characters)
        if(source.length() > 10 || source.length() < 1) {
            // Return -1 if the input length is invalid
            System.out.println(-1);
            return;
        }

        // Calculate the maximum number of combinations of '+' placements
        int max_i = (int)Math.pow(2, source.length() - 1);

        // Initialize a variable to hold the cumulative sum of the evaluated expressions
        double sum = 0;

        // Iterate through all possible combinations of '+' placements
        for (int i = 0; i < max_i; ++i) {
            // Create a bitset to represent the current combination of '+' placements
            java.util.BitSet plus = java.util.BitSet.valueOf(new long[]{i});

            // Initialize a variable to hold the current number being evaluated
            double number = 0;

            // Create a working copy of the source string to manipulate
            String working = source;
            // While there are still '+' placements to evaluate
            while(plus.nextSetBit(0) != -1) {
                int i = plus.nextSetBit(0);
                // Convert the substring up to the current position to a double and add to sum
                sum += Double.parseDouble(working.substring(0, i + 1));
                // Update the working string to remove the processed segment
                working = working.substring(i + 1);
                // Shift the bitset to the right to evaluate the next segment
                plus.clear(0, i + 1);
            }
            // Add the remaining part of the working string to the sum
            sum += Double.parseDouble(working);
        }

        // Set the precision for output and print the final sum
        System.out.printf("%.0f\n", sum);
    }
}
