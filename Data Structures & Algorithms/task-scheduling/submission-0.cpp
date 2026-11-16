class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> frequencies;

        for(char task : tasks){

            frequencies[task] += 1;

        }

        // Arriba dejamos el con la mayor cantidad pendiente
        priority_queue<int> heap;

        for(auto& freq : frequencies){

            heap.push(freq.second);

        }

        int time = 0;

        while(!heap.empty()){

            vector<int> pending;

            int actualTime = 0;

            while(!heap.empty() && actualTime < n + 1 ){

                int quantity = heap.top();
                heap.pop();

                quantity -= 1;
                actualTime += 1;

                if(quantity > 0){
                    pending.push_back(quantity);
                }

            }

            for(int quantity : pending){

                heap.push(quantity);

            }

            if(heap.empty()){
                time += actualTime; 
            }else{
                time += (n + 1);
            }

        }

        return time;

    }
};
