
import java.util.Scanner;

public class codeforces_7_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int m = scanner.nextInt();
        int[] alocuente = new int[m];
        int ind = 1;

        for (int i = 0; i < t; i++) {
            String op = scanner.next();
            if (op.equals("alloc")) {
                int pos = 0;
                int size = scanner.nextInt();
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        pos++;
                        if (pos == size) {
                            for (int k = j - size + 1; k <= j; k++) {
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
                if (pos!= size) {
                    System.out.println("NULL");
                }
            } else if (op.equals("erase")) {
                int id = scanner.nextInt();
                boolean found = false;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == id) {
                        alocuente[j] = 0;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }
            } else if (op.equals("defragment")) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++;
                    }
                }
                int[] newAlocuente = new int[m - cnt];
                int index = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j]!= 0) {
                        newAlocuente[index] = alocuente[j];
                        index++;
                    }
                }
                for (int j = 0; j < cnt; j++) {
                    newAlocuente[index] = 0;
                    index++;
                }
                alocuente = newAlocuente;
            }
        }
    }
}
