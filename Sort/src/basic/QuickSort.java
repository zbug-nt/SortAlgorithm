package basic;

public class QuickSort {

    /**
     * 快速排序
     * @param array
     */
    public static void sort(int[] array) {
        int length = array.length;
        quickSort(array, 0, length - 1);
    }

    private static void quickSort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot = array[left];
        int l = left;
        int r = right;
        int temp;
        while(l < r) {
            while (l < r && array[r] >= pivot) {
                r--;
            }
            while (l < r && array[l] <= pivot) {
                l++;
            }
            if (l < r) {
                temp = array[l];
                array[l] = array[r];
                array[r] = temp;
            }
        }
        array[left] = array[l];
        array[l] = pivot;

        quickSort(array, left, l - 1);
        quickSort(array, r + 1, right);
    }




}
