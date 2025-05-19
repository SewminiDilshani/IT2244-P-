//Enter your age and verify your aligible or not for election voting

#include<stdio.h>
int main(){
        int age;
        printf("Enter your age: ");
        scanf("%d",&age);
        if(age<0){
                printf("Invalid Input..\n");
        }
        else if(age>18){
                printf("Elegible for Voting.\n");
        }
		else{
			    printf("Not Elegible for Voting.\n");
		}
        return 0;
}

/*
Using Ternary Operator
test_condition ? expression1 : expression2 ; 
*/

#include<stdio.h>
int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    // Ternary operator for checking eligibility
    age < 0 ? printf("Invalid Input..\n") :
    (age > 18 ? printf("Eligible for Voting.\n") : printf("Not Eligible for Voting.\n"));

    return 0;
}
