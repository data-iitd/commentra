public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt(); // Read the value of N from the standard input
        long sum = 0; // Initialize sum to store the sum of elements
        long wa = 0; // Initialize wa to store the weighted sum
        int[] A = new int[N]; // Declare an array A of size N to store the elements
        int[] sa = new int[N]; // Declare an array sa of size N to store the differences between consecutive elements
        int ans = 0; // Declare an integer variable ans to store the result
        int shou = 0; // Declare an integer variable shou to store the quotient
        long min = 1123456789; // Initialize min to store the minimum value

        // Use a for loop to read the elements of the array A and calculate the sum and wa
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read the elements of the array A
            sum += A[i]; // Add the current element to sum
            wa += i + 1; // Add the current index+1 to wa
        }

        // Check if the sum is divisible by wa
        if (sum % wa != 0) ans = 0; // If not, set ans to 0
        else {
            shou = (int) (sum / wa); // Calculate the quotient shou
            // Calculate the differences between consecutive elements and store them in the array sa
            for (int i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou;
            }

            // Check if all differences are less than or equal to 0 and divisible by N
            for (int i = 0; i < N - 1; i++) {
                if (sa[i] <= 0 && sa[i] % N == 0)
                    ans = 1; // If so, set ans to 1
                else {
                    ans = 0; // Otherwise, set ans to 0 and break the loop
                    break;
                }
            }
        }

        // Print "YES" if ans is 1, otherwise print "NO"
        if (ans == 1) System.out.println("YES");
        else System.out.println("NO");
    }
}
