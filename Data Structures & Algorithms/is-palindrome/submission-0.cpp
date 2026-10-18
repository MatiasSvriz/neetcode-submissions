class Solution {
public:
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.size() - 1;

        while(left < right){

            // ignoramos caracteres no alfanumericos

            if(!isalnum(s[left])){
                left ++;
                continue;
            }
            if(!isalnum(s[right])){
                right --;
                continue;
            }

            // comparamos ambos caracteres en minuscula
            if(tolower(s[left]) != tolower(s[right])){

                return false;

            }
            
            // acercamos los punteros

            else{

                left ++;
                right --;

            }

        }

        return true;

    }
};
