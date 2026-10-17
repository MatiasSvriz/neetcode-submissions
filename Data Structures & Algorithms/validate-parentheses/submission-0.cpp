class Solution {
public:
    bool isValid(string s) {

        stack<char> brackets;

        for(char c : s){

            if(c == '[' || c == '{' || c == '('){

                brackets.push(c);

            }

            else{

                if(brackets.empty()){
                    return false;
                }

                char last = brackets.top();

                if(c == ']' && last != '['){
                    return false;
                }
                if(c == '}' && last != '{'){
                    return false;
                }
                if(c == ')' && last != '('){
                    return false;
                }

                brackets.pop();

            }

        }

        if(brackets.empty()){
            return true;
        }else{
            return false;
        }

    }
};
