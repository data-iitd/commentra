public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read an integer `n` and a string `s` from the standard input.
        int n = scanner.nextInt();
        String s = scanner.next();
        
        // Print the number of occurrences of the substring "ABC" in the string `s`.
        // The `s.split("ABC").length - 1` expression is used to count the occurrences of the substring "ABC".
        System.out.println(s.split("ABC").length - 1);
    }
}
