#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS_PER_FILE 10 // Maximum number of students per file (파일당 최대 학생 수)

// Define subjects as an enum (과목 열거형 정의)
typedef enum { KOREAN, ENGLISH, MATH, SCIENCE } Subject;

// Structure for student information (학생 정보 구조체 정의)
typedef struct
{
    char name[50];         // Student name (이름)
    int division;          // Class division (분반)
    int id;                // Student ID (학번)
    int scores[4];         // Scores for each subject (과목별 점수)
    float average;         // Average score (평균 점수)
    int division_rank;     // Class division rank (분반 등수)
    int overall_rank;      // Overall rank (전체 등수)
} Student;

// Function prototypes (함수 프로토타입 선언)
void read_students_from_file(const char* filename, Student* students, int* count, int division);
void calculate_ranks(Student* students, int count);
void sort_by_average(Student* students, int count);
void print_students_for_class(const Student* students, int count, int division, const char* filename);
void save_class_results(const Student* students, int count, const char* filename);

int main()
{
    Student students[MAX_STUDENTS_PER_FILE * 2]; // Combined student array for both classes
    int count = 0;

    // Read students from files
    read_students_from_file("students_1.txt", students, &count, 1); // Class 1
    read_students_from_file("students_2.txt", students, &count, 2); // Class 2

    // Calculate ranks
    calculate_ranks(students, count);

    // Sort by average score
    sort_by_average(students, count);

    // Print students' information for each class and save to files
    printf("Saving student results...\n");
    print_students_for_class(students, count, 1, "1-students_1_results.txt"); // Class 1
    print_students_for_class(students, count, 2, "2-students_2_results.txt"); // Class 2

    // Save class results (class average, class rank, overall average)
    save_class_results(students, count, "3-class_results.txt");

    return 0;
}

void read_students_from_file(const char* filename, Student* students, int* count, int division)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s %d %d %d %d %d", students[*count].name, &students[*count].id, &students[*count].scores[KOREAN], &students[*count].scores[ENGLISH], &students[*count].scores[MATH], &students[*count].scores[SCIENCE]) == 6)
    {
        students[*count].division = division; // Assign division (분반 설정)

        // Calculate average directly while reading
        students[*count].average = (students[*count].scores[KOREAN] + students[*count].scores[ENGLISH] + students[*count].scores[MATH] + students[*count].scores[SCIENCE]) / 4.0;
        (*count)++;
        if (*count >= MAX_STUDENTS_PER_FILE * 2) break; // Limit the number of students
    }

    fclose(file);
}

void calculate_ranks(Student* students, int count)
{
    // Calculate overall ranks
    for (int i = 0; i < count; i++)
    {
        int overall_rank = 1;
        for (int j = 0; j < count; j++)
        {
            if (students[j].average > students[i].average)
            {
                overall_rank++;
            }
        }
        students[i].overall_rank = overall_rank;
    }

    // Calculate division ranks
    for (int i = 0; i < count; i++)
    {
        int division_rank = 1;
        for (int j = 0; j < count; j++)
        {
            if (students[i].division == students[j].division && students[j].average > students[i].average)
            {
                division_rank++;
            }
        }
        students[i].division_rank = division_rank;
    }
}

void sort_by_average(Student* students, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students_for_class(const Student* students, int count, int division, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (!file)
    {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    // Print header
    fprintf(file, "ID\t\tName\t\tKorean\t\tEnglish\t\tMath\t\tScience\t\tAverage\t\tDivision Rank\t\tOverall Rank\n\n");

    // Print students only from the specified division
    for (int i = 0; i < count; i++)
    {
        if (students[i].division == division)
        {
            fprintf(file, "%d\t\t%s\t%d\t\t\t%d\t\t\t%d\t\t%d\t\t\t%.2f\t\t\t%d\t\t\t\t%d\n",
                students[i].id,
                students[i].name,
                students[i].scores[KOREAN],
                students[i].scores[ENGLISH],
                students[i].scores[MATH],
                students[i].scores[SCIENCE],
                students[i].average,
                students[i].division_rank,
                students[i].overall_rank);
        }
    }

    fclose(file);
}

void save_class_results(const Student* students, int count, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (!file)
    {
        perror("Failed to open class results file");
        exit(EXIT_FAILURE);
    }

    float total_average = 0.0;
    float class_1_average = 0.0, class_2_average = 0.0;
    int class_1_count = 0, class_2_count = 0;

    // Calculate overall class averages
    for (int i = 0; i < count; i++)
    {
        total_average += students[i].average;
        if (students[i].division == 1)
        {
            class_1_average += students[i].average;
            class_1_count++;
        }
        else if (students[i].division == 2)
        {
            class_2_average += students[i].average;
            class_2_count++;
        }
    }

    total_average /= count;
    class_1_average /= class_1_count;
    class_2_average /= class_2_count;

    // Write results to file
    fprintf(file, "Division 1 Average: %.2f\n", class_1_average);
    fprintf(file, "Division 1 Rank: %d\n\n", class_1_count);  // Assuming rank is the number of students in the class
    fprintf(file, "Division 2 Average: %.2f\n", class_2_average);
    fprintf(file, "Division 2 Rank: %d\n\n\n\n", class_2_count);  // Assuming rank is the number of students in the class
    fprintf(file, "Overall Average: %.2f", total_average);

    fclose(file);
}