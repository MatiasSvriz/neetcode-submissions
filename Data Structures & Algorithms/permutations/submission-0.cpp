class Solution {
public:

    void dfs(vector<int>& nums, 
            vector<int>& actual,  
            vector<vector<int>>& output,
            vector<bool>& usado){

        if(actual.size() == nums.size()){
            output.push_back(actual);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(usado[i] == true){

                continue;

            }else{

                usado[i] = true;
                actual.push_back(nums[i]);

                dfs(nums, actual, output, usado);

                actual.pop_back();
                usado[i] = false;

            }

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> output;
        vector<int> actual;
        vector<bool> usado(nums.size(), false);

        dfs(nums, actual, output, usado);

        return output;

    }
};
