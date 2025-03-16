public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements N
        int[] A = new int[N]; // Declare an array A with N elements
        for (int i = 0; i < N; i++) { // Loop to read N elements into the array A
            A[i] = scanner.nextInt();
        }
        int ans = 0; // Initialize answer variable ans to 0
        int count = 0; // Initialize count variable to 0
        for (int i = 0; i < N - 1; i++) { // Loop through the array elements
            if (A[i] == A[i + 1]) { // Check if the current element is equal to the next element
                count++; // Increment the count
                if (count % 2 != 0) { // Check if the count is odd
                    ans++; // Increment the answer variable ans
                }
            } else {
                count = 0; // Reset the count to 0 if the current element is not equal to the next element
            }
        }
        System.out.println(ans); // Print the value of ans
    }
}
