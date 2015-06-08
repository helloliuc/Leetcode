class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = min(C, G) - max(A, E);
        int y = min(D, H) - max(B, F);
        return (C - A) * (D - B) + (G - E) * (H - F) - (x < 0 ? 0 : x) * (y < 0 ? 0 : y);
    }
};
