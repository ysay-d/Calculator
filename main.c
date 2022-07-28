/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2022年07月27日 18时17分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YSAY (DYH), 570260087@qq.com
 *   Organization:  csu
 *
 * =====================================================================================
 */

#include	<stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  driven function 
 * =====================================================================================
 */

void caculator_body();
void caculator_getstatement();
int main ( int argc, char *argv[] )
{
		
		while ( 1 ) {
				caculator_body();
				caculator_getstatement();
		}
		return 0;
}				/* ----------  end of function main  ---------- */
