public class MinMax{

    public static int[] findMinMax(int[] arr, int low, int high, int[] result) {
        if (low == high) {
            result[0] = arr[low];
            result[1] = arr[low];
            return result;
        }

        if (high == low + 1) {
            if (arr[low] < arr[high]) {
                result[0] = arr[low];
                result[1] = arr[high];
            } else {
                result[0] = arr[high];
                result[1] = arr[low];
            }
            return result;
        }

        int mid = (low + high) / 2;
        findMinMax(arr, low, mid, result);
        int leftMin = result[0], leftMax = result[1];

        findMinMax(arr, mid + 1, high, result);
        int rightMin = result[0], rightMax = result[1];

        result[0] = Math.min(leftMin, rightMin);
        result[1] = Math.max(leftMax, rightMax);

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {3, 5, 7, 2, 8, -1, 4, 10, 12};
        int[] result = {Integer.MAX_VALUE, Integer.MIN_VALUE};

        findMinMax(arr, 0, arr.length - 1, result);
        System.out.println("Minimum: " + result[0]);
        System.out.println("Maximum: " + result[1]);
    }
}
