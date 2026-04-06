/*
Problem credits: https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

Given a string s, reverse the string without reversing its individual words. Words are separated by dots(.).

Note: The string may contain leading or trailing dots(.) or multiple dots(.) between two words. The returned string should only have a single dot(.) separating the words, and no extra dots should be included.
*/

import java.util.stream.Collectors;
class Solution {
    public String reverseWords(String s) {
        return Arrays.stream(s.split("\\.+"))
        .filter(w -> !w.isEmpty())
        .collect(Collectors.collectingAndThen(Collectors.toList(), 
            l -> {
                Collections.reverse(l);
                return String.join(".", l);
            }));
    }
}
