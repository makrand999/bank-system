#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <math.h>

// struct of username and pin(modify)

time_t t;
int x[20], y[20];
char a, ch, cpin[22], cpin1[22], username[] = "max", tusername[22];
int p,u, i=0, j,J, in, pin, I[22]={0}, X, L = 0,cibil_score[10]={700}; // i is for new acc counter and I[] is for transection counter p is independent
long long int temp_acc_number;

struct tran
{
  int tdate[9];
  long long int transfer, balance;
};

struct tran h[11][22];

struct cust
{
  int acc_date[5], dob[5], acc_type;
  char name[55], pan[22], pin1, address[111];
  long long int aadhar, phone_number, acc_balance;
  int b, acc_number;
};

struct cust m[10];



struct loan
{
  char l_purpose[55], l_type[22], employment_status[20], acc_number;
  long long int m_income, l_amount;
  int ldate[3], rdate[3];
};
struct loan l[10];

void Time();
void set();
void login();
void home();
void deposite();
void create_account();
void acc_details();
void withdraw();
void history();
int DOB();
int blank(int);
int acc_update();
int phone_number();
int aadhar_number();
int pan_number();
int transection();
int send1();                                    
void loan();
void loanc();
void acc();

int main()
{
  
  loanc();
  login();
  home();

  return 0;
}

void home()
{
  system("cls");

  printf("\n\nSTUDENT BANK OF MIT\n\n\n");

  printf("1] create new account\n\n");
  printf("2] cheack account details\n\n");
  printf("3] transection\n\n");
  printf("4] view transection history\n\n");
  printf("5] loan\n\n");
  a = getch();
  system("cls");

  switch (a)
  {
    case 0:
    main();
    break;
  case '1':
    create_account();
    break;

  case '2':
  acc_num:
    printf("account number:- ");
    get(0);
    blank(20);
    set(0);
    scanf("%d", &temp_acc_number);
    in = 0;
    in = temp_acc_number % 10;
    if (temp_acc_number == 1)
    {
      system("cls");
      home();
    }
    if (temp_acc_number != m[in].acc_number)
    {
      goto acc_num;
    }
    if (temp_acc_number == 1)
      home();
    system("cls");
    acc_details();
    break;

  case '3':
    transection();
    break;

  case '4':
    history();
    break;

  case '5':
    loan();
    break;

  default:
    system("cls");
    home();
  }
}

void create_account()
{
  printf("1] Name: ");
  scanf(" %[^\n]", m[i].name);
  printf("\n");
  get(1);
  DOB();
  printf("\n\n");
  get(2);
  aadhar_number();
  printf("\n\n");
  get(3);
  phone_number();
  printf("\n\n");
  get(4);
  pan_number();
  printf("\n\n");
  printf("address:- ");
  scanf(" %[^\n]", m[i].address);

  printf("\n\n1] current\n2] saving\n3] fixed\n\n");

  while (1)
  {
    a = getch();
    if (a < 52 && a != 48)
    {
      m[i].b = a - 48;
      m[i].acc_type = m[i].b;
      break;
    }
  }

  if (m[i].b == 3)
  {

    printf("\n\n1] for 1 year\n2] for 2 year\n3] for 3 year\n\n");
  facc_type:
    scanf("%d", &m[i].b);

    if (m[i].b > 3)
    {
      printf("invalid option\n");
      goto facc_type;
    }
    m[i].acc_type = 30 + m[i].b; // ex(33 for fixed account for 3 year)
  }

  system("cls");
  srand(time(NULL));
  m[i].acc_number = ((rand() % 100) + 99) * 10 + i;
  get(0);
  x[0] /= 4;
  y[0] /= 4;
  set();

  printf("\nyour account created succesesfully\n\n\n");
  printf("your account number is  \n\n%d", m[i].acc_number);
  i++;
  while (1)
  {
    a = getch();

    if (a == 27)
   break;  
  }
      system("cls");
      home();
    
    
  
}

void deposite() //  deposite function
{

  system("cls");


  printf("\naccount balance:- %d", m[in].acc_balance);

  printf("\nenter amount:-");
  scanf("%li", &h[in][I[in]].transfer);
  m[in].acc_balance += h[in][I[in]].transfer;
  h[in][I[in]].balance = m[in].acc_balance;
  printf("\ntransection successfull");
  Time();

  I[in]++;
while(1){
  a = getch();
  if (a == 27)
break;
}
    system("cls");
    home();
  
 
}

void login() // login function
{
  printf("\n\n");

  printf("username:- ");
  j = 0;

  while (1)
  {
    ch = getch();

    if (ch == 13)
      break;

    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    tusername[j] = ch;
    printf("%c", ch);
    j++;
  }
  tusername[j] = '\0';
  u = strcmp(username, tusername);

  if (u != 0)
  {
    system("cls");
    login();
  }
  printf("\n\n\nEnter your PIN: "); // pin start
pin:
  get(0);
  j = 0;
  while (1)
  {
    ch = getch();

    if (ch == 13)
      break;
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[j] = ch;
      printf("*");
      j++;
    }
  }
  blank(22);
  get(1);
  blank(22);
  set(1);

  cpin[j] = '\0';
  pin = atoi(cpin);

  if (pin != 261224)
  {
    printf("wrong pin");
    set(0);
    blank(22);
    set(0);
    goto pin;
  }

  system("cls");
}

void acc_details() // acc detail function
{
  printf("\n\naccount details\n\n");

udone:

  printf("1] NAME:- ");
  get(0);
  printf("%s\n\n\n", m[in].name);
  get(1);
  printf("2] date of birth:- %d/%d/%d\n\n\n", m[in].dob[0], m[in].dob[1], m[in].dob[2]);
  get(2);
  printf("3] aadhar no.:- %lld\n\n\n", m[in].aadhar);
  get(3);
  printf("4] phone number:- %lld\n\n\n", m[in].phone_number);
  get(4);
  printf("5] pan number:- %s\n\n\n", m[in].pan);
  get(5);
  printf("6] address:- %s\n\n\n", m[in].address);
  printf("balance:- %lld\n\n", m[in].acc_balance);
  printf("type of account:- ");
  switch (m[in].acc_type)
  {
  case 1:
    printf("current");
    break;
  case 2:
    printf("saving");
    break;
  default:
    printf("fixed for %d year", m[in].b);
  }

  while (1)
  {
    a = getch();
    if (a==27||a>48&&a<55)
    break;
  }
    if (a == 27)
      home();
    if (a > 48 && a < 55)
    {
      acc_update();
      goto udone;
    }
  
}

void withdraw() // withdraw funcyion
{
  system("cls");

  printf("WITHDRAW\n\n");
  printf("\n\n\namount:- ");
  scanf("%d", &h[in][I[in]].transfer);
  m[in].acc_balance -= h[in][I[in]].transfer;
  h[in][I[in]].balance = m[in].acc_balance;
  printf("\n\ndone\n");
  Time();
  I[in]++;
  while(1){
  a = getch();
  if (a == 27)
  break;
  }
    system("cls");
    home();
  
  
}

void history()
{
  printf("enter account nummber:- ");
  scanf("%lld", &temp_acc_number);
  u = temp_acc_number % 10;
  for (in = 0; in < I[u]; in++)
    printf("date:- %d/%d/%d     ammount:-%lld       balance:-%lld\n", h[u][in].tdate[0], h[u][in].tdate[1], h[u][in].tdate[2], h[u][in].transfer, h[u][in].balance);
  while(1){
  a = getch();
  if (a == 27)
  break;
  }
  
    system("cls");
    home();
  
}

void Time()
{
  time(&t);
  struct tm *current_time = localtime(&t);

  h[in][I[in]].tdate[0] = current_time->tm_year + 1900;
  h[in][I[in]].tdate[1] = current_time->tm_mon + 1;
  h[in][I[in]].tdate[2] = current_time->tm_mday;
}

void set(X)
{
  COORD coord;
  coord.X = x[X];
  coord.Y = y[X];
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void get(X)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  x[X] = csbi.dwCursorPosition.X;
  y[X] = csbi.dwCursorPosition.Y;
}

int DOB()
{
  set(1);
dob:
  get(0);
  printf("2] date of birth:- dd/mm/yyyy\b\b\b\b\b\b\b\b\b\b");
  cpin[0] = 1;
  while (cpin[0] < 48 || cpin[0] > 58)
    cpin[0] = getch();
  printf("%c", cpin[0]);
  cpin[1] = 1;
  while (cpin[1] < 48 || cpin[1] > 58)
    cpin[1] = getch();
  printf("%c", cpin[1]);
  printf("/");
  m[i].dob[0] = (cpin[0] - 48) * 10 + cpin[1] - 48; // completed
  cpin[0] = 1;
  while (cpin[0] < 48 || cpin[0] > 58)
    cpin[0] = getch();
  printf("%c", cpin[0]);
  cpin[1] = 1;
  while (cpin[1] < 48 || cpin[1] > 58)
    cpin[1] = getch();
  printf("%c", cpin[1]);
  printf("/");
  m[i].dob[1] = (cpin[0] - 48) * 10 + cpin[1] - 48;
  for (j = 0; j < 4; j++)
  {
    cpin[j] = 1;
    while (cpin[j] < 48 || cpin[j] > 58)
      cpin[j] = getch();
    printf("%c", cpin[j]);
  }
  m[i].dob[2] = (cpin[0] - 48) * 1000 + (cpin[1] - 48) * 100 + (cpin[2] - 48) * 10 + cpin[3] - 48;
  printf("\t\t\t\t");

  if (m[i].dob[0] > 31 || m[i].dob[1] > 12 || m[i].dob[1] == 0 || m[i].dob[2] < 1900 || m[i].dob[2] > 2024)
  {
    set(0);
    goto dob;
  }
}
int blank(u)
{

  for (J = 0; J < u; J++)
    printf(" ");
    
}

int acc_update()
{
  j = i;
  i = in;
  switch (a)
  {
  case 49:
    set(0);
    blank(50);
    set(0);
    scanf(" %[^\n]", m[i].name);

    break;
  case 50:
    set(1);
    blank(50);
    set(1);
    DOB();

    break;
  case 51:
    set(2);
    blank(50);
    set(2);
    aadhar_number();

    break;
  case 52:
    set(3);
    blank(50);
    set(3);
    phone_number();

    break;
  case 53:
    set(4);
    blank(50);
    set(4);
    pan_number();

    break;
  case 54:
    set(5);
    blank(50);
    set(5);
    printf("6] address:- ");
    scanf(" %[^\n]", m[i].address);

    break;
  }
  i = j;
  system("cls");
}

int aadhar_number()
{
  set(2);
  printf("3] aadhar no.:- ");

  get(0);

  j = 0;    // aadhar
  while (1) // this is for no alphabates
  {
    ch = getch();

    if (j == 12)
      break;

    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[j] = ch;
      printf("%c", ch);
      j++;
    }
  }

  cpin[j] = '\0';
  m[i].aadhar = atoll(cpin);
}
int phone_number()
{
  set(3);
  printf("4] phone number:- "); // phone number start

  get(0);
  j = 0;
  while (1)
  {
    
    if (j == 10)
   {
     j++; 
      break;
   }
      ch = getch();
    if (j==0 && ch<54|| ch >57 )
    continue;


    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }

  cpin1[j] = '\0';

  m[i].phone_number = atoll(cpin1);
}

int pan_number()
{
  set(4);
  printf("5] pan number:- "); // pan  number
  get(0);
  j = 0;
  while (1)
  {
    if (j == 10)
      break;
    ch = getch();

    if ((j < 5 || j == 9) && ch >= 'a' && ch <= 'z')
    {
      m[i].pan[j] = ch - 32;
      printf("%c", m[i].pan[j]);
      j++;
    }
    else if (j > 4 && j < 9 && ch >= '0' && ch <= '9')
    {
      m[i].pan[j] = ch;
      printf("%c", m[i].pan[j]);
      j++;
    }
    else if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
    }
  }
}


int transection()
{

  printf("account number:- ");
  j = 0;
  while (1)
  {

    if (j == 4)
      break;

    ch = getch();
    if (ch == 27 || ch==32)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch==27)
 home();
 if (ch==32)
 {
  acc();
  transection();
 }
  cpin1[j] = '\0';

  temp_acc_number = atoi(cpin1);
  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number)
    {
      in = j;
      j = 33;
      break;
      // cheak how many digit is acc no.
    }
  }

  printf("\n\n%s",m[in].name);

  if (j == 33)
  {
    printf("\n\n1] Deposite");
    printf("\n2] Witndraw");
    printf("\n3] send ");
  
   while(1)
   {
    a = getch();
   if (a > 48 && a < 52)
   break;
   }
    switch (a)
    {
    case '1':
      deposite();
      break;
    case '2':
      withdraw();
      break;
    case '3':
      send1();
      break;
    }
  }
  else
  {
    system("cls");
    transection();
  }
}

int send1()
{
  u=in;
  system("cls");
  printf("SEND\n\n");

  printf("account number:- ");
  j = 0;
  while (1)
  {

if (j == 4)
    {
      break;
    }
    ch = getch();
    
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch==27)home();

  cpin1[j] = '\0';
  temp_acc_number = atoi(cpin1);

  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number)
      in = 0;
  }
  if (in == 0)
  {
    in = j - 1;

    printf("\nname:- %s\n", m[in].name);
    printf("amount:- ");
    j = 0;
    while (1)
    {
      ch = getch();
      if (ch == 13 || ch == 27)
      {
        break;
      }
      if (ch == 8 && j > 0)
      {
        printf("\b \b");
        j--;
        continue;
      }

      if (ch >= '0' && ch <= '9')
      {
        cpin1[j] = ch;
        printf("%c", ch);
        j++;
      }
    }
    if (ch == 27)
    home();

    cpin1[j] = '\0';
    h[in][I[in]].transfer = atoll(cpin1);
    
    m[in].acc_balance += h[in][I[in]].transfer;
    m[u].acc_balance -= h[in][I[in]].transfer;
    h[u][I[u]].transfer = h[in][I[in]].transfer;
   h[in][I[in]].balance = m[in].acc_balance;
   h[u][I[u]].balance =  m[u].acc_balance;
    Time();
    in = u;
    Time();
    I[in]++;
    I[u]++;

    printf("\ndone");
  }
  else
    send1();
  while (1)
  {
    a = getch();
    if (a == 27)
    break;
  }
  
  home();
}

void loan()
{
  printf("LOAN\n\n");
  printf("account number:- ");
  j = 0;
  while (1)
  {

    ch = getch();
    if (ch == 24)
    {
      break;
    }
    if (ch == 8 && j > 0)
    {
      printf("\b \b");
      j--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin1[j] = ch;
      printf("%c", ch);
      j++;
    }
  }
  if (ch==27)
  home();

  cpin1[j] = '\0';
  temp_acc_number = atoi(cpin1);

  for (j = 0; j < i; j++)
  {
    if (temp_acc_number == m[j].acc_number)
      in = 0;
  }
  if (in == 0)
  {
    in = j - 1;
    l[L].acc_number = m[in].acc_number;
    printf("\nname:- %s\n", m[in].name);
    printf("employment status:-\n");
    printf("1] employed\n2] self-employed\n3] unemployed ");
    while (1)
    {
      a = getch();
      if (a == 1)
      {
        strcpy(l[L].employment_status, "employed");
        break;
      }
      else if (a == 2)
      {
        strcpy(l[L].employment_status, "self-employed");
        break;
      }
      else if (a == 3)
      {
        strcpy(l[L].employment_status, "unemployed");
        break;
      }
    }
    if (a != 3)
    {
      printf("\nmonthly income :- ");
      j = 0;
      while (1)
      {
        a = getch();
        if (a == 8)
        {
          printf("\b \b");
          j--;
          continue;
        }
        if (a < 58 && a > 48)
        {
          cpin1[j] = a - 48;
          printf("%C", a);
          j++;
        }
        if (a == 13)
        {
          break;
        }
      }
      cpin1[j] = '\0';
      l[L].m_income = atoll(cpin1);
    }
    printf("\nloan amount repuest:-");
    j = 0;
    while (1)
    {
      ch = getch();
      if (ch == 8)
      {
        printf("\b \b");
        j--;
        continue;
      }
      if (ch < 58 && ch > 48)
      {
        cpin1[j] = ch - 48;
        printf("%c", ch);

        j++;
      }
      if (ch == 13)
      {
        break;
      }
    }
    cpin1[j] = '\0';
    l[L].l_amount = atoll(cpin1);
    printf("\npurpose of the loan:- ");
    scanf("[^\n]", l[L].l_purpose[55]);

    printf("type of loan:- ");
    scanf("[^\n]", l[L].l_type[22]);
    time(&t);
    struct tm *current_time = localtime(&t);

    l[L].ldate[0] = current_time->tm_year + 1900;
    l[L].ldate[1] = current_time->tm_mon + 1;
    l[L].ldate[2] = current_time->tm_mday;
    loanc();
    L++;
  }

  printf("repay date:- ");
Rdate:
  get(0);
  printf("2] date of birth:- dd/mm/yyyy\b\b\b\b\b\b\b\b\b\b");
  cpin[0] = 1;
  while (cpin[0] < 48 || cpin[0] > 58)
    cpin[0] = getch();
  printf("%c", cpin[0]);
  cpin[1] = 1;
  while (cpin[1] < 48 || cpin[1] > 58)
    cpin[1] = getch();
  printf("%c", cpin[1]);
  printf("/");
  l[L].rdate[0] = (cpin[0] - 48) * 10 + cpin[1] - 48; // completed
  cpin[0] = 1;
  while (cpin[0] < 48 || cpin[0] > 58)
    cpin[0] = getch();
  printf("%c", cpin[0]);
  cpin[1] = 1;
  while (cpin[1] < 48 || cpin[1] > 58)
    cpin[1] = getch();
  printf("%c", cpin[1]);
  printf("/");
  l[L].rdate[1] = (cpin[0] - 48) * 10 + cpin[1] - 48;
  for (j = 0; j < 4; j++)
  {
    cpin[j] = 1;
    while (cpin[j] < 48 || cpin[j] > 58)
      cpin[j] = getch();
    printf("%c", cpin[j]);
  }
  l[L].rdate[2] = (cpin[0] - 48) * 1000 + (cpin[1] - 48) * 100 + (cpin[2] - 48) * 10 + cpin[3] - 48;
  printf("\t\t\t\t");

  if (l[L].rdate[0] > 31 || l[L].rdate[1] > 12 || l[L].rdate[1] == 0 || l[L].rdate[2] < 1900 || l[L].rdate[2] > 2025)
  {
    set(0);
    goto Rdate;
  }
  while(1){
  ch=getch();
  if (ch==27)
  break;
  }
  home();
}
void loanc()
{
  in = 10;
  Time();
  for (j = 0; j < L; j++)
  {
    if (h[in][I[in]].tdate[0] == l[L].rdate[0] && h[in][I[in]].tdate[1] == l[L].rdate[1] && h[in][I[in]].tdate[2] == l[L].rdate[2])
    {
      int A;
      float p, r = 0.01;

      l[L].l_amount = pow(p * (1 + r), 1 / 30);
    }
  }
}


void acc()
{
  for (j=0;j<i;j++)
  {
    printf("\n\n%s",m[j].name);
p=strlen(m[j].name);
blank(30-p);
printf("%d\n\n",m[j].acc_number);

  }
  j=0;
  while(1)
  {
    ch=getch();
    if (ch==32)break;
  }
  system("cls");
}
