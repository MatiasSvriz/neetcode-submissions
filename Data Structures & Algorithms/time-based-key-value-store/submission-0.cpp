class TimeMap {

private:
    unordered_map<string, vector<pair<int,string>>> data;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        data[key].push_back({timestamp, value});

    }
    
    string get(string key, int timestamp) {

        vector<pair<int,string>>& values = data[key];

        int left = 0;
        int right = values.size() - 1;

        int result = - 1;

        while(left <= right){

            int mid = left + (right - left) / 2;

            if(values[mid].first <= timestamp){

                result = mid;
                left = mid + 1;

            }else{

                right = mid - 1;

            }

        }

        if(result == -1){
            return "";
        }

        return values[result].second;

    }
};
