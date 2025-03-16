import java.util.*;
public class Main {
    public static void main(String[] args) {
        int[] li = new int[369];
        int ind = 0;
        for (int i = 1; i < 371; i++) {
            int[] temp = new int[10];
            int p = i, q = i;
            int count = 0;
            while (p!= 0) {
                p /= 10;
                count++;
            }
            if (count == 1) {
                li[ind++] = i;
            }
            if (count == 2) {
                while (q!= 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[ind++] = x;
                }
                for (int j = ind - 1; j >= 0; j--) {
                    li[ind++] = temp[j];
                }
            }
            if (count == 3) {
                while (q!= 0) {
                    int x = q % 10;
                    q /= 10;
                    temp[ind++] = x;
                }
                for (int j = ind - 1; j >= 0; j--) {
                    li[ind++] = temp[j];
                }
            }
        }
        li[ind - 2] = 0;
        li[ind - 1] = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(li[n - 1]);
    }
}
