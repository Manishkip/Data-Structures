//Search a 2D Matrix (Binary Search Implementation)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Initialize pointers for binary search
        int left = 0, right = rows * cols - 1;

        // Handle the case when there are no rows in the matrix
        if (rows == 0)
            return false;

        // Binary search loop
        while (left <= right) {
            // Calculate the middle index and the corresponding value
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / cols][mid % cols];

            // If the middle value is equal to the target, return true
            if (midValue == target) {
                return true;
            }
            // If the middle value is less than the target, move the left pointer to mid + 1
            else if (midValue < target) {
                left = mid + 1;
            }
            // If the middle value is greater than the target, move the right pointer to mid - 1
            else {
                right = mid - 1;
            }
        }

        // If the target was not found, return false
        return false;
    }
};
