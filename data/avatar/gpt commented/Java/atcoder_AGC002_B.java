import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of boxes (N) and the number of moves (M)
        int N = sc.nextInt(); 
        int M = sc.nextInt(); 
        
        // Initialize an array of Box objects
        Box[] B = new Box[N]; 
        
        // Create the first box as red and the rest as not red
        B[0] = new Box(1, true); 
        for (int i = 1; i < N; i++) { 
            B[i] = new Box(1, false); 
        } 
        
        // Process M moves based on user input
        for (int i = 0; i < M; i++) { 
            // Read the indices of the boxes to move from and to
            int x = sc.nextInt() - 1; 
            int y = sc.nextInt() - 1; 
            // Move the contents from box x to box y
            B[x].moveTo(B[y]); 
        } 
        
        // Count the number of red boxes after all moves
        int counter = 0; 
        for (Box b : B) { 
            if (b.red) { 
                counter++; 
            } 
        } 
        
        // Output the count of red boxes
        System.out.println(counter); 
    } 
} 

// Box class representing a box with a number and a color state
class Box { 
    public int num; // Number of items in the box
    public boolean red; // Indicates if the box is red

    // Constructor to initialize the box with a number and color
    public Box(int n, boolean r) { 
        num = n; 
        red = r; 
    } 

    // Method to move items from this box to another box
    public void moveTo(Box other) { 
        // If this box is empty, do nothing
        if (num == 0) { 
            return; 
        } 
        // If this box has one item, transfer it to the other box
        else if (num == 1) { 
            num = 0; 
            other.num++; 
            // If this box is red, the other box becomes red
            if (red) { 
                other.red = true; 
            } 
            red = false; // This box is no longer red
        } 
        // If this box has more than one item, transfer one item to the other box
        else { 
            num--; 
            other.num++; 
            // If this box is red, the other box becomes red
            if (red) { 
                other.red = true; 
            } 
        } 
    } 
}
