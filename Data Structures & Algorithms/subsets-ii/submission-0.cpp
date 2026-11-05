class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& output, 
            vector<int>& actual, int index){

        if(index == nums.size()){
            output.push_back(actual);
            return;
        }

        // Opción 1 : incluimos el número

        actual.push_back(nums[index]);

        dfs(nums, output, actual, index + 1);

        // Opcion 2 : no incluimos el número

        actual.pop_back();

        int next = index + 1;

        while(next < nums.size() && nums[next] == nums[index]){
            next += 1;
        } 

        dfs(nums, output, actual, next);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> output;
        vector<int> actual;

        dfs(nums, output, actual, 0);

        return output;

    }
};
