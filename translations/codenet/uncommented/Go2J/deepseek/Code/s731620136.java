public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        String S = scanner.next();

        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') nr++;
            else if (c == 'B') nb++;
            else if (c == 'G') ng++;
        }

        int same = 0;
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = a;
            int k = 2 * a;
            if (k >= N) break;
            while (k < N) {
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                }
                i++;
                j++;
                k++;
            }
        }

        int tot = nr * nb * ng;
        System.out.println(tot - same);
    }
}
