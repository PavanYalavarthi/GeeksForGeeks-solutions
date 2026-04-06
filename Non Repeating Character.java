/*
Problem credits: https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

Given a string s consisting of lowercase English Letters. return the first non-repeating character in s. 

If there is no non-repeating character, return '$'.

*/

class Solution {
    public char nonRepeatingChar(String s) {
        int []freq = new int[26];
        for(char c: s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        for(char c: s.toCharArray()) {
            if (freq[c - 'a'] == 1) {
                return c;
            }
        }
        return '$';
    }
}
