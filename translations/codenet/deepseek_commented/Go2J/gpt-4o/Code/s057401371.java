import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        // Define the difference between lowercase and uppercase ASCII values
        int d = 'a' - 'A';

        // Iterate over each character in the input string
        StringBuilder result = new StringBuilder();
        for (char r : s.toCharArray()) {
            char rr = r;
            // Check if the character is an uppercase letter
            if ('A' <= r && r <= 'Z') {
                // Convert uppercase to lowercase
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                // Convert lowercase to uppercase
                rr = (char) (r - d);
            }
            // Append the converted character to the result
            result.append(rr);
        }
        System.out.println(result.toString());
    }
}

// <END-OF-CODE>
