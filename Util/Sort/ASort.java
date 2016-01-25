import java.util.Comparator;

public abstract class ASort {
    /**
     * 对数组依照comparator提供的顺序进行排序
     * @param list 待排序数组
     * @param comparator 比较器。 当compare(A, B) > 0 <=> A > B时为升序，反之为倒序。
     */
    abstract <T> void sort(T[] list, Comparator<? super T> comparator);
    <T> void swap(T[] list, int i1, int i2) {
        T temp = list[i1];
        list[i1] = list[i2];
        list[i2] = temp;
    }
}
