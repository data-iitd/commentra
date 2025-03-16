
public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input number and the sum
        int n, sum;

        // Read an integer input from the user
        n = Integer.parseInt(args[0]);

        // Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
        sum = (n * (n + 1)) / 2;

        // Print the calculated sum to the console
        System.out.println(sum);
    }
}

