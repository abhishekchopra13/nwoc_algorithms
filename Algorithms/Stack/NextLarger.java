<!-- 
Find NextLargerElement
Language Used: JAVA

Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input format: The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output format: For each test case, print in a new line, the next greater element for each array element separated by space in order.

Sample Input:
2
4
1 3 2 4
4
4 3 2 1

Sample Output:
3 4 4 -1
-1 -1 -1 -1

-->
 

import java.util.*;

class NextLarger{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    int testcases = scan.nextInt();
    while(testcases -- > 0)
    {
      int size = scan.nextInt();
      int array[] = new int[size];
      
      for(int i=0;i<size;i++)
      {
        array[i]=scan.nextInt();
      }
      
      int result[] = new int[size];
      int index=0;
      result[index++]=-1;
      
      Stack<Integer>stack = new Stack<Integer>();
      stack.push(array[size-1]);
      
      for(int i=size-2;i>=0;i--)
      {
        while(!stack.isEmpty() && stack.peek()<=array[i])
        {
          stack.pop();
        }
        if(!stack.isEmpty() && stack.peek()>array[i])
        {
          result[index++]=stack.peek();
        }
        else
        {
          result[index++]=-1;
        }
        stack.push(array[i]);
      }
      
      for(int i=index-1;i>=0;i--)
      {
        if(i==0)
          System.out.print(result[i]);
        else
        System.out.print(result[i]+" ");
      }
      
      System.out.println();
    }
  }
}
