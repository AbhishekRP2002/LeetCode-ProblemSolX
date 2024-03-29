class Solution {
public:
    void merge(vector<int>&nums , int low , int mid , int high)
    {
//         base case
        if(low==high)
            return;
        
        vector<int>temp;
        int i = low;
        int j = mid+1;
        while(i<=mid and j<=high)
        {
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
                
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
                
            }
            
        }
        
        
        while(i<=mid)
        {
            temp.push_back(nums[i]);i++;
        }
        while(j<=high)
        {
            temp.push_back(nums[j]);
            j++;
        }
        
        for(int i=low ;i<=high;++i)
        {
            nums[i] = temp[i-low];
        }
        
    }
        void mergeSort(vector<int>& nums , int low , int high)
    {
//         base case
            if(low >= high)
                return;
        
        int mid = low + (high-low)/2;
        mergeSort(nums , low , mid);
        mergeSort(nums , mid+1 , high);
        merge(nums , low , mid , high);
    }
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        // return nums;
        int low  = 0 , high = nums.size();
        mergeSort(nums , low , high-1);
        return nums;
    }
};