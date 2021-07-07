//
// Created by 少年与梦 on 2021-05-10.
//
#include <stdlib.h>
#include <valarray>

#ifndef DATA_STRUCTURE_SEQUETAILLIST_H
#define DATA_STRUCTURE_SEQUETAILLIST_H
#define MaxSize 20//设记录不超过20个
typedef int KeyType;//设关键字为整型类型（int型）
typedef char InfoType;//其他数据域
typedef struct {//定义每个记录（数据元素）的结构
    KeyType key;//关键字
    InfoType other_info;//其他数据项
} RedType;//record type
typedef struct {//定义顺序表的结构
    RedType r[MaxSize + 1];//存储顺序表的向量//r[0]一般作为哨兵或缓冲区
    int length;//顺序表长度
} SqList;


bool InitSqList(SqList &list) {
    list.length = 0;//空表的长度初始化为0

    //构造一个空的顺序表，动态申请存储空间
    if (!list.r)return false;
    else return true;
}

//尾部insert
bool InsertSqList(SqList &list, KeyType x) {
    if (list.length == MaxSize)//表满，插入失败
        return false;
    list.r[0].key = -1;
    list.r[list.length + 1].key = x;//值存入R->key中
    list.length++;// length+1
    return true;
}

void foreach(SqList list);

bool InsertSList(SqList &list, RedType x, int index) {
    if (MaxSize == list.length || index > (list.length) || index < 1) {
        return false;
    }

    for (int i = list.length - 1; i > (index - 1); i--) {
        list.r[i + 1] = list.r[i];
    }
    list.r[index - 1] = x;
    list.length++;
    return true;
}

void foreach(SqList list) {
    printf("\n数组里的元素有：[");
    for (int i = 0; i < list.length; ++i) {
        printf("%d ", list.r[i].key);
    }
    printf("]\n数组的长度为：%d", list.length);
}

//直接插入排序--插入排序
void InsertSort(SqList &list);

//希尔排序--插入排序，不稳定的排序
void ShellInsertSort(SqList &list, int dk);

//折半插入排序--插入排序
void BinaryInsertSort(SqList &list);

//冒泡排序--交换排序
void Bubble_sort(SqList &list);

//快速排序--交换排序，不稳定的排序
void QuickSort(SqList &list, int low, int high);

//简单选择排序--选择排序--不稳定的排序
void SelectSort(SqList &list);


//直接插入排序
void InsertSort(SqList &list) {
    int i, j;
    for (i = 2; i < list.length; i++) {
        if (list.r[i].key < list.r[i - 1].key) {//若‘<'，将L.r[i]插入有序子表 //如果r[i]小于r[i-1],就将r[i]赋值到r[0](哨兵)
            list.r[0] = list.r[i];//复制为哨兵
            printf("\n第i=%d次:\n", i);
            for (j = i - 1; list.r[0].key < list.r[j].key; j--) {
                printf(" j=%d ", j);
                list.r[j + 1] = list.r[j];//记录后移
            }
            printf("\n j:%d", j);
            list.r[j + 1] = list.r[0];//插入到正确位置
        }
    }
}

//折半插入排序
void BinaryInsertSort(SqList &list) {
    int low, high, mid;
    for (int i = 2; i < list.length; ++i) {//依次插入第2~第n个元素
        list.r[0] = list.r[i];//当前插入元素到’哨兵‘位置
        low = 1;
        high = i - 1;//采用二分查找插入位置
        while (low <= high) {
            mid = (low + high) / 2;
            if (list.r[0].key < list.r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }//循环结束，high+1，为插入位置
        for (int j = i - 1; j >= high + 1; j--) {
            list.r[j + 1] = list.r[j];//移动元素
        }
        list.r[high + 1] = list.r[0];//插入到正确位置
    }
}//BinaryInsertSort
//希尔排序间距数组
/*int * GetShellArray(SqList list){
    int arr[20] ;
    int j=0;
    for (int i = 6; i >= 0; i--) {
        int t;
        if (( t=pow(2,i)-1)<list.length){
            arr[j]=t;
            j++;
        }
    }
    return arr;
}*/
//希尔排序
void ShellInsertSort(SqList &list, int dk) {
    int i, j;
//对顺序表L进行一趟增量为dk的Shell排序，dk为步长因子
    for (i = dk + 1; i <= list.length; ++i) {
        if (list.r[i].key < list.r[i - dk].key) {
            list.r[0] = list.r[i];
            j = i - dk;
            while (j > 0 && (list.r[0].key < list.r[j].key)) {
                list.r[j + dk] = list.r[j];
                j = j - dk;
            }
            list.r[j + dk] = list.r[0];
        }
    }
}

//冒泡排序
void Bubble_sort(SqList &list) {
    RedType temp;
    KeyType x;//用于交换时临时存储
    for (int m = 0; m < list.length - 1; ++m) {//总共需要跑m趟
        for (int j = 0; j < list.length - m; ++j) {
            if (list.r[j].key > list.r[j + 1].key) {//发生逆序
//              交换位置
                temp = list.r[j];
                list.r[j] = list.r[j + 1];
                list.r[j + 1] = temp;
            }
        }
    }
}

//冒泡排序--改进
void Bubble_sort_new(SqList &list) {
    RedType temp;
    int flag = 1;//flag作为是有否交换的标记
    KeyType x;//用于交换时临时存储
    for (int m = 0; m < list.length - 1 && flag == 1; ++m) {//总共需要跑m趟
        flag = 0;
        for (int j = 0; j < list.length - m; ++j) {
            if (list.r[j].key > list.r[j + 1].key) {//发生逆序
                flag = 1;//发生了交换，flag设置为1，如果本趟没有发生交换，flag保持为0
                // 交换位置
                temp = list.r[j];
                list.r[j] = list.r[j + 1];
                list.r[j + 1] = temp;
            }
        }
    }
}

int Partition(SqList &list, int low, int high) {
    list.r[0] = list.r[low];
    int pivotKey = list.r[low].key;
    while (low < high) {
        while (low < high && list.r[high].key >= pivotKey)
            high--;
        list.r[low] = list.r[high];
        while (low < high && list.r[low].key <= pivotKey)
            low++;
        list.r[high] = list.r[low];
    }
    list.r[low] = list.r[0];
    return low;
}

//快速排序
void QuickSort(SqList &list, int low, int high) {
    if (low < high) {//长度大于1

        int pivotLoc = Partition(list, low, high);

//    将L.r[low~high]一分为二，pivotloc为枢轴元素排好序的位置
        QuickSort(list, low, pivotLoc - 1);//对低子表进行递归排序
        QuickSort(list, pivotLoc + 1, high);//对高子表进行递归排序
    }
}
//简单选择排序--不稳定的排序
void SelectSort(SqList &list) {
    int k;
    RedType temp;//中间量
    for (int i = 0; i < list.length - 1; ++i) {
        k = i;
        for (int j = i + 1; j < list.length - 1; ++j) {
            if (list.r[j].key < list.r[k].key)//记录最小值的位置
                k = j;
        }
        if (k != i) {//交换
            temp=list.r[i];
            list.r[i]=list.r[k];
            list.r[k]=temp;
        }
    }
}
//堆排序
void HeapAdjust(SqList &list,int s,int m){
    /*已知R[s...m]中记录的关键字除R[s],之外均满足堆的定义，
     * 本函数调整R[s]的关键字，使其R[s...m]成为一个小根堆*/
    RedType redType=list.r[s];
    for (int i = 2*s; i < m; i*=2) {//沿key较小的孩子节点向下筛选
        if (i<m && list.r[i].key > list.r[i+1].key)
            i++;//i为key较小的节点
        if (redType.key<=list.r[i].key)//若redType.key 已经小于等于，其孩子节点的最小值，就结束循环
            break;

        list.r[s]=list.r[i];
        //redType应插在i的位置
        s=i;
    }
    list.r[s]=redType;//插入
}
void Swap(RedType &root,RedType &child){
    RedType temp;
    temp=root;
    root=child;
    child=temp;
}
void HeapSort(SqList &list){
    int i;

    for (i = (list.length-1)/2; i >=1 ;i--) {
        HeapAdjust(list,i,list.length-1);
    }
    for (int i = list.length-1; i >=1; i--) {
        Swap(list.r[1],list.r[i]);
        HeapAdjust(list,1,i-1);
     }
}

#endif //DATA_STRUCTURE_SEQUENTIAL_H
