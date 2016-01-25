import java.util.Comparator;


public class SelectSort extends ASort {

    @Override
    <T> void sort(T[] list, Comparator<? super T> comparator) {
        if (list == null || list.length <= 1) {
            return;
        }
        
        int length = list.length;
        
        for (int i = length - 1; i >= 1; i--) {
            T extremum = list[0];
            int extreIndex = 0;
            for (int j = 1; j <= i; j++) {
                if (comparator.compare(list[j], extremum) > 0) {
                    extreIndex = j;
                    extremum = list[j];   
                }
            }
            swap(list, extreIndex, i);
        }
        
    }

}
