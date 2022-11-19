package distributed;

import basic.MergeSort;
import basic.QuickSort;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;

public class DistributedSort {

    public static void sort() {
        List<int[]> arrayList = new ArrayList<>();
        int threadNum = 10;
        for (int i = 0; i < threadNum; i++) {
            arrayList.add(DateOperator.initData());
        }

        CountDownLatch latch = new CountDownLatch(threadNum);
        for (int[] ints : arrayList) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    // 快排
                    QuickSort.sort(ints);
                    // 归并
//                    MergeSort.sort(ints);
                    latch.countDown();
                }
            }).start();
        }
        try {
            latch.await();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        DateOperator.mergeAndWriteToFile(arrayList);
    }

}
