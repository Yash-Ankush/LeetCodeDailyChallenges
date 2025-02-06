class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen=1;
        int incLen=1;
        int descLen=1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                incLen++;
                descLen=1;
            }
            else if(nums[i] < nums[i-1]){
                descLen++;
                incLen=1;
            }
            else{
                incLen=1;
                descLen=1;
            }

            maxLen=max(maxLen, max(incLen, descLen));
        }
        return maxLen;
    }
};