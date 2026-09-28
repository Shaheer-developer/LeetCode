class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0;
        while(s[length] != '\0'){
             length +=1;
        }
        int longest = 0;
        int* arr = new int[length];
        int size = 0;
        int base_index = -1;
        for(int i = 0; i < length; i++){
            if(s[i] == ')' && size == 0){
                base_index = i;
                 continue;
            }
            else if(s[i] == '('){
                 arr[size] = i;
                 size++;
            }
            else if(s[i] == ')'){
                size--;
                int current_length;
                if (size == 0) {
                    current_length = i - base_index;
                } else {
                    current_length = i - arr[size - 1];
                }
                
                if (current_length > longest) {
                    longest = current_length;
                }
            }
        }
        return longest;
    }
};