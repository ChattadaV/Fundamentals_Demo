/* 
 * File: main_template.c
 * Copy: Copyright (c) 2021 Chattada Viriyaphap
 * BlazerID: chattada
 * Vers: 1.0.0 11/23/2021
 * Desc: Driver for testing concepts 
 */ 

#include <stdio.h> // printf, scanf, definitions
#include <stdlib.h>
#include <string.h> // strcpy, strcmpi
#include <math.h> // math library
#include <time.h>

#define KMS_PER_MILE 1.609 // conversion constant
#define pi approximate_pi() // use function approximate_pi to define value for pi

// Function prototypes
int get_info(void); // print information about the user
int Figure_2_1(void); // converts from miles to kilometers
void arithmetic_operators(void);
void integer_division(void);
void integer_remainder(void);
void formatting_integers(void);
void formatting_doubles(void);
double approximate_pi(void);
void type_casts(void);
void interactive_01(void);
void parametric_01(const char first_name[], const char last_name[], const char course_department[], const int course_number);
void for_loops_01(void);
void for_loops_02(void);
int for_loops_03(int start, int increment, int end);
void while_loops_01(void);
void while_loops_02(void);
int rand_range(int min, int max );

void calculator_v1(void);
void calculator_v2(void);
double add_double(double first, double second);
double subtract_double(double first, double second);
double multiply_double(double first, double second);
double divide_double(double first, double second);
double help_calculator(void);

void help(void);

// argc - count of the number of arguments
// argv - array of arguments from command line
// indexing is 0-based
/* 
 * Name: int main(int argc, char** argv)
 * Desc: Used to drive other functions for the purpose to demo features in
 * class.  Function calls are commented/uncommented depending on which features 
 * are to be tested.  
 */
int main (int argc, char** argv) {
    int index;
    char first_name[10]; // maxmimum 10-1 = 9 characters long
    char last_name[10];
    char course_department[3];
    int course_number;
    int start;
    int increment;
    int end;
    int results;
    
    printf("argc: %d\n", argc);
    for(index = 0; index < argc; index++){
        printf("argv[ %d ] has the value of %s\n", index, argv[ index ]);
    }
    
    /* 
     * how to test what arguments are coming from the command line must have 
     * at least one argument --> name of the executable. Use an if statement to
     * determine which function to call. Use the function name as the command 
     * line argument (arbitrary).
     */
    if (argc < 2) {
        help(); // implicit call for help
    } else if ((strcmpi(argv[ 1 ], "/h") == 0) || (strcmpi(argv[1], "/?") == 0)) {
        help(); // explicit call for help
    } else if (strcmpi(argv[ 1 ], "/get_info") == 0) {
        get_info();
    } else if (strcmpi(argv[ 1 ], "/Figure_2_1") == 0) {
        Figure_2_1(); 
    } else if (strcmpi(argv[ 1 ], "/arithmetic_operators") == 0) {
        arithmetic_operators();
    } else if (strcmpi(argv[ 1 ], "/integer_division") == 0) {
        integer_division();
    } else if (strcmpi(argv[ 1 ], "/integer_remainder") == 0) {
        integer_remainder();
    } else if (strcmpi(argv[ 1 ], "/formatting_integers") == 0) { 
        formatting_integers();
    } else if (strcmpi(argv[ 1 ], "/formatting_doubles") == 0) {
        formatting_doubles();
    } else if (strcmpi(argv[ 1 ], "/type_casts") == 0) {
        type_casts();
    } else if (strcmpi(argv[ 1 ], "/interactive_01") == 0) {
        interactive_01();
    // parametric_01 with argc = 6 below comes before parametric_01 with argc = 2 because argc = 6 is more restrictive
    } else if ((strcmpi(argv[ 1 ], "/parametric_01") == 0) && (argc == 6)) {
        // strcpy --> string copy
        strcpy(first_name, argv[2]); // string copy argv[2] to variable first_name
        strcpy(last_name, argv[3]); // string copy argv[3] to last_name
        strcpy(course_department, argv[4]); // string copy argv[4] to course_department
        course_number = atoi(argv[5]); // atoi convert string to integer
        
        // call to output function
        parametric_01(first_name, last_name, course_department, course_number);
    } else if ((strcmpi(argv[ 1 ], "/parametric_01") == 0) && (argc == 2)) {
        // capture information from user
        printf("Please enter a first name:\n");
        scanf("%s", &first_name);
        
        printf("Please enter a last name:\n");
        scanf("%s", &last_name);
        
        printf("Please enter a course department:\n");
        scanf("%s", &course_department);
        
        printf("Please enter a course number:\n");
        scanf("%d", &course_number);
        
        // call to output function
        parametric_01(first_name, last_name, course_department, course_number);      
    } else if (strcmpi(argv[1], "/for_loops_01") == 0) {
        for_loops_01();
    } else if (strcmpi(argv[1], "/for_loops_02") == 0) {
        for_loops_02();
    } else if ((strcmpi(argv[1], "/for_loops_03") == 0) && (argc == 2)) { // 2 arguments in cmd (fundamentals_demo.exe, /for_loops_03)
        // assume the user wants to gather the information interactively
        printf("Please enter a starting integer:\n");
        scanf("%d", &start);
        
        printf("Please enter an increment integer:\n");
        scanf("%d", &increment);
        
        printf("Please enter an ending integer:\n");
        scanf("%d", &end);
        
        results = for_loops_03(start, increment, end);
        printf("Congratulations! Your loop ran %d times!\n", results);
    } else if (strcmpi(argv[1], "/while_loops_01") == 0) { 
        while_loops_01();
    } else if (strcmpi(argv[1], "/while_loops_02") == 0) { 
        while_loops_02(); // simple guessing game :)
    } else if (strcmpi(argv[1], "/calculator_v1") == 0) {
        calculator_v1();
    } else if (strcmpi(argv[1], "/calculator_v2") == 0) {
        calculator_v2();
    } else {
        help(); // implicit call for help
    }
    
    return(EXIT_SUCCESS);
}

/* 
 * Name: void help(void)
 * Desc: prints out help
 * Args: no input/output
 */
void help(void) {
    printf("Usage:\n");
    printf("    fundamentals_demo.exe /h                         ... calls help\n");
    printf("    fundamentals_demo.exe /get_info                  ... calls get_info\n");
    printf("    fundamentals_demo.exe /Figure_2_1                ... calls Figure_2_1\n");
    printf("    fundamentals_demo.exe /arithmetic_operators      ... calls arithmetic_operators\n");
    printf("    fundamentals_demo.exe /integer_division          ... calls integer_division\n");
    printf("    fundamentals_demo.exe /integer_remainder         ... calls integer_remainder\n");
    printf("    fundamentals_demo.exe /formatting_integers       ... calls formatting_integers\n");
    printf("    fundamentals_demo.exe /formatting_doubles        ... calls formatting_doubles\n");
    printf("    fundamentals_demo.exe /type_casts                ... calls type_casts\n");
    printf("    fundamentals_demo.exe /interactive_01            ... calls interactive_01\n");
    printf("    fundamentals_demo.exe /parametric_01             ... calls parametric_01\n");
    printf("    fundamentals_demo.exe /parametric_01 Chattada Viriyaphap EE233  ... calls parametric_01 using cmd line args\n");
    printf("    fundamentals_demo.exe /for_loops_01              ... calls for_loops_01\n");
    printf("    fundamentals_demo.exe /for_loops_02              ... calls for_loops_02\n");   
    printf("    fundamentals_demo.exe /for_loops_03              ... calls for_loops_03\n");   
    printf("    fundamentals_demo.exe /for_loops_03 0 1 9        ... calls for_loops_03\n"); // count from 0 up to 9   
    printf("    fundamentals_demo.exe /while_loops_01            ... calls while_loops_01\n");
    printf("    fundamentals_demo.exe /while_loops_02            ... calls while_loops_02\n");
    printf("    fundamentals_demo.exe /calculator_v1             ... calls calculator_v1\n");
    printf("    fundamentals_demo.exe /calculator_v2             ... calls calculator_v2\n");
    printf("    fundamentals_demo.exe /typedefs_01               ... calls typedefs_01\n");
}


int get_info(void) {
    printf("Firstname: Chattada\n");
    printf("Lastname: Viriyaphap\n");
    printf("BlazerID: chattada\n");
    printf("Initials: CV\n");
    printf("Languages: MatLab, C/C++, Python\n");
    printf("Goals (Class): To be proficient in C language (and get an A!)\n");
    printf("Goals (Professional): Become an airline pilot\n");
    printf("Graduation: Spring 2024\n");
    printf("Computer Model: Dell Latitude 5510\n");
    printf("Computer CPU: i5-10210U @1.60 Ghz\n");
    printf("Computer Memory: 8 Gb (7.64 Gb Usable)\n");
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: Figure_2_1 (from Figure_1_13)
 * Desc: Convert from miles to kilometers
 * Args: 
 *      miles - input
 *      kilometers - output
 */
int Figure_2_1(void) {
    double miles, kms; // input - miles, output - kilometers
    
    // get the distance in miles
    printf("Enter the distance in miles:\n");
    scanf("%lf", &miles);
    
    // convert the distance into kilometers
    kms = KMS_PER_MILE * miles;
    
    // display the distance in kilometers
    printf("That equals %.4f kilometers.\n", kms);
    
    return(EXIT_SUCCESS);
}

/* 
 * Name: arithmetic_operators(void)
 * Desc: Demonstration of arithmetic operators
 */
void arithmetic_operators(void) {
    int a_int;
    int b_int;
    double a_double;
    double b_double;
    
    a_int = 10;
    b_int = 3;
    a_double = 10.0;
    b_double = 3.0;
    
    printf("Fundamentals: Demonstration of Arithmetic Operators\n");
    printf("========================================\n");
    printf("%d + %d = %d\n", a_int, b_int, (a_int + b_int));    
    printf("%f + %f = %f\n", a_double, b_double, (a_double + b_double));
    printf("%d + %f = %f\n", a_int, b_double, (a_int + b_double));
    printf("%f + %d = %f\n", a_double, b_int, (a_double + b_int));
    
    printf("%d - %d = %d\n", a_int, b_int, (a_int - b_int));    
    printf("%f - %f = %f\n", a_double, b_double, (a_double - b_double));
    printf("%d - %f = %f\n", a_int, b_double, (a_int - b_double));
    printf("%f - %d = %f\n", a_double, b_int, (a_double - b_int));
    
    printf("%d * %d = %d\n", a_int, b_int, (a_int * b_int));    
    printf("%f * %f = %f\n", a_double, b_double, (a_double * b_double));
    printf("%d * %f = %f\n", a_int, b_double, (a_int * b_double));
    printf("%f * %d = %f\n", a_double, b_int, (a_double * b_int));
    
    printf("%d / %d = %d\n", a_int, b_int, (a_int / b_int));    
    printf("%f / %f = %f\n", a_double, b_double, (a_double / b_double));
    printf("%d / %f = %f\n", a_int, b_double, (a_int / b_double));
    printf("%f / %d = %f\n", a_double, b_int, (a_double / b_int));
    
    printf("%d %% %d = %d\n", a_int, b_int, (a_int % b_int)); // remainder of 10/3         
    
    printf("========================================\n");
}

/*
 * Name: void integer_division(void)
 * Desc: Demonstration of Results of Integer Division 
 */
void integer_division(void) {
    printf("Fundamentals: Results of Integer Division\n");
    printf("========================================\n");        
    
    // "normal" examples
    printf("%d / %d = %d\n", 3, 15, (3/15) );
    printf("%d / %d = %d\n", 4, 15, (4/15) );
    printf("%d / %d = %d\n", 5, 15, (5/15) );
    printf("%d / %d = %d\n", 6, 15, (6/15) );
    printf("%d / %d = %d\n", 7, 15, (7/15) );
    printf("%d / %d = %d\n", 8, 15, (8/15) );
    printf("%d / %d = %d\n", 14, 15, (14/15) );
    printf("%d / %d = %d\n", 15, 15, (15/15) );
    printf("%d / %d = %d\n", 15, 3, (15/3) );
    printf("%d / %d = %d\n", 16, 3, (16/3) );
    printf("%d / %d = %d\n", 17, 3, (17/3) );
    printf("%d / %d = %d\n", 18, 3, (18/3) );
    
    // negative examples
    printf("%d / %d = %d\n", 16, -3, (16/-3) );
    printf("%d / %d = %d\n", -16, 3, (-16/3) );
    printf("%d / %d = %d\n", -16, -3, (-16/-3) );
    
    printf("%d / %d = %d\n", 0, 4, (0/4) );
    
    // divide by zero // will crash the executable
    // printf("%d / %d = %d\n", 4, 0, (4/0) ); 
    
    printf("========================================\n");
}

/*
 * Name: void integer_remainder(void)
 * Desc: Demonstration of Results of % Operation 
 */
void integer_remainder(void) {
    printf("Fundamentals: Results of Integer Remainder\n");
    printf("========================================\n");    
    
    // "normal" examples
    printf("%d %% %d = %d\n", 3, 15, (3%15));
    printf("%d %% %d = %d\n", 4, 5, (4%5));
    printf("%d %% %d = %d\n", 5, 5, (5%5));
    printf("%d %% %d = %d\n", 6, 5, (6%5));
    printf("%d %% %d = %d\n", 7, 5, (7%5));
    printf("%d %% %d = %d\n", 8, 5, (8%5));
    printf("%d %% %d = %d\n", 5, 3, (5%3));
    printf("%d %% %d = %d\n", 5, 4, (5%4));
    printf("%d %% %d = %d\n", 15, 5, (15%5));
    printf("%d %% %d = %d\n", 15, 6, (15%6));
    
    // negative examples // will crash the executable
    printf("%d %% %d = %d\n", 15, -7, (15%-7));
    printf("%d %% %d = %d\n", -15, 7, (-15%7));
    printf("%d %% %d = %d\n", -15, -7, (-15%-7));
    
    // remainder by 0
    // printf("%d %% %d = %d\n", 15, 0, (15%0));
    
    printf("========================================\n");
}

/*
 * Name: void formatting_integers(void)
 * Desc: Demonstration of Displaying 234 and –234 Using Different Formatting
 */
void formatting_integers(void) {
    printf("Fundamentals: Examples of Formatting Type Integer Values\n");
    printf("========================================\n");

    printf("%4d\n", 234);
    printf("%5d\n", 234);
    printf("%6d\n", 234);
    printf("%1d\n", 234);
    
    printf("%4d\n", -234);
    printf("%5d\n", -234);
    printf("%6d\n", -234);
    printf("%2d\n", -234); 
    
    printf("========================================\n");    
}

/*
 * Name: void formatting_doubles(void)
 * Desc: Demonstration of Formatting Type double Values 
 */
void formatting_doubles(void) {     
    printf("Fundamentals: Examples of Formatting Type Double Values\n");
    printf("========================================\n");    
    printf("%f\n", pi);
    printf("%16f\n", pi);
    printf("%16.8f\n", pi);
    printf("%16.12f\n", pi);
    printf("%5.2f\n", pi);
    printf("%3.2f\n", pi);
    printf("%5.3f\n", pi);
    printf("%4.2f\n", .1234);        
    printf("========================================\n");    
}

/*
 * Name: double approximate_pi(void)
 * Desc: Calculate pi using the Gregory–Leibniz series
 */
double approximate_pi(void) {
    int count;
    int sign;
    double sum;
        
    sign = 1;
    sum = 0.0;
    
    for (count = 1; count <= 19999; count += 2) {
        sum = sum +  sign * (1 / ((double) count)); 
        /* Display the iteration number, the addendum and the running total.
         * printf("%d %f %f\n", count, (sign * (1 / ((double) count))), (4*sum) );
         */
        // 
        sign = -sign;        
    }
    sum = 4 * sum;
    return(sum);
}

/*
 * Name: void type_casts(void)
 * Desc: Demonstration of Examples of the Use of Type Casts 
 */
void type_casts(void) {
    int int_a;
    int int_b;
    double double_a;
    double double_b;
    char char_a;
    
    int_a = 5;
    int_b = 6;
    double_a = 5.0;
    double_b = 6.0;    
    char_a = 'G'; // single quote --> char
    
    printf("Fundamentals: Examples of Use of Type Casts\n");
    printf("========================================\n");    
    
    // changing the datatype of the value (not the variable)
    // int --> double
    printf("%d --> %f\n", 5, ((double) 5) );
    printf("%d --> %f\n", int_a, ((double) int_a) );
    printf("%d + %d --> %f\n", int_a, int_b, ((double) (int_a + int_b)) );
    
    // double --> int
    printf("%f --> %d\n", double_a, ((int) double_a) );
    printf("%f + %f --> %d\n", double_a, double_b, ((int) (double_a + double_b)) );
    
    int_a = (int) (double_a + double_b);
    printf("int_a: %d\n", int_a);
    int_b = (int) (double_b / double_a);
    printf("int_b: %d\n", int_b);
    
    int_b = (int) (5.0 / 3.0); // truncation
    printf("int_b: %d\n", int_b);
    
    printf("1.9999 --> %d\n", (int) 1.9999); // truncation
    
    // char --> int
    printf("%c --> %d\n", char_a, ((int) char_a)); // ASCII code for each character (decimation value for upper case G)
    
    // int --> char
    printf("%d --> %c\n", 97, ((char) 97)); // ASCII code for each character (decimation value for lower case a)
    char_a = (char) 97; // lowercase a
    
    printf("========================================\n");
}

/*
 * Name: void interactive_01(void)
 * Desc: Demonstration of scanf and printf interactively using strings
 */
void interactive_01(void) {
    // When allocating the size of a string, ALWAYS allocate one size LARGER than the largest piece
    char first_name[10]; // expecting length of first name string to be maximum 9 characters long
    char last_name[10]; // expecting length of last name string to be maximum 9 characters long
    char course_department[3]; // expecting length of course department string to be maximum 2 characters long
    int course_number;    

    // collect this information from the user
    printf("Please enter your first name (no more than 9 characters):\n");
    scanf("%s", &first_name);

    printf("Please enter your last name (no more than 9 characters):\n");
    scanf("%s", &last_name);

    printf("Please enter a course department (no more than 2 characters):\n");
    scanf("%s", &course_department);

    printf("Please enter a course number:\n");
    scanf("%d", &course_number);
        
    // print the output
    printf("Hello %s %s! Welcome to %s%d!\n", first_name, last_name, course_department, course_number);
}

/*
 * Name: void parametric_01(const char first_name[], const char last_name[], const char course_department[], const int course_number )
 * Desc: Demonstration of scanf and printf parametrically using strings
 */
void parametric_01(const char first_name[], const char last_name[], const char course_department[], const int course_number ) {
    // do some error checking
    printf("Hello %s %s! Welcome to %s%d!\n", first_name, last_name, course_department, course_number);  
}

/* 
 * Name: void for_loops_01(void)
 * Desc: Demonstration of different ways to use for loops
 */
void for_loops_01(void) {
    int index;
    double current;
    
    /* Syntax:
     *      initialization expression - where the loop starts
     *      loop repetition condition - must evaluate to true for the loop to continue
     *      update expression - how the loop increments/decrements

     *  for ( initialization expression; loop repetition condition; update expression)
     *  {   
     *      block of code/statements
     *      statement;
     *  }
     */ 
    
    // ascending values at increment of 1
    printf("index      value\n");
    printf("======================================\n");
    for (index=0; index<=9; index++) {
        printf("%d          %d\n", index, 2*index);
    }
    printf("======================================\n\n");
    
    // descending values at increment of -1
    printf("index      value\n");
    printf("======================================\n");
    for (index = 9; index >= 0; index--) {
        printf("%d          %d\n", index, 2*index);
    }
    printf("======================================\n\n");
    
    // ascending values at increment of to the power of 2
    printf("current      value\n");
    printf("======================================\n");
    for (current = 0.0; current <= 2.0; current = current + 0.1) {
        printf("%.2f          %.2f\n", current, pow(current, 2.0)); // 2nd value is current squared
    }
    printf("======================================\n\n");
    
    // example of empty for_loop
    printf("index      value\n");
    printf("======================================\n");
    for (index = 0; index < 0; index = index + 1) {
        printf("%d          %d\n", index, 2*index);        
    }
    printf("======================================\n");
}

/* 
 * Name: void for_loops_02(void)
 * Desc: Demonstration of different ways to use for loops
 */
void for_loops_02(void) {
    int index_outer;
    int index_inner;
    double current_outer;
    double current_inner;
    
    // find number of outer and inner loops then multiply it
    printf("index          value\n");
    printf("======================================\n");
    for (index_outer = 1; index_outer <= 12; index_outer++) {
        for (index_inner = 1; index_inner <= 10; index_inner++) {
            // use the indeces to fill out the multiplication table
            // index_inner * index_outer --> total number of times this code will run
            printf("%d, %d          %d\n", index_outer, index_inner, (index_outer * index_inner));
        }
    }
    printf("======================================\n\n");        
    
    // find number of outer and inner loops according to value of pi then multiply it
    printf("current          value\n");
    printf("======================================\n");
    for (current_outer = 0.0; current_outer < 10.0; current_outer++) {
        for (current_inner = 0.0; current_inner < (2 * M_PI); current_inner = current_inner + (M_PI / 4.0)) {
            printf("%.4f, %.4f          %.4f\n", current_outer, current_inner, (current_outer * current_inner));
        }
    }
    printf("======================================\n\n");    
    
    // making table of values of for-loop
    for (index_outer = 0; index_outer < 12; index_outer++) { // stops at 11
        for (index_inner = 0; index_inner < 9; index_inner++) { // stops at 8
            printf("%d,", ((index_outer + 1) * (index_inner + 1)));
        }
        printf("%d\n", ((index_outer + 1) * (index_inner + 1)));
    }
}

/* 
 * Name: int for_loops_03(int start, int increment, int end)
 * Desc: Demonstration of different ways to use for loops
 * Args:
 *  start - where the loop starts
 *  increment - how much the value changes each loop
 *  end - ending value (inclusive)
 *  returns number of iterations
 */
int for_loops_03(int start, int increment, int end) {
    int count;
    int index;
    
    count = 0; // to keep track of how many times the for-loop has run
    
    if (increment < 0) {
        if (end > start) {
            printf("Warning: Increment is negative but the end is greater than the start!\n");
        } else {
            // end <= start
            printf("index      value\n");
            printf("======================================\n");
            for(index = start; index >= end; index = index + increment){ // increment is negative
                printf("%d          %d\n", index, (2 * index));
                count++; // count = count + 1
            }
            printf("======================================\n");    
        }
    } else if (increment > 0) {
        if (end < start) {
            printf("Warning: Increment is positive but the end is less than the start!\n");
        } else {
            // end >= start
            printf("index      value\n");
            printf("======================================\n");
            for(index = start; index <= end; index = index + increment){ // increment is positive
                printf("%d          %d\n", index, (2 * index));
                count++; // count = count + 1
            }
            printf("======================================\n"); 
        }
    } else {
        // increment = 0 --> infinite loop because index never changes
        printf("Warning: Increment must be non-zero (or you will get an infinite loop)!\n");
    }
    return(count); // return how many times for-loop has run
}

/* 
 * Name: void while_loops_01(void)
 * Desc: Demonstration of different ways to use while loops
 */
void while_loops_01(void) {
    int index;
    double balance; // check card balance
    double purchase; // attempt to buy something
    int broke; // flag that represents a condition
    int count;
    
    /* Syntax:
     *      loop repetition condition - while this is true, the loop continue
     * - make sure to initialize the condition outside the while loop
     * - make sure the condition changes at some point in the while loop (or the loop will be infinite)
     * 
     *  while (loop repetition condition)
     * {    
     *      block of code/statements
     *      statement;
     * }      
     */
    
    // https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Standard_C_Library/Functions/srand    
    // https://en.wikibooks.org/wiki/C_Programming/time.h
    srand( time(NULL) );    
    
    // basic while loop
    index = 0; // start value
    printf("index      value\n");
    printf("======================================\n");
    while (index <= 9) {
        printf("%d          %d\n", index, (2 * index));
        index++; // index = index + 1
    }
    printf("======================================\n\n");
    
    // basic while loop with random number generator
    index = 0; // initialize value again
    printf("index      value\n");
    printf("======================================\n");
    while (index <= 9) {
        printf("%d          %d\n", index, rand());
        index++; // index = index + 1
    }
    printf("======================================\n\n");
    
    // basic while loop to track money spending
    balance = 1000;
    count = 0;
    printf("count      value            balance\n");
    printf("======================================\n");
    while (balance > 0.0) {
        // can purchase things
        purchase = rand() / 100.0; // convert an integer value to dollars/cents
        balance = balance - purchase;
        count++;
        printf("%d          %.2f            %.2f\n", count, purchase, balance);
    }
    printf("======================================\n\n");
    
    /*
     * while loop to track money spending using a flag that represents 
     * broke (stop buying) or not broke (keep buying) so we don't end up with 
     * negative balance at the end
    */
    balance = 1000;
    count = 0;
    broke = 0; // not broke
    printf("count      value            balance\n");
    printf("======================================\n");
    while (broke == 0) {
        purchase = rand() / 100.0;
        if (purchase < balance) {
            // can buy
            balance = balance - purchase;
            count++;
            printf("%d          %.2f            %.2f\n", count, purchase, balance);
        } else {
            // cannot buy because not enough money
            broke = 1;
        }
    }
    printf("======================================\n");
}

/* 
 * Name: void while_loops_02(void)
 * Desc: Simple game of guessing
 *      Demonstration an interactive way to use while loops
 *      
 */
void while_loops_02(void){
    int valid;
    int first;
    int second;
    int chosen; // chosen by computer
    int guess;
    int count_current;
    int count_max;
    
    valid = 0; // valid is false
    count_current = 0;
    count_max = 3; // consider asking user how many times they'd like to guess
    
    // srand(time(0));
    srand(time(NULL)); // Creates the seed for the random number generator.
    
    printf("Let's play a guessing game!  Pick two integers.\n");
    printf("I'll pick one in between them.\n");
    printf("I'll give you %d guesses to figure out my integer!\n", count_max);
    printf("Let's go!!!\n\n");
    
    printf("Please enter the minimum integer value\n");
    scanf("%d", &first);
    // make sure minimum and maximum value are different
    while (valid == 0) {
        printf("Please enter the maximum integer value\n");
        scanf("%d", &second);
        // make sure minimum and maximum value are different
        if (second > first) {
            // continue
            valid = 1;
        } else {
            valid = 0;
        }
    }
    // assume the user wants to continue
    chosen = rand_range(first, second);
    valid = 0; // the user has not yet picked the correct value
    while ((valid == 0) && (count_current < count_max)) {
        printf("Please guess the value that I have picked!\n");
        count_current++;
        printf("Try #%d of %d\n", count_current, count_max);
        scanf("%d", &guess);
        if (guess == chosen) { // guessed correctly, won the game
            printf("Congratulations! You guessed the correct number!\n");
            valid = 1;
            // loop terminates
        } else if (guess < chosen) { // guessed a wrong number (too low)
            printf("Nope! Number is too low!\n");
            // loop continues
        } else if (guess > chosen) { // guessed a wrong number (too high)
            printf("Nope! Number is too high!\n");
            // loop continues
        }
    }
    if (valid == 0) { // lost the game
        printf("You did not guess correctly within the number of tries :( the correct number is %d ... Wanna play again?\n", chosen);
    } else { // won the game
        printf("Wanna play again?\n");
    }
}

/* 
 * Name: int rand_range(int min, int max )
 * Desc: Demonstration of a random integer generator
 */
int rand_range(int min, int max ) {    
    return (min + rand() / (RAND_MAX / (max - min + 1) + 1)); // RAND_MAX --> find max value across all random integers in the list
}

/* 
 * Name: void calculator_v1(void)
 * Desc: Demonstration of top down design, control of flow and data validation
 */
void calculator_v1(void) {
    double first;
    double second;
    double results;
    int option;
    int valid; // use this as a flag to determine whether to continue

    valid = 0; // false 
    
    printf("Welcome to calculator_v1!\n");
    printf("===================================\n");
    printf("Allows the user to enter two values\n");
    printf("and an operation!\n");
    printf("===================================\n");
    printf("Options:\n");
    printf(" 1 - addition\n");
    printf(" 2 - subtraction\n");
    printf(" 3 - multiplication\n");
    printf(" 4 - division\n");
    printf("===================================\n");
    
    while (valid == 0) {
        printf("Please enter an option (1-4)\n");
        scanf("%d", &option);
        
        if ((option >= 1) && (option <= 4)) {
            valid = 1;
        } else {
            // prompt the user again --> run the loop again
            printf("Warning: Invalid option!\n");
        }
        
        // assume the user wants to continue
        valid = 0; // reset the flag
        
        printf("Please enter the first value:\n");
        scanf("%lf", &first); // percent L F
                
        while (valid == 0) {
            printf("Please enter the second value:\n");
            scanf("%lf", &second); // percent L F
            
            if ((option == 4) && (second == 0.0)) {
                printf("Please enter a non-zero value!\n");
            } else {
                // nothing to prompt the user
                valid = 1; // escape out of the while loop
            }
        }
       
        switch (option) {
            case 1:
                // addition
                results = add_double(first, second);
                printf("%.4f + %.4f = %.4f\n", first, second, results);
                break;
            case 2:
                // subtraction
                results = subtract_double(first, second);
                printf("%.4f - %.4f = %.4f\n", first, second, results);                
                break;
            case 3:
                // multiplication
                 results = multiply_double(first, second);
                printf("%.4f * %.4f = %.4f\n", first, second, results);               
                break;
            case 4:
                // division - assume a non-zero second value
                results = divide_double(first, second);
                printf("%.4f / %.4f = %.4f\n", first, second, results);                
                break;
            default:
                printf("Error: Unhandled option!\n");                
        }
    }
}

/* 
 * Name: void calculator_v2(void)
 * Desc: Demonstration of top down design, control of flow and data validation
 */
void calculator_v2(void) {       
    // https://en.wikipedia.org/wiki/Reverse_Polish_notation
    double first;
    double second;
    double results;
    int option;
    int valid; // flag
    int first_run; // the results from subsequent runs become the first value
    int done; // flag // allows the user to exit the application
    
    printf("Welcome to calculator_v2!\n");
    printf("===================================\n");
    printf("Allows the user to enter two values\n");
    printf("and an operation!\n");  
    
    valid = 0; // false
    first_run = 1; // true
    done = 0; // false // the user is not done until they specifically select exit
    
    help_calculator();
    
    while (done == 0) {
        if (first_run == 1) {
            // capture two values
            printf("Please enter the first value:\n");
            scanf("%lf", &first); // percent L F            
            printf("Please enter the second value:\n");
            scanf("%lf", &second); // percent L F
            first_run = 0; // after the first run, set this flag to false
        } else {
            // capture only the second value and resue the result from the previous run
            printf("Please enter the second value:\n");
            scanf("%lf", &second); // percent L F
        }

        valid = 0; // reinforce flag to false so while-loop below will run at least once
        while (valid == 0)  {
            printf("Please enter an option (1-4) or 9 - help or 0 - exit\n");
            scanf("%d", &option);    

            if (option == 1) {
                // addition
                results = add_double(first, second);
                printf("%.4f + %.4f = %.4f\n", first, second, results);
                first = results; // save it to variable first for next operation (option 2)         
                valid = 1;
/*
                printf("%.4f + %.4f = %.4f\n", first, second, add_doubles (first, second));
                // if no output is needed
                first = add_double(first, second);
                printf("%lf\n", first); // act as a result 
*/
            } else if (option == 2) {
                // subtraction
                results = subtract_double(first, second);
                printf("%.4f - %.4f = %.4f\n", first, second, results);
                first = results; // save it to variable first for next operation (option 3)
                valid = 1;
            } else if (option == 3) {
                // multiplication
                results = multiply_double(first, second);
                printf("%.4f * %.4f = %.4f\n", first, second, results);
                first = results; // save it to variable first for next operation (option 4)
                valid = 1;
            } else if (option == 4) {
                // division 
                while (second == 0.0) {
                    printf("Warning: Please enter a non-zero second value!\n");
                    scanf("%lf", &second);
                }
                results = divide_double(first, second);
                printf("%.4f / %.4f = %.4f\n", first, second, results);
                first = results;
                valid = 1;
            } else if (option == 9) {
                // call help
                help_calculator();
                // valid = 0; // reinforce the flag
            } else if (option == 0) {
                // allow the user to exit
                done = 1; // set flag to true // the user is done
                valid = 1;
            } else {
                // call help
                help_calculator();               
            }
        }
    }
}

/* 
 * Name: double help_calculator(void)
 * Desc: help menu for users
 * Args: no input or output args
 */
double help_calculator(void) {
    printf("===================================\n");
    printf("Options:\n");
    printf(" 1 - addition\n");
    printf(" 2 - subtraction\n");
    printf(" 3 - multiplication\n");
    printf(" 4 - division\n");
    printf(" 9 - help\n");
    printf(" 0 - exit\n");
    printf("===================================\n"); 
}

/* 
 * Name: double add_double(double first, double second)
 * Desc: add two doubles together
 * Args:
 *      input - first, second
 *      output - results
 */
double add_double(double first, double second) {
    double results;
    
    results = first + second;    
    return(results);
}

/* 
 * Name: double subtract_double(double first, double second)
 * Desc: subtract two doubles
 * Args:
 *      input - first, second
 *      output - results
 */
double subtract_double(double first, double second) {
    double results;
    
    results = first - second;
    return(results);    
}

/* 
 * Name: double multiply_double(double first, double second)
 * Desc: multiply two doubles
 * Args:
 *      input - first, second
 *      output - results
 */
double multiply_double(double first, double second) {
    double results;
    
    results = first * second;
    return(results);
}

/* 
 * Name: double divide_double(double first, double second)
 * Desc: divide two doubles
 * Args:
 *      input - first, second
 *      output - results
 */
double divide_double(double first, double second) {
    double results;
    
    if (second != 0.0) { // if second value is NOT equal to zero
        // proceed with calculation
        results = first / second;
    } else {
        // assign a value to the results variable - discussion
        results = 0.0; // not mathematically correct, but at least it's executable
        // results = (double) NULL;        
    }
    return(results);
}

