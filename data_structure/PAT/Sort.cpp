//
// Created by 少年与梦 on 2021-07-07.
//
#include "stdio.h"
//选择排序
//每趟选出待排序部分[i,n]中最小的元素，将其与arr[i]交换，总复杂度为O(n^2)
void selectSort(int arr[],int n) {
    for (int i = 0; i < n-1; ++i) {//进行n趟操作
        int k = i;
        for (int j = i+1; j < n; ++j) {//选出[i,n]中最小的元素，下标为k
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        int temp = arr[i];//交换arr[i]与arr[k]
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

//直接插入排序
void insertSort(int A[],int n){// n为元素的个数，数组下标从0~n-1
    for (int i = 1; i < n; ++i) {//进行n-1趟排序
        int temp=A[i],j=i;// temp临时存放A[i],j从i开始往前枚举
        while (j>0&&temp<A[j-1]){//只要temp小于前一个元素
            A[j]=A[j-1];//把A[j-1]后移至A[j]
            j--;
        }
        A[j]=temp;//插入位置为j
    }
}

int main() {
    int arr[] ={5,2,4,6,3,1};
//    selectSort(arr,6);
    insertSort(arr,6);
    for (int i = 0; i < 6; ++i) {
        printf("%d ",arr[i]);
    }

    return 0;
};
