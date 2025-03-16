public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String n = System.console().readLine();
        
        // Loop through the first three characters of the input string
        for (int i = 0; i < 3; i++) {
            // Check if the current character is '7'
            if (n.charAt(i) == '7') {
                // If '7' is found, print "Yes" and exit the program
                System.out.println("Yes");
                return;
            }
        }
        
        // If '7' is not found in the first three characters, print "No"
        System.out.println("No");
    }
}
