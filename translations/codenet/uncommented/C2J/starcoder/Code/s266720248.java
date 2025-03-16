
import java.util.*;

public class Main{
  public static void main(String[] args){
    int elaps = 0, c;
    int i, q;
    P u;

    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    q = sc.nextInt();

    for(i = 1 ; i <= n ; i++){
      sc.next();
      Q[i].t = sc.nextInt();
    }
    head = 1;
    tail = n + 1;

    while(head!= tail){
      u = dequeue();
      c = min(q,u.t);
      u.t -= c;
      elaps += c;
      if(u.t > 0) enqueue(u);
      else{
        System.out.println(u.name + " " + elaps);
      }
    }
  }

  static int min(int a, int b){
    return a < b? a : b;
  }

  static class P{
    String name;
    int t;
  }

  static P[] Q = new P[LEN];
  static int head, tail, n;

  static void enqueue(P x){
    Q[tail] = x;
    tail = (tail + 1) % LEN;
  }

  static P dequeue(){
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
  }
}

