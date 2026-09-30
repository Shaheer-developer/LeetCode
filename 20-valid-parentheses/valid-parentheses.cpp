class Solution {
public:
    bool isValid(string s) {
        vector<char> stack; 
        int index = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') {
                stack.push_back('(');
                index++;
            }
            else if(s[i] == '[') {
                stack.push_back('[');
                index++;
            }
            else if(s[i] == '{'){
                 stack.push_back('{');
                 index++;
            }
            else if(s[i] == ')'){
                if(index != -1 && stack[index] == '('){
                    stack.pop_back();
                    index--;
                } 
                else return false;
            }
            else if(s[i] == ']'){
                if(index != -1 && stack[index] == '['){
                     stack.pop_back();
                     index--;
                }
                else return false;
            }
            else if(s[i] == '}'){
                if(index != -1 && stack[index] == '{') {
                    stack.pop_back();
                    index--;
                }
                else return false;
            }
        }
        return stack.empty();
    }
};