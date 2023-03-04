class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long  n = nums.size();
//         unordered_map<int,int>m;
//         for(int i=0;i<n;++i)
//         {
//             if(nums[i]==minK or nums[i]==maxK)
//                 m[nums[i]]++;
            
//         }
        //sliding window use / Two pointers 
        //BF -> Finding all subarrays and then checking the min and max of each ->ctr++
        
     long res = 0;
        bool minFound = false,maxFound = false;
        int start = 0,minStart = 0,maxStart = 0;
        
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(num < minK || num > maxK){
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if(num == minK){
                minFound  = true;
                minStart = i;
            }
            if(num == maxK){
                maxFound = true;
                maxStart = i;
            }
            
            if(minFound && maxFound){
                res += (min(minStart,maxStart) - start + 1);
            }
        }
        return res;
        
        
    }
};