class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n),suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] * prefix[i - 1];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i] * suffix[i + 1];
        }
        vector<int>result(n);
        result[0] = suffix[1];
        result[n-1] = prefix[n-2];
        for(int i=1;i<n-1;i++){
            result[i] = prefix[i-1]*suffix[i+1];
        }
        return result;
    }
};