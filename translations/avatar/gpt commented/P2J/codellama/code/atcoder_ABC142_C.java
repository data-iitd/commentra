import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Integer> A = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            A.add(sc.nextInt());
        }
        Collections.sort(A, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });
        for (int i = 0; i < N - 1; i++) {
            System.out.print(i + 1 + " ");
        }
        System.out.print(N);
        sc.close();
    }
}

