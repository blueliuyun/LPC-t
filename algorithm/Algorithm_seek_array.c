/** 
 * @breif  对{有序}数组做二分法查找.
 * @param a 		需要被查找的数组
 * @param front 	数组的第一个索引, 数组下标从 0 开始
 * @param end 		数组的最后一个索引
 * @param seekValue 需要查找的元素
 * @return int 		返回查到的元素索引，-1表示没有查到.
 */
static int seek_array_index_binary(const int a[], int front, int end, int seekValue) 
{
	if (front <= end) {
		int mid;
		mid = (front + end) / 2;
		if (a[mid] == seekValue) {
			return mid;
		} else if (a[mid] > seekValue) {
			return seek_array_index_binary(a, front, mid - 1, seekValue);
		} else if (a[mid] < seekValue) {
			return seek_array_index_binary(a, mid + 1, end, seekValue);
		}
	}
	return -1;
}

/** 
 * @breif  对{有序}数组做二分法查找.
 * @param a 		需要被查找的数组
 * @param front 	数组的第一个索引, 数组下标从 0 开始
 * @param end 		数组的最后一个索引
 * @param seekValue 需要查找的元素
 * @return int 		返回查到的元素索引，-1表示没有查到.
 */
static int seek_array_index_Sequential(const int a[], int front, int end, int seekValue) 
{
	int i = 0;
	if (front <= end) {
    	for(i=front; i<end; i++) {		
			if(a[i] == seekValue) {
				return i;
			}            
		}
	}
	return -1;
}
