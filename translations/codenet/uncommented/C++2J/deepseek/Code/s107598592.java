import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Integer> X = new ArrayList<>();
        List<Integer> Y = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            X.add(scanner.nextInt());
            Y.add(X.get(i));
        }
        
        Collections.sort(Y);
        
        int y = Y.get(N / 2);
        for (int i = 0; i < N; i++) {
            if (X.get(i) < Y.get(N / 2)) {
                System.out.println(Y.get(N / 2));
            } else {
                System.out.println(Y.get(N / 2 - 1));
            }
            System.out.println();
        }
    }
}
