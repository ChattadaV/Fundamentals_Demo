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

#define KMS_PER_MILE 1.609 // conversion constant

// Function prototypes
int get_info(void); // print information about the user
int Figure_2_1(void); // converts from miles to kilometers
void arithmetic_operators(void);
void integer_division(void);
void integer_remainder(void);
void formatting_integers(void);
void fornatting_doubles(void);
double approximate_pi(void);
void type_casts(void);
void interactive_01(void);
void parametric_01(const char first_name[], const char last_name[], const char course_department[], const int course_number);
void for_loops_01(void);
void for_loops_02(void);


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
int main(int argc, char** argv){
    int index;
    char first_name[10];
    char last_name[10];
    char course_department[3];
    int course_number;
    
    // get_info();
    // Figure_2_1();
    // arithmetic_operators(); 
    
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
    if(argc < 2){
        help(); // implicit call for help
    } else if((strcmpi(argv[ 1 ], "/h") == 0) || (strcmpi(argv[1], "/?") == 0)){
        help(); // explicit call for help
    } else if(strcmpi(argv[ 1 ], "/get_info") == 0){
        get_info();
    } else if(strcmpi(argv[ 1 ], "/Figure_2_1") == 0){
        Figure_2_1(); 
    } else if(strcmpi(argv[ 1 ], "/arithmetic_operators") == 0){
        arithmetic_operators();
/*
    } else if(strcmpi(argv[ 1 ], "/integer_division") == 0){
        integer_division();
    } else if(strcmpi(argv[ 1 ], "/integer_remainder") == 0){
        integer_remainder();
    } else if(strcmpi(argv[ 1 ], "/formatting_integers") == 0){
        formatting_integers();
    } else if(strcmpi(argv[ 1 ], "/formatting_doubles") == 0){
        formatting_doubles();
    } else if(strcmpi(argv[ 1 ], "/type_casts") == 0){
        type_casts();
    } else if(strcmpi(argv[ 1 ], "/interactive_01") == 0){
        interactive_01();
    } else if((strcmpi(argv[ 1 ], "/parametric_01") == 0) && (argc == 6)){
        strcpy(first_name, argv[2]); // string copy argv[2] to variable first_name
        strcpy(last_name, argv[3]); // string copy argv[3] to last_name
        strcpy(course_department, argv[4]); // string copy argv[4] to course_department
        course_number = atoi(argv[5]); // atoi convert string to integer
        
        // call to output function
        parametric_01(first_name, last_name, course_department, course_number);
    } else if((strcmpi(argv[ 1 ], "/parametric_01") == 0) && (argc == 2)){
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
*/
    } else if(strcmpi(argv[1], "/for_loops_01") == 0){
        for_loops_01();
    } else if(strcmpi(argv[1], "/for_loops_02") == 0){
        for_loops_02();
    } else{
        help(); // implicit call for help
    }
    
    return(EXIT_SUCCESS);
}

/* 
 * Name: void help(void)
 * Desc: prints out help
 * Args: no input/output
 */
void help(void){
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
    printf("    fundamentals_demo.exe /parametric_01 Chattada Viriyaphap        ... calls parametric_01 using cmd line args\n");
    printf("    fundamentals_demo.exe /for_loops_01              ... calls for_loops_01\n");
    printf("    fundamentals_demo.exe /for_loops_02              ... calls for_loops_02\n");   
    
}


int get_info(void){
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
int Figure_2_1(void){
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
void arithmetic_operators(void){
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
 * Name: void for_loops_01(void)
 * Desc: Demonstration of different ways to use for loops
 */
void for_loops_01(void){
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
    for(index=0; index<=9; index++){
        printf("%d          %d\n", index, 2*index);
    }
    printf("======================================\n\n");
    
    // descending values at increment of -1
    printf("index      value\n");
    printf("======================================\n");
    for(index = 9; index >= 0; index--){
        printf("%d          %d\n", index, 2*index);
    }
    printf("======================================\n\n");
    
    // ascending values at increment of to the power of 2
    printf("current      value\n");
    printf("======================================\n");
    for(current = 0.0; current <= 2.0; current = current + 0.1){
        printf("%.2f          %.2f\n", current, pow(current, 2.0)); // 2nd value is current squared
    }
    printf("======================================\n\n");
    
    // example of empty for_loop
    printf("index      value\n");
    printf("======================================\n");
    for(index = 0; index < 0; index = index + 1){
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
    for(index_outer = 1; index_outer <= 12; index_outer++){
        for(index_inner = 1; index_inner <= 10; index_inner++){
            // use the indeces to fill out the multiplication table
            // index_inner * index_outer --> total number of times this code will run
            printf("%d, %d          %d\n", index_outer, index_inner, (index_outer * index_inner));
        }
    }
    printf("======================================\n\n");        
    
    // find number of outer and inner loops according to value of pi then multiply it
    printf("current          value\n");
    printf("======================================\n");
    for(current_outer = 0.0; current_outer < 10.0; current_outer++){
        for(current_inner = 0.0; current_inner < (2 * M_PI); current_inner = current_inner + (M_PI / 4.0)){
            printf("%.4f, %.4f          %.4f\n", current_outer, current_inner, (current_outer * current_inner));
        }
    }
    printf("======================================\n\n");    
    
    // making table of values of for-loop
    for(index_outer = 0; index_outer < 12; index_outer++){ // stops at 11
        for(index_inner = 0; index_inner < 9; index_inner++){ // stops at 8
            printf("%d,", ((index_outer + 1) * (index_inner + 1)));
        }
        printf("%d\n", ((index_outer + 1) * (index_inner + 1)));
    }
}
