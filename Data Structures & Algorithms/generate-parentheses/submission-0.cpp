class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack){
        if(openN == closedN && openN == n){ //our parentheses are used up
            res.push_back(stack);
            return;
        }

        if(openN < n){ // add open parentheses as long as we have them available
            stack += '(';
            backtrack(openN + 1, closedN, n, res, stack);
            stack.pop_back();
        }
        if(closedN < openN){ // add a closing parentheses only if closed < open
            stack += ')';
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
};
