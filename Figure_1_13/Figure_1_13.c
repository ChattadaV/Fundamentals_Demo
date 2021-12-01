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

int main(void){
    double miles, kms; // input - miles, output - kilometers
    
    // get the distance in miles
    printf("Enter the distance in miles:\n");
    scanf("%lf", &miles);
    
    // convert the distance into kilometers
    kms = KMS_PER_MILE * miles;
    
    // display the distance in kilometers
    printf("That equals %f kilometers.\n", kms);
    
    return(0);
}



