
public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int n;

        // Read an integer value from standard input
        n = Integer.parseInt(args[0]);

        // Check if n is a multiple of 1000
        if(n % 1000 == 0) 
            // If true, print 0 since no additional amount is needed to reach the next multiple of 1000
            System.out.println(0);
        else 
            // If false, calculate and print the difference to the next multiple of 1000
            System.out.println((n / 1000 + 1) * 1000 - n);
    }
}

