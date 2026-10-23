class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int right = 0;

        int maxLength = 0;

        unordered_map<char, int> frequency;

        while(right < s.size()){

            // Añadimos letra de la derecha
            frequency[s[right]] ++;

            // Reducimos ventana hasta necesitar como mucho k cambios
            while(true){

                int maxFrequency = 0;

                for(const auto& [character, freq] : frequency){

                    maxFrequency = max(freq, maxFrequency);

                }

                int length = right - left + 1;
                int replacementNeeds = length - maxFrequency;

                if(replacementNeeds <= k){
                    break;
                }else{

                    frequency[s[left]] --;
                    left ++;

                }

            }

            // Dado que salió del bucle, quiere decir que encontró ventana valida
            int length = right - left + 1;
            maxLength = max(maxLength, length);

            right++;

        }

        return maxLength;

    }
};
