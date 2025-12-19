public final class FloodFillDFS {

    private FloodFillDFS() {
        // Utility class; prevent instantiation.
    }
    public static void main(String[] args) {
        int[][] image = {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
        };

        floodFill(image, 1, 1, 2);

        for (int[] row : image) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    static void floodFill(int[][] image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return;
        dfs(image, sr, sc, oldColor, newColor);
    }

    static void dfs(int[][] image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || c < 0 || r >= image.length || c >= image[0].length) return;
        if (image[r][c] != oldColor) return;

        image[r][c] = newColor;

        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
}
