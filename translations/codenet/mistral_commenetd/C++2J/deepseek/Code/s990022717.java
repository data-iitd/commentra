public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int n, k, x, y;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt(); // Read input value for n from standard input
        k = scanner.nextInt(); // Read input value for k from standard input
        x = scanner.nextInt(); // Read input value for x from standard input
        y = scanner.nextInt(); // Read input value for y from standard input

        int sum = 0; // Initialize sum variable to 0

        // Iterate through numbers from 1 to n
        for(int i=1;i<=n;i++){
            // If the current number i is greater than k, add y to the sum
            if(i>k)sum+=y;
            // Otherwise, add x to the sum
            else sum+=x;
        }

        // Output the final sum value to the standard output
        System.out.println(sum);
    }
}
