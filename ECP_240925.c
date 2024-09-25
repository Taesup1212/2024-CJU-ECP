/*
#include <stdio.h>

int main(void)
{
    int a;

    scanf("%d", &a);
    printf("input result : %d\n", a);

    return 0;
}
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
#include <stdio.h>

int main(void)
{
    int age;
    double height;

    printf("input your age and height : ");
    scanf("%d%lf", &age, &height);
    printf("age is %d, height is %1lfcm\n", age, height);

    return 0;
}
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>

int main(void)
{
    char strName[20];
    char chMaleFemale;
    int nAge = 0;
    double dHeight = 0.0;
    printf("Input your information(age, male/female, height):\n");
    scanf("%d %c %s %lf", &nAge, &chMaleFemale, sizeof(chMaleFemale), strName, sizeof(strName), &dHeight);
    printf("Result(age, male/female, height):(%d, %c, %s, %.2lf)\n", nAge, chMaleFemale, strName, dHeight);
    return 0;
}