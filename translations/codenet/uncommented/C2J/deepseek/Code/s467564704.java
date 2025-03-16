public class Main {
    public static void main(String[] args) {
        int[][] input = new int[4][4];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                input[i][j] = scanner.nextInt();
            }
        }
        
        int tc = scanner.nextInt();
        for (int i = 0; i < tc; i++) {
            int testcase = scanner.nextInt();
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (input[j][k] == testcase) {
                        input[j][k] = 0;
                    }
                }
            }
        }
        
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
