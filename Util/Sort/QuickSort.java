import java.util.Comparator;

public class QuickSort extends ASort {

    @Override
    <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }
        qSort(list, 0, list.length - 1, comparator);
    }

    private <T> void qSort(T[] list, int front, int tail,
            Comparator<? super T> comparator) {
        if (front >= tail || tail >= list.length) {
            return;
        }

        T flag = list[front];
        
        int start = front, end = tail; 

        while (start < end) {
            while (start < end && comparator.compare(list[end], flag) >= 0) {
                end--;
            }
            list[start] = list[end];
            while (start < end && comparator.compare(list[start], flag) <= 0) {
                start++;
            }
            list[end] = list[start];
        }
        list[start] = flag;
        
        qSort(list, front, start - 1, comparator);
        qSort(list, start + 1, tail, comparator);
    }
}
