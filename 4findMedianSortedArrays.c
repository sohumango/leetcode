/**
https://leetcode.com/problems/median-of-two-sorted-arrays/

gcc 4findMedianSortedArrays.c -o t4
./t4

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0

Example 2:
    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5

malloc new array cause heap buffer overflow
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sz = nums1Size + nums2Size;
    int m1 =  sz / 2;
    int m0 = -1;
    if( sz%2 == 0){
        m0 = m1-1;
    }
    int * p1 = nums1;
    int * p2 = nums2;
    int *p1End = p1 + nums1Size;
    int *p2End = p2 + nums2Size;
    int idx = 0;
    int sum = 0;
    while (p1 < p1End ||  p2 <p2End ) {
        int tmp = 0;
        if( p1<p1End && p2<p2End ) {
            if (*p1 <= *p2){
                tmp = *p1;
                p1++;
            } else {
                tmp = *p2;
                p2++;
            }
        } else if (p1<p1End){
            tmp = *p1;
            p1++;
        } else{
            tmp = *p2;
            p2++;
        }
        if(idx==m0){
            sum += tmp;
        } else if(idx==m1){
            sum += tmp;
            break;
        }
        idx++;
    }
    return m0>=0? sum/2.0 :sum;
}

int main(){
    int a1[2] = {1,3};
    int a2[1] = {2};
    double m1 = findMedianSortedArrays(a1, sizeof(a1)/sizeof(int), a2, sizeof(a2)/sizeof(int));
    printf("m = %f\n", m1);
    int b1[2] = {1,2};
    int b2[2] = {3,4};
    double m2 = findMedianSortedArrays(b1, sizeof(b1)/sizeof(int), b2, sizeof(b2)/sizeof(int));
    printf("m = %f\n", m2);
    int c1[0] = {};
    int c2[2] = {2,3};
    double m3 = findMedianSortedArrays(c1, sizeof(c1)/sizeof(int), c2, sizeof(c2)/sizeof(int));
    printf("m = %f\n", m3);
    return 0;
}