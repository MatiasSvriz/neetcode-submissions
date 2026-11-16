class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // Montando el heap de esta forma, 
        // el .top() siempre devuelve el más pequeño
        priority_queue<int, vector<int>, greater<int>> heap;

        for(int num : nums){

            heap.push(num);

            if(heap.size() > k){
                heap.pop();
            }

        }

        return heap.top();

    }
};
