import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextInt()){
      int N = sc.nextInt();
      if(N==0) break;

      Map<Integer,List<Integer>> log = new HashMap<Integer,List<Integer>>();
      for(int i=0;i<N;i++){
	int month,day,hour,min,id;
	String action;
	month = sc.nextInt();
	day = sc.nextInt();
	hour = sc.nextInt();
	min = sc.nextInt();
	action = sc.next();
	id = sc.nextInt();

	int t = month*24*60 + day*24*60 + hour*60 + min;
	if(!log.containsKey(id)){
	  log.put(id,new ArrayList<Integer>());
	}
	log.get(id).add(t);
	if(action.equals("enter")) log.get(id).add(t);
      }

      int[] total = new int[1000];
      Arrays.fill(total,0);

      for(int i=0;i+1<log.get(0).size();i+=2){
	int god_start = log.get(0).get(i);
	int god_end = log.get(0).get(i+1);

	for(Map.Entry<Integer,List<Integer>> entry : log.entrySet()){
	  int id = entry.getKey();
	  if(id==0) continue;
	  List<Integer> schedule = entry.getValue();
	  for(int j=0;j<schedule.size();j+=2){
	    int ppl_start = schedule.get(j);
	    int ppl_end = schedule.get(j+1);
	    int start = Math.max(god_start,ppl_start);
	    int end = Math.min(god_end,ppl_end);
	    total[id] += Math.max(0,end-start);
	  }
	}
      }

      int max_v = 0;
      for(int id=0;id<1000;id++){
	max_v = Math.max(total[id],max_v);
      }
      System.out.println(max_v);
    }
  }
}

