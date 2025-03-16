import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the height (H) and width (W) of the grid
        int H = sc.nextInt(); 
        int W = sc.nextInt(); 
        
        // Initialize a 2D character array to store the grid
        char[][] A = new char[H][W]; 
        
        // Initialize a queue to perform BFS (Breadth-First Search)
        Queue<int[]> queue = new ArrayDeque<int[]>(); 
        
        // Read the grid input and populate the character array
        for (int i = 0; i < H; i++) { 
            String row = sc.next(); 
            for (int j = 0; j < W; j++) { 
                A[i][j] = row.charAt(j); 
                
                // If the current cell is a wall ('#'), add its position to the queue
                if (A[i][j] == '#') { 
                    int[] start = {i, j, 0}; // Store the position and initial depth
                    queue.add(start); // Add the starting position to the queue
                } 
            } 
        } 
        
        // Initialize a flag array to track visited cells
        int[][] flag = new int[H][W]; 
        
        // Variable to store the maximum depth reached
        int ans = 0; 
        
        // Direction vectors for moving up, down, left, and right
        int[] dx = {1, -1, 0, 0}; 
        int[] dy = {0, 0, 1, -1}; 
        
        // Perform BFS until the queue is empty
        loop: while (!queue.isEmpty()) { 
            int[] temp = queue.remove(); // Remove the front element from the queue
            int y = temp[0]; // Current y-coordinate
            int x = temp[1]; // Current x-coordinate
            int depth = temp[2]; // Current depth
            
            // Explore all four possible directions
            for (int i = 0; i < 4; i++) { 
                // Calculate new coordinates
                int newY = y + dy[i];
                int newX = x + dx[i];
                
                // Check if the new coordinates are within bounds
                if (0 <= newY && newY <= H - 1 && 0 <= newX && newX <= W - 1) { 
                    // Check if the cell has not been visited and is an empty space ('.')
                    if (flag[newY][newX] == 0 && A[newY][newX] == '.') { 
                        flag[newY][newX] = 1; // Mark the cell as visited
                        int[] queue_add = {newY, newX, depth + 1}; // Prepare the new position and updated depth
                        queue.add(queue_add); // Add the new position to the queue
                        ans = depth + 1; // Update the maximum depth reached
                    } 
                } 
            } 
        } 
        
        // Output the maximum depth reached
        System.out.println(ans); 
    } 
}
