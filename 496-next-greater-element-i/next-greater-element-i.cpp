#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    stack<int> st;
    vector<int> nge;

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge2(n2, -1);  // with intial value -1

        // Step 1: Calculate NGE for nums2 using the monotonic stack approach
        for (int i = n2 - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            if (!st.empty())
                nge2[i] = st.top();
            st.push(nums2[i]);
        }

        // Step 2: For every nums1[i], find its index in nums2 and take result from nge2
        nge.resize(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < n2; ++j) {
                if (nums1[i] == nums2[j]) {
                    nge[i] = nge2[j];
                    break;
                }
            }
        }
        return nge;
    }
};
