
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] list = new int[n];
        for (int i = 0; i < n; i++) {
            list[i] = sc.nextInt() % 2;
        }
        if (sum(list) == 1) {
            System.out.println(indexOf(list, 1) + 1);
        } else {
            System.out.println(indexOf(list, 0) + 1);
        }
    }

    public static int sum(int[] list) {
        int sum = 0;
        for (int i = 0; i < list.length; i++) {
            sum += list[i];
        }
        return sum;
    }

    public static int indexOf(int[] list, int element) {
        for (int i = 0; i < list.length; i++) {
            if (list[i] == element) {
                return i;
            }
        }
        return -1;
    }
}

