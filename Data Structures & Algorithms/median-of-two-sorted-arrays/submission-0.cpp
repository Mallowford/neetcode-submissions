class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        int med1 = 0;
        int med2 = 0;

        for (int count = 0; count < (n1 + n2) / 2 + 1; count++) {
            med2 = med1;
            if (i < n1 && j < n2) {
                if (nums1[i] > nums2[j]) {
                    med1 = nums2[j];
                    j++;
                }
                else {
                    med1 = nums1[i];
                    i++;
                };
            }
            else if (i < n1) {
                med1 = nums1[i];
                i++;
            }
            else {
                med1 = nums2[j];
                j++;
            };
        };

        if ((n1 + n2) % 2 == 1) {
            return (double) med1;
        } else {
            return (med1 + med2) / 2.0;
        };

    };
};
