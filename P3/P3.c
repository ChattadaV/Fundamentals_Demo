/* 
 * File: P3.c
 * Copy: Copyright (c) 2021 Gregory C. Myers
 * BlazerID: gmyers
 * Vers: 1.0.0 01/25/2021 GCM - Original Coding
 * Desc: Driver for testing concepts 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define a_y -32.2 // constant acceleration due to gravity

/* Function prototype */
int projectile_1D_v2(double y_init);
int projectile_2D_v2(double v_init, double theta);
int simple_supported_beam_v2(double W, double L, double a);
int help(void);

/* 
 * Name: int main(int argc, char** argv)
 * Desc: Used to drive other functions for the purpose to demo features in
 * class.  Function calls are commented/uncommented depending on which features 
 * are to be tested.  
 */
int main(int argc, char** argv) {
    int index;
    double y_init;
    double v_init;
    double theta;
    double W;
    double L;
    double a;
        
    printf("argv[ 0 ]: %s\n", argv[ 0 ]); // name of the executable
    
    for (index = 0; index < argc; index++){
        printf("argv[ %d ]: %s\n", index, argv[ index ]);
    }
    
    if (argc < 2){
        help();
    } else{
        // handle scenarios where we have 2+ arguments
        if (strcmpi(argv[ 1 ], "/h") == 0){ // string compare i if argv[1] matches "/h" (==0)
            help(); // explicit call for help
        } else if ((argc == 3) && (strcmpi(argv[ 1 ], "/i") == 0) && (strcmpi(argv[ 2 ], "/1D") == 0)){
            // projectile_1D_v2()
            printf("Using interactive mode.\n");
            printf("Please enter the y_init (ft):\n");
            scanf("%lf", &y_init); // use %lf (letter L before f) to turn the result to double
            
            projectile_1D_v2( y_init );  
            
        } else if ((argc == 3) && (strcmpi(argv[ 1 ], "/i") == 0) && (strcmpi(argv[ 2 ], "/2D") == 0)){
            // projectile_2D_v2()
            printf("Using interactive mode.\n");           
            printf("Please enter the v_init (ft/s):\n");
            scanf("%lf", &v_init); // use %lf (letter L before f) to turn the result to double
            printf("Please enter the theta (radians):\n");
            scanf("%lf", &theta); // use %lf (letter L before f) to turn the result to double
            
            projectile_2D_v2( v_init, theta ); 
            
        } else if ((argc == 3) && (strcmpi(argv[ 1 ], "/i") == 0) && (strcmpi(argv[ 2 ], "/Beam")) == 0){
            // simple_supported_beam_v2()
            printf("Using interactive mode.\n");
            printf("Please enter the load (lbs):\n");
            scanf("%lf", &W); // use %lf (letter L before f) to turn the result to double
            printf("Please enter the beam length (ft):\n");
            scanf("%lf", &L); // use %lf (letter L before f) to turn the result to double
            printf("Please enter the load location (ft):\n");
            scanf("%lf", &a); // use %lf (letter L before f) to turn the result to double
            
            simple_supported_beam_v2( W, L, a ); 
            
        } else if ((argc == 4) && (strcmpi(argv[ 1 ], "/p") == 0) && (strcmpi(argv[ 2 ], "/1D") == 0)){
            // projectile_1D_v2()
            printf("Using parametric mode.\n");           
            y_init = atof(argv[ 3 ]); // 3rd arg, convert string to double using atof
            
            projectile_1D_v2( y_init);
            
        } else if ((argc == 5) && (strcmpi(argv[ 1 ], "/p") == 0) && (strcmpi(argv[ 2 ], "/2D") == 0)){
            // projectile_2D_v2()
            printf("Using parametric mode.\n");           
            v_init = atof(argv[ 3 ]); // 3rd arg
            theta = atof(argv[ 4 ]); // 4th arg
            
            projectile_2D_v2( v_init, theta);
            
        } else if ((argc == 6) && (strcmpi(argv[ 1 ], "/p") == 0) && (strcmpi(argv[ 2 ], "/Beam") == 0)){
            // simple_supported_beam_v2()
            printf("Using parametric mode.\n");           
            W = atof(argv[ 3 ]); // 3rd arg
            L = atof(argv[ 4 ]); // 4th arg
            a = atof(argv[ 5 ]); // 5th arg
                    
            simple_supported_beam_v2( W, L, a);
            
        } else{
            help();
        }
    }
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: projectile_1D_v2(double y_init)
 * Desc: Calculate the amount of time taken from an object to drop from an 
 * initial height as well as the final velocity.
 * Args: double y_init - initial height
 */
int projectile_1D_v2(double y_init){
    printf("projectile_1D_v2\n");
    printf("y_init: %.4f\n", y_init);
    
    double t_init;
    double t_final;
    double v_y_init;
    double v_y_final;
    double y_final;
    
    // initialize values
    t_init = 0.0;
    t_final = 0.0;
    v_y_init = 0.0;
    v_y_final = 0.0;
    y_final = 0.0;
    
    // calc t_final
    t_final = sqrt((-2 * y_init) / a_y);
    // calc v_y_final
    v_y_final = v_y_init + (a_y * t_final);
    
    // result table
    printf("Name                    Value\n");
    printf("=============================\n");
    printf("y_init (ft):            %.2f\n", y_init);
    printf("y_final (ft):           %.2f\n", y_final);
    printf("t_init (s):             %.2f\n", t_init);
    printf("t_final (s):            %.2f\n", t_final);
    printf("v_y_final (ft/s):       %.2f\n", v_y_final);
    printf("=============================\n");
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: projectile_2D_v2(double v_init, double theta)
 * Desc: Calculate the amount of time taken from an object launched from a 
 * cannon at a specific angle and velocity.
 * Args: 
 *      double v_init - inital velocity
 *      double theta - initial angle theta
 */
int projectile_2D_v2(double v_init, double theta){
    printf("projectile_2D_v2\n");
    printf("y_init: %.4f\n", v_init);
    printf("theta: %.4f\n", theta);
    
    // initialize values
    double t_init;
    double t_final;
    double y_init;
    double y_final;
    double x_init;
    double x_final;
    double v_y_init;
    double v_y_final;
    double v_x_init;
    double v_x_final;
    double a_x;
    
    t_init = 0.0;
    t_final = 0.0;
    y_init = 0.0; // assume level ground
    y_final = 0.0;
    x_init = 0.0; // assumed origin
    x_final = 0.0;
    v_y_init = 0.0;
    v_y_final = 0.0;
    v_x_init = 0.0;
    v_x_final = 0.0;
    a_x = 0.0;
    
    // split out v_init into its components
    v_x_init = v_init * cos(theta);
    v_y_init = v_init * sin(theta);
        
    // calc t_final
    t_final = -2 * (v_y_init / a_y);
    
    // calc the positions
    x_final = x_init + (v_x_init * t_final) + (0.5 * a_x * pow( t_final, 2.0));
    y_final = y_init + (v_y_init * t_final) + (0.5 * a_y * pow( t_final, 2.0));

    // calc the velocities
    v_x_final = v_x_init + (a_x * t_final);
    v_y_final = v_y_init + (a_y * t_final);
    
    // result table
    printf("Name                    Value\n");
    printf("=============================\n");
    printf("v_init (ft/s):          %.2f\n", v_init);
    printf("theta (radians          %.2f\n", theta);
    printf("y_init (ft):            %.2f\n", y_init);
    printf("y_final (ft):           %.2f\n", y_final);
    printf("x_init (ft):            %.2f\n", x_init);
    printf("x_final (ft):           %.2f\n", x_final);
    printf("t_init (ft):            %.2f\n", t_init);
    printf("t_final (s):            %.2f\n", t_final);
    printf("v_y_init (ft/s):        %.2f\n", v_y_init);
    printf("v_y_final (ft/s):       %.2f\n", v_y_final);
    printf("v_x_init (ft/s):        %.2f\n", v_x_init);
    printf("v_x_final (ft/s):       %.2f\n", v_x_final);
    printf("=============================\n");
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: simple_supported_beam_v2(double W, double L, double a)
 * Desc: Calculate the reaction forces on a beam, given a load, length, and 
 * load location
 * Args: 
 *      double W - load
 *      double L - beam length
 *      double a - load location
 */
int simple_supported_beam_v2(double W, double L, double a){
    printf("simple_supported_beam_v2\n");
    printf("W: %.4f\n", W);
    printf("L: %.4f\n", L);
    printf("a: %.4f\n", a);
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: help(void)
 * Desc: Help menu
 * Args: void input
 */
int help(void){
    printf("========================================\n");
    printf("File: P3.exe\n");
    printf("Copy: Copyright (c) 2021 Chattada Viriyaphap\n");
    printf("vERS: 1.0.0 11/22/2021 CV - Initial version\n");
    printf("Desc: Physics Calculator\n");
    printf("========================================\n");
    printf("Usage:\n");
    printf("    /i - Interactive mode\n");
    printf("        /1D - One dimensional motion\n");
    printf("        /2D - Two dimensional motion\n");
    printf("        /Beam - Beam problem\n");
    printf("    /p - Parametric mode\n");
    printf("        /1D - One dimensional motion\n");
    printf("            requires initial height\n");
    printf("        /2D - Two dimensional motion\n");
    printf("            requires initial velocity and angle\n");
    printf("        /Beam - Beam problem\n");
    printf("    /h - Help\n");
    printf("========================================\n");
    printf("Examples:\n");
    printf("    /i /1D                  ...1D interactive\n");
    printf("    /i /2D                  ...2D interactive\n");
    printf("    /i /Beam                ...Beam interactive\n");
    printf("    /p /1D 100              ...1D with initial height\n");
    printf("    /p /2D 100 .7071        ...2D with initial velocity and angle\n");
    printf("    /p /Beam 100.0 10.0 5.0 ...Beam with weight, length, and weight location\n");
       
    return (EXIT_SUCCESS);
}

