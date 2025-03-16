public class Main {
    public static void main(String[] args) {
        // Declare three string variables to hold the input values
        String s1, s2, s3;

        // Read input values for s1, s2, and s3 from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        s1 = scanner.next();
        s2 = scanner.next();
        s3 = scanner.next();

        // Split each input string into individual characters
        String[] s1s = s1.split("");
        String[] s2s = s2.split("");
        String[] s3s = s3.split("");

        // Print the uppercase version of the first character of each input string
        System.out.println(s1s[0].toUpperCase() + s2s[0].toUpperCase() + s3s[0].toUpperCase());
    }
}
