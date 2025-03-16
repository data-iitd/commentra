public class Main {
    public static void main(String[] args) {
        int A, B; // Declare variables A and B to store input values
        int ans = 0; // Initialize answer variable ans to 0
        int out = 1; // Initialize counter variable out to 1

        // Read values of A and B from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();

        // Use a while loop to find the number of times A can be added to get a value greater than or equal to B
        while(out<B){
            out--; // Decrement out by 1
            out += A; // Increment out by A
            ans++; // Increment ans by 1 each time the loop runs
        }

        // Display the answer
        System.out.println("The answer is: " + ans);

        // Return 0 to indicate successful execution
        System.exit(0);
    }
}
