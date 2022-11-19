package basic;

import java.util.ArrayList;
import java.util.List;

public class RadixSort {

    /**
     * 基数排序
     * @param array
     */
    public static void sort(int[] array) {
        int length = array.length;
        if (array.length < 2) return;
        //根据最大值算出位数
        int max = array[0];
        for (int temp : array) {
            if (temp > max) {
                max = temp;
            }
        }
        //算出位数digit
        int maxDigit = 0;
        while (max != 0) {
            max /= 10;
            maxDigit++;
        }
        //创建桶并初始化
        ArrayList<List<Integer>> bucket = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            bucket.add(new ArrayList<>());
        }
        //按照从右往左的顺序，依次将每一位都当做一次关键字，然后按照该关键字对数组排序，每一轮排序都基于上轮排序后的结果
        int mold = 10;//取模运算
        int div = 1;//获取对应位数的值
        for (int i = 0; i < maxDigit; i++, mold *= 10, div *= 10) {
            for (int j = 0; j < array.length; j++) {
                //获取个位/十位/百位......
                int num = (array[j] % mold) / div;
                //把数据放入到对应的桶里
                bucket.get(num).add(array[j]);
            }
            //把桶中的数据重新写回去，并把桶的元素清空，开始第二轮排序
            int index = 0;
            for (int k = 0; k < bucket.size(); k++) {
                //桶中对应的数据
                List<Integer> list = bucket.get(k);
                for (int m = 0; m < list.size(); m++) {
                    array[index++] = list.get(m);
                }
                //清除桶
                bucket.get(k).clear();
            }
        }
    }

}
