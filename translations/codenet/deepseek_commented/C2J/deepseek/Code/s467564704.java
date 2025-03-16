public class TicTacToe {
    public static void main(String[] args) {
        // Declare a 3x3 matrix to store the input
        int[][] input = new int[3][3];
        
        // Read the 3x3 matrix from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = scanner.nextInt();
            }
        }
        
        // Read the number of test cases
        int tc = scanner.nextInt();
        
        // Loop through each test case
        for (int t = 0; t < tc; t++) {
            // Read the test case value
            int testcase = scanner.nextInt();
            
            // Loop through the matrix to zero out the corresponding elements
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (input[i][j] == testcase) {
                        input[i][j] = 0;
                    }
                }
            }
        }
        
        // Check for winning conditions for a Tic-Tac-Toe game
        if ((input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) ||
            (input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) ||
            (input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) ||
            (input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) ||
            (input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) ||
            (input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) ||
            (input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) ||
            (input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
