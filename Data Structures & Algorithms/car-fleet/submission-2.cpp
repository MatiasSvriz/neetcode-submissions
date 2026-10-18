class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> cars;

        for(int i = 0; i < position.size(); i ++){

            cars.push_back({position[i], speed[i]});

        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        float lastTimeOfArrival = 0;

        // We start from the one closer to arrival
        for(int i = position.size() - 1; i >= 0; i --){

            int pos = cars[i].first;
            int speed = cars[i].second;

            float time = (float)(target - pos) / speed;

            if(time > lastTimeOfArrival){

                fleets += 1;
                lastTimeOfArrival = time;

            }

        }

        return fleets;

    }
};
