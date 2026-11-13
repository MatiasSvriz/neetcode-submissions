class KthLargest {

private:

    int k;

    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) {
        
        this->k = k;

        for(int num : nums){

            heap.push(num);

            // Conservamos solo los k-mayores
            if(heap.size() > k){

                heap.pop();

            }

        }

    }
    
    int add(int val) {
        
        // Añadimos el nuevo numero
        heap.push(val);

        // Si sobra uno, descartamos el menor
        if(heap.size() > k){

            heap.pop();

        }

        // El menor de los k-mayores, es el k-esimo
        return heap.top();

    }
};
