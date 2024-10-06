#include <stdio.h>
#include <stdlib.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorization and weather advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay warm and indoors.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and avoid the sun.\n");
    }
}

// Main program to perform conversions and display results
int main() {
    float temperature, converted_temp;
    int input_scale, output_scale;
    char retry;

    do {
        // Input the temperature value
        printf("Enter the temperature: ");
        while (scanf("%f", &temperature) != 1) {
            printf("Invalid temperature input. Please enter a valid number: ");
            while (getchar() != '\n'); // Clear invalid input
        }

        // Input the current temperature scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        while (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
            printf("Invalid input scale choice. Please choose (1), (2), or (3): ");
            while (getchar() != '\n'); // Clear invalid input
        }

        // Input the target temperature scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        while (scanf("%d", &output_scale) != 1 || output_scale < 1 || output_scale > 3) {
            printf("Invalid target scale choice. Please choose (1), (2), or (3): ");
            while (getchar() != '\n'); // Clear invalid input
        }

        // Invalid conversion case (converting to the same scale)
        if (input_scale == output_scale) {
            printf("No conversion needed, same scale chosen.\n");
            continue; // Ask for inputs again
        }

        // Convert the temperature based on input and output scales
        switch (input_scale) {
            case 1: // Celsius
                if (output_scale == 2) {
                    converted_temp = celsius_to_fahrenheit(temperature);
                    printf("Converted temperature: %.2f°F\n", converted_temp);
                } else if (output_scale == 3) {
                    converted_temp = celsius_to_kelvin(temperature);
                    printf("Converted temperature: %.2fK\n", converted_temp);
                }
                break;
            case 2: // Fahrenheit
                if (output_scale == 1) {
                    converted_temp = fahrenheit_to_celsius(temperature);
                    printf("Converted temperature: %.2f°C\n", converted_temp);
                } else if (output_scale == 3) {
                    converted_temp = fahrenheit_to_kelvin(temperature);
                    printf("Converted temperature: %.2fK\n", converted_temp);
                }
                break;
            case 3: // Kelvin
                if (temperature < 0) {
                    printf("Invalid temperature: Negative Kelvin value is not allowed.\n");
                    continue; // Ask for inputs again
                }
                if (output_scale == 1) {
                    converted_temp = kelvin_to_celsius(temperature);
                    printf("Converted temperature: %.2f°C\n", converted_temp);
                } else if (output_scale == 2) {
                    converted_temp = kelvin_to_fahrenheit(temperature);
                    printf("Converted temperature: %.2f°F\n", converted_temp);
                }
                break;
            default:
                printf("Invalid conversion.\n");
                continue; // Ask for inputs again
        }

        // Categorize and provide weather advisory based on the converted temperature in Celsius
        if (output_scale == 1) {
            categorize_temperature(converted_temp); // If output is in Celsius, directly categorize
        } else if (output_scale == 2) {
            categorize_temperature(fahrenheit_to_celsius(converted_temp)); // Convert to Celsius for categorization
        } else if (output_scale == 3) {
            categorize_temperature(kelvin_to_celsius(converted_temp)); // Convert to Celsius for categorization
        }

        // Ask if the user wants to perform another conversion
        printf("Do you want to enter another temperature? (y/n): ");
        while (getchar() != '\n'); // Clear newline
        scanf("%c", &retry);

    } while (retry == 'y' || retry == 'Y'); // Continue if the user enters 'y' or 'Y'

    return 0;
}

