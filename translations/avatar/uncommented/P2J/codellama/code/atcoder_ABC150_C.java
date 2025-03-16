import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<List<Integer>> orig = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            List<Integer> temp = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                temp.add(j);
            }
            orig.add(temp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (orig.get(j).get(i) > orig.get(j + 1).get(i)) {
                    List<Integer> temp = orig.get(j);
                    orig.set(j, orig.get(j + 1));
                    orig.set(j + 1, temp);
                }
            }
        }
        int pn = 0;
        int qn = 0;
        for (int i = 0; i < n; i++) {
            if (orig.get(i).equals(Arrays.asList(1, 2, 3, 4, 5))) {
                pn = i;
            }
            if (orig.get(i).equals(Arrays.asList(5, 4, 3, 2, 1))) {
                qn = i;
            }
        }
        System.out.println(Math.abs(pn - qn));
    }
}

