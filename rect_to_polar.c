#include <math.h>
#include <stdio.h>

#define PI 3.1415926

typedef struct
{
    double x;
    double y;
} rect;

typedef struct
{
    double len;
    double angle;
} polar;

polar rect_to_polar(rect);

int main(void)
{
    rect input;
    polar result;
    printf("(x,y) = ");
    scanf("%lf %lf", &input.x, &input.y);
    result = rect_to_polar(input);
    printf("\n(¦Ñ, ¦È) = (%.2lf, %.2lf¡ã)\n", result.len, result.angle);
    getchar();
    getchar();
    return 0;
}

polar rect_to_polar(rect r)
{
    polar p;
    p.len = sqrt(r.x * r.x + r.y * r.y);
    p.angle = (180 / PI) * atan2(r.y, r.x);
    return p;
}
