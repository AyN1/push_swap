#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>


static long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (isspace(str[i]))
		++i;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (isdigit(str[i]))
        nb = nb * 10 + (str[i++] - '0');
	return (nb * sign);
}

void test_case(const char *input, long expected, const char *description) {
    long result = ft_atol(input);
    long stdlib_result = atol(input);
    
    printf("Test: %s\n", description);
    printf("  Input: \"%s\"\n", input);
    printf("  Expected: %ld\n", expected);
    printf("  ft_atol result: %ld\n", result);
    printf("  stdlib atol result: %ld\n", stdlib_result);
    
    if (result == expected) {
        printf("  ✅ PASS\n\n");
    } else {
        printf("  ❌ FAIL\n\n");
    }
    
    // Compare with stdlib's atol for reference
    if (result != stdlib_result) {
        printf("  ⚠️ Note: ft_atol and stdlib's atol return different values\n\n");
    }
}

int main() {
    printf("==== FT_ATOL UNIT TESTS ====\n\n");

    // Basic positive numbers
    test_case("0", 0, "Zero");
    test_case("1", 1, "Simple positive");
    test_case("42", 42, "Positive integer");
    test_case("12345", 12345, "Larger positive");
    
    // Basic negative numbers
    test_case("-1", -1, "Simple negative");
    test_case("-42", -42, "Negative integer");
    test_case("-12345", -12345, "Larger negative");
    
    // Whitespace handling
    test_case("   42", 42, "Leading spaces");
    test_case("\t\n\v\f\r 42", 42, "Various whitespace");
    test_case("   -42", -42, "Spaces before negative");
    
    // Sign handling
    test_case("+42", 42, "Explicit positive sign");
    test_case("++42", 0, "Double positive sign"); // Only first sign is processed, then non-digit
    test_case("+-42", 0, "Positive then negative"); // Only first sign is processed
    test_case("-+42", 0, "Negative then positive"); // Only first sign is processed
    test_case("--42", 0, "Double negative"); // Only first sign is processed
    
    // Invalid input handling
    test_case("abc", 0, "Non-numeric string");
    test_case("42abc", 42, "Number followed by letters");
    test_case("  42abc", 42, "Spaces, number, letters");
    test_case("", 0, "Empty string");
    
    // Edge cases
    test_case("2147483647", 2147483647, "INT_MAX");
    test_case("-2147483648", -2147483648, "INT_MIN");
    
    // Note: These might overflow depending on the system's long size
    char max_long_str[32];
    char min_long_str[32];
    sprintf(max_long_str, "%ld", LONG_MAX);
    sprintf(min_long_str, "%ld", LONG_MIN);
    
    test_case(max_long_str, LONG_MAX, "LONG_MAX");
    test_case(min_long_str, LONG_MIN, "LONG_MIN");
    
    // Overflow tests (these test the behavior when overflow occurs)
    char overflow_str[330];
    sprintf(overflow_str, "%ld0", LONG_MAX); // One digit beyond LONG_MAX
    test_case(overflow_str, LONG_MAX, "Overflow beyond LONG_MAX - may fail if no overflow handling");
    
    char underflow_str[330];
    sprintf(underflow_str, "%ld0", LONG_MIN); // One digit beyond LONG_MIN
    test_case(underflow_str, LONG_MIN, "Underflow beyond LONG_MIN - may fail if no overflow handling");
    
    return 0;
}