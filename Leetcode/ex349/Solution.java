package ex349;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public static int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s = new HashSet<>();
        
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int i = 0;
        int j = 0;
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] == nums2[j]){
                s.add(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        
        int[] result = new int[s.size()];
        i = 0;
        for(int a : s){
            result[i++] = a;
        }
        return result;
    }
    
    public static void main(String[] args) {
    	int[] num1 = {1,5,2,6};
    	int[] num2 = {5,2,9,7};
    	int[] result = intersection(num1, num2);
		System.out.println(Arrays.toString(result));
	}
}