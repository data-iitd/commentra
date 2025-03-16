public class Main {
    public static void main(String[] args) throws Exception {
        java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedWriter bw = new java.io.BufferedWriter(new java.io.OutputStreamWriter(System.out));

        if (args.length > 1) {
            br = new java.io.BufferedReader(new java.io.InputStreamReader(new java.io.FileInputStream(args[0])));
            if (args.length > 2) {
                bw = new java.io.BufferedWriter(new java.io.OutputStreamWriter(new java.io.FileOutputStream(args[1])));
            }
        }

        int n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");
        int[] ll = new int[n];

        for (int i = 0; i < n; i++) {
            ll[i] = Integer.parseInt(line[i]);
        }

        java.util.Arrays.sort(ll);

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                ans += l - (j + 1);
            }
        }
        bw.write(ans + "\n");
        bw.flush();
    }
}
