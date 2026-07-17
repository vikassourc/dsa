class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int sum = 0;
        int maxi = INT_MIN;
        
        int low = 0;
        int high = k - 1;
        
        // first window
        for(int i = low; i <= high; i++) {
            sum += arr[i];
        }
        
        maxi = sum;
        
        // sliding window
        while(high < n - 1) {
            high++;
            sum += arr[high];   // add next element
            sum -= arr[low];    // remove old element
            low++;
            
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};