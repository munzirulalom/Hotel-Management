#include<stdio.h>
#include<conio.h>
struct user
{
    char name[100];
    char username[50];
    char email[50];
    char password[100];
    char nid[50];
    char address[100];
    char nationality[20];
};

int food_menu()
{

}

int ac_room_list()
{
    system("CLS");
    printf("AC Room List");
}

int non_ac_room_list()
{

}

int room_menu()
{
    system("CLS");
    int rm;
    printf("1. AC Room\n2. Non AC Room\n");
    printf("Enter choice: "); scanf("%d", &rm);
    if(rm==1)
        ac_room_list();
    else if(rm==2)
        non_ac_room_list();
    else
        printf("Invalid Input!");
}
int user_menu()
{
    system("CLS");
    int a;
    printf("\t\t### User Menu ###\n");
    printf("1. Book Room\n2. Order Food\n3. Order History\n4. User Profile\n5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &a);

    switch(a)
    {
        case 1:
            room_menu();
            break;
        case 2:
            food_menu();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            break;
        default:
            printf("Error! Invalid input.");
    }

}
int admin_login()
{
    printf("Enter your username: ");
    printf("Enter your password: ");
}

int user_login()
{
    char username[50], password[100];


    FILE *log;
    log = fopen("user_info.txt", "r");
    struct user login;
    printf("Username: ");scanf("%s", &username);
    printf("Password: ");scanf("%s", &password);

    /*
    while(fread(&login, sizeof(login), 1, log))
    {
        if(strcmp(username,login.username)==0 && strcmp(password,login.password)==0)
            printf("User Login Succesful\n");
        else
        {
            printf("Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("CLS");
            user_login();
        }
    }
    */
    fclose(log);

    user_menu();
}

int registation()
{
    FILE *reg;
    reg = fopen("user_info.txt", "w");
    struct user add;

    printf("Enter username: ");scanf("%s", add.username);
    printf("Enter your name: ");scanf("%s", add.name);
    printf("Enter your email: ");scanf("%s", add.email);
    printf("Enter a password: ");scanf("%s", add.password);
    printf("Enter your NID/Passport no: ");scanf("%s", add.nid);
    printf("Enter your address: ");scanf("%s", add.address);
    printf("Enter your nationality: ");scanf("%s", add.nationality);

    fwrite(&add, sizeof(add), 1, reg);
    fclose(reg);

    printf("\tRegistation Sussefull\nPress any key to Login...");
    getch();
    system("CLS");
    user_login();
}



int main()
{
    int n;
    printf("1. User System\n2. Admin System\n\n");
    printf("Enter your choice: "); scanf("%d", &n);
    system("CLS");
    if(n==1)
    {
        printf("1. Login\n2. Registation\n");
        printf("Enter choice: "); scanf("%d", &n);
        system("CLS");
        if(n==1)
            user_login();
        if(n==2)
            registation();
    }
    else if(n==2)
        admin_login();
    else
        printf("Invalid Input!\n");

    return 0;
}
