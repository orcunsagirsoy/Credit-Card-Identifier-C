#include <stdio.h>
#include <unistd.h>
#include <cs50.h>
#include <math.h>


int main(void)
{


long cardNumber;
int firstgroup;
int secondgroup;
int seconds;
int secondssum = 0;
int firstsum = 0;
int totalsum;
int remainderr;
int reverse = 0;
int twoDigits = 0;
int remainderrr;

    // Initiating the input
    do
    {
        cardNumber = get_long("Credit Card Number: ");
    }
    while(cardNumber < 0);

    printf("Number: %li\n", cardNumber);


    //Applying Lhun's Algorithm
    while(cardNumber > 0)
    {
        firstgroup = cardNumber % 10;
        firstsum += firstgroup;

        cardNumber /= 10;


        secondgroup = cardNumber % 10;
        while(secondgroup > 0)
        {
            seconds = secondgroup % 10;
            secondssum += seconds;
            seconds /= 10;
        }

        cardNumber /= 10;
    }

    totalsum = firstsum + secondssum;



    //Reversing the card number

    while(cardNumber != 0)
    {
        remainderr = cardNumber % 10;
        cardNumber /= 10;
        reverse += remainderr;
        reverse *= 10;
    }

    //Finding first two digits from the last two digits of reversed number

    for(int i = 0; i < 2; i++)
    {
        remainderrr = reverse % 10;
        twoDigits *= 10;
        twoDigits += remainderrr;
        reverse /= 10;
    }



    if(totalsum % 10 == 0)
    {
        if(twoDigits == 51 || twoDigits ==  52 || twoDigits == 53 || twoDigits == 54 || twoDigits == 55)
        {
            printf("MASTERCARD\n");
        }
        else if(twoDigits/10 == 4)
        {
            printf("VISA\n");
        }
        else if(twoDigits == 34 || twoDigits == 37)
        {
            printf("AMEX\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
