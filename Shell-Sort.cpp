#include <stdio.h>

// 輔助函式：印出陣列
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 希爾排序（帶過程輸出）
void shell_sort(int arr[], int n) {
    int gap, i, j, temp, step = 1;

    // 初始化 gap，逐步縮小
    for (gap = n / 2; gap > 0; gap /= 2) {
        printf("\n--- 當前 gap = %d ---\n", gap);

        // 遍歷子序列中的元素
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // 在子序列中做插入排序
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;

            // 顯示每次插入後的狀態
            printf("步驟 %d: ", step++);
            print_array(arr, n);
        }
    }
}

int main() {
    int arr[] = { 9, 8, 3, 7, 5, 6, 4, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列: ");
    print_array(arr, n);

    shell_sort(arr, n);

    printf("\n最終排序結果: ");
    print_array(arr, n);

    return 0;
}
