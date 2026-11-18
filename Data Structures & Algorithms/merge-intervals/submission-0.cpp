class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;

        for(int i = 0; i < intervals.size(); i++){

            if(output.empty() || intervals[i][0] > output.back()[1]){
                output.push_back(intervals[i]);
            }else{

                output.back()[1] = max(output.back()[1], intervals[i][1]);

            }

        }

        return output;

    }
};
