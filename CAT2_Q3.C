/*
Name : Colllins Kimani
Reg : PA106/G/29036/25
Description : CAT2_Q3
*/
#include <stdio.h>
#include <stdlib.h>

// Function to handle errors and exit the program
void handle_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// 1. Write a function that prompts the user to input 10 integers and stores them in a file named "input.txt".
void write_integers_to_file() {
    FILE* file_pointer = fopen("input.txt", "w");
    if (file_pointer == NULL) {
        handle_error("Error opening input.txt for writing");
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        int number;
        printf("Integer %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            // Clear input buffer
            while (getchar() != '\n');
            i--; // Decrement i to re-prompt for the same number
            continue;
        }
        fprintf(file_pointer, "%d\n", number);
    }

    fclose(file_pointer);
}

// 2. Write a function that reads the integers from "input.txt", calculates the sum and average of the numbers,
// and writes the sum and average to another file named "output.txt".
void calculate_and_write_results() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        handle_error("Error opening input.txt for reading");
    }

    int sum = 0;
    int count = 0;
    int number;

    while (fscanf(input_file, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    fclose(input_file);

    if (count == 0) {
        printf("No numbers found in input.txt.\n");
        return;
    }

    double average = (double)sum / count;

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        handle_error("Error opening output.txt for writing");
    }

    fprintf(output_file, "Sum: %d\n", sum);
    fprintf(output_file, "Average: %.2f\n", average);

    fclose(output_file);
}

// 3. Write a function that reads and displays the contents of both "input.txt" and "output.txt"
// in a formatted manner.
void display_file_contents() {
    // Display input.txt
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        handle_error("Error opening input.txt for display");
    }
    printf("\n--- Contents of input.txt ---\n");
    int character;
    while ((character = fgetc(input_file)) != EOF) {
        putchar(character);
    }
    fclose(input_file);

    // Display output.txt
    FILE* output_file = fopen("output.txt", "r");
    if (output_file == NULL) {
        handle_error("Error opening output.txt for display");
    }
    printf("\n--- Contents of output.txt ---\n");
    while ((character = fgetc(output_file)) != EOF) {
        putchar(character);
    }
    fclose(output_file);
    printf("------------------------------\n");
}

int main() {
    write_integers_to_file();
    calculate_and_write_results();
    display_file_contents();

    return 0;
}