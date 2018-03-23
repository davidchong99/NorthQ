package q1;

import java.util.ArrayList;
import java.util.Arrays;

public class RemoveDuplicate {
	private static int bucketLength = 0;
	
	public static boolean isDuplicateN(int[] bucket, int a, int n) {
		// record the occurrence of each element
		bucket[a]++;
		
		// return true if the n-th duplicate is found
		if (bucket[a] == n) {
			return true;
		}else {
			return false;
		}
	}
	
	public static void printUsage() {
		System.out.println("Usage: RemoveDuplicate <Array length> <N-th duplicate> <Elements of array>");
		System.out.println("Example: RemoveDuplicate 10 3 1 2 2 3 5 2 4 5 5 2");
		System.exit(1);
	}
	
	public static void main(String args[]) {
		// 1st check for correct usage
		if (args.length < 1) {
			printUsage();
		}
		
		int numElements = Integer.parseInt(args[0]);
		
		// 2nd check for correct usage
		if (args.length < numElements + 2) {
			printUsage();
		}
		
		int n = Integer.parseInt(args[1]);
		int[] inputArr=new int[numElements];
		for(int i=0; i <numElements; ++i){
            inputArr[i] = Integer.parseInt(args[i+2]);
        }
		
		System.out.println("Input: ");
		// ArrayList input for print out of user input
		ArrayList<Integer> input = new ArrayList<Integer>();
		for (int i=0; i<inputArr.length; i++)
		{
		    input.add(inputArr[i]);
		}
		System.out.println(Arrays.toString(input.toArray()));
		
		// ArrayList to hold the result
		ArrayList<Integer> result = new ArrayList<Integer>();
		
		// Find the max value in the array
		int maxElement = inputArr[0];
		for (int x = 1; x <= inputArr.length - 1; ++x) {
			if (inputArr[x] > maxElement) {
				maxElement = inputArr[x];
			}
		}
		
		// Assume an arbitrary large number for the bucket array length
		bucketLength = maxElement + inputArr.length;
		int[] bucket = new int[bucketLength];
		
		for (int i = 0; i < inputArr.length; i++) {
			if (!isDuplicateN(bucket, inputArr[i], n)) {
				result.add(inputArr[i]);
			}
				
		}
		System.out.println("Output:");
		System.out.println(Arrays.toString(result.toArray()));
	}

}
