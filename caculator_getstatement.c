/*
 * =====================================================================================
 *
 *       Filename:  caculator_core.c
 *
 *    Description: the core of caculator.support randon number.just for long int type,and don't support (). 
 *
 *        Version:  2.0
 *        Created:  2022年07月28日 10时10分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YSAY (DYH), 570260087@qq.com
 *   Organization:  csu
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  caculator_core
 *  Description:  
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

	
	void
caculator_getstatement ( void )
{
	long num_stack[20];
	int sn= 0;                                      /* stack pointer start from 0 */
	char operator[20];
	int onum = 0;
	char statement[255];
	char number[255];                       /* get the number in statement */

	int priority[255];
	priority['"'] = 0;
	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;

	operator[onum++] = '"';

	fgets(statement,255,stdin);
//	printf ( "%s",statement );

	char *ptr = statement;
	char *np = number;                      /* np point the end of number */
	while(*ptr){
		if(*ptr == ' '){
			++ptr;
			continue;
		}
		else if(isdigit(*ptr)){
			*np = *ptr;
			++np;
		}
		else {                          /* This case is operator or \n*/
			*np = '\0';
			num_stack[sn++] = atoi(number);
			np = number;            /* reset the np to start of number array */
			if(*ptr == '\n')*ptr = '"';
			if(*ptr == '"' && operator[onum-1] == '"')
				break;
			while(priority[*ptr] <= priority[operator[onum-1]]){
				if(*ptr == '"' && operator[onum-1] == '"')
					break;

				char op_temp = operator[--onum];
				long num2 = num_stack[--sn];
				long num1 = num_stack[--sn];
				printf("%c\n",op_temp);
				switch ( op_temp ) {
					case '*':	
						num_stack[sn++] = num1 * num2;
						break;

					case '+':	
						num_stack[sn++] = num1 + num2;
						break;

					case '-':	
						num_stack[sn++] = num1 - num2;
						break;
					case '/':
						num_stack[sn++] = num1 / num2;
						break;

					default:	
						printf ( "wrong operator.(just support +-*/now\n" );
						break;
					}				/* -----  end switch  ----- */


			}
			operator[onum++] = *ptr;


		}
		++ptr;
	}
	printf("result:%ld\n",num_stack[0]);
	
}		/* -----  end of function caculator_core  ----- */

//TODO:get each statement and operator. 
