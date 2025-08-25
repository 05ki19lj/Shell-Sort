from typing import List

class Solution:
    def shell_sort(self, arr: List[int]) -> List[int]:
        """
        使用 Shell Sort（希尔排序）对列表 arr 进行排序，返回排序后的列表。
        """
        n = len(arr)
        gap = n // 2  # 初始间隔

        # 当 gap > 0 时，不断缩小间隔进行分组插入排序
        while gap > 0:
            # 对每个间隔内（gap 分组）的元素执行插入排序
            for i in range(gap, n):
                temp = arr[i]
                j = i
                # 将比 temp 大的元素在同一分组中后移一个 gap
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp  # 插入正确的位置

            # 缩小间隔，继续下一轮分组排序
            gap //= 2

        return arr

    def sortArray(self, nums: List[int]) -> List[int]:
        """
        用于兼容题目结构：调用 shell_sort 完成排序。
        """
        return self.shell_sort(nums)

# 示例：测试排序功能
if __name__ == "__main__":
    solution = Solution()
    examples = [
        [5, 2, 3, 1],
        [5, 1, 1, 2, 0, 0],
        [9, 8, 3, 7, 5, 6, 4, 1, 2],
    ]

    for arr in examples:
        sorted_arr = solution.sortArray(arr.copy())
        print(f"原始: {arr} → 排序后: {sorted_arr}")
