class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        int left = 0;
        int right = (m * n) - 1;

        while(left <= right){

            int mid = left + (right - left) / 2;

            int row = mid / n; // Integer division gives the row index
            int col = mid % n; // Modulo gives the column index (remainder)

            int value = matrix[row][col];

            if(value == target){
                return true;
            }

            if(value < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }

        }

        return false;

    }
};
