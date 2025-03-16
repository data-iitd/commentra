public class Main {
    public static void main(String[] args) {
        int x;  // Declare an integer variable named x

        // Read an integer value from the standard input and store it in the variable x
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();

        if(x == 1) {  // Check if the value of x is equal to 1
            System.out.println("0");  // If x is 1, print 0 to the standard output
        } else {  // If x is not equal to 1
            System.out.println("1");  // Otherwise, print 1 to the standard output
        }
    }
}
