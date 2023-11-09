#include<stdio.h>
#include<conio.h>
int acc_date[5],dob[5],acc_type,b;
char a,f[10],l[10],m[10],pan[22];
long long int aadhar,phone_number;
int i,acc_number,pin;



int main()
{
 
 b:
  printf("\n\n\tSTUDENT BANK OF MIT\n\n\n");

  printf("1] create new account\n\n");
  printf("2] cheack account details\n\n");
  printf("3] update account details\n\n");
  printf("4] deposite cash\n\n");
  printf("5] withdraw cash\n\n");
  printf("6] view transection history\n\n");

  printf("enter option number (ex.4):-");


 a=getch();
 system("cls");
 switch (a)
 {
   case '1':
   tdate:
   printf("Today's date(dd/mm/yyyy);");
   scanf("%d/%d/%d",&acc_date[0],&acc_date[1],&acc_date[2]);
       
   
      if(acc_date[0]>30||acc_date[1]>12||acc_date[1]<1||acc_date[2]<1900||acc_date[2]>2024)
      {
       printf("invalid date\n");
       goto tdate;
      }
        
    
   printf("\nEnter your name:");
   scanf("%s %s %s",f,l,m);                  
   printf("\nDate of birth:");
   scanf("%d/%d/%d",&dob[0],&dob[1],&dob[2]);
       
   for (i=0;i<1;i++)  
    {
      if(dob[0]>30||dob[1]>12||dob[1]<1||dob[2]<1900||dob[2]>2022)
      { 
      printf("invalid date\n");
      printf("\nDate of birth:");
      scanf("%d/%d/%d",&dob[0],&dob[1],&dob[2]);
      i--;
      }
    }
       printf("\nAdhaar no.:-");
       scanf("%lli",&aadhar);
   for (i=0;i<1;i++)  
   {
     if(aadhar>999999999999 && aadhar<1000000000000)
     {
       printf("invalid number\n");
       printf("\nAadhar no:");
       scanf("%lli",&aadhar);
       i--;
     }
   }
       
   printf("\nPan no.:-");
   scanf("%s",&pan);
   printf("\nphone number:-");
   scanf("%lli",&phone_number);
   for(i=0;i<1;i++)
    { 
      if(phone_number<1000000000 || phone_number>9999999999 || phone_number/1000000000<7 || phone_number/1000000000>9) 
     {
       printf("INVALID NUMBER!\n");
       printf("enter valid number:-");
       scanf("%lli",&phone_number);
       i--;
     }
    }
      
    printf("\n\n1] current\n2] saving\n3] fixed\n\n");
    printf("type of account:");
    scanf("%d",&b);
    acc_type=b;
    
    for (i=0;i<1;i++)  
   {
     if(b>3)
     {
       printf("invalid option\n");
       printf("\ntype of account:");
       scanf("%d",&b);
       i--;
     }
   }
   
    printf("\n1] for 1 year\n2] for 2 year\n3] for 3 year\n\n");
    scanf("%d",&b);
    acc_type=30+b;                 //ex(33 for fixed account for 3 year)
    for (i=0;i<1;i++)  
    {
     if(b>3)
     {
       printf("invalid option\n");
       printf("\ntype of account:");
       scanf("%d",&b);
       i--;
     }
    }
     system("cls");
    srand(time(NULL));
    acc_number=(rand()+68754)%1000;
    pin:
    printf("create pin:-");
    scanf("%s",&pin); 
    if (pin<1000)
    {
     printf("pin must have least 4 digit\n");
     goto pin;
    }   
    printf("\nyour account created succesesfully\n");
    printf("your account number is  %d\n\n",acc_number);
    printf("\n\n\n\n\n\n\t\t\t\t\tenter 1 for main manu or 0 to close:-");
    a=getch();
    if(a=='1')
    { 
      system("cls");
      goto b;
    }
    else goto a;
            
            
   case '3':
    system("cls");
    int temp_acc_number,balance,deposite;
    char tempf[22],tempm[22],templ[22],temp_pin[22];
    printf("\n\nenter account number:-");
    scanf("%d",&temp_acc_number);
     
    for(i=0;i<1;i++)
    {
      if (acc_number != temp_acc_number )
      {
        printf("account does not exist");
        printf("enter account number;-"); 
        scanf("%d",&temp_acc_number);
      }
    }
    printf("\nenter pin;-");
    scanf("%s",&temp_pin);    
    for(i=0;i<1;i++)
    {
      if (pin != temp_pin )
      {
       printf("wrong pin");
       printf("enter pin;-"); 
       scanf("%s",&temp_pin);
      }
    }

    printf("\nenter amount:-");
    scanf("%li",&deposite);
    printf("\ntransection successfull");       
    
    /* else if(a==3){
    update_acc();
    }
    else if (a==4){
    deposite_acc();
    }
    else  {
    }*/
    
 }
  a:
  return 0;
}