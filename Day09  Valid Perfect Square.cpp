/* Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
	Input: 16
	Output: true

Example 2:
	Input: 14
	Output: false
*/

//Iterative Approach (Time Consuming)
class Solution {
public:
    bool isPerfectSquare(int num) {        
		for(int i=1;i<=(num/2)+1;i++) {
            if(num%i == 0 && (num/i) == i)
                return true;
    	}
    	return false;
    }
};

//Binary Search Technique
class Solution {
public:
    bool isPerfectSquare(int num) {        
        long l=1,r=num,mid,sqr;
        
        while(l<=r) {
            mid = l + (r-l)/2;
            sqr = mid*mid;
            if(sqr<num)
                l = mid+1;
            else if(sqr>num)
                r = mid-1;
            else
                return true;
        }
        return false;
    }
};
