package basic;

public class MergeSort {

    /**
     * 归并排序
     * @param array
     */
    public static void sort(int[] array) {
        int length = array.length;
        sort(array, 0, length-1);
    }

    private static void sort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        sort(array, left, mid);
        sort(array, mid+1, right);
        merge(array, left, mid, right);
    }

    private static void merge(int[] array, int left, int mid, int right) {

        int[] temp = new int[right - left +1];
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right){
            if (array[i] < array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }

        while (i <= mid){
            temp[k++] = array[i++];
        }
        while (j <= right){
            temp[k++] = array[j++];
        }

        for (int index = 0; index < temp.length; index++) {
            array[left + index] = temp[index];
        }
    }

}
