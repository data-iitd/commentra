########
# Code #
########

// Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Define the modulus value
final int mod = 1000000007;

// Function to read an integer
static int I() throws IOException {
    return Integer.parseInt(br.readLine().trim());
}

// Function to read a list of integers
static List<Integer> III() throws IOException {
    return Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a list of lists (2D array)
static List<List<Integer>> Line(int N) throws IOException {
    List<List<Integer>> read_all = new ArrayList<>();
    for (int i = 0; i < N; i++) {
        read_all.add(III());
    }
    return read_all;
}

// Function to read a string
static String S() throws IOException {
    return br.readLine().trim();
}

// Function to read a string array
static String[] SS() throws IOException {
    return br.readLine().split(" ");
}

// Function to read an integer array
static int[] II() throws IOException {
    return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read a long array
static long[] LL() throws IOException {
    return Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
}

// Function to read a double array
static double[] DD() throws IOException {
    return Arrays.stream(br.readLine().split(" ")).mapToDouble(Double::parseDouble).toArray();
}

// Function to read a double array
static double[][] DDD() throws IOException {
    String[][] arr = new String[2][];
    arr[0] = SS();
    arr[1] = SS();
    double[][] darr = new double[2][];
    darr[0] = Arrays.stream(arr[0]).mapToDouble(Double::parseDouble).toArray();
    darr[1] = Arrays.stream(arr[1]).mapToDouble(Double::parseDouble).toArray();
    return darr;
}

// Function to read a double array
static double[][][] DDDD() throws IOException {
    String[][][] arr = new String[3][2][];
    for (int i = 0; i < 3; i++) {
        arr[i][0] = SS();
        arr[i][1] = SS();
    }
    double[][][] darr = new double[3][2][];
    for (int i = 0; i < 3; i++) {
        darr[i][0] = Arrays.stream(arr[i][0]).mapToDouble(Double::parseDouble).toArray();
        darr[i][1] = Arrays.stream(arr[i][1]).mapToDouble(Double::parseDouble).toArray();
    }
    return darr;
}

// Function to read a double array
static double[][][][] DDDDD() throws IOException {
    String[][][][] arr = new String[4][3][2][];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j][0] = SS();
            arr[i][j][1] = SS();
        }
    }
    double[][][][] darr = new double[4][3][2][];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            darr[i][j][0] = Arrays.stream(arr[i][j][0]).mapToDouble(Double::parseDouble).toArray();
            darr[i][j][1] = Arrays.stream(arr[i][j][1]).mapToDouble(Double::parseDouble).toArray();
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][] DDDDDD() throws IOException {
    String[][][][][] arr = new String[5][4][3][2][];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                arr[i][j][k][0] = SS();
                arr[i][j][k][1] = SS();
            }
        }
    }
    double[][][][][] darr = new double[5][4][3][2][];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                darr[i][j][k][0] = Arrays.stream(arr[i][j][k][0]).mapToDouble(Double::parseDouble).toArray();
                darr[i][j][k][1] = Arrays.stream(arr[i][j][k][1]).mapToDouble(Double::parseDouble).toArray();
            }
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][][] DDDDDDD() throws IOException {
    String[][][][][][] arr = new String[6][5][4][3][2][];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 3; l++) {
                    arr[i][j][k][l][0] = SS();
                    arr[i][j][k][l][1] = SS();
                }
            }
        }
    }
    double[][][][][][] darr = new double[6][5][4][3][2][];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 3; l++) {
                    darr[i][j][k][l][0] = Arrays.stream(arr[i][j][k][l][0]).mapToDouble(Double::parseDouble).toArray();
                    darr[i][j][k][l][1] = Arrays.stream(arr[i][j][k][l][1]).mapToDouble(Double::parseDouble).toArray();
                }
            }
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][][][] DDDDDDDD() throws IOException {
    String[][][][][][][] arr = new String[7][6][5][4][3][2][];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 3; m++) {
                        arr[i][j][k][l][m][0] = SS();
                        arr[i][j][k][l][m][1] = SS();
                    }
                }
            }
        }
    }
    double[][][][][][][] darr = new double[7][6][5][4][3][2][];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 4; l++) {
                    for (int m = 0; m < 3; m++) {
                        darr[i][j][k][l][m][0] = Arrays.stream(arr[i][j][k][l][m][0]).mapToDouble(Double::parseDouble).toArray();
                        darr[i][j][k][l][m][1] = Arrays.stream(arr[i][j][k][l][m][1]).mapToDouble(Double::parseDouble).toArray();
                    }
                }
            }
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][][][][] DDDDDDDDD() throws IOException {
    String[][][][][][][][] arr = new String[8][7][6][5][4][3][2][];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 6; k++) {
                for (int l = 0; l < 5; l++) {
                    for (int m = 0; m < 4; m++) {
                        for (int n = 0; n < 3; n++) {
                            arr[i][j][k][l][m][n][0] = SS();
                            arr[i][j][k][l][m][n][1] = SS();
                        }
                    }
                }
            }
        }
    }
    double[][][][][][][][] darr = new double[8][7][6][5][4][3][2][];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 6; k++) {
                for (int l = 0; l < 5; l++) {
                    for (int m = 0; m < 4; m++) {
                        for (int n = 0; n < 3; n++) {
                            darr[i][j][k][l][m][n][0] = Arrays.stream(arr[i][j][k][l][m][n][0]).mapToDouble(Double::parseDouble).toArray();
                            darr[i][j][k][l][m][n][1] = Arrays.stream(arr[i][j][k][l][m][n][1]).mapToDouble(Double::parseDouble).toArray();
                        }
                    }
                }
            }
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][][][][][] DDDDDDDDDD() throws IOException {
    String[][][][][][][][][] arr = new String[9][8][7][6][5][4][3][2][];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 7; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 5; m++) {
                        for (int n = 0; n < 4; n++) {
                            for (int o = 0; o < 3; o++) {
                                arr[i][j][k][l][m][n][o][0] = SS();
                                arr[i][j][k][l][m][n][o][1] = SS();
                            }
                        }
                    }
                }
            }
        }
    }
    double[][][][][][][][][] darr = new double[9][8][7][6][5][4][3][2][];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 7; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 5; m++) {
                        for (int n = 0; n < 4; n++) {
                            for (int o = 0; o < 3; o++) {
                                darr[i][j][k][l][m][n][o][0] = Arrays.stream(arr[i][j][k][l][m][n][o][0]).mapToDouble(Double::parseDouble).toArray();
                                darr[i][j][k][l][m][n][o][1] = Arrays.stream(arr[i][j][k][l][m][n][o][1]).mapToDouble(Double::parseDouble).toArray();
                            }
                        }
                    }
                }
            }
        }
    }
    return darr;
}

// Function to read a double array
static double[][][][][][][][][][] DDDDDDDDDDD() throws IOException {
    String[][][][][][][][][][] arr = new String[10][9][8][7][6][5][4][3][2][];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 7; l++) {
                    for (int m = 0; m < 6; m++) {
                        for (int n = 0; n < 5; n++) {
                            for (int o = 0; o < 4; o++) {
                                for (int p = 0; p < 3; p++) {
                                    arr[i][j][k][l][m][n][o][p][0] = SS();
                                    arr[i][j][k][l][m][n][o][p][1] = SS();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    double[][][][][][][][][][] darr = new double[10][9][8][7][6][5][4][3][2][];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 8; k++) {
  