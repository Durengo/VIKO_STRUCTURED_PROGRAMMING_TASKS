# structured-programming-tasks-Durengo
structured-programming-tasks-Durengo created by GitHub Classroom

Problem URL https://leetcode.com/problems/valid-perfect-square/

Problem No. 367 Valid Perfect Square

Given a positive integer number, write a function which returns True if number is a perfect square else False.

Our program calculates if the entered number can be a perfectly squared number.
To check our answer we will use a loop and use a number which we will multiply by itself, starting from 1, and after each loop we will add 1 to it. We will run this loop until we get the number the user entered or terminate the loop if it exceeds the entered number.

Such a calculation uses natural numbers to check for our answer.

Since we are using natural numbers then we only need to use integers.

Data / variables used:

1. Input: num
2. Void function square check: 1. int x; 2. int y = x * x; - both are used in our loop calculation
3. Output: Is num squared: num is a perfect square or num is not a perfect square

Formulas/Function:

1. Calculate the square root of the given number without using sqrt function. 
    Use while loop; square up (x * x) each number (starting from 1) until we get the entered 
value; stop the loop if the squared up value (x * x) exceeds the entered number (y > num);

Algorithm design:
1. User inputs a natural number.
2. If user doesn't input a natural number return to 1.
3. Program calls function squarecheck.
4. Function squarecheck runs a loop check against the given number.
5. Program displays on screen if the given number is a perfect square.
