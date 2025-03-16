public class Main {
    public static String group(int n) { // Function to determine group based on input number n
        if (n == 4 || n == 6 || n == 9 || n == 11) { // Check if number belongs to group B
            return "B";
        } else {
            return "A";
        }
    }

    public static void main(String[] args) { // Main function
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a scanner object
        int x = scanner.nextInt(); // Read input value of x from standard input
        int y = scanner.nextInt(); // Read input value of y from standard input

        if (x == 2 || y == 2) { // Check if either x or y is equal to 2
            System.out.println("No"); // If yes, print "No" and exit
            return;
        }

        String xg = group(x); // Determine group of number x
        String yg = group(y); // Determine group of number y

        if (xg.equals(yg)) { // Check if both numbers belong to the same group
            System.out.println("Yes"); // If yes, print "Yes"
        } else {
            System.out.println("No"); // If not, print "No"
        }
    }
}
