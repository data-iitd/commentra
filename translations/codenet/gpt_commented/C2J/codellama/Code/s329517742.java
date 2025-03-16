
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Read two integers from the user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Check if 500 times the value of 'a' is greater than or equal to 'b'
        if (500 * a >= b) 
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        else 
            // If the condition is false, print "No"
            System.out.println("No");
    }
}

