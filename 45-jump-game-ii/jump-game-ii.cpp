class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int left = 0, right = 0;           // block of indices reachable with `jumps` jumps

        while (right < n - 1) {            // until the last index is inside the block
            int farthest = 0;

            for (int i = left; i <= right; i++) {
                farthest = max(farthest, i + nums[i]);   // best reach from this block
            }

            left = right + 1;              // next block starts after the current one
            right = farthest;              // and ends at the farthest reach
            jumps++;                       // moving to the next block = 1 more jump
        }
        return jumps;
    }
};