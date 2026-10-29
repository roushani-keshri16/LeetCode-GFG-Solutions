class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int original, int color) {
        // boundary check + sirf original color wale pixels hi change honge
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size()) return;
        if (image[r][c] != original) return;

        image[r][c] = color;

        dfs(image, r + 1, c, original, color);
        dfs(image, r - 1, c, original, color);
        dfs(image, r, c + 1, original, color);
        dfs(image, r, c - 1, original, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        // agar start pixel ka color pehle se hi same hai, to infinite recursion ho jayegi
        if (original == color) return image;

        dfs(image, sr, sc, original, color);
        return image;
    }
};