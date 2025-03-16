import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Maximum track limit
    private final int maxTrack;
    // Current position of the elevator
    private final int currentPosition;
    // Direction of movement: true for up, false for down
    private boolean movingUp;
    // Farthest position reached during the execution
    private int farthestPosition;

    // Constructor to initialize the elevator's starting position, direction, and track limit
    public Main(int startPosition, boolean initialDirection, int maxTrack) {
        this.currentPosition = startPosition;
        this.movingUp = initialDirection;
        this.maxTrack = maxTrack;
    }

    // Method to execute the elevator requests and return the order of service
    public List<Integer> execute(List<Integer> requests) {
        // List to store the result of the order of service
        List<Integer> result = new ArrayList<>();
        // Lists to hold requests below and above the current position
        List<Integer> lower = new ArrayList<>();
        List<Integer> upper = new ArrayList<>();

        // Separate requests into lower and upper based on the current position
        for (int request : requests) {
            if (request >= 0 && request < maxTrack) { // Validate request within track limits
                if (request < currentPosition) {
                    lower.add(request); // Add to lower if below current position
                } else {
                    upper.add(request); // Add to upper if above or at current position
                }
            }
        }

        // Sort the lower and upper requests
        Collections.sort(lower);
        Collections.sort(upper);

        // Process requests based on the current direction of movement
        if (movingUp) {
            // If moving up, serve all upper requests first
            result.addAll(upper);
            if (!upper.isEmpty()) {
                farthestPosition = upper.get(upper.size() - 1); // Update farthest position
            }
            movingUp = false; // Change direction to down
            Collections.reverse(lower); // Reverse lower requests to serve them in descending order
            result.addAll(lower);
            if (!lower.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, lower.get(0)); // Update farthest position
            }
        } else {
            // If moving down, serve all lower requests first
            Collections.reverse(lower); // Reverse lower requests to serve them in descending order
            result.addAll(lower);
            if (!lower.isEmpty()) {
                farthestPosition = lower.get(0); // Update farthest position
            }
            movingUp = true; // Change direction to up
            result.addAll(upper); // Serve upper requests next
            if (!upper.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, upper.get(upper.size() - 1)); // Update farthest position
            }
        }
        return result; // Return the order of service
    }

    // Main method to run the elevator simulation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read maximum track limit, starting position, initial direction, and number of requests
        int maxTrack = scanner.nextInt();
        int startPosition = scanner.nextInt();
        boolean movingUp = scanner.nextInt() == 1; // Convert input to boolean
        int numRequests = scanner.nextInt();
        
        // Read the requests into a list
        List<Integer> requests = new ArrayList<>();
        for (int i = 0; i < numRequests; i++) {
            requests.add(scanner.nextInt());
        }
        
        // Create an instance of the Main class (elevator scheduler)
        Main scheduler = new Main(startPosition, movingUp, maxTrack);
        
        // Execute the requests and get the result
        List<Integer> result = scheduler.execute(requests);
        
        // Print the result of the order of service
        for (int r : result) {
            System.out.print(r + " ");
        }
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }
}
