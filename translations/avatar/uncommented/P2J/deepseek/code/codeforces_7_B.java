import java.util.Scanner;

public class MemoryAllocation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t, m;
        t = scanner.nextInt();
        m = scanner.nextInt();
        int[] alocuente = new int[m];
        int ind = 1;

        for (int i = 0; i < t; i++) {
            String[] op = scanner.next().split("");
            if (op[0].equals("alloc")) {
                int pos = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        pos++;
                        if (pos == Integer.parseInt(op[1])) {
                            for (int k = j - Integer.parseInt(op[1]) + 1; k <= j; k++) {
                                alocuente[k] = ind;
                            }
                            System.out.println(ind);
                            ind++;
                            break;
                        }
                    } else {
                        pos = 0;
                    }
                }
                if (pos != Integer.parseInt(op[1])) {
                    System.out.println("NULL");
                }
            } else if (op[0].equals("erase")) {
                int pos = Integer.parseInt(op[1]);
                if (pos < 1 || pos > m || alocuente[pos - 1] == 0) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    alocuente[pos - 1] = 0;
                }
            } else if (op[0].equals("defragment")) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] != 0) {
                        alocuente[cnt++] = alocuente[j];
                    }
                }
                for (int j = cnt; j < m; j++) {
                    alocuente[j] = 0;
                }
            }
        }
    }
}
