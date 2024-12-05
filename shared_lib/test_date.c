#include <stdio.h>
#include <dlfcn.h>
#include "date_utilities.h"

int main() {
    void *handle;
    int (*is_leap_year_func)(int);
    int (*is_valid_date_func)(int, int, int);
    Date (*add_days_func)(Date, int);
    void (*format_date_func)(Date, char *);
    char *error;

    // Load dynamic libraries
    handle = dlopen("./libdate.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error opening library: %s\n", dlerror());
        return 1;
    }

    // Load function pointer
    is_leap_year_func = dlsym(handle, "is_leap_year");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading is_leap_year: %s\n", error);
        dlclose(handle);
        return 1;
    }

    is_valid_date_func = dlsym(handle, "is_valid_date");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading is_valid_date: %s\n", error);
        dlclose(handle);
        return 1;
    }

    add_days_func = dlsym(handle, "add_days");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading add_days: %s\n", error);
        dlclose(handle);
        return 1;
    }

    format_date_func = dlsym(handle, "format_date");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error loading format_date: %s\n", error);
        dlclose(handle);
        return 1;
    }

    // Test functions
    // Test is_leap_year
    printf("2024 is a leap year: %d\n", is_leap_year_func(2024));
    printf("2023 is a leap year: %d\n", is_leap_year_func(2023));

    // Test is_valid_date
    printf("2024-02-29 is valid: %d\n", is_valid_date_func(2024, 2, 29));
    printf("2023-02-29 is valid: %d\n", is_valid_date_func(2023, 2, 29));
    printf("2023-13-29 is valid: %d\n", is_valid_date_func(2023, 13, 29));

    // Test add_days and format_date
    Date date1 = {2024, 12, 4};
    Date new_date = add_days_func(date1, 30);
    char formatted_date[11];
    format_date_func(new_date, formatted_date);
    printf("2024-12-04 + 30 days = %s\n", formatted_date);

    // Unload dynamic libraries
    dlclose(handle);

    return 0;
}
