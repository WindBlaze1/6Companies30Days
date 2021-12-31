class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n = arr.size();
        
        int curr_sum = 0;
        
        int mini = INT_MAX;
        
        int start = 0;
        int end = 0;
        
        while(end < n)
        {
            while(curr_sum < target && end < n)
            {
                curr_sum += arr[end];
                end++;
            }
            
            while(curr_sum >= target && start < n)
            {
                mini = min(mini,(end-start));
                curr_sum -= arr[start];
                start++;
            }
        }
        
        if(mini == INT_MAX)
            return 0;
        
        return mini;
    }
};
