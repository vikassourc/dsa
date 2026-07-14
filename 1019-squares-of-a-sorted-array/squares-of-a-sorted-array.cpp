class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }

        }
        if(arr1.size()==0)
        {
            for(int i=0;i<arr2.size();i++)
            {
                arr2[i]=arr2[i]*arr2[i];
                
            }
            return arr2;

        }
        if(arr2.size()==0)
        {
            for(int i=0;i<arr1.size();i++)
            {
                arr1[i]=arr1[i]*arr1[i];
                
            }
            reverse(arr1.begin(),arr1.end());
            return arr1;

        }
        int i=0;
        int j=0;
        int id=0;
        int n=arr1.size();
        int m=arr2.size();
        vector<int>arr(n+m);
        for(int i=0;i<n;i++)
        {
            arr1[i]=arr1[i]*arr1[i];
            
        }
        reverse(arr1.begin(),arr1.end());

        for(int i=0;i<m;i++)
        {
            arr2[i]=arr2[i]*arr2[i];
        }
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                arr[id]=arr1[i];
                id++;
                i++;

            }
            else
            {
                arr[id]=arr2[j];
                id++;
                j++;
            }
        }
        while(i<n)
        {
            arr[id]=arr1[i];
            id++;
            i++;

        }
        while(j<m)
        {
            arr[id]=arr2[j];
            id++;
            j++;
        }
        return arr;
        

        
        
    }
};