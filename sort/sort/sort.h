//
//  sort.h
//  sort
//
//  Created by 曾长欢 on 2022/4/19.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>

//冒泡排序    相邻两个数比较，把最符合条件放到最后的位置
void BubbleSort(int arr[], int n);

//选择排序    每一次找准一个位置，通过这个位置的值去和后面所有的值去做比较，把最满足条件的值放在这个位置
void SelectSort(int arr[], int n);

//插入排序    拿一个数和一个已序的序列做插入操作
void InsertSort(int arr[], int n);

//快速排序
void QuickSort(int arr[], int left, int right);

//希尔排序
void ShellSort(int arr[], int n);

//归并排序
void MergeSort(int arr[], int left, int right);

//归并排序中用来做合并的
void _merge_in_arr(int arr[], int left, int mid, int right);

//桶排序
void radix_sort(int arr[], size_t len);

//显示数组
void show(int arr[], int n);

//交换
void swap(int arr[], int x, int y);



#endif /* sort_h */
