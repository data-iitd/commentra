import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input and split into two strings, a and b
        String[] input = scanner.nextLine().trim().split(" ");
        String a = input[0];
        String b = input[1];
        
        // Determine the maximum length of the two strings
        int x = Math.max(a.length(), b.length());
        
        // Pad the shorter string with zeros on the left
        a = String.format("%" + x + "s", a).replace(' ', '0');
        
        // Pad the shorter string with zeros on the right
        b = String.format("%-" + x + "s", b).replace(' ', '0');
        
        // Initialize an empty StringBuilder to store the result
        StringBuilder s = new StringBuilder();
        
        // Initialize carry to 0
        int c = 0;
        
        // Loop through each digit from right to left
        for (int i = 0; i < x; i++) {
            // Add the corresponding digits from a and b along with the carry
            int d = Character.getNumericValue(b.charAt(i)) + Character.getNumericValue(a.charAt(x - i - 1)) + c;
            
            // If the sum is greater than 9, set carry to 1 and append the tens digit
            if (d > 9) {
                s.append(d % 10);
                c = 1;
            } else {
                // Otherwise, append the sum and set carry to 0
                s.append(d);
                c = 0;
            }
        }
        
        // If there's a carry left after the final addition, append '1'
        if (c == 1) {
            s.append('1');
        }
        
        // Reverse the result string and print it as an integer
        System.out.println(Integer.parseInt(s.reverse().toString()));
        
        scanner.close();
    }
}
// <END-OF-CODE>
