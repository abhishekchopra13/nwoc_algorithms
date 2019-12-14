// InfixToPostfix Conversion
// Language Used: JAVA

// Given an infix expression in the form of a string str. Convert this infix expression to postfix expression.
// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

// Input format: The first line of input contains an integer T denoting the number of test cases. The next T lines contains an infix expression.
//		 The expression contains all characters and ^,*,/,+,-.
// Output format: For each testcase, in a new line, output the infix expression to postfix expression.

//  Sample Input:
//  2                         Denoting no. of test cases.
//  a+b*(c^d-e)^(f+g*h)-i
//  A*(B+C)/D

//  Sample Output:
//  abcd^e-fgh*+^*+i-
//  ABC+*D/


import java.util.*;

class InfixToPostfix{
    
    public static int precision(char operator)
    {
        switch(operator)
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
