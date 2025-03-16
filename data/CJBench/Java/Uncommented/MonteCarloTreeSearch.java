
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.Scanner;
public class MonteCarloTreeSearch {
    public class Node {
        Node parent;
        ArrayList<Node> childNodes;
        boolean isPlayersTurn; 
        boolean playerWon; 
        int score;
        int visitCount;
        public Node(Node parent, boolean isPlayersTurn) {
            this.parent = parent;
            this.childNodes = new ArrayList<>();
            this.isPlayersTurn = isPlayersTurn;
            this.playerWon = false;
            this.score = 0;
            this.visitCount = 0;
        }
    }
    static final int WIN_SCORE = 10;
    static final int TIME_LIMIT = 500; 
    public Node monteCarloTreeSearch(Node rootNode, int childCount) {
        Node winnerNode;
        double timeLimit;
        addChildNodes(rootNode, childCount);
        timeLimit = System.currentTimeMillis() + TIME_LIMIT;
        while (System.currentTimeMillis() < timeLimit) {
            Node promisingNode = getPromisingNode(rootNode);
            if (promisingNode.childNodes.isEmpty()) {
                addChildNodes(promisingNode, childCount);
            }
            simulateRandomPlay(promisingNode);
        }
        winnerNode = getWinnerNode(rootNode);
        printScores(rootNode);
        return winnerNode;
    }
    public void addChildNodes(Node node, int childCount) {
        for (int i = 0; i < childCount; i++) {
            node.childNodes.add(new Node(node, !node.isPlayersTurn));
        }
    }
    public Node getPromisingNode(Node rootNode) {
        Node promisingNode = rootNode;
        while (!promisingNode.childNodes.isEmpty()) {
            double uctIndex = Double.MIN_VALUE;
            int nodeIndex = 0;
            for (int i = 0; i < promisingNode.childNodes.size(); i++) {
                Node childNode = promisingNode.childNodes.get(i);
                double uctTemp = (childNode.visitCount == 0)
                        ? Double.MAX_VALUE
                        : ((double) childNode.score / childNode.visitCount)
                        + 1.41 * Math.sqrt(Math.log(promisingNode.visitCount) / childNode.visitCount);
                if (uctTemp > uctIndex) {
                    uctIndex = uctTemp;
                    nodeIndex = i;
                }
            }
            promisingNode = promisingNode.childNodes.get(nodeIndex);
        }
        return promisingNode;
    }
    public void simulateRandomPlay(Node promisingNode) {
        Random rand = new Random();
        Node tempNode = promisingNode;
        boolean isPlayerWinner = rand.nextBoolean(); 
        while (tempNode != null) {
            tempNode.visitCount++;
            if ((tempNode.isPlayersTurn && isPlayerWinner) || (!tempNode.isPlayersTurn && !isPlayerWinner)) {
                tempNode.score += WIN_SCORE;
            }
            tempNode = tempNode.parent;
        }
    }
    public Node getWinnerNode(Node rootNode) {
        return Collections.max(rootNode.childNodes, Comparator.comparing(c -> c.score));
    }
    public void printScores(Node rootNode) {
        System.out.println("Node\tScore\tVisits");
        for (int i = 0; i < rootNode.childNodes.size(); i++) {
            System.out.printf("%d\t%d\t%d%n", i + 1, rootNode.childNodes.get(i).score, rootNode.childNodes.get(i).visitCount);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int childCount = scanner.nextInt();
        boolean isPlayersTurn = scanner.nextBoolean();
        MonteCarloTreeSearch mcts = new MonteCarloTreeSearch();
        Node rootNode = mcts.new Node(null, isPlayersTurn);
        Node winnerNode = mcts.monteCarloTreeSearch(rootNode, childCount);
        System.out.printf("Optimal node: %d%n", rootNode.childNodes.indexOf(winnerNode) + 1);
        scanner.close();
    }
}
