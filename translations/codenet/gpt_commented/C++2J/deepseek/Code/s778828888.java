public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
        int n, m, x;
        // Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
        int[] a = new int[105];
        
        // Read the values of n, m, and x from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        x = scanner.nextInt();

        // Read m numbers from input and mark their presence in the array 'a'
        for(int i = 0; i < m; ++i)
        {
            int temp = scanner.nextInt();
            a[temp] = 1;
        }

        // Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
        int ansl = 0, ansr = 0;

        // Count how many numbers are present from x to n (right side)
        for(int i = x; i <= n; ++i)
        {
            ansr += a[i]; // Increment ansr if a[i] is 1 (indicating presence)
        }

        // Count how many numbers are present from x to 0 (left side)
        for(int i = x; i >= 0; --i)
        {
            ansl += a[i]; // Increment ansl if a[i] is 1 (indicating presence)
        }

        // Output the minimum of the counts from both sides
        System.out.println(Math.min(ansl, ansr));
        
        // Return 0 to indicate successful completion of the program
    }
}
