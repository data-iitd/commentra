public class Main {
    public static void main(String[] args) {
        // Declare a character array to store the input string
        char[] S = new char[6];
        
        // Read a string input from the user and store it in S
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String input = scanner.nextLine();
        input.getChars(0, input.length(), S, 0);
        
        // Loop through each character in the string S
        for(int i = 0; i < S.length; i++){
            // Check if the current character is 'A' and the next character is 'C'
            if(S[i] == 'A' && i + 1 < S.length && S[i + 1] == 'C'){
                // If the condition is met, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }
        
        // If the condition is not met after the loop completes, print "No" and exit the program
        System.out.println("No");
    }
}
