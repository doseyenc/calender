

#include <stdio.h> /* C standard library */
#include "hw1.h" /*header file*/

#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};
int main(int argc,char* argv[]){
	takeInput(argc,argv);
}


int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}
int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}
void printSpecifiedDateandMonth(int year,int month,int daycode){
	int day;
	int monthsDays;
	if(determineleapyear(year)==1 && month ==2){
		monthsDays=29;
	}
	else{
		monthsDays=days_in_month[month];
	}
	printf("%s", months[month]);
	printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		
		for ( day = 1; day <= monthsDays; day++ )
		{
			printf("%2d", day );
			
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
		printf("\n");
}
void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printSpecifiedDateandMonth( year, month, daycode);
		
	}
}
void giveInfo(){
	char str[]="NAME\nDisplays a calender and the date.\n\nThe options are as follows\n-h shows the required information\n-m month Display the specified month the argument may be number between 1-12 or full name of month or may be abbreviation of month(January/jan/1)\n-y year takes a specified year and shows the calender of that year\n";
	printf("%s",str);
}
void printMonth(int month,int daycode){

	int  day;
	
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			daycode = ( daycode + days_in_month[month] ) % 7;

}
int stringToInt(char str[]){
    int i=0,sum=0;

    while(str[i]!='\0'){
         if(str[i]< 48 || str[i] > 57){
             printf("Unable to convert it into integer.\n");
             return 0;
         }
         else{
             sum = sum*10 + (str[i] - 48);
             i++;
         }

    }

    return sum;

}
int specifiedMonth(char str[]){

	if(checker(str,"1") ==1|| checker(str,"Jan")==1 || checker(str,"jan")==1 || checker(str,"january")==1 ||checker(str,"January")==1){
		return 1;
	}
	else if(checker(str,"2")==1 || checker(str,"Feb")==1 || checker(str,"feb")==1 || checker(str,"February")==1 || checker(str,"february")==1 ){
		return 2;
	}
	else if(checker(str,"3")==1 || checker(str,"Mar")==1 || checker(str,"mar")==1 || checker(str,"march")==1 || checker(str,"March")==1 ){
		return 3;
	}
	else if(checker(str,"4")==1 || checker(str,"Apr")==1 || checker(str,"apr")==1 || checker(str,"april")==1 || checker(str,"April")==1 ){
		return 4;
	}
	else if(checker(str,"5")==1 || checker(str,"May")==1 || checker(str,"may")==1 ){
		return 5;
	}
	else if(checker(str,"5")==1 || checker(str,"Jun")==1 || checker(str,"jun")==1 || checker(str,"June")==1 || checker(str,"june")==1 ){
		return 6;
	}
	else if(checker(str,"7")==1 || checker(str,"Jul")==1 || checker(str,"jul")==1 || checker(str,"July")==1 || checker(str,"july")==1 ){
		return 7;
	}
	else if(checker(str,"8")==1 || checker(str,"Aug")==1 || checker(str,"aug")==1 || checker(str,"August")==1 || checker(str,"august")==1 ){
		return 8;
	}
	else if(checker(str,"9")==1 || checker(str,"Sept")==1 || checker(str,"sept")==1 || checker(str,"September")==1 || checker(str,"september")==1 ){
		return 9;
	}
	else if(checker(str,"10")==1 || checker(str,"Oct")==1 || checker(str,"oct")==1 || checker(str,"October")==1 || checker(str,"october")==1 ){
		return 10;
	}
	else if(checker(str,"11")==1 || checker(str,"Nov")==1 || checker(str,"nov")==1 || checker(str,"November")==1 || checker(str,"november")==1 ){
		return 11;
	}
	else if(checker(str,"12")==1 || checker(str,"Dec")==1 || checker(str,"dec")==1 || checker(str,"December")==1 || checker(str,"december")==1 ){
		return 12;
	}
}
int checker(char input[],char check[])
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++) {
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}
void takeInput(int argc,char* argv[]){
	int year=0;
	int month=0;
	int infoGived=0;
	
	for (int i = 0; i < argc; i++)
	{
		
		if ( argc == 1 || checker(argv[i],"-h")==1 )
		{
			giveInfo();
			infoGived=1;
			break;
		}
		if (checker(argv[i],"-y")==1)
		{
			year=stringToInt(argv[i+1]);
		}
		if (checker(argv[i],"-m")==1)
		{
			month=specifiedMonth(argv[i+1]);
		}
	}
	if (infoGived == 0)
	{
		if (month==0)
		{
			int daycode = determinedaycode(year);
			determineleapyear(year);
			calendar(year, daycode);
		}
		if (year==0)
		{
			int daycode = determinedaycode(2022);
			printMonth(month,daycode);
		}
		else{
				int daycode = determinedaycode(year);
				printSpecifiedDateandMonth(year,month,daycode);
		}
		
		
		
	}
	
	
	
}

