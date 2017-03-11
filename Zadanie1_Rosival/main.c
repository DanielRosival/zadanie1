//
//  main.c
//  Zadanie1_Rosival
//
//  Created by Daniel Rosival on 11/03/2017.
//  Copyright © 2017 Daniel Rosival. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void showbits(short int x){  //Funkcia z wikipedie na kontrolu
    int i;
    for(i=(sizeof(short int)*8)-1; i>=0; i--)
        (x&(1u<<i))?putchar('1'):putchar('0');
    
    printf("\n");
}

short int swap_endianness(short int x){
    unsigned char aux1, aux2;
    short int *pointer;
    
    pointer=&x;
    
    aux1= *(unsigned char *)pointer;
    aux2= *((unsigned char *)pointer+1);
    *(unsigned char *)pointer=aux2;
    *((unsigned char *)pointer+1)=aux1;
    
    x=*pointer;
    
    return x;
}

int main(int argc, const char * argv[]) {
    short int x;
    
    x=8;
    showbits(x);
    x=swap_endianness(x);
    showbits(x);
    
    printf("%d\n",x);
}
