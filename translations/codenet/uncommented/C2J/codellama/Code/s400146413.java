
public class LinearSearch {

    public static int linearSearch(int[] S, int n, int key) {
        int i = 0;
        int count = 0;
        while (S[i] != key) {
            i++;
            if (i >= n) {
                count = 1;
                return count;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int i, j, n, q, S[] = new int[10000], T[] = new int[10000];
        int count = 0, key;

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (i = 0; i < n; i++) {
            S[i] = sc.nextInt();
        }

        q = sc.nextInt();
        for (j = 0; j < q; j++) {
            T[j] = sc.nextInt();
        }

        for (j = 0; j < q; j++) {
            key = T[j];
            if (linearSearch(S, n, key) == 0) {
                count++;
            }
        }

        System.out.println(count);
    }
}

