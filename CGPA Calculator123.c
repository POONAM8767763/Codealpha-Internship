#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course
{
    string name;
    float credits;
    float grade;
};

int main() 
{
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    float totalCredits = 0;
    float totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) 
	{
        cout << "\nCourse " << i + 1 << ":" << endl;
        cout << "Enter course name: ";
        cin >> courses[i].name;
        cout << "Enter course credits: ";
        cin >> courses[i].credits;
        cout << "Enter grade points (0 to 10) for the course: ";
        cin >> courses[i].grade;

        totalCredits += courses[i].credits;
        totalGradePoints += courses[i].credits * courses[i].grade;
    }

    if (totalCredits == 0) 
	{
        cout << "\nTotal credits cannot be zero." << endl;
        return 0;
    }

    // Calculate CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display course-wise details
    cout << "\nCourse-wise details:\n";
    cout << setw(20) << left << "Course Name" 
         << setw(10) << "Credits" 
         << setw(10) << "Grade" << endl;
    for (int i = 0; i < numCourses; ++i) 
	{
        cout << setw(20) << left << courses[i].name
             << setw(10) << courses[i].credits
             << setw(10) << courses[i].grade << endl;
    }

    // Display total and CGPA
    cout << "\nTotal Credits: " << fixed << setprecision(2) << totalCredits << endl;
    cout << "Total Grade Points: " << fixed << setprecision(2) << totalGradePoints << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
