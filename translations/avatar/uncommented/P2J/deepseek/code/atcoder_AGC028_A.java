import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        String S = scanner.nextLine();
        String T = scanner.nextLine();

        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        ArrayList<Integer> Number_iMN = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            Number_iMN.add(i * M / N);
        }

        HashSet<Integer> Number_j = new HashSet<>();
        for (int j = 0; j < M; j++) {
            Number_j.add(j);
        }

        HashSet<Integer> Kaburi_j = new HashSet<>(Number_iMN);
        Kaburi_j.retainAll(Number_j);

        ArrayList<Integer> Kaburi_i = new ArrayList<>();
        for (int j : Kaburi_j) {
            Kaburi_i.add(j * N / M);
        }

        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size();

        while (counter <= Kaburi_Size - 1) {
            if (list_S[Kaburi_i.get(counter)] != list_T[counter]) {
                Flag = 1;
                break;
            }
            counter++;
        }

        if (Flag == 1) {
            System.out.println(-1);
        } else {
            int gcd = gcd(N, M);
            System.out.println(N * M / gcd);
        }
    }

    public static int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
