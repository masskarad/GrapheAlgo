#include<string.h>

void Merge(char *array, int left, int mid, int right){
    char tempArray[right-left+1];
    int pos=0,lpos = left,rpos = mid + 1;
    while(lpos <= mid && rpos <= right){
            if(array[lpos] <= array[rpos]){
                    tempArray[pos++] = array[lpos++];
          }
            else{
                    tempArray[pos++] = array[rpos++];
            }
    }
    while(lpos <= mid)  tempArray[pos++] = array[lpos++];
    while(rpos <= right)tempArray[pos++] = array[rpos++];
    int iter;
    for(iter = 0;iter < pos; iter++){
            array[iter+left] = tempArray[iter];
    }
    return;
}

void MergeSort(char *array, int left, int right){
    int mid = (left+right)/2;
    if(left<right){
            MergeSort(array,left,mid);
            MergeSort(array,mid+1,right);
            Merge(array,left,mid,right);
    }
}

int main (){ 
	char s[100];
	int n,d;
    scanf("%s",s);
    n=strlen(s);
    MergeSort(s,0,n-1);
    printf("%s",s); 
	return 0;
}
