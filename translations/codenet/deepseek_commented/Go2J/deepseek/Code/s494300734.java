public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next(); // Read a string from standard input
        
        String ans = "No"; // Initialize the answer variable with "No"
        
        // Check if 'C' appears before the last occurrence of 'F' in the string s
        int firstC = s.indexOf('C');
        int lastF = s.lastIndexOf('F');
        if (firstC >= 0 && firstC < lastF) {
            ans = "Yes"; // Update ans to "Yes" if the condition is true
        }
        
        // Check if 'C' does not appear in the string s
        if (s.indexOf('C') < 0) {
            ans = "No"; // Update ans to "No" if the condition is true
        }
        
        System.out.println(ans); // Print the final value of ans
    }
}
