#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int acc_date[5], dob[5], b, acc_type;
char a, name[55], pan[22], pin1, ch, cpin[20], username[20], address[111];
long long int aadhar, phone_number;
int i, acc_number, pin, temp_acc_number;

void login(void);
void home(void);
void deposite(void);
void create_account(void);
void acc_details(void);
void withdraw(void);
void history(void);

int main()
{

  login();
  home();

  return 0;
}

void home()
{
b:
  printf("\n\n\t\t\t\t\t\tSTUDENT BANK OF MIT\n\n\n");

  printf("1] create new account\n\n");
  printf("2] cheack account details\n\n");
  printf("3] update account details\n\n");
  printf("4] deposite cash\n\n");
  printf("5] withdraw cash\n\n");
  printf("6] view transection history\n\n\n\n\n\n\n\n");

  printf("enter option number (ex.4):-");

  a = getch();
  system("cls");

  switch (a)
  {
  case '1':
    create_account();
    break;

  case '2':
    acc_details();
    break;

  case '3':
    deposite();
    break;

  case '4':
    withdraw();
    break;

  case '5':
    history();
    break;

  default:
    system("cls");
    home();
  }
}

void create_account()
{
tdate:
  printf("Today's date(dd/mm/yyyy);"); // add no alphabates
  scanf("%d/%d/%d", &acc_date[0], &acc_date[1], &acc_date[2]);

  if (acc_date[0] > 30 || acc_date[1] > 12 || acc_date[1] < 1 || acc_date[2] < 1900 || acc_date[2] > 2024)
  {
    printf("invalid date\n");
    goto tdate;
  }

  printf("\nEnter your name: ");
  scanf(" %[^\n]", name);

bdate:
  printf("\nDate of birth:");
  scanf("%d/%d/%d", &dob[0], &dob[1], &dob[2]); // add no alphabates

  if (dob[0] > 31 || dob[1] > 12 || dob[1] == 0 || dob[2] < 1900 || dob[2] > 2024)
  {
    printf("invalid date\n");
    goto bdate;
  }

aadhar:
  printf("\nAadhar no.:-");
  i = 0;    // aadhar
  while (1) // this is for no alphabates
  {
    ch = getch();

    if (ch == 13)
      break;

    if (ch == 8 && i > 0)
    {
      printf("\b \b");
      i--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[i] = ch;
      printf("%c", ch);
      i++;
    }
  }

  cpin[i] = '\0';
  aadhar = atoll(cpin);

  printf("\n\nPan no.:-"); // pan  number
  scanf("%s", &pan);

ph:
  printf("\nphone number:-");
  i = 0; // phone number start
  while (1)
  {
    ch = getch();

    if (ch == 13)
      break;

    if (ch == 8 && i > 0)
    {
      printf("\b \b");
      i--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[i] = ch;
      printf("%c", ch);
      i++;
    }
  }

  cpin[i] = '\0';
  phone_number = atoll(cpin);

  if (phone_number < 1000000000 || phone_number > 9999999999 || phone_number / 1000000000 < 7 || phone_number / 1000000000 > 9)
  {
    printf("INVALID NUMBER!\n");
    goto ph;
  }

  printf("\n\naddresse:- ");
  scanf(" %[^\n]", address);

  printf("\n\n1] current\n2] saving\n3] fixed\n\n");
  printf("type of account:");
  scanf("%d", &b);
  acc_type = b;

  for (i = 0; i < 1; i++)
  {
    if (b > 3)
    {
      printf("invalid option\n");
      printf("\ntype of account:");
      scanf("%d", &b);
      i--;
    }
  }
  if (b == 3)
  {
    printf("\n1] for 1 year\n2] for 2 year\n3] for 3 year\n\n");
    scanf("%d", &b);
    acc_type = 30 + b; // ex(33 for fixed account for 3 year)
    for (i = 0; i < 1; i++)
    {
      if (b > 3)
      {
        printf("invalid option\n");
        printf("\ntype of account:");
        scanf("%d", &b);
        i--;
      }
    }
  }

  system("cls");
  srand(time(NULL));
  acc_number = (rand() % 100000) + 89789;

  printf("\nyour account created succesesfully\n");
  printf("your account number is  %d\n\n", acc_number);
  printf("\n\n\n\n\n\n\t\t\t\t\tenter 1 for main manu or 0 to close:-");
  a = getch();

  if (a == '1')
  {
    system("cls");
    home();
  }
}

void deposite() //  deposite function
{

  system("cls");
  int temp_acc_number, balance, deposite;
  char tempf[22], tempm[22], templ[22], temp_pin[22];
  printf("\n\nenter account number:-");
  scanf("%d", &temp_acc_number);

  for (i = 0; i < 1; i++)
  {
    if (acc_number != temp_acc_number)
    {
      printf("account does not exist"); // we can do something different here
      printf("enter account number;-");
      scanf("%d", &temp_acc_number);
    }
  }
  printf("\nenter pin;-");
  scanf("%s", &temp_pin);
  for (i = 0; i < 1; i++)
  {
    if (pin != temp_pin)
    {
      printf("wrong pin");
      printf("enter pin;-");
      scanf("%s", &temp_pin);
    }
  }

  printf("\nenter amount:-");
  scanf("%li", &deposite);
  printf("\ntransection successfull");
}

void login()
{

  printf("\n\n\t\t\t\tUsername:- ");
  scanf("%s", username);

pin:

  printf("\n\t\t\t\tEnter your PIN: "); // pin start
  i = 0;
  while (1)
  {
    ch = getch();

    if (ch == 13)
      break;
    if (ch == 8 && i > 0)
    {
      printf("\b \b");
      i--;
      continue;
    }

    if (ch >= '0' && ch <= '9')
    {
      cpin[i] = ch;
      printf("*");
      i++;
    }
  }

  cpin[i] = '\0';
  int pin = atoi(cpin);

  if (pin < 1000)
  {
    printf("\npin must have least 4 digit\n");
    goto pin;
  }
  system("cls");
}

void acc_details()
{
  printf("\n\n\t\t\t\t\account details\n");
acc_num:
  printf("account number:- ");
  scanf("%d", &temp_acc_number);
  if (temp_acc_number == 1)
  {
    system("cls");  
    home();
  }
  if (temp_acc_number != acc_number)
  {
    printf("account does not exist");
    goto acc_num;
  }
  if (temp_acc_number == 1)
    home();
  printf("\n\n1] NAME:- %s\n\n\n", name);
  printf("2] date of birth:- %d/%d/%d\n\n\n", dob[0], dob[1], dob[2]);
  printf("4] aadhar number:- %d\n\n\n", aadhar);
  printf("5] phone number:- %d\n\n\n", phone_number);
  printf("6] pan number:- %s\n\n\n", pan);
  printf("7] address:- %s\n\n\n", address);
  printf("type of account:- ");
  switch (b)
  {
  case 1:
    printf("current");
    break;
  case 2:
    printf("saving");
    break;
  default:
    printf("fixed for %d year", b);
  }
  a = getch();
  if (a == '1')
  {
    system("cls");
    home();
  }
}

void withdraw() {}
void history() {}
