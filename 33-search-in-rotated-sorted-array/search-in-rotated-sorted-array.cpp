class Solution {
public:

    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Find minimum index
        int start = 0;
        int end = n - 1;

        while(start <= end)
        {
            if(nums[start] <= nums[end])
            {
                break;
            }

            int mid = start + (end - start) / 2;

            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if(nums[mid] < nums[prev] && nums[mid] < nums[next])
            {
                start = mid;
                break;
            }
            else if(nums[start] <= nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        int minIndex = start;

        // Array is completely sorted
        if(minIndex == 0)
        {
            return binarySearch(nums, 0, n - 1, target);
        }

        // Search in left sorted part
        if(target >= nums[0] && target <= nums[minIndex - 1])
        {
            return binarySearch(nums, 0, minIndex - 1, target);
        }

        // Search in right sorted part
        return binarySearch(nums, minIndex, n - 1, target);
    }
};