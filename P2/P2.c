/* 
 * File: P2.c
 * Copy: Copyright (c) 2021 Chattada Viriyaphap
 * BlazerID: chattada
 * Vers: 1.0.0 11/23/2021
 * Desc: Driver for testing concepts 
 */ 

#include <stdio.h>
#include <stdlib.h>

void projectile_1D_v1(void);
void projectile_2D_v1(void);
void simple_supported_beam_v1(void);

/* 
 * Name: int main(int argc, char** argv)
 * Desc: Used to drive other functions for the purpose to demo features in
 * class.  Function calls are commented/uncommented depending on which features 
 * are to be tested.  
 */
int main(int argc, char** argv) {
    projectile_1D_v1(); // calls 1D version
    projectile_2D_v1(); // calls 2D version
    simple_supported_beam_v1(); // calls beam
    
    return (EXIT_SUCCESS);
}

/* 
 * Name: projectile_1D_v1(void)
 * Desc: 1D projectile calculation
 * Args: void input and output
 */
void projectile_1D_v1(void){
    printf("Calling projectile_1D_v1\n");    
}

/* 
 * Name: projectile_2D_v1(void)
 * Desc: 2D projectile calculation
 * Args: void input and output
 */
void projectile_2D_v1(void){
    printf("Calling projectile_2D_v1\n");
}

/* 
 * Name: simple_supported_beam_v1(void)
 * Desc: Reaction forces for a simple supported beam
 * Args: void input and output
 */
void simple_supported_beam_v1(void){
    printf("Calling simple_supported_beam_v1\n");
}
