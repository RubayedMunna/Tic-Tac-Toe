#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<conio.h>
#define PI acos(-1)
typedef struct
{
    char xx[100];
    char yy[100];
} abc;

void SignUp();
bool LogIn();
void tic_tac();
void Won();
void Draw();
bool test();
void show();
void Max();
void Min();
void Avg();
void Mean();
void Addition();
void Subtraction();
void Multiplication();
void Division();
void Factorial();
long long fact(long long n);
void Fibonacci();
void Sorting();
void NumberConversion();
void AreaCalculator();
void MultiplicationTable();
void Calculator();
void NumberConversion();

int main()
{

    while(1)
    {
        printf("Press 'a' to Sign Up or Press 'b' to Log In or Press 'Q' to Quit\n");
        char ch;
        scanf("%c",&ch);
        getchar();
        if(ch=='a')
        {
            SignUp();
        }
        else if(ch=='b')
        {
            // jump:

            bool xx=LogIn();
            if(xx)
            {

                printf("\nYour Account Has Been Identified.\n");
                printf("Logged In.\n\n");

                printf("*****************************************\n");
                printf("* Press 'c' to Open Calculator      	*\n");
                printf("* Or 'g' to Enter in Game Zone.     	*\n");
                printf("* Or press 'q' to Log Out.          	*\n");
                printf("*****************************************\n\n");
                while(1)
                {
                    char ch_;
                    scanf("%ch",&ch_);
                    getchar();
                    if(ch_=='c')
                    {
                        Calculator();
                    }
                    else if(ch_=='g')
                    {
                        tic_tac();
                    }
                    else if(ch_=='q')
                    {
                        break;
                    }
                }

            }
            else
            {
                printf("\nEnter Correct Email and Password.\n\n");
                //goto jump;
            }
        }
        else if(ch=='Q')
        {
            return 0;
        }
    }
    return 0;
}

void SignUp()
{
    char mail[100];
    char pass1[100];
    char pass2[100];
    char str[100];
    int idx=0;
    int flg=0;
    printf("Account Registration.\n");
    printf("----------------------\n");
    printf("Your Email: \n");
    scanf("%s",mail);
    getchar();
    printf("Type Your Password: \n");
    scanf("%s",pass1);
    getchar();
    printf("Re-tyepe Your Password: \n");
    scanf("%s",pass2);
    getchar();

    FILE* fp_in;
    fp_in=fopen("My_File.txt","r");
    if(fp_in!=NULL)
    {
        while(!feof(fp_in))
        {
            char ch=getc(fp_in);
            if(ch!='\n')
            {
                str[idx]=ch;
                idx++;
            }
            else
            {
                str[idx]='\0';
                idx=0;
                if(strcmp(str,mail)==0)
                {
                    flg=1;
                    break;
                }
            }
        }
    }
    if(flg==1)
    {
        printf("There is an account using this email.\n");
        return;
    }
    else
    {
        if(strcmp(pass1,pass2)!=0)
        {
            printf("Entered Password Doesn't match with retyped Password.\n");
            return;
        }
        else
        {
            int a=0,b=0,c=0,d=0;
            int len=strlen(pass1);
            if(len>=6)
            {
                a=1;
            }
            for(int i=0; i<len; i++)
            {
                if(pass1[i]>='A'&&pass1[i]<='Z')
                {
                    b=1;
                }
                if(pass1[i]>='a'&&pass1[i]<='z')
                {
                    c=1;
                }
                if(pass1[i]=='.'||pass1[i]=='!'||pass1[i]=='@'||pass1[i]=='#'||pass1[i]=='$'||pass1[i]==','||pass1[i]=='*')
                {
                    d=1;
                }
            }
            if(a==0)
            {
                printf("Length of Password must be greater than 6.\n");

            }
            if(b==0)
            {
                printf("Password must contain an Upper Case letter.\n");
            }
            if(c==0)
            {
                printf("Password must contain a Lower Case letter.\n");
            }
            if(d==0)
            {
                printf("Password must contain a special character.\n");
            }
            if(a&&b&&c&&d)
            {
                FILE *fp_out;
                fp_out=fopen("My_File.txt","a");
                fprintf(fp_out,"%s\n",mail);
                fprintf(fp_out,"%s\n",pass1);
                printf("****************************************************************************************\n");
                printf("* Your Account Has Been Created.                                                   	*\n");
                printf("* Now. to save your account informations in our server, You need to quit the program.  *\n");
                printf("* After that you can LogIn your Account.                                           	*\n");
                printf("****************************************************************************************\n\n");

                return;
            }
        }
    }
}

bool LogIn()
{
    char mail[100];
    char pass[100];
    printf("Loggin In :\n");
    printf("---------------\n");
    printf("Enter Your Email Address :\n");
    scanf("%s",mail);
    getchar();
    printf("Enter Your Password :\n");
    scanf("%s",pass);
    getchar();
    int a=0;
    int idx=0;
    FILE* fp_in;
    fp_in=fopen("My_File.txt","r");
    abc var;
    if(fp_in!=NULL)
    {
        while(!feof(fp_in))
        {
            char ch=fgetc(fp_in);
            if(ch!='\n')
            {
                if(a==0)
                {
                    var.xx[idx]=ch;
                }
                else if(a==1)
                {
                    var.yy[idx]=ch;
                }
                idx++;
            }
            else
            {
                if(a)
                {
                    var.yy[idx]='\0';

                    if(strcmp(mail,var.xx)==0)
                    {
                        if(strcmp(pass,var.yy)==0)
                        {

                            return true;
                        }
                        else
                        {
                            printf("You Have Entered Wrong Password.\n");
                            return false;
                        }
                    }
                    idx=0;
                    a=0;
                }
                else
                {
                    var.xx[idx]='\0';
                    idx=0;
                    a=1;
                }

            }
        }
    }
    printf("There Is No Such Email.\n");
    return false;
}

void Won()
{
    printf("\n\n");
    printf("  ||  	||  ||||||  |||   ||\n");
    printf("  ||  	||	||	||||  ||\n");
    printf("  ||  ||  ||	||	|| || ||\n");
    printf("   || || || 	||	||  ||||\n");
    printf("	||  ||	||||||  ||   |||\n");
    printf("\n\n");
}
void Draw()
{
    printf("\n\n");
    printf("  ||||||   ||||||  	|| 	||  	||\n");
    printf("  ||   ||  ||   ||	||||	||  	||\n");
    printf("  ||   ||  ||||||	||  ||   ||  ||  ||\n");
    printf("  ||   ||  ||   ||  ||||||||   || || ||\n");
    printf("  ||||||   ||   ||  ||	||	||  ||\n");
    printf("\n\n  The Game Drawn.\n");
}
bool test(char ara[3][3])
{
    for(int i=0; i<3; i++)
    {
        if(ara[0][i]==ara[1][i]&&ara[1][i]==ara[2][i]&&ara[0][i]!=' ')
        {
            return true;
        }
        if(ara[i][0]==ara[i][1]&&ara[i][1]==ara[i][2]&&ara[i][0]!=' ')
        {
            return true;
        }
    }
    if(ara[0][0]==ara[1][1]&&ara[1][1]==ara[2][2]&&ara[2][2]!=' ')
    {
        return true;
    }
    if(ara[2][0]==ara[1][1]&&ara[1][1]==ara[0][2]&&ara[1][1]!=' ')
    {
        return true;
    }
    return false;
}
void show(char ara[3][3])
{
    printf("\n");
    printf("	%c | %c | %c  \n",ara[0][0],ara[0][1],ara[0][2]);
    printf("  -------------\n");
    printf("	%c | %c | %c  \n",ara[1][0],ara[1][1],ara[1][2]);
    printf("  -------------\n");
    printf("	%c | %c | %c  \n",ara[2][0],ara[2][1],ara[2][2]);
    printf("\n");
    return;
}
void tic_tac()
{
    char ara[3][3];
    memset(ara,' ',sizeof(ara));
    printf("\n####   Game Zone   ####\n");
    printf("*************************\n\n");
    int x,y;
    show(ara);
    printf("\n");
    for(int i=1; i<=9; i++)
    {

        if(i%2)
        {
            printf("  It's First Player's Trun : \n\n  ");
            scanf("%d %d",&x,&y);
            getchar();
            if(ara[x-1][y-1]!=' '||x<1||x>3||y<1||y>3)
            {
                printf("  You Have Entered Wrong Key.\nEnter Correct Key.\n");
                scanf("%d %d",&x,&y);

            }
            ara[x-1][y-1]='X';
            show(ara);
            bool flag=test(ara);
            if(flag)
            {
                Won();
                printf("  First Player Have Won The Game.\n");
                return;
            }
        }
        else
        {
            printf("  It's Second Player's Turn : \n\n");
            scanf("%d %d",&x,&y);
            getchar();
            if(ara[x-1][y-1]!=' '||x<1||x>3||y<1||y>3)
            {
                printf("  You Have Entered Wrong Key.\nEnter Correct Key.\n");
                scanf("%d %d",&x,&y);
            }
            ara[x-1][y-1]='O';
            show(ara);
            bool flag=test(ara);
            if(flag)
            {
                Won();
                printf("  Second Player Have Won The Game.\n");
                return;
            }
        }
    }
    Draw();
}


void Max()
{
    int n;
    printf("Maximum Element.\n");
    printf("*****************\n\n");
    printf("Enter Number of Elements : \n");
    scanf("%d",&n);
    getchar();
    int x;
    scanf("%d",&x);
    int max=x;
    if(n>1)
    {
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&x);
            if(x>max)
            {
                max=x;
            }
        }
    }
    printf("The Maximum Value is %d.\n",max);
}

void Min()
{
    int n;
    printf("Minimum Element.\n");
    printf("******************\n\n");
    printf("Enter Number of Elements : \n");
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    int min=x;
    if(n>1)
    {
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&x);
            if(x<min)
            {
                min=x;
            }
        }
    }
    printf("The minimum Value is %d.\n",min);
}

void Avg()
{
    int n;
    printf("Average Function.\n");
    printf("******************\n");
    printf("Enter the number of elements of an array: \n");
    scanf("%d",&n);
    double sum=0.0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    double avg=sum/(double)n;
    printf("The average value is %lf.\n",avg);
}

void Mean()
{
    int n;
    printf("Mean Calculation.\n");
    printf("*******************\n\n");
    printf("Enter the number of elements of an array : \n");
    scanf("%d",&n);
    int ara[n+10];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i-1; j>=1; j--)
        {
            if(ara[j]>ara[j+1])
            {
                int temp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=temp;
            }
        }
    }
    int a,b;
    double median;
    if(n%2)
    {
        a=(n/2)+1;
        median=(double)ara[a];
    }
    else
    {
        a=(n/2);
        b=(n/2)+1;
        median=((double)ara[a]+(double)ara[b])/2.0;
    }
    printf("Median of this array is %lf.\n",median);
}

void Addition()
{
    printf("*******Addition*******.\n");
    printf("***********************\n\n");
    printf("Enter two numbers for addition: \n");
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long ans=a+b;
    printf("%lld + %lld = %lld\n",a,b,a+b);
}

void Subtraction()
{
    printf("*******Subtraction*******.\n");
    printf("**************************\n\n");
    long long a,b;
    printf("Enter two numbers for Subtraction : \n");
    scanf("%lld %lld",&a,&b);
    long long ans=a-b;
    printf("%lld - %lld = %lld\n",a,b,ans);
}

void Multiplication()
{
    printf("*******Multiplication******.\n");
    printf("****************************\n\n");
    printf("Enter two numbers for multiplication : \n");
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long ans=a*b;
    printf("%lld X %lld = %lld\n",a,b,ans);

}

void Division()
{
    printf("*******Division*******.\n");
    printf("***********************\n\n");
    printf("Enter 2 decimal numbers for division: \n");
    double a,b;
    scanf("%lf %lf",&a,&b);
    double ans=a/b;
    printf("%lf / %lf = %lf\n",a,b,ans);
}
long long fact(long long n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
void Factorial()
{
    printf("*****Factorial Calculation******.\n");
    printf("*********************************\n\n");
    long long int n;
    printf("Enter a number for factorial : \n");
    scanf("%lld",&n);
    long long ans=fact(n);

    printf("%lld is the factorial of %lld.\n",ans,n);
    return;
}

void Fibonacci()
{
    printf("*******Fibonacci Calculation*******\n");
    printf("***********************************\n\n");
    long long int n;
    printf("Enter a number for fibonacci number: \n");
    scanf("%lld",&n);
    long long int ara[n+10];
    ara[0]=1;
    ara[1]=1;
    for(int i=2; i<=n; i++)
    {
        ara[i]=ara[i-1]+ara[i-2];
    }
    printf("%lldth fibonacci number is %lld\n",n,ara[n]);

}

void Sorting()
{
    printf("*******Sorting Elements*******\n");
    printf("******************************\n\n");
    int n;
    printf("Enter Number of elements : \n");
    scanf("%d",&n);
    int ara[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(ara[j]>ara[j+1])
            {
                int tmp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=tmp;
            }
        }
    }
    printf("The sorted array is : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");
}

void MultiplicationTable()
{
    printf("*******Multiplication Table*******\n");
    printf("**********************************\n\n");

    int n;
    printf("Enter an integer for Multiplication Table: \n");
    scanf("%d",&n);
    printf("Multiplication Table for %d is : \n\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d X %d = %d\n",n,i,n*i);
    }
}


void AreaCalculator()
{
    printf("*******Area Calculation*******\n");
    printf("******************************\n\n");

    printf("******************************************************\n");
    printf("* Press '1' for Triangle, '2' for Rectangle      	*\n");
    printf("* '3' for Circle and '-1' for previous Interface 	*\n");
    printf("******************************************************\n\n");

    while(1)
    {

        int x;
        scanf("%d",&x);
        getchar();
        if(x==1)

        {
            printf("******Triangle Calculation******\n");
            printf("********************************\n\n");

            printf("Enter three sides of a triangle: \n");
            double a,b,c,s,area;
            scanf("%lf%lf%lf",&a,&b,&c);
            getchar();
            if((a+b)<=c||(a+c)<=b||(b+c)<=a)
            {
                printf("Given Triangle is not valid.\n\n");
                continue;
            }
            s=(a+b+c)/2.0;
            double xx=s*(s-a)*(s-b)*(s-c);
            area=sqrt(xx);
            printf("Area of the triangle is %lf Square Unit.\n\n",area);
        }
        else if(x==2)
        {
            printf("******Rectangle Calculation******\n");
            printf("*********************************\n\n");
            double a,b;
            printf("Enter the two side of Rectangle: \n\n");
            scanf("%lf %lf",&a,&b);
            getchar();
            double area=a*b;
            printf("Area of the Rectangle is %lf Square Unit.\n\n",area);
        }
        else if(x==3)
        {
            printf("******Circle Calculation******\n");
            printf("******************************\n\n");
            double r;
            printf("Enter the radius of Circle:\n\n");
            scanf("%lf",&r);
            getchar();
            double area=PI*r*r;
            printf("Area of the Circle is %lf Square Unit.\n\n",area);
        }
        else if(x==-1)
        {
            return;
        }
    }
}
void NumberConversion()
{
    printf("*******Number Conversion*******\n");
    printf("*******************************\n\n");


    printf("******************************************\n");
    printf("* Press '1' for Binary to Decimal,   	*\n");
    printf("* Press '2' for Decimal to Binary,   	*\n");
    printf("* Press '3' for Binary to Hexadecimal,   *\n");
    printf("* Press '4' for Hexadecimal to Binary,   *\n");
    printf("* Press '5' for Decimal to Hexadecimal,  *\n");
    printf("* Press '6' for Hexadecimal to Decimal,  *\n");
    printf("* Press '7' for Octal to Hexadecimal,	*\n");
    printf("* Press '8' for Hexadecimal to Octal,	*\n");
    printf("* Press '-1' to go previous session. 	*\n");
    printf("******************************************\n\n");
    int x;
    while(1)
    {

        scanf("%d",&x);

        getchar();
        if(x==-1)
        {
            return;
        }
        else if(x==1)
        {
            printf("******Binary to Decimal******\n");
            printf("*****************************\n\n");

            printf("Enter an Integer in Binary form.\n\n");
            char str[32];
            scanf("%s",str);
            getchar();
            int len=strlen(str);
            int dec=0;
            int x=1;
            for(int i=len-1; i>=0; i--)
            {
                dec+=(str[i]-'0')*x;
                x*=2;
            }
            printf("%d is the decimal form of given number.\n\n",dec);
        }
        else if(x==2)
        {
            printf("******Decimal to Binary******\n");
            printf("*****************************\n\n");
            int n,x;
            printf("Enter an Integer in decimal form.\n\n");
            scanf("%d",&n);
            getchar();
            char str[16];
            memset(str,'0',16);
            int idx=16;
            x=n;
            while(x)
            {
                int last=x%2;
                x/=2;
                str[idx]=last+'0';
                idx--;
            }
            printf("%s is the binary form of the given integer.\n\n",str);
        }
        else if(x==3)
        {
            printf("******Binary to Hexadecimal******\n");
            printf("*********************************\n\n");
            printf("Enter an Integer in binary form.\n\n");
            char str[32];
            scanf("%s",str);
            getchar();
            int len=strlen(str);
            int dec=0;
            int x=1;
            for(int i=len-1; i>=0; i--)
            {
                dec+=(str[i]-'0')*x;
                x*=2;
            }
            printf("%X is the Hexadecimal form of The given number.\n\n",dec);
        }
        else if(x==4)
        {
            printf("******Hexadecimal to Binary******\n");
            printf("*********************************\n\n");
            int n,x;
            printf("Enter an Integer in Hexadecimal form.\n\n");
            scanf("%x",&n);
            getchar();
            char str[16];
            memset(str,'0',16);
            int idx=16;
            x=n;
            while(x)
            {
                int last=x%2;
                x/=2;
                str[idx]=last+'0';
                idx--;
            }
            printf("%s is the binary form of the given integer.\n\n",str);
        }
        else if(x==5)
        {
            printf("******Decimal to Hexadecimal******\n");
            printf("**********************************\n\n");
            printf("Enter an Integer in decimal form.\n\n");
            int n;
            scanf("%d",&n);
            getchar();
            printf("%X is the Hexadecimal form of The Given number.\n\n",n);
        }
        else if(x==6)
        {
            printf("******Hexadecimal to Decimal******\n");
            printf("**********************************\n\n");
            printf("Enter an Integer in Hexadecimal form.\n\n");
            int n;
            scanf("%X",&n);
            getchar();
            printf("%d is the Decimal form of the Given Number.\n\n",n);
        }
        else if(x==7)
        {
            printf("******Octal to Hexadecimal******\n");
            printf("********************************\n\n");
            printf("Enter an Integer In Octal Form.\n\n");
            int n;
            scanf("%o",&n);
            getchar();
            printf("%X is the Hexadecimal form of The Given Number.\n\n",n);
        }
        else if(x==8)
        {
            printf("******Hexadecimal to Octal******\n");
            printf("********************************\n\n");
            printf("Enter an Integer In Hexadecimal form.\n\n");
            int n;
            scanf("%X",&n);
            getchar();
            printf("%o is the Octal form of The Given Number.\n\n",n);
        }
    }
}

void Calculator()
{
    printf("**********************************************************************************\n");
    printf("* Press 'a' for Max  or 'b' for Min or 'c' for Avg                           	*\n");
    printf("* 'd' for Mean or 'e' for Addition or 'f' for Subtraction                    	*\n");
    printf("* 'g' for Multiplication or 'h' for Division or 'i' for Factorial            	*\n");
    printf("* 'j' for Fibonacci or 'k' for Area Calculator or 'l' for Number Conversion  	*\n");
    printf("* 'm' for  Multiplication Table: Multiplication table for any integer        	*\n");
    printf("* 'n' for Sort a list of elements and 'B' for previous interface             	*\n");
    printf("**********************************************************************************\n\n");
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        getchar();
        if(ch=='a')
        {
            Max();
            getchar();
        }
        else if(ch=='b')
        {
            Min();
            getchar();
        }
        else if(ch=='c')
        {
            Avg();
            getchar();
        }
        else if(ch=='d')
        {
            Mean();
            getchar();
        }
        else if(ch=='e')
        {
            Addition();
            getchar();
        }
        else if(ch=='f')
        {
            Subtraction();
            getchar();
        }
        else if(ch=='g')
        {
            Multiplication();
            getchar();
        }
        else if(ch=='h')
        {
            Division();
            getchar();
        }
        else if(ch=='i')
        {
            Factorial();
            getchar();
        }
        else if(ch=='j')
        {
            Fibonacci();
            getchar();
        }
        else if(ch=='k')
        {
            AreaCalculator();
            getchar();
        }
        else if(ch=='l')
        {
            NumberConversion();
            getchar();
        }
        else if(ch=='m')
        {
            MultiplicationTable();
            getchar();
        }
        else if(ch=='n')
        {
            Sorting();
            getchar();
        }
        else if(ch=='B')
        {
            break;
        }
        printf("\n");
    }
}

