#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double NormalizeAngle(double ang) {
    int times360 = (int) floor(ang / 360.0);

    double angle = ang - (360 * times360);

    if (angle >= 0) {
        return angle;
    } else {
        return angle + 360;
    }
}

int main() {
    double angle;
    double realAngle;
    double radians;
    char input[100];
    char *ptr;

    printf("Hullo, mate! Lemme help you with your Trigonometry assignment!\n");
    printf("Give me the angle (degrees): ");
    fgets(input, sizeof(input), stdin);

    angle = strtod(input, &ptr);

    if (strlen(input) != strlen(ptr)) {
        realAngle = NormalizeAngle(angle);
        radians = realAngle * M_PI / 180.0;
        printf("Sin(%lf) = %lf\n", angle, sin(radians));
        printf("Cos(%lf) = %lf\n", angle, cos(radians));

        if (realAngle != 90.0 && realAngle != 270.0) {
            printf("Tan(%lf) = %lf\n", angle, tan(radians));
        } else {
            printf("Tan(%lf) is not defined\n", angle);
        }

        if (realAngle != 90.0 && realAngle != 270.0) {
            printf("Sec(%lf) = %lf\n", angle, 1/cos(radians));
        } else {
            printf("Sec(%lf) is not defined\n", angle);
        }

        if (realAngle != 0.0 && realAngle != 180.0) {
            printf("Csc(%lf) = %lf\n", angle, 1/sin(radians));
        } else {
            printf("Csc(%lf) is not defined\n", angle);
        }

        if (realAngle != 0.0 && realAngle != 180.0 && tan(radians) != 0.0) {
            printf("Ctg(%lf) = %lf\n", angle, 1/tan(radians));
        } else {
            printf("Ctg(%lf) is not defined\n", angle);
        }
    } else {
        printf("That's not a valid input, mate! I can't work with that.\n");
    }
    printf("See you around, mate!\n");

    return 0;
}