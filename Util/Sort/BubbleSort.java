import java.util.Comparator;

public class BubbleSort extends ASort {
    
    @Override
    public <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }
        int length = list.length;
        for (int i = length - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (comparator.compare(list[j], list[j + 1]) > 0) {
                    swap(list, j, j + 1);
                }
            }
        }
    }
}