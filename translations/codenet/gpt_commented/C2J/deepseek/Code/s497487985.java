public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long n = scanner.nextLong(); // Number of participants
        long k = scanner.nextLong(); // Points required to win
        long q = scanner.nextLong(); // Number of questions
        long[] a = new long[100001]; // Array to store the questions
        long[] point = new long[100001]; // Array to track points of each participant

        // Read input values for n, k, and q
        // No need to initialize points for each participant to k or check if any participant has less points than k

        // Process each question and update points for the corresponding participant
        for (long i = 0; i < q; i++) {
            a[(int) i] = scanner.nextLong(); // Read the participant number for the question
            point[(int) (a[(int) i] - 1)]++; // Increment the point for the participant who answered
            /*
            // Update points for other participants (commented out)
            for (long j = 0; j < n; j++) {
                if (a[i] != (j + 1) && point[j] < k) {
                    point[j]++;
                }
                // System.out.printf("i = %d  point = %d\n", i, point[j]);
            }
            */
        }

        // Determine if each participant has enough points to win
        for (long i = 0; i < n; i++) {
            if (k - (q - point[(int) i]) > 0) { // Check if the participant has enough points
                System.out.println("Yes"); // Participant can win
            } else {
                System.out.println("No"); // Participant cannot win
            }
        }
    }
}
