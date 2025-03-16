
import java.util.ArrayList;
import java.util.Scanner;
class AdjacencyListGraph<E extends Comparable<E>> {
    ArrayList<Vertex> vertices;
    AdjacencyListGraph() {
        vertices = new ArrayList<>();
    }
    private class Vertex {
        E data;
        ArrayList<Vertex> adjacentVertices;
        Vertex(E data) {
            adjacentVertices = new ArrayList<>();
            this.data = data;
        }
        public boolean addAdjacentVertex(Vertex to) {
            for (Vertex v : adjacentVertices) {
                if (v.data.compareTo(to.data) == 0) {
                    return false; 
                }
            }
            return adjacentVertices.add(to); 
        }
        public boolean removeAdjacentVertex(E to) {
            for (int i = 0; i < adjacentVertices.size(); i++) {
                if (adjacentVertices.get(i).data.compareTo(to) == 0) {
                    adjacentVertices.remove(i);
                    return true;
                }
            }
            return false;
        }
    }
    public boolean removeEdge(E from, E to) {
        Vertex fromV = null;
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) {
                fromV = v;
                break;
            }
        }
        if (fromV == null) {
            return false;
        }
        return fromV.removeAdjacentVertex(to);
    }
    public boolean addEdge(E from, E to) {
        Vertex fromV = null;
        Vertex toV = null;
        for (Vertex v : vertices) {
            if (from.compareTo(v.data) == 0) { 
                fromV = v;
            } else if (to.compareTo(v.data) == 0) { 
                toV = v;
            }
            if (fromV != null && toV != null) {
                break; 
            }
        }
        if (fromV == null) {
            fromV = new Vertex(from);
            vertices.add(fromV);
        }
        if (toV == null) {
            toV = new Vertex(to);
            vertices.add(toV);
        }
        return fromV.addAdjacentVertex(toV);
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Vertex v : vertices) {
            sb.append("Vertex: ");
            sb.append(v.data);
            sb.append("\n");
            sb.append("Adjacent vertices: ");
            for (Vertex v2 : v.adjacentVertices) {
                sb.append(v2.data);
                sb.append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
public final class Graphs {
    private Graphs() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AdjacencyListGraph<Integer> graph = new AdjacencyListGraph<>();
        int edgeCount = scanner.nextInt();
        for (int i = 0; i < edgeCount; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            graph.addEdge(from, to);
        }
        System.out.println("Graph Representation:");
        System.out.println(graph);
        scanner.close();
    }
}
