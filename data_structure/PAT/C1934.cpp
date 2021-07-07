//
// Created by 少年与梦 on 2021-07-07.
//
#include "stdio.h"
#include "stdlib.h"
/*
 * 输入一个数 n（1<=n<=200）,然后输入n个不同的数值，
 * 在输入一个值 x，
 * 输出这个值在数组中的下标（从0开始，不存在，则返回-1）
 * */
const int max=200;

int main(){
    int n;
   scanf("%d",&n);
    int a[n];//存放n的个数
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);//向数组中输入数据
    }
//    输入要查找的数
    int x;
    scanf("%d",&x);
    int min=0,mid,max=n;
    while (a[mid]!=x){
        mid=(min+max)/2;
        if(a[mid]>x){
            max=mid-1;
        }
        if(a[mid]<x){
            min=mid+1;
        }
        if(min>max){
            break;
        }
    }
    if(mid>=0 && mid<=n-1){
        printf("\n%d",mid);
    } else{
        printf("%d",-1);
    }
    return 0;
}
