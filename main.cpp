//*****************************************************Luhn algorithm*******************************************************//
// https://en.wikipedia.org/wiki/Luhn_algorithm

// Start by including the neccessary Libraries:

// the vector library enables us to use vectors. Vectors are Arrays but without a size limit and can expand themselves accodinglly.
#include <vector>
// just include this library too. Don't ask me why!!
#include <iostream>

// this line enables us to use standard types such as String or int value types, instead of adding (std::) to each type.
using namespace std;

// first of all, we have to convert the String value we get into an integer to process the credit card number.
// the function takes the string "line":
vector<int> stringToIntVector(string &line)
{

    // we start by initiating an array i.e vector, that contains integer values and call it myVector.
    vector<int> myVector;

    // this for Loop iterates through each character in the string line.
    int e = 0;
    for (int i = 0; i < line.size(); i++)
    {
        // We check if the character is a number and between 0 and 9
        if (line[i] >= '0' && line[i] <= '9')
        {
            // Add each character as a integer to the vector
            myVector.push_back(line[i] - 48);
        }
    }

    // Return our Vector.
    return myVector;
}

// Then we are going to need to reverse the vector values to ease the next steps.
// the function takes our Vector that contains Integer values:
vector<int> reverseNumber(vector<int> &creditCardNumber)
{
    // we define a Pointer for the first value in our vector and call it left.
    int left = 0;
    // then define a pointer for the last value of our vector and call it right;
    int right = creditCardNumber.size() - 1;

    // The swapping i.e reversing of the values should happen as long as the two pointer dont meet in the middle and go across.
    while (left < right)
    {
        // we assign our left value from the vector into a temporary variable.
        int temporary = creditCardNumber[left];
        // then we assign the right value from the vector to the left value of the vector
        creditCardNumber[left] = creditCardNumber[right];
        // In the end, we assign the prevoisly saved original left value to the right value.
        creditCardNumber[right] = temporary;

        // after swapping the first value in the vector with the last one, we move the pointers a step closer to the middle.
        left++;
        right--;
    }

    // Return our reversed Vector.
    return creditCardNumber;
}

// After turning our string to a Integer Vector and reversing the values, we need to double every second value in the vector.
// the function takes our vector of reversed Integer Values and doubles every second digit:
vector<int> doubleEverySecondDigit(vector<int> myVector)
{

    // this for LOop goes through every second value by starting at 1 and going i = i + 2 each turn.
    for (int i = 1; i < myVector.size(); i += 2)
    {

        // Here we multiply every second value by 2.
        myVector[i] *= 2;

        // If multiplying the number results in a number bigger than 9, we substract 9 from the result.
        if (myVector[i] > 9)
        {
            myVector[i] -= 9;
        }
    }

    // After multiplications are done, return the Vector.
    return myVector;
}

// After proccessing the numbers, we have to add them.
// this function takes a vector contains Integer values and adds them together in the sum variable:
int addNumbersTogether(vector<int> list)
{
    // Define a int variable to store the sum of all integers in the vector.
    int sum = 0;

    // Go through all the numbers in the vector and add them to our sum integer.
    for (int num : list)
    {
        sum += num;
    }

    // return the sum.
    return sum;
}

// In the main function, we proccess the number using our functions we created above.
// in this example the sum is 70, which is dividable by 10. therefore the card is valid.
int main()
{

    string myCreditCard = "79927398713";
    vector<int> myCreditCardAsIntVector = stringToIntVector(myCreditCard);

    // for (int num : myCreditCardAsIntVector)
    // {
    //     cout << num << " ";
    // }

    vector<int> myCreditCardAsIntVectorReversed = reverseNumber(myCreditCardAsIntVector);

    // for (int num : myCreditCardAsIntVectorReversed)
    // {
    //     cout << num << " ";
    // }

    vector<int> myCreditCardAsIntVectorReversedAndDoubled = doubleEverySecondDigit(myCreditCardAsIntVectorReversed);

    // for (int num : myCreditCardAsIntVectorReversedAndDoubled)
    // {
    //     cout << num << " ";
    // }

    vector<int> myCreditCardAsIntVectorReversedAndDoubledAndReversedAgain = reverseNumber(myCreditCardAsIntVectorReversedAndDoubled);

    // for (int num : myCreditCardAsIntVectorReversedAndDoubledAndReversedAgain)
    // {
    //     cout << num << " ";
    // }

    int result = addNumbersTogether(myCreditCardAsIntVectorReversedAndDoubledAndReversedAgain);

    // Finally, we check if the sum of the credit cards numbers is dividable by 10. If so, then the card is valid.
    if (result % 10 == 0)
    {
        cout << "This card is valid";
    }
    else
    {
        printf("this card is not valid");
    }

    return 0;
}
