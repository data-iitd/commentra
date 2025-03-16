
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking the number of nodes 'N' and the number of edges 'K' as input
        int N = sc.nextInt();
        int K = sc.nextInt();

        // Initializing the list 'L' with the given number of edges
        List<Integer> L = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            L.add(sc.nextInt());
        }

        // Adding a special node with index -1 at the beginning of the list 'L'
        L.add(0, -1);

        // Initializing an empty list 'path' to store the shortest path
        List<Integer> path = new ArrayList<>();
        path.add(1);

        // Initializing variables 'ind' and 'count'
        int ind = 0;
        int count = 0;

        // Initializing variables 'x' and 't'
        int x = 1;
        int t = -1;

        // Initializing a boolean variable 'flag'
        boolean flag = false;

        // Creating an empty hash table 'Hash'
        HashMap<Integer, Integer> Hash = new HashMap<>();

        // Traversing through all the nodes from 0 to 'N'
        for (int i = 0; i <= N; i++) {
            // Getting the next edge 'ne' from the current node 'x'
            int ne = L.get(x);

            // Checking if the current node 'ne' is already in the hash table 'Hash'
            if (Hash.containsKey(ne)) {
                // Setting the boolean variable 'flag' to True and storing the index of the previous occurrence of the node 'ne' in 't'
                flag = true;
                t = Hash.get(ne);
                break;
            }

            // Appending the next edge 'ne' to the list 'path'
            path.add(ne);

            // Incrementing the index 'ind' and storing it in the hash table 'Hash' with the key as the current node 'ne' and value as 'ind'
            ind++;
            Hash.put(ne, ind);

            // Updating the current node 'x' to the next node 'ne'
            x = ne;
        }

        // Checking if there is a cycle in the graph
        if (flag == true) {
            // Storing the list of nodes in the cycle 'loop'
            List<Integer> loop = path.subList(t, path.size());

            // Checking if the length of the path is less than 'K'
            if (path.size() < K) {
                // Printing the 'K'th node in the path
                System.out.println(path.get(K));
            }

            // If the length of the path is greater than or equal to 'K', then we need to find the 'K'th node in the cycle 'loop'
            else {
                // Updating the value of 'K' by subtracting the length of the path and taking the modulo with the length of the cycle 'loop'
                K = K - path.size();
                K = K % loop.size();

                // Printing the 'K'th node in the cycle 'loop'
                System.out.println(loop.get(K));
        }

        // If there is no cycle in the graph, then we simply print the 'K'th node in the path
        else {
            // Printing the 'K'th node in the path
            System.out.println(path.get(K - 1));
        }
    }
}

