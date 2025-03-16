
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int m = sc.nextInt();
        int[] alocuente = new int[m];
        int ind = 1;
        for (int i = 0; i < t; i++) {
            String[] op = sc.nextLine().split(" ");
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
                if (pos == 0) {
                    System.out.println("NULL");
                }
            }
            if (op[0].equals("erase")) {
                int pos = 0;
                if (!(Integer.parseInt(op[1]) > 0 && alocuente[Integer.parseInt(op[1]) - 1] == Integer.parseInt(op[1]))) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                } else {
                    for (int j = Integer.parseInt(op[1]) - 1; j < m; j++) {
                        if (alocuente[j] == Integer.parseInt(op[1])) {
                            alocuente[j] = 0;
                            break;
                        }
                    }
                }
            }
            if (op[0].equals("defragment")) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++;
                    }
                }
                alocuente = new int[m - cnt];
                for (int j = 0; j < m - cnt; j++) {
                    if (alocuente[j] != 0) {
                        alocuente[j] = j + 1;
                    }
                }
                for (int j = m - cnt; j < m; j++) {
                    alocuente[j] = 0;
                }
            }
        }
    }
}

