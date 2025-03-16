import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, a, b, x = 10, y = 10;
        boolean[][] fld = new boolean[21][21];
        while(~(n = sc.nextInt())) {
            // Clear the grid
            for(int i = 0; i < 21; i++)
                for(int j = 0; j < 21; j++)
                    fld[i][j] = false;
            // Read the positions of items and mark them in the grid
            while(n--) {
                a = sc.nextInt();
                b = sc.nextInt();
                fld[b][a] = true;
            }
            // Read the number of movements
            m = sc.nextInt();
            // Perform the movements
            while(m--) {
                char buf = sc.next().charAt(0);
                a = sc.nextInt();
                // Determine the direction and convert it to an index
                int d = buf == 'N'? 0 : buf == 'E'? 1 : buf == 'S'? 2 : 3;
                // Move the robot and collect items
                while(a-- > 0) {
                    // Update the robot's position based on the direction
                    d % 2? ~-d? x-- : x++ : d? y-- : y++;
                    // Check if the robot collects an item
                    if(fld[y][x]) {
                        fld[y][x] = false;
                        n--;
                    }
                }
            }
            // Output the result
            System.out.println(n == 0? "Yes" : "No");
        }
    }
}

