#ifndef DATE_UTILITIES_H
#define DATE_UTILITIES_H

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Check if a year is a leap year
int is_leap_year(int year);

// Function to verify that the date structure is valid
int is_valid_date(int year, int month, int day);

// Function to add days to a given date
Date add_days(Date date, int days);

// Function to output date in YYYY-MM-DD format
void format_date(Date date, char *output);

#endif // DATE_UTILITIES_H