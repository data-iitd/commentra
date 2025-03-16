public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the integer input and the string input
        int n;
        String s;
        
        // Read an integer from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        
        // Read a string from standard input
        s = scanner.next();
        
        // Count the occurrences of the substring "ABC" in the input string
        // and print the result
        int count = 0;
        for (int i = 0; i <= s.length() - 3; i++) {
            if (s.substring(i, i + 3).equals("ABC")) {
                count++;
            }
        }
        System.out.println(count);
    }
}
