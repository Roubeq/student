#include <stdio.h>
#include <math.h>

int main() {
    double u = 0;
    double max = 0;
    for (double x = 1; x <= 3; x += 1.3) {
        for (double y = 2; y <= 4; y += 1.3)   {
            for (double z = 0.5; z <= 1.5; z += 0.8) {
                u = (sqrt((pow(y,2)) + ((4*pow(x,2))/3)) + ((5 * pow(cos(x*y),4))/(x*z)));
                printf("x - %f, y - %f, z - %f, u - %f\n",x,y,z,u);
                if (u > max) {
                    max = u;
                }
            }
        }  
    }
    printf("MAX U = %f",max);
    return 0;
}
