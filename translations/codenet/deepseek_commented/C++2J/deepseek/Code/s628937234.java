public class Main {
    public static void main(String[] args) {
        // Declare two string variables, s and t
        String s, t;
        
        // Create a new Scanner object to read input from the standard input stream
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read a string from the standard input and store it in s
        s = scanner.nextLine();
        
        // Assign the first character of s to t
        t = s.substring(0, 1);
        
        // Append the size of s minus 2 to t
        t += String.valueOf(s.length() - 2);
        
        // Append the last character of s to t
        t += s.substring(s.length() - 1);
        
        // Print the modified string t
        System.out.println(t);
    }
}
