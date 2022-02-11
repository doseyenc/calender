#define TRUE    1
#define FALSE   0

int inputyear(void);
int determinedaycode(int year);
int determineleapyear(int year);
void printSpecifiedDateandMonth(int year,int month,int daycode);
void calendar(int year, int daycode);
void giveInfo();
void printMonth(int month,int daycode);
int stringToInt(char str[]);
int specifiedMonth(char str[]);
int checker(char input[],char check[]);
void takeInput(int argc,char* argv[]);
