public class ReverseString {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.next(); // Read a string from the user
        
        char[] charArray = str.toCharArray(); // Convert the string to a character array
        int len = charArray.length; // Calculate the length of the character array
        
        // Reverse the character array and print it
        for (int i = len - 1; i >= 0; i--) {
            System.out.print(charArray[i]); // Print each character in reverse order
        }
        System.out.println(); // Print a newline character at the end
    }
}
