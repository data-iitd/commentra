import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/**
 * The {@code SkylineProblem} class is used to solve the skyline problem using a
 * divide-and-conquer approach.
 * It reads input for building data, processes it to find the skyline, and
 * prints the skyline.
 */
public class SkylineProblem {

    private Building[] buildings;
    private int count;

    public SkylineProblem(int numBuildings) {
        buildings = new Building[numBuildings];
        count = 0;
    }

    /**
     * Adds a building with the given left, height, and right values to the
     * buildings list.
     *
     * @param left   The left x-coordinate of the building.
     * @param height The height of the building.
     * @param right  The right x-coordinate of the building.
     */
    public void add(int left, int height, int right) {
        buildings[count++] = new Building(left, height, right);
    }

    /**
     * Computes the skyline for a range of buildings using the divide-and-conquer
     * strategy.
     *
     * @param start The starting index of the buildings to process.
     * @param end   The ending index of the buildings to process.
     * @return A list of {@link Skyline} objects representing the computed skyline.
     */
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

    /**
     * Merges two skylines (sky1 and sky2) into one combined skyline.
     *
     * @param sky1 The first skyline list.
     * @param sky2 The second skyline list.
     * @return A list of {@link Skyline} objects representing the merged skyline.
     */
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

    /**
     * A class representing a point in the skyline with its x-coordinate and height.
     */
    public static class Skyline {
        public int x;
        public int height;

        /**
         * Constructor for the {@code Skyline} class.
         *
         * @param coordinates The x-coordinate of the skyline point.
         * @param height      The height of the skyline at the given coordinate.
         */
        public Skyline(int x, int height) {
            this.x = x;
            this.height = height;
        }

        @Override
        public String toString() {
            return x + " " + height;
        }
    }

    /**
     * A class representing a building with its left, height, and right
     * x-coordinates.
     */
    public static class Building {
        public int left;
        public int height;
        public int right;

        /**
         * Constructor for the {@code Building} class.
         *
         * @param left   The left x-coordinate of the building.
         * @param height The height of the building.
         * @param right  The right x-coordinate of the building.
         */
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
