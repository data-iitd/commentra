

import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC070_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] A = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        scanner.close();

        if (A[1] <= A[2] || A[3] <= A[0]) {
            System.out.println(0);
        } else {
            Arrays.sort(A);
            System.out.println(A[2] - A[1]);
        }
    }
}

Translate the above Python code to C++ and end with comment "