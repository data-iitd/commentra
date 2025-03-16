
import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class codeforces_106_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] inputArray = new int[n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                inputArray[i][j] = scanner.nextInt();
            }
        }
        Set<Integer[]> outdated = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (inputArray[i][0] < inputArray[j][0] &&
                    inputArray[i][1] < inputArray[j][1] &&
                    inputArray[i][2] < inputArray[j][2]) {
                    outdated.add(inputArray[i]);
                }
            }
        }
        int minCost = 100000;
        int inputNumber = 0;
        for (int i = 0; i < n; i++) {
            if (!outdated.contains(inputArray[i]) && inputArray[i][3] < minCost) {
                minCost = inputArray[i][3];
                inputNumber = i + 1;
            }
        }
        System.out.println(inputNumber);
    }
}
