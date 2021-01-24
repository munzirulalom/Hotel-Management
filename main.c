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
int dinner_food_list()
{
    system("CLS");
    printf("Dinner Food List");
    getch();
    user_menu();
}
int snacks_food_list()
{
    system("CLS");
    printf("                     ######  ###    ##     ##       #####   ##   ##   ######    \n");
    printf("                    #        ## #   ##    ####     ##    #  ## ##    #          \n");
    printf("                     #####   ##  #  ##   ##  ##    ##       ###       #####     \n");
    printf("                          #  ##   # ##  ## ## ##   ##    #  ## ##          #    \n");
    printf("                    ######   ##    ### ##      ##   #####   ##   ##  ######     \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Berger          --  250 tk      ##\n" );
    printf("\t\t2.      Sandwich        --  180 tk      ##\n" );
    printf("\t\t3.      Beef Stick      --  350 tk      ##\n" );
    printf("\t\t4.      Nachos          --  200 tk      ##\n" );
    printf("\t\t5.      Sicilian Pizza  --  550 tk      ##\n" );
    printf("\t\t6.      Mango Juces     --  80  tk      ##\n" );
    printf("\t\t7.      Chicken Fry     --  450 tk      ##\n" );
    printf("\t\t8.      Water 1 Lt.     --  50  tk      ##\n" );
    printf("\t\t9.      Water 2 Lt.     --  95  tk      ##\n" );

    getch();
    food_menu();
}
int lunch_food_list()
{
    system("CLS");
    printf("                    ##       ##   ##  ###    ##   #####   ##    ##  \n");
    printf("                    ##       ##   ##  ## #   ##  ##    #  ##    ##  \n");
    printf("                    ##       ##   ##  ##  #  ##  ##       ########  \n");
    printf("                    ##    #  ##   ##  ##   # ##  ##    #  ##    ##  \n");
    printf("                    ######    #####   ##    ###   #####   ##    ##  \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Rice        --      60  tk      ##\n" );
    printf("\t\t2.      Fried Rice  --      250 tk      ##\n" );
    printf("\t\t3.      Beef        --      360 tk      ##\n" );
    printf("\t\t4.      Mutton      --      450 tk      ##\n" );
    printf("\t\t5.      Pulses      --      40  tk      ##\n" );
    printf("\t\t6.      Kabab       --      160 tk      ##\n" );
    printf("\t\t7.      Fish        --      250 tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );
    printf("\t\t9.      Chicken     --      280 tk      ##\n" );
    getch();
    food_menu();
}
int breakfast_food_list()
{
    system("CLS");
    printf("            #####   #####   #####      ##       #####   ##   ##  #####     ##      #####   ######## \n");
    printf("            ##  ##  ##  ##  ##        ####     ##    #  ## ##    ##       ####    #           ##    \n");
    printf("            #####   #####   #####    ##  ##    ##       ###      #####   ##  ##    #####      ##    \n");
    printf("            ##  ##  ## ##   ##      ## ## ##   ##    #  ## ##    ##     ## ## ##        #     ##    \n");
    printf("            #####   ##  ##  #####  ##      ##   #####   ##   ##  ##    ##      ##  #####      ##    \n\n");
    printf("###############################################################################################################\n\n");
    printf("\t\t##      Name        ##      Price       ##\n" );
    printf("\t\t------------------------------------------\n" );
    printf("\t\t1.      Bread       --      100 tk      ##\n" );
    printf("\t\t2.      Eggs        --      60  tk      ##\n" );
    printf("\t\t3.      Coffee      --      200 tk      ##\n" );
    printf("\t\t4.      Green Tea   --      150 tk      ##\n" );
    printf("\t\t5.      Normal Tea  --      80  tk      ##\n" );
    printf("\t\t6.      Nuts        --      500 tk      ##\n" );
    printf("\t\t7.      Nun Bread   --      70  tk      ##\n" );
    printf("\t\t8.      Vegetable   --      50  tk      ##\n" );

    getch();
    food_menu();

    getch();
    user_menu();
}
int food_menu()
{
    system("CLS");
    int fm;
    printf("1. Breakfast\n2. Lunch\n3. Snacks\n4. Dinner\n5. Food Menu\n6. Main Menu\n");
    printf("Enter Choice: "); scanf("%d", &fm);
    switch (fm)
    {
    case 1:
        breakfast_food_list();
        break;
    case 2:
        lunch_food_list();
        break;
    case 3:
        snacks_food_list();
        break;
    case 4:
        dinner_food_list();
        break;
    case 5:
        food_menu();
        break;
    case 6:
        user_menu();
        break;
    default:
        printf("Invalid Input! [Food Menu]");

    }
}

int ac_room_list()
{
    system("CLS");
    printf("AC Room List");
    getch();
    user_menu();
}

int non_ac_room_list()
{
    system("CLS");
    printf("AC Room List");
    getch();
    user_menu();
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
