import java.util.Comparator;

public class HeapSort extends ASort {

    @Override
    <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }

        int length = list.length;

        for (int i = length / 2 - 1; i >= 0; i--) {
            adjustHeap(list, comparator, i, length);
        }

        for (int i = length - 1; i >= 1; i--) {
            swap(list, i, 0);
            adjustHeap(list, comparator, 0, i);
        }
    }

    private <T> void adjustHeap(T[] list, Comparator<? super T> comparator,
            int index, int length) {
        T cur = list[index];
        for (int i = index * 2 + 1; i < length; i = 2 * i + 1) {
            if (i < length - 1 && comparator.compare(list[i], list[i + 1]) < 0) {
                // 选取右孩子
                i++;
            }
            if (comparator.compare(cur, list[i]) < 0) {
                swap(list, i, index);
                index = i;   
            } else {
                break;
            }
        }
    }

}
