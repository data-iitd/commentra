

import java.util.Scanner;

public class codeforces_7_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int m = scanner.nextInt();
        int[] memory = new int[m];
        int id = 1;
        for (int i = 0; i < t; i++) {
            String[] operation = scanner.next().split(" ");
            if (operation[0].equals("alloc")) {
                int size = Integer.parseInt(operation[1]);
                int start = 0;
                while (start < m) {
                    if (memory[start] == 0) {
                        boolean flag = true;
                        for (int j = start + 1; j < start + size; j++) {
                            if (memory[j]!= 0) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            for (int j = start; j < start + size; j++) {
                                memory[j] = id;
                            }
                            System.out.println(id);
                            id++;
                            break;
                        }
                    }
                    start++;
                }
                if (start == m) {
                    System.out.println("NULL");
                }
            } else if (operation[0].equals("erase")) {
                int idToErase = Integer.parseInt(operation[1]);
                boolean flag = false;
                for (int j = 0; j < m; j++) {
                    if (memory[j] == idToErase) {
                        memory[j] = 0;
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    System.out.println("ILLEGAL_ERASE_ARGUMENT");
                }
            } else if (operation[0].equals("defragment")) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (memory[j] == 0) {
                        cnt++;
                    }
                }
                int[] newMemory = new int[m - cnt];
                int index = 0;
                for (int j = 0; j < m; j++) {
                    if (memory[j]!= 0) {
                        newMemory[index++] = memory[j];
                    }
                }
                for (int j = 0; j < cnt; j++) {
                    newMemory[index++] = 0;
                }
                memory = newMemory;
            }
        }
    }
}
