class Solution {
public:
    int getDigitSum(int val) {
        int sum = 0;
        while (val) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max_sum = -1;
        for (int i : nums) {
            int digit_sum = getDigitSum(i);
            if (mp.count(digit_sum)) {
                max_sum = max(max_sum, i + mp[digit_sum]);
                if (mp[digit_sum] < i) {
                    mp[digit_sum] = i;
                }
            } else {
                mp[digit_sum] = i;
            }
        }

        return max_sum;
    }
};
