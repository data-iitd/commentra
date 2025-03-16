import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input and split into two strings a and b
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        String a = parts[0];
        String b = parts[1];

        // Determine the maximum length of the two strings
        int x = Math.max(a.length(), b.length());

        // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
        a = String.format("%" + x + "s", a).replace(' ', '0');
        b = String.format("%-" + x + "s", b).replace(' ', '0');

        // Initialize an empty StringBuilder to store the result and a carry variable
        StringBuilder s = new StringBuilder();
        int c = 0;

        // Iterate over each digit from the least significant to the most significant
        for (int i = 0; i < x; i++) {
            // Calculate the sum of the corresponding digits and the carry
            int d = Character.getNumericValue(b.charAt(i)) + Character.getNumericValue(a.charAt(x - i - 1)) + c;

            // Check if the sum exceeds 9, which requires a carry
            if (d > 9) {
                s.append(d % 10); // Append the last digit of the sum to the result
                c = 1; // Set carry to 1 for the next iteration
            } else {
                s.append(d); // Append the sum to the result
                c = 0; // Reset carry to 0
            }
        }

        // If there's a carry left after the last addition, append '1' to the result
        if (c == 1) {
            s.append('1');
        }

        // Print the final result, reversing the string to get the correct order and converting to int to remove leading zeros
        System.out.println(Integer.parseInt(s.reverse().toString()));
    }
}

// <END-OF-CODE>
