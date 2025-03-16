import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the input line
        String[] input = scanner.nextLine().split(" ");
        String a = input[0];
        String b = input[1];

        // Finding the maximum length between 'a' and 'b' and padding zeros to the shorter string
        int x = Math.max(a.length(), b.length());
        a = String.format("%1$" + x + "s", a).replace(' ', '0');
        b = String.format("%1$" + x + "s", b).replace(' ', '0');

        // Initializing an empty string 's' and a counter 'c' for carrying
        StringBuilder s = new StringBuilder();
        int c = 0;

        // Iterating through each index 'i' in the range of the length of the padded strings 'x'
        for (int i = 0; i < x; i++) {

            // Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
            int d = Character.getNumericValue(b.charAt(x - i - 1)) + Character.getNumericValue(a.charAt(i)) + c;

            // If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
            if (d > 9) {
                s.append(d % 10);
                c = 1;
            }

            // If the sum is less than or equal to 9, add the digit to the result string 's'
            else {
                s.append(d);
                c = 0;
            }
        }

        // If there is still a carry left, add it to the result string 's'
        if (c == 1) {
            s.append(c);
        }

        // Printing the final result after removing the leading zeros (if any)
        System.out.println(Integer.parseInt(s.reverse().toString()));
    }
}
