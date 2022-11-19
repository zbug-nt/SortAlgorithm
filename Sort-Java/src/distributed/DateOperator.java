package distributed;

import java.io.*;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DateOperator {

    // 数值范围 200万以内
    private final static int DATA_RANGE = 2_000_000;
    // 数组大小 15万
    private final static int DATA_SIZE = 150_000;

    /**
     * 生成数据
     */
    public static int[] initData() {
        int[] array = new int[DATA_SIZE];
        Random random = new Random();
        for (int i = 0; i < DATA_SIZE; i++) {
            array[i] = (int) (random.nextDouble() * DATA_RANGE);
        }
        return array;
    }

    public static void mergeAndWriteToFile(List<int[]> data) {
        List<Integer> indexList = new ArrayList<>();
        data.forEach(i -> indexList.add(0));

        String path = "distributedSort.txt";
        File file = new File(path);
        FileOutputStream fileOutputStream = null;
        try {
            fileOutputStream = new FileOutputStream(file);
            int num = 1;
            while (num <= DATA_SIZE * data.size()) {
                int dataToWrite = Integer.MAX_VALUE;
                int indexToUp = 0;
                for (int i = 0; i < data.size(); i++) {
                    int[] ints = data.get(i);
                    Integer tIndex = indexList.get(i);
                    if (tIndex >= DATA_SIZE) continue;
                    int intValue = ints[indexList.get(i)];
                    if (intValue < dataToWrite) {
                        dataToWrite = intValue;
                        indexToUp = i;
                    }
                }
                indexList.set(indexToUp, indexList.get(indexToUp)+1);
                fileOutputStream.write((dataToWrite+" ").getBytes());
                if (num % 20 == 0) {
                    fileOutputStream.write("\n".getBytes());
                }
                num++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (fileOutputStream != null) {
                try {
                    fileOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }



}
