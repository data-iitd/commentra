import java.util.Arrays;
import java.util.Scanner;

public class MemoryAllocator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int m = scanner.nextInt();
        int[] alocuente = new int[m];
        int ind = 1;
        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < t; i++) {
            String[] op = scanner.nextLine().split(" ");
            if (op[0].equals("alloc")) {
                int pos = 0;
                int size = Integer.parseInt(op[1]);
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        pos++;
                        if (pos == size) {
                            Arrays.fill(alocuente, j - size + 1, j + 1, ind);
                            System.out.println(ind);
                            ind++;
                            break;
                        }
                    } else {
                        pos = 0;
                    }
                }
                if (pos < size) {
                    System.out.println("NULL");
                }
            } else if (op[0].equals("erase")) {
                int eraseId = Integer.parseInt(op[1]);
                boolean found = false;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == eraseId) {
                        alocuente[j] = 0;
                        found = true;
                    }
                }
                if (!found && eraseId != 0) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }
            } else if (op[0].equals("defragment")) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] == 0) {
                        cnt++;
                    }
                }
                int[] newAlocuente = new int[m - cnt];
                int index = 0;
                for (int j = 0; j < m; j++) {
                    if (alocuente[j] != 0) {
                        newAlocuente[index++] = alocuente[j];
                    }
                }
                alocuente = new int[m];
                System.arraycopy(newAlocuente, 0, alocuente, 0, newAlocuente.length);
                // Fill the remaining part with zeros
                for (int j = newAlocuente.length; j < m; j++) {
                    alocuente[j] = 0;
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
