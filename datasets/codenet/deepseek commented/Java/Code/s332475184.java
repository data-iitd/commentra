import java.util.*;
import java.io.*;

class Main{
    // Array to keep track of counts
    static int[] counter ;
    // Graph represented as an adjacency list
    static List<List<Integer>> graph;

    public static void main(String[] args){
        // FastScanner for efficient input reading
        FastScanner fs = new FastScanner();
        // Read number of nodes
        int n = fs.nextInt();
        // Read number of queries
        int q = fs.nextInt();
        // Initialize the graph as an adjacency list
        graph = new ArrayList<>();
        for(int i=0;i<n;i++) graph.add(new LinkedList<>());

        // Initialize the counter array
        counter = new int[n];
        Integer a,b;
        // Read edges and populate the graph
        for(int i=0;i<n-1;i++){
            a = fs.nextInt()-1;
            b = fs.nextInt()-1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        // Read queries and update the counter array
        for(int i=0;i<q;i++){
            counter[fs.nextInt()-1]+=fs.nextInt();
        }
        // Perform DFS to propagate counts through the graph
        dfs(0,-1,0);
        // Print the counter array as a space-separated string
        StringJoiner sj = new StringJoiner(" ");
        for(int i=0;i<n;i++){
            sj.add(String.valueOf(counter[i]));
        }
        System.out.println(sj.toString());
    }

    // Depth-first search to update the counter array
    static void dfs(int v, int par, long val){
        // Traverse all children of the current node
        for(Integer i: graph.get(v)){
            if(i != par){
                // Recursively call DFS for children
                dfs(i, v, val + counter[v]);
            }
        }
        // Update the counter for the current node
        counter[v] += val;
    }

    // FastScanner class for efficient input reading
    static class FastScanner{
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private boolean hasNextByte(){
            if(ptr < buflen){
                return true;
            }else{
                ptr = 0;
                try{
                    buflen = in.read(buffer);
                }catch(IOException e){
                    e.printStackTrace();
                }
                if(buflen <= 0){
                    return false;
                }
            }
            return true;
        }

        private int readByte(){
            if(hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private boolean isPrintableChar(int c){
            return 33 <= c && c <= 126;
        }

        public boolean hasNext(){
            while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        public String next(){
            if(!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)){
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong(){
            if(!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if(b == '-'){
                minus = true;
                b = readByte();
            }
            if(b < '0' || '9' < b){
                throw new NumberFormatException();
            }
            while(true){
                if('0' <= b && b <= '9'){
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        public int nextInt(){
            long nl = nextLong();
            if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int)nl;
        }

        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}
