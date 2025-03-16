public class ReverseString {
    public static void main(String[] args) {
        // Declare a String variable to hold the input string (maximum length 20 + 1 for null terminator)
        String str;
        int i, len;
        
        // Create a Scanner object to read input from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read a string from standard input
        str = scanner.next();
        
        // Calculate the length of the input string
        len = str.length();

        // Loop through the string in reverse order
        for(i = len - 1; i >= 0; i--){
            // Output each character of the string in reverse
            System.out.print(str.charAt(i));
        }
        
        // Print a newline character after the reversed string
        System.out.println();
        
        // Return 0 to indicate successful completion of the program
        // Note: In Java, the return type of the main method is void, so we don't need to return anything
    }
}
