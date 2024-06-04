
public class Main {
    static int maxProfit(int[] arr){
        int maxProfit = 0;
        int minVal = Integer.MAX_VALUE;

        int n = arr.length;
        for(int i = 0; i < n; i++){
            minVal = Math.min(minVal, arr[i]);
            maxProfit = Math.max(maxProfit, arr[i] - minVal);
        }
        return maxProfit;
    }
    public static void main(String[] args) {
        int[] arr = {7,1,5,3,6,4};
        System.out.println("The max Profit is " + maxProfit(arr));
    }
}
