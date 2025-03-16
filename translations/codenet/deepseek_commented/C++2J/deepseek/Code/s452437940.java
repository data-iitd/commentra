public class Main {
    public static void main(String[] args) {
        // Declare variables to store user input
        long a, b, x;
        
        // Read three long integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextLong();
        b = scanner.nextLong();
        x = scanner.nextLong();
        
        // Calculate the number of multiples of x between a and b inclusive
        long s = (b / x - a / x);
        
        // Check if a is a multiple of x and adjust the count accordingly
        if (a % x == 0)
            s++;
        
        // Print the result
        System.out.println(s);
    }
}
