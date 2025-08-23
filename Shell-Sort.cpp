#include <stdio.h>

// ���U�禡�G�L�X�}�C
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �ƺ��Ƨǡ]�a�L�{��X�^
void shell_sort(int arr[], int n) {
    int gap, i, j, temp, step = 1;

    // ��l�� gap�A�v�B�Y�p
    for (gap = n / 2; gap > 0; gap /= 2) {
        printf("\n--- ��e gap = %d ---\n", gap);

        // �M���l�ǦC��������
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // �b�l�ǦC�������J�Ƨ�
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;

            // ��ܨC�����J�᪺���A
            printf("�B�J %d: ", step++);
            print_array(arr, n);
        }
    }
}

int main() {
    int arr[] = { 9, 8, 3, 7, 5, 6, 4, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("��l�}�C: ");
    print_array(arr, n);

    shell_sort(arr, n);

    printf("\n�̲ױƧǵ��G: ");
    print_array(arr, n);

    return 0;
}
