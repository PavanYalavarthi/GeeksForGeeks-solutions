/*
Problem credits: https://www.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1

Given two arrays a[] and b[] of equal size, the task is to find whether the elements in the arrays are equal.
Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.
Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.

Solution: use hashmap to store freq and subtract in b's iteration
*/

class Solution {
    public static boolean checkEqual(int[] a, int[] b) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i: a) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        
        for(int i: b) {
            int cnt = mp.getOrDefault(i, 0);
            if (cnt == 0) return false;
            mp.put(i, cnt - 1);
        }
        return true;
    }
}