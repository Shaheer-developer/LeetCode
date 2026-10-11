class Solution {
public:
    int getAdvantage(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];
        int featureA = nums[left] - getAdvantage(nums, left+1, right);
        int featureB = nums[right] - getAdvantage(nums, left, right-1);
        
        return featureA > featureB? featureA: featureB;
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int result = getAdvantage(nums, 0, nums.size() - 1);
        return result >= 0;
    }
};