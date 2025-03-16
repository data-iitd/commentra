import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Main class for the request scheduler problem.
 */
public class Main {

    /**
     * Maximum track length.
     */
    private final int maxTrack;

    /**
     * Current position on the track.
     */
    private final int currentPosition;

    /**
     * Flag indicating whether the direction is up or down.
     */
    private boolean movingUp;

    /**
     * The farthest position reached during the execution.
     */
    private int farthestPosition;

    /**
     * Constructor for the Main class.
     *
     * @param startPosition initial position on the track
     * @param initialDirection initial direction (up or down)
     * @param maxTrack maximum track length
     */
    public Main(int startPosition, boolean initialDirection, int maxTrack) {
        this.currentPosition = startPosition;
        this.movingUp = initialDirection;
        this.maxTrack = maxTrack;
    }

    /**
     * Executes the given list of requests and returns the result.
     *
     * @param requests the list of requests to be executed
     * @return the result of the execution
     */
    public List<Integer> execute(List<Integer> requests) {
        List<Integer> result = new ArrayList<>(); // Initialize an empty result list
        List<Integer> lower = new ArrayList<>(); // Initialize an empty list for requests lower than the current position
        List<Integer> upper = new ArrayList<>(); // Initialize an empty list for requests higher than the current position

        // Iterate through the requests and sort them accordingly
        for (int request : requests) {
            if (request >= 0 && request < maxTrack) { // Check if the request is valid
                if (request < currentPosition) { // If the request is lower than the current position, add it to the lower list
                    lower.add(request);
                } else { // If the request is higher than the current position, add it to the upper list
                    upper.add(request);
                }
            }
        }

        // Sort the lower and upper lists
        Collections.sort(lower);
        Collections.sort(upper);

        // Determine the direction and update the farthest position
        if (movingUp) { // If moving up, add the upper list to the result and update the farthest position
            result.addAll(upper);
            if (!upper.isEmpty()) {
                farthestPosition = upper.get(upper.size() - 1);
            }
            movingUp = false; // Reverse the direction for the next iteration
            Collections.reverse(lower); // Reverse the lower list for the next iteration
            result.addAll(lower); // Add the lower list to the result
            if (!lower.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, lower.get(0)); // Update the farthest position
            }
        } else { // If moving down, reverse the lower list and add it to the result, then add the upper list and update the farthest position
            Collections.reverse(lower);
            result.addAll(lower);
            if (!lower.isEmpty()) {
                farthestPosition = lower.get(0);
            }
            movingUp = true; // Reverse the direction for the next iteration
            result.addAll(upper);
            if (!upper.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, upper.get(upper.size() - 1));
            }
        }

        return result; // Return the final result
    }

    /**
     * Main method for running the program.
     *
     * @param args command-line arguments (not used in this program)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner for reading input

        // Read input from the user
        int maxTrack = scanner.nextInt();
        int startPosition = scanner.nextInt();
        boolean movingUp = scanner.nextInt() == 1;
        int numRequests = scanner.nextInt();
        List<Integer> requests = new ArrayList<>();
        for (int i = 0; i < numRequests; i++) {
            requests.add(scanner.nextInt());
        }

        // Create an instance of the Main class and execute the requests
        Main scheduler = new Main(startPosition, movingUp, maxTrack);
        List<Integer> result = scheduler.execute(requests);

        // Print the result to the console
        for (int r : result) {
            System.out.print(r + " ");
        }

        scanner.close(); // Close the Scanner to free system resources
    }
}
