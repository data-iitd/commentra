public class Main {
    public static void main(String[] args) {
        // Declare a string variable to store input
        String S;

        // Read a string input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        S = scanner.next();

        // Iterate through each character in the string until the end of the string is reached
        for(int i = 0; i < S.length(); i++) {
            // Check if the current character is 'A' and the next character is 'C'
            if(S.charAt(i) == 'A' && i + 1 < S.length() && S.charAt(i + 1) == 'C') {
                // If the condition is met, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }

        // If the loop completes without finding "AC", print "No"
        System.out.println("No");
    }
}
