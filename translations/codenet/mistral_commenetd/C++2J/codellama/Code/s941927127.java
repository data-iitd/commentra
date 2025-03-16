
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String W = sc.next();
        char[] W_array = W.toCharArray();
        java.util.Arrays.sort(W_array);
        for (int i = 0; i < W_array.length - 1; i++) {
            if (W_array[i] != W_array[i + 1]) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}

