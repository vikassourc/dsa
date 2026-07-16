class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>arr;
        for(int i=0;i<m;i++)
        {
            arr.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++)
        {
            arr.push_back(nums2[i]);
        }
        sort(arr.begin(),arr.end());
        int p=arr.size();
        if(p%2==0)
        {
            double median=(arr[p/2] + arr[(p/2)-1]) / 2.0;
            return median;

        }
        else
        {
            return arr[p/2];
        }

        
    }
};