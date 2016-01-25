import java.util.Comparator;

public class ShellSort extends ASort {

    @Override
    <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }

        int length = list.length;

        int step = length >> 1;
        // step变为不大于length的2^n - 1位数，大部分为质数
        step |= step >> 1;
        step |= step >> 2;
        step |= step >> 4;
        step |= step >> 8;
        step |= step >> 16;
        step = step <= 0 ? 1 : step;

        for (; step > 0; step >>= 1) {

            for (int i = step; i < length; i++) {
                T cur = list[i];
                int j = i - step;
                while (j >= 0
                        && comparator.compare(cur, list[j]) < 0) {
                    j -= step;
                }
                // 此处为新元素位置
                j += step;
                for (int k = i; k > j; k -= step) {
                    list[k] = list[k - step];
                }
                list[j] = cur;
            }

        }
    }

}
