#include <iostream>
#include <vector>
using namespace std;

class FloodFillDFS {
public:
    void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return;
        dfs(image, sr, sc, oldColor, newColor);
    }

    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        // Boundary check
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
            return;

        // Stop if color does not match
        if (image[r][c] != oldColor)
            return;

        // Replace color
        image[r][c] = newColor;

        // Explore neighbors
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
    }
};

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    FloodFillDFS solver;
    solver.floodFill(image, 1, 1, 2);

    // Print output
    for (auto& row : image) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
