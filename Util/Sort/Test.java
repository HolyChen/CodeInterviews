import java.util.*;

/**
 * 一个测试类。为了能够独立运行和易读性，不引入JUnit
 */
public class Test {

    public static void main(String[] args) {
        // 测试用数据量，【可进行修改】
        int length = 1000000;
        Integer[] list = new Integer[length];
        
        // 随机数选取，【可进行修改】
        Random random = new Random(47);
        for (int i = 0; i < length; i++) {
            list[i] = random.nextInt();
        }

        // 用于验证算法是否正确
        Integer[] example = Arrays.copyOf(list, length);
        Integer[] listAs = Arrays.copyOf(list, length);
        Integer[] listDes = Arrays.copyOf(list, length);

        // 这里选择不同的排序算法，【可进行修改】
        ASort sorter = new HeapSort();
        
        // 升序
        long asStart = System.currentTimeMillis();
        sort(listAs, ASCENDING, sorter);
        long asCost = System.currentTimeMillis() - asStart;

        // 降序
        long desStart = System.currentTimeMillis();
        sort(listDes, DESCENDING, sorter);
        long desCost = System.currentTimeMillis() - desStart;

        // 对照组
        Arrays.sort(example);

        // 输出格式，【可进行修改】
        System.out.println("Length: " + length + "\t Algorithem: " + sorter.getClass().getSimpleName());
        System.out.println("-------------------------");
        System.out.println("Source:");
        // System.out.println(Arrays.toString(list));
        System.out.println("-------------------------");
        System.out.println("Ascending: \t"
                + arrayEquals(example, listAs).toString().toUpperCase() + "\t CS: " + asCost + " ms");
        // System.out.println(Arrays.toString(listAs));
        System.out.println("-------------------------");
        System.out.println("Descending: \t"
                + arrayEquals(reverse(example), listDes).toString()
                        .toUpperCase() + "\t CS: " + desCost + " ms");
        // System.out.println(Arrays.toString(listDes));
    }

    static Comparator<Integer> ASCENDING = new Comparator<Integer>() {

        @Override
        public int compare(Integer o1, Integer o2) {
            return o1 - o2;
        }
    };

    static Comparator<Integer> DESCENDING = new Comparator<Integer>() {

        @Override
        public int compare(Integer o1, Integer o2) {
            return o2 - o1;
        }
    };

    static void sort(Integer[] list, Comparator<Integer> comparator,
            ASort sorter) {
        sorter.sort(list, comparator);
    }

    static Integer[] reverse(Integer[] list) {
        int length = list.length;
        for (int i = 0; i < length / 2; i++) {
            Integer temp = list[i];
            list[i] = list[length - 1 - i];
            list[length - 1 - i] = temp;
        }
        return list;
    }

    static <T> Boolean arrayEquals(T[] list1, T[] list2) {
        int length1 = list1.length;
        int length2 = list2.length;
        if (length1 != length2) {
            return false;
        }
        for (int i = 0; i < length1; i++) {
            if (!list1[i].equals(list2[i])) {
                return false;
            }
        }
        return true;
    }

}
