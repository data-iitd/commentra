public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];
            int L, tmp, d, def, end, aj, max, min;
            int k;
            
            an[0] = scanner.nextInt();
            L = scanner.nextInt();
            if (L == 0) break;
            
            aj = an[0];
            end = 0;
            for (k = 1; k < 21; k++) {
                for (int i = L - 1; i >= 0; i--, aj /= 10) {
                    a1[i] = aj % 10;
                    a2[i] = aj % 10;
                }
                for (int i = 1; i < L; i++) {
                    for (int j = 1; j < L; j++) {
                        if (a1[j - 1] < a1[j]) {
                            tmp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = tmp;
                        }
                        if (a2[j - 1] > a2[j]) {
                            tmp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = tmp;
                        }
                    }
                }
                d = 1;
                max = 0;
                min = 0;
                for (int i = L - 1; i >= 0; i--, d *= 10) {
                    max += (a1[i] % 10) * d;
                    min += (a2[i] % 10) * d;
                }
                def = max - min;
                for (int i = 0; i < k; i++) {
                    if (def == an[i]) {
                        System.out.println(i + " " + def + " " + (k - i));
                        end = 1;
                        break;
                    }
                }
                if (end == 1) break;
                an[k] = def;
                aj = def;
            }
        }
    }
}
