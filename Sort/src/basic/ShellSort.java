package basic;

public class ShellSort {

    /**
     * 希尔排序
     * @param array
     */
    public static void sort(int[] array) {
        int length = array.length;
        // 步长逐步/2
        for (int gap = length / 2; gap > 0; gap /= 2) {
            // 默认gap前面的为有序的（即每组的第一个数为有序的）
            for(int i = gap; i < length; i++) {
                //定义待排序的下标
                int insertIndex = i;
                //定义待排序的数
                int insertVal = array[insertIndex];
                while(insertIndex - gap >= 0 && insertVal < array[insertIndex-gap]) {//说明还没有找到插入的位置
                    array[insertIndex] = array[insertIndex-gap];//后移
                    insertIndex-=gap;//接着向前找
                }
                //跳出循环，说明找到位置了
                array[insertIndex] = insertVal;
            }
        }
    }


}
