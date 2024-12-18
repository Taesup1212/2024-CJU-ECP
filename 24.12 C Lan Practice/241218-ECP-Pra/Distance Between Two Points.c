#include <stdio.h>
#include <math.h>

// Define a structure to represent a 3D point
typedef struct _Point3D
{
    double x;
    double y;
    double z;
} Point3D;

// Function to calculate the Euclidean distance between two points
double calculateDistance(const Point3D* p1, const Point3D* p2) 
{
    // Calculate the difference between corresponding coordinates
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;

    // Return the square root of the sum of squared differences
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() 
{
    // Declare an array of 3D points
    Point3D points[2];

    // Use pointers to access array elements
    Point3D* p1 = &points[0];
    Point3D* p2 = &points[1];

    // Input: Collect coordinates for the two points
    printf("Enter coordinates for Point 1 (x y z): ");
    scanf("%lf %lf %lf", &p1->x, &p1->y, &p1->z);

    printf("Enter coordinates for Point 2 (x y z): ");
    scanf("%lf %lf %lf", &p2->x, &p2->y, &p2->z);

    // Calculate the distance
    double distance = calculateDistance(p1, p2);

    // Output: Display the distance
    printf("\n[Distance Between Two Points]\n%.2f\n", distance);

    return 0;
}