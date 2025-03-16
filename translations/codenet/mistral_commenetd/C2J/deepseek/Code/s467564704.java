public class Main {
    public static void main(String[] args) {
        int[][] input = new int[4][4];
        int tc;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read the elements of the `input` array from the standard input.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = scanner.nextInt();
            }
        }
        
        // Read the number of test cases `tc` from the standard input.
        tc = scanner.nextInt();
        
        // Iterate through each test case and check if the given testcase is present in the `input` array or not.
        for (int i = 0; i < tc; i++) {
            int testcase = scanner.nextInt();
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (input[m][n] == testcase) {
                        input[m][n] = 0;
                    }
                }
            }
        }
        
        // Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
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
