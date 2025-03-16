
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int sa = sc.nextInt();
        int sk = sc.nextInt();
        int[] ans = new int[n];
        for (int i = 0; i < k; i++) {
            ans[i] = sk + 1;
        }
        for (int i = k; i < n; i++) {
            ans[i] = sa - sk + 1;
        }
        System.out.println(Arrays.stream(ans).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
    }
}

