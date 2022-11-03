class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int>temp(n/2);
        for(int i=0;i<n/2;++i)
        {
            if(i%2)
                temp[i] = max(nums[2 * i], nums[2 * i + 1]);
            else
                temp[i] = min(nums[2 * i], nums[2 * i + 1]);
        }
        
        int ans = minMaxGame(temp);
        return ans;
    }
};