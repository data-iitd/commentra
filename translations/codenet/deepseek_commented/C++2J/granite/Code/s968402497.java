
```java
import java.util.*;
import java.io.*;

public class s968402497{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int tc = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        int m = Integer.parseInt(input[2]);
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        boolean flag = false;
        for (int i = 1; i <= m; i++) {
            if (i * tc >= n && i * tc <= m) {
                System.out.println("OK");
                flag = true;
                break;
            }
        }
        if (!flag) {
            System.out.println("NG");
        }
    }
}
```

