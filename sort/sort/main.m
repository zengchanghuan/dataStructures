//
//  main.m
//  sort
//
//  Created by 曾长欢 on 2022/4/19.
//

#import <Foundation/Foundation.h>
#import "sort.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int arr[15];  // = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
        for (int i = 0; i < 15; i++)
        {
            arr[i] = rand() % 120;
        }
        show(arr, 15);
        BubbleSort(arr, 15);
        show(arr, 15);
    }
    return 0;
}
