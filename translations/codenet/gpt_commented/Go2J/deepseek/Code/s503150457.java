public class Main {
    public static void main(String[] args) {
        // Declare three string variables to hold user input
        String s1, s2, s3;
        
        // Read three strings from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        s1 = scanner.next();
        s2 = scanner.next();
        s3 = scanner.next();

        // Convert the first character of each string to uppercase and concatenate them
        String result = s1.substring(0, 1).toUpperCase() + s2.substring(0, 1).toUpperCase() + s3.substring(0, 1).toUpperCase();
        
        // Print the concatenated result
        System.out.println(result);
    }
}
