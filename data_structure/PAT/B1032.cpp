//
// Created by 少年与梦 on 2021-07-07.
//
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

typedef struct Person {
    int id;//学校编号
    int scope;//分数
    char name[10];//选手姓名
    int age;//选手年龄

} Person;

/*
 * 输入在第 1 行给出不超过 10^5的正整数 N，即参赛人数。
 * 随后 N 行，每行给出一位参赛者的信息和成绩，
 * 包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），
 * 中间以空格分隔。
 * */
int main() {
    const int max = 100010;
    int school[max];//用于记录学校的总分
    int n, schoolId, score;
    scanf("%d \n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &schoolId, &score);//学校的id和分数
        school[schoolId] += score;//学校schoolId的总分和
    }
    int k = 1;
    int Max = -1;
    for (int i = 1; i <= n; ++i) {
        if (school[i] > Max) {
            Max = school[i];
            k = i;
        }
    }
    printf("%d %d", k, Max);//输出最高分的学校ID及其总分
    return 0;
}