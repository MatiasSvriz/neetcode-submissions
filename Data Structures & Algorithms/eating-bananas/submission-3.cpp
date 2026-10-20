class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int result = 0;

        while(left <= right){

            int k = left + (right - left) / 2; // Platanos que puede comer por hora

            // h -> horas máximas

            long totalHours = 0;

            for(int pile : piles){

                int hours = pile / k;

                if (pile % k != 0){
                    hours += 1;
                }

                totalHours += hours;

            }

            if(totalHours <= h){
                result = k;
                right = k - 1;
            }else{
                left = k + 1;
            }

        } 

        return result;

    }
};
