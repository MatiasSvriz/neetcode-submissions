class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> target;
        unordered_map<char,int> window;

        for(char c : s1){

            target[c] ++;

        }

        int left = 0;
        int right = 0;

        while(right < s2.size()){

            window[s2[right]] ++;

            if(right - left + 1 > s1.size()){

                window[s2[left]] --;

                // Hacemos limpieza total para poder hacer window == target
                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }

                left ++;

            }

            if((right - left + 1) == s1.size() && window == target){
                return true;
            }

            right ++;

        }

        return false;

    }
};
