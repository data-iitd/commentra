
public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Read three integers from the user
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        // Check if the first number is less than the second and the second is less than the third
        if(a < b && b < c) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}

