
import java.io.*;
import java.util.*;

class s814403222{
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while((line = br.readLine())!= null){
      int n = Integer.parseInt(line);
      if(n == 0) break;
      int m;
      int[][] v = new int[n][2];
      List<List<Integer>> d = new ArrayList<List<Integer>>();
      for(int i = 0; i < 33; i++){
        d.add(new ArrayList<Integer>());
      }
      for(int i = 0; i < n; i++){
        v[i][0] = 0;
        String[] str = br.readLine().split(" ");
        v[i][1] = Integer.parseInt(str[0]);
        m = Integer.parseInt(str[1]);
        for(int j = 0; j < m; j++){
          int a = Integer.parseInt(br.readLine());
          v[i][0] += n - d.get(a).size();
          for(int k = 0; k < d.get(a).size(); k++){
            v[d.get(a).get(k)][0]--;
          }
          d.get(a).add(i);
        }
      }
      Arrays.sort(v, new Comparator<int[]>(){
        public int compare(int[] a, int[] b){
          return a[0] - b[0];
        }
      });
      System.out.println(v[0][0] + " " + v[0][1]);
    }
  }
}
