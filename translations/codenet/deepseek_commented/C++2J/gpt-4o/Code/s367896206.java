import java.util.Arrays;

// Represents a cube with six faces, each face having an integer value.
class Cube {
    int[] f;

    // Constructor to initialize the cube faces
    public Cube() {
        f = new int[6];
    }

    // Rotates the cube around the z-axis.
    public void rollZ() {
        roll(1, 2, 4, 3);
    }

    // Rotates the cube around the y-axis.
    public void rollY() {
        roll(0, 2, 5, 3);
    }

    // Rotates the cube around the x-axis.
    public void rollX() {
        roll(0, 1, 5, 4);
    }

    // Helper method to rotate the cube by swapping the values of the faces.
    private void roll(int i, int j, int k, int l) {
        int t = f[i];
        f[i] = f[j];
        f[j] = f[k];
        f[k] = f[l];
        f[l] = t;
    }
}

// <END-OF-CODE>
