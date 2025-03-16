import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable for iteration and a character array to store input
        int i;
        char S[] = new char[6];

        // Read a string input from the user
        Scanner sc = new Scanner(System.in);
        String S1 = sc.next();

        // Iterate through each character in the string until the null terminator is reached
        for(i = 0; S1.charAt(i)!= '\0'; i++) {
            // Check if the current character is 'A' and the next character is 'C'
            if(S1.charAt(i) == 'A' && S1.charAt(i + 1) == 'C') {
                // If the condition is met, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }

        // If the loop completes without finding "AC", print "No"
        System.out.println("No");
    }
}
