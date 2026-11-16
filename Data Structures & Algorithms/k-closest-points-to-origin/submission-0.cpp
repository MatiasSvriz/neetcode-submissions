class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // { distancia , {x,y} }
        priority_queue<pair<int, vector<int>>> heap;

        for(vector<int>& point : points){

            int x = point[0];
            int y = point[1];

            int distance = x * x + y * y;

            heap.push({distance, {x,y}});

            // Si sobran puntos
            if(heap.size() > k){

                heap.pop();

            }

        }

        vector<vector<int>> output;

        while(!heap.empty()){

            output.push_back(heap.top().second);
            heap.pop();

        }

        return output;

    }
};
