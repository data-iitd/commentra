import java.util.*; // Importing the utility classes

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Step 1: Initialize the Scanner object to read input
        int H = sc.nextInt(); // Reading the height of the grid
        int W = sc.nextInt(); // Reading the width of the grid
        
        char[][] A = new char[H][W]; // Step 2: Initialize the grid A
        Queue<int[]> queue = new ArrayDeque<>(); // Initialize the queue for BFS
        
        // Step 3: Read the grid row by row and initialize the queue with positions of '#' characters
        for (int i = 0; i < H; i++) {
            String row = sc.next(); // Reading the next line which represents a row in the grid
            for (int j = 0; j < W; j++) {
                A[i][j] = row.charAt(j); // Storing the character in the grid
                if (A[i][j] == '#') { // If the character is '#'
                    int[] start = {i, j, 0}; // Create a starting point array
                    queue.add(start); // Add the starting point to the queue
                }
            }
        }
        
        // Step 4: Initialize a flag array to keep track of visited cells
        int[][] flag = new int[H][W];
        int ans = 0; // Variable to store the maximum distance
        
        // Directions for moving in the grid (right, left, down, up)
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        
        // Step 5: Perform BFS to find the maximum distance from any '#' to a '.'
        while (!queue.isEmpty()) {
            int[] temp = queue.remove(); // Remove the first element from the queue
            int y = temp[0]; // Current y-coordinate
            int x = temp[1]; // Current x-coordinate
            int depth = temp[2]; // Current depth of the BFS
            
            // Check all four possible directions
            for (int i = 0; i < 4; i++) {
                if (0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1) {
                    if (flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.') {
                        flag[y + dy[i]][x + dx[i]] = 1; // Mark the cell as visited
                        int[] queue_add = {y + dy[i], x + dx[i], depth + 1}; // Create a new position to add to the queue
                        queue.add(queue_add); // Add the new position to the queue
                        ans = depth + 1; // Update the maximum distance
                    }
                }
            }
        }
        
        // Step 6: Output the maximum distance found
        System.out.println(ans);
    }
}
