
import java.util.*;
import java.io.*;

class s660035552{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] str = br.readLine().split(" ");
    int n = Integer.parseInt(str[0]);
    int m = Integer.parseInt(str[1]);
    int[] a = new int[m];
    int[] b = new int[m];
    int[] low = new int[m];
    int[] high = new int[m];
    int sp = 0;
    int cnt = 0;
    int i,j,x,t;

    for(i = 0;i < m;i++){
      str = br.readLine().split(" ");
      a[i] = Integer.parseInt(str[0]);
      b[i] = Integer.parseInt(str[1]);
    }

    low[sp] = 0;
    high[sp] = m - 1;
    sp++;

    while(sp > 0){
      sp--;
      i = low[sp];
      j = high[sp];

      if(i >= j);

      else {
        x = b[j];
        t = i;
        while(i < j){
          while(b[++i] < x);
          while(i < --j && x < b[j]);
          if(i >= j) break;
          int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
          tmp = b[i]; b[i] = b[j]; b[j] = tmp;
        }
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        tmp = b[i]; b[i] = b[j]; b[j] = tmp;

        if(i - t < j - i){
          low[sp] = i + 1;
          high[sp++] = j;
          low[sp] = t;
          high[sp++] = i - 1;
        }

        else{
          low[sp] = t;
          high[sp++] = i - 1;
          low[sp] = i + 1;
          high[sp++] = j;
        }
      }
    }

    t = 0;
    for(i = 0;i < m;i++){
      if(t <= a[i]){
        t = b[i];
        cnt++;
      }
    }

    System.out.println(cnt);
  }
}
