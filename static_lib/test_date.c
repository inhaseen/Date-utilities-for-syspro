#include <stdio.h>
#include "date_utilities.h"

int main() {
    // Test is_leap_year
    printf("2024 is a leap year: %d\n", is_leap_year(2024));
    printf("2023 is a leap year: %d\n", is_leap_year(2023));

    // Test is_valid_date
    printf("2024-02-29 is valid: %d\n", is_valid_date(2024, 2, 29));
    printf("2023-02-29 is valid: %d\n", is_valid_date(2023, 2, 29));
    printf("2023-13-29 is valid: %d\n", is_valid_date(2023, 13, 29));

    Date date1 = {2024, 12, 4};
    Date date2 = {2025, 1, 15};
    
    // Test add_days and format_date
    Date new_date = add_days(date1, 30);
    char formatted_date[11]; // Defining a character array to store date strings
    format_date(new_date, formatted_date);
    printf("2024-12-04 + 30 days = %s\n", formatted_date);

    return 0;
}
