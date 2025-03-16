import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] input_array = new int[n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                input_array[i][j] = sc.nextInt();
            }
        }
        int minimum_cost = 100000;
        int input_number = 0;
        for (int i = 0; i < n; i++) {
            int[] current_item = input_array[i];
            int cost = current_item[3];
            if (cost < minimum_cost) {
                minimum_cost = cost;
                input_number = i + 1;
            }
        }
        System.out.println(input_number);
    }
}
