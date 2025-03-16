import java.util.*;
public class Main{
  public static void main(String[] args){
    int n, l[] = new int[2001], i, j, k, cnt=0, tmp=0;
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    for(i=0; i<n; i++){
      l[i] = sc.nextInt();
    }
    for(i=0; i<n-1; i++){
      for(j=i+1; j<n; j++){
        if(l[j]<l[i]){
          tmp = l[i];
          l[i] = l[j];
          l[j] = tmp;
        }
      }
    }
    for(i=0; i<n-2; i++){
      for(j=i+1; j<n-1; j++){
        for(k=j+1; k<n; k++){
          if(l[i]+l[j]>l[k]){
            cnt++;
          }
          else{
            break;
          }
        }
      }
    }
    System.out.println(cnt);
  }
}
