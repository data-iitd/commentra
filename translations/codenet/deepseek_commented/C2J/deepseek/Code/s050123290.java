public class SumOfDigits {
    public static void main(String[] args) {
        // 1. Define the array and variables
        char[] su = new char[1000]; // Array to store the sequence of digits
        int susum = 0; // Variable to store the sum of the digits
        int j = 0; // Index to iterate through the array

        while (true) {
            // 2. Read input and calculate sum
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            String input = scanner.nextLine();
            if (input.equals("0")) break; // Break if the sequence starts with '0'

            for (j = 0; j < input.length(); j++) {
                su[j] = input.charAt(j);
                susum += su[j] - '0'; // Convert character to integer and add to sum
            }

            // 3. Print the sum
            System.out.println(susum); // Print the sum of the digits
            susum = 0; // Reset the sum for the next sequence
        }
        // 4. Check for termination condition
    }
}
