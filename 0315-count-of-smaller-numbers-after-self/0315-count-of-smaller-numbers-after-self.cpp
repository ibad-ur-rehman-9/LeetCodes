class Solution
{
public:
    void merge(vector<int> &nums, vector<int> &counts, vector<int> &indices, int start, int end)
    {
        int mid = start + ((end - start) / 2);
        int len1 = (mid - start) + 1;
        int len2 = end - mid;

        vector<int> subArr1(len1);
        vector<int> subArr2(len2);
        vector<int> indexArr1(len1);
        vector<int> indexArr2(len2);

        int k = start;
        for (int i = 0; i < len1; i++)
        {
            subArr1[i] = nums[k];
            indexArr1[i] = indices[k++];
        }

        k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            subArr2[i] = nums[k];
            indexArr2[i] = indices[k++];
        }

        // Merging two sorted arrays
        int indexOfSubArr1 = 0, indexOfSubArr2 = 0;
        k = start;

        while (indexOfSubArr1 < len1 && indexOfSubArr2 < len2)
        {
            if (subArr1[indexOfSubArr1] <= subArr2[indexOfSubArr2])
            {
                nums[k] = subArr1[indexOfSubArr1];
                indices[k] = indexArr1[indexOfSubArr1];
                counts[indexArr1[indexOfSubArr1]] += indexOfSubArr2; // Count smaller elements
                k++;
                indexOfSubArr1++;
            }
            else
            {
                nums[k] = subArr2[indexOfSubArr2];
                indices[k] = indexArr2[indexOfSubArr2];
                k++;
                indexOfSubArr2++;
            }
        }

        // Copy remaining elements of subArr1, if any
        while (indexOfSubArr1 < len1)
        {
            nums[k] = subArr1[indexOfSubArr1];
            indices[k] = indexArr1[indexOfSubArr1];
            counts[indexArr1[indexOfSubArr1]] += indexOfSubArr2;
            k++;
            indexOfSubArr1++;
        }

        // Copy remaining elements of subArr2, if any
        while (indexOfSubArr2 < len2)
        {
            nums[k] = subArr2[indexOfSubArr2];
            indices[k] = indexArr2[indexOfSubArr2];
            k++;
            indexOfSubArr2++;
        }
    }

    void mergeSort(vector<int> &nums, vector<int> &counts, vector<int> &indices, int start, int end)
    {
        // Base case
        if (start >= end)
        {
            return;
        }

        int mid = start + ((end - start) / 2);

        // Sorting the left part
        mergeSort(nums, counts, indices, start, mid);

        // Sorting the right part
        mergeSort(nums, counts, indices, mid + 1, end);

        // Merging two sorted sub-arrays
        merge(nums, counts, indices, start, end);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> counts(n, 0); // Initialize counts with 0s
        vector<int> indices(n);   // Track original indices
        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }

        mergeSort(nums, counts, indices, 0, n - 1);
        return counts;
    }
};