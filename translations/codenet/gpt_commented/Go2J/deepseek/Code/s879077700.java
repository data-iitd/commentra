public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String a = scanner.nextLine();
        
        // Initialize a variable 'ans' with the default value "Good"
        String ans = "Good";
        
        // Loop through the first three characters of the string 'a'
        for (int i = 0; i < 3; i++) {
            // Check if the current character is the same as the next character
            if (i + 1 < a.length() && a.charAt(i) == a.charAt(i + 1)) {
                // If they are the same, set 'ans' to "Bad"
                ans = "Bad";
            }
        }
        
        // Print the final result stored in 'ans'
        System.out.println(ans);
    }
}
