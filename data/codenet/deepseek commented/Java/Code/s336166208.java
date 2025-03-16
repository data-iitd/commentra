
public class Main {
    public static void main(String[] args) {

        // Initialize a 3D array to store information about buildings, floors, and rooms
        int[][][] info = new int[4][3][10];
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) { info[i][j][k] = 0; }
            }
        }

        // Create a Scanner object to read input
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int n = sc.nextInt(); // Read the number of entries
        for (int i = 0; i < n; i ++) {
            int built = sc.nextInt();
            int floor = sc.nextInt();
            int room = sc.nextInt();
            int num = sc.nextInt();
            // Adjust the indices by -1 to fit the 0-based index of the array
            info[built - 1][floor - 1][room - 1] += num;
        }

        // Print the contents of the 3D array
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int k = 0; k < 10; k ++) {
                    System.out.print(" " + info[i][j][k]);
                }
                System.out.print("\n");
            }
            if (i != 4 - 1) { System.out.print("####################\n"); }
        }
    }
}