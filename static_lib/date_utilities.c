#include "date_utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to verify that the date structure is valid
int is_valid_date(int year, int month, int day) {
    // Check if month and day are valid
    if (month < 1 || month > 12 || day < 1) {
        return 0;
    }
    
    // Check if day exceeds the maximum
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // February in leap years is treated as 29 days.
    if (is_leap_year(year)) {
        days_per_month[1] = 29;
    }

    return day <= days_per_month[month - 1];
}

// Function to add days to a given date
Date add_days(Date date, int days) {
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Leap year settings
    if (is_leap_year(date.year)) {
        days_per_month[1] = 29;
    }

    date.day += days;
    //Convert to correct date by checking if date exceeds total number of days in month
    while (date.day > days_per_month[date.month - 1]) {
        date.day -= days_per_month[date.month - 1];
        date.month++;
        // Processing when the month value is December
        if (date.month > 12) {
            date.month = 1;
            date.year++;
            // Check if a year is a leap year
            if (is_leap_year(date.year)) {
                days_per_month[1] = 29;
            }
        }
    }

    return date;
}

// Function to output date in YYYY-MM-DD format
void format_date(Date date, char *output) {
    // Return date string to variable output
    sprintf(output, "%04d-%02d-%02d", date.year, date.month, date.day);
}