public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;

            int[] sq = new int[10000];
            int[] fr = new int[5000];
            java.util.List<Integer> com = new java.util.ArrayList<>();
            int tmp;

            for (int i = 1; i < n; i++) {
                sq[i] = (i * i) % n;
            }
            com.clear();

            for (int i = 1; i < n; i++) {
                boolean f = true;
                for (int j = 0; j < com.size(); j++) {
                    if (com.get(j) == sq[i]) {
                        f = false;
                        break;
                    }
                }
                if (f) com.add(sq[i]);
            }

            for (int i = 0; i <= (n - 1) / 2; i++) {
                fr[i] = 0;
            }

            for (int i = 0; i < com.size(); i++) {
                for (int j = 0; j < com.size(); j++) {
                    if (i != j) {
                        tmp = com.get(i) - com.get(j);
                        if (tmp < 0) tmp += n;
                        if (tmp > (n - 1) / 2) tmp = n - tmp;
                        fr[tmp]++;
                    }
                }
            }

            for (int i = 1; i <= (n - 1) / 2; i++) {
                System.out.println(fr[i]);
            }
        }
