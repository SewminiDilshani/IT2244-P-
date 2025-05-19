/*Write C program that:
Accepts two strings as input from the user.
Concatenates the two strings display the concatenates result.*/

#include<stdio.h>
#include<string.h>

int main() {
    char str1[100], str2[100];

    // Accept two strings as input from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the newline character from the strings if present
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate str2 to str1
    strcat(str1, str2);

    // Display the concatenated result
    printf("Concatenated String: %s\n", str1);

    return 0;
}
