/*
    credits: https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

    Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.
Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.
*/

class Solution {
  public:
    bool isOperator(char c) {
        return (c == '+') || (c == '-') || (c == '*') || (c == '/');
    }
    bool checkRedundancy(string &s) {
        stack<char>stk;
        for(char c: s) {
            if (c == '(') {
                stk.push(c);
            } else if (isOperator(c)) {
                if (!stk.empty() && stk.top() == '(') {
                    stk.push(c);
                }
            } else if (c == ')') {
                char t = stk.top();
                stk.pop();
                if (t == '(') {
                    return true;
                }
                stk.pop();
            }
        }
        return false;
    }
};
