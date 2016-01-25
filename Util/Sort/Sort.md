## 常用排序算法（Java实现）

包括以下排序算法
- 冒泡排序
- 选择排序
- 插入排序
- 希尔排序
- 堆排序（非递归）
- 快速排序（递归）
- 归并排序（非递归）
以及一个测试类
- Test

在Test中可以更改不同的参数来设置数组长度、以及排序算法。也可以根据喜好设置输出格式。

类关系如下：
``` plain
-----------------
|     ASort     |
|       |       | 
|       ^       | 
|       |       |
|   BubbleSort  |
|   SelectSort  |    ------------->  Test
|   InsertSort  |
|   ShellSort   |
|   HeapSort    |
|   QuickSort   |
|   MergeSort   |
-----------------
```
