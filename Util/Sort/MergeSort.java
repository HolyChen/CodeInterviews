import java.util.Comparator;

public class MergeSort extends ASort {
    
    @SuppressWarnings("unchecked")
    @Override
    <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }

        int length = list.length;
        Object[] temp = new Object[length];

        // 从底向上，两个一组、四个一组……逐次归并
        for (int step = 1; step < length; step <<= 1) {
            // 将一个step长度作为一个组，对连续两组进行归并
            for (int i = 0; i < length; i += step * 2) {
                // 指向第一组的第0个元素
                int indexA = i;
                // 指向第二组的第0个元素
                int indexB = i + step;
                
                int endA = i + step > length ? length : i + step;
                int endB = i + step * 2 > length ? length : i + step * 2;

                int indexTemp = i;
                // 归并
                while (indexA < endA && indexB < endB) {
                    if (comparator.compare(list[indexA], list[indexB]) < 0) {
                        temp[indexTemp] = list[indexA];
                        indexA++;
                    } else {
                        temp[indexTemp] = list[indexB];
                        indexB++;
                    }
                    indexTemp++;
                }

                while (indexA < endA) {
                    temp[indexTemp++] = list[indexA++];
                }

                while (indexB < endB) {
                    temp[indexTemp++] = list[indexB++];
                }

            }
            
            // 一趟归并完成，将temp中数据复制回list
            for (int i = 0; i < length; i++) {
                list[i] = (T)(temp[i]);
            }
        }

    }

}
