#include <stdio.h>

// Function declarations
int getFirstDayOfMonth(int year, int month);
int isLeapYear(int year);
int getDaysInMonth(int year, int month);

int main() {
    int month, year;
    
    // Input year and month from user
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    
    // Get the first day of the month
    int firstDay = getFirstDayOfMonth(year, month);
    
    // Get the number of days in the month
    int daysInMonth = getDaysInMonth(year, month);
    
    // Print the calendar
    printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    
    // Print initial spaces
    for (int i = 0; i < firstDay; i++) {
        printf("     ");
    }
    
    // Print days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);
        
        // Move to the next line after Saturday
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    
    printf("\n");
    return 0;
}

// Function to get the first day of the month
int getFirstDayOfMonth(int year, int month) {
    int day = 1, y, m;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y = year - (month < 3);
    return ( y + y / 4 - y / 100 + y / 400 + t[month - 1] + day) % 7;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int getDaysInMonth(int year, int month) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}
