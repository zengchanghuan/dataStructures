//
//  sort.c
//  sort
//
//  Created by 曾长欢 on 2022/4/19.
//

#include "sort.h"
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j + 1, j);
            }
        }
    }
}
void SelectSort(int arr[], int n) {
    
}
void InsertSort(int arr[], int n) {
    
}
void QuickSort(int arr[], int left, int right) {
    
}
void ShellSort(int arr[], int n) {
    
}
void MergeSort(int arr[], int left, int right) {
    
}
void _merge_in_arr(int arr[], int left, int mid, int right) {
    
}
void radix_sort(int arr[], size_t len) {
    
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
