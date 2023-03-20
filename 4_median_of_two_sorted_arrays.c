#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	if(nums1Size == 0 && nums2Size == 0)
        return 0.0;
    else if(nums1Size != 0 && nums2Size == 0)
        return nums1Size % 2 ? nums1[nums1Size/2] : (nums1[nums1Size/2-1]+nums1[nums1Size/2])/2.0;
    else if(nums1Size == 0 && nums2Size != 0)
        return nums2Size % 2 ? nums2[nums2Size/2] : (nums2[nums2Size/2-1]+nums2[nums2Size/2])/2.0;
	double median = nums1[0]<=nums2[0] ? nums1[0] : nums2[0];
    int i = 0;
    int j = 0;
	while(i + j <= ((nums1Size + nums2Size) / 2 - 1))
	{
		if(i < nums1Size && j < nums2Size)
		{
			if(nums1[i] <= nums2[j])
        	{
            	median = nums1[i];
            	i++;
        	}
        	else if(j < nums2Size && nums1[i] > nums2[j])
        	{
            	median = nums2[j];
            	j++;
        	}
		}
		else if(i < nums1Size)
		{
			median = nums1[i];
			i++;
		}
		else if(j < nums2Size)
		{
			median = nums2[j];
			j++;
		}
	}
	if((nums1Size + nums2Size) % 2)//odd
	{
		if(i < nums1Size && j < nums2Size)
		{
			if(nums1[i] <= nums2[j])
				return nums1[i];
			else
				return nums2[j];
		}
		else if(i < nums1Size)
			return nums1[i];
		else if(j < nums2Size)
			return nums2[j];
	}
	else//even
	{
		if(i < nums1Size && j < nums2Size)
		{
			if(nums1[i] <= nums2[j])
            	return (median + nums1[i])/2.0;
        	else
        	    return (median + nums2[j])/2.0;
		}
		else if(i < nums1Size)
			return (median + nums1[i])/2.0;
		else if(j < nums2Size)
			return (median + nums2[j])/2.0;
	}
	return -1;//error
}

int main()
{
	int nums1[2] = {1,3};
	int nums2[1] = {2};
	printf("%f\n",findMedianSortedArrays(nums1, 2, nums2, 1));
	int nums3[2] = {1,2};
    int nums4[2] = {3,4};
    printf("%f\n",findMedianSortedArrays(nums3, 2, nums4, 2));
	int nums5[6] = {0,1,2,3,4,5};
    int nums6[6] = {0,1,2,3,4,5};
    printf("%f\n",findMedianSortedArrays(nums5, 6, nums6, 6));
	int nums7[0];
	int nums8[2] = {2,3};
	printf("%f\n",findMedianSortedArrays(nums7, 0, nums8, 2));
	int nums9[3] = {2,2,2};
    int nums0[4] = {2,2,2,2};
    printf("%f\n",findMedianSortedArrays(nums9, 3, nums0, 4));
	return 0;
}
