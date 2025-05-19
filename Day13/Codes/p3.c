/*Write a code for small astrology based on your life path number for that get 
date of from user then calculate life path number.(use switch case)
Ex:
Date: 23
Calculation for life path number:
                  a=date%10
				  b=date/10
				  c=a+b
If life path number:
                  1:Lucky
				  2:Carefuly do your work
				  3:Storger
				  4:Happy
				  5:Can get help
				  6:Doubt
				  7:Sad
				  8:Like
				  9:Courage  */
			

#include<stdio.h>
int main() {
    int date, a, b, c, d, e, f;

    printf("Date: ");
    scanf("%d", &date);

    // Calculate life path number
    a = date % 10;  // Get last digit of the date
    b = date / 10;  // Get first digit(s)
    c = a + b;      // Sum of digits
    
    // Break down the sum to get the final life path number
    d = c % 10;     // Get last digit of c
    e = c / 10;     // Get first digit of c
    f = d + e;      // Sum of the digits of c to get final life path number

    printf("Calculation for life path number: %d\n", f);

    // Astrology message based on life path number
    switch(f) {
        case 1:
            printf("Lucky\n");
            break;
        case 2:
            printf("Carefully do your work\n");
            break;
        case 3:
            printf("Stronger\n");
            break;
        case 4:
            printf("Happy\n");
            break;
        case 5:
            printf("Can get help\n");
            break;
        case 6:
            printf("Doubt\n");
            break;
        case 7:
            printf("Sad\n");
            break;
        case 8:
            printf("Like\n");
            break;
        case 9:
            printf("Courage\n");
            break;
        default:
            printf("Invalid life path number.\n");
    }

    return 0;
}



