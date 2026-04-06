/*
    credits: https://www.geeksforgeeks.org/problems/alien-dictionary/1

    A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

*/

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<int>indegree(26, -1);
        vector<unordered_set<int>> gr(26);
        int n = words.size(), uniqueChars = 0;
        string prev = "";
        for(auto& curr: words) {
            if (uniqueChars != 26) {
                for(char c: curr) {
                    int idx = c - 'a';
                    if (indegree[idx] == -1) {
                        uniqueChars++;
                        indegree[idx] = 0;
                    }
                }
            }
            bool isFound = false;
            for(int j = 0; j < min(prev.size(), curr.size()); j++) {
                if (prev[j] != curr[j]) {
                    int idx1 = prev[j] - 'a', idx2 = curr[j] - 'a';
                    if (gr[idx1].count(idx2) == 0) {
                        gr[idx1].insert(idx2);
                        indegree[idx2]++;
                    }
                    isFound = true;
                    break;
                }
            }
            if (!isFound && prev.size() > curr.size()) {
                return "";
            }
            prev = curr;
        }
        queue<int>q;
        for(int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                uniqueChars--;
            }
        }
        string ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node + 'a');
            for(int child: gr[node]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    q.push(child);
                    uniqueChars--;
                }
            }
        }
        return (uniqueChars == 0) ? ans : "";
    }
};