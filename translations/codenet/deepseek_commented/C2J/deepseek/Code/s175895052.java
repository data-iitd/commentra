public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String n = scanner.next();  // Read a string from the user input

        // Check if any two consecutive characters in the string n are the same
        if ((n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2)) || (n.charAt(1) == n.charAt(2) && n.charAt(2) == n.charAt(3))) {
            System.out.println("Yes");  // Print "Yes" if the condition is true
        } else {
            System.out.println("No");  // Print "No" if the condition is false
        }
    }
}
