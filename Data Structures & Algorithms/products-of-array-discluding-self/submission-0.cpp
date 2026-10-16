class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int,int>> products(n, {1,1});

        vector<int> result(n);

        // De izquierda a derecha
        int product = 1;

        for(int i = 0; i < n; i ++){
            products[i].first = product;
            product *= nums[i];
        }

        // De derecha a izquierda
        product = 1;

        for(int i = n-1; i >= 0; i --){
            products[i].second = product;
            product *= nums[i];
        }

        for(int i = 0; i < n; i ++){

            result[i] = products[i].first * products[i].second;

        }

        return result;

    }
};
