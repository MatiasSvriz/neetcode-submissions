class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> heap;

        for(int weight : stones){

            heap.push(weight);

        }

        while(heap.size() > 1){

            int largest = heap.top();
            heap.pop();

            int secondLargest = heap.top();
            heap.pop();

            if(largest > secondLargest){
                heap.push(largest - secondLargest);
            }

        }

        if(heap.empty()){

            return 0;

        }

        return heap.top();

    }
};
