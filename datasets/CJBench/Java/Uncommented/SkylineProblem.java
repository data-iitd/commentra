import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
public class SkylineProblem {
    private Building[] buildings;
    private int count;
    public SkylineProblem(int numBuildings) {
        buildings = new Building[numBuildings];
        count = 0;
    }
    public void add(int left, int height, int right) {
        buildings[count++] = new Building(left, height, right);
    }
    public ArrayList<Skyline> findSkyline(int start, int end) {
        if (start == end) {
            ArrayList<Skyline> list = new ArrayList<>();
            list.add(new Skyline(buildings[start].left, buildings[start].height));
            list.add(new Skyline(buildings[start].right, 0));
            return list;
        }
        int mid = (start + end) / 2;
        ArrayList<Skyline> leftSkyline = findSkyline(start, mid);
        ArrayList<Skyline> rightSkyline = findSkyline(mid + 1, end);
        return mergeSkyline(leftSkyline, rightSkyline);
    }
    public ArrayList<Skyline> mergeSkyline(ArrayList<Skyline> sky1, ArrayList<Skyline> sky2) {
        ArrayList<Skyline> mergedSkyline = new ArrayList<>();
        int h1 = 0, h2 = 0, maxHeight = 0;
        while (!sky1.isEmpty() && !sky2.isEmpty()) {
            if (sky1.get(0).x < sky2.get(0).x) {
                int x = sky1.get(0).x;
                h1 = sky1.get(0).height;
                sky1.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            } else {
                int x = sky2.get(0).x;
                h2 = sky2.get(0).height;
                sky2.remove(0);
                maxHeight = Math.max(h1, h2);
                addSkylinePoint(mergedSkyline, x, maxHeight);
            }
        }
        while (!sky1.isEmpty()) {
            mergedSkyline.add(sky1.remove(0));
        }
        while (!sky2.isEmpty()) {
            mergedSkyline.add(sky2.remove(0));
        }
        return mergedSkyline;
    }
    private void addSkylinePoint(ArrayList<Skyline> skyline, int x, int height) {
        if (skyline.isEmpty() || skyline.get(skyline.size() - 1).height != height) {
            skyline.add(new Skyline(x, height));
        }
    }
    public static class Skyline {
        public int x;
        public int height;
        public Skyline(int x, int height) {
            this.x = x;
            this.height = height;
        }
        @Override
        public String toString() {
            return x + " " + height;
        }
    }
    public static class Building {
        public int left;
        public int height;
        public int right;
        public Building(int left, int height, int right) {
            this.left = left;
            this.height = height;
            this.right = right;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numBuildings = scanner.nextInt();
        SkylineProblem skylineProblem = new SkylineProblem(numBuildings);
        for (int i = 0; i < numBuildings; i++) {
            int left = scanner.nextInt();
            int height = scanner.nextInt();
            int right = scanner.nextInt();
            skylineProblem.add(left, height, right);
        }
        ArrayList<Skyline> result = skylineProblem.findSkyline(0, numBuildings - 1);
        for (Skyline point : result) {
            System.out.println(point);
        }
        scanner.close();
    }
}
