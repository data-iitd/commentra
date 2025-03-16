
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // The maximum track number the elevator can reach
    private final int maxTrack;
    // The current position of the elevator
    private final int currentPosition;
    // Indicates the direction in which the elevator is moving
    private boolean movingUp;
    // The farthest position reached by the elevator
    private int farthestPosition;

    // Constructor to initialize the elevator's state
    public Main(int startPosition, boolean initialDirection, int maxTrack) {
        this.currentPosition = startPosition;
        this.movingUp = initialDirection;
        this.maxTrack = maxTrack;
    }

    // Method to execute the elevator's movement based on the requests
    public List<Integer> execute(List<Integer> requests) {
        // List to store the order of requests
        List<Integer> result = new ArrayList<>();
        // Lists to store requests categorized by their position relative to the current position
        List<Integer> lower = new ArrayList<>();
        List<Integer> upper = new ArrayList<>();

        // Categorize requests based on their position
        for (int request : requests) {
            if (request >= 0 && request < maxTrack) {
                if (request < currentPosition) {
                    lower.add(request);
                } else {
                    upper.add(request);
                }
            }
        }

        // Sort the lists of requests
        Collections.sort(lower);
        Collections.sort(upper);

        // Execute the requests based on the current direction
        if (movingUp) {
            result.addAll(upper); // Add requests to be served in the current direction
            if (!upper.isEmpty()) {
                farthestPosition = upper.get(upper.size() - 1); // Update the farthest position
            }
            movingUp = false; // Change the direction
            Collections.reverse(lower); // Reverse the lower list for serving in the opposite direction
            result.addAll(lower); // Add requests to be served in the opposite direction
            if (!lower.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, lower.get(0)); // Update the farthest position
            }
        } else {
            Collections.reverse(lower); // Reverse the lower list for serving in the current direction
            result.addAll(lower); // Add requests to be served in the current direction
            if (!lower.isEmpty()) {
                farthestPosition = lower.get(0); // Update the farthest position
            }
            movingUp = true; // Change the direction
            result.addAll(upper); // Add requests to be served in the new direction
            if (!upper.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, upper.get(upper.size() - 1)); // Update the farthest position
            }
        }

        return result;
    }

    // Main method to run the elevator simulation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int maxTrack = scanner.nextInt(); // Read the maximum track number
        int startPosition = scanner.nextInt(); // Read the starting position
        boolean movingUp = scanner.nextInt() == 1; // Read the initial direction
        int numRequests = scanner.nextInt(); // Read the number of requests
        List<Integer> requests = new ArrayList<>();
        for (int i = 0; i < numRequests; i++) {
            requests.add(scanner.nextInt()); // Read each request
        }
        Main scheduler = new Main(startPosition, movingUp, maxTrack);
        List<Integer> result = scheduler.execute(requests);
        for (int r : result) {
            System.out.print(r + " "); // Print the result
        }
        scanner.close();
    }
}