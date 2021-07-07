//
// Created by 少年与梦 on 2021-05-09.
//

#ifndef DATA_STRUCTURE_SQLIST_H
#define DATA_STRUCTURE_SQLIST_H
typedef  int KeyType ;
#define MaxSize 10
typedef struct {
    KeyType key;
}ElemType;
typedef struct {
    ElemType *R;//基地址
    int length;//表长
    int size;

}SqList;//Sequential List
//初始化表
bool InitSqList(SqList &list){
    list.length=0;//空表的长度初始化为0
    list.size=MaxSize;
    list.R= (ElemType *)(malloc(list.size * sizeof(ElemType)));//构造一个空的顺序表，动态申请存储空间
    if (!list.R)return false;
    else return true;
}
//尾部insert
bool InsertSqList(SqList &list,KeyType x){
    if(list.length==list.size)//表满，插入失败
        return false;
    list.R[list.length].key=x;//值存入R->key中
    list.length++;// length+1
    return true;
}
void foreach(SqList list);
bool InsertSList(SqList &list,ElemType x,int index){
    if(list.size==list.length||index>(list.length)||index<1){
        return false;
    }

    for (int i = list.length-1; i >(index-1) ; i--) {
        list.R[i+1]=list.R[i];
    }
    list.R[index-1]=x;
    list.length++;
    return true;
}
void foreach(SqList list){
    printf("\n数组里的元素有：[");
    for (int i = 0; i < list.length; ++i) {
        printf("%d ",list.R[i].key);
    }
    printf("]\n数组的长度为：%d",list.length);
}
int BinarySearch(SqList list,int x){
    int low=0,mid;
    int high=list.length-1;
    while (low<=high){
        mid=(low+high)/2;
        if(list.R[mid].key==x){
            return mid;
        }
        if (list.R[mid].key>x){
            high=mid-1;
        }
        if (list.R[mid].key<x){
            low=mid+1;
        }
    }
    return -1;
}
#endif //DATA_STRUCTURE_SQLIST_H
