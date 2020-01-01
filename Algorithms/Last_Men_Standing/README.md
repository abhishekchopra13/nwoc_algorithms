# **Last Men Standing**
A king gathers all his men in the kingdom who are to be sentenced to death for their crimes. He gathers all the criminals in a circle and gives his sword to one man. The man with the sword kills the man to his left and passes the sword to the dead man's left. Find the last two men standing. <br/> **The user inputs the number of criminals(N).** <br/> For simplicity, assume that the criminals are numbered in the anticlockwise direction and there are more than 2 prisoners.

## **How to solve?**
The basic solution or the first thing that comes to the mind upon reading the problem statement is to use either an array or better, a circular linked list as our answers will vary depending on whether **N** is even or odd. But if we look closely, we will find a pattern which can easily be represented as a mathematical formula and hence can be reduced to be solved in linear or constant time and space.

## **Input Format**
The input consists of one line.\
There will be a single integer N, which is the number of criminals.
## **Output Format**
The criminal number(s) that stay alive.

## **Sample Input**
9 
## **Sample Output**
3 &nbsp; 7

## **Time Complexity**
The time complexity is linear for large values of N (as we are using only one loop). It can be considered to be almost constant for small values of N.
