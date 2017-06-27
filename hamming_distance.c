/* The Hamming distance between two integers is the number of positions 
 * at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 * Example:
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
          ↑   ↑
 * The above arrows point to positions where the corresponding bits are different.
 */

 #include <stdio.h>

int hammingDistance(int, int);

 int main()
 {  
     int x;
     int y;
     printf("Enter the 1st integer: ");
     scanf("%d", &x);
     printf("Enter the 2nd integer: ");
     scanf("%d", &y);
     int ham_distance = hammingDistance(x , y);
     printf("Hamming distance between x & y is %d\n", ham_distance);
 }

 int hammingDistance(int x, int y) 
 {
    int z = x ^ y;
    int count = 0;
    while(z)
    {
        count += z % 2;
        z >>= 1;
    }
    return count;
}
