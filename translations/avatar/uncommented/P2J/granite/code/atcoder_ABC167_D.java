
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] L = new int[N+1];
		for(int i = 1; i <= N; i++) {
		    L[i] = sc.nextInt();
		}
		int[] path = new int[N+1];
		int ind = 0;
		int count = 0;
		int x = 1;
		int t = -1;
		boolean flag = false;
		HashMap<Integer, Integer> Hash = new HashMap<>();
		for(int i = 0; i <= N; i++) {
		    int ne = L[x];
		    if(Hash.containsKey(ne)) {
		        flag = true;
		        t = Hash.get(ne);
		        break;
		    }
		    path[ind+1] = ne;
		    ind++;
		    Hash.put(ne, ind);
		    x = ne;
		}
		if(flag) {
		    int[] loop = Arrays.copyOfRange(path, t, path.length);
		    if(K < path.length) {
		        System.out.println(path[K]);
		    } else {
		        K = K - path.length;
		        K = K % loop.length;
		        System.out.println(loop[K]);
		    }
		} else {
		    System.out.println(path[K-1]);
		}
	}
}

Translate the above Python code to C++ and end with comment "