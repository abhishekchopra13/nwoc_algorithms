
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
    public static int precision(char a)
    {
        switch(a)
        {
            case '^':
                return 3;
            case '/':
            case '*':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }
    
	public static void main (String[] args) {
    	Scanner scan = new Scanner(System.in);
    	int testcase = scan.nextInt();
    	while(testcase -- > 0)
    	{
    	    String infix = scan.next();
    	    infix+=")";
    	    Stack<Character>stack = new Stack<Character>();
    	    stack.push('(');
    	    
    	    String postfix="";
    	    int i=0;
    	    while(!stack.isEmpty())
    	    {
    	        if( infix.charAt(i)=='(' )
    	        stack.push('(');
    	        else if( infix.charAt(i)==')' )
    	        {
    	            while( stack.peek()!='(' )
    	            {
    	                postfix+=stack.pop();
    	            }
    	            stack.pop();
    	        }
    	        else if( Character.isLetter( infix.charAt(i) ) )
    	        {
    	            postfix+=infix.charAt(i);
    	        }
    	        else
    	        {
    	            while( precision(stack.peek()) >= precision( infix.charAt(i) ) )
    	            {
    	                postfix+=stack.pop();
    	            }
    	            stack.push( infix.charAt(i) );
    	        }
    	        
    	        i++;
    	    }
    	    
    	    
    	    System.out.println(postfix);
    	    
    	}
    }
}