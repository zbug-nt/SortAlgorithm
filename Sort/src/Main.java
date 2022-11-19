import basic.*;
import com.sun.scenario.effect.Merge;
import distributed.DistributedSort;

public class Main {

    public static void main(String[] args) {
        int[] array1 = {45, 65, 12, 132, 98, 9, 78, 100};
        int[] array2 = {45, 65, 12, 132, 98, 9, 78, 100};
        int[] array3 = {45, 65, 12, 132, 98, 9, 78, 100};
        int[] array4 = {45, 65, 12, 132, 98, 9, 78, 100};
        int[] array5 = {45, 65, 12, 132, 98, 9, 78, 100};

        SelectionSort.sort(array1);
        MergeSort.sort(array2);
        QuickSort.sort(array3);
        ShellSort.sort(array4);
        RadixSort.sort(array5);

        System.out.println("选择排序：");
        for (int i : array1) {
            System.out.print(i+", ");
        }
        System.out.println("\n归并排序：");
        for (int i : array2) {
            System.out.print(i+", ");
        }
        System.out.println("\n快速排序：");
        for (int i : array3) {
            System.out.print(i+", ");
        }
        System.out.println("\n希尔排序：");
        for (int i : array4) {
            System.out.print(i+", ");
        }
        System.out.println("\n基数排序：");
        for (int i : array5) {
            System.out.print(i+", ");
        }

        // 分布式排序
//        DistributedSort.sort();

    }
}
