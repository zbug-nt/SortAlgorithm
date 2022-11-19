package basic;

public class SelectionSort {

    /**
     * 选择排序
     * @param array
     */
    public static void sort(int[] array) {
        int length = array.length;
        int index;
        for (int i = 0; i < length; i++) {
            index = i;
            for (int j = i+1; j < length; j++) {
                if (array[j] < array[index]) {
                    index = j;
                }
            }
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }

}
