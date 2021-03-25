#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char username[50];
int item_id=0;

struct hotel
{
    char name[50];
    char features[100];
    char location[50];
    char phone[15];
    char email[25];
} hotel_inf;
struct admin
{
    char name[100];
    char username[50];
    char password[100];
    char email[50];
    char nationality[20];
} admin_nfo;
struct user
{
    char name[100];
    char username[50];
    char email[50];
    char password[100];
    char nid[50];
    char address[100];
    char nationality[20];
} user_info;
struct employee
{
    int id;
    char name[100];
    char address[100];
    long salary;
} employee_info;
struct room
{
    int no;
    char name[50];
    char features[200];
    int type;
    int price;
    int status;
} room_info;
struct food
{
    int code;
    char name[50];
    char description[200];
    int price;
    int category;
    int status;
} food_info;
struct order
{
    int or_id;
    char or_name[100];
    char or_type[50];
    char or_user[100];
    char or_payment[10];
    int or_status;
    long int or_price;
    int item_id;
    char in_date[25];
    char out_date[25];
    int item_count;
    int adult_count;
    int children_count;
} order_info;
struct payment
{
    int no;
    int code;
    char expire;
} payment_info;

//All Function
void hotel_info();
void dis_hotel_info();

void login();
void registration();
void main_menu();
void employee_menu();
void room_menu();
void food_menu();
void user_menu();

void add_room();
void room_list();
void update_room();
void delete_room();
void room_search();

void add_food();
void food_list();
void update_food();
void delete_food();
void food_search();

void user_list();
void update_user();
void delete_user();
void user_search();

void add_employee();
void employee_list();
void update_employee();
void delete_employee();
void employee_search();

void order_search();
void order_room();
void order_details();
void order_food();
void user_order_history();
void update_order_status();

void payment();
void card();
void m_banking();

void thanks();
void update_order();
void order_room_update();


void top()
{
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\n");

    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1     \xB1\xB1\xB1\xB1\xB1\xB1\xB1     \xB1\xB1\xB1\xB1\xB1               \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1  \xB1\xB1\xB1\xB1\xB1  \xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1  \xB1\xB1\xB1  \xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1  \xB1  \xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1                \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1               \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");
    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1   \xB1\xB1\xB1\xB1\xB1               \xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n");

    printf("\t\t\t\t\t\t\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1 \n\n");
}

/*
    ==================================================================================
                                Contact Function
    ==================================================================================
*/
void contact()
{
    system("CLS");
    top();
    printf("\n\n");
    printf("\t\t\t\t\t :::::::::: Hotel Management System ::::::::::\n\n");
    printf("\t\t\t\t\t\t Name: D.M. Ajmain Shariar\tID: 19202103308\t\tEmail: ajmainshariar77@gmail.com\n");
    printf("\t\t\t\t\t\t Name: MD Mahabub Morshed\tID: 19202103298\t\tEmail: mdmahabubmorshed876@gmail.com\n");
    printf("\t\t\t\t\t\t Name: Munzirul Alom\t\tID: 19202103303\t\tEmail: cse.alomb008@gmail.com\n");

    getch();
    main_menu(1);
}

/*
    ==================================================================================
                                Registration Function
    ==================================================================================
*/
void registration(int n)
{
    top();
    if(n==1)
    {
        n=0;
        FILE *reg;
        reg = fopen("admin.txt", "ab+");

        printf("\t\t\t\t\t\t Enter username: ");scanf("%s", &admin_nfo.username);
        printf("\t\t\t\t\t\t Enter your name: ");scanf("%s", &admin_nfo.name);
        printf("\t\t\t\t\t\t Enter your email: ");scanf("%s", &admin_nfo.email);
        printf("\t\t\t\t\t\t Enter a password: ");scanf("%s", &admin_nfo.password);
        printf("\t\t\t\t\t\t Enter your nationality: ");scanf("%s", &admin_nfo.nationality);

        fwrite(&admin_nfo, sizeof(admin_nfo), 1, reg);
        fclose(reg);

        printf("\t\t\t\t\t\tRegistration Successful\n\n");
        printf("\t\t\t\t\t\t Press any key to Login...");
        getch();
        system("cls");
        login(1);
    }
    else if (n == 2)
    {
        n=0;
        FILE *reg;
        reg = fopen("user.txt", "ab+");

        printf("\t\t\t\t\t\t Enter username: ");scanf("%s", &user_info.username);
        printf("\t\t\t\t\t\t Enter your name: ");scanf("%s", &user_info.name);
        printf("\t\t\t\t\t\t Enter your email: ");scanf("%s", &user_info.email);
        printf("\t\t\t\t\t\t Enter a password: ");scanf("%s", &user_info.password);
        printf("\t\t\t\t\t\t Enter your NID/Passport no: ");scanf("%s", &user_info.nid);
        printf("\t\t\t\t\t\t Enter your address: ");scanf("%s", &user_info.address);
        printf("\t\t\t\t\t\t Enter your nationality: ");scanf("%s", &user_info.nationality);

        fwrite(&user_info, sizeof(user_info), 1, reg);
        fclose(reg);

        printf("\t\t\t\t\t\tRegistration Successful\n\n");
        printf("\t\t\t\t\t\t Press any key to Login...");
        getch();
        system("cls");
        login(2);
    }
}

/*
    ==================================================================================
                                Login Function
    ==================================================================================
*/
void login(int n)
{
    top();
    char password[100];
    int flag;
    FILE *log;

    if(n==1) //Admin Login
    {
        flag=0;
        log = fopen("admin.txt", "rb");

        if (log == NULL)
        {
            printf("\t\t\t\t\t\t Error: Unable to open file.\n");
            exit(1);
        }

        printf("\t\t\t\t\t\t Username: ");scanf("%s", &username);
        printf("\t\t\t\t\t\t Password: ");scanf("%s", &password);

        while(fread(&admin_nfo, sizeof(admin_nfo), 1, log) && flag==0)
        {
            if(strcmp(admin_nfo.username,username)==0 && strcmp(admin_nfo.password,password) == 0)
            {
                flag=1;
                printf("\n\t\t\t\t\t\tAdmin Login Successful\n\n");
            }
        }
        fclose(log);
        if(flag==1)
            main_menu(1);
        else if(flag==0)
        {
            printf("\t\t\t\t\t\t Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("cls");
            login(1);
        }
    }
    else if(n==2) //User Login
    {
        flag=0;
        log = fopen("user.txt", "rb");

        if (log == NULL)
        {
            printf("\t\t\t\t\t\t Error: Unable to open file.\n");
            exit(1);
        }

        printf("\t\t\t\t\t\t Username: ");scanf("%s", &username);
        printf("\t\t\t\t\t\t Password: ");scanf("%s", &password);

        while(fread(&user_info, sizeof(user_info), 1, log) && flag==0)
        {
            if(strcmp(username,user_info.username)==0 && strcmp(password,user_info.password) == 0)
            {
                flag=1;
                printf("\n\t\t\t\t\t\tUser Login Successful\n\n");
            }
        }
        fclose(log);

        if(flag==1)
            main_menu(2);
        else if(flag == 0)
        {
            printf("\t\t\t\t\t\t Incorrect Username or Password. Please Try again\nPress any key to try again...");
            getch();
            system("cls");
            login(2);
        }
    }

}

/*
    ==================================================================================
                                    Main Function
    ==================================================================================
*/
int main()
{
    int n;

    top();
    printf("\t\t\t\t\t\t 1. Admin System\n");
    printf("\t\t\t\t\t\t 2. User System\n\n");
    printf("\t\t\t\t\t\tEnter choice: ");
    scanf("%d", &n);

    system("cls");
    top();
    if(n==1) //Admin Login and Registration
    {
        n=0;
        printf("\t\t\t\t\t\t 1. Login\n");
        printf("\t\t\t\t\t\t 2. Registration\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &n);
        system("cls");
        if(n==1)
            login(1);
        else if(n==2)
            registration(1);
        else
            printf("\t\t\t\t\t\t Error: Invalid input");
    }
    else if(n==2) //User Login and Registration
    {
        n=0;
        printf("\t\t\t\t\t\t 1. Login\n");
        printf("\t\t\t\t\t\t 2. Registration\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &n);
        system("cls");
        if(n==1)
            login(2);
        else if(n==2)
            registration(2);
        else
            printf("\t\t\t\t\t\t Error: Invalid input");
    }
    else
        printf("\t\t\t\t\t\t Error: Invalid input");

    return 0;
}

/*
    ==================================================================================
                                Main Menu Function
    ==================================================================================
*/
void main_menu(int n)
{
    system("cls");
    top();

    if(n==1) //Admin Main Menu
    {
        n=0;
        int m;
        printf("\t\t\t\t\t\t ::::::::::Admin Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. Hotel\n");
        printf("\t\t\t\t\t\t 2. Checkout\n");
        printf("\t\t\t\t\t\t 3. Order\n");
        printf("\t\t\t\t\t\t 4. Room\n");
        printf("\t\t\t\t\t\t 5. Food\n");
        printf("\t\t\t\t\t\t 6. Employee\n");
        printf("\t\t\t\t\t\t 7. User\n");
        printf("\t\t\t\t\t\t 8. Hotel Info\n");
        printf("\t\t\t\t\t\t 9. Contact\n");
        printf("\t\t\t\t\t\t 10. Logout\n\n");
        printf("\t\t\t\t\t\t Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            hotel_info();
            main_menu(1);
            break;
        case 2:
            system("cls");
            top();
            printf("\t\t\t\t\t\t ::::::::::Checkout Room::::::::::\n\n");
            printf("\t\t\t\t\t\t Enter Room No: ");scanf("%d", &item_id);
            order_room_update(0); //Update Room Status to Avalabile
            printf("\t\t\t\t\t\t Room no: %d checkout successful. Press any key to continue.....", item_id);
            getch();
            main_menu(1);
            break;
        case 3:
            m=0;
            system("cls");
            top();
            printf("\t\t\t\t\t\t 1. Search by ID\n");
            printf("\t\t\t\t\t\t 2. Confirmed Order List\n");
            printf("\t\t\t\t\t\t 3. Pending Order List\n");
            printf("\t\t\t\t\t\t 4. Update Order\n");
            printf("\t\t\t\t\t\t 5. Main Menu\n\n");
            printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

            if(m==1) order_search(0);
            else if(m==2) order_search(1);
            else if(m==3) order_search(2);
            else if(m==4) update_order_status(1);

            getch();
            main_menu(1);
            break;
        case 4:
            room_menu(1);
            break;
        case 5:
            food_menu(1);
            break;
        case 6:
            employee_menu(1);
            getch();
            main_menu(1);
            break;
        case 7:
            user_menu(1);
            break;
        case 8:
            dis_hotel_info();
            main_menu(1);
            break;
        case 9:
            contact();
            break;
        case 10:
            system("CLS");
            main();
            break;
        default:
            printf("\t\t\t\t\t\t Error: Invalid input...");
        }

    }
    else if(n==2) //user Menu
    {
        n=0;
        int m;
        printf("\t\t\t\t\t\t :::::::::User Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. Book Room\n");
        printf("\t\t\t\t\t\t 2. Order Food\n");
        printf("\t\t\t\t\t\t 3. Order History\n");
        printf("\t\t\t\t\t\t 4. User Profile\n");
        printf("\t\t\t\t\t\t 5. Hotel Info\n");
        printf("\t\t\t\t\t\t 6. Logout\n\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

        switch(m)
        {
            case 1:
                room_menu(2);
                break;
            case 2:
                food_menu(2);
                break;
            case 3:
                user_order_history();
                getch();
                main_menu(2);
                break;
            case 4:
                system("cls");
                top();
                m=0;
                printf("\t\t\t\t\t\t 1. View Profile\n");
                printf("\t\t\t\t\t\t 2. Edit Profile\n");
                printf("\t\t\t\t\t\t 3. Change Password\n");
                printf("\t\t\t\t\t\t Enter your choice: ");scanf("%d", &m);

                if(m==1) user_search(2);
                else if(m==2) update_user(2);
                else if(m==3) update_user(3);
                else printf("\t\t\t\t\t\t Invalid Input...");
                getch();
                main_menu(2);
                break;
            case 5:
                dis_hotel_info();
                main_menu(2);
                break;
            case 6:
                system("cls");
                main();
                break;
            default:
                printf("\t\t\t\t\t\t Error! Invalid input.");
        }
    }

}

/*
    ==================================================================================
                                    Hotel Function
    ==================================================================================
*/
void hotel_info(int n)
{
    system("cls");
    top();

    printf("\t\t\t\t\t\t ::::::::::Update Hotel Information ::::::::::\n\n");

    FILE *fptr;
    FILE *temp;

    char filename[15]="hotel.txt";

    fptr  = fopen(filename, "rb+");
    temp = fopen("temp-hotel.tmp", "wb+");

    if (fptr == NULL || temp == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.\n");
        exit(1);
    }


    while(fread(&hotel_inf, sizeof(hotel_inf), 1, fptr))
    {
        printf("\t\t\t\t\t\t Update Hotel Name: ");scanf("%s", &hotel_inf.name);
        printf("\t\t\t\t\t\t Update Hotel Features: ");scanf("%s", &hotel_inf.features);
        printf("\t\t\t\t\t\t Update Hotel Phone No: ");scanf("%s", &hotel_inf.phone);
        printf("\t\t\t\t\t\t Update Hotel Email: ");scanf("%s", &hotel_inf.email);
        printf("\t\t\t\t\t\t Update Hotel Location: ");scanf("%s", &hotel_inf.location);

        fwrite(&hotel_inf, sizeof(hotel_inf), 1, temp);
    }
    fclose(fptr);
    fclose(temp);

    remove(filename);
    rename("temp-hotel.tmp", filename);

    printf("\n\t\t\t\t\t\t Hotel Information Update Sussefully. Press any key to continue... ");
    getch();
}

/*
    ==================================================================================
                                    Display Hotel Info Function
    ==================================================================================
*/
void dis_hotel_info()
{
    system("cls");
    top();
    printf("\t\t\t\t\t\t ::::::::::Hotel Information ::::::::::\n\n");

    FILE *fptr;

    fptr  = fopen("hotel.txt", "rb");

    if (fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.\n");
        exit(1);
    }

    while(fread(&hotel_inf, sizeof(hotel_inf), 1, fptr))
    {
        printf("\t\t\t\t\t\t Enter Hotel Name: %s\n", hotel_inf.name);
        printf("\t\t\t\t\t\t Enter Hotel Features: %s\n", hotel_inf.features);
        printf("\t\t\t\t\t\t Enter Hotel Phone No: %s\n", hotel_inf.phone);
        printf("\t\t\t\t\t\t Enter Hotel Email: %s\n", hotel_inf.email);
        printf("\t\t\t\t\t\t Enter Hotel Location: %s\n", hotel_inf.location);
    }
    fclose(fptr);
    getch();
}

/*
    ==================================================================================
                                    Room Function
    ==================================================================================
*/
void room_menu(int n)
{
    system("cls");
    top();
    int m;

    if(n==1) //Admin Room Menu
    {
        n=m=0;
        printf("\t\t\t\t\t\t ::::::::::Admin Room Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. Add Room\n");
        printf("\t\t\t\t\t\t 2. Room List\n");
        printf("\t\t\t\t\t\t 3. Update Room\n");
        printf("\t\t\t\t\t\t 4. Delete Room\n");
        printf("\t\t\t\t\t\t 5. Search Room\n");
        printf("\t\t\t\t\t\t 6. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_room();
            getch();
            room_menu(1);
            break;
        case 2:
            system("cls");
            room_list();
            getch();
            room_menu(1);
            break;
        case 3:
            update_room();
            getch();
            room_menu(1);
            break;
        case 4:
            delete_room();
            getch();
            room_menu(1);
            break;
        case 5:
            system("cls");
            top();
            m=0;
            printf("\t\t\t\t\t\t 1. Search by Room no\n");
            printf("\t\t\t\t\t\t 2. AC Room\n");
            printf("\t\t\t\t\t\t 3. Non AC Room\n");
            printf("\t\t\t\t\t\t 4. Available Room\n");
            printf("\t\t\t\t\t\t 5. Not Available\n");
            printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);
            if(m==1) room_search(0);
            else if(m==2) room_search(1);
            else if(m==3) room_search(2);
            else if(m==4) room_search(3);
            else if(m==5) room_search(4);
            getch();
            room_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("\t\t\t\t\t\t Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=m=0;
        printf("\t\t\t\t\t\t ::::::::::User Room Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. AC Room\n");
        printf("\t\t\t\t\t\t 2. Non AC Room\n");
        printf("\t\t\t\t\t\t 3. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

        switch (m)
        {
        case 1:
            room_search(1,2);
            break;
        case 2:
            room_search(2,2);
            break;
        case 3:
            main_menu(2);
            break;
        default:
            printf("\t\t\t\t\t\t Error: Invalid Input");
        }


    }

}

/*
    ==================================================================================
                                    Admin Add Room Function
    ==================================================================================
*/
void add_room()
{
    system("cls");
    top();
    FILE *fptr = fopen("room.txt", "ab+");

    struct room add;

    printf("\t\t\t\t\t\t ::::::::::Add New Room::::::::::\n\n");
    printf("\t\t\t\t\t\t Enter Room No: ");scanf("%d", &add.no);
    printf("\t\t\t\t\t\t Enter Room Name: ");scanf("%s", &add.name);
    printf("\t\t\t\t\t\t Enter Room Features: ");scanf("%s", &add.features);
    printf("\t\t\t\t\t\t Enter Room Type (1. AC or 2. Non AC): ");scanf("%d", &add.type);
    printf("\t\t\t\t\t\t Enter Room Price: ");scanf("%d", &add.price);
    add.status = 0;

    fwrite(&add, sizeof(add), 1, fptr);
    fclose(fptr);

    printf("\n\n\n\t\t\t\t\t\tRoom No: %d\t|\tRoom Name: %s\t|\tRoom Features: %s\t|\tRoom Type: %d\t|\tRoom Price: %d tk\n\n", add.no, add.name, add.features, add.type, add.price);
    printf("\t\t\t\t\t\t Room Added Successful! Press any key to go Menu\n");

}

/*
    ==================================================================================
                                    Admin Room List Function
    ==================================================================================
*/
void room_list()
{
    FILE *fptr = fopen("room.txt", "rb");

    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.");
        exit(1);
    }
    struct room list;

    printf("\t\t\t\t\t\t ::::::::::Room List::::::::::\n\n");
    while(fread(&list, sizeof(list), 1, fptr))
    {
        printf("Room No: %d", list.no);
        printf("\t|\tRoom Name: %s", list.name);
        printf("\t|\tRoom Features: %s", list.features);
        printf("\t|\tRoom Type: ");
        if(list.type == 1)
            printf("AC");
        else if(list.type == 2)
            printf("Non AC");
        printf("\t|\tRoom Price: %d", list.price);
        printf("\t|\tRoom Status: ");
        if(list.status == 0)
            printf("Available");
        else if(list.status == 1)
            printf("Not Available");
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Room Function
    ==================================================================================
*/
void update_room()
{
    system("cls");
    top();
    room_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="room.txt";
    int delete_line;
    struct room add;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t Replace Room No: ");
    scanf("%d", &delete_line);


    while(fread(&add, sizeof(add),1,main_file) == 1)
    {
        if(add.no != delete_line)
            fwrite(&add, sizeof(add), 1, temp_file);
        else if(add.no == delete_line)
        {
            printf("\t\t\t\t\t\t Updated Room No: ");scanf("%d", &add.no);
            printf("\t\t\t\t\t\t Updated Room Name: ");scanf("%s", &add.name);
            printf("\t\t\t\t\t\t Updated Room Features: ");scanf("%s", &add.features);
            printf("\t\t\t\t\t\t Updated Room Type (1. AC or 2. Non AC): ");scanf("%d", &add.type);
            printf("\t\t\t\t\t\t Updated Room Price: ");scanf("%d", &add.price);

            fwrite(&add, sizeof(add), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("\t\t\t\t\t\t ::::::::::After Update::::::::::");
    room_list();
}


/*
    ==================================================================================
                                    Admin Delete Room Function
    ==================================================================================
*/
void delete_room()
{
    system("cls");
    top();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="room.txt";
    int delete_line;
    struct room add, list;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    room_list();

    printf("\t\t\t\t\t\t Delete Room No: ");
    scanf("%d", &delete_line);


    while(fread(&add, sizeof(add),1,main_file) == 1)
    {
        if(add.no != delete_line)
        {
            fwrite(&add, sizeof(add), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\t\t\t\t\t\t ::::::::::After Delete %d No Room::::::::::", delete_line);
    room_list();

    fclose(main_file);
}

/*
    ==================================================================================
                                    Admin Room Searching Function
    ==================================================================================
*/
void room_search(int n, int autho)
{
    system("cls");
    top();

    char filename[]="room.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("\t\t\t\t\t\t ::::::::::Search Room by Room no::::::::::\n\n");
        printf("\t\t\t\t\t\t Enter Room no: ");
        scanf("%d", &num);
        printf("\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.no == num)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("\t\t\t\t\t\t ::::::::::AC Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.type == 1)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==2)
    {
        printf("\t\t\t\t\t\t ::::::::::Non AC Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.type == 2)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==3)
    {
        printf("\t\t\t\t\t\t ::::::::::Available Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.status == 0)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==4)
    {
        printf("\t\t\t\t\t\t ::::::::::Not Available Room List::::::::::\n\n");
        while(fread(&room_info, sizeof(room_info),1,fptr) == 1)
        {
            if(room_info.status == 1)
            {
                flag = 1;
                printf("Room No: %d", room_info.no);
                printf("\t|\tRoom Name: %s", room_info.name);
                printf("\t|\tRoom Features: %s", room_info.features);
                printf("\t|\tRoom Type: ");
                if(room_info.type == 1)
                    printf("AC");
                else if(room_info.type == 2)
                    printf("Non AC");
                printf("\t|\tRoom Price: %d", room_info.price);
                printf("\t|\tRoom Status: ");
                if(room_info.status == 0)
                    printf("Available");
                else if(room_info.status == 1)
                    printf("Not Available");
                printf("\n\n");
            }
        }
    }
    fclose(fptr);

    if(n==1 && autho==2 && flag==1)
    {
        int id;
        printf("\t\t\t\t\t\t Enter room ID which is you want to buy: ");scanf("%d", &id);
        order_room(id);
    }
    else if(n==2 && autho==2 && flag==1)
    {
        int id;
        printf("\t\t\t\t\t\t Enter room ID which is you want to buy: ");scanf("%d", &id);
        order_room(id);
    }
    else if(flag==0 && autho!=2)
    {
        printf("\n\t\t\t\t\t\tNot Found");
        getch();
        room_menu(1);
    }
    else if(flag==0 && autho==2)
    {
        printf("\n\t\t\t\t\t\tNot Found");
        getch();
        room_menu(2);
    }
}

/*
    ==================================================================================
                                    Food Function
    ==================================================================================
*/
void food_menu(int n)
{
    system("cls");
    top();

    int m=0;

    if(n==1) //Admin Food Menu
    {
        n=0;
        printf("\t\t\t\t\t\t ::::::::::Admin Food Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. Add Food\n");
        printf("\t\t\t\t\t\t 2. Food List\n");
        printf("\t\t\t\t\t\t 3. Update Food\n");
        printf("\t\t\t\t\t\t 4. Delete Food\n");
        printf("\t\t\t\t\t\t 5. Food Search\n");
        printf("\t\t\t\t\t\t 6. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_food();
            getch();
            food_menu(1);
            break;
        case 2:
            system("cls");
            top();
            food_list();
            getch();
            food_menu(1);
            break;
        case 3:
            update_food();
            getch();
            food_menu(1);
            break;
        case 4:
            delete_food();
            getch();
            food_menu(1);
            break;
        case 5:
            system("cls");
            top();

            m=0;
            printf("\t\t\t\t\t\t :::::::::: Admin Food Search ::::::::::\n\n");
            printf("\t\t\t\t\t\t 1. Search by Food ID\n");
            printf("\t\t\t\t\t\t 2. Breakfast List\n");
            printf("\t\t\t\t\t\t 3. Lunch List\n");
            printf("\t\t\t\t\t\t 4. Snacks List\n");
            printf("\t\t\t\t\t\t 5. Dinner List\n");
            printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);
            if(m==1)food_search(0);
            else if(m==2) food_search(1);
            else if(m==3) food_search(2);
            else if(m==4) food_search(3);
            else if(m==5) food_search(4);
            getch();
            food_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("\t\t\t\t\t\t Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=m=0;
        printf("\t\t\t\t\t\t ::::::::::User Food Menu::::::::::\n\n");

            printf("\t\t\t\t\t\t 1. Breakfast List\n");
            printf("\t\t\t\t\t\t 2. Lunch List\n");
            printf("\t\t\t\t\t\t 3. Snacks List\n");
            printf("\t\t\t\t\t\t 4. Dinner List\n");
            printf("\t\t\t\t\t\t 5. Main Menu\n\n");
            printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

            switch(m)
            {
            case 1:
                food_search(1, 2);
                break;
            case 2:
                food_search(2, 2);
                break;
            case 3:
                food_search(3, 2);
                break;
            case 4:
                food_search(4, 2);
                break;
            case 5:
                main_menu(2);
                break;
            default:
                printf("\t\t\t\t\t\t Error: Invalid input");
            }
    }
}

/*
    ==================================================================================
                                    Admin Add Food Function
    ==================================================================================
*/
void add_food()
{
    system("cls");
    FILE *fptr = fopen("food.txt", "ab+");

    printf("\t\t\t\t\t\t Enter Food Code: ");scanf("%d", &food_info.code);
    printf("\t\t\t\t\t\t Enter Food Name: ");scanf("%s", &food_info.name);
    printf("\t\t\t\t\t\t Enter Food Description: ");scanf("%s", &food_info.description);
    printf("\t\t\t\t\t\t Enter Food Category(1. Breakfast, 2. Lunch 3. Snacks, 4. Dinner): ");scanf("%d", &food_info.category);
    printf("\t\t\t\t\t\t Enter Food Price: ");scanf("%d", &food_info.price);
    food_info.status = 0;

    fwrite(&food_info, sizeof(food_info), 1, fptr);
    fclose(fptr);

    printf("\n\n\t\t\t\t\t\tFood Code %d\t|\tFood Name: %s\t|\tFood Description: %s\t|\tFood Category: %d\t|\tFood Price: %d tk\n\n", food_info.code, food_info.name, food_info.description, food_info.category, food_info.price);
    printf("\t\t\t\t\t\t Room Added Successful! Press any key to go Menu\n");

}

/*
    ==================================================================================
                                    Admin Food List Function
    ==================================================================================
*/
void food_list()
{
    FILE *fptr = fopen("food.txt", "rb");

    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.");
        exit(1);
    }

    printf("\t\t\t\t\t\t ::::::::::Food List::::::::::\n\n");

    while(fread(&food_info, sizeof(food_info), 1, fptr) == 1)
    {
        printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
        printf("\t|\tFood Name: %s", food_info.name);
        printf("\t|\tFood Description: %s", food_info.description);
        printf("\t|\tFood Category: ");
            if(food_info.category == 1) printf("Breakfast");
            else if(food_info.category == 2) printf("Lunch");
            else if(food_info.category == 3) printf("Snacks");
            else if(food_info.category == 4) printf("Dinner");
        printf("\t|\tFood Price: %d", food_info.price);
        printf("\t|\tFood Status: ");
            if(food_info.status == 0) printf("Available");
            else if(food_info.status == 1) printf("Not Available");
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Food Function
    ==================================================================================
*/
void update_food()
{
    system("cls");

    food_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="food.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t Enter food code which is you want to update: ");
    scanf("%d", &delete_line);


    while(fread(&food_info, sizeof(food_info),1,main_file) == 1)
    {
        if(food_info.code != delete_line)
            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        else if(food_info.code == delete_line)
        {
            printf("\t\t\t\t\t\t Updated Food Code: ");scanf("%d", &food_info.code);
            printf("\t\t\t\t\t\t Updated Food Name: ");scanf("%s", &food_info.name);
            printf("\t\t\t\t\t\t Updated Food Description: ");scanf("%s", &food_info.description);
            printf("\t\t\t\t\t\t Updated Food Category(1. Breakfast, 2. Lunch 3. Snacks, 4. Dinner): ");scanf("%d", &food_info.category);
            printf("\t\t\t\t\t\t Updated Food Price: ");scanf("%d", &food_info.price);

            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("\t\t\t\t\t\t ::::::::::After Update::::::::::");
    food_list();
}


/*
    ==================================================================================
                                    Admin Delete Food Function
    ==================================================================================
*/
void delete_food()
{
    system("cls");
    FILE *main_file;
    FILE *temp_file;

    char filename[100]="food.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    food_list();

    printf("\t\t\t\t\t\t Enter food code which is you want to delete: ");
    scanf("%d", &delete_line);


    while(fread(&food_info, sizeof(food_info),1,main_file) == 1)
    {
        if(food_info.code != delete_line)
        {
            fwrite(&food_info, sizeof(food_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\t\t\t\t\t\t ::::::::::After Delete %d No Food::::::::::", delete_line);
    food_list();

    fclose(main_file);
}

/*
    ==================================================================================
                                    Admin Food Searching Function
    ==================================================================================
*/
void food_search(int n, int autho)
{
    system("cls");
    top();

    char filename[]="food.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("\t\t\t\t\t\t ::::::::::Search Food by Food ID::::::::::\n\n");
        printf("\t\t\t\t\t\t Enter Food Code: ");
        scanf("%d", &num);
        printf("\n\n");

        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.code == num)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
                printf("\t|\tFood Name: %s", food_info.name);
                printf("\t|\tFood Description: %s", food_info.description);
                printf("\t|\tFood Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\tFood Price: %d", food_info.price);
                printf("\t|\tFood Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("\t\t\t\t\t\t ::::::::::Breakfast Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 1)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
                printf("\t|\tFood Name: %s", food_info.name);
                printf("\t|\tFood Description: %s", food_info.description);
                printf("\t|\tFood Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\tFood Price: %d", food_info.price);
                printf("\t|\tFood Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("\t\t\t\t\t\t Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==2)
    {
        printf("\t\t\t\t\t\t ::::::::::Lunch Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 2)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
                printf("\t|\tFood Name: %s", food_info.name);
                printf("\t|\tFood Description: %s", food_info.description);
                printf("\t|\tFood Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\tFood Price: %d", food_info.price);
                printf("\t|\tFood Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("\t\t\t\t\t\t Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==3)
    {
        printf("\t\t\t\t\t\t ::::::::::Snacks Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 3)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
                printf("\t|\tFood Name: %s", food_info.name);
                printf("\t|\tFood Description: %s", food_info.description);
                printf("\t|\tFood Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\tFood Price: %d", food_info.price);
                printf("\t|\tFood Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("\t\t\t\t\t\t Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }
    else if(n==4)
    {
        printf("\t\t\t\t\t\t ::::::::::Dinner Food List::::::::::\n\n");
        while(fread(&food_info, sizeof(food_info),1,fptr) == 1)
        {
            if(food_info.category == 4)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Food Code: %d", food_info.code);
                printf("\t|\tFood Name: %s", food_info.name);
                printf("\t|\tFood Description: %s", food_info.description);
                printf("\t|\tFood Category: ");
                    if(food_info.category == 1) printf("Breakfast");
                    else if(food_info.category == 2) printf("Lunch");
                    else if(food_info.category == 3) printf("Snacks");
                    else if(food_info.category == 4) printf("Dinner");
                printf("\t|\tFood Price: %d", food_info.price);
                printf("\t|\tFood Status: ");
                    if(food_info.status == 0) printf("Available");
                    else if(food_info.status == 1) printf("Not Available");
                printf("\n\n");
            }
        }
        if(autho==2 && flag==1)
        {
            int buy;
            printf("\t\t\t\t\t\t Enter food ID which is you want to buy: ");scanf("%d", &buy);
            order_food(buy);
        }
    }

    if(flag==0 && autho!=2)
    {
        printf("\n\t\t\t\t\t\tNot Found");
        getch();
        food_menu(1);
    }
    else if(flag==0 && autho==2)
    {
        printf("\n\t\t\t\t\t\tNot Found");
        getch();
        food_menu(2);
    }
    fclose(fptr);
}

/*
    ==================================================================================
                                    User Function
    ==================================================================================
*/
void user_menu(int n)
{
    system("cls");
    top();

    int m;

    if(n==1) //Admin User Menu
    {
        n=m=0;
        printf("\t\t\t\t\t\t ::::::::::Admin User Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. User List\n");
        printf("\t\t\t\t\t\t 2. Update User\n");
        printf("\t\t\t\t\t\t 3. Delete User\n");
        printf("\t\t\t\t\t\t 4. Search User\n");
        printf("\t\t\t\t\t\t 5. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            system("cls");
            top();
            user_list();
            getch();
            user_menu(1);
            break;
        case 2:
            update_user(1);
            getch();
            user_menu(1);
            break;
        case 3:
            delete_user();
            getch();
            user_menu(1);
            break;
        case 4:
            user_search(1);
            getch();
            user_menu(1);
            break;
        case 5:
            main_menu(1);
            break;
        default:
            printf("\t\t\t\t\t\t Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=m=0;
        printf("\t\t\t\t\t\t ::::::::::User Room Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. AC Room\n");
        printf("\t\t\t\t\t\t 2. Non AC Room\n");
        printf("\t\t\t\t\t\t 3. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

        switch (m)
        {
        case 1:
            room_search(1,2);
            break;
        case 2:
            room_search(2,2);
            break;
        case 3:
            main_menu(2);
            break;
        default:
            printf("\t\t\t\t\t\t Error: Invalid Input");
        }


    }

}

/*
    ==================================================================================
                                    Admin User List Function
    ==================================================================================
*/
void user_list()
{
    FILE *fptr = fopen("user.txt", "rb");

    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.");
        exit(1);
    }

    printf("\t\t\t\t\t\t ::::::::::User List::::::::::\n\n");
    while(fread(&user_info, sizeof(user_info), 1, fptr))
    {
        printf("\t Username: %s", user_info.username);
        printf("\t|\tName: %s", user_info.name);
        printf("\t|\tEmail: %s", user_info.email);
        printf("\t|\tNID: %s", user_info.nid);
        printf("\t|\tAddress: %s", user_info.address);
        printf("\t|\tNationality: %s", user_info.nationality);
        printf("\t|\tPassword: %s", user_info.password);
        printf("\n\n");
    }
    fclose(fptr);
}

/*
    ==================================================================================
                                    Admin & User Update User Function
    ==================================================================================
*/
void update_user(int n)
{
    system("cls");
    top();

    if(n==1)
        user_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="user.txt";

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    if(n==1) //Admin User Update Function
    {
        char up_username[50];
        printf("\t\t\t\t\t\t Enter username which is you want to update: ");
        scanf("%s", &up_username);

        while(fread(&user_info, sizeof(user_info),1,main_file) == 1)
        {
            if(strcmp(user_info.username,up_username) != 0)
                fwrite(&user_info, sizeof(user_info), 1, temp_file);
            else if(strcmp(user_info.username,up_username) == 0)
            {
                printf("\t\t\t\t\t\t Username: %s *Usernames cannot be changed\n", user_info.username);
                printf("\t\t\t\t\t\t Update Name: ");scanf("%s", &user_info.name);
                printf("\t\t\t\t\t\t Update Email: ");scanf("%s", &user_info.email);
                printf("\t\t\t\t\t\t NID/Passport No: ");scanf("%s", &user_info.nid);
                printf("\t\t\t\t\t\t Update Address: ");scanf("%s", &user_info.address);
                printf("\t\t\t\t\t\t Update Nationality: ");scanf("%s", &user_info.nationality);
                printf("\t\t\t\t\t\t Update Password: ");scanf("%s", &user_info.password);

                fwrite(&user_info, sizeof(user_info), 1, temp_file);
            }
        }
    }
    else if(n==2) //User Profile Update Function
    {
        printf("\t\t\t\t\t\t ::::::::::Update Profile::::::::::\n\n");
        while(fread(&user_info, sizeof(user_info),1,main_file) == 1)
        {
            if(strcmp(user_info.username,username) != 0)
                fwrite(&user_info, sizeof(user_info), 1, temp_file);
            else if(strcmp(user_info.username,username) == 0)
            {
                printf("\t\t\t\t\t\t Username: %s *Usernames cannot be changed\n", user_info.username);
                printf("\t\t\t\t\t\t Update Name: ");scanf("%s", &user_info.name);
                printf("\t\t\t\t\t\t Update Email: ");scanf("%s", &user_info.email);
                printf("\t\t\t\t\t\t NID/Passport No: %s *NID/Passport cannot be changed\n", user_info.nid);
                printf("\t\t\t\t\t\t Update Address: ");scanf("%s", &user_info.address);
                printf("\t\t\t\t\t\t Update Nationality: ");scanf("%s", &user_info.nationality);

                fwrite(&user_info, sizeof(user_info), 1, temp_file);

                printf("\t\t\t\t\t\t Profile update successful. Press any key to continue...");
            }
        }
    }
    else if(n==3) //User Password Update Function
    {
        printf("\t\t\t\t\t\t ::::::::::Change Password::::::::::\n\n");
        while(fread(&user_info, sizeof(user_info),1,main_file) == 1)
        {
            if(strcmp(user_info.username,username) != 0)
                fwrite(&user_info, sizeof(user_info), 1, temp_file);
            else if(strcmp(user_info.username,username) == 0)
            {
                char up_password[100];
                printf("\t\t\t\t\t\t Enter previous password: ");scanf("%s", &up_password);

                if(strcmp(user_info.password,up_password)==0)
                {
                    printf("\t\t\t\t\t\t Enter new password: ");scanf("%s", &user_info.password);
                    printf("\t\t\t\t\t\t Password Update Successful. Press any key to continue...");
                }
                else
                    printf("\t\t\t\t\t\t Password does not matched. Press any key to continue...");

                fwrite(&user_info, sizeof(user_info), 1, temp_file);
            }
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");

    if(n==1)
    {
        printf("\t\t\t\t\t\t ::::::::::After Update::::::::::");
        user_list();
    }
    else if(n==2 || n==3)
    {
        getch();
        main_menu(2);
    }
}

/*
    ==================================================================================
                                    Admin User Delete Function
    ==================================================================================
*/
void delete_user()
{
    system("cls");
    top();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="user.txt";
    char del_username[50];

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    user_list();

    printf("\t\t\t\t\t\t Enter username which is you want to delete: ");
    scanf("%s", &del_username);


    while(fread(&user_info, sizeof(user_info),1,main_file) == 1)
    {
        if(strcmp(user_info.username,del_username) !=0 )
        {
            fwrite(&user_info, sizeof(user_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\t\t\t\t\t\t ::::::::::After Delete %s User::::::::::", del_username);
    user_list();

}

/*
    ==================================================================================
                                    Admin User Searching Function
    ==================================================================================
*/
void user_search(int n)
{
    system("cls");
    top();

    FILE *fptr = fopen("user.txt", "rb");

    int flag=0;

    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.");
        exit(1);
    }

    if(n==1)
    {
        char ser_user[50];
        printf("\t\t\t\t\t\t ::::::::::User Searching::::::::::\n\n");
        printf("\t\t\t\t\t\t Enter usernames: ");scanf("%s", &ser_user);

        while(fread(&user_info, sizeof(user_info), 1, fptr) && flag==0)
        {
            if(strcmp(user_info.username,ser_user)==0)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Username: %s", user_info.username);
                printf("\t|\tName: %s", user_info.name);
                printf("\t|\tEmail: %s", user_info.email);
                printf("\t|\tNID: %s", user_info.nid);
                printf("\t|\tAddress: %s", user_info.address);
                printf("\t|\tNationality: %s", user_info.nationality);
                printf("\t|\tPassword: %s", user_info.password);
                printf("\n\n");
            }
        }
    }
    if(n==2)
    {
        printf("\t\t\t\t\t\t ::::::::::User Profile::::::::::\n\n");

        while(fread(&user_info, sizeof(user_info), 1, fptr) && flag==0)
        {
            if(strcmp(user_info.username,username)==0)
            {
                flag = 1;
                printf("\t\t\t\t\t\t Username: %s", user_info.username);
                printf("\t|\tName: %s", user_info.name);
                printf("\t|\tEmail: %s", user_info.email);
                printf("\t|\tNID: %s", user_info.nid);
                printf("\t|\tAddress: %s", user_info.address);
                printf("\t|\tNationality: %s", user_info.nationality);
                printf("\n\n");
            }
        }
    }
    fclose(fptr);

    if(flag==0)
        printf("\n\n\t\t\t\t\t\tError: User Not Found");
}


/*
    ==================================================================================
                                    Employee Function
    ==================================================================================
*/
void employee_menu(int n)
{
    system("cls");
    top();

    int m=0;

    if(n==1) //Admin Employee Menu
    {
        n=0;
        printf("\t\t\t\t\t\t ::::::::::Employee Menu::::::::::\n\n");
        printf("\t\t\t\t\t\t 1. Add Employee\n");
        printf("\t\t\t\t\t\t 2. Employee List\n");
        printf("\t\t\t\t\t\t 3. Update Employee\n");
        printf("\t\t\t\t\t\t 4. Delete Employee\n");
        printf("\t\t\t\t\t\t 5. Employee Search\n");
        printf("\t\t\t\t\t\t 6. Main Menu\n\n");
        printf("\t\t\t\t\t\t Enter Choice: ");scanf("%d", &m);

        switch(m)
        {
        case 1:
            add_employee();
            getch();
            employee_menu(1);
            break;
        case 2:
            system("cls");
            top();
            employee_list();
            getch();
            employee_menu(1);
            break;
        case 3:
            update_employee();
            getch();
            employee_menu(1);
            break;
        case 4:
            delete_employee();
            getch();
            employee_menu(1);
            break;
        case 5:
            employee_search();
            getch();
            employee_menu(1);
            break;
        case 6:
            main_menu(1);
            break;
        default:
            printf("\t\t\t\t\t\t Error: invalid input");
        }
    }
    else if(n==2) //User Room Menu
    {
        n=0;
        printf("\t\t\t\t\t\t ::::::::::User Room Menu::::::::::\n\n");
    }
}

/*
    ==================================================================================
                                    Admin Add Employee Function
    ==================================================================================
*/
void add_employee()
{
    system("cls");
    top();

    FILE *fptr = fopen("employee.txt", "ab+");

    printf("\t\t\t\t\t\t Enter Employee ID: ");scanf("%d", &employee_info.id);
    printf("\t\t\t\t\t\t Enter Employee Name: ");scanf("%s", &employee_info.name);
    printf("\t\t\t\t\t\t Enter Employee Address: ");scanf("%s", &employee_info.address);
    printf("\t\t\t\t\t\t Enter Employee Salary: "); scanf("%ld", &employee_info.salary);

    fwrite(&employee_info, sizeof(employee_info), 1, fptr);
    fclose(fptr);

    printf("\n\n\t\t\t\t\t\tEmployee ID: %d\t|\tEmployee Name: %s\t|\tEmployee Address: %s\t|\tEmployee Salary: %ld\n\n", employee_info.id, employee_info.name, employee_info.address, employee_info.salary);
    printf("\t\t\t\t\t\t Employee Added Successful! Press any key to go Menu\n");
}

/*
    ==================================================================================
                                    Admin Employee List Function
    ==================================================================================
*/
void employee_list()
{
    FILE *fptr = fopen("employee.txt", "rb");

    if(fptr == NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file.");
        exit(1);
    }

    printf("\t\t\t\t\t\t ::::::::::Employee List::::::::::\n\n");

    while(fread(&employee_info, sizeof(employee_info), 1, fptr) == 1)
    {
        printf("\t\t\t\t\t\t Employee ID: %d", employee_info.id);
        printf("\t|\tEmployee Name: %s", employee_info.name);
        printf("\t|\tEmployee Address: %s", employee_info.address);
        printf("\t|\tEmployee Salary: %d", employee_info.salary);
        printf("\n\n");
    }
    fclose(fptr);
}


/*
    ==================================================================================
                                    Admin Update Employee Function
    ==================================================================================
*/
void update_employee()
{
    system("cls");
    top();

    employee_list();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="employee.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t Enter employee ID which is you want to update: ");
    scanf("%d", &delete_line);


    while(fread(&employee_info, sizeof(employee_info),1,main_file) == 1)
    {
        if(employee_info.id != delete_line)
            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        else if(employee_info.id == delete_line)
        {
            printf("\t\t\t\t\t\t Updated Employee ID: ");scanf("%d", &employee_info.id);
            printf("\t\t\t\t\t\t Updated Employee Name: ");scanf("%s", &employee_info.name);
            printf("\t\t\t\t\t\t Updated Employee Address: ");scanf("%s", &employee_info.address);
            printf("\t\t\t\t\t\t Updated Employee Salary: "); scanf("%ld", &employee_info.salary);

            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n");
    printf("\t\t\t\t\t\t ::::::::::After Update::::::::::");
    employee_list();
}


/*
    ==================================================================================
                                    Admin Delete Employee Function
    ==================================================================================
*/
void delete_employee()
{
    system("cls");
    top();

    FILE *main_file;
    FILE *temp_file;

    char filename[100]="employee.txt";
    int delete_line;

    main_file  = fopen(filename, "rb+");
    temp_file = fopen("temp-file.tmp", "wb+");

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    employee_list();

    printf("\t\t\t\t\t\t Enter employee ID which is you want to delete: ");
    scanf("%d", &delete_line);


    while(fread(&employee_info, sizeof(employee_info),1,main_file) == 1)
    {
        if(employee_info.id != delete_line)
        {
            fwrite(&employee_info, sizeof(employee_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\t\t\t\t\t\t ::::::::::After Delete %d No Employee ID::::::::::", delete_line);
    employee_list();
}

/*
    ==================================================================================
                                    Admin Employee Searching Function
    ==================================================================================
*/
void employee_search()
{
    system("cls");
    top();

    employee_list();printf("\n\n");

    char filename[]="employee.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t Enter employee ID: ");
    scanf("%d", &num);

    printf("\n\n");

    while(fread(&employee_info, sizeof(employee_info),1,fptr) == 1)
    {
        if(employee_info.id == num)
        {
            flag = 1;
            printf("\t\t\t\t\t\t Employee ID: %d", employee_info.id);
            printf("\t|\tEmployee Name: %s", employee_info.name);
            printf("\t|\tEmployee Address: %s", employee_info.address);
            printf("\t|\tEmployee Salary: %d", employee_info.salary);
            printf("\n\n");
        }
    }
    if(flag==0)
        printf("\n\t\t\t\t\t\tNot Found");

    fclose(fptr);
}

/*
    ==================================================================================
                                    Admin Order Searching Function
    ==================================================================================
*/
void order_search(int n)
{
    system("cls");
    top();

    char filename[]="order.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    if(n==0)
    {
        printf("\t\t\t\t\t\t ::::::::::Search Food by Order ID::::::::::\n\n");
        printf("\t\t\t\t\t\t Enter Order ID: ");
        scanf("%d", &num);
        printf("\n\n");

        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_id == num)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }
    else if(n==1)
    {
        printf("\t\t\t\t\t\t ::::::::::Confirmed Order List::::::::::\n\n");
        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_status == 1)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }
    else if(n==2)
    {
        printf("\t\t\t\t\t\t ::::::::::Pending Order List::::::::::\n\n");
        while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
        {
            if(order_info.or_status == 0)
            {
                flag = 1;
                printf("Order ID: %d\t|\t", order_info.or_id);
                printf("Item ID: %d\t|\t", order_info.item_id);
                printf("Item Name: %s\t|\t", order_info.or_name);
                printf("Item Type: %s\t|\t", order_info.or_type);
                printf("Quantity: %d\t|\t", order_info.item_count);
                printf("Total price: %ld\t|\t", order_info.or_price);
                printf("User: %s\t|\t", order_info.or_user);
                printf("Status: ");
                    if(order_info.or_status==0) printf("Pending");
                    else if(order_info.or_status == 1) printf("Confirmed");
                printf("\n\n");
            }
        }
    }

    fclose(fptr);

    if(flag==0)
        printf("\n\t\t\t\t\t\tNot Order Found");

    getch();
    main_menu(1);
}

/*
    ==================================================================================
                                    User Order History Function
    ==================================================================================
*/
void user_order_history()
{
    system("cls");
    top();

    char filename[]="order.txt";

    FILE *fptr;
    fptr = fopen(filename, "rb");

    int num,flag=0;

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t ::::::::::Order History::::::::::\n\n");
    while(fread(&order_info, sizeof(order_info),1,fptr) == 1)
    {
        if(strcmp(order_info.or_user,username)==0)
        {
            flag = 1;
            printf("Order ID: %d\t|\t", order_info.or_id);
            printf("Item ID: %d\t|\t", order_info.item_id);
            printf("Item Name: %s\t|\t", order_info.or_name);
            printf("Item Type: %s\t|\t", order_info.or_type);
            printf("Quantity: %d\t|\t", order_info.item_count);
            printf("Total price: %ld\t|\t", order_info.or_price);
            printf("User: %s\t|\t", order_info.or_user);
            printf("Status: ");
                if(order_info.or_status==0) printf("Pending");
                else if(order_info.or_status == 1) printf("Confirmed");
            printf("\n\n");
        }
    }
    fclose(fptr);

    if(flag==0)
        printf("\n\t\t\t\t\t\tNot Order Found");

    getch();
    main_menu(2);
}

/*
    ==================================================================================
                                    Order Room Function
    ==================================================================================
*/
void order_room(int id)
{
    system("cls");

    FILE *main_file;
    FILE *temp_or_file;

    char filename[100]="room.txt";
    int flag=0;

    main_file  = fopen(filename, "rb");
    temp_or_file = fopen("temp-order-file.tmp", "wb+");

    if (main_file == NULL || temp_or_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    while(fread(&room_info, sizeof(room_info),1,main_file) == 1 && flag==0)
    {
        if(room_info.no == id && room_info.status==0)
        {
            flag=1;

            printf("\t\t\t\t\t\t Check ID Date(D-M-Y): ");scanf("%s", &order_info.in_date);
            printf("\t\t\t\t\t\t Check Out Date (D-M-Y): ");scanf("%s", &order_info.out_date);
            printf("\t\t\t\t\t\t How Many Rooms: ");scanf("%d", &order_info.item_count);
            printf("\t\t\t\t\t\t How Many Adults: ");scanf("%d", &order_info.adult_count);
            printf("\t\t\t\t\t\t How Many Children: ");scanf("%d", &order_info.children_count);

            strcpy(order_info.or_user, username);
            order_info.item_id=room_info.no;
            strcpy(order_info.or_name, room_info.name);
            if(room_info.type==1) strcpy(order_info.or_type, "AC");
            else if(room_info.type==2) strcpy(order_info.or_type, "Non AC");
            order_info.or_price = room_info.price*order_info.item_count;

            fwrite(&order_info, sizeof(order_info), 1, temp_or_file);
        }
    }
    fclose(main_file);
    fclose(temp_or_file);

    if(flag==1)
    {
        payment(1);
    }
    else
    {
        remove("temp-order-file.tmp");
        printf("\t\t\t\t\t\t %d Room not Available\n\n", id);
        getch();
        room_menu(2);
    }
}

/*
    ==================================================================================
                                    Order Food Function
    ==================================================================================
*/
void order_food(int id)
{
    system("cls");
    top();

    FILE *main_file;
    FILE *temp_or_file;

    char filename[100]="food.txt";
    int flag=0;

    main_file  = fopen(filename, "rb");
    temp_or_file = fopen("temp-order-file.tmp", "wb+");

    if (main_file == NULL || temp_or_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    while(fread(&food_info, sizeof(food_info),1,main_file) == 1 && flag==0)
    {
        if(food_info.code == id && food_info.status==0)
        {
            flag=1;

            printf("\t\t\t\t\t\t Food Quantity: ");scanf("%d", &order_info.item_count);

            strcpy(order_info.or_user, username);
            order_info.item_id=food_info.code;
            strcpy(order_info.or_name, food_info.name);
            if(food_info.category == 1) strcpy(order_info.or_type,"Breakfast");
            else if(food_info.category == 2) strcpy(order_info.or_type, "Lunch");
            else if(food_info.category == 3) strcpy(order_info.or_type, "Snacks");
            else if(food_info.category == 4) strcpy(order_info.or_type, "Dinner");
            order_info.or_price = food_info.price*order_info.item_count;

            fwrite(&order_info, sizeof(order_info), 1, temp_or_file);
        }
    }
    fclose(main_file);
    fclose(temp_or_file);

    if(flag==1)
    {
        payment(2);
    }
    else
    {
        remove("temp-order-file.tmp");
        printf("\t\t\t\t\t\t %d Food not Available\n\n", id);
        getch();
        food_menu(2);
    }
}

/*
    ==================================================================================
                                    Order Details Function
    ==================================================================================
*/
void order_details(int n)
{
    FILE *fptr;
    fptr = fopen("temp-order-file.tmp", "rb");

    printf("\t\t\t\t\t\t ::::::::::Order Details::::::::::\n\n");

    if (fptr == NULL)
    {
        printf("\n\n\t\t\t\t\t\tUnable to open file.\n");
        exit(1);
    }

    if(n==1) //Room Order Details
    {
        while(fread(&order_info, sizeof(order_info),1,fptr)==1)
        {
            item_id = order_info.item_id;
            printf("\t\t\t\t\t\t Room No: %d\n", order_info.item_id);
            printf("\t\t\t\t\t\t Room Name: %s\n", order_info.or_name);
            printf("\t\t\t\t\t\t Room Type: %s\n", order_info.or_type);
            printf("\t\t\t\t\t\t Check in date: %s\n", order_info.in_date);
            printf("\t\t\t\t\t\t Check out date: %s\n", order_info.out_date);
            printf("\t\t\t\t\t\t Rooms: %d\n", order_info.item_count);
            printf("\t\t\t\t\t\t Adult: %d\n", order_info.adult_count);
            printf("\t\t\t\t\t\t Children: %d\n", order_info.children_count);
            printf("\t\t\t\t\t\t Total price: %ld\n", order_info.or_price);
            //printf("\t\t\t\t\t\t Username: %s", order_info.or_user);

            printf("\n\n");
        }
    }
    else if(n==2) //Food Order Details
    {
        while(fread(&order_info, sizeof(order_info),1,fptr)==1)
        {
            item_id = order_info.item_id;
            printf("\t\t\t\t\t\t Food Code: %d\n", order_info.item_id);
            printf("\t\t\t\t\t\t Food Name: %s\n", order_info.or_name);
            printf("\t\t\t\t\t\t Food Type: %s\n", order_info.or_type);
            printf("\t\t\t\t\t\t Food Quantity: %d\n", order_info.item_count);
            printf("\t\t\t\t\t\t Total price: %ld\n", order_info.or_price);
            //printf("\t\t\t\t\t\t Username: %s", order_info.or_user);

            printf("\n\n");
        }
    }

    fclose(fptr);

}

/*
    ==================================================================================
                                    Payment Function
    ==================================================================================
*/
void payment(int n)
{
    system("CLS");

    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    printf("\t\t\t\t\t\t ::::::::::Payment options::::::::::\n\n");
    int m;
    printf("\t\t\t\t\t\t 1. Visa/Credit/MasterCard\n");
    printf("\t\t\t\t\t\t 2. Bkash/Rocket\n");
    printf("\t\t\t\t\t\t 3. Cash\n\n");
    printf("\t\t\t\t\t\t Enter choice: ");scanf("%d", &m);

    switch(m)
    {
    case 1:
        card(n);
        break;
    case 2:
        m_banking(n);
        break;
    case 3:
        thanks(n, 0);
        printf("\t\t\t\t\t\t Pay in Cash\n");
        break;
    default:
        printf("\t\t\t\t\t\t Error! Invalid Input..");
        getch();
        main_menu(2);
    }
}

/*
    ==================================================================================
                                    Card Payment Function
    ==================================================================================
*/
void card(int n)
{
    system("CLS");
    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    char c;

    printf("\t\t\t\t\t\t ::::::::::Payment > Card Information::::::::::\n\n");
    printf("\t\t\t\t\t\t Enter Card No\t\t: ");scanf("%d", &payment_info.no);

    printf("\t\t\t\t\t\t Enter Card Expire Date\t: ");scanf("%s", &payment_info.expire);
    printf("\t\t\t\t\t\t Enter CVC No\t\t: ");scanf("%d", &payment_info.code);

    printf("\t\t\t\t\t\t Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        thanks(n, 1);
    }
    else
    {
        printf("\t\t\t\t\t\t Payment Deny..............");
        main_menu(2);
    }
}

/*
    ==================================================================================
                                    Mobile Banking Payment Function
    ==================================================================================
*/
void m_banking(int n)
{
    system("cls");
    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    char c;

    printf("\t\t\t\t\t\t ::::::::::Payment > Mobile Banking Information::::::::::\n\n");
    printf("\t\t\t\t\t\t Enter Your Mobile Banking (Bkash/Rocket) Number: ");scanf("%d", &payment_info.no);
    printf("\t\t\t\t\t\t Enter Your PIN: ");scanf("%d", &payment_info.code);
    printf("\t\t\t\t\t\t Confirm Payment (Y/N): ");scanf("%s", &c);

    system("CLS");

    if(c=='Y')
    {
        thanks(n, 1);
    }
    else
        printf("\t\t\t\t\t\t Payment Deny..............\n");
}

/*
    ==================================================================================
                                    Checkout Function
    ==================================================================================
*/
void thanks(int n, int m)
{
    system("cls");

    printf("\t\t\t\t\t\t                 ##########  ##     ##      ##      ###    ##  ##   ##   #####                    \n");
    printf("\t\t\t\t\t\t                     ##      ##     ##     ####     ## #   ##  ## ##    #                         \n");
    printf("\t\t\t\t\t\t                     ##      #########    ##  ##    ##  #  ##  ###       #####                    \n");
    printf("\t\t\t\t\t\t                     ##      ##     ##   ## ## ##   ##   # ##  ## ##          #                   \n");
    printf("\t\t\t\t\t\t                     ##      ##     ##  ##      ##  ##    ###  ##   ##   #####                    \n\n");
    printf("\t\t\t\t\t\t ##############################################################################################   \n\n");

    if(n==1) order_details(1); //Room Order Details
    else if(n==2) order_details(2); //Food Order Details

    if(n==1 && m==1) //Room Auto Payment
    {
        update_order(1);
        order_room_update(1);
    }
    else if(n==1 && m==0) //Room, Cash Payment
        update_order(0);
    else if(n==2 && m==1) //Food Payment
        update_order(1);
    else if(n==2 && m==0) //Food, Cash Payment
        update_order(0);

    getch();
    main_menu(2);
}

/*
    ==================================================================================
                                    Update Order List Function
    ==================================================================================
*/
void update_order(int n)
{
    FILE *main_file;
    FILE *temp_file;
    char filename[100]="order.txt";

    main_file  = fopen(filename, "ab+");
    temp_file = fopen("temp-order-file.tmp", "rb");

    int count=1;

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    while(fread(&order_info, sizeof(order_info),1,main_file) == 1)
    {
        count++;
    }

    while(fread(&order_info, sizeof(order_info),1,temp_file) == 1)
    {
        order_info.or_id = count;
        if(n==1)
            order_info.or_status = 1;
        else
            order_info.or_status = 0;

        fwrite(&order_info, sizeof(order_info), 1, main_file);
    }

    fclose(main_file);
    fclose(temp_file);

    remove("temp-order-file.tmp");
}

/*
    ==================================================================================
                                    Update Room Status Function
    ==================================================================================
*/
void order_room_update(int n)
{
    FILE *fptr, *fptr_temp1;

    fptr = fopen("room.txt", "rb");
    fptr_temp1 = fopen("temp-file.tmp", "wb+");

    if (fptr==NULL || fptr_temp1==NULL)
    {
        printf("\t\t\t\t\t\t Error: Unable to open file\n\n");
        exit(1);
    }


    while(fread(&room_info, sizeof(room_info), 1, fptr) == 1)
    {
        if(room_info.no != item_id)
            fwrite(&room_info, sizeof(room_info), 1, fptr_temp1);
        else if(room_info.no == item_id)
        {
            if(n==0) room_info.status = 0; //Checkout: Change Room Status to Avalabile
            else if(n==1) room_info.status = 1; //Order: Change Room Status to Not Avalabile

            fwrite(&room_info, sizeof(room_info), 1, fptr_temp1);
        }
    }

    fclose(fptr);
    fclose(fptr_temp1);

    remove("room.txt");
    rename("temp-file.tmp", "room.txt");
}

/*
    ==================================================================================
                                    Update Order Status Function
    ==================================================================================
*/
void update_order_status(int n)
{
    FILE *main_file;
    FILE *temp_file;
    char filename[100]="order.txt";

    main_file  = fopen(filename, "rb");
    temp_file = fopen("temp-file.tmp", "wb+");

    int count;

    if (main_file == NULL || temp_file == NULL)
    {
        printf("\t\t\t\t\t\t Unable to open file.\n");
        exit(1);
    }

    printf("\t\t\t\t\t\t Enter order ID: ");scanf("%d", &count);


    while(fread(&order_info, sizeof(order_info),1,main_file) == 1)
    {
        if(order_info.or_id != count)
            fwrite(&order_info, sizeof(order_info), 1, temp_file);
        else if(order_info.or_id == count)
        {
            if(n==0) order_info.or_status = 0; //Change Order Status to Pending
            if(n==1) order_info.or_status = 1; //Change order status to Confirmed

            fwrite(&order_info, sizeof(order_info), 1, temp_file);
        }
    }

    fclose(main_file);
    fclose(temp_file);

    remove(filename);
    rename("temp-file.tmp", filename);

    printf("\n\n\t\t\t\t\t\t%d No Order Confirmed. Press any key to continue.....", count);
}
