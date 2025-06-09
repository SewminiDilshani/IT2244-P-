/*
Area Calculation Program
Circle => C
Triangle => T
Square => S 
Rectangle => R 
Enter your choice: C

Circle Area Calculation
Enter the radius: 20.9
Area is: 1371.58
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate area
float calculateArea(char shape[], float a, float b) {
    if (strcmp(shape, "circle") == 0)
        return M_PI * a * a;
    else if (strcmp(shape, "rectangle") == 0)
        return a * b;
    else if (strcmp(shape, "triangle") == 0)
        return 0.5 * a * b;
    else if (strcmp(shape, "square") == 0)
        return a * a;
    return -1; // Invalid shape
}

int main() {
    char shape[20];
    float val1, val2, area;

    printf("Enter shape (circle, rectangle, triangle, square): ");
    scanf("%s", shape);

    if (strcmp(shape, "circle") == 0 || strcmp(shape, "square") == 0) {
        printf("Enter value (radius or side length): ");
        scanf("%f", &val1);
        val2 = 0;
    } else {
        printf("Enter two values (length & width or base & height): ");
        scanf("%f %f", &val1, &val2);
    }

    area = calculateArea(shape, val1, val2);

    if (area >= 0)
        printf("Area of %s: %.2f\n", shape, area);
    else
        printf("Invalid shape entered!\n");

    return 0;
}

