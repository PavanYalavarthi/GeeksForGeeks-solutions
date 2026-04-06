/*
Problem credits: https://www.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1

Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, ... ,Z, AA, AB, AC,.... ,AZ, BA, BB, ... ZZ, AAA, AAB ..... etc. In other words, column 1 is named as "A", column 2 as "B", column 27 as "AA" and so on.

*/

// User function Template for Java
import java.util.stream.Stream;
class Solution {
    String colName(long n) {
       
        return Stream.iterate(n, x -> x > 0, x -> (x - 1)/26)
                .map(x -> (char)('A' + (x - 1)% 26))
                .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append)
                .reverse().toString();
    }
}