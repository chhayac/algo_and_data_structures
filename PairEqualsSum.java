/** 
 * Given a collection of numbers, determine whether there exists two distinct elements in the array
 * whose sum equals a target value.
 * Example:
 * elements = [2,4,5,9,1], target = 8  -> False
 * elements = [2,4,5,9,1], target = 7 -> true
 */

import java.util.*;
public class PairEqualsSum
{
    static boolean printpairs(int arr[], int target) {
        HashSet<Integer> hset = new HashSet<Integer>();
        for(int i = 0; i < arr.length; i++)
        {
            if(hset.contains(target - arr[i]))
            {
                System.out.println("1st element:" + arr[i] + "," +"2nd element:"+ (target-arr[i]));
                return true;
            }
            else
            {
                hset.add(arr[i]);
            }
        }
        return false;
    }
public static void main(String args[]) {
        int A[] = {2,5,4,9,1};
        int target = 10;
        boolean ifPrinted = printpairs(A,target);
        if (ifPrinted)
        {
            System.out.println("True");
        }
        else
        {
            System.out.println("False");
        }
    }  
}


