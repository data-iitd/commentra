
public class Main {
    public static void main(String[] args) {
        // Read the number of elements from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Read the list of integers from the user input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize variables to track the current level and the number of turns
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;

        // Start a while loop that continues until all elements are processed
        while (counter < n) {
            // Increment the turn counter
            counterTurns++;
            // Iterate over the list 'a' to process each element
            for (int i = 0; i < n; i++) {
                // Check if the element is not -1 and is less than or equal to the current level
                if (a[i] != -1 && a[i] <= currentLevel) {
                    // Increment the counter and mark the element as processed
                    counter++;
                    a[i] = -1;
                }
            }
            // Reverse the list 'a' to process elements in a different order in the next iteration
            for (int i = 0; i < n / 2; i++) {
                int temp = a[i];
                a[i] = a[n - i - 1];
                a[n - i - 1] = temp;
            }
        }

        // Print the number of turns taken to process all elements
        System.out.println(counterTurns);
    }
}
