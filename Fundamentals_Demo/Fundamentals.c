/* 
 * File: main_template.c
 * Copy: Copyright (c) 2021 Chattada Viriyaphap
 * BlazerID: chattada
 * Vers: 1.0.0 11/23/2021
 * Desc: Driver for testing concepts 
 */ 

#include <stdio.h> // printf, scanf, definitions
#include <stdlib.h>

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
// void parametric_01(const char first_name[], const char);
void for_loops_01(void);

void help(void);

// argc - count of the number of arguments
// argv - array of arguments from command line
// indexing is 0-based
int main(int argc, char** argv){
    int index;
    char first_name[10];
    chat last_name[10];
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
        help();
    } else if((strcmpi(argv[ 1 ], "/h" == 0) || (strcmpi(argv[1], "/?") == 0)))
    
    return(EXIT_SUCCESS);
}

/* 
 * Name: int main(int argc, char** argv)
 * Desc: Used to drive other functions for the purpose to demo features in
 * class.  Function calls are commented/uncommented depending on which features 
 * are to be tested.  
 */
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
    printf("index          value\n");
    printf("======================================\n");
    for(index=0; index<=9; index=index+1){
        printf("%d          %d\n", index, 2*index);
    }
    printf("======================================\n");
    
    printf("index          value\n");
    printf("======================================\n");
    printf("======================================\n");
}


