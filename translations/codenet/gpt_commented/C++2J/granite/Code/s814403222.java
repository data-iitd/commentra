
import java.util.*;

public class s814403222{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()) {
            int n = sc.nextInt();

            if(n == 0) break;

            int m;
            int[] score = new int[n];
            String[] name = new String[n];
            List<Integer>[] list = new ArrayList[33];

            for(int i = 0; i < 33; i++) {
                list[i] = new ArrayList<>();
            }

            for(int i = 0; i < n; i++) {
                name[i] = sc.next();
                m = sc.nextInt();

                for(int j = 0; j < m; j++) {
                    int a = sc.nextInt();
                    score[i] += n - list[a].size();

                    for(int k = 0; k < list[a].size(); k++) {
                        score[list[a].get(k)]--;
                    }

                    list[a].add(i);
                }
            }

            int max = 0;
            int maxIndex = 0;

            for(int i = 0; i < n; i++) {
                if(max < score[i]) {
                    max = score[i];
                    maxIndex = i;
                }
            }

            System.out.println(score[maxIndex] + " " + name[maxIndex]);
        }
    }
}
