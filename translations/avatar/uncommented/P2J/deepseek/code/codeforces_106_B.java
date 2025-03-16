import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<int[]> inputArray = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int S = scanner.nextInt();
            int R = scanner.nextInt();
            int H = scanner.nextInt();
            int C = scanner.nextInt();
            inputArray.add(new int[]{S, R, H, C});
        }
        
        Set<int[]> outdated = new HashSet<>();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (inputArray.get(i)[0] < inputArray.get(j)[0] &&
                    inputArray.get(i)[1] < inputArray.get(j)[1] &&
                    inputArray.get(i)[2] < inputArray.get(j)[2]) {
                    outdated.add(inputArray.get(i));
                }
            }
        }
        
        int minimumCost = Integer.MAX_VALUE;
        int inputNumber = 0;
        
        for (int i = 0; i < n; i++) {
            int[] currentItem = inputArray.get(i);
            int cost = currentItem[3];
            if (!outdated.contains(currentItem) && cost < minimumCost) {
                minimumCost = cost;
                inputNumber = i + 1;
            }
        }
        
        System.out.println(inputNumber);
    }
}
