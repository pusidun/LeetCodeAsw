package ex202;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public static boolean isHappy(int n) {
        Set<Integer> s = new HashSet<>();
        
        if(n < 0)
        	return false;
        
        int tmp = n;
        while(tmp!=1)
        {
        	
        	int sum = 0;
        	while(tmp != 0)
        	{
        		sum += (tmp % 10) * (tmp % 10);
        		tmp /= 10;
        	}
        	tmp = sum;
        	if(s.contains(tmp))
        		break;
        	s.add(sum);
        }
        return tmp == 1;
    }
    
    public static void main(String[] args) {
		System.out.println(isHappy(2));
	}
}