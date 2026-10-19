class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();

        int left = 0;
        int right = n - 1;

        int maxArea = 0;

        while(left < right){

            int actualArea = min(heights[left], heights[right]) * (right - left);

            if(actualArea > maxArea){
                maxArea = actualArea;
            }

            if(heights[left] < heights[right]){
                left ++;
            }else{
                right --;
            }

        }

        return maxArea;
        
    }
};
