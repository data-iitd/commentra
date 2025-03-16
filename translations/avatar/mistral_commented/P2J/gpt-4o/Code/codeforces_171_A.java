import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Reading the input and splitting it into two strings 'a' and 'b'
        String[] input = scanner.nextLine().split(" ");
        String a = input[0];
        String b = input[1];
        
        // Finding the maximum length between 'a' and 'b'
        int x = Math.max(a.length(), b.length());
        
        // Padding 'a' with leading zeros and 'b' with trailing zeros
        a = String.format("%" + x + "s", a).replace(' ', '0');
        b = String.format("%-" + x + "s", b).replace(' ', '0');
        
        // Initializing an empty StringBuilder 's' and a counter 'c' for carrying
        StringBuilder s = new StringBuilder();
        int c = 0;

        // Iterating through each index 'i' in the range of the length of the padded strings 'x'
        for (int i = 0; i < x; i++) {
            // Adding the current digits of 'a' and 'b' at the corresponding positions and carrying if necessary
            int d = Character.getNumericValue(b.charAt(i)) + Character.getNumericValue(a.charAt(x - i - 1)) + c;

            // If the sum is greater than 9, add the carry to the next digit and reset the carry to 0
            if (d > 9) {
                s.append(d % 10);
                c = 1;
            } else {
                // If the sum is less than or equal to 9, add the digit to the result string 's'
                s.append(d);
                c = 0;
            }
        }

        // If there is still a carry left, add it to the result string 's'
        if (c == 1) {
            s.append('1');
        }

        // Printing the final result after removing the leading zeros (if any)
        // We need to reverse the string since we built it backwards
        String result = s.reverse().toString();
        System.out.println(Integer.parseInt(result)); // This will remove leading zeros

        // Closing the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
