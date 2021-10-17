#include <iostream>

using namespace std;

void squarecheck(int &num); //This will be a function which will run a loop to see if the number which the user has entered is a perfectly squared number or not.

int main() {    //The main function.

    int num; //The main integer for input and output.

    cout << "Please enter a natural number: " << endl;
    cin >> num; //Here we ask the user to input a natural number.

    while (num <= 0){   //If the (int num) number is not a natural number, so num = 0, or num < 0, we ask the user to input a natural number again.
        cout <<"Please enter a natural number: " << endl;
        cin >> num;
    }
    squarecheck(num);   //Call our loop check function.
    return 0;   //Exit.
}
void squarecheck(int &num){ //We execute the loop check function here. Using a reference point (&) we ensure that we do not waste memory.

    int x = 1;  //This is our lowest possible number that we can start with for our mathematical algorithm. (x * x)
    int y = 0;  //This is an integer which shall contain the formula we will use. We initialize y to 0 so that our next loop can start indefinitely.

    while (y < num){    //We run this loop until we find the number which the user has entered. If our algorithm exceeds the inputted number the loop shall stop.
        y = x * x;
        x++;
    }

    if (y == num){  //If our loop's algorithm has found a number that is equal to the number the user has entered (y == num), then we return a positive response.
        cout << num << " is a perfectly squared number.";
    }
    else{   //If our loop's algorithm has not found a number that is equal to the number the user has entered (y != num), then we return a negative response.
        cout << num << " is not a perfectly squared number.";
    }
}