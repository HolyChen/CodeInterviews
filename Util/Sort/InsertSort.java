import java.util.Comparator;

public class InsertSort extends ASort {

    @Override
    public <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }
        int length = list.length;
        for (int i = 1; i < length; i++) {
            int j = i - 1;
            T cur = list[i];
            while (j >= 0 && comparator.compare(cur, list[j]) < 0) {
                j--;
            }
            // 此处为新元素的位置
            j++;
            for (int k = i; k > j; k--) {
                list[k] = list[k - 1];
            }
            list[j] = cur;

        }
    }
}
