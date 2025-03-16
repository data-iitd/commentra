import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];
            int L = scanner.nextInt();
            an[0] = scanner.nextInt();
            if (L == 0) break;

            int aj = an[0];
            boolean end = false;

            for (int k = 1; k < 21; k++) {
                for (int i = L - 1; i >= 0; i--, aj /= 10) {
                    a1[i] = aj % 10;
                    a2[i] = aj % 10;
                }

                for (int i = 1; i < L; i++) {
                    for (int j = 1; j < L; j++) {
                        if (a1[j - 1] < a1[j]) {
                            int tmp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = tmp;
                        }
                        if (a2[j - 1] > a2[j]) {
                            int tmp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = tmp;
                        }
                    }
                }

                int def = 0;
                int max = 0;
                int min = 0;
                int d = 1;

                for (int i = L - 1; i >= 0; i--, d *= 10) {
                    max += (a1[i] % 10) * d;
                    min += (a2[i] % 10) * d;
                }
                def = max - min;

                for (int i = 0; i < k; i++) {
                    if (def == an[i]) {
                        System.out.printf("%d %d %d\n", i, def, k - i);
                        end = true;
                        break;
                    }
                }
                if (end) break;
                an[k] = def;
                aj = def;
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
