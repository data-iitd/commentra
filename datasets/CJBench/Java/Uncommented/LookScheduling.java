import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class LookScheduling {
    private final int maxTrack;
    private final int currentPosition;
    private boolean movingUp;
    private int farthestPosition;
    public LookScheduling(int startPosition, boolean initialDirection, int maxTrack) {
        this.currentPosition = startPosition;
        this.movingUp = initialDirection;
        this.maxTrack = maxTrack;
    }
    public List<Integer> execute(List<Integer> requests) {
        List<Integer> result = new ArrayList<>();
        List<Integer> lower = new ArrayList<>();
        List<Integer> upper = new ArrayList<>();
        for (int request : requests) {
            if (request >= 0 && request < maxTrack) {
                if (request < currentPosition) {
                    lower.add(request);
                } else {
                    upper.add(request);
                }
            }
        }
        Collections.sort(lower);
        Collections.sort(upper);
        if (movingUp) {
            result.addAll(upper);
            if (!upper.isEmpty()) {
                farthestPosition = upper.get(upper.size() - 1);
            }
            movingUp = false;
            Collections.reverse(lower);
            result.addAll(lower);
            if (!lower.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, lower.get(0));
            }
        } else {
            Collections.reverse(lower);
            result.addAll(lower);
            if (!lower.isEmpty()) {
                farthestPosition = lower.get(0);
            }
            movingUp = true;
            result.addAll(upper);
            if (!upper.isEmpty()) {
                farthestPosition = Math.max(farthestPosition, upper.get(upper.size() - 1));
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int maxTrack = scanner.nextInt();
        int startPosition = scanner.nextInt();
        boolean movingUp = scanner.nextInt() == 1;
        int numRequests = scanner.nextInt();
        List<Integer> requests = new ArrayList<>();
        for (int i = 0; i < numRequests; i++) {
            requests.add(scanner.nextInt());
        }
        LookScheduling scheduler = new LookScheduling(startPosition, movingUp, maxTrack);
        List<Integer> result = scheduler.execute(requests);
        for (int r : result) {
            System.out.print(r + " ");
        }
        scanner.close();
    }
}
